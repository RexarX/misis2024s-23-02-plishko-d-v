#include <cstdint>

template <class T>
class DynArr {
public:
  DynArr();
  DynArr(const DynArr& rhs);
  ~DynArr();

  ptrdiff_t Size() const { return size_; }

  void Resize(const ptrdiff_t& newCapacity);

  DynArr<T>& operator=(const DynArr<T>& rhs);

  const T& operator[](const ptrdiff_t& index) const;
  T& operator[](const ptrdiff_t& index);

  bool operator==(const DynArr<T>& rhs) const;
  bool operator!=(const DynArr<T>& rhs) const { return !operator==(rhs); }

private:
  ptrdiff_t size_ = 0;
  ptrdiff_t capacity_ = 2;
  T* data_ = nullptr;
};