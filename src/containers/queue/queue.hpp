#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_QUEUE_QUEUE_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_QUEUE_QUEUE_HPP

#include <stdlib.h>

#include "../../s21_containersplus.hpp"

namespace s21 {
template <typename T>
class queue {
 public:
  // friend class list<T>;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  constexpr queue() = default;
  constexpr queue(std::initializer_list<value_type> const &items);
  constexpr queue(const queue &q);
  constexpr queue(queue &&q);
  ~queue() = default;
  constexpr queue &operator=(queue &&q);

  constexpr const_reference front() const noexcept;
  constexpr const_reference back() const noexcept;

  constexpr bool empty() const noexcept;
  constexpr size_type size() const noexcept;

  constexpr void push(const_reference value);
  constexpr void pop();
  constexpr void swap(queue &other);

  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  list<T> top_;
};

};  // namespace s21
#include "queue.tpp"
#endif