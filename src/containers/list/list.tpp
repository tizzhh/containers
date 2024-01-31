#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_TPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_TPP

namespace s21 {
// Helper methods
template <typename T>
void list<T>::alloc_new_front_back_end_() {
  node<T> *head = new node<T>();
  front_ = back_ = head;
  size_ = 0;

  node<T> *end = new node<T>();
  end_ = end;
  back_->next = end_;
  end_->prev = back_;
}

template <typename T>
void list<T>::move_end_ptr_() {
  back_->next = end_;
  end_->prev = back_;
}

// List Functions
template <typename T>
list<T>::list() {
  // здесь такая хуйня по причине того, что стд лист
  // возвращает T() для пустого листа.
  // То же самое касается и мува, опер= и клира.
  // Я бы вообще сделал для пустого нуллптр для всего нах +
  // исключения при попытке к ним обратиться. В конце решим(у) чо делать
  alloc_new_front_back_end_();
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
  // не понимаю, как сделать этот конструктор нормально
  // нам нужен КОНСТ итератор, который НЕ имеет ++ и -- перегрузов.
  // тем не менее стд лист как-то работает, используя конст итератор.
  for (const auto &elem : l) {
    push_back(elem);
  }
}

template <typename T>
list<T>::list(list &&l)
    : front_(l.front_), back_(l.back_), size_(l.size_), end_(l.end_) {
  node<T> *head = new node<T>();
  l.front_ = head;
  l.back_ = head;
  l.size_ = 0;
  node<T> *end = new node<T>();
  l.end_ = end;
  l.back_->next = l.end_;
  l.end_->prev = l.back_;
}

template <typename T>
list<T> &list<T>::operator=(list &&l) {
  front_ = l.front_;
  back_ = l.back_;
  size_ = l.size_;
  back_->next = end_;
  end_->prev = back_;
  node<T> *head = new node<T>();
  l.front_ = head;
  l.back_ = head;
  l.size_ = 0;
  node<T> *end = new node<T>();
  l.end_ = end;
  l.back_->next = l.end_;
  l.end_->prev = l.back_;
  return *this;
}

template <typename T>
list<T>::~list() {
  clear();
  delete end_;
  delete front_;
}

// List Modifiers
template <typename T>
void list<T>::clear() {
  while (front_ != nullptr) {
    node<T> *next = front_->next;
    delete front_;
    front_ = next;
  }
  front_ = back_ = nullptr;
  alloc_new_front_back_end_();
}

template <typename T>
void list<T>::erase(iterator pos) {
  if (pos == end()) {
    // std::erase в таком случае даст сегу, что является кринжем,
    // поэтому я поменял поведение
    pos = pos->prev;
    pos->prev->next = nullptr;
    back_ = pos->prev;
  } else {
    if (pos->prev != nullptr) {
      pos->prev->next = pos->next;
    } else {
      front_ = front_->next;
    }

    if (pos->next != end().get_ptr()) {
      pos->next->prev = pos->prev;
    } else {
      back_ = back_->prev;
    }
  }
  delete pos.get_ptr();
  move_end_ptr_();
  --size_;
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  node<T> *new_elem = new node<T>();
  new_elem->data = value;
  new_elem->next = pos.get_ptr();

  // придумать мб еще что-то здесь
  if (pos == end()) {
    back_->next = new_elem;
    new_elem->prev = back_;
    back_ = new_elem;
  } else {
    new_elem->prev = pos->prev;

    if (pos->prev != nullptr) {
      pos->prev->next = new_elem;
    } else {
      front_ = new_elem;
    }

    pos->prev = new_elem;

    if (pos->next != nullptr) {
      pos->next->prev = new_elem;
    }
  }
  move_end_ptr_();
  ++size_;
  return ListIterator(new_elem);
}

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
  move_end_ptr_();
  ++size_;
}

template <typename T>
void list<T>::pop_back() {
  if (size_ == 0) {
    throw std::length_error("Container is empty!");
  }
  node<T> *temp = back_;
  back_ = back_->prev;
  delete temp;
  --size_;
  if (size_ == 0) {
    alloc_new_front_back_end_();
  } else {
    move_end_ptr_();
  }
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
  return ListIterator(end_);
}

template <typename T>
typename list<T>::const_iterator list<T>::begin() const {
  return ListConstIterator(front_);
}

template <typename T>
typename list<T>::const_iterator list<T>::end() const {
  return ListConstIterator(end_);
}

// List capacity
template <typename T>
bool list<T>::empty() {
  return size_ == 0;
}

template <typename T>
typename list<T>::size_type list<T>::max_size() {
  return std::numeric_limits<std::size_t>::max() / sizeof(node<T>) / 2;
}

template <typename T>
typename list<T>::size_type list<T>::size() {
  return size_;
}
}  // namespace s21

#endif