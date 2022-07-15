#include "lib.hpp"
#include <iostream>
using namespace std;

void LinkedList::push_back(int value) {
    if(head == nullptr){
        head = new Node(value);
        return;
    }
    auto node = head;
    while(node->next != nullptr){
        node = node->next;
    }
    node->next = new Node(value);
}
void LinkedList::push_front(int value) {
    auto node = new Node(value);
    node->next = head;
    head = node;
}
void LinkedList::pop_back() {
    if(head == nullptr){
        return;
    }
    if(head->next == nullptr){
        pop_front();
        return;
    }
    auto node = head;
    while(node->next->next != nullptr){
        node = node->next;
    }
    delete node->next;
    node->next = nullptr;
}
void LinkedList::pop_front() {
    if(head == nullptr){
        return;
    }
    auto save = head;
    head = head->next;
    delete save;
}
int  LinkedList::size() {

    int counter{0};
    Node* current = head;

    while(current != NULL){
        counter++;
        current = current ->next;
    }

    return counter;
}