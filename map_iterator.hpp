#ifndef FT_CONTAINERS_MAP_ITERATOR_HPP
# define FT_CONTAINERS_MAP_ITERATOR_HPP

# include "./map.hpp"

namespace ft
{
	template < class Key, class T, class Compare, class Allocator >
	class ft::map<Key, T, Compare, Allocator>::iterator
	{
		public:
			// public member types
			typedef ft::pair<const Key, T>				value_type;
			typedef std::ptrdiff_t						difference_type;
			typedef value_type *						pointer;
			typedef value_type &						reference;
			typedef std::bidirectional_iterator_tag		iterator_category;

		public:
			node_type									*_cur;

		public:
			// public member functions
			iterator ( void );
			iterator ( const iterator & other );
			iterator ( node_type * cur );
			~iterator ( void );

			iterator & operator = ( const iterator & other );

			bool operator == ( const iterator & other ) const;
			bool operator != ( const iterator & other ) const;

			value_type & operator * ( void );
			const value_type & operator * ( void ) const;
			value_type * operator -> ( void );
			const value_type * operator -> ( void ) const;

			iterator & operator ++ ( void );
			iterator operator ++ ( int n );
			iterator & operator -- ( void );
			iterator operator -- ( int n );

	}; // class ft::map<Key, T, Compare, Allocator>::iterator;

	template < class Key, class T, class Compare, class Allocator >
	class ft::map<Key, T, Compare, Allocator>::const_iterator
	{
		public:
			// public member types
			typedef ft::pair<const Key, T>				value_type;
			typedef std::ptrdiff_t						difference_type;
			typedef const value_type *					pointer;
			typedef const value_type &					reference;
			typedef std::bidirectional_iterator_tag		iterator_category;

		public:
			const node_type								*_cur;

		public:
			const_iterator ( void );
			const_iterator ( const const_iterator & other );
			const_iterator ( const iterator & it );
			const_iterator ( const node_type * cur );
			~const_iterator ( void );

			const_iterator & operator = ( const const_iterator & other );

			bool operator == ( const const_iterator & other ) const;
			bool operator != ( const const_iterator & other ) const;

			const value_type & operator * ( void ) const;
			const value_type * operator -> ( void ) const;

			const_iterator & operator ++ ( void );
			const_iterator operator ++ ( int n );
			const_iterator & operator -- ( void );
			const_iterator operator -- ( int n );
	}; // class ft::map<Key, T, Compare, Allocator>::const_iterator;

} // namespace ft

# include "./map_iterator.tpp"

#endif // FT_CONTAINERS_MAP_ITERATOR_HPP