#ifndef FT_CONTAINERS_TREE_HPP
# define FT_CONTAINERS_TREE_HPP

# include <memory>
# include "../pair.hpp" // TODO : change direction

namespace ft
{
	template < class Key, class T, class Compare, class Allocator >
	class Tree
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<Key, T>						value_type;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef Compare									key_compare;
			typedef Allocator								allocator_type;
			typedef value_type &							reference;
			typedef const value_type &						const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;

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

				public:
					Node ( void );
					Node ( const Node & other );
					Node ( const_reference value );
					~Node ( void );

					Node & operator = ( const Node & other );

					Node * prev ( void );
					const Node * prev ( void ) const;
					Node * next ( void );
					const Node * next ( void ) const;

			}; // class Node

		protected:
			Node													__NIL_NODE__;
			Node *													_nil;
			Node *													_root;
			size_type												_size;
			key_compare												_comp;
			typename allocator_type::template rebind<Node>::other	_alloc;

		private:
			// Never using
			Tree ( const Tree & other );
			Tree & operator = ( const Tree & other );

		public:
			Tree ( void );
			~Tree ( void );

			Node * find ( const key_type & key );
			const Node * find ( const key_type & key ) const;
			Node * insert ( const_reference value );
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
