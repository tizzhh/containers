#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_PLUS_ARRAY_ARRAY_TPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_PLUS_ARRAY_ARRAY_TPP

#include <stdexcept>

namespace s21 {
template <typename T, std::size_t N>
constexpr Array<T, N>::Array() : capacity_(N), size_(0){};

template <typename T, std::size_t N>
constexpr Array<T, N>::Array(std::initializer_list<value_type> const& items) {
  if (items.size() > capacity_) throw std::invalid_argument("#");
  size_type i = 0;
  for (auto val : items) storage_[i++] = val;
  size_ = i;
}

template <typename T, std::size_t N>
constexpr Array<T, N>::Array(const Array& a) {
  if (a.max_size() != capacity_) throw std::invalid_argument("#");
  for (size_t i = 0; i != a.size(); ++i) storage_[i] = a[i];
  size_ = a.size();
}

template <typename T, std::size_t N>
constexpr Array<T, N>::Array(Array&& a) {
  if (a.max_size() != capacity_) throw std::invalid_argument("#");
  for (size_t i = 0; i != a.size(); ++i) storage_[i] = std::move(a[i]);
  size_ = a.size();
}

template <typename T, std::size_t N>
constexpr Array<T, N>& Array<T, N>::operator=(Array&& a) {
  if (a.max_size() != capacity_) throw std::invalid_argument("#");
  for (size_t i = 0; i != a.size(); ++i) storage_[i] = std::move(a[i]);
  size_ = a.size();
  return *this;
}

template <typename T, std::size_t N>
constexpr Array<T, N>& Array<T, N>::operator=(
  const std::initializer_list<value_type>& values) {
  if (values.size() > capacity_) throw std::invalid_argument("#");
  size_type i = 0;
  for (auto val : values) storage_[i++] = val;
  size_ = i;
  return *this;
}

template <typename T, std::size_t N>
constexpr typename Array<T, N>::reference Array<T, N>::operator[](const size_type& pos) {
  if (pos > capacity_) throw std::out_of_range("#");
  return /*pos > size_ ? 0 :*/ storage_[pos];
}

template <typename T, std::size_t N>
constexpr typename Array<T, N>::const_reference Array<T, N>::operator[](
    const size_type& pos) const {
  if (pos > capacity_) throw std::out_of_range("#");
  return /*pos > size_ ? 0 :*/ storage_[pos];
}

template <typename T, std::size_t N>
constexpr typename Array<T, N>::reference Array<T, N>::at(const size_type& pos) {
  if (pos > capacity_) throw std::out_of_range("#");
  return /*pos > size_ ? 0 :*/ storage_[pos];
}

template <typename T, std::size_t N>
constexpr typename Array<T, N>::const_reference Array<T, N>::at(
    const size_type& pos) const {
  if (pos > capacity_) throw std::out_of_range("#");
  return /*pos > size_ ? 0 :*/ storage_[pos];
}
template <typename T, std::size_t N>
constexpr typename Array<T, N>::reference Array<T, N>::front() noexcept {
  // if(size_ == 0) std::logic_error("#");
  return storage_[0];
}

template <typename T, std::size_t N>
constexpr typename Array<T, N>::const_reference Array<T, N>::front() const noexcept {
  // if(size_ == 0) std::logic_error("#");
  return storage_[0];
}

template <typename T, std::size_t N>
constexpr typename Array<T, N>::reference Array<T, N>::back() noexcept {
  // if(size_ == 0) std::logic_error("#");
  return storage_[size_ - 1];
}

template <typename T, std::size_t N>
constexpr typename Array<T, N>::const_reference Array<T, N>::back() const noexcept {
  // if(size_ == 0) std::logic_error("#");
  return storage_[size_ - 1];
}

template <typename T, std::size_t N>
constexpr typename Array<T, N>::iterator Array<T, N>::data() noexcept {
  // if(size_ == 0) throw std::logic_error("#");
  return storage_;
}

template <typename T, std::size_t N>
constexpr typename Array<T, N>::const_iterator Array<T, N>::data() const noexcept {
  // if(size_ == 0) throw std::logic_error("#");
  return storage_;
}

template <typename T, std::size_t N>
constexpr typename Array<T, N>::iterator
Array<T, N>::begin() noexcept {  // returns an iterator to the beginning
  return storage_;
}

template <typename T, std::size_t N>
constexpr typename Array<T, N>::const_iterator Array<T, N>::cbegin()
    const noexcept {  // returns an iterator to the beginning
  return storage_;
}

template <typename T, std::size_t N>
constexpr typename Array<T, N>::iterator
Array<T, N>::end() noexcept {  // returns an iterator to the end
  return storage_ + capacity_;
}

template <typename T, std::size_t N>
constexpr typename Array<T, N>::const_iterator Array<T, N>::cend()
    const noexcept {  // returns an iterator to the end
  return storage_ + capacity_;
}

template <typename T, std::size_t N>
constexpr bool Array<T, N>::empty() const noexcept {
  return size_ == 0;
}

template <typename T, std::size_t N>
constexpr typename Array<T, N>::size_type Array<T, N>::size() const noexcept {
  return size_;
}

template <typename T, std::size_t N>
constexpr typename Array<T, N>::size_type Array<T, N>::max_size() const noexcept {
  return capacity_;
}

template <typename T, std::size_t N>
constexpr void Array<T, N>::swap(const Array& other) noexcept {
  std::swap_ranges(this->begin(), this->end(), other.begin());
}

template <typename T, std::size_t N>
constexpr void Array<T, N>::fill(const_reference value) noexcept {
  std::fill(this->begin(), this->end(), value);
}

};  // namespace s21

#endif // S21_CONTAINERS_SRC_S21_CONTAINERS_PLUS_ARRAY_ARRAY_TPP