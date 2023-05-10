// SPDX-FileCopyrightText: Intel Corporation
//
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <any>
#include <iterator>
#include <type_traits>

#include <dr/detail/ranges_shim.hpp>

namespace dr {

namespace ranges {

template <typename> inline constexpr bool disable_rank = false;

namespace {

template <typename T>
concept has_rank_method = requires(T t) {
  { t.rank() } -> std::weakly_incrementable;
};

template <typename R>
concept has_rank_adl = requires(R &r) {
  { rank_(r) } -> std::weakly_incrementable;
};

template <typename Iter>
concept is_remote_iterator_shadow_impl_ =
    std::forward_iterator<Iter> && has_rank_method<Iter> &&
    !disable_rank<std::remove_cv_t<Iter>>;

} // namespace

namespace {

struct rank_fn_ {

  // Return the rank associated with a remote range.
  // This is either:
  // 1) r.rank(), if the remote range has a `rank()` method
  // OR, if not available,
  // 2) r.begin().rank(), if iterator is `remote_iterator`
  template <rng::forward_range R>
    requires((has_rank_method<R> && !disable_rank<std::remove_cv_t<R>>) ||
             (has_rank_adl<R> && !disable_rank<std::remove_cv_t<R>>) ||
             is_remote_iterator_shadow_impl_<rng::iterator_t<R>>)
  constexpr auto operator()(R &&r) const {
    if constexpr (has_rank_method<R> && !disable_rank<std::remove_cv_t<R>>) {
      return std::forward<R>(r).rank();
    } else if constexpr (is_remote_iterator_shadow_impl_<rng::iterator_t<R>>) {
      return operator()(rng::begin(std::forward<R>(r)));
    } else if constexpr (has_rank_adl<R> &&
                         !disable_rank<std::remove_cv_t<R>>) {
      return rank_(std::forward<R>(r));
    }
  }

  template <std::forward_iterator Iter>
    requires(has_rank_method<Iter> && !disable_rank<std::remove_cv_t<Iter>>)
  auto operator()(Iter iter) const {
    if constexpr (has_rank_method<Iter> &&
                  !disable_rank<std::remove_cv_t<Iter>>) {
      return std::forward<Iter>(iter).rank();
    }
  }
};

} // namespace

inline constexpr auto rank = rank_fn_{};

namespace __detail {

template <typename R>
concept remote_range_shadow_impl_ =
    rng::forward_range<R> && requires(R &r) { dr::ranges::rank(r); };

template <typename R>
concept segments_range =
    rng::forward_range<R> && remote_range_shadow_impl_<rng::range_value_t<R>>;

template <typename R>
concept has_segments_method = requires(R r) {
  { r.segments() } -> segments_range;
};

template <typename R>
concept has_segments_adl = requires(R &r) {
  { segments_(r) } -> segments_range;
};

struct segments_fn_ {
  template <rng::forward_range R>
    requires(has_segments_method<R> || has_segments_adl<R>)
  constexpr decltype(auto) operator()(R &&r) const {
    if constexpr (has_segments_method<R>) {
      return std::forward<R>(r).segments();
    } else if constexpr (has_segments_adl<R>) {
      return segments_(std::forward<R>(r));
    }
  }

  template <std::forward_iterator I>
    requires(has_segments_method<I> || has_segments_adl<I>)
  constexpr decltype(auto) operator()(I iter) const {
    if constexpr (has_segments_method<I>) {
      return std::forward<I>(iter).segments();
    } else if constexpr (has_segments_adl<I>) {
      return segments_(std::forward<I>(iter));
    }
  }
};

} // namespace __detail

inline constexpr auto segments = __detail::segments_fn_{};

namespace {

template <typename T>
concept has_local_adl = requires(T &t) { local_(t); };

template <typename Iter>
concept iter_has_local_method =
    std::forward_iterator<Iter> && requires(Iter iter) {
      { iter.local() } -> std::forward_iterator;
    };

template <typename Segment>
concept segment_has_local_method =
    rng::forward_range<Segment> && requires(Segment segment) {
      { segment.local() } -> rng::forward_range;
    };

struct local_fn_ {

  template <class Iter>
    requires(has_local_adl<Iter> || iter_has_local_method<Iter> ||
             std::contiguous_iterator<Iter> ||
             std::is_scalar_v<std::remove_cvref_t<Iter>>)
  auto operator()(Iter &&iter) const {
    if constexpr (iter_has_local_method<Iter>) {
      return iter.local();
    } else if constexpr (has_local_adl<Iter>) {
      return local_(std::forward<Iter>(iter));
    } else if constexpr (std::contiguous_iterator<Iter> ||
                         std::is_scalar_v<std::remove_cvref_t<Iter>>) {
      return std::forward<Iter>(iter);
    }
  }

  template <rng::forward_range R>
    requires(has_local_adl<R> || iter_has_local_method<rng::iterator_t<R>> ||
             segment_has_local_method<R> ||
             std::contiguous_iterator<rng::iterator_t<R>> ||
             rng::contiguous_range<R>)
  auto operator()(R &&r) const {
    if constexpr (segment_has_local_method<R>) {
      return r.local();
    } else if constexpr (iter_has_local_method<rng::iterator_t<R>>) {
      return rng::views::counted(rng::begin(r).local(), rng::size(r));
    } else if constexpr (has_local_adl<R>) {
      return local_(std::forward<R>(r));
    } else if constexpr (std::contiguous_iterator<rng::iterator_t<R>>) {
      return std::span(rng::begin(r), rng::size(r));
    }
  }
};

} // namespace

inline constexpr auto local = local_fn_{};

namespace __detail {

template <typename T>
concept has_local = requires(T &t) {
  { dr::ranges::local(t) } -> std::convertible_to<std::any>;
};

struct local_fn_ {
  template <typename T>
    requires(has_local<T>)
  auto operator()(T &&t) const {
    return dr::ranges::local(t);
  }

  template <typename T> auto operator()(T &&t) const { return t; }
};

inline constexpr auto local = local_fn_{};

} // namespace __detail

} // namespace ranges

} // namespace dr
