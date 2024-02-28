#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_VECTOR_VECTOR_TPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_VECTOR_VECTOR_TPP

namespace s21 {
// template<typename T>
// constexpr typename vector<T>::size_type vector<T>::CapacityCalc(size_type
// amount_of_elements) const noexcept{
//   return 1 << ((size_type)log2(amount_of_elements) + 1);
// }

template <typename T>
constexpr vector<T>::vector() : capacity_(0), size_(0){};

template <typename T>
constexpr vector<T>::vector(size_type n) : capacity_(n), size_(n) {
  storage_ = new T[n]();
  /*  if (!storage_)
      throw std::bad_alloc();*/
};

template <typename T>
constexpr vector<T>::vector(std::initializer_list<value_type> const &items)
    : capacity_(items.size()), size_(items.size()) {
  storage_ = new value_type[items.size()];
  /*  if (!storage_)
      throw std::bad_alloc();*/
  size_type i = 0;
  for (auto val : items) storage_[i++] = val;
}

template <typename T>
constexpr vector<T>::vector(const vector &a)
    : capacity_(a.size()), size_(a.size()) {
  storage_ = new value_type[a.size()]();
  /*  if (!storage_)
      throw std::bad_alloc();*/
  for (size_t i = 0; i != a.size(); ++i) storage_[i] = a[i];
}

template <typename T>
constexpr vector<T>::vector(vector &&a)
    : capacity_(a.capacity()), size_(a.size()) {
  storage_ = a.GetStorage();
  a.SetStorage(nullptr);
  capacity_ = a.capacity();
  a.reserve(0);
  size_ = a.size();
  a.resize(0);
}

template <typename T>
vector<T>::~vector() {
  delete[] storage_;
}

template <typename T>
constexpr vector<T> &vector<T>::operator=(vector &&a) noexcept {
  storage_ = a.GetStorage();
  a.SetStorage(nullptr);
  capacity_ = a.capacity();
  a.reserve(0);
  size_ = a.size();
  a.resize(0);
  return *this;
}

template <typename T>
constexpr typename vector<T>::reference vector<T>::operator[](
    const size_type &pos) {
  return /*pos > size_ ? 0 :*/ storage_[pos];
}

template <typename T>
constexpr typename vector<T>::const_reference vector<T>::operator[](
    const size_type &pos) const {
  return /*pos > size_ ? 0 :*/ storage_[pos];
}

template <typename T>
constexpr typename vector<T>::reference vector<T>::at(const size_type &pos) {
  if (pos > capacity_) throw std::out_of_range("#");
  return /*pos > size_ ? 0 :*/ storage_[pos];
}

template <typename T>
constexpr typename vector<T>::const_reference vector<T>::at(
    const size_type &pos) const {
  if (pos > capacity_) throw std::out_of_range("#");
  return /*pos > size_ ? 0 :*/ storage_[pos];
}
template <typename T>
constexpr typename vector<T>::reference vector<T>::front() noexcept {
  // if(size_ == 0) std::logic_error("#");
  return storage_[0];
}

template <typename T>
constexpr typename vector<T>::const_reference vector<T>::front()
    const noexcept {
  // if(size_ == 0) std::logic_error("#");
  return storage_[0];
}

template <typename T>
constexpr typename vector<T>::reference vector<T>::back() noexcept {
  // if(size_ == 0) std::logic_error("#");
  return storage_[size_ - 1];
}

template <typename T>
constexpr typename vector<T>::const_reference vector<T>::back() const noexcept {
  // if(size_ == 0) std::logic_error("#");
  return storage_[size_ - 1];
}

template <typename T>
constexpr typename vector<T>::iterator vector<T>::data() noexcept {
  // if(size_ == 0) throw std::logic_error("#");
  return storage_;
}

template <typename T>
constexpr typename vector<T>::const_iterator vector<T>::data() const noexcept {
  // if(size_ == 0) throw std::logic_error("#");
  return storage_;
}

template <typename T>
constexpr typename vector<T>::iterator
vector<T>::begin() noexcept {  // returns an iterator to the beginning
  return storage_;
}

template <typename T>
constexpr typename vector<T>::const_iterator vector<T>::cbegin()
    const noexcept {  // returns an iterator to the beginning
  return storage_;
}

template <typename T>
constexpr typename vector<T>::iterator
vector<T>::end() noexcept {  // returns an iterator to the end
  return storage_ + size_;
}

template <typename T>
constexpr typename vector<T>::const_iterator vector<T>::cend()
    const noexcept {  // returns an iterator to the end
  return storage_ + size_;
}

template <typename T>
constexpr inline bool vector<T>::empty() const noexcept {
  return this->cbegin() == this->cend();
}

template <typename T>
constexpr typename vector<T>::size_type vector<T>::size() const noexcept {
  return size_;
}

template <typename T>
constexpr typename vector<T>::size_type vector<T>::max_size() const noexcept {
  return std::numeric_limits<std::size_t>::max() / sizeof(value_type) / 2;
}

template <typename T>
constexpr void vector<T>::SetStorage(iterator value) noexcept {
  storage_ = value;
}

template <typename T>
constexpr typename vector<T>::iterator vector<T>::GetStorage() const noexcept {
  return storage_;
}

template <typename T>
constexpr void vector<T>::reserve(size_type size) noexcept {
  if (capacity_ < size) capacity_ = size;
}

template <typename T>
constexpr void vector<T>::resize(size_type size) noexcept {
  if (size > capacity_) {
    value_type temp[size_];
    for (size_type i = 0; i != size_; i++) temp[i] = storage_[i];
    delete[] storage_;
    capacity_ = size;
    storage_ = new value_type[capacity_];
    for (size_type i = 0; i != size_; i++) storage_[i] = temp[i];
    for (size_type i = size_; i != size; i++) storage_[i] = T();
  }
  if (size > size_) {
    for (size_type i = size_; i != size; i++) storage_[i] = T();
  }
  size_ = size;
}

template <typename T>
constexpr typename vector<T>::size_type vector<T>::capacity() const noexcept {
  return capacity_;
}

template <typename T>
constexpr void vector<T>::shrink_to_fit() noexcept {
  capacity_ = size_;
}

template <typename T>
constexpr void vector<T>::clear() noexcept {
  for (size_type i = 0; i != capacity_; ++i)
    storage_[i] = static_cast<char>(i + 1);
  size_ = 0;
}

template <typename T>
constexpr typename vector<T>::iterator vector<T>::insert(
    iterator pos, const_reference value) {
  auto index = pos - this->begin();
  if (pos == end()) {
    push_back(value);
  } else {
    value_type last_element = *(this->end() - 1);
    for (auto i = this->end() - 1; i != pos; --i) *i = *(i - 1);
    *pos = value;
    if (size_ == capacity_) {
      value_type *temp = new value_type[capacity_];
      for (size_t i = 0; i != capacity_; ++i) {
        temp[i] = 0;
      }
      for (size_type i = 0; i != capacity_; ++i) temp[i] = storage_[i];
      delete[] storage_;
      capacity_ *= 2;
      storage_ = new value_type[capacity_];
      for (size_type i = 0; i != size_; ++i) storage_[i] = temp[i];
      delete[] temp;
    }
    storage_[size_++] = last_element;
  }
  return this->begin() + index;
}

template <typename T>
constexpr void vector<T>::erase(
    iterator pos) noexcept {  // delete element move other shit to left size--
                              // capacity state iter income
  for (auto i = pos; i != this->end() - 1; ++i) *i = *(i + 1);
  --size_;
}

template <typename T>
constexpr void vector<T>::push_back(const_reference value) {
  if (capacity_ != 0) {
    this->reserve(size_ * 2);
    value_type temp[size_];
    for (size_type i = 0; i != size_; i++) temp[i] = storage_[i];
    delete[] storage_;
    storage_ = new value_type[capacity_];
    for (size_type i = 0; i != size_; i++) storage_[i] = temp[i];
    for (size_type i = size_; i != capacity_; i++) storage_[i] = T();
  } else {
    storage_ = new value_type[1];
    capacity_ = 1;
  }
  storage_[size_++] = value;
}

template <typename T>
constexpr void vector<T>::pop_back() noexcept {
  --size_;
}
template <typename T>
constexpr void vector<T>::swap(vector &other) noexcept {
  auto mem =
      std::make_tuple(other.size(), other.capacity(), other.GetStorage());
  other.resize(size_);
  other.reserve(capacity_);
  other.SetStorage(storage_);
  size_ = std::get<0>(mem);
  capacity_ = std::get<1>(mem);
  storage_ = std::get<2>(mem);
}
//при [0] а сайз равен 0 то сег фолт

template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  iterator last_inserted = const_cast<iterator>(pos);
  for (auto &&elem : {args...}) {
    last_inserted = insert(last_inserted, elem);
    ++last_inserted;
  }
  return --last_inserted;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args &&...args) {
  for (auto &&elem : {args...}) {
    push_back(elem);
  }
}

};  // namespace s21

#endif  // S21_CONTAINERS_SRC_S21_CONTAINERS_VECTOR_VECTOR_TPP
