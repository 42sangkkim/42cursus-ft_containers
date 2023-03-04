#ifndef FT_CONTAINERS_SET_ITERATOR_HPP
# define FT_CONTAINERS_SET_ITERATOR_HPP

# include "./set.hpp"

namespace ft
{
	template < class Key, class Compare, class Allocator >
	class ft::set<Key, Compare, Allocator>::iterator
	{
		friend class ft::set<Key, Compare, Allocator>;

		public:
			// public member types
			typedef const Key							value_type;
			typedef std::ptrdiff_t						difference_type;
			typedef value_type *						pointer;
			typedef value_type &						reference;
			typedef std::bidirectional_iterator_tag		iterator_category;

		protected:
			const node_type								*_cur;

		public:
			// public member functions
			iterator ( void );
			iterator ( const iterator & other );
			iterator ( const node_type * cur );
			~iterator ( void );

			iterator & operator = ( const iterator & other );

			bool operator == ( const iterator & other ) const;
			bool operator != ( const iterator & other ) const;

			value_type & operator * ( void ) const;
			value_type * operator -> ( void ) const;

			iterator & operator ++ ( void );
			iterator operator ++ ( int n );
			iterator & operator -- ( void );
			iterator operator -- ( int n );
	}; // class ft::set<Key, Compare, Allocator>::iterator;

} // namespace ft

# include "./set_iterator.tpp"

#endif // FT_CONTAINERS_SET_ITERATOR_HPP