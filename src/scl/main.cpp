#include <iostream>
#include "vector.hpp"
#include "vector.cpp"

int main(){
	IBusko::Vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.insert(0, 0);
	std::cout << vec.get_size() << std::endl;
	vec.print();

	vec.remove_first(1);	
	std::cout << vec.has_item(1) << std::endl;
	vec.print();
}
