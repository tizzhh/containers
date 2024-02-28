#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_PLUS_ARRAY_ARRAY_TPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_PLUS_ARRAY_ARRAY_TPP

#include <stdexcept>

namespace s21 {
template <typename T, std::size_t N>
constexpr array<T, N>::array() : capacity_(N), size_(N) {
  fill(0);
};

template <typename T, std::size_t N>
constexpr array<T, N>::array(std::initializer_list<value_type> const &items)
    : size_(N) {
  if (items.size() > capacity_)
    throw std::invalid_argument("array::constructor");
  for (size_type i = 0; i != N; i++)
    storage_[i] = i < items.size() ? *(items.begin() + i) : 0;
}

template <typename T, std::size_t N>
constexpr array<T, N>::array(const array &a) {
  if (a.max_size() != capacity_)
    throw std::invalid_argument("array::constructor");
  for (size_t i = 0; i != a.size(); ++i) storage_[i] = a[i];
  size_ = a.size();
}

template <typename T, std::size_t N>
constexpr array<T, N>::array(array &&a) {
  if (a.max_size() != capacity_)
    throw std::invalid_argument("array::constructor");
  for (size_t i = 0; i != a.size(); ++i) storage_[i] = std::move(a[i]);
  size_ = a.size();
}

template <typename T, std::size_t N>
constexpr array<T, N> &array<T, N>::operator=(array &&a) {
  if (a.max_size() != capacity_)
    throw std::invalid_argument("array::constructor");
  for (size_t i = 0; i != a.size(); ++i) storage_[i] = std::move(a[i]);
  size_ = a.size();
  return *this;
}

template <typename T, std::size_t N>
constexpr array<T, N> &array<T, N>::operator=(
    const std::initializer_list<value_type> &values) {
  if (values.size() > capacity_)
    throw std::invalid_argument("array::constructor");
  size_type i = 0;
  for (auto val : values) storage_[i++] = val;
  size_ = i;
  return *this;
}

template <typename T, std::size_t N>
constexpr typename array<T, N>::reference array<T, N>::operator[](
    const size_type &pos) {
  // if (pos > capacity_) throw std::out_of_range("#");
  return /*pos > size_ ? 0 :*/ storage_[pos];
}

template <typename T, std::size_t N>
constexpr typename array<T, N>::const_reference array<T, N>::operator[](
    const size_type &pos) const {
  // if (pos > capacity_) throw std::out_of_range("#");
  return /*pos > size_ ? 0 :*/ storage_[pos];
}

template <typename T, std::size_t N>
constexpr typename array<T, N>::reference array<T, N>::at(
    const size_type &pos) {
  if (pos > capacity_) throw std::out_of_range("array::at");
  return /*pos > size_ ? 0 :*/ storage_[pos];
}

template <typename T, std::size_t N>
constexpr typename array<T, N>::const_reference array<T, N>::at(
    const size_type &pos) const {
  if (pos > capacity_) throw std::out_of_range("array::at");
  return /*pos > size_ ? 0 :*/ storage_[pos];
}
template <typename T, std::size_t N>
constexpr typename array<T, N>::reference array<T, N>::front() noexcept {
  // if(size_ == 0) std::logic_error("#");
  return storage_[0];
}

template <typename T, std::size_t N>
constexpr typename array<T, N>::const_reference array<T, N>::front()
    const noexcept {
  // if(size_ == 0) std::logic_error("#");
  return storage_[0];
}

template <typename T, std::size_t N>
constexpr typename array<T, N>::reference array<T, N>::back() noexcept {
  // if(size_ == 0) std::logic_error("#");
  return storage_[size_ - 1];
}

template <typename T, std::size_t N>
constexpr typename array<T, N>::const_reference array<T, N>::back()
    const noexcept {
  // if(size_ == 0) std::logic_error("#");
  return storage_[size_ - 1];
}

template <typename T, std::size_t N>
constexpr typename array<T, N>::iterator array<T, N>::data() noexcept {
  // if(size_ == 0) throw std::logic_error("#");
  return storage_;
}

template <typename T, std::size_t N>
constexpr typename array<T, N>::const_iterator array<T, N>::data()
    const noexcept {
  // if(size_ == 0) throw std::logic_error("#");
  return storage_;
}

template <typename T, std::size_t N>
constexpr typename array<T, N>::iterator
array<T, N>::begin() noexcept {  // returns an iterator to the beginning
  return storage_;
}

template <typename T, std::size_t N>
constexpr typename array<T, N>::const_iterator array<T, N>::cbegin()
    const noexcept {  // returns an iterator to the beginning
  return storage_;
}

template <typename T, std::size_t N>
constexpr typename array<T, N>::iterator
array<T, N>::end() noexcept {  // returns an iterator to the end
  return storage_ + capacity_;
}

template <typename T, std::size_t N>
constexpr typename array<T, N>::const_iterator array<T, N>::cend()
    const noexcept {  // returns an iterator to the end
  return storage_ + capacity_;
}

template <typename T, std::size_t N>
constexpr bool array<T, N>::empty() const noexcept {
  return size_ == 0;
}

template <typename T, std::size_t N>
constexpr typename array<T, N>::size_type array<T, N>::size() const noexcept {
  return size_;
}

template <typename T, std::size_t N>
constexpr typename array<T, N>::size_type array<T, N>::max_size()
    const noexcept {
  return capacity_;
}

template <typename T, std::size_t N>
constexpr void array<T, N>::swap(array<T, N> &other) noexcept {
  std::swap_ranges(this->begin(), this->end(), other.begin());
}

template <typename T, std::size_t N>
constexpr void array<T, N>::fill(const_reference value) noexcept {
  std::fill(this->begin(), this->end(), value);
}

};  // namespace s21

#endif  // S21_CONTAINERS_SRC_S21_CONTAINERS_PLUS_ARRAY_ARRAY_TPP
