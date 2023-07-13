#include <iostream>
#include <stdexcept>
#include <cassert>

template <typename T>
class SequentialContainer {
public:
    SequentialContainer() : size_(0), capacity_(DEFAULT_CAPACITY) {
        data_ = new T[DEFAULT_CAPACITY];
    }

    ~SequentialContainer() {
        delete[] data_;
    }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            reserve(capacity_ * 2);
        }

        data_[size_] = value;
        size_++;
    }

    void insert(size_t position, const T& value) {
        if (position > size_) {
            throw std::out_of_range("Invalid position");
        }

        if (size_ == capacity_) {
            reserve(capacity_ * 2);
        }

        for (size_t i = size_; i > position; i--) {
            data_[i] = data_[i - 1];
        }

        data_[position] = value;
        size_++;
    }

    void erase(size_t position) {
        if (position >= size_) {
            throw std::out_of_range("Invalid position");
        }

        for (size_t i = position; i < size_ - 1; i++) {
            data_[i] = data_[i + 1];
        }

        size_--;
    }

    size_t size() const {
        return size_;
    }

    const T& operator[](size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Invalid index");
        }

        return data_[index];
    }

    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Invalid index");
        }

        return data_[index];
    }

    void printContainer() const {
        for (size_t i = 0; i < size_; i++) {
            std::cout << data_[i];
            if (i != size_ - 1) {
                std::cout << ", ";
            }
        }

        std::cout << std::endl;
    }

private:
    static const size_t DEFAULT_CAPACITY = 10;

    T* data_;
    size_t size_;
    size_t capacity_;

    void reserve(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size_; i++) {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }
};
