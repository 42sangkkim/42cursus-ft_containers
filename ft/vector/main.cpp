#include <iostream>
using std::cout;
using std::endl;


#include "./vector.hpp"

void leaks(void)
{
	system("leaks a.out | grep total");
}

void print_vector(ft::vector<int> & vec)
{
	cout << "size : " << vec.size() << " cap : " << vec.capacity() << endl << "[";
	for (size_t i = 0; i + 1 < vec.size(); i++)
		cout << vec[i] << ", ";
	if (!vec.empty())
		cout << vec[vec.size() - 1];
	cout << "]" << endl;
}

int main(void)
{
	atexit(leaks);
	ft::vector<int> vec;

	print_vector(vec);

	vec.reserve(2);

	print_vector(vec);

	for (int i = 0; i < 10; i++)
		vec.push_back(i + 1);

	print_vector(vec);

}
