#include <cstdint>

template <class T>
class DynArr {
public:
  DynArr();
  DynArr(const ptrdiff_t& rhs);
  DynArr(const DynArr<T>& rhs);
  ~DynArr();

  ptrdiff_t Size() const { return size_; }
  ptrdiff_t Capacity() const { return capacity_; }

  void Resize(const ptrdiff_t& newCapacity);
  void Push_back(const T& object);
  void Pop_back();
  void Erase(const ptrdiff_t& index);
  void Clear();
  void Print();

  DynArr<T>& operator=(const DynArr<T>& rhs);

  const T& operator[](const ptrdiff_t& index) const;
  T& operator[](const ptrdiff_t& index);

  bool operator==(const DynArr<T>& rhs) const;
  bool operator!=(const DynArr<T>& rhs) const { return !operator==(rhs); }

private:
  ptrdiff_t size_ = 0;
  ptrdiff_t capacity_ = 1;
  T* data_ = nullptr;
};