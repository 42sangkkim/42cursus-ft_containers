#include <iostream>
#include <map>

int main ( void )
{
	// std::map<int, char, std::greater<char> > m1;
	// std::map<int, char, std::greater<char> > m2;
	std::map<int, char, std::less<char> > m1;
	std::map<int, char, std::less<char> > m2;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';

	m2[1] = 'A';
	m2[2] = 'B';
	m2[3] = 'C';

    std::cout << std::boolalpha;
    std::cout << "m1 == m2 returns " << (m1 == m2) << '\n';
    std::cout << "m1 != m2 returns " << (m1 != m2) << '\n';
    std::cout << "m1 <  m2 returns " << (m1 < m2) << '\n';
    std::cout << "m1 <= m2 returns " << (m1 <= m2) << '\n';
    std::cout << "m1 >  m2 returns " << (m1 > m2) << '\n';
    std::cout << "m1 >= m2 returns " << (m1 >= m2) << '\n';
}