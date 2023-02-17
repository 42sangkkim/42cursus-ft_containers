#ifndef FT_CONTAINERS_TREE_HPP
# define FT_CONTAINERS_TREE_HPP

# include <memory>
# include "../pair.hpp"

namespace ft
{
	template < class Key, class T >
	class Tree
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<Key, T>						value_type;
			typedef value_type &							reference;
			typedef const value_type &						const_reference;
			typedef value_type *							pointer; // TODO : Allocator
			typedef const value_type *						const_pointer; // TODO : Allocator

			enum dir_t
			{
				LEFT = 0,
				RIGHT,
			};

			class Node
			{
				public:
					value_type				_value;
					Node *					_parent;
					Node *					_child[2];

				private:
					// Never using
					Node ( const Node & other );
					Node & operator = ( const Node & other );

				public:
					Node ( void );
					Node ( const value_type & value );
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

			Node * find ( const key_type & key );
			const Node * find ( const key_type & key ) const;
			Node * insert ( const value_type & value );
			Node * erase ( Node * target );
			void clear ( void );

			Node * lower_bound ( const key_type & key );
			const Node * lower_bound ( const key_type & key ) const;
			Node * upper_bound ( const key_type & key );
			const Node * upper_bound ( const key_type & key ) const;

		protected:
			void destroy ( Node * target );

	};
} // namespace ft

# include "./Tree.tpp"

#endif // FT_CONTAINERS_TREE_HPP
