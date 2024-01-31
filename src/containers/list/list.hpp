#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_HPP

#include <stdlib.h>

#include <initializer_list>
#include <limits>

// CLANG МЕНЯЕТ 2 СЛЕДУЮЩИХ МЕСТАМИ И ВСЕ ИДЕТ ПО ПИЗДЕ
#include "list_node.hpp"
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

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();
  list &operator=(list &&l);

  // List Element access
  const_reference front() const;
  const_reference back() const;

  // List Iterators
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  // List Capacity
  bool empty();
  size_type size();
  size_type max_size();

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

 private:
  node<T> *front_ = nullptr;
  node<T> *back_ = nullptr;
  node<T> *end_ = nullptr;
  size_type size_ = 0;
};
};  // namespace s21
#include "list.tpp"
#endif