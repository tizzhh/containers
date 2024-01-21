#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_QUEUE_QUEUE_TPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_QUEUE_QUEUE_TPP

namespace s21 {
template <typename T>
constexpr queue<T>::queue(std::initializer_list<value_type> const &items) {
  for (auto elem : items) {
    top_.push_back(elem);
  }
}

template <typename T>
constexpr queue<T>::queue(const queue &s) {
  top_.clear();
  top_ = s.top_;
}

template <typename T>
constexpr queue<T>::queue(queue &&s) {
  top_ = s.top_;
  s.top_.clear();
}

template <typename T>
constexpr queue<T> &queue<T>::operator=(queue &&s) {
  top_ = std::move(s);
  return *this;
}

template <typename T>
constexpr typename queue<T>::const_reference queue<T>::front() const noexcept {
  return top_.front();
}

template <typename T>
constexpr typename queue<T>::const_reference queue<T>::back() const noexcept {
  return top_.back();
}

template <typename T>
constexpr bool queue<T>::empty() const noexcept {
  return top_.empty();
}

template <typename T>
constexpr typename queue<T>::size_type queue<T>::size() const noexcept {
  return top_.size();
}

template <typename T>
constexpr void queue<T>::push(const_reference value) {
  top_.push_back(value);
}

template <typename T>
constexpr void queue<T>::pop() {
  top_.pop_front();
}

template <typename T>
constexpr void queue<T>::swap(queue &other) {
  top_.swap(other.top_);
}

template <typename T>
queue<T>::~queue() {
  top_.clear();
}
}  // namespace s21

#endif