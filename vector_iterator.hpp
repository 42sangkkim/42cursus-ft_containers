#ifndef FT_CONTAINERS_VECTOR_ITERATOR_HPP
# define FT_CONTAINERS_VECTOR_ITERATOR_HPP

namespace ft
{
	template < class T >
	class vector_iterator
	{
		public:
			typedef T									value_type;
			typedef std::ptrdiff_t						difference_type;
			typedef T *									pointer;
			typedef T &									reference;
			typedef std::random_access_iterator_tag		iterator_category;

		public:
			// Member objects
			T *											_cur;

		public:
			// Member functions
			vector_iterator ( void );
			vector_iterator ( const vector_iterator & other );
			vector_iterator ( T * cur );
			~vector_iterator ( void );

			vector_iterator & operator = ( const vector_iterator & other );

			bool operator == ( const vector_iterator & other ) const;
			bool operator != ( const vector_iterator & other ) const;

			T & operator * ( void );
			const T & operator * ( void ) const;
			T * operator -> ( void );
			const T * operator -> ( void ) const;
			T & operator [] ( difference_type n );
			const T & operator [] ( difference_type n ) const;

			vector_iterator & operator ++ ( void );
			vector_iterator operator ++ ( int n );
			vector_iterator & operator -- ( void );
			vector_iterator operator -- ( int n );

			difference_type operator - ( const vector_iterator & other ) const;

			bool operator < ( const vector_iterator & other ) const;
			bool operator > ( const vector_iterator & other ) const;
			bool operator <= ( const vector_iterator & other ) const;
			bool operator >= ( const vector_iterator & other ) const;

			vector_iterator & operator += ( difference_type n );
			vector_iterator & operator -= ( difference_type n );

	}; // class vector_iterator

	// Non-member function
	template < class T >
	typename ft::vector_iterator<T> operator + ( const ft::vector_iterator<T> & lhs, typename ft::vector_iterator<T>::difference_type rhs );
	template < class T >
	typename ft::vector_iterator<T> operator + ( typename ft::vector_iterator<T>::difference_type lhs, const ft::vector_iterator<T> & rhs );
	template < class T >
	typename ft::vector_iterator<T> operator - ( const ft::vector_iterator<T> & lhs, typename ft::vector_iterator<T>::difference_type rhs );

	template < class T >
	class const_vector_iterator
	{
		public:
			typedef const T								value_type;
			typedef std::ptrdiff_t						difference_type;
			typedef const T *							pointer;
			typedef const T &							reference;
			typedef std::random_access_iterator_tag		iterator_category;

		public:
			// Member objects
			const T *									_cur;

		public:
			// Member functions
			const_vector_iterator ( void );
			const_vector_iterator ( const const_vector_iterator & other );
			const_vector_iterator ( const ft::vector_iterator<T> & iter );
			const_vector_iterator ( const T * cur );
			~const_vector_iterator ( void );

			const_vector_iterator & operator = ( const const_vector_iterator & other );

			bool operator == ( const const_vector_iterator & other ) const;
			bool operator != ( const const_vector_iterator & other ) const;

			const T & operator * ( void ) const;
			const T * operator -> ( void ) const;
			const T & operator [] ( difference_type n ) const;

			const_vector_iterator & operator ++ ( void );
			const_vector_iterator operator ++ ( int n );
			const_vector_iterator & operator -- ( void );
			const_vector_iterator operator -- ( int n );

			difference_type operator - ( const const_vector_iterator & other ) const;

			bool operator < ( const const_vector_iterator & other ) const;
			bool operator > ( const const_vector_iterator & other ) const;
			bool operator <= ( const const_vector_iterator & other ) const;
			bool operator >= ( const const_vector_iterator & other ) const;

			const_vector_iterator & operator += ( difference_type n );
			const_vector_iterator & operator -= ( difference_type n );

	}; // class const_vector_iterator

	//Non-member function
	template < class T >
	typename ft::const_vector_iterator<T> operator + ( const ft::const_vector_iterator<T> & lhs, typename ft::const_vector_iterator<T>::difference_type rhs );
	template < class T >
	typename ft::const_vector_iterator<T> operator + ( typename ft::const_vector_iterator<T>::difference_type lhs, const ft::const_vector_iterator<T> & rhs );
	template < class T >
	typename ft::const_vector_iterator<T> operator - ( const ft::const_vector_iterator<T> & lhs, typename ft::const_vector_iterator<T>::difference_type rhs );


	// Normal - const operations

	template < class T >
	typename ft::const_vector_iterator<T> operator + ( const ft::vector_iterator<T> & lhs, const ft::const_vector_iterator<T> & rhs );
	template < class T >
	typename ft::const_vector_iterator<T> operator + ( const ft::const_vector_iterator<T> & lhs, const ft::vector_iterator<T> & rhs );
	template < class T >
	typename ft::const_vector_iterator<T>::difference_type operator - ( const ft::vector_iterator<T> & lhs, const ft::const_vector_iterator<T> & rhs );
	template < class T >
	typename ft::const_vector_iterator<T>::difference_type operator - ( const ft::const_vector_iterator<T> & lhs, const ft::vector_iterator<T> & rhs );

	template < class T >
	bool operator == ( const ft::vector_iterator<T> & lhs, const ft::const_vector_iterator<T> & rhs );
	template < class T >
	bool operator == ( const ft::const_vector_iterator<T> & lhs, const ft::vector_iterator<T> & rhs );
	template < class T >
	bool operator != ( const ft::vector_iterator<T> & lhs, const ft::const_vector_iterator<T> & rhs );
	template < class T >
	bool operator != ( const ft::const_vector_iterator<T> & lhs, const ft::vector_iterator<T> & rhs );
	template < class T >
	bool operator < ( const ft::vector_iterator<T> & lhs, const ft::const_vector_iterator<T> & rhs );
	template < class T >
	bool operator < ( const ft::const_vector_iterator<T> & lhs, const ft::vector_iterator<T> & rhs );
	template < class T >
	bool operator > ( const ft::vector_iterator<T> & lhs, const ft::const_vector_iterator<T> & rhs );
	template < class T >
	bool operator > ( const ft::const_vector_iterator<T> & lhs, const ft::vector_iterator<T> & rhs );
	template < class T >
	bool operator <= ( const ft::vector_iterator<T> & lhs, const ft::const_vector_iterator<T> & rhs );
	template < class T >
	bool operator <= ( const ft::const_vector_iterator<T> & lhs, const ft::vector_iterator<T> & rhs );
	template < class T >
	bool operator >= ( const ft::vector_iterator<T> & lhs, const ft::const_vector_iterator<T> & rhs );
	template < class T >
	bool operator >= ( const ft::const_vector_iterator<T> & lhs, const ft::vector_iterator<T> & rhs );

} // namespace ft

# include "./vector_iterator.tpp"

#endif // FT_CONTAINERS_VECTOR_ITERATOR_HPP