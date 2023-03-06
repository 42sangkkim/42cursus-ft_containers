#include <iostream>
#ifdef STD_TEST //CREATE A REAL STL EXAMPLE
	#include <stack>
	namespace ft = std;
#else
	#include <stack.hpp>
#endif

// My solution for BOJ 10828
// https://www.acmicpc.net/problem/10828

using namespace std;

int main() {
	ft::stack<int>	stack;
	int				N, val;
	std::string		command;

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> command;
		if (command == "push") {
			std::cin >> val;
			stack.push(val);
		} else if (command == "pop") {
			if (stack.empty())
				std::cout << "-1\n";
			else {
				std::cout << stack.top() << "\n";
				stack.pop();
			}
		} else if (command == "size") {
			std::cout << stack.size() << "\n";
		} else if (command == "empty") {
			if (stack.empty())
				std::cout << "1\n";
			else
				std::cout << "0\n";
		} else if (command == "top") {
			if (stack.empty())
				std::cout << "-1\n";
			else
				std::cout << stack.top() << "\n";
		} else {
			std::cout << "unknown command [" << command << "]\n";
		}
	}
	return 0;
}