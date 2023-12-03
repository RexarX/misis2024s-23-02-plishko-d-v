#include <cstddef>

template <class T>
class DynArr {
public:
  DynArr();
  DynArr(const std::ptrdiff_t& rhs);
  DynArr(const DynArr<T>& rhs);
  ~DynArr();

  std::ptrdiff_t Size() const { return size_; }
  std::ptrdiff_t Capacity() const { return capacity_; }

  void Resize(const std::ptrdiff_t& newCapacity);
  void Push_back(const T& object);
  void Pop_back();
  void Erase(const std::ptrdiff_t& index);
  void Clear();
  void Print();

  DynArr<T>& operator=(const DynArr<T>& rhs);

  const T& operator[](const std::ptrdiff_t& index) const;
  T& operator[](const std::ptrdiff_t& index);

  bool operator==(const DynArr<T>& rhs) const;
  bool operator!=(const DynArr<T>& rhs) const { return !operator==(rhs); }

private:
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t capacity_ = 1;
  T* data_ = nullptr;
};