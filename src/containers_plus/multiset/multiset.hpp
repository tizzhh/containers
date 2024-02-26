#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_PLUS_MULTISET_MULTISET_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_PLUS_MULTISET_MULTISET_HPP

#include "../../containers/set/set.hpp"

namespace s21
{
template <typename K> class multiset : public set<K> {
public:
  using key_type = K;
  using value_type = K;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = SetIterator<value_type>;
  using const_iterator = SetConstIterator<value_type>;
  using size_type = size_t;
  constexpr multiset() = default;
  constexpr multiset(std::initializer_list<value_type> const &items) {
    for (auto i = items.begin(); i != items.end(); ++i)
      this->insert(*i);
  }
  constexpr multiset(const multiset &s) {
    for (auto iter = s.cbegin(); iter != s.cend(); ++iter) {
      this->insert(*iter);
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
  ~multiset() {
    this->clear();
  }

  constexpr bool empty() { return size_ == 0; }

std::pair<iterator, bool> insert(const value_type &value) {
    std::pair<iterator, bool> iter{root_, false};
    if (this->empty()) {
        root_ = new Node(value);
        ++size_;
    } else {
        iter = root_->insert(value);
      std::pair<iterator, bool> result{SetIterator(iter.first), iter.second};
      if (iter.second) {
        ++size_;
      }
    }
    return iter;
  }

private:
  size_type size_ = 0;
  Node<value_type> *root_ = nullptr;
};
}; // namespace s21


#endif // S21_CONTAINERS_SRC_S21_CONTAINERS_PLUS_MULTISET_MULTISET_HPP