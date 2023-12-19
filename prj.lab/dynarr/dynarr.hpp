#include <cstddef>

class DynArr {
public:
  DynArr();
  DynArr(const std::ptrdiff_t& rhs);
  DynArr(const DynArr& rhs);
  DynArr(const DynArr&) = default;
  ~DynArr();

  std::ptrdiff_t Size() const { return size_; }

  void Resize(const std::ptrdiff_t& newSize);
  void Push_back(const float& object);
  void Pop_back();
  void Erase(const std::ptrdiff_t& index);
  void Clear();
  void Print();

  DynArr& operator=(const DynArr& rhs);

  const float& operator[](const std::ptrdiff_t& index) const;
  float& operator[](const std::ptrdiff_t& index);

  bool operator==(const DynArr& rhs) const;
  bool operator!=(const DynArr& rhs) const { return !operator==(rhs); }

private:
  void ChangeCapacity(const std::ptrdiff_t& newCapacity);

  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t capacity_ = 1;
  float* data_ = nullptr;
};
