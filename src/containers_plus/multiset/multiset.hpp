#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_PLUS_MULTISET_MULTISET_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_PLUS_MULTISET_MULTISET_HPP

#include "../../containers/set/set.hpp"

namespace s21 {
template <typename T>
class MultiSetIterator {
 public:
  using value_type = T;
  MultiSetIterator() = default;
  MultiSetIterator(Node<T> *item) : ptr_(item){};
  ~MultiSetIterator() = default;
  constexpr value_type &operator*() { return ptr_->item; }
  constexpr MultiSetIterator &operator++() {
    ptr_ = ptr_->next();
    return *this;
  }
  constexpr MultiSetIterator &operator--() {
    ptr_ = ptr_->prevElement();
    return *this;
  }
  constexpr bool operator==(const MultiSetIterator &iter) const {
    return this->ptr_ == iter.ptr_;
  }
  constexpr bool operator!=(const MultiSetIterator &iter) const {
    return this->ptr_ != iter.ptr_;
  }

 private:
  Node<T> *ptr_ = nullptr;
};
template <typename T>
class MultisetConstIterator {
 public:
  using value_type = T;
  MultisetConstIterator() = default;
  MultisetConstIterator(Node<T> *item) : ptr_(item){};
  ~MultisetConstIterator() = default;
  constexpr value_type operator*() const { return ptr_->item; }
  constexpr MultisetConstIterator &operator++() {
    ptr_ = ptr_->next();
    return *this;
  }
  constexpr MultisetConstIterator &operator--() {
    ptr_ = ptr_->prevElement();
    return *this;
  }
  constexpr bool operator==(const MultisetConstIterator &iter) const {
    return this->ptr_ == iter.ptr_;
  }
  constexpr bool operator!=(const MultisetConstIterator &iter) const {
    return this->ptr_ != iter.ptr_;
  }

 private:
  Node<T> *ptr_ = nullptr;
};

template <typename K>
class multiset : public set<K> {
 public:
  using key_type = K;
  using value_type = K;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = MultiSetIterator<value_type>;
  using const_iterator = MultisetConstIterator<value_type>;
  using size_type = size_t;
  constexpr multiset() = default;
  constexpr multiset(std::initializer_list<value_type> const &items) {
    for (auto i = items.begin(); i != items.end(); ++i) insert(*i);
  }
  constexpr multiset(const multiset &s) : set<K>(s) {
    for (auto iter = s.cbegin(); iter != s.cend(); ++iter) {
      insert(*iter);
    }
  }
  constexpr multiset(multiset &&s) {
    if (&s != this) {
      root_ = s.root_;
      s.root_ = nullptr;
    }
  }
  constexpr multiset &operator=(multiset &&s) noexcept {
    if (&s != this) {
      root_ = s.root_;
      s.root_ = nullptr;
    }
    return *this;
  }
  ~multiset() { clear(); }

  iterator begin() {
    if (size_ == 0) {
      return MultiSetIterator(root_->end());
    }
    return MultiSetIterator(root_->begin());
  }
  iterator end() { return MultiSetIterator(root_->end()); }
  const_iterator cbegin() const {
    if (size_ == 0) {
      return MultisetConstIterator(root_->end());
    }
    return MultisetConstIterator(root_->begin());
  }
  const_iterator cend() const { return MultisetConstIterator(root_->end()); }
  constexpr bool empty() { return size_ == 0; }
  constexpr size_type size() { return size_; }
  constexpr size_type max_size() {
    return (std::numeric_limits<size_type>::max() / (sizeof(size_type) * 10));
  }
  void clear() {
    if (root_ != nullptr) {
      delete root_->getHead();
      root_ = nullptr;
    }
    size_ = 0;
  }
  iterator insert(const value_type &value) {
    iterator iter = root_;
    if (empty()) {
      root_ = new Node(value);
    } else {
      iter = root_->insert(value).first;
    }
    ++size_;
    return iter;
  }
  void erase(iterator pos) {
    if (pos != end()) {
      auto iter = root_->find(*pos);
      root_ = root_->erase(iter);
      --size_;
    }
  }
  void swap(multiset &other) {
    auto temp = other.root_;
    auto temp_size = other.size_;
    other.root_ = root_;
    other.size_ = size_;
    root_ = temp;
    size_ = temp_size;
  }
  void merge(multiset &other) {
    s21::vector<value_type> to_delete;
    for (auto i : other) {
      to_delete.push_back(i);
      insert(i);
    }
    for (size_t i = 0; i < to_delete.size(); ++i) {
      other.erase(other.find(to_delete[i]));
    }
  }
  size_type count(const key_type &key) {
    auto iter = begin();
    size_type res = 0;
    while (iter != end()) {
      if (*iter > key) {
        break;
      }
      if (*iter == key) {
        ++res;
      }
      ++iter;
    }
    return res;
  }
  iterator find(const key_type &key) {
    return MultiSetIterator(root_->find(key));
  }
  bool contains(const key_type &key) {
    return root_->find(key) != root_->end();
  }
  std::pair<iterator, iterator> equal_range(const key_type &key) {
    return {lower_bound(key), upper_bound(key)};
  }
  iterator lower_bound(const key_type &key) {
    auto iter = begin();
    while (*iter < key) {
      ++iter;
    }
    return iter;
  }
  iterator upper_bound(const key_type &key) {
    auto iter = begin();
    while (*iter <= key) {
      ++iter;
    }
    return iter;
  }

  template <typename... Args>
  vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    s21::vector<std::pair<iterator, bool>> result;
    for (auto &&elem : {args...}) {
      result.push_back({insert(elem), true});
    }
    return result;
  }

 private:
  size_type size_ = 0;
  Node<value_type> *root_ = nullptr;
};
};  // namespace s21

#endif  // S21_CONTAINERS_SRC_S21_CONTAINERS_PLUS_MULTISET_MULTISET_HPP