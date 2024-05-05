#include <iostream>
#include "doubly_linked_list.hpp"
#include "doubly_linked_list.cpp"
#include "vector.hpp"
#include "vector.cpp"


int main(){
	IBusko::Vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.insert(2, 0);
	std::cout << vec.get_size() << std::endl;
	vec.print();
	std::cout << std::endl;

	vec.remove_first(0);	
	std::cout << vec.has_item(0) << ' ' << vec.has_item(1) << std::endl;
	vec.print();
	std::cout << std::endl;


	IBusko::Vector<int> vec_empty;
	std::cout << vec_empty.get_size() << ' ' << vec_empty.has_item(1) << ' ' << vec_empty.remove_first(1) << std::endl;
	vec_empty.print();
	std::cout << std::endl;

	std::cout << "--------------------------------" << std::endl;

	IBusko::DoublyLinkedList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	list.print();
	std::cout << std::endl;
	std::cout << list.has_item(2) << std::endl;

	list.remove_first(2);
	list.push_back(4);
	list.print();
	std::cout << std::endl;

	std::cout << list.size() << std::endl;

	IBusko::DoublyLinkedList<int> empty;
	std::cout << empty.size() << ' ' << empty.has_item(1) << ' ' << empty.remove_first(1) << std::endl;
	empty.print();
	std::cout << std::endl;
}
