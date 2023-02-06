#ifndef FT_REVERSE_ITERATOR_HPP
# define FT_REVERSE_ITERATOR_HPP

# include "./iterator_traits.hpp"

namespace ft
{

	template < class Iter >
	class reverse_iterator
	{
	public:
		// Member types
		typedef Iter													iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;

		// Member functions

		reverse_iterator ( void );
		explicit reverse_iterator ( iterator_type iter );
		template < class U >
		reverse_iterator ( const reverse_iterator<U> & other );

		template < class U >
		reverse_iterator & operator= ( const reverse_iterator<U> & other);

		iterator_type base ( void ) const;

		reference operator* ( void ) const;
		pointer operator-> ( void ) const;

		reference operator[] ( difference_type n ) const;

		reverse_iterator & operator++ ( void );
		reverse_iterator & operator++ ( int );
		reverse_iterator & operator+= ( difference_type n );
		reverse_iterator & operator+ ( difference_type n ) const;
		reverse_iterator & operator-- ( void );
		reverse_iterator & operator-- ( int );
		reverse_iterator & operator-= ( difference_type n );
		reverse_iterator & operator- ( difference_type n ) const;

	protected:
		// Member objects
		iterator_type	current;
	};

	// Non-member functions

	template < class Iterator1, class Iterator2 >
	bool operator== ( \
		const ft::reverse_iterator<Iterator1> & lhs, \
		const ft::reverse_iterator<Iterator2> & rhs 
	);
	template < class Iterator1, class Iterator2 >
	bool operator!= ( \
		const ft::reverse_iterator<Iterator1> & lhs, \
		const ft::reverse_iterator<Iterator2> & rhs 
	);
	template < class Iterator1, class Iterator2 >
	bool operator< ( \
		const ft::reverse_iterator<Iterator1> & lhs, \
		const ft::reverse_iterator<Iterator2> & rhs 
	);
	template < class Iterator1, class Iterator2 >
	bool operator<= ( \
		const ft::reverse_iterator<Iterator1> & lhs, \
		const ft::reverse_iterator<Iterator2> & rhs 
	);
	template < class Iterator1, class Iterator2 >
	bool operator> ( \
		const ft::reverse_iterator<Iterator1> & lhs, \
		const ft::reverse_iterator<Iterator2> & rhs 
	);
	template < class Iterator1, class Iterator2 >
	bool operator>= ( \
		const ft::reverse_iterator<Iterator1> & lhs, \
		const ft::reverse_iterator<Iterator2> & rhs 
	);

	template < class Iter >
	ft::reverse_iterator<Iter> operator+ ( \
		typename reverse_iterator<Iter>::difference_type n, \
		const reverse_iterator<Iter> & it \
	);

	template < class Iter >
	ft::reverse_iterator<Iter> operator- ( \
		typename reverse_iterator<Iter>::difference_type n, \
		const reverse_iterator<Iter> & it \
	);

}; // namespace ft

#endif // FT_REVERSE_ITERATOR_HPP
