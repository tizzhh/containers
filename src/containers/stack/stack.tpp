#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_STACK_STACK_TPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_STACK_STACK_TPP

namespace s21 {
template <typename T>
constexpr stack<T>::stack(std::initializer_list<value_type> const &items) {
  for (auto elem : items) {
    top_.push_back(elem);
  }
}

template <typename T>
constexpr stack<T>::stack(const stack &s) {
  top_.clear();
  for (const auto &elem : s.top_) {
    top_.push_back(elem);
  }
}

template <typename T>
constexpr stack<T>::stack(stack &&s) {
  top_ = std::move(s.top_);
}

template <typename T>
constexpr stack<T> &stack<T>::operator=(stack &&s) {
  top_ = std::move(s.top_);
  return *this;
}

template <typename T>
constexpr typename stack<T>::const_reference stack<T>::top() const noexcept {
  return top_.back();
}

template <typename T>
constexpr bool stack<T>::empty() const noexcept {
  return top_.empty();
}

template <typename T>
constexpr typename stack<T>::size_type stack<T>::size() const noexcept {
  return top_.size();
}

template <typename T>
constexpr void stack<T>::push(const_reference value) {
  top_.push_back(value);
}

template <typename T>
constexpr void stack<T>::pop() {
  top_.pop_back();
}

template <typename T>
constexpr void stack<T>::swap(stack &other) {
  top_.swap(other.top_);
}

template <typename T>
template <typename... Args>
void stack<T>::insert_many_front(Args &&...args) {
  for (auto &&elem : {args...}) {
    push(elem);
  }
}
}  // namespace s21

#endif