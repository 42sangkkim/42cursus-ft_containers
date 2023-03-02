#ifndef FT_CONTAINER_PAIR_TPP
# define FT_CONTAINER_PAIR_TPP

# include "./pair.hpp"

template < class T1, class T2 >
ft::pair<T1, T2>::pair ( void )
	: first(), second()
{}

template < class T1, class T2 >
ft::pair<T1, T2>::pair ( const T1 & x, const T2 & y )
	: first(x), second(y)
{}

template < class T1, class T2 >
template < class U1, class U2 >
ft::pair<T1, T2>::pair ( const pair<U1, U2> & p )
	: first(p.first), second(p.second)
{}

template < class T1, class T2 >
typename ft::pair<T1, T2> & ft::pair<T1, T2>::operator = ( const pair & other )
{
	this->first = other.first;
	this->second = other.second;
	return *this;
}

// Non-member functions

template < class T1, class T2 >
typename ft::pair<T1, T2> ft::make_pair( T1 t, T2 u )
{
	return ft::pair<T1, T2>(t, u);
}

template < class T1, class T2 >
bool ft::operator == ( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs )
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template < class T1, class T2 >
bool ft::operator != ( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs )
{
	return !(lhs == rhs);
}

template < class T1, class T2 >
bool ft::operator < ( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs )
{
	return (lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second));
}

template < class T1, class T2 >
bool ft::operator > ( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs )
{
	return (lhs.first > rhs.first || (lhs.first == rhs.first && lhs.second > rhs.second));
}

template < class T1, class T2 >
bool ft::operator <= ( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs )
{
	return !(lhs > rhs);
}

template < class T1, class T2 >
bool ft::operator >= ( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs )
{
	return !(lhs < rhs);
}

#endif // FT_CONTAINER_PAIR_TPP
