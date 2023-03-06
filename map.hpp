#ifndef FT_CONTAINERS_MAP_HPP
# define FT_CONTAINERS_MAP_HPP

# include <memory>
# include <functional>
# include "./RedBlackTree/RedBlackTree.hpp"
# include "./pair.hpp"
# include "./reverse_iterator.hpp"

#include<map>

namespace ft
{
	template <
		class Key,
		class T,
		class Compare = std::less< Key >,
		class Allocator = std::allocator< ft::pair< const Key, T > > >
	class map
	{
		public:
			// Member types
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair< const Key, T >						value_type;
			typedef std::size_t										size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef Compare											key_compare;
			class 													value_compare;	
			typedef Allocator										allocator_type;
			typedef value_type &									reference;
			typedef const value_type &								const_reference;
			typedef typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;
			class													iterator;
			class													const_iterator;	
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		protected:
			typedef RedBlackTree<value_type, value_compare, Allocator>	tree_type;
			typedef typename tree_type::node							node_type;

		protected:
			tree_type												_tree;

		public:
			// Member functions
			map ( void );
			explicit map ( const key_compare & comp, const allocator_type & alloc = allocator_type() );
			template < class InputIt >
			map ( InputIt first, InputIt last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type() );
			map ( const map & other );

			~map ( void );

			map & operator = ( const map & other );
			Allocator get_allocator ( void ) const;

			// Element accesses
			T & at ( const key_type & key );				// std::out_of_range
			const T & at ( const key_type & key ) const;	// std::out_of_range
			T & operator [] (const key_type & key );

			// iterators
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
			size_t size ( void ) const;
			size_t max_size ( void ) const;

			// Modifiers
			void clear ( void );
			ft::pair<iterator, bool> insert ( const value_type & value );
			iterator insert ( iterator pos, const value_type & value );
			template < class InputIt >
			void insert ( InputIt first, InputIt last );
			iterator erase ( iterator pos );
			iterator erase ( iterator first, iterator last );
			size_t erase ( const key_type & key );
			void swap ( map & other );

			// Lookup
			size_t count ( const key_type & key ) const;
			iterator find ( const key_type & key );
			const_iterator find ( const key_type & key ) const;
			ft::pair<iterator, iterator> equal_range ( const key_type & key );
			ft::pair<const_iterator, const_iterator> equal_range ( const key_type & key ) const;
			iterator lower_bound ( const key_type & key );
			const_iterator lower_bound ( const key_type & key ) const;
			iterator upper_bound ( const key_type & key );
			const_iterator upper_bound ( const key_type & key ) const;

			// Observers
			key_compare key_comp ( void ) const;
			value_compare value_comp ( void ) const;

	}; // class map

	// Non-member functions
	template < class Key, class T, class Compare, class Allocator >
	bool operator == ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs );
	template < class Key, class T, class Compare, class Allocator >
	bool operator != ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs );
	template < class Key, class T, class Compare, class Allocator >
	bool operator < ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs );
	template < class Key, class T, class Compare, class Allocator >
	bool operator > ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs );
	template < class Key, class T, class Compare, class Allocator >
	bool operator <= ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs );
	template < class Key, class T, class Compare, class Allocator >
	bool operator >= ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs );

	template < class Key, class T, class Compare, class Allocator >
	void swap ( ft::map<Key, T, Compare, Allocator> & lhs, ft::map<Key, T, Compare, Allocator> & rhs );

	template < class Key, class T, class Compare, class Allocator >
	class ft::map<Key, T, Compare, Allocator>::value_compare : public std::binary_function< value_type, value_type, bool >
	{
		friend class ft::map<Key, T, Compare, Allocator>;
		protected:
			// Member objects
			Compare comp;
			// protected member functions
			value_compare ( Compare c );

		public:
			// Member functions
			bool operator () ( const value_type & lhs, const value_type & rhs ) const;
	}; // class ft::map<Key, T, Compare, Allocator>::value_compare

} // namespace ft

# include "./map_iterator.hpp"
# include "./map.tpp"

#endif // FT_CONTAINERS_MAP_HPP
