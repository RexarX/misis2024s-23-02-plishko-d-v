#include <iostream>
#include <cstring>
#include <dynarr/dynarr.hpp>

DynArr::DynArr()
  : data_(new float[capacity_]())
{
}

DynArr::DynArr(const std::ptrdiff_t& rhs)
  : capacity_(rhs), data_(new float[rhs]())
{
}

DynArr::DynArr(const DynArr& rhs)
  : size_(rhs.size_), capacity_(rhs.capacity_), data_(new float[rhs.capacity_])
{
  /*for (std::ptrdiff_t i = 0; i < size_; ++i) {
    data_[i] = rhs.data_[i];
  }*/
  std::memcpy(data_, rhs.data_, size_ * sizeof(float));
}

DynArr::~DynArr() {
  delete[] data_;
}

void DynArr::ChangeCapacity(const std::ptrdiff_t& newCapacity) {
  float* newArray = new float[newCapacity]();
  if (newCapacity < size_) { size_ = newCapacity; }
  /*for (std::ptrdiff_t i = 0; i < size_; ++i) {
    newArray[i] = std::move(data_[i]);
  }*/
  std::memmove(newArray, data_, size_ * sizeof(float));
  delete[] data_;
  data_ = newArray;
  capacity_ = newCapacity;
}

void DynArr::Resize(const std::ptrdiff_t& newSize) {
  if (newSize > 0) {
    if (newSize > capacity_) { ChangeCapacity(newSize); }
    else {
      /*for (std::ptrdiff_t i = newSize; i < capacity_; ++i) {
        data_[i] = 0;
      }*/
      std::memset(data_ + newSize, static_cast<float>(0), capacity_);
    }
    size_ = newSize;
  }
  else { throw ("Invalid size value"); }
}

void DynArr::Push_back(const float& object) {
  if (size_ >= capacity_) { ChangeCapacity(2 * capacity_); }
  data_[size_] = object;
  ++size_;
}

void DynArr::Pop_back() {
  if (size_ > 0) {
    /*float* newArray = new float[capacity_]();
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
      newArray[i] = std::move(data_[i]);
    }
    delete[] data_;
    data_ = newArray;*/
    --size_;
  }
  else { throw ("Empty array pop"); }
}

void DynArr::Erase(const std::ptrdiff_t& index) {
  if (index >= 0 && index < size_) {
    /*float* newArray = new float[capacity_]();
    for (std::ptrdiff_t i = 0; i < index; ++i) {
      newArray[i] = std::move(data_[i]);
    }
    for (std::ptrdiff_t i = index; i < size_; ++i) {
      newArray[i] = std::move(data_[i + 1]);
    }
    delete[] data_;
    data_ = newArray;*/
    /*for (std::ptrdiff_t i = index; i < size_; ++i) {
      data_[i] = data_[i + 1];
    }*/
    --size_;
  }
  else { throw std::out_of_range("Index out of range"); }
}

void DynArr::Clear() {
  float* newArray = new float[capacity_]();
  delete[] data_;
  data_ = newArray;
  size_ = 0;
}

void DynArr::Print() {
  for (std::ptrdiff_t i = 0; i < size_; ++i) {
    std::cout << data_[i] << ' ';
  }
  std::cout << '\n';
}

DynArr& DynArr::operator=(const DynArr& rhs) {
  if (capacity_ < rhs.size_) { ChangeCapacity(rhs.capacity_); }
  /*for (std::ptrdiff_t i = 0; i < rhs.size_; ++i) {
    data_[i] = rhs.data_[i];
  }*/
  std::memcpy(data_, rhs.data_, rhs.size_ * sizeof(float));
  size_ = rhs.size_;
  return *this;
}

const float& DynArr::operator[](const std::ptrdiff_t& index) const {
  if (index > size_ || index < 0) { throw std::out_of_range("Index out of range"); }
  return data_[index];
}

float& DynArr::operator[](const std::ptrdiff_t& index) {
  if (index > size_ || index < 0) { throw std::out_of_range("Index out of range"); }
  return data_[index];
}

bool DynArr::operator==(const DynArr& rhs) const {
  if (size_ != rhs.size_) { return false; }
  for (std::ptrdiff_t i = 0; i < size_; ++i) {
    if (data_[i] != rhs.data_[i]) { return false; }
  }
  return true;
}
