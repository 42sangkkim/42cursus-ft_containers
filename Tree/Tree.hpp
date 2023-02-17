#ifndef FT_CONTAINERS_TREE_HPP
# define FT_CONTAINERS_TREE_HPP

# include <memory>
#include <iostream> // TODO :delete

namespace ft
{
	class Tree
	{
		public:
			enum dir_t
			{
				LEFT = 0,
				RIGHT,
			};

			class Node
			{
				public:
					int					_value;
					Node *				_parent;
					Node *				_child[2];

				private:
					// Never using
					Node ( void );
					Node ( const Node & other );
					Node & operator = ( const Node & other );

				public:
					Node ( int value );
					~Node ( void );

					Node * prev ( void );
					const Node * prev ( void ) const;
					Node * next ( void );
					const Node * next ( void ) const;

			}; // class Node

		protected:
			Node						__NIL_NODE__;
			Node *						_nil;
			Node *						_root;
			std::size_t					_size;

		private:
			// Never using
			Tree ( const Tree & other );
			Tree & operator = ( const Tree & other );

		public:
			Tree ( void );
			~Tree ( void );

			Node * find ( int value );
			const Node * find ( int value ) const;
			Node * insert ( int value );
			Node * erase ( Node * target );
			void clear ( void );

			 Node * lower_bound ( int value );
			 Node * upper_bound ( int value );

			void print_all(void)
			{
				print(this->_root);
			}
			void print(Node * target)
			{
				if (target->_child[LEFT] != NULL)
					print(target->_child[LEFT]);
				std::cout << target->_value << ", ";
				if (target->_child[RIGHT] != NULL)
					print(target->_child[RIGHT]);
			}

		protected:
			void destroy ( Node * target );

	};
} // namespace ft

# include "./Tree.tpp"

#endif // FT_CONTAINERS_TREE_HPP
