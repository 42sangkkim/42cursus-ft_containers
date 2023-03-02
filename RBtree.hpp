#ifndef FT_CONTAINERS_RB_TREE_HPP
# define FT_CONTAINERS_RB_TREE_HPP

# include "./pair.hpp"

namespace ft
{
	template < class Key, class T, class Compare, class Allocator >
	class RBtree
	{
		public:
			typedef Key								key_type;
			typedef T								mapped_type;
			typedef ft::pair<const Key, T>			value_type;
			typedef Compare							key_compare;
			typedef Allocator						allocator_type;

		protected:
			enum dir_t { LEFT = 0, RIGHT, };
			enum color_t { RED = 0, BLACK, };

		public:
			class RBnode
			{
				public:
					value_type 			value;
					RBnode *			parent;
					RBnode *			child[2];
					color_t				color;

				public:
					RBnode ( void );
					RBnode ( const RBnode & other );
					RBnode ( const value_type & value );
					~RBnode ( void );

					RBnode & operator = ( const RBnode & other );

					RBnode * prev ( void );
					const RBnode * prev ( void ) const;
					RBnode * next ( void );
					const RBnode * next ( void ) const;
			}; // class Node

		protected:
			RBnode *											_nil;
			RBnode *											_root;
			size_t												_size;
			key_compare											_comp;
			allocator_type										_alloc;
			typename Allocator::template rebind<RBnode>::other	_node_alloc;

		private:
			// Never using
			explicit RBtree ( const RBtree & other );
			RBtree & operator = ( const RBtree & other );

		protected:
			void destroy_node ( RBnode * node );

		public:
			RBtree ( void );
			RBtree ( const key_compare & comp, const allocator_type & alloc );
			~RBtree ( void );

			size_t size ( void ) const;

			RBnode * begin ( void );
			const RBnode * begin ( void ) const;
			RBnode * end ( void );
			const RBnode * end ( void ) const;

			RBnode * find ( const key_type & key );
			const RBnode * find ( const key_type & key ) const;
			RBnode * lower_bound ( const key_type & key );
			const RBnode * lower_bound ( const key_type & key ) const;
			RBnode * upper_bound ( const key_type & key );
			const RBnode * upper_bound ( const key_type & key ) const;

			ft::pair<RBnode *, bool> insert ( const value_type & value );
			RBnode * erase ( RBnode * target );
			void clear ( void );

			void swap ( RBtree & other );

	}; // class RBree
} // namespace ft

# include "./RBtree.tpp"

#endif // FT_CONTAINERS_RB_TREE_HPP