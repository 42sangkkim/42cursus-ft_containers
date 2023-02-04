#ifndef FT_VECTOR_ITERATOR_HPP
# define FT_VECTOR_ITERATOR_HPP

# include "./vector.hpp"

namespace ft
{
	template < \
		class T, \
		class Allocator = std::allocator<T> \
	>
	class vector
	{
		class iterator : public std::iterator <\
			std::iterator_tag, \
			value_type, \
			difference_type, \
			pointer, \
			reference \
		>
		{
			public:
			// Constructor
				iterator ( void );
				iterator ( const iterator & other );
				iterator & operator= ( const iterator & other);
			
			// Destructor
				~iterator ( void );

			// Copy assignment
				iterator & operator= ( const iterator & other);

			// Compare
				bool operator== ( const iterator & other ) const;
				bool operator!= ( const iterator & other ) const;

			// rvalue
			*a;
			a->m;

			// lvalue
			*a = t;

			// Increment
				iterator operator++ ( void ); // prefix
				iterator operator++ ( int );  // postfix

			// Decrement
				iterator operator-- ( void ); // prefix
				iterator operator-- ( int );  // postfix

			// Arithmetic operator
				iterator operator+ ( size_type n );
				iterator operator- ( size_type n );

			// Compound assignment operator
				+=;
				-=;

			// Dereference operator
				reference operator[] ( size_type n );
				const_reference operator[] ( size_type n ) const;
		}
	};
};

#endif // FT_VECTOR_ITERATOR_HPP
