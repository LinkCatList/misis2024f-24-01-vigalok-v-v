#include <iostream>
#include <memory>

template<typename T>
class Array {
public:
    Array(std::ptrdiff_t size = 0)
    : Data_(new T[size])
    , Size_(size)
    , Capacity_(2 * size)
    {
        for (size_t i = 0; i < size; ++i) {
            Data_[i] = T();
        }
    }

    Array(const Array& otherArray) {
        Data_ = std::shared_ptr<T[]>(new T[otherArray.Size()]);
        Size_ = otherArray.Size();
        Capacity_ = otherArray.Capacity_;
        for (size_t i = 0; i < otherArray.Size(); ++i) {
            Data_[i] = otherArray.Data_[i];
        }
    }

    Array& operator =(const Array& otherArray) {
        Data_.reset();
        Data_ = std::shared_ptr<T[]>(new T[otherArray.Size()]);
        Size_ = otherArray.Size();
        Capacity_ = otherArray.Capacity;
        for (size_t i = 0; i < otherArray.Size(); ++i) {
            Data_[i] = otherArray.Data_[i];
        }
    }

    void Resize(const std::ptrdiff_t size) {
        std::shared_ptr<T[]> currentData = Data_;
        Data_.reset();
        Data_ = std::shared_ptr<T[]>(new T[size]);
        for (size_t i = 0; i < size; ++i) {
            Data_[i] = T();
        }
        for (size_t i = 0; i < std::min(Size_, size); ++i) {
            Data_[i] = currentData[i];
        }
        Size_ = size;
        Capacity_ = size * 2;
    }

    void Insert(const std::ptrdiff_t index) {
        
    }

    void Remove(const std::ptrdiff_t index) {

    }

    ~Array() {
        Data_.reset();
        Size_ = 0;
        Capacity_ = 0;
    }

public:
    T& operator [](const std::ptrdiff_t index) {
        return Data_[index];
    }
    const T& operator [](const std::ptrdiff_t index) const {
        return Data_[index];
    }

    [[nodiscard]] std::ptrdiff_t Size() const {
        return Size_;
    }

private:
    std::shared_ptr<T[]> Data_ = nullptr;
    std::ptrdiff_t Size_ = 0;
    std::ptrdiff_t Capacity_ = 0;
};
