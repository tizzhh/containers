#ifndef S21_CONTAINERS_SRC_S21_CONTAINERS_VECTOR_VECTOR_HPP
#define S21_CONTAINERS_SRC_S21_CONTAINERS_VECTOR_VECTOR_HPP

#include <stdexcept>

namespace s21 {
  template<typename T>
  class vector {
    public:
      using value_type = T;
      using reference = value_type &;
      using const_reference = const value_type &;
      using iterator = value_type *;
      using const_iterator = const value_type *;
      using size_type = size_t;
      constexpr vector();
      constexpr vector(size_type n);
      constexpr vector(std::initializer_list<value_type> const &items);
      constexpr vector(const vector &v);
      constexpr vector(vector &&v);
      ~vector();
 
      constexpr vector& operator=(vector&& a);
      constexpr vector& operator=(const std::initializer_list<value_type>& values);
      constexpr reference operator[](const size_type& pos);
      constexpr const_reference operator[](const size_type& pos)	const;
 
      constexpr reference at(const size_type& pos);
      constexpr const_reference at(const size_type& pos) const;
      constexpr reference front() noexcept;
      constexpr const_reference front() const noexcept;
      constexpr reference back() noexcept;
      constexpr const_reference back() const noexcept;
      constexpr iterator data() noexcept;
      constexpr const_iterator data() const noexcept;
 
      constexpr iterator begin() noexcept;
      constexpr const_iterator cbegin() const noexcept;
      constexpr iterator end() noexcept;
      constexpr const_iterator cend() const noexcept;
 
      constexpr bool empty() const noexcept;
      constexpr size_type size() const noexcept {return size_;}
      constexpr size_type max_size() const noexcept {return capacity_;}
      constexpr void reserve(size_type size) noexcept {capacity_ = size;}
      constexpr size_type capacity() const noexcept{return capacity_;}
      constexpr void shrink_to_fit();
 
      constexpr void clear() noexcept;
      constexpr iterator insert(iterator pos, const_reference value); // ?
      constexpr void erase(iterator pos);
      constexpr void push_back(const_reference value);
      constexpr void pop_back() noexcept;
      constexpr void swap(vector& other) noexcept;
    protected:
    //    size_type CapacityCalc(size_type amount_of_elements) const noexcept;
      constexpr void SetStorage(iterator value) noexcept;
      constexpr void SetSize(size_t num) noexcept;
      constexpr void SetCapacity(size_t num) noexcept;
      constexpr iterator GetStorage() const noexcept;
      constexpr size_type GetSize() const noexcept;
      constexpr size_type GetCapacity() const noexcept;
    private:
      iterator storage_ = nullptr;
      size_type capacity_ = 0;
      size_type size_ = 0;
      iterator iter = nullptr;
  };
}; //namespace s21

#include "vector.tpp"

#endif // S21_CONTAINERS_SRC_S21_CONTAINERS_VECTOR_VECTOR_HPP