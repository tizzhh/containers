#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_NODE_TPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_NODE_TPP

namespace s21 {
template <typename T>
struct node {
  T data = T();
  struct node *prev = nullptr;
  struct node *next = nullptr;

  bool operator<(const node &other) const { return (data < other.data); }
};
}  // namespace s21

#endif