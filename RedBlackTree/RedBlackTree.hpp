#ifndef FT_CONTAINERS_RED_BLACK_TREE_HPP
# define FT_CONTAINERS_RED_BLACK_TREE_HPP

# include <functional>
# include <memory>
# include "../pair.hpp"

# include "./RedBlackNode.hpp"

namespace ft
{
	template < class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	class RedBlackTree
	{
		public:
			typedef T										value_type;
			typedef Compare									compare;
			typedef Allocator								allocator_type;
			typedef ft::RedBlackNode<T>						node_type;

		protected:
			node_type *												_head;
			node_type *												_root;
			size_t													_size;
			compare													_comp;
			allocator_type											_alloc;
			typename Allocator::template rebind<node_type>:: other		_node_alloc;

		private:
			// Never using
			RedBlackTree ( void );
			explicit RedBlackTree ( const RedBlackTree & other );
			RedBlackTree & operator = ( const RedBlackTree & other );

		protected:
			void destroy_node ( node_type * node );

			void rotate ( node_type * target, dir_t dir );
			void check_double_red ( node_type * target );
			void extra_black ( node_type * target, node_type * parent);

		public:
			RedBlackTree ( const compare & comp, const allocator_type & alloc );
			~RedBlackTree ( void );

			size_t size ( void ) const;
			size_t max_size ( void ) const;

			node_type * begin ( void );
			const node_type * begin ( void ) const;

			node_type * end ( void );
			const node_type * end ( void ) const;

			node_type * find ( const value_type & value );
			const node_type * find ( const value_type & value ) const;

			node_type * lower_bound ( const value_type & value );
			const node_type * lower_bound ( const value_type & value ) const;

			node_type * upper_bound ( const value_type & value );
			const node_type * upper_bound ( const value_type & value ) const;

			ft::pair<node_type *, bool> insert ( const value_type & value );
			node_type * erase ( node_type * target );
			void clear ( void );

			void swap ( RedBlackTree & other );

	}; // class RBree
} // namespace ft

# include "./RedBlackTree.tpp"

#endif // FT_CONTAINERS_RED_BLACK_TREE_HPP