#ifndef FT_CONTAINERS_RB_TREE_TPP
# define FT_CONTAINERS_RB_TREE_TPP

# include "./RBtree.hpp"
#include <iostream>

// RBnode

namespace ft
{
	template < class K, class T, class C, class A >
	ft::RBtree<K, T, C, A>::RBnode::RBnode ( void )
		: value(), parent(NULL), color(RED)
	{
		child[RIGHT] = NULL;
		child[LEFT] = NULL;
	}

	template < class K, class T, class C, class A >
	ft::RBtree<K, T, C, A>::RBnode::RBnode ( const RBnode & other )
		: value(other.value), parent(other.parent), color(other.color)
	{
		child[RIGHT] = other.child[RIGHT];
		child[LEFT] = other.child[LEFT];
	}

	template < class K, class T, class C, class A >
	ft::RBtree<K, T, C, A>::RBnode::RBnode ( const value_type & value )
		: value(value), parent(NULL), color(RED)
	{
		child[RIGHT] = NULL;
		child[LEFT] = NULL;
	}

	template < class K, class T, class C, class A >
	ft::RBtree<K, T, C, A>::RBnode::~RBnode ( void )
	{}

	template < class K, class T, class C, class A >
	typename ft::RBtree<K, T, C, A>::RBnode & ft::RBtree<K, T, C, A>::RBnode::operator = ( const RBnode & other )
	{
		this->value = other.value;
		this->parent = other.parent;
		this->child[RIGHT] = other.child[RIGHT];
		this->child[LEFT] = other.child[LEFT];
		this->_color = other.color;
	}

	template < class K, class T, class C, class A >
	typename ft::RBtree<K, T, C, A>::RBnode * ft::RBtree<K, T, C, A>::RBnode::prev ( void )
	{
		RBnode * cur;
		if (this->child[LEFT] != NULL)
		{
			cur = this->child[LEFT];
			while (cur->child[RIGHT] != NULL)
				cur = cur->child[RIGHT];
		}
		else
		{
			cur = this;
			while (cur->parent != NULL && cur->parent->child[LEFT] == cur)
				cur = cur->parent;
			if (cur->parent != NULL)
				cur = cur->parent;
		}
		return cur;
	}

	template < class K, class T, class C, class A >
	const typename ft::RBtree<K, T, C, A>::RBnode * ft::RBtree<K, T, C, A>::RBnode::prev ( void ) const
	{
		const RBnode * cur;
		if (this->child[LEFT] != NULL)
		{
			cur = this->child[LEFT];
			while (cur->child[RIGHT] != NULL)
				cur = cur->child[RIGHT];
		}
		else
		{
			cur = this;
			while (cur->parent != NULL && cur->parent->child[LEFT] == cur)
				cur = cur->parent;
			if (cur->parent != NULL)
				cur = cur->parent;
		}
		return cur;
	}

	template < class K, class T, class C, class A >
	typename ft::RBtree<K, T, C, A>::RBnode * ft::RBtree<K, T, C, A>::RBnode::next ( void )
	{
		RBnode * cur;

		if (this->child[RIGHT] != NULL)
		{
			cur = this->child[RIGHT];
			while (cur->child[LEFT] != NULL)
				cur = cur->child[LEFT];
		}
		else
		{
			cur = this;
			while (cur->parent != NULL && cur->parent->child[RIGHT] == cur)
				cur = cur->parent;
			if (cur->parent != NULL)
				cur = cur->parent;
		}
		return cur;
	}

	template < class K, class T, class C, class A >
	const typename ft::RBtree<K, T, C, A>::RBnode * ft::RBtree<K, T, C, A>::RBnode::next ( void ) const
	{
		const RBnode * cur;
		if (this->child[RIGHT] != NULL)
		{
			cur = this->child[RIGHT];
			while (cur->child[LEFT] != NULL)
				cur = cur->child[LEFT];
		}
		else
		{
			cur = this;
			while (cur->parent != NULL && cur->parent->child[RIGHT] == cur)
				cur = cur->parent;
			if (cur->parent != NULL)
				cur = cur->parent;
		}
		return cur;
	}
} // namespace ft

// RBtree
namespace ft
{
	template < class K, class T, class C, class A >
	ft::RBtree<K, T, C, A>::RBtree ( void )
		: _size(0), _comp(), _alloc(), _node_alloc()
	{
		this->_nil = this->_node_alloc.allocate(1);
		this->_node_alloc.construct(this->_nil, RBnode());
		this->_nil->child[RIGHT] = this->_nil;
		this->_nil->child[LEFT] = this->_nil;
		this->_root = this->_nil;
	}

	template < class K, class T, class C, class A >
	ft::RBtree<K, T, C, A>::RBtree ( const key_compare & comp, const allocator_type & alloc )
		: _size(0), _comp(comp), _alloc(alloc)
	{
		this->_nil = this->_node_alloc.allocate(1);
		this->_node_alloc.construct(this->_nil, RBnode());
		this->_nil->child[RIGHT] = this->_nil;
		this->_nil->child[LEFT] = this->_nil;
		this->_root = this->_nil;
	}

	template < class K, class T, class C, class A >
	ft::RBtree<K, T, C, A>::~RBtree ( void )
	{
		this->clear();
		this->_node_alloc.destroy(this->_nil);
		this->_node_alloc.deallocate(this->_nil, 1);
	}

	template < class K, class T, class C, class A >
	size_t ft::RBtree<K, T, C, A>::size ( void ) const
	{
		return this->_size;
	}

	template < class K, class T, class C, class A >
	typename ft::RBtree<K, T, C, A>::RBnode * ft::RBtree<K, T, C, A>::begin ( void )
	{
		return this->_nil->child[RIGHT];
	}

	template < class K, class T, class C, class A >
	const typename ft::RBtree<K, T, C, A>::RBnode * ft::RBtree<K, T, C, A>::begin ( void ) const
	{
		return this->_nil->child[RIGHT];
	}

	template < class K, class T, class C, class A >
	typename ft::RBtree<K, T, C, A>::RBnode * ft::RBtree<K, T, C, A>::end ( void )
	{
		return this->_nil;
	}

	template < class K, class T, class C, class A >
	const typename ft::RBtree<K, T, C, A>::RBnode * ft::RBtree<K, T, C, A>::end ( void ) const
	{
		return this->_nil;
	}

	template < class K, class T, class C, class A >
	typename ft::RBtree<K, T, C, A>::RBnode * ft::RBtree<K, T, C, A>::find ( const key_type & key )
	{
		RBnode * cur = this->_root;

		if (cur == this->_nil)
			return this->_nil;
		while (cur != NULL)
		{
			if (this->_comp(key, cur->value.first))
				cur = cur->child[LEFT];
			else if (this->_comp(cur->value.first, key))
				cur = cur->child[RIGHT];
			else
				return cur;
		}
		return this->_nil;
	}

	template < class K, class T, class C, class A >
	const typename ft::RBtree<K, T, C, A>::RBnode * ft::RBtree<K, T, C, A>::find ( const key_type & key ) const
	{
		const RBnode * cur = this->_root;

		if (cur == this->_nil)
			return this->_nil;
		while (cur != NULL)
		{
			if (this->_comp(key, cur->value.first))
				cur = cur->child[LEFT];
			else if (this->_comp(cur->value.first, key))
				cur = cur->child[RIGHT];
			else
				return cur;
		}
		return this->_nil;
	}

	template < class K, class T, class C, class A >
	typename ft::RBtree<K, T, C, A>::RBnode * ft::RBtree<K, T, C, A>::lower_bound ( const key_type & key )
	{
		RBnode * cur = this->_root;
		RBnode * tmp = this->_nil;

		if (cur == this->_nil)
			return this->_nil;
		while (cur != NULL)
		{
			if (this->_comp(key, cur->value.first)) // key < cur
			{
				tmp = cur;
				cur = cur->child[LEFT];
			}
			else if (this->_comp(cur->value.first, key))
				cur = cur->child[RIGHT];
			else
				return cur;
		}
		return tmp;
	}

	template < class K, class T, class C, class A >
	const typename ft::RBtree<K, T, C, A>::RBnode * ft::RBtree<K, T, C, A>::lower_bound ( const key_type & key ) const
	{
		const RBnode * cur = this->_root;
		const RBnode * tmp = this->_nil;

		if (cur == this->_nil)
			return this->_nil;
		while (cur != NULL)
		{
			if (this->_comp(key, cur->value.first))
			{
				tmp = cur;
				cur = cur->child[LEFT];
			}
			else if (this->_comp(cur->value.first, key))
				cur = cur->child[RIGHT];
			else
				return cur;
		}
		return tmp;
	}

	template < class K, class T, class C, class A >
	typename ft::RBtree<K, T, C, A>::RBnode * ft::RBtree<K, T, C, A>::upper_bound ( const key_type & key )
	{
		RBnode * cur = this->_root;
		RBnode * tmp = this->_nil;

		if (cur == this->_nil)
			return this->_nil;
		while (cur != NULL)
		{
			if (this->_comp(key, cur->value.first))
			{
				tmp = cur;
				cur = cur->child[LEFT];
			}
			else
				cur = cur->child[RIGHT];
		}
		return tmp;
	}

	template < class K, class T, class C, class A >
	const typename ft::RBtree<K, T, C, A>::RBnode * ft::RBtree<K, T, C, A>::upper_bound ( const key_type & key ) const
	{
		const RBnode * cur = this->_root;
		const RBnode * tmp = this->_nil;

		if (cur == this->_nil)
			return this->_nil;
		while (cur != NULL)
		{
			if (this->_comp(key, cur->value.first))
			{
				tmp = cur;
				cur = cur->child[LEFT];
			}
			else
				cur = cur->child[RIGHT];
		}
		return tmp;
	}

	template < class K, class T, class C, class A >
	ft::pair<typename ft::RBtree<K, T, C, A>::RBnode *, bool> ft::RBtree<K, T, C, A>::insert ( const value_type & value )
	{
		RBnode *	cur = this->_root;

		if (cur == this->_nil)
		{
			this->_root = this->_node_alloc.allocate(1);
			this->_node_alloc.construct(this->_root, RBnode(value));
			this->_size += 1;
			this->_nil->child[LEFT] = this->_root;
			this->_nil->child[RIGHT] = this->_root;
			this->_root->parent = this->_nil;
			return ft::make_pair(this->_root, true);
		}

		while (true)
		{
			dir_t dir;
			if (this->_comp(value.first, cur->value.first))
				dir = LEFT;
			else if (this->_comp(cur->value.first, value.first))
				dir = RIGHT;
			else
				return ft::make_pair(cur, false);

			if (cur->child[dir] != NULL)
				cur = cur->child[dir];
			else
			{
				cur->child[dir] = this->_node_alloc.allocate(1);
				this->_node_alloc.construct(cur->child[dir], RBnode(value));
				cur->child[dir]->parent = cur;
				cur = cur->child[dir];
				this->_size += 1;
				break ;
			}
			// TODO: Red Black Operation
		}

		if (this->_comp(cur->value.first, this->_nil->child[RIGHT]->value.first)) // update first
			this->_nil->child[RIGHT] = cur;
		if (this->_comp(this->_nil->child[LEFT]->value.first, cur->value.first)) // update last
			this->_nil->child[LEFT] = cur;
		return ft::make_pair(cur, true);
	}

	template < class K, class T, class C, class A >
	typename ft::RBtree<K, T, C, A>::RBnode * ft::RBtree<K, T, C, A>::erase ( RBnode * target )
	{
		RBnode * following = target->next();

		if (target == this->_nil)
			return target;


		following = target->next();
		if (this->_size == 1)
		{
			this->_root = this->_nil;
			this->_nil->child[RIGHT] = this->_nil;
			this->_nil->child[LEFT] = this->_nil;
			this->_size -= 1;
			this->_node_alloc.destroy(target);
			this->_node_alloc.deallocate(target, 1);
			return this->_nil;
		}
		if (target->child[RIGHT] != NULL)
		{
			memmove(&target->value, &following->value, sizeof(value_type));
			RBnode * temp = target;
			target = following;
			following = temp;
		}
		else if (target == this->_nil->child[RIGHT]) // update first
			this->_nil->child[RIGHT] = target->next();
		if (target == this->_nil->child[LEFT]) // update last
			this->_nil->child[LEFT] = target->prev();

		// TODO: Red Black Operation

		RBnode * child = (target->child[RIGHT] != NULL ? target->child[RIGHT] : target->child[LEFT]);
		if (child != NULL)
			child->parent = target->parent;
		if (target == this->_root)
			this->_root = child;
		else if (target == target->parent->child[RIGHT])
			target->parent->child[RIGHT] = child;
		else // (target == this->parent->child[LEFT])
			target->parent->child[LEFT] = child;
		this->_node_alloc.destroy(target);
		this->_node_alloc.deallocate(target, 1);
		this->_size -= 1;
		return following;
	}

	template < class K, class T, class C, class A >
	void ft::RBtree<K, T, C, A>::clear ( void )
	{
		if (this->_size == 0)
			return ;
		this->destroy_node(this->_root);
		this->_root = this->_nil;
		this->_root->child[RIGHT] = this->_nil;
		this->_root->child[LEFT] = this->_nil;
		this->_size = 0;
	}

	template < class K, class T, class C, class A >
	void ft::RBtree<K, T, C, A>::destroy_node ( RBnode * node )
	{
		if (node->child[RIGHT] != NULL)
			this->destroy_node(node->child[RIGHT]);
		if (node->child[LEFT] != NULL)
			this->destroy_node(node->child[LEFT]);
		this->_node_alloc.destroy(node);
		this->_node_alloc.deallocate(node, 1);
	}

	template < class K, class T, class C, class A >
	void ft::RBtree<K, T, C, A>::swap ( RBtree & other )
	{
		RBnode * tmp_nil		= this->_nil;
		RBnode * tmp_root		= this->_root;
		size_t tmp_size			= this->_size;
		this->_nil				= other._nil;
		this->_root				= other._root;
		this->_size				= other._size;
		other._nil				= tmp_nil;
		other._root				= tmp_root;
		other._size				= tmp_size;
	}

} // namespace ft

#endif // FT_CONTAINERS_RB_TREE_TPP