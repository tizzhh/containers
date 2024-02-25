#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_SET_SET_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_SET_SET_HPP

#include "../node/node.hpp"
#include "../vector/vector.hpp"
#include <iostream>
#include <limits>
namespace s21 {
  template <typename T> class SetIterator {
  public:
    using value_type = T;
    SetIterator(Node<T> *item) : ptr_(item){};
    ~SetIterator() = default;
    constexpr value_type &operator*() { return ptr_->item; }
    constexpr SetIterator &operator++() {
      ptr_ = ptr_->next();
      return *this;
    }
    constexpr SetIterator &operator--() {
      ptr_ = ptr_->prevElement();
      return *this;
    }
    constexpr bool operator==(const SetIterator &iter) const {
      return this->ptr_ == iter.ptr_;
    }
    constexpr bool operator!=(const SetIterator &iter) const {
      return this->ptr_ != iter.ptr_;
    }

  private:
    Node<T> *ptr_ = nullptr;
  };
  // хз как сделать чтоб оно работало с наследованием, у меня конструктор
  // нормально не робит :(
  // template <typename T> class SetConstIterator : public SetIterator<T> {
  // public:
  //   using value_type = T;
  //   SetConstIterator(Node<T> *item) : SetIterator<T>(item){};
  //   ~SetConstIterator() = default;
  //   constexpr value_type operator*() const { return ptr_->item; }

  // private:
  //   Node<T> *const ptr_ = nullptr;
  // };
    template <typename T> class SetConstIterator {
  public:
    using value_type = T;
    SetConstIterator(Node<T> *item) : ptr_(item){};
    ~SetConstIterator() = default;
    constexpr value_type operator*() const { return ptr_->item; }
    constexpr SetConstIterator &operator++() {
      ptr_ = ptr_->next();
      return *this;
    }
    constexpr SetConstIterator &operator--() {
      ptr_ = ptr_->prevElement();
      return *this;
    }
    // не помню, что мы обсуждали насчет сравнения, но
    // стд итер не по значению сравнивает
    constexpr bool operator==(const SetConstIterator &iter) const {
      return this->ptr_ == iter.ptr_;
    }
    constexpr bool operator!=(const SetConstIterator &iter) const {
      return this->ptr_ != iter.ptr_;
    }

  private:
    Node<T> *ptr_ = nullptr;
  };

template <typename K> class set {
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
    for (auto i = items.begin(); i != items.end(); ++i)
      root_->insert(*i);
  }
  constexpr set(const set &s) {
    for (auto iter = s.cbegin(); iter != s.cend(); ++iter) {
      insert(*iter);
    }
  }
  constexpr set(set &&s) {
    if (&s != this) {
      root_ = s.root_;
      s.root_ = nullptr;
    }
  }
  constexpr set &operator=(set &&s) noexcept {
    if (&s != this) {
      root_ = s.root_;
      s.root_ = nullptr;
    }
    return *this;
  }
  ~set() {
    clear();
  }

  iterator begin() { return SetIterator(root_->begin()); }
  iterator end() { return SetIterator(root_->end()); }
  const_iterator cbegin() const { return SetConstIterator(root_->begin()); }
  const_iterator cend() const { return SetConstIterator(root_->end()); }
  constexpr bool empty() { return size_ == 0; }
  constexpr size_type size() { return size_; }
  constexpr size_type max_size() {
    return std::numeric_limits<std::size_t>::max() / sizeof(set<value_type>) / 2;
  }
  void clear() { 
    if (root_ != nullptr) {
      delete root_->getHead();
      root_ = nullptr;
    }
    size_ = 0;
  }
  std::pair<iterator, bool> insert(const value_type &value) {
    std::pair<iterator, bool> iter{root_, true};
    if (empty()) {
      root_ = new Node(value);
    } else {
      iter = root_->insert(value);
    }
    std::pair<iterator, bool> result{SetIterator(iter.first), iter.second};
    if (result.second) {
      ++size_;
    }
    return result;
  }
  void erase(iterator pos) {
    // root_ = root_->erase(root_->find(*pos));
    auto iter = root_->find(*pos);
    root_ = root_->erase(iter);
    --size_;  
  }
  void swap(set &other) {
    auto temp = other.root_;
    other.root_ = root_;
    root_ = temp;
  }
  void merge(set &other) {
    s21::vector<value_type> to_delete;
    for (auto i : other) {
      if (!contains(i)) {
        to_delete.push_back(i);
        insert(i);
      }
    }
    for (size_t i = 0; i < to_delete.size(); ++i) {
      other.erase(other.find(to_delete[i]));
    }
  }
  iterator find(const key_type &key) { return SetIterator(root_->find(key)); };
  bool contains(const key_type &key) { return root_->find(key) != root_->end(); }

private:
  size_type size_ = 0;
  Node<value_type> *root_ = nullptr;
};
}; // namespace s21

#endif // S21_CONTAINERS_SRC_S21_CONTAINERS_SET_SET_HPP
