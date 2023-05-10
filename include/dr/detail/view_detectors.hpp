// SPDX-FileCopyrightText: Intel Corporation
//
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <type_traits>

namespace dr {

template <typename T> struct is_ref_view : std::false_type {};
template <rng::range R>
struct is_ref_view<rng::ref_view<R>> : std::true_type {};

template <typename T> inline constexpr bool is_ref_view_v = is_ref_view<T>{};

template <typename T> struct is_iota_view : std::false_type {};
template <std::weakly_incrementable W>
struct is_iota_view<rng::iota_view<W>> : std::true_type {};

template <typename T> inline constexpr bool is_iota_view_v = is_iota_view<T>{};

template <typename T> struct is_take_view : std::false_type {};
template <typename T>
struct is_take_view<rng::take_view<T>> : std::true_type {};

template <typename T>
inline constexpr bool is_take_view_v = is_take_view<T>::value;

template <typename T> struct is_drop_view : std::false_type {};
template <typename T>
struct is_drop_view<rng::drop_view<T>> : std::true_type {};

template <typename T>
inline constexpr bool is_drop_view_v = is_drop_view<T>::value;

template <typename T> struct is_subrange_view : std::false_type {};
template <typename T>
struct is_subrange_view<rng::subrange<T>> : std::true_type {};

template <typename T>
inline constexpr bool is_subrange_view_v = is_subrange_view<T>::value;

#define DEFINE_DETECTOR(NAME)                                                  \
  template <typename T> struct is_##NAME : std::false_type {};                 \
  template <typename T> struct is_##NAME<rng::NAME<T>> : std::true_type {};    \
  template <typename T>                                                        \
  inline constexpr bool is_##NAME##_v =                                        \
      is_##NAME<std::remove_cvref_t<T>>::value;

// DEFINE_DETECTOR(drop)
// DEFINE_DETECTOR(iota)
// DEFINE_DETECTOR(ref)
DEFINE_DETECTOR(sliding_view)
// DEFINE_DETECTOR(subrange)
// DEFINE_DETECTOR(take)

#undef DEFINE_DETECTOR

template <typename T> struct is_zip_view : std::false_type {};

template <typename... Views>
struct is_zip_view<rng::zip_view<Views...>> : std::true_type {};

template <typename T>
inline constexpr bool is_zip_view_v = is_zip_view<T>::value;

} // namespace dr
