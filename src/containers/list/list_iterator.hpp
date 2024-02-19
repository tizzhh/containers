#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_ITERATOR_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_ITERATOR_HPP

#include "list_node.hpp"

namespace s21 {
template <typename T>
class ListConstIterator;

template <typename T>
class ListIterator {
 public:
  constexpr ListIterator() = default;
  constexpr ListIterator(node<T> *ptr);
  constexpr ListIterator(const ListConstIterator<T> &other);
  constexpr ListIterator &operator--() noexcept;
  constexpr ListIterator &operator++() noexcept;
  constexpr bool operator==(const ListIterator &other) noexcept;
  constexpr bool operator!=(const ListIterator &other) noexcept;
  constexpr T &operator*();
  constexpr node<T> *operator->();
  constexpr node<T> *get_ptr() const;
  constexpr ListIterator &advance(int num) noexcept;
  constexpr ListIterator &next(int num = 1) noexcept;
  constexpr ListIterator &prev(int num = -1) noexcept;

 private:
  node<T> *pointer_ = nullptr;
};

template <typename T>
class ListConstIterator {
 public:
  constexpr ListConstIterator() = default;
  constexpr ListConstIterator(node<T> *ptr);
  constexpr ListConstIterator(const ListIterator<T> &other);
  constexpr ListConstIterator &operator--() noexcept;
  constexpr ListConstIterator &operator++() noexcept;
  constexpr bool operator==(const ListConstIterator &other) noexcept;
  constexpr bool operator!=(const ListConstIterator &other) noexcept;
  constexpr const T &operator*() const;
  constexpr const node<T> *operator->() const;
  constexpr node<T> *get_ptr() const;
  constexpr ListConstIterator &advance(int num) noexcept;
  constexpr ListConstIterator &next(int num = 1) noexcept;
  constexpr ListConstIterator &prev(int num = -1) noexcept;

 private:
  node<T> *pointer_ = nullptr;
};
};  // namespace s21
#include "list_iterator.tpp"
#endif