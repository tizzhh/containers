#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_SET_SET_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_SET_SET_HPP

#include <iostream>
#include <limits>

#include "../node/node.hpp"
namespace s21 {
template <typename K>
class SetIterator;
template <typename K>
class SetConstIterator;
template <typename K>
class set {
 public:
  using key_type = K;
  using value_type = K;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = SetIterator<value_type>;
  using const_iterator = SetConstIterator<value_type>;
  using size_type = size_t;
  constexpr set() = default;
  constexpr set(std::initializer_list<value_type> const &items)
      : size_(items.size()) {
    root_ = new Node(*items.begin());
    for (auto i = items.begin(); i != items.end(); ++i) root_->insert(*i);
  }
  constexpr set(const set &s) : root_(s.root_) {}
  constexpr set(set &&s) {
    auto temp = std::move(s);
    root_ = temp.root_;
  }
  constexpr set &operator=(set &&a) noexcept {
    auto temp = std::move(a);
    root_ = temp.root_;
  }
  ~set() { clear(); }

  iterator begin() { return SetIterator(root_->begin()); }
  iterator end() { return SetIterator(root_->end()); }
  const_iterator cbegin() const { return SetConstIterator(root_->begin()); }
  const_iterator cend() const { return SetConstIterator(root_->end()); }
  constexpr bool empty() { return size_ == 0; }
  constexpr size_type size() { return size_; }
  constexpr size_type max_size() {
    return std::numeric_limits<size_type>::max() / sizeof(set<value_type>) / 2;
  }
  void clear() {
    if (root_ != nullptr) {
      delete root_->getHead();
      root_ = nullptr;
    }
  }
  std::pair<iterator, bool> insert(const value_type &value) {
    auto iter = root_->insert(value);
    std::pair<iterator, bool> result{SetIterator(iter.first), iter.second};
    return result;
  }
  void erase(iterator pos) { root_->erase(root_->find(*pos)); }
  void swap(set &other) {
    auto temp = other.root_;
    other.root_ = root_;
    root_ = temp;
  }
  void merge(set &other) {
    for (auto i : other) {
      insert(*i);
    }
  }
  iterator find(const key_type &key) { return SetIterator(root_->find(key)); };
  bool contains(const key_type &key) { return root_->find() != root_->end(); }

 protected:
  template <typename T>
  class SetIterator {
   public:
    using value_type = T;
    SetIterator(Node<T> *item) : ptr_(item){};
    ~SetIterator() = default;
    constexpr value_type &operator*() { return ptr_->item; }
    constexpr SetIterator &operator++() { return SetIterator(ptr_->next()); }
    constexpr SetIterator &operator--() {
      return SetIterator(ptr_->prevElement());
    }
    constexpr bool operator==(const SetIterator &iter) const {
      return this->ptr_->item == iter->ptr_->item;
    }
    constexpr bool operator!=(const SetIterator &iter) const {
      return this->ptr_->item != iter->ptr_->item;
    }

   private:
    Node<T> *const ptr_ = nullptr;
  };
  template <typename T>
  class SetConstIterator : public SetIterator<T> {
   public:
    using value_type = T;
    SetConstIterator(Node<T> *item) : ptr_(item){};
    ~SetConstIterator() = default;
    constexpr value_type operator*() const { return ptr_->item; }

   private:
    Node<T> *const ptr_ = nullptr;
  };

 private:
  size_type size_ = 0;
  Node<value_type> *root_ = nullptr;
};
};  // namespace s21

#endif  // S21_CONTAINERS_SRC_S21_CONTAINERS_SET_SET_HPP
