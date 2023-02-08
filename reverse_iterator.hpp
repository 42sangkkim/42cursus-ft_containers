#ifndef FT_CONTAINERS_RESERSE_ITERATOR_HPP
# define FT_CONTAINERS_RESERSE_ITERATOR_HPP

namespace ft
{
	template < class Iter >
	class reverse_iteratori : public std::iterator < 
			ft::iterator_traits<Iter>::difference_type, 
			ft::iterator_traits<Iter>::value_type, 
			ft::iterator_traits<Iter>::pointer, 
			ft::iterator_traits<Iter>::reference, 
			ft::iterator_traits<Iter>::iterator_category >
	{
		public:
			// Member types
			typedef Iter													iterator_type;

		protected:
			// Member objects
			iterator_type			current;

		public:
			// Member functions
			// (Constructor)
			reverse_iterator ( void );
			ecplicit reverse_iterator ( iterator_type x );
			template < class U >
			reverse_iterator ( const reverse_iterator < U > & other );

			reverse_iterator & operator = ( const reverse_iterator < U > & other );

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
