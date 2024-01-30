#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_TPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_TPP

namespace s21 {
// List Functions
template <typename T>
list<T>::list() {
  node *head = new node();
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
  for (const auto &elem : l) {
    push_back(elem);
  }
}

template <typename T>
list<T>::list(list &&l) : front_(l.front_), back_(l.back_), size_(l.size_) {
  node *head = new node();
  l.front_ = head;
  l.back_ = head;
  l.size_ = 0;
}

template <typename T>
list<T> &list<T>::operator=(list &&l) {
  front_ = l.front_;
  back_ = l.back_;
  size_ = l.size_;
  node *head = new node();
  l.front_ = head;
  l.back_ = head;
  l.size_ = 0;
  return *this;
}

template <typename T>
list<T>::~list() {
  node *pointer = front_;
  node *next = pointer;
  while (pointer != nullptr) {
    node *next = pointer->next;
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
    node *new_elem = new node();
    new_elem->data = value;
    back_->next = new_elem;
    new_elem->prev = back_;
    back_ = new_elem;
  }
  size_++;
}

// List Element access
template <typename T>
typename list<T>::const_reference list<T>::back() {
  return back_->data;
}

template <typename T>
typename list<T>::const_reference list<T>::front() {
  return front_->data;
}

// List capacity
template <typename T>
typename list<T>::size_type list<T>::size() {
  return size_;
}
}  // namespace s21

#endif