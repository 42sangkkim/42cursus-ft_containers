#ifndef FT_PAIR_HPP
# define FT_PAIR_HPP

namespace ft
{
	template < class T1, class T2 >
	struct pair
	{
		// Member types
		typedef T1				first_type;
		typedef T2				second_type;

		// Member objects
		first_type				first;
		second_type				second;

		// Member functions
		pair ( void );
		pair ( const T1 & first, const T2 & second );
		pair ( const pair<T1, T2> & rhs );
		pair ( const pair & rhs ) = default;

		pair & operator= ( const pair<T1, T2> & rhs );
	};

	// Non-member fuctions
	template < class T1, class T2 >
	pair<T1, T2> make_pair ( T1 x, T2 y );
	
	template < class T1, class T2 >
	bool operator== ( const ft::pair<T1, T2> & lhs,  const ft::pair<T1, T2> & rhs );
	template < class T1, class T2 >
	bool operator!= ( const ft::pair<T1, T2> & lhs,  const ft::pair<T1, T2> & rhs );
	template < class T1, class T2 >
	bool operator< ( const ft::pair<T1, T2> & lhs,  const ft::pair<T1, T2> & rhs );
	template < class T1, class T2 >
	bool operator<= ( const ft::pair<T1, T2> & lhs,  const ft::pair<T1, T2> & rhs );
	template < class T1, class T2 >
	bool operator> ( const ft::pair<T1, T2> & lhs,  const ft::pair<T1, T2> & rhs );
	template < class T1, class T2 >
	bool operator>= ( const ft::pair<T1, T2> & lhs,  const ft::pair<T1, T2> & rhs );

}; // namespace  ft

# include "./pair.tpp"

#endif // FT_PAIR_HPP
