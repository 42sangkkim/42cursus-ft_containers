#ifndef FT_PAIR_TPP
# define FT_PAIR_TPP

# include "./pair.hpp"

namespace ft
{
	template < class T1, class T2 >
	pair<T1, T2>::pair ( void )
	 : first(), second()
	{

	}

	template < class T1, class T2 >
	pair<T1, T2>::pair ( const T1 & first, const T2 & second )
	 : first(first), second(second)
	{

	}

	template < class T1, class T2 >
	pair<T1, T2>::pair ( const pair<T1, T2> & rhs )
	 : first(rhs.first), second(rhs.second)
	{

	}

	//template < class T1, class T2 >
	//pair<T1, T2>::pair ( const pair & rhs ) = default
	// : first(rhs.first), second(rhs.second)
	//{

	//}

	template < class T1, class T2 >
	ft::pair<T1, T2> & pair<T1, T2>::operator= ( const pair<T1, T2> & rhs )
	{
		this->first = rhs.first;
		this->second = rhs.second;
		return *this;
	}

	template < class T1, class T2 >
	ft::pair<T1, T2> make_pair ( T1 first, T2 second )
	{
		return pair<T1, T2>(first, second);
	}

	template < class T1, class T2 >
	bool operator== ( const ft::pair<T1, T2> & lhs,  const ft::pair<T1, T2> & rhs )
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template < class T1, class T2 >
	bool operator!= ( const ft::pair<T1, T2> & lhs,  const ft::pair<T1, T2> & rhs )
	{
		return (lhs.first != rhs.first || lhs.second != rhs.second);
	}

	template < class T1, class T2 >
	bool operator< ( const ft::pair<T1, T2> & lhs,  const ft::pair<T1, T2> & rhs )
	{
		return (lhs.first < rhs.first \
			|| (lhs.first == rhs.first && lhs.second < rhs.second));
	}

	template < class T1, class T2 >
	bool operator<= ( const ft::pair<T1, T2> & lhs,  const ft::pair<T1, T2> & rhs )
	{
		return (lhs.first < rhs.first \
			|| (lhs.first == rhs.first && lhs.second <= rhs.second));
	}

	template < class T1, class T2 >
	bool operator> ( const ft::pair<T1, T2> & lhs,  const ft::pair<T1, T2> & rhs )
	{
		return (lhs.first > rhs.first \
			|| (lhs.first == rhs.first && lhs.second > rhs.second));
	}

	template < class T1, class T2 >
	bool operator>= ( const ft::pair<T1, T2> & lhs,  const ft::pair<T1, T2> & rhs )
	{
		return (lhs.first > rhs.first \
			|| (lhs.first == rhs.first && lhs.second >= rhs.second));
	}
} // namespace ft


#endif // FT_PAIR_TPP
