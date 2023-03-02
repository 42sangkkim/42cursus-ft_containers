#ifndef FT_CONTAINERS_MAP_ITERATOR_HPP
# define FT_CONTAINERS_MAP_ITERATOR_HPP

# include "./map.hpp"

namespace ft
{
	template < class Key, class T, class Compare, class Allocator >
	class ft::map<Key, T, Compare, Allocator>::iterator
	{
		friend class ft::map<Key, T, Compare, Allocator>;
		friend class ft::map<Key, T, Compare, Allocator>::const_iterator;

		public:
			// public member types
			typedef ft::pair<const Key, T>				value_type;
			typedef std::ptrdiff_t						difference_type;
			typedef value_type *						pointer;
			typedef value_type &						reference;
			typedef std::bidirectional_iterator_tag		iterator_category;

		protected:
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

} // namespace ft

# include "./map_iterator.tpp"

#endif // FT_CONTAINERS_MAP_ITERATOR_HPP