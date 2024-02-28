#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_MAP_MAP_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_MAP_MAP_HPP
#include <limits>
#include <stdexcept>
#include <utility>

#include "../node/node.hpp"
#include "../vector/vector.hpp"
namespace s21 {
template <typename K, typename T>
class MapIterator {
 public:
  using value_type = T;
  using key_type = K;
  K first = K();
  T second = T();
  MapIterator() = default;
  MapIterator(Node<K, T> *item) : ptr_(item) {
    if (ptr_) first = ptr_->item;
    if (ptr_) second = ptr_->item_value;
  };
  ~MapIterator() = default;
  constexpr value_type &operator*() { return ptr_->item_value; }
  constexpr MapIterator &operator++() {
    ptr_ = ptr_->next();
    if (ptr_) first = ptr_->item;
    if (ptr_) second = ptr_->item_value;
    return *this;
  }
  constexpr MapIterator &operator--() {
    ptr_ = ptr_->prevElement();
    if (ptr_) first = ptr_->item;
    if (ptr_) second = ptr_->item_value;
    return *this;
  }
  constexpr MapIterator *operator->() { return this; }
  constexpr bool operator==(const MapIterator &iter) const {
    return this->ptr_ == iter.ptr_;
  }
  constexpr bool operator!=(const MapIterator &iter) const {
    return this->ptr_ != iter.ptr_;
  }

 private:
  Node<K, T> *ptr_ = nullptr;
};
template <typename K, typename T>
class MapConstIterator {
 public:
  using value_type = T;
  using key_type = K;
  K first = K();
  T second = T();
  MapConstIterator() = default;
  MapConstIterator(Node<K, T> *item) : ptr_(item) {
    if (ptr_) first = ptr_->item;
    if (ptr_) second = ptr_->item_value;
  };
  ~MapConstIterator() = default;
  constexpr value_type &operator*() { return ptr_->item_value; }
  constexpr MapConstIterator &operator++() {
    ptr_ = ptr_->next();
    if (ptr_) first = ptr_->item;
    if (ptr_) second = ptr_->item_value;
    return *this;
  }
  constexpr MapConstIterator &operator--() {
    ptr_ = ptr_->prevElement();
    if (ptr_) first = ptr_->item;
    if (ptr_) second = ptr_->item_value;
    return *this;
  }
  constexpr MapConstIterator *operator->() { return this; }
  constexpr bool operator==(const MapConstIterator &iter) const {
    return this->ptr_ == iter.ptr_;
  }
  constexpr bool operator!=(const MapConstIterator &iter) const {
    return this->ptr_ != iter.ptr_;
  }

 private:
  Node<K, T> *ptr_ = nullptr;
};

template <typename K, typename T>
class map {
 public:
  using key_type = K;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = MapIterator<K, T>;
  using const_iterator = MapConstIterator<K, T>;
  using size_type = std::size_t;
  constexpr inline map() = default;
  constexpr inline map(
      std::initializer_list<value_type> const &items) noexcept {
    for (auto i = items.begin(); i != items.end(); ++i) {
      insert(*i);
    }
  }
  constexpr inline map(const map &m) noexcept {
    for (auto i = m.cbegin(); i != m.cend(); ++i) {
      insert({i->first, i->second});
    }
  };
  constexpr inline map(map &&m) noexcept {
    if (&m != this) {
      root_ = m.root_;
      m.root_ = nullptr;
    }
  }
  ~map() noexcept { clear(); }
  constexpr inline map &operator=(map &&m) noexcept {
    if (&m != this) {
      root_ = m.root_;
      m.root_ = nullptr;
    }
    return *this;
  }
  constexpr inline T &at(const K &key) {
    auto result = root_->find(key);
    if (result == root_->end()) throw std::out_of_range("map::at");
    return result->item_value;
  }

  constexpr inline T at(const K &key) const {
    auto result = root_->find(key);
    if (result == root_->end()) throw std::out_of_range("map::at");
    return result->item_value;
  }
  constexpr inline T &operator[](const K &key) noexcept {
    auto result = root_->find(key);
    return result->item_value;
  }

  constexpr inline T operator[](const K &key) const noexcept {
    auto result = root_->find(key);
    return result->item_value;
  }

  iterator begin() {
    if (size_ == 0) {
      return MapIterator(root_->end());
    }
    return MapIterator(root_->begin());
  }
  iterator end() { return MapIterator(root_->end()); }
  const_iterator cbegin() const {
    if (size_ == 0) {
      return MapConstIterator(root_->end());
    }
    return MapConstIterator(root_->begin());
  }
  const_iterator cend() const { return MapConstIterator(root_->end()); }
  constexpr inline bool empty() const noexcept { return size_ == 0; }

  constexpr inline size_type size() const noexcept { return size_; }

  constexpr inline size_type max_size() const noexcept {
    return (std::numeric_limits<size_type>::max() / (sizeof(size_type) * 10));
  }

  std::pair<iterator, bool> insert(const value_type &value) {
    bool does_contain = contains(value.first);
    std::pair<iterator, bool> iter{
        !does_contain ? MapIterator(root_) : find(value.first), false};
    if (empty()) {
      root_ = new Node(value.first, value.second);
      ++size_;
    } else {
      if (!does_contain) {
        iter = root_->insert(value.first, value.second);
      }
      std::pair<iterator, bool> result{MapIterator(iter.first), iter.second};
      if (iter.second) {
        ++size_;
      }
    }
    return iter;
  }

  std::pair<iterator, bool> insert(const K &key, const T &obj) {
    return insert({key, obj});
  }

  std::pair<iterator, bool> insert_or_assign(const K &key, const T &obj) {
    if (!contains(key)) {
      return insert({key, obj});
    } else {
      operator[](key) = obj;
      return {find(key), true};
    }
  }
  void erase(iterator pos) {
    // root_ = root_->erase(root_->find(*pos));
    if (pos != end()) {
      auto iter = root_->find(pos->first);
      root_ = root_->erase(iter);
      --size_;
    }
  }
  void swap(map &other) {
    auto temp = other.root_;
    auto temp_size = other.size_;
    other.root_ = root_;
    other.size_ = size_;
    root_ = temp;
    size_ = temp_size;
  }
  void merge(map &other) {
    s21::vector<key_type> to_delete;
    for (auto iter = other.begin(); iter != other.end(); ++iter) {
      if (!contains(iter->first)) {
        to_delete.push_back(iter->first);
        insert({iter->first, iter->second});
      }
    }
    for (size_t i = 0; i < to_delete.size(); ++i) {
      other.erase(other.find(to_delete[i]));
    }
  }
  constexpr inline void clear() noexcept {
    if (root_ != nullptr) {
      delete root_->getHead();
      root_ = nullptr;
    }
    size_ = 0;
  }
  constexpr inline bool contains(const K &key) const noexcept {
    return root_->find(key) != root_->end();
  }

  template <typename... Args>
  vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    s21::vector<std::pair<iterator, bool>> result;
    for (auto &&elem : {args...}) {
      result.push_back(insert_or_assign(elem.first, elem.second));
    }
    return result;
  }

 protected:
  iterator find(const key_type &key) { return MapIterator(root_->find(key)); };

 private:
  size_type size_ = 0;
  Node<key_type, mapped_type> *root_ = nullptr;
};
};  // namespace s21

#endif  // S21_CONTAINERS_SRC_S21_CONTAINERS_MAP_MAP_HPP
