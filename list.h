#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
    };

    Node* Start;
    Node* End;

public:
    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}

        T& operator*() {
            return current->data;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        Iterator& operator--() {
            current = current->prev;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    List();
    ~List();

    void push_front(const T& data);
    void push_back(const T& data);
    void pop_front();
    void pop_back();
    void remove(const T& data);
    bool is_empty() const;
    void print_list() const;
    T second_to_last() const;

    Iterator begin() const;
    Iterator end() const;
};

template <typename T>
List<T>::List() : Start(nullptr), End(nullptr) {}

template <typename T>
List<T>::~List() {
    while (!is_empty()) {
        pop_front();
    }
}

template <typename T>
void List<T>::push_front(const T& data) {
    Node* new_node = new Node(data);
    if (is_empty()) {
        Start = End = new_node;
    } else {
        new_node->next = Start;
        Start->prev = new_node;
        Start = new_node;
    }
}

template <typename T>
void List<T>::push_back(const T& data) {
    Node* new_node = new Node(data);
    if (is_empty()) {
        Start = End = new_node;
    } else {
        new_node->prev = End;
        End->next = new_node;
        End = new_node;
    }
}

template <typename T>
void List<T>::pop_front() {
    if (is_empty()) {
        std::cerr << "List is empty, cannot pop front" << std::endl;
        return;
    }

    Node* temp = Start;
    if (Start == End) {
        Start = End = nullptr;
    } else {
        Start = Start->next;
        Start->prev = nullptr;
    }
    delete temp;
}

template <typename T>
void List<T>::pop_back() {
    if (is_empty()) {
        std::cerr << "List is empty, cannot pop back" << std::endl;
        return;
    }

    Node* temp = End;
    if (Start == End) {
        Start = End = nullptr;
    } else {
        End = End->prev;
        End->next = nullptr;
    }
    delete temp;
}

template <typename T>
void List<T>::remove(const T& data) {
    Node* current = Start;
    while (current != nullptr) {
        if (current->data == data) {
            Node* temp = current;
            if (current == Start && current == End) {
                Start = End = nullptr;
            } else if (current == Start) {
                Start = current->next;
                Start->prev = nullptr;
            } else if (current == End) {
                End = current->prev;
                End->next = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            current = current->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}

template <typename T>
bool List<T>::is_empty() const {
    return Start == nullptr;
}

template <typename T>
void List<T>::print_list() const {
    Node* current = Start;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
typename List<T>::Iterator List<T>::begin() const {
    return Iterator(Start);
}

template <typename T>
typename List<T>::Iterator List<T>::end() const {
    return Iterator(nullptr);
}

template <typename T>
T List<T>::second_to_last() const {
    if (Start == nullptr || Start->next == nullptr) {
        return nullptr;
    }

    Node* current = End;
    return current->prev->data;
}

#endif // LIST_H
