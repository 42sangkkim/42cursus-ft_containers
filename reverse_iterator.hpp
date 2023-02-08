#ifndef FT_CONTAINERS_RESERSE_ITERATOR_HPP
# define FT_CONTAINERS_RESERSE_ITERATOR_HPP

# include "./iterator_traits.hpp"

namespace ft
{
	template < class Iter >
	class reverse_iterator : public std::iterator < 
			typename ft::iterator_traits<Iter>::difference_type, 
			typename ft::iterator_traits<Iter>::value_type, 
			typename ft::iterator_traits<Iter>::pointer, 
			typename ft::iterator_traits<Iter>::reference, 
			typename ft::iterator_traits<Iter>::iterator_category >
	{
		public:
			// Member types
			typedef Iter													iterator_type;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef typename ft::iterator_traits<Iter>::reference			reference;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;

		protected:
			// Member objects
			iterator_type			current;

		public:
			// Member functions
			// (Constructor)
			reverse_iterator ( void );
			explicit reverse_iterator ( iterator_type x );
			template < class U >
			reverse_iterator ( const reverse_iterator<U> & other );

			template < class U >
			reverse_iterator & operator = ( const reverse_iterator<U> & other );

			iterator_type base ( void ) const;

			reference operator * ( void ) const;
			pointer operator -> ( void ) const;

			reference operator [] ( difference_type n ) const;

			reverse_iterator & operator ++ ( void );
			reverse_iterator & operator -- ( void );
			reverse_iterator operator ++ ( int );
			reverse_iterator operator -- ( int );
			reverse_iterator operator + ( difference_type n ) const;
			reverse_iterator operator - ( difference_type n ) const;
			reverse_iterator & operator += ( difference_type n );
			reverse_iterator & operator -= ( difference_type n );

	};

}

# include "./reverse_iterator.tpp"

#endif // FT_CONTAINERS_RESERSE_ITERATOR_HPP
