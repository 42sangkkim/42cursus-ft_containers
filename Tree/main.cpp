#include <iostream>
#include "./Tree.hpp"
#include "../pair.hpp"

int main ( void )
{
	ft::Tree<int, int> t;

	for (int i = 10; i > 0; i--)
		t.insert(ft::pair<int, int>(i, 0));
	std::cout << "Insertion complete" << std::endl;

	ft::Tree<int, int>::Node * node = t.insert(ft::pair<int, int>(42, 0));
	for (int i = 0; i < 11; i++)
	{
		std::cout << "Index(" << i << ") : " << node->_value.first << " [" << node << "]" << std::endl;
		node = node->prev();
	}
	std::cout << "Iterator complete" << std::endl;

}
