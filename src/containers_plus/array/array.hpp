#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_PLUS_ARRAY_ARRAY_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_PLUS_ARRAY_ARRAY_HPP

#include <iostream>
#include <tuple>
namespace s21 {
template <typename T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = value_type *;
  using const_iterator = const value_type *;
  using size_type = size_t;

  constexpr array();
  constexpr array(std::initializer_list<value_type> const &items);
  constexpr array(const array &a);
  constexpr array(array &&a);
  ~array() = default;

  constexpr array &operator=(array &&a);
  constexpr array &operator=(const std::initializer_list<value_type> &values);
  constexpr reference operator[](const size_type &pos);
  constexpr const_reference operator[](const size_type &pos) const;

  constexpr reference at(const size_type &pos);
  constexpr const_reference at(const size_type &pos) const;
  constexpr reference front() noexcept;
  constexpr const_reference front() const noexcept;
  constexpr reference back() noexcept;
  constexpr const_reference back() const noexcept;
  constexpr iterator data() noexcept;
  constexpr const_iterator data() const noexcept;

  constexpr iterator begin() noexcept;
  constexpr const_iterator cbegin() const noexcept;
  constexpr iterator end() noexcept;
  constexpr const_iterator cend() const noexcept;

  constexpr bool empty() const noexcept;
  constexpr size_type size() const noexcept;
  constexpr size_type max_size() const noexcept;

  constexpr void swap(array &other) noexcept;
  constexpr void fill(const_reference value) noexcept;

 private:
  value_type storage_[N] = {};
  size_type capacity_ = N;
  size_type size_ = 0;
};

};  // namespace s21
#include "array.tpp"

#endif  // S21_CONTAINERS_SRC_S21_CONTAINERS_PLUS_ARRAY_ARRAY_HPP