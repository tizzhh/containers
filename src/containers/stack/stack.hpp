#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_STACK_STACK_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_STACK_STACK_HPP

// это надо не забыть поменять на s21::list))
// здесь нужно доделать insert many
#include "../../s21_containerplus.hpp"
#include <stdlib.h>

namespace s21 {
template <typename T>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  constexpr stack() = default;
  constexpr stack(std::initializer_list<value_type> const &items);
  constexpr stack(const stack &s);
  constexpr stack(stack &&s);
  ~stack();
  constexpr stack &operator=(stack &&s);

  constexpr const_reference top() const noexcept;

  constexpr bool empty() const noexcept;
  constexpr size_type size() const noexcept;

  constexpr void push(const_reference value);
  constexpr void pop();
  constexpr void swap(stack &other);

 private:
  list<T> top_;
};

};  // namespace s21
#include "stack.tpp"
#endif