#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_NODE_NODE_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_NODE_NODE_HPP

#include <iostream>

namespace s21 {
template <typename T, typename K = T>
class Node {
 public:
  constexpr Node();
  constexpr Node(T item);
  constexpr Node(T item, K item_value);
  constexpr Node(T item, Node *prev);
  constexpr Node(T item, K item_value, Node *prev);
  ~Node();
  constexpr Node *begin();
  constexpr Node *end();
  constexpr Node *next();
  constexpr Node *prevElement();
  constexpr std::pair<Node<T, K> *, bool> insert(const T &item);
  constexpr std::pair<Node<T, K> *, bool> insert(const T &item, const K &value);
  constexpr Node *find(const T &item);
  constexpr Node *erase(Node *iter);
  constexpr Node *lastElement();
  void setRoot();
  Node *getHead();
  void clear();
  void fixHeight();
  void balanceShit();
  int calcDiff();
  void leftSmallRotate();
  void rightSmallRotate();
  void leftBigRotate();
  void rightBigRotate();
  T item;
  K item_value;  // key
  Node *left = nullptr, *right = nullptr, *prev = nullptr;
  size_t height = 1;
  static Node end_;
  Node *root_;
};
template <typename T, typename K>
Node<T, K> Node<T, K>::end_;
};  // namespace s21
#include "node.tpp"

#endif  // S21_CONTAINERS_SRC_S21_CONTAINERS_NODE_NODE_HPP
