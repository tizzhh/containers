#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_ITERATOR_TPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_ITERATOR_TPP

#include <cstddef>

#include "list_iterator.hpp"

namespace s21 {
template <typename T>
constexpr ListIterator<T>::ListIterator(node<T> *ptr) : pointer_(ptr) {}

template <typename T>
constexpr ListIterator<T>::ListIterator(const ListConstIterator<T> &other)
    : pointer_(other.get_ptr()) {}

template <typename T>
constexpr ListIterator<T> &ListIterator<T>::operator--() noexcept {
  if (pointer_->prev != nullptr) {
    pointer_ = pointer_->prev;
  }
  return *this;
}

template <typename T>
constexpr ListIterator<T> &ListIterator<T>::operator++() noexcept {
  if (pointer_->next != nullptr) {
    pointer_ = pointer_->next;
  }
  return *this;
}

template <typename T>
constexpr bool ListIterator<T>::operator==(const ListIterator &other) noexcept {
  return pointer_ == other.pointer_;
}

template <typename T>
constexpr bool ListIterator<T>::operator!=(const ListIterator &other) noexcept {
  return pointer_ != other.pointer_;
}

template <typename T>
constexpr T &ListIterator<T>::operator*() {
  return pointer_->data;
}

template <typename T>
constexpr node<T> *ListIterator<T>::operator->() {
  return pointer_;
}

template <typename T>
constexpr node<T> *ListIterator<T>::get_ptr() const {
  return pointer_;
}

template <typename T>
constexpr ListIterator<T> &ListIterator<T>::advance(int num) noexcept {
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
constexpr ListIterator<T> &ListIterator<T>::next(int num) noexcept {
  advance(num);
  return *this;
}

template <typename T>
constexpr ListIterator<T> &ListIterator<T>::prev(int num) noexcept {
  advance(num);
  return *this;
}

template <typename T>
constexpr ListConstIterator<T>::ListConstIterator(node<T> *ptr)
    : pointer_(ptr) {}

template <typename T>
constexpr ListConstIterator<T>::ListConstIterator(const ListIterator<T> &other)
    : pointer_(other.get_ptr()) {}

template <typename T>
constexpr bool ListConstIterator<T>::operator==(
    const ListConstIterator &other) noexcept {
  return pointer_ == other.pointer_;
}

template <typename T>
constexpr bool ListConstIterator<T>::operator!=(
    const ListConstIterator &other) noexcept {
  return pointer_ != other.pointer_;
}

template <typename T>
constexpr const node<T> *ListConstIterator<T>::operator->() const {
  return pointer_;
}

template <typename T>
constexpr node<T> *ListConstIterator<T>::get_ptr() const {
  return pointer_;
}

template <typename T>
constexpr const T &ListConstIterator<T>::operator*() const {
  return pointer_->data;
}

template <typename T>
constexpr ListConstIterator<T> &ListConstIterator<T>::operator--() noexcept {
  if (pointer_->prev != nullptr) {
    pointer_ = pointer_->prev;
  }
  return *this;
}

template <typename T>
constexpr ListConstIterator<T> &ListConstIterator<T>::operator++() noexcept {
  if (pointer_->next != nullptr) {
    pointer_ = pointer_->next;
  }
  return *this;
}

template <typename T>
constexpr ListConstIterator<T> &ListConstIterator<T>::advance(
    int num) noexcept {
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
constexpr ListConstIterator<T> &ListConstIterator<T>::next(int num) noexcept {
  advance(num);
  return *this;
}

template <typename T>
constexpr ListConstIterator<T> &ListConstIterator<T>::prev(int num) noexcept {
  advance(num);
  return *this;
}
}  // namespace s21

#endif