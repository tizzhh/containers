#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_HPP

#include <stdlib.h>

#include <algorithm>
#include <initializer_list>
#include <limits>
#include <stdexcept>

// CLANG МЕНЯЕТ 2 СЛЕДУЮЩИХ МЕСТАМИ И ВСЕ ИДЕТ ПО ПИЗДЕ
#include "../vector/vector.hpp"
#include "list_iterator.hpp"

namespace s21 {
template <typename T>
class list {
 public:
  friend class ListIterator<T>;
  friend class ListConstIterator<T>;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
  using size_type = size_t;

  constexpr list();
  constexpr list(size_type n);
  constexpr list(std::initializer_list<value_type> const &items);
  constexpr list(const list &l);
  constexpr list(list &&l);
  ~list();
  constexpr list &operator=(list &&l);

  // List Element access
  constexpr const_reference front() const noexcept;
  constexpr const_reference back() const noexcept;

  // List Iterators
  constexpr iterator begin() noexcept;
  constexpr iterator end() noexcept;
  constexpr const_iterator begin() const noexcept;
  constexpr const_iterator end() const noexcept;

  // List Capacity
  constexpr bool empty() const noexcept;
  constexpr size_type size() const noexcept;
  constexpr size_type max_size() const noexcept;

  // List Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

  // Part 3 bonus
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);
  template <typename... Args>
  void insert_many_front(Args &&...args);

 private:
  void alloc_new_front_back_end_();
  void move_end_ptr_();
  bool check_if_list_sorted_();

  node<T> *front_ = nullptr;
  node<T> *back_ = nullptr;
  size_type size_ = 0;
  node<T> *end_ = nullptr;
};
};  // namespace s21
#include "list.tpp"
#endif