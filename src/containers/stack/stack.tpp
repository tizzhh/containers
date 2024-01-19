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
  top_ = s.top_;
}

template <typename T>
constexpr stack<T>::stack(stack &&s) {
  top_ = s.top_;
  s.top_ = nullptr;
}

template <typename T>
constexpr stack<T> &stack<T>::operator=(stack &&s) {
  top_ = std::move(s);
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
  top_.swap(other);
}

template <typename T>
stack<T>::~stack() {
  top_.clear();
}
}  // namespace s21

#endif