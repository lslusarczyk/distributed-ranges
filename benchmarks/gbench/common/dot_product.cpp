// SPDX-FileCopyrightText: Intel Corporation
//
// SPDX-License-Identifier: BSD-3-Clause

#include "xhp-bench.hpp"

#ifdef SYCL_LANGUAGE_VERSION
#include <oneapi/dpl/algorithm>
#include <oneapi/dpl/async>
#include <oneapi/dpl/execution>
#include <oneapi/dpl/numeric>
#endif

using T = double;

T init_val = 1;

void check_dp(auto actual, const nostd::source_location location =
                               nostd::source_location::current()) {
  auto expected = default_vector_size * init_val * init_val;
  if (expected != actual) {
    fmt::print("Error in {}\n"
               "  Expected: {}\n"
               "  Actual: {}\n",
               location.function_name(), expected, actual);
    exit(1);
  } else {
    return;
  }
}

static void DotProduct_ZipReduce_DR(benchmark::State &state) {
  xhp::distributed_vector<T> a(default_vector_size, init_val);
  xhp::distributed_vector<T> b(default_vector_size, init_val);
  auto mul = [](auto v) {
    auto [a, b] = v;
    return a * b;
  };
  T res = 0;
  for (auto _ : state) {
    for (std::size_t i = 0; i < default_repetitions; i++) {
      res = xhp::reduce(xhp::views::zip(a, b) | xhp::views::transform(mul));
      benchmark::DoNotOptimize(res);
    }
  }
  check_dp(res);
}

BENCHMARK(DotProduct_ZipReduce_DR);

static void DotProduct_ZipReduce_Std(benchmark::State &state) {
  std::vector<T> a(default_vector_size, init_val);
  std::vector<T> b(default_vector_size, init_val);
  auto mul = [](auto v) {
    auto [a, b] = v;
    return a * b;
  };
  auto &&m = rng::views::zip(a, b) | rng::views::transform(mul);

  T res = 0;
  for (auto _ : state) {
    for (std::size_t i = 0; i < default_repetitions; i++) {
      res = std::reduce(std::execution::par_unseq, m.begin(), m.end());
      benchmark::DoNotOptimize(res);
    }
  }
  check_dp(res);
}

BENCHMARK(DotProduct_ZipReduce_Std);

static void DotProduct_TransformReduce_Std(benchmark::State &state) {
  std::vector<T> a(default_vector_size, init_val);
  std::vector<T> b(default_vector_size, init_val);
  auto mul = [](auto a, auto b) { return a * b; };

  T res = 0;
  for (auto _ : state) {
    for (std::size_t i = 0; i < default_repetitions; i++) {
      res = std::transform_reduce(std::execution::par_unseq, a.begin(), a.end(),
                                  b.begin(), T(0), std::plus(), mul);
      benchmark::DoNotOptimize(res);
    }
  }
  check_dp(res);
}

BENCHMARK(DotProduct_TransformReduce_Std);

static void DotProduct_Loop_Std(benchmark::State &state) {
  std::vector<T> a(default_vector_size, init_val);
  std::vector<T> b(default_vector_size, init_val);
  T res = 0;

  for (auto _ : state) {
    res = 0;
    for (std::size_t i = 0; i < default_vector_size; i++) {
      res += a[i] * b[i];
    }
    benchmark::DoNotOptimize(res);
  }
  check_dp(res);
}

BENCHMARK(DotProduct_Loop_Std);

#ifdef SYCL_LANGUAGE_VERSION
static void DotProduct_TransformReduce_DPL(benchmark::State &state) {
  T res = 0;
  sycl::queue q;
  auto policy = oneapi::dpl::execution::make_device_policy(q);

  auto mul = [](auto a, auto b) { return a * b; };
  auto a = sycl::malloc_device<T>(default_vector_size, q);
  ;
  auto b = sycl::malloc_device<T>(default_vector_size, q);
  ;
  q.fill(a, init_val, default_vector_size);
  q.fill(b, init_val, default_vector_size);
  q.wait();

  for (auto _ : state) {
    for (std::size_t i = 0; i < default_repetitions; i++) {
      res = std::transform_reduce(policy, a, a + default_vector_size, b, T(0),
                                  std::plus(), mul);
      benchmark::DoNotOptimize(res);
    }
  }
  check_dp(res);
}

BENCHMARK(DotProduct_TransformReduce_DPL);
#endif