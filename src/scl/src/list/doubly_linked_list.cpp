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
bool IBusko::DoublyLinkedList<T>::has_item(const T& value) const noexcept{
	Node* element = begin;
	while(element != end){
		if (element->value == value){
			return 1;
		}
		element = element->next;
	}

	if (end != nullptr) {
		if (end->value == value) {
			return 1;
		}
	}

	return 0;
}


template<typename T>
void IBusko::DoublyLinkedList<T>::print() const noexcept{
	Node* element = begin;
	while(element != end){
		std::cout << element->value << " ";
		element = element->next;
	}
	if (end != nullptr)
		std::cout << end->value << std::endl;
}



template<typename T>
bool IBusko::DoublyLinkedList<T>::remove_first(const T& value) noexcept{
	Node* element = begin;
	while(element != end){
		if (element->value == value){
			element->prev->next = element->next;
			element->next->prev = element->prev;
			delete element;
			return 1;
		}
		element = element->next;
	}

	if (end != nullptr){
		if (end->value == value){
			end = end->prev;
			delete end->next;
			end->next = nullptr;
			return 1;
		}
	}

	return 0;
}


template<typename T>
std::size_t IBusko::DoublyLinkedList<T>::size() const noexcept{
	std::size_t counter = 0;
	Node* element = begin;
	while(element != end){
		counter++;
		element = element->next;
	}

	if (end != nullptr)
		counter++;

	return counter;
}
