#include <iostream>
#include "./Tree.hpp"

int main ( void )
{
	ft::Tree t;

	for (int i = 10; i > 0; i--)
		t.insert(i);
	std::cout << "Insertion complete" << std::endl;

	t.print_all();

	ft::Tree::Node * node = t.insert(42);
	for (int i = 0; i < 11; i++)
	{
		std::cout << "Index(" << i << ") : " << node->_value << " [" << node << "]" << std::endl;
		node = node->prev();
	}
	std::cout << "Iterator complete" << std::endl;

}
