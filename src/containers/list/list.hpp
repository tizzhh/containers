#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_LIST_LIST_HPP

#include <initializer_list>

#include "list_iterator.hpp"

namespace s21 {
template <typename T>
class list {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
  using size_type = size_t;

  // List Functions
  // в пустом листе тоже есть значения в фронт и бэк
  // в случае инта и чара - это 0. В случае со
  // стрингом у меня вообще бесконечный цикл лол.
  // так что пусть будет NULL пока.
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();
  list &operator=(list &&l);

  // List Element access
  const_reference front();
  const_reference back();

  // List Iterators
  iterator begin();
  iterator end();

  // List Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // List Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

 private:
  struct node {
    value_type data = T();
    struct node *prev = nullptr;
    struct node *next = nullptr;
  };
  node *front_ = nullptr;
  node *back_ = nullptr;
  size_type size_ = 0;
};
};  // namespace s21
#include "list.tpp"
#endif