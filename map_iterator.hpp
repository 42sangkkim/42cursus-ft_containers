#ifndef FT_CONTAINERS_MAP_ITERATOR_HPP
# define FT_CONTAINERS_MAP_ITERATOR_HPP

# include "./map.hpp"

namespace ft
{
	template < class Key, class T >
	class map_iterator
	{
		public:
			typedef ft::pair<const Key, T>					value_type;
			typedef std::ptrdiff_t							difference_type;
			typedef value_type *							pointer;
			typedef value_type &							reference;
			typedef std::bidirectional_iterator_tag			iterator_category;

		protected:
			typedef typename ft::RedBlackNode<value_type>	node_type;

		public:
			node_type *										_cur;

		public:
			// public member functions
			map_iterator ( void );
			map_iterator ( const map_iterator & other );
			map_iterator ( node_type * cur );
			virtual ~map_iterator ( void );

			map_iterator & operator = ( const map_iterator & other );

			bool operator == ( const map_iterator & other ) const;
			bool operator != ( const map_iterator & other ) const;

			value_type & operator * ( void );
			const value_type & operator * ( void ) const;
			value_type * operator -> ( void );
			const value_type * operator -> ( void ) const;

			map_iterator & operator ++ ( void );
			map_iterator operator ++ ( int n );
			map_iterator & operator -- ( void );
			map_iterator operator -- ( int n );

	}; // map_iterator

	template < class Key, class T >
	class const_map_iterator
	{
		public:
			// public member types
			typedef ft::pair<const Key, T>					value_type;
			typedef std::ptrdiff_t							difference_type;
			typedef const value_type *						pointer;
			typedef const value_type &						reference;
			typedef std::bidirectional_iterator_tag			iterator_category;
		protected:
			typedef typename ft::RedBlackNode<value_type>	node_type;

		public:
			const node_type *								_cur;

		public:
			// public member functions
			const_map_iterator ( void );
			const_map_iterator ( const const_map_iterator & other );
			const_map_iterator ( const node_type * cur );
			const_map_iterator ( const ft::map_iterator<Key, T> & iter );
			~const_map_iterator ( void );

			const_map_iterator & operator = ( const const_map_iterator & other );

			bool operator == ( const const_map_iterator & other ) const;
			bool operator != ( const const_map_iterator & other ) const;

			const value_type & operator * ( void ) const;
			const value_type * operator -> ( void ) const;

			const_map_iterator & operator ++ ( void );
			const_map_iterator operator ++ ( int n );
			const_map_iterator & operator -- ( void );
			const_map_iterator operator -- ( int n );

	}; // class map_const_iterator

} // namespace ft

# include "./map_iterator.tpp"

#endif // FT_CONTAINERS_MAP_ITERATOR_HPP