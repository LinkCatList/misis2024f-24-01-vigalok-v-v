#pragma once

#include <iostream>
#include <memory>

template<typename T>
class Array {
public:
    Array(std::ptrdiff_t size = 0)
    : Data_(new T[2 * size])
    , Size_(size)
    , Capacity_(2 * size)
    {
        for (size_t i = 0; i < size; ++i) {
            Data_[i] = T();
        }
    }

    Array(const Array& otherArray) {
        Data_ = std::shared_ptr<T[]>(new T[otherArray.Capacity_()]);
        Size_ = otherArray.Size();
        Capacity_ = otherArray.Capacity_;
        for (size_t i = 0; i < otherArray.Size(); ++i) {
            Data_[i] = otherArray.Data_[i];
        }
    }

    Array& operator =(const Array& otherArray) {
        if (*this != otherArray) {
            Data_.reset();
            Data_ = std::shared_ptr<T[]>(new T[otherArray.Size()]);
            Size_ = otherArray.Size();
            Capacity_ = otherArray.Capacity;
            for (size_t i = 0; i < otherArray.Size(); ++i) {
                Data_[i] = otherArray.Data_[i];
            }
        }
        return *this;
    }

    void Resize(const std::ptrdiff_t size) {
        std::shared_ptr<T[]> currentData = Data_;
        Data_.reset();
        Data_ = std::shared_ptr<T[]>(new T[2 * size]);
        for (size_t i = 0; i < 2 * size; ++i) {
            Data_[i] = T();
        }
        for (size_t i = 0; i < std::min(Size_, size); ++i) {
            Data_[i] = currentData[i];
        }
        Size_ = size;
        Capacity_ = 2 * size;
    }

    void Insert(const std::ptrdiff_t index, const T& value) {
        CheckIndex(index);
        if (Size_ == Capacity_) {
            Resize(2 * Size_);
            Size_ /= 2;
        }
        
        for (size_t i = Size_; i > index; --i) {
            Data_[i] = Data_[i - 1];
        }
        Data_[index] = value;
        ++Size_;
    }

    void Remove(const std::ptrdiff_t index) {
        CheckIndex(index);
        for (size_t i = index; i < Size_ - 1; ++i) {
            Data_[i] = Data_[i + 1];
        }
        --Size_;
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
    void CheckIndex(const std::ptrdiff_t index) {
        if (index < 0 || index >= Size_) {
            throw std::runtime_error("invalid index");
        }
    }

    std::shared_ptr<T[]> Data_ = nullptr;
    std::ptrdiff_t Size_ = 0;
    std::ptrdiff_t Capacity_ = 0;
};
