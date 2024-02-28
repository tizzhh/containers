#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_NODE_NODE_TPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_NODE_NODE_TPP
#include "node.hpp"

namespace s21 {
template <typename T, typename K>
constexpr Node<T, K>::Node() = default;
template <typename T, typename K>
constexpr Node<T, K>::Node(T item) : item(item), item_value(item){};
template <typename T, typename K>
constexpr Node<T, K>::Node(T item, K item_value)
    : item(item), item_value(item_value){};

template <typename T, typename K>
constexpr Node<T, K>::Node(T item, Node *prev)
    : item(item), item_value(item), prev(prev){};

template <typename T, typename K>
constexpr Node<T, K>::Node(T item, K item_value, Node<T, K> *prev)
    : item(item), item_value(item_value), prev(prev){};

template <typename T, typename K>
Node<T, K>::~Node() {
  clear();
}

template <typename T, typename K>
constexpr Node<T, K> *Node<T, K>::begin() {
  Node *temp = getHead();
  while (temp && temp->left) temp = temp->left;
  return temp;
}

template <typename T, typename K>
constexpr Node<T, K> *Node<T, K>::end() {
  return &end_;
}

template <typename T, typename K>
constexpr Node<T, K> *Node<T, K>::lastElement() {
  auto iter = getHead();
  while (iter->right) iter = iter->right;
  return iter;
}

template <typename T, typename K>
constexpr Node<T, K> *Node<T, K>::next() {
  if (this == lastElement()) return this->end();
  if (right) {
    Node *res = right;
    while (res->left) res = res->left;
    return res;
  } else {
    Node *res = this;
    while (res->prev && res == res->prev->right) {
      res = res->prev;
    }
    return (res->prev) ? res->prev : this->end();
  }
}

template <typename T, typename K>
constexpr Node<T, K> *Node<T, K>::prevElement() {
  if (this == this->begin()) return this->begin();
  if (left) {
    Node *res = left;
    while (res->right) res = res->right;
    return res;
  } else {
    Node *res = this;
    while (res->prev && res == res->prev->left) {
      res = res->prev;
    }
    return (res->prev) ? res->prev : this->end();
  }
  return this->prev;
}

template <typename T, typename K>
constexpr Node<T, K> *Node<T, K>::find(const T &item) {
  Node *iter = getHead();
  while (iter != nullptr) {
    if (iter->item == item) break;
    if (iter->item > item)
      iter = iter->left;
    else
      iter = iter->right;
  }
  return iter == nullptr ? end() : iter;
}
template <typename T, typename K>
Node<T, K> *Node<T, K>::getHead() {
  Node *head = this;
  while (head && head->prev) {
    head = head->prev;
  }
  return head;
}

template <typename T, typename K>
void Node<T, K>::clear() {
  auto iter = this;
  if (iter->left) {
    delete iter->left;
    iter->left = nullptr;
  }
  if (iter->right) {
    delete iter->right;
    iter->right = nullptr;
  }
}

template <typename T, typename K>
constexpr std::pair<Node<T, K> *, bool> Node<T, K>::insert(const T &item) {
  Node *iter = this->find(item);

  std::pair<Node *, bool> res{iter, false};
  iter = this->getHead();
  Node *prev = nullptr;
  while (iter) {
    prev = iter;
    if (iter->item > item)
      iter = iter->left;
    else
      iter = iter->right;
  }
  iter = new Node(item, prev);
  if (prev) {
    if (item < prev->item)
      prev->left = iter;
    else
      prev->right = iter;
  }
  res.first = iter;
  res.second = true;
  if (prev) prev->fixHeight();
  return res;
}

template <typename T, typename K>
constexpr std::pair<Node<T, K> *, bool> Node<T, K>::insert(const T &item,
                                                           const K &value) {
  Node *iter = this->find(item);

  std::pair<Node *, bool> res{iter, false};
  iter = this->getHead();
  Node *prev = nullptr;
  while (iter) {
    prev = iter;
    if (iter->item > item)
      iter = iter->left;
    else
      iter = iter->right;
  }
  iter = new Node(item, value, prev);
  if (prev) {
    if (item < prev->item)
      prev->left = iter;
    else
      prev->right = iter;
  }
  res.first = iter;
  res.second = true;
  if (prev) prev->fixHeight();
  return res;
}
template <typename T, typename K>
constexpr Node<T, K> *Node<T, K>::erase(Node<T, K> *iter) {
  if (!iter || iter == this->end()) return iter;
  if (iter->left) {
    Node *temp = iter->left;
    if (temp->right) {
      while (temp->right) temp = temp->right;
    }
    iter->item = temp->item;
    iter->item_value = temp->item_value;
    temp->prev->fixHeight();  // need to be tested

    if (iter->left == temp) {
      iter->left = temp->left;
    }

    temp->right = nullptr;
    temp->left = nullptr;
    if (temp->prev->right == temp) {
      temp->prev->right = nullptr;
    }
    temp->prev = nullptr;
    delete temp;
    return iter->getHead()->begin();
  } else if (!iter->prev) {
    if (iter->right) {
      auto res = iter->right;
      iter->right->prev = nullptr;
      iter->right = nullptr;
      delete iter;
      return res->getHead()->begin();
    } else {
      item = T();
      item_value = K();
      height = 0;
    }
  } else {
    if (iter->item < iter->prev->item) {
      iter->prev->left = iter->left;
    } else {
      iter->prev->right = iter->right;
      if (iter->right != nullptr) {
        iter->right->prev = iter->prev;
      }
    }
    Node *to_return = iter->prev;
    to_return->fixHeight();  // need to be tested
    iter->right = nullptr;
    iter->left = nullptr;
    iter->prev = nullptr;
    delete iter;
    // return to_return;
    return to_return->getHead()->begin();
  }
  return getHead()->begin();
}

// balanceshit
// prev pls fix height

template <typename T, typename K>
void Node<T, K>::fixHeight() {
  size_t height_l = left ? left->height : 0,
         height_r = right ? right->height : 0;
  size_t pr_height = height;

  height = (height_l > height_r ? height_l : height_r) + 1;
  if (pr_height != height) {
    balanceShit();
  }
  if (prev) {
    prev->fixHeight();
  }
}

template <typename T, typename K>
void Node<T, K>::balanceShit() {
  const int diff = calcDiff();
  if (abs(diff) > 1) {
    if (diff < 0) {
      if (right->calcDiff() <= 0)
        leftSmallRotate();
      else
        leftBigRotate();
    } else {
      if (left->calcDiff() >= 0)
        rightSmallRotate();
      else
        rightBigRotate();
    }
  }
}

template <typename T, typename K>
int Node<T, K>::calcDiff() {
  int height_l = left ? left->height : 0, height_r = right ? right->height : 0;
  return height_l - height_r;
}

template <typename T, typename K>
void Node<T, K>::leftSmallRotate() {
  right->prev = prev;
  prev = right;
  right = right->left;
  prev->left = this;
  if (right) right->prev = this;
  if (prev->prev) {
    if (prev->item < prev->prev->item)
      prev->prev->left = prev;
    else
      prev->prev->right = prev;
  }
  fixHeight();
  // return prev; // to return new head
}

template <typename T, typename K>
void Node<T, K>::rightSmallRotate() {
  left->prev = prev;
  prev = left;
  left = left->right;
  prev->right = this;
  if (left) left->prev = this;
  if (prev->prev) {
    if (prev->item < prev->prev->item)
      prev->prev->left = prev;
    else
      prev->prev->right = prev;
  }
  fixHeight();
  // return prev; // to return new head
}

template <typename T, typename K>
void Node<T, K>::leftBigRotate() {
  right->left->prev = prev;
  prev = right->left;
  Node *const temp = right;
  right = right->left->left;
  if (right) right->prev = this;
  temp->left->left = this;
  temp->left = temp->left->right;
  prev->right = temp;
  temp->prev = prev;
  if (temp->left) temp->left->prev = temp;
  if (prev->prev) {
    if (prev->item < prev->prev->item)
      prev->prev->left = prev;
    else
      prev->prev->right = prev;
  }
  fixHeight();
  if (prev->right) {
    prev->right->fixHeight();
  }

  // return prev; // to return new head
}

template <typename T, typename K>
void Node<T, K>::rightBigRotate() {
  left->right->prev = prev;
  prev = left->right;
  Node *const temp = left;
  left = left->right->right;
  if (left) left->prev = this;
  temp->right->right = this;
  temp->right = temp->right->left;
  prev->left = temp;
  temp->prev = prev;
  if (temp->right) temp->right->prev = temp;
  if (prev->prev) {
    if (prev->item < prev->prev->item)
      prev->prev->left = prev;
    else
      prev->prev->right = prev;
  }
  fixHeight();
  if (prev->left) {
    prev->left->fixHeight();
  }
}
};  // namespace s21

#endif  // S21_CONTAINERS_SRC_S21_CONTAINERS_NODE_NODE_TPP
