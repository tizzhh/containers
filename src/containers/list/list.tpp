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
constexpr list<T>::list() {
  alloc_new_front_back_end_();
}

template <typename T>
constexpr list<T>::list(size_type n) : list() {
  for (size_t i = 0; i < n; ++i) {
    push_back(T());
  }
}

template <typename T>
constexpr list<T>::list(std::initializer_list<value_type> const &items)
    : list() {
  for (const auto &elem : items) {
    push_back(elem);
  }
}

template <typename T>
constexpr list<T>::list(const list &l) : list() {
  for (const auto &elem : l) {
    push_back(elem);
  }
}

template <typename T>
constexpr list<T>::list(list &&l)
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
constexpr list<T> &list<T>::operator=(list &&l) {
  auto front_temp = front_, back_temp = back_, end_temp = end_;
  auto size_temp = size_;

  front_ = l.front_;
  back_ = l.back_;
  size_ = l.size_;
  end_ = l.end_;
  back_->next = end_;
  end_->prev = back_;

  l.front_ = front_temp;
  l.back_ = back_temp;
  l.end_ = end_temp;
  l.size_ = size_temp;
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
  if (empty()) {
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
  if (empty()) {
    throw std::length_error("Container is empty!");
  }
  node<T> *temp = back_;
  back_ = back_->prev;
  delete temp;
  --size_;
  if (empty()) {
    delete end_;
    alloc_new_front_back_end_();
  } else {
    move_end_ptr_();
  }
}

template <typename T>
void list<T>::push_front(const_reference value) {
  if (empty()) {
    front_->data = value;
  } else {
    node<T> *new_elem = new node<T>();
    new_elem->data = value;
    new_elem->next = front_;
    front_->prev = new_elem;
    front_ = new_elem;
  }
  ++size_;
}

template <typename T>
void list<T>::pop_front() {
  if (empty()) {
    throw std::length_error("Container is empty!");
  } else {
    node<T> *temp = front_;
    front_ = front_->next;
    front_->prev = nullptr;
    delete temp;
  }
  --size_;
  if (empty()) {
    delete end_;
    alloc_new_front_back_end_();
  }
}

template <typename T>
void list<T>::swap(list &other) {
  if (other.front_ != this->front_) {
    std::swap(front_, other.front_);
    std::swap(back_, other.back_);
    std::swap(end_, other.end_);
    std::swap(size_, other.size_);
  }
}

template <typename T>
void list<T>::splice(const_iterator pos, list &other) {
  for (const auto &elem : other) {
    insert(pos, elem);
  }
  other.clear();
}

template <typename T>
void list<T>::reverse() {
  auto it = begin();
  while (it != end()) {
    auto next = it->next;
    it->next = it->prev;
    it->prev = next;
    it = next;
  }
  node<T> *temp = front_;
  front_ = back_;
  back_ = temp;
  move_end_ptr_();
}

template <typename T>
void list<T>::unique() {
  auto prev = T();
  auto it = begin();
  ++it;
  while (it != end()) {
    auto next = it->next;
    auto it_val = *it;
    if (it_val == prev) {
      erase(it);
    }
    prev = it_val;
    it = next;
  }
}

template <typename T>
void list<T>::merge(list &other) {
  if (front_ != other.front_ && !other.empty()) {
    if (empty()) {
      swap(other);
      return;
    }

    if (!check_if_list_sorted_() or !other.check_if_list_sorted_()) {
      throw std::logic_error("Lists should be sorted");
    }
    auto temp = list(size_ + other.size_);
    auto it1 = begin();
    auto it2 = other.begin();
    for (auto new_iter = temp.begin(); new_iter != temp.end(); ++new_iter) {
      if (it1 == end()) {
        *new_iter = *it2;
        ++it2;
      } else if (it2 == other.end()) {
        *new_iter = *it1;
        ++it1;
      } else {
        if (*it1 <= *it2) {
          *new_iter = *it1;
          ++it1;
        } else {
          *new_iter = *it2;
          ++it2;
        }
      }
    }
    swap(temp);
    other.clear();
  }
}

template <typename T>
bool list<T>::check_if_list_sorted_() {
  auto prev = T();
  bool is_eq = true;
  for (auto iter = begin(); iter != end() && is_eq; ++iter) {
    if (*iter < prev) {
      is_eq = false;
    }
    prev = *iter;
  }
  return is_eq;
}

template <typename T>
void list<T>::sort() {
  if (!empty()) {
    vector<T> a;
    for (auto iter = begin(); iter != end(); ++iter) {
      a.push_back(*iter);
    }
    std::sort(a.begin(), a.end());
    clear();
    for (const auto &elem : a) {
      push_back(elem);
    }
  }
}

template <typename T>
template <typename... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args &&...args) {
  iterator last_inserted;
  for (auto &&elem : {args...}) {
    last_inserted = insert(pos, elem);
  }
  return last_inserted;
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_back(Args &&...args) {
  for (auto &&elem : {args...}) {
    push_back(elem);
  }
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_front(Args &&...args) {
  for (auto &&elem : {args...}) {
    push_front(elem);
  }
}

// List Element access
template <typename T>
constexpr typename list<T>::const_reference list<T>::back() const noexcept {
  return back_->data;
}

template <typename T>
constexpr typename list<T>::const_reference list<T>::front() const noexcept {
  return front_->data;
}

// List Iterators
template <typename T>
constexpr typename list<T>::iterator list<T>::begin() noexcept {
  return ListIterator(front_);
}

template <typename T>
constexpr typename list<T>::iterator list<T>::end() noexcept {
  return ListIterator(end_);
}

template <typename T>
constexpr typename list<T>::const_iterator list<T>::begin() const noexcept {
  return ListConstIterator(front_);
}

template <typename T>
constexpr typename list<T>::const_iterator list<T>::end() const noexcept {
  return ListConstIterator(end_);
}

// List capacity
template <typename T>
constexpr bool list<T>::empty() const noexcept {
  return size_ == 0;
}

template <typename T>
constexpr typename list<T>::size_type list<T>::max_size() const noexcept {
  return std::numeric_limits<std::size_t>::max() / sizeof(node<T>) / 2;
}

template <typename T>
constexpr typename list<T>::size_type list<T>::size() const noexcept {
  return size_;
}
}  // namespace s21

#endif