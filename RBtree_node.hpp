#ifndef FT_CONTAINERS_RB_TREE_NODE_HPP
# define FT_CONTAINERS_RB_TREE_NODE_HPP

# include "./RBtree.hpp"

namespace ft
{
	template < class T, class Compare, class Allocator >
	class ft::RBtree<T, Compare, Allocator>::node
	{
		public:
			// Member objects
			value_type									value;
			node *										parent;
			node *										child[2];
			color_t										color;

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

# include "./RBtree_node.tpp"

#endif // FT_CONTAINERS_RB_TREE_NODE_HPP
