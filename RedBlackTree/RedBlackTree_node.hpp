#ifndef FT_CONTAINERS_RED_BLACK_TREE_NODE_HPP
# define FT_CONTAINERS_RED_BLACK_TREE_NODE_HPP

# include "./RedBlackTree.hpp"

namespace ft
{
	template < class T, class Compare, class Allocator >
	class ft::RedBlackTree<T, Compare, Allocator>::node
	{
		public:
			// Member objects
			value_type									value;
			color_t										color;
			node *										parent;
			node *										child[2];

		public:
			// Member functions
			node ( void );
			node ( const node & other );
			node ( const value_type & value );
			~node ( void );

			node & operator = ( const node & other );

			node * prev ( void );
			const node * prev ( void ) const;

			node * next ( void );
			const node * next ( void ) const;

	}; // class node
} // namespace ft

# include "./RedBlackTree_node.tpp"

#endif // FT_CONTAINERS_RED_BLACK_TREE_NODE_HPP
