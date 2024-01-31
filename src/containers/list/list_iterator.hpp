#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_ITERATOR_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_ITERATOR_HPP

#include "list.hpp"

namespace s21 {
template <typename T>
class ListIterator {
 public:
  ListIterator() = default;
  ListIterator(node<T> *ptr);
  ListIterator &operator--();
  ListIterator &operator++();
  bool operator==(const ListIterator &other);
  bool operator!=(const ListIterator &other);
  T &operator*();
  node<T> *operator->();
  node<T> *get_ptr();
  ListIterator &advance(size_t num);
  ListIterator &next(size_t num = 1);
  ListIterator &prev(size_t num = -1);

 private:
  node<T> *pointer_ = nullptr;
};

template <typename T>
class ListConstIterator {
 public:
  ListConstIterator() = default;
  ListConstIterator(node<T> *ptr);
  bool operator==(const ListConstIterator &other);
  bool operator!=(const ListConstIterator &other);
  const T &operator*();

 private:
  const node<T> *pointer_ = nullptr;
};
};  // namespace s21
#include "list_iterator.tpp"
#endif