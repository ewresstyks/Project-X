#include "List.h"
#include <iostream>
using namespace std;

List::List() : head(nullptr), tail(nullptr), size(0) {}

List::~List() {
    clear();
}

List::List(const List& other) : head(nullptr), tail(nullptr), size(0) {
    Node* current = other.head;
    while (current) {
        push_back(current->value);
        current = current->next;
    }
}

List& List::operator=(const List& other) {
    if (this == &other) {
        return *this;
    }

    clear();

    Node* current = other.head;
    while (current) {
        push_back(current->value);
        current = current->next;
    }

    return *this;
}

void List::push_back(int value) {
    Node* new_node = new Node(value);
    if (tail) {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    else {
        head = tail = new_node;
    }
    size++;
}

void List::push_front(int value) {
    Node* new_node = new Node(value);
    if (head) {
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }
    else {
        head = tail = new_node;
    }
    size++;
}

void List::pop_back() {
    if (!tail) return;

    Node* delete1 = tail;
    if (tail->prev) {
        tail = tail->prev;
        tail->next = nullptr;
    }
    else {
        head = tail = nullptr;
    }
    delete delete1;
    size--;
}

void List::pop_front() {
    if (!head) return;

    Node* delete2 = head;
    if (head->next) {
        head = head->next;
        head->prev = nullptr;
    }
    else {
        head = tail = nullptr;
    }
    delete delete2;
    size--;
}

void List::reverse() {
    if (!head) return;

    Node* current = head;
    Node* temp = nullptr;
    tail = head;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp) {
        head = temp->prev;
    }
}

void List::clear() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;
}

void List::show() const {
    Node* current = head;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}