#ifndef FT_CONTAINERS_MAP_HPP
# define FT_CONTAINERS_MAP_HPP

# include <memory>
# include <functional>
# include "./pair.hpp"

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
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair< const Key, T >					value_type;
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef value_type &								reference;
			typedef const value_type &							const_reference;
			typedef Allocator::pointer							pointer;
			typedef Allocator::const_pointer					const_pointer;
			typedef RBnode										iterator;
			typedef const RBnode								const_iterator;
			typedef reverse_iterator<iterator>					reverse_iterator;
			typedef reverse_iterator<const_iterator>			const_reverse_iterator;

			// Member classes
			class value_compare : public std::binary_function< value_type, value_type, bool >
			{
				protected:
					// Member objects
					Compare comp;

				public:
					// Member functions
					value_compare ( void );
					value_compare ( Compare c );
					bool operator () ( const value_type & lhs, const value_type) const;

			}; // class value_compare

			class RBnode
			{
				private:
					value_type									_value;
					//e_color										_color;
					RBnode *									_parent;
					RBnode *									_child[2];

				public:
					RBnode ( void );
					RBnode ( value_type value );
					RBnode ( const RBnode & other );

					~RBnode ( void );

					RBnode & operator = ( const RBnode & other );

					value_type & getValue ( void );
					const value_type & getValue ( void ) const;

			};

			// Member objects
			RBnode *										_root;
			RBnode * 										_begin;
			RBnode *										_end;
			size_type										_size;

			// Member functions
			map ( void );
			explicit map ( const key_compare & comp, const allocator_type & alloc = allocator_type() );
			template < class InputIt >
			map ( InputIt first, InputIt last, const allocator_type & alloc = allocator_type() );
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
} // namespace ft

# include "./map.tpp"

#endif // FT_CONTAINERS_MAP_HPP
