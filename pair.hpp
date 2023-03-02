#ifndef FT_CONTAINERS_PAIR_HPP
# define FT_CONTAINERS_PAIR_HPP

namespace ft
{
	template < class T1, class T2 >
	struct pair
	{
		// Member typed
		typedef T1					first_type;
		typedef T2					second_type;

		// Member Objects
		first_type					first;
		second_type					second;

		// Member function
		pair ( void );
		pair ( const T1 & x, const T2 & y );
		template < class U1, class U2 >
		pair ( const pair<U1, U2> & p );

		pair & operator = ( const pair & other );

	}; // struct pair

	// Non-member functions
	template < class T1, class T2 >
	typename ft::pair<T1, T2> make_pair ( T1 t, T2 u );

	template < class T1, class T2 >
	bool operator == ( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs );

	template < class T1, class T2 >
	bool operator != ( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs );

	template < class T1, class T2 >
	bool operator < ( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs );

	template < class T1, class T2 >
	bool operator > ( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs );

	template < class T1, class T2 >
	bool operator <= ( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs );

	template < class T1, class T2 >
	bool operator >= ( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs );

} // namespace ft

# include "./pair.tpp"

#endif // FT_CONTAINERS_PAIR_HPP
