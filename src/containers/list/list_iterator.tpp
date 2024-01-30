#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_ITERATOR_TPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_ITERATOR_TPP

#include "list_iterator.hpp"  // убрать (стоит здесь только для ттого чтоб ошибки не подсвечивало)
namespace s21 {
template <typename T>
ListIterator<T>::ListIterator(node<T>* ptr) : pointer_(ptr) {}

template <typename T>
ListIterator<T>& ListIterator<T>::operator--() {
  if (pointer_->prev != nullptr) {
    pointer_ = pointer_->prev;
  }
  return *this;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator++() {
  // if (pointer_->next != nullptr) {
  // закомменчено из-за for-each лупа и подобных проходов от бегина до энда
  // без проверки есть риск сеги (сделал эксепшном), с проверкой он просто не
  // дойдет до end, хз как сделать нормально поэтому.
  pointer_ = pointer_->next;
  // }
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
  if (pointer_ == nullptr) {
    throw std::out_of_range("Iterator is out of range");
  }
  return pointer_->data;
}

template <typename T>
ListIterator<T>& ListIterator<T>::advance(size_t num) {
  std::cout << "aboba" << '\n';
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
ListIterator<T>& ListIterator<T>::next(size_t num) {
  advance(num);
  return *this;
}

template <typename T>
ListIterator<T>& ListIterator<T>::prev(size_t num) {
  advance(num);
  return *this;
}

template <typename T>
ListConstIterator<T>::ListConstIterator(node<T>* ptr) : pointer_(ptr) {}

template <typename T>
bool ListConstIterator<T>::operator==(const ListConstIterator& other) {
  return pointer_ == other.pointer_;
}

template <typename T>
bool ListConstIterator<T>::operator!=(const ListConstIterator& other) {
  std::cout << "aboba" << '\n';
  return pointer_ != other.pointer_;
}

template <typename T>
const T& ListConstIterator<T>::operator*() {
  if (pointer_ == nullptr) {
    throw std::out_of_range("Iterator is out of range");
  }
  return pointer_->data;
}
}  // namespace s21

#endif