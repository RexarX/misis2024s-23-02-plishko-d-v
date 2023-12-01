#include <dynarr/dynarr.hpp>
#include <iostream>
#include <sstream>

template<class T>
DynArr<T>::DynArr() 
  : data_(new T[capacity_]) 
{
}

template<class T>
DynArr<T>::DynArr(const DynArr<T>& rhs)
  : size_(rhs.size_), capacity_(rhs.capacity_), data_(rhs.data_)
{
  if (size_ < rhs.size_) { Resize(rhs.capacity_); }

  for (ptrdiff_t i = 0; i < size_; i++) {
    data_[i] = rhs.data_[i];
  }
}

template<class T>
DynArr<T>::~DynArr() {
  delete[] data_;
}

template<class T>
void DynArr<T>::Resize(const ptrdiff_t& newCapacity) {
  T* newArray = new T[newCapacity];
 
  if (newCapacity < size_) {
    size_ = newCapacity;
  }

  for (ptrdiff_t i = 0; i < size_; i++) {
    newArray[i] = data_[i];
  }

  delete[] data_;
  data_ = newArray;
  capacity_ = newCapacity;
}

template<class T>
DynArr<T>& DynArr<T>::operator=(const DynArr<T>& rhs) {
  if (size_ < rhs.size_) { Resize(rhs.capacity_); }

  for (ptrdiff_t i = 0; i < size_; i++) {
    data_[i] = rhs.data_[i];
  }

  return *this;
}

template<class T>
const T& DynArr<T>::operator[](const ptrdiff_t& index) const {
  if (index > size_ || index < 0) { throw std::out_of_range("Index out of range"); }
  //std::cout << '|' << '1' << '|';

  return data_[index];
}

template<class T>
T& DynArr<T>::operator[](const ptrdiff_t& index) {
  if (index < 0) { throw std::out_of_range("Array index out of range"); }
  if (index >= capacity_) { Resize(capacity_ * (static_cast<int>(index / capacity_) + 1)); }
  ++size_;

  return data_[index];
}

template<class T>
bool DynArr<T>::operator==(const DynArr<T>& rhs) const {
  if (size_ != rhs.size_) { return false; }

  for (ptrdiff_t i = 0; i < size_; i++) {
    if (data_[i] != rhs.data_[i]) { return false; }
  }

  return true;
}
