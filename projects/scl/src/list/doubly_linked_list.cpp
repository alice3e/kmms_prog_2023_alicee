#include "doubly_linked_list.hpp"
#include <iostream>


template<typename T>
IBusko::DoublyLinkedList<T>::~DoublyLinkedList() noexcept{
	Node* element = begin;
	while(element != end){
		Node* next = element->next;
		delete element;
		element = next;
	}
	delete end;
}


template<typename T>
void IBusko::DoublyLinkedList<T>::push_back(const T& value) noexcept{
	Node* element = new Node(value);
	if (begin == nullptr){
		begin = element;
		end = element;
	} else {
		end->next = element;
		element->prev = end;
		end = element;
	}
}


template<typename T>
bool IBusko::DoublyLinkedList<T>::has_item(const T& value) const noexcept {
    for (Node* element = begin; element != nullptr; element = element->next) {
        if (element->value == value) {
            return true;
        }
    }
    return false;
}


template<typename T>
void IBusko::DoublyLinkedList<T>::print() const noexcept{
	if (end == nullptr){
		return;
	}
	Node* element = begin;
	while(element != end){
		std::cout << element->value << " ";
		element = element->next;
	}
	std::cout << end->value;
}




template<typename T>
bool IBusko::DoublyLinkedList<T>::remove_first(const T& value) noexcept {

    if (begin == nullptr) {
        return false;
    }

    Node* current = begin;
    while (current != nullptr) {
        if (current->value == value) {



            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {

                begin = current->next;
            }


            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {

                end = current->prev;
            }

            delete current;
            return true; // Value found and removed
        }

        current = current->next; // Move to the next node
    }

    return false; // Value not found
}


template<typename T>
std::size_t IBusko::DoublyLinkedList<T>::size() const noexcept {

    std::function<std::size_t(Node*)> count_nodes = [&](Node* node) -> std::size_t {
        if (node == nullptr) {
            return 0;
        }
        return 1 + count_nodes(node->next);
    };

    return count_nodes(begin);
}