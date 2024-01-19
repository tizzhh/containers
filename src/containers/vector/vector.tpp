#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_VECTOR_VECTOR_TPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_VECTOR_VECTOR_TPP

namespace s21 {
  // template<typename T>
  // constexpr typename vector<T>::size_type vector<T>::CapacityCalc(size_type amount_of_elements) const noexcept{
  //   return 1 << ((size_type)log2(amount_of_elements) + 1);
  // }

  template <typename T>
  constexpr vector<T>::vector() : capacity_(0), size_(0) {};

  template <typename T>
  constexpr vector<T>::vector(size_type n) : capacity_(n), size_(n) {
    storage_ = new T[n]();
    if(!storage_) throw std::bad_alloc();
  };

  template <typename T>
  constexpr vector<T>::vector(std::initializer_list<value_type> const &items) : capacity_(items.size()), size_(items.size()) {
    storage_ = new T[items.size()];
    if(!storage_) throw std::bad_alloc();
    size_type i = 0;
    for(auto val : items) storage_[i++] = val;
  }

  template <typename T> 
  constexpr vector<T>::vector(const vector& a) : capacity_(a.size()), size_(a.size()){
    storage_ = new T[a.size()]();
    if(!storage_) throw std::bad_alloc();
    for(size_t i = 0;i != a.size();++i) storage_[i] = a[i];
  }

  template <typename T>
  constexpr vector<T>::vector(vector&& a) : capacity_(a.capacity()), size_(a.size()) {
    storage_ = a.GetStorage();
    a.SetStorage(nullptr);
    capacity_ = a.GetCapacity();
    a.SetCapacity(0);
    size_ = a.GetSize();
    a.SetSize(0);
  }
  template <typename T>
  vector<T>::~vector() {
    delete[] storage_;
  }

  template <typename T>
  constexpr typename vector<T>::reference vector<T>::operator[](const size_type& pos) {
    return /*pos > size_ ? 0 :*/ storage_[pos];
  }

  template <typename T>
  constexpr typename vector<T>::const_reference vector<T>::operator[](const size_type& pos) const{
    return /*pos > size_ ? 0 :*/ storage_[pos];
  }
  
  template <typename T>
  constexpr void vector<T>::SetStorage(iterator value) noexcept {
    storage_ = value;
  }

  template <typename T>
  constexpr void vector<T>::SetSize(size_t num) noexcept {
    size_ = num;
  }

  template <typename T>
  constexpr void vector<T>::SetCapacity(size_t num) noexcept {
    capacity_ = num;
  }

  template <typename T>
  constexpr typename vector<T>::iterator vector<T>::GetStorage() const noexcept {
    return storage_;
  }

  template <typename T>
  constexpr typename vector<T>::size_type vector<T>::GetSize() const noexcept {
    return size_;
  }

  template <typename T>
  constexpr typename vector<T>::size_type vector<T>::GetCapacity() const noexcept {
    return capacity_;
  }
  //при [0] а сайз равен 0 то сег фолт
};

#endif // S21_CONTAINERS_SRC_S21_CONTAINERS_VECTOR_VECTOR_TPP