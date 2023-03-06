#ifndef FT_CONTAINERS_RED_BLACK_TREE_HPP
# define FT_CONTAINERS_RED_BLACK_TREE_HPP

# include <functional>
# include <memory>
# include "../pair.hpp"

namespace ft
{
	template < class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	class RedBlackTree
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
			node *													_head;
			node *													_root;
			size_t													_size;
			compare													_comp;
			allocator_type											_alloc;
			typename Allocator::template rebind<node>:: other		_node_alloc;

		private:
			// Never using
			RedBlackTree ( void );
			explicit RedBlackTree ( const RedBlackTree & other );
			RedBlackTree & operator = ( const RedBlackTree & other );

		protected:
			void destroy_node ( node * node );

			void rotate ( node * target, dir_t dir );
			void check_double_red ( node * target );
			void extra_black ( node * target, node * parent);

		public:
			RedBlackTree ( const compare & comp, const allocator_type & alloc );
			~RedBlackTree ( void );

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

			void swap ( RedBlackTree & other );

	}; // class RBree
} // namespace ft

# include "./RedBlackTree_node.hpp"

# include "./RedBlackTree.tpp"

#endif // FT_CONTAINERS_RED_BLACK_TREE_HPP