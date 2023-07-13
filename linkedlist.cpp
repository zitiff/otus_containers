#include <iostream>
#include <stdexcept>
#include <cassert>

template <typename T>
class LinkedListContainer {
public:
    LinkedListContainer() : head_(nullptr), tail_(nullptr), size_(0) {}

    ~LinkedListContainer() {
        clear();
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        newNode->prev = tail_;
        if (tail_) {
            tail_->next = newNode;
        }
        else {
            head_ = newNode;
        }
        tail_ = newNode;
        size_++;
    }

    void insert(size_t position, const T& value) {
        if (position > size_) {
            throw std::out_of_range("Invalid position");
        }

        if (position == size_) {
            push_back(value);
            return;
        }

        Node* newNode = new Node(value);

        if (position == 0) {
            newNode->next = head_;
            head_->prev = newNode;
            head_ = newNode;
        }
        else {
            Node* current = getNode(position);
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }

        size_++;
    }

    void erase(size_t position) {
        if (position >= size_) {
            throw std::out_of_range("Invalid position");
        }

        Node* nodeToRemove = getNode(position);

        if (nodeToRemove == head_) {
            head_ = nodeToRemove->next;
        }
        else {
            nodeToRemove->prev->next = nodeToRemove->next;
        }

        if (nodeToRemove == tail_) {
            tail_ = nodeToRemove->prev;
        }
        else {
            nodeToRemove->next->prev = nodeToRemove->prev;
        }

        delete nodeToRemove;
        size_--;
    }

    size_t size() const {
        return size_;
    }

    const T& operator[](size_t index) const {
        return getNode(index)->data;
    }

    T& operator[](size_t index) {
        return getNode(index)->data;
    }

    void clear() {
        while (head_) {
            Node* next = head_->next;
            delete head_;
            head_ = next;
        }
        tail_ = nullptr;
        size_ = 0;
    }

    void printContainer() const {
        Node* current = head_;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << ", ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head_;
    Node* tail_;
    size_t size_;

    Node* getNode(size_t index) const {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Invalid index");
        }

        Node* current = head_;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }

        return current;
    }
};