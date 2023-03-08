#ifndef FT_CONTAINERS_SET_ITERATOR_HPP
# define FT_CONTAINERS_SET_ITERATOR_HPP

# include "./set.hpp"

namespace ft
{
	template < class Key >
	class set_iterator
	{
		public:
			// public member types
			typedef const Key								value_type;
			typedef std::ptrdiff_t							difference_type;
			typedef value_type *							pointer;
			typedef value_type &							reference;
			typedef std::bidirectional_iterator_tag			iterator_category;

		protected:
			typedef typename ft::RedBlackNode<Key>			node_type;

		public:
			const node_type *								_cur;

		public:
			// public member functions
			set_iterator ( void );
			set_iterator ( const set_iterator & other );
			set_iterator ( const node_type * cur );
			~set_iterator ( void );

			set_iterator & operator = ( const set_iterator & other );

			bool operator == ( const set_iterator & other ) const;
			bool operator != ( const set_iterator & other ) const;

			value_type & operator * ( void ) const;
			value_type * operator -> ( void ) const;

			set_iterator & operator ++ ( void );
			set_iterator operator ++ ( int n );
			set_iterator & operator -- ( void );
			set_iterator operator -- ( int n );

	}; // class set_iterator

} // namespace ft

# include "./set_iterator.tpp"

#endif // FT_CONTAINERS_SET_ITERATOR_HPP