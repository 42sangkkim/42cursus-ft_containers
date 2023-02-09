#ifndef FT_CONTAINERS_MAP_HPP
# define FT_CONTAINERS_MAP_HPP

# include <memory>
# include "./pair.hpp"

namespace ft
{
	template < 
		class Key, 
		class T, 
		class Compare = std::less<Key>, 
		class Allocator = std::allocator< ft::pair<const Key, T> >
	class map
	{
		public:
			// Member types
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef ft::pair<const key_type, mapped_type>				value_type;
			typedef std::size_t											size_type;
			typedef std::ptrdiff_t										difference_type;
			typedef Compare												key_compare;
			typedef Allocator											allocator_type;
			typedef value_type &										reference;
			typedef const value_type &									const_reference;
			typedef Allocator::pointer									pointer;
			typedef Allocator::const_pointer							const_pointer;
			typedef	iterator; // TODO
			typedef	const_iterator; // TODO
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		protected:
			// Member Objects

			// Member classes
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				protected:
					// Member objects
					compare_type										comp;

					// Member functions
					value_compare ( compare_type c );

				public:
					// Member functions
					bool operator() ( const value_type & lhs, const value_type & rhs ) const;

			};

		public:
			// Member functions
			map ( void );
			explicit map ( const key_compare & comp, const allocator_type alloc = allocator_type() );
			template < class InputIt >
			map ( ft::enable_if<!ft::is_integral<InputIt>, InputIt> first, InputIt last, const allocator_type & alloc = allocator_type() );
			map ( const map & other );

			~map ( void );
			map & operator = ( const map & other );
			allocator_type get_allocator ( void ) const;

			// Element access
			mapped_type & at ( const key_type & key );					// std::out_of_range
			const mapped_type & at ( const key_type & key ) const;		// std::out_of_range
			mapped_type & operator [] ( const key_type & key );

			// Iterators
			iterator begin ( void );
			const_iterator begin ( void ) const;
			iterator end ( void );
			const_iterator end ( void ) const;
			reverse_iterator rbegin ( void );
			const_reverse_iterator rbegin ( void ) const;
			reverse_iterator rend ( void );
			const_reverse_iterator rend ( void ) const;

			// Capacity
			bool empty ( void ) const;
			size_type size ( void ) const;
			size_type max_size ( void ) const;

			// Modifiers
			void clear ( void );
			ft::pair<iterator, bool> insert ( const value_type & value );
			iterator insert ( iterator pos, const value_type & value );
			template < class InputIt >
			ft::enable_if<!ft::is_integral<InputIt>, void> insert ( InputIt first, InputIt last );
			iterator erase ( iterator pos );
			iterator erase ( iterator first, iterator last );
			size_type erase ( const key_type & key );
			void swap ( map & other );

			// Look up
			size_type count ( const key_type & key ) const;
			iterator find ( const key_type & key );
			const_iterator find ( const key_type & key ) const;
			ft::pair<iterator, iterator> equal_range ( const key_type & key );
			ft::pair<const_iterator, const_iterator> equal_range ( const key_type & key ) const;
			iterator lower_bound ( const key_type & key );
			const_iterator lower_bound ( const key_type & key ) const;
			iterator upper_bound ( const key_type & key );
			const_iterator upper_bound ( const key_type & key ) const;

			// Observers
			key_comp key_comp ( void ) const;
			ft::map::value_compare value_comp ( void ) const;

	}

	// Non-member functions
	template < class Key, class T, class Compare, class Alloc >
	bool operator == ( const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs );

	template < class Key, class T, class Compare, class Alloc >
	bool operator != ( const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs );

	template < class Key, class T, class Compare, class Alloc >
	bool operator < ( const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs );

	template < class Key, class T, class Compare, class Alloc >
	bool operator > ( const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs );

	template < class Key, class T, class Compare, class Alloc >
	bool operator <= ( const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs );

	template < class Key, class T, class Compare, class Alloc >
	bool operator >= ( const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs );

	template < class Key, class T, class Compare, class Alloc >
	void swap ( ft::map<Key, T, Compare, Alloc> & lhs, ft::map<Key, T, Compare, Alloc> & rhs );

} // namespace ft

# include "./map.tpp"

#endif // FT_CONTAINERS_MAP_HPP
