#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_TPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_TPP

namespace s21 {
// List Functions
template <typename T>
list<T>::list() {
  // здесь такая хуйня по причине того, что стд лист
  // возвращает T() для пустого листа.
  // То же самое касается и мува, опер= и клира
  node<T> *head = new node<T>();
  front_ = back_ = head;
}

template <typename T>
list<T>::list(size_type n) : list() {
  for (int i = 0; i < n; ++i) {
    push_back(T());
  }
}

template <typename T>
list<T>::list(std::initializer_list<value_type> const &items) : list() {
  for (const auto &elem : items) {
    push_back(elem);
  }
}

template <typename T>
list<T>::list(const list &l) : list() {
  // не понимаю, как сделать этот конструктор
  // нам нужен КОНСТ итератор, который НЕ имеет ++ и -- методов
  // тем не менее, стд лист как-то работает, используя конст итератор.
  for (const auto &elem : l) {
    push_back(elem);
  }
}

template <typename T>
list<T>::list(list &&l) : front_(l.front_), back_(l.back_), size_(l.size_) {
  node<T> *head = new node<T>();
  l.front_ = head;
  l.back_ = head;
  l.size_ = 0;
}

template <typename T>
list<T> &list<T>::operator=(list &&l) {
  front_ = l.front_;
  back_ = l.back_;
  size_ = l.size_;
  node<T> *head = new node<T>();
  l.front_ = head;
  l.back_ = head;
  l.size_ = 0;
  return *this;
}

template <typename T>
list<T>::~list() {
  node<T> *pointer = front_;
  node<T> *next = pointer;
  while (pointer != nullptr) {
    node<T> *next = pointer->next;
    delete pointer;
    pointer = next;
  }
  front_ = back_ = nullptr;
}

// List Modifiers
template <typename T>
void list<T>::push_back(const_reference value) {
  if (size_ == 0) {
    front_->data = value;
  } else {
    node<T> *new_elem = new node<T>();
    new_elem->data = value;
    back_->next = new_elem;
    new_elem->prev = back_;
    back_ = new_elem;
  }
  size_++;
}

// List Element access
template <typename T>
typename list<T>::const_reference list<T>::back() const {
  return back_->data;
}

template <typename T>
typename list<T>::const_reference list<T>::front() const {
  return front_->data;
}

// List Iterators
template <typename T>
typename list<T>::iterator list<T>::begin() {
  return ListIterator(front_);
}

template <typename T>
typename list<T>::iterator list<T>::end() {
  return ListIterator(back_->next);
}

template <typename T>
typename list<T>::const_iterator list<T>::begin() const {
  return ListConstIterator(front_);
}

template <typename T>
typename list<T>::const_iterator list<T>::end() const {
  return ListConstIterator(back_->next);
}

// List capacity
template <typename T>
bool list<T>::empty() {
  return size_ != 0;
}

template <typename T>
typename list<T>::size_type list<T>::max_size() {
  return std::numeric_limits<std::size_t>::max() / sizeof(value_type);
}

template <typename T>
typename list<T>::size_type list<T>::size() {
  return size_;
}
}  // namespace s21

#endif