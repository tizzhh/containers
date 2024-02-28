#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_VECTOR_VECTOR_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_VECTOR_VECTOR_HPP

#include <iostream>
#include <limits>
#include <stdexcept>
#include <tuple>
namespace s21 {
template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = value_type *;
  using const_iterator = const value_type *;
  using size_type = size_t;
  constexpr inline vector();
  constexpr inline vector(size_type n);
  constexpr inline vector(std::initializer_list<value_type> const &items);
  constexpr inline vector(const vector &v);
  constexpr inline vector(vector &&v);
  ~vector();

  constexpr inline vector &operator=(vector &&a) noexcept;
  constexpr inline reference operator[](const size_type &pos);
  constexpr inline const_reference operator[](const size_type &pos) const;

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
  constexpr void reserve(size_type size) noexcept;
  constexpr void resize(size_type size) noexcept;
  constexpr size_type capacity() const noexcept;
  constexpr void shrink_to_fit() noexcept;

  constexpr void clear() noexcept;
  constexpr iterator insert(iterator pos, const_reference value);  // ?
  constexpr void erase(iterator pos) noexcept;
  constexpr void push_back(const_reference value);
  constexpr void pop_back() noexcept;
  constexpr void swap(vector &other) noexcept;

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);

 protected:
  //    size_type CapacityCalc(size_type amount_of_elements) const noexcept;
  constexpr void SetStorage(iterator value) noexcept;
  constexpr iterator GetStorage() const noexcept;

 private:
  iterator storage_ = nullptr;
  size_type capacity_ = 0;
  size_type size_ = 0;
};
};  // namespace s21

#include "vector.tpp"

#endif  // S21_CONTAINERS_SRC_S21_CONTAINERS_VECTOR_VECTOR_HPP