#include <iostream>
#include <dynarr/dynarr.hpp>

template<class T>
DynArr<T>::DynArr()
  : data_(new T[capacity_])
{
}

template<class T>
DynArr<T>::DynArr(const ptrdiff_t& rhs)
  : capacity_(rhs)
{
  data_ = new T[capacity_];
}

template<class T>
DynArr<T>::DynArr(const DynArr<T>& rhs)
{
  if (capacity_ < rhs.size_) { Resize(rhs.size_); }
  for (ptrdiff_t i = 0; i < rhs.size_; i++) {
    data_[i] = rhs.data_[i];
  }
}

template<class T>
DynArr<T>::~DynArr() {
  delete[] data_;
}

template<class T>
void DynArr<T>::Resize(const ptrdiff_t& newCapacity) {
  if (newCapacity > 0) {
    T* newArray = new T[newCapacity];
    if (newCapacity < size_) { size_ = newCapacity; }
    for (ptrdiff_t i = 0; i < size_; i++) {
      newArray[i] = std::move(data_[i]);
    }
    delete[] data_;
    data_ = newArray;
    capacity_ = newCapacity;
  }
  else { throw ("Invalid capacity value"); }
}

template<class T>
void DynArr<T>::Push_back(const T& object) {
  if (size_ >= capacity_) { Resize(2 * capacity_); }
  data_[size_] = object;
  ++size_;
}

template<class T>
void DynArr<T>::Pop_back() {
  if (size_ > 0) {
    T* newArray = new T[capacity_];
    for (ptrdiff_t i = 0; i < size_; i++) {
      newArray[i] = std::move(data_[i]);
    }
    delete[] data_;
    data_ = newArray;
    --size_;
  }
  else { throw ("Empty array pop"); }
}

template<class T>
void DynArr<T>::Erase(const ptrdiff_t& index) {
  if (index >= 0 && index < size_) {
    T* newArray = new T[capacity_];
    for (ptrdiff_t i = 0; i < index; i++) {
      newArray[i] = std::move(data_[i]);
    }
    for (ptrdiff_t i = index; i < size_; i++) {
      newArray[i] = std::move(data_[i + 1]);
    }
    delete[] data_;
    data_ = newArray;
    --size_;
  }
  else { throw std::out_of_range("Index out of range"); }
}

template<class T>
void DynArr<T>::Clear() {
  T* newArray = new T[capacity_];
  delete[] data_;
  data_ = newArray;
  size_ = 0;
}

template<class T>
void DynArr<T>::Print() {
  for (ptrdiff_t i = 0; i < size_; i++) {
    std::cout << data_[i] << ' ';
  }
  std::cout << '\n';
}

template<class T>
DynArr<T>& DynArr<T>::operator=(const DynArr<T>& rhs) {
  if (capacity_ < rhs.size_) { Resize(rhs.capacity_); }
  for (ptrdiff_t i = 0; i < rhs.size_; i++) {
    data_[i] = rhs.data_[i];
  }
  size_ = rhs.size_;
  return *this;
}

template<class T>
const T& DynArr<T>::operator[](const ptrdiff_t& index) const {
  if (index > size_ || index < 0) { throw std::out_of_range("Index out of range"); }
  return data_[index];
}

template<class T>
T& DynArr<T>::operator[](const ptrdiff_t& index) {
  if (index > size_ || index < 0) { throw std::out_of_range("Index out of range"); }
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