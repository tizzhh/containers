#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_QUEUE_QUEUE_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_QUEUE_QUEUE_HPP

// здесь нужно доделать insert many
#include "../../s21_containerplus.hpp"
#include <stdlib.h>

namespace s21 {
template <typename T>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  constexpr queue() = default;
  constexpr queue(std::initializer_list<value_type> const &items);
  constexpr queue(const queue &s);
  constexpr queue(queue &&s);
  ~queue();
  constexpr queue &operator=(queue &&s);

  constexpr const_reference front() const noexcept;
  constexpr const_reference back() const noexcept;

  constexpr bool empty() const noexcept;
  constexpr size_type size() const noexcept;

  constexpr void push(const_reference value);
  constexpr void pop();
  constexpr void swap(queue &other);

 private:
  list<T> top_;
};

};  // namespace s21
#include "queue.tpp"
#endif