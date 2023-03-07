#ifndef FT_CONTAINERS_RED_BLACK_NODE_HPP
# define FT_CONTAINERS_RED_BLACK_NODE_HPP

# include "./RedBlackTree.hpp"

namespace ft
{
	enum dir_t		{LEFT = 0, RIGHT};
	enum color_t	{RED = 0 , BLACK};

	template < class T >
	class RedBlackNode
	{
		protected:
			// Member types
			typedef T											value_type;

		public:
			// Member objects
			RedBlackNode *										parent;
			RedBlackNode *										child[2];
			value_type											value;
			color_t												color;

		public:
			// Member functions
			RedBlackNode ( const value_type & value = value_type() );
			RedBlackNode ( const RedBlackNode & other );
			~RedBlackNode ( void );

			RedBlackNode & operator = ( const RedBlackNode & other );

			RedBlackNode * prev ( void );
			const RedBlackNode * prev ( void ) const;
			RedBlackNode * next ( void );
			const RedBlackNode * next ( void ) const;

	}; // class RedBlackNode
} // namespace ft

# include "./RedBlackNode.tpp"

#endif // FT_CONTAINERS_RED_BLACK_NODE_HPP
