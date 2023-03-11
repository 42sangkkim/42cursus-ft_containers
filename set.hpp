#ifndef FT_CONTAINERS_SET_HPP
# define FT_CONTAINERS_SET_HPP

# include <memory>
# include <functional>
# include "./RedBlackTree/RedBlackTree.hpp"
# include "./reverse_iterator.hpp"
# include "./pair.hpp"

# include "./set_iterator.hpp"

namespace ft
{
	template < 
		class Key, 
		class Compare = std::less<Key>, 
		class Allocator = std::allocator<Key> >
	class set
	{
		public:
			// Member types
			typedef Key												key_type;
			typedef Key												value_type;
			typedef std::size_t										size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef Compare											key_compare;
			typedef Compare											value_compare;
			typedef Allocator										allocator_type;
			typedef typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;
			typedef value_type &									reference;
			typedef const value_type &								const_reference;
			typedef typename ft::set_iterator<Key>					iterator;
			typedef iterator										const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		protected:
			typedef	typename ft::RedBlackTree<Key, Compare, Allocator>	tree_type;
			typedef typename tree_type::node_type						node_type;

		protected:
			// Member objects
			tree_type												_tree;

		public:
			//Member functions
			set ( void );
			explicit set ( const Compare & comp, const Allocator & alloc = Allocator() );
			template < class InputIt >
			set ( InputIt first, InputIt last, const Compare & comp = Compare(), const Allocator & alloc = Allocator() );
			set ( const set & other );
			~set ( void );

			set & operator = ( const set & other );
			allocator_type get_allocator ( void ) const;

			//		Iterators
			iterator begin ( void );
			const_iterator begin ( void ) const;
			iterator end ( void );
			const_iterator end ( void ) const;
			reverse_iterator rbegin ( void );
			const_reverse_iterator rbegin ( void ) const;
			reverse_iterator rend ( void );
			const_reverse_iterator rend ( void ) const;

			//		Capacity
			bool empty ( void ) const;
			size_type size ( void ) const;
			size_type max_size ( void ) const;

			//		Modifiers
			void clear ( void );
			ft::pair<iterator, bool> insert ( const value_type & value );
			iterator insert ( iterator pos, const value_type & value );
			template < class InputIt >
			void insert ( InputIt first, InputIt last );
			iterator erase ( iterator pos );
			iterator erase ( iterator first, iterator last );
			size_type erase ( const key_type & key );
			void swap ( set & other );

			//		Lookup
			size_type count ( const key_type & key ) const;
			iterator find ( const key_type & key );
			const_iterator find ( const key_type & key ) const;
			ft::pair<iterator, iterator> equal_range ( const key_type & key );
			ft::pair<const_iterator, const_iterator> equal_range ( const key_type & key ) const;
			iterator lower_bound ( const key_type & key );
			const_iterator lower_bound ( const key_type & key ) const;
			iterator upper_bound ( const key_type & key );
			const_iterator upper_bound ( const key_type & key ) const;

			//		Observers
			key_compare key_comp ( void ) const;
			value_compare value_comp ( void ) const;

	}; // class set

	// Non-member functions
	template < class Key, class Compare, class Allocator >
	bool operator == ( const ft::set<Key, Compare, Allocator> & lhs, const ft::set<Key, Compare, Allocator> & rhs );
	template < class Key, class Compare, class Allocator >
	bool operator != ( const ft::set<Key, Compare, Allocator> & lhs, const ft::set<Key, Compare, Allocator> & rhs );
	template < class Key, class Compare, class Allocator >
	bool operator < ( const ft::set<Key, Compare, Allocator> & lhs, const ft::set<Key, Compare, Allocator> & rhs );
	template < class Key, class Compare, class Allocator >
	bool operator > ( const ft::set<Key, Compare, Allocator> & lhs, const ft::set<Key, Compare, Allocator> & rhs );
	template < class Key, class Compare, class Allocator >
	bool operator <= ( const ft::set<Key, Compare, Allocator> & lhs, const ft::set<Key, Compare, Allocator> & rhs );
	template < class Key, class Compare, class Allocator >
	bool operator >= ( const ft::set<Key, Compare, Allocator> & lhs, const ft::set<Key, Compare, Allocator> & rhs );

} // namespace ft

// # include "./set_iterator.hpp"
# include "./set.tpp"

#endif // FT_CONTAINERS_SET_HPP