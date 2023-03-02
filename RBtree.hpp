#ifndef FT_CONTAINERS_RB_TREE_HPP
# define FT_CONTAINERS_RB_TREE_HPP

# include <functional>
# include <memory>
# include "./pair.hpp"

namespace ft
{
	template < class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	class RBtree
	{
		public:
			typedef T										value_type;
			typedef Compare									compare;
			typedef Allocator								allocator_type;

		protected:
			enum dir_t   { LEFT = 0, RIGHT, };
			enum color_t { RED  = 0, BLACK, };

		public:
			class node;

		protected:
			node *													_nil;
			node *													_root;
			size_t													_size;
			compare													_comp;
			allocator_type											_alloc;
			typename Allocator::template rebind<node>:: other		_node_alloc;

		private:
			// Never using
			explicit RBtree ( const RBtree & other );
			RBtree & operator = ( const RBtree & other );

		protected:
			void destroy_node ( node * node );

		public:
			// RBtree ( void );
			RBtree ( const compare & comp, const allocator_type & alloc );
			~RBtree ( void );

			size_t size ( void ) const;
			size_t max_size ( void ) const;

			node * begin ( void );
			const node * begin ( void ) const;

			node * end ( void );
			const node * end ( void ) const;

			node * find ( const value_type & value );
			const node * find ( const value_type & value ) const;

			node * lower_bound ( const value_type & value );
			const node * lower_bound ( const value_type & value ) const;

			node * upper_bound ( const value_type & value );
			const node * upper_bound ( const value_type & value ) const;

			ft::pair<node *, bool> insert ( const value_type & value );
			node * erase ( node * target );
			void clear ( void );

			void swap ( RBtree & other );

	}; // class RBree
} // namespace ft

# include "./RBtree_node.hpp"

# include "./RBtree.tpp"

#endif // FT_CONTAINERS_RB_TREE_HPP