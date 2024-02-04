#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_ITERATOR_TPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_ITERATOR_TPP

#include <cstddef>

#include "list_iterator.hpp"

namespace s21 {
template <typename T>
ListIterator<T>::ListIterator(node<T>* ptr) : pointer_(ptr) {}

template <typename T>
ListIterator<T>::ListIterator(const ListConstIterator<T>& other)
    : pointer_(other.get_ptr()) {}

template <typename T>
ListIterator<T>& ListIterator<T>::operator--() {
  if (pointer_->prev != nullptr) {
    pointer_ = pointer_->prev;
  }
  return *this;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator++() {
  if (pointer_->next != nullptr) {
    pointer_ = pointer_->next;
  }
  return *this;
}

template <typename T>
bool ListIterator<T>::operator==(const ListIterator& other) {
  return pointer_ == other.pointer_;
}

template <typename T>
bool ListIterator<T>::operator!=(const ListIterator& other) {
  return pointer_ != other.pointer_;
}

template <typename T>
T& ListIterator<T>::operator*() {
  return pointer_->data;
}

template <typename T>
node<T>* ListIterator<T>::operator->() {
  return pointer_;
}

template <typename T>
node<T>* ListIterator<T>::get_ptr() const {
  return pointer_;
}

template <typename T>
ListIterator<T>& ListIterator<T>::advance(int num) {
  if (num > 0) {
    while (num--) {
      operator++();
    }
  } else {
    while (num++) {
      operator--();
    }
  }
  return *this;
}

template <typename T>
ListIterator<T>& ListIterator<T>::next(int num) {
  advance(num);
  return *this;
}

template <typename T>
ListIterator<T>& ListIterator<T>::prev(int num) {
  advance(num);
  return *this;
}

template <typename T>
ListConstIterator<T>::ListConstIterator(node<T>* ptr) : pointer_(ptr) {}

template <typename T>
ListConstIterator<T>::ListConstIterator(const ListIterator<T>& other)
    : pointer_(other.get_ptr()) {}

template <typename T>
bool ListConstIterator<T>::operator==(const ListConstIterator& other) {
  return pointer_ == other.pointer_;
}

template <typename T>
bool ListConstIterator<T>::operator!=(const ListConstIterator& other) {
  return pointer_ != other.pointer_;
}

template <typename T>
const node<T>* ListConstIterator<T>::operator->() {
  return pointer_;
}

template <typename T>
node<T>* ListConstIterator<T>::get_ptr() const {
  return pointer_;
}

template <typename T>
const T& ListConstIterator<T>::operator*() {
  return pointer_->data;
}

template <typename T>
ListConstIterator<T>& ListConstIterator<T>::operator--() {
  if (pointer_->prev != nullptr) {
    pointer_ = pointer_->prev;
  }
  return *this;
}

template <typename T>
ListConstIterator<T>& ListConstIterator<T>::operator++() {
  if (pointer_->next != nullptr) {
    pointer_ = pointer_->next;
  }
  return *this;
}

template <typename T>
ListConstIterator<T>& ListConstIterator<T>::advance(int num) {
  if (num > 0) {
    while (num--) {
      operator++();
    }
  } else {
    while (num++) {
      operator--();
    }
  }
  return *this;
}

template <typename T>
ListConstIterator<T>& ListConstIterator<T>::next(int num) {
  advance(num);
  return *this;
}

template <typename T>
ListConstIterator<T>& ListConstIterator<T>::prev(int num) {
  advance(num);
  return *this;
}
}  // namespace s21

#endif