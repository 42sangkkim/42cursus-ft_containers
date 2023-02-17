#ifndef FT_CONTAINERS_TREE_TPP
# define FT_CONTAINERS_TREE_TPP

# include "./Tree.hpp"

namespace ft
{
	// Node

	template < class K, class T, class C, class A >
	ft::Tree<K, T, C, A>::Node::Node ( void )
		: _value(value_type()), _parent(NULL)
	{
		this->_child[LEFT] = NULL;
		this->_child[RIGHT] = NULL;
	}

	template < class K, class T, class C, class A >
	ft::Tree<K, T, C, A>::Node::Node ( const Node & other )
		: _value(other._value), _parent(other._parent)
	{
		this->_child[LEFT] = other._child[LEFT];
		this->_child[RIGHT] = other._child[RIGHT];
	}

	template < class K, class T, class C, class A >
	ft::Tree<K, T, C, A>::Node::Node ( const_reference value )
		: _value(value), _parent(NULL)
	{
		this->_child[LEFT] = NULL;
		this->_child[RIGHT] = NULL;
	}

	template < class K, class T, class C, class A >
	ft::Tree<K, T, C, A>::Node::~Node ( void )
	{}

	template < class K, class T, class C, class A >
	typename ft::Tree<K, T, C, A>::Node & ft::Tree<K, T, C, A>::Node::operator = ( const Node & other )
	{
		this->_value = other._value;
		this->_parent = other._parent;
		this->_child[LEFT] = other._child[LEFT];
		this->_child[RIGHT] = other._child[RIGHT];
		return *this;
	}

	template < class K, class T, class C, class A >
	typename ft::Tree<K, T, C, A>::Node * ft::Tree<K, T, C, A>::Node::prev ( void )
	{
		Node * cur = this;

		if (cur->_child[LEFT] != NULL)
		{
			cur = cur->_child[LEFT];
			while (cur->_child[RIGHT] != NULL)
				cur = cur->_child[RIGHT];
			return cur;
		}
		else
		{
			while (cur->_parent != NULL)
			{
				if (cur != cur->_parent->_child[LEFT])
					return cur->_parent;
				cur = cur->_parent;
			}
			return cur;
		}
	}

	template < class K, class T, class C, class A >
	const typename ft::Tree<K, T, C, A>::Node * ft::Tree<K, T, C, A>::Node::prev ( void ) const
	{
		const Node * cur = this;

		if (cur->_child[LEFT] != NULL)
		{
			cur = cur->_child[LEFT];
			while (cur->_child[RIGHT] != NULL)
				cur = cur->_child[RIGHT];
			return cur;
		}
		else
		{
			while (cur->_parent != NULL)
			{
				if (cur != cur->_parent->_child[LEFT])
					return cur->_parent;
				cur = cur->_parent;
			}
			return cur;
		}
	}

	template < class K, class T, class C, class A >
	typename ft::Tree<K, T, C, A>::Node * ft::Tree<K, T, C, A>::Node::next ( void )
	{
		Node * cur = this;

		if (cur->_child[RIGHT] != NULL)
		{
			cur = cur->_child[RIGHT];
			while (cur->_child[LEFT] != NULL)
				cur = cur->_child[LEFT];
			return cur;
		}
		else
		{
			while (cur->_parent != NULL)
			{
				if (cur != cur->_parent->_child[RIGHT])
					return cur->_parent;
				cur = cur->_parent;
			}
			return cur;
		}
	}

	template < class K, class T, class C, class A >
	const typename ft::Tree<K, T, C, A>::Node * ft::Tree<K, T, C, A>::Node::next ( void ) const
	{
		const Node * cur = this;

		if (cur->_child[RIGHT] != NULL)
		{
			cur = cur->_child[RIGHT];
			while (cur->_child[LEFT] != NULL)
				cur = cur->_child[LEFT];
			return cur;
		}
		else
		{
			while (cur->_parent != NULL)
			{
				if (cur != cur->_parent->_child[RIGHT])
					return cur->_parent;
				cur = cur->_parent;
			}
			return cur;
		}
	}

	// Tree

	template < class K, class T, class C, class A >
	ft::Tree<K, T, C, A>::Tree ( void )
		: __NIL_NODE__(), _nil(&this->__NIL_NODE__), _root(&this->__NIL_NODE__), _size(0), _comp(key_compare()), _alloc()
	{
		this->__NIL_NODE__._child[LEFT] = this->_nil;
		this->__NIL_NODE__._child[RIGHT] = this->_nil;
	}

	template < class K, class T, class C, class A >
	ft::Tree<K, T, C, A>::~Tree ( void )
	{
		this->clear();
	}

	template < class K, class T, class C, class A >
	typename ft::Tree<K, T, C, A>::Node * ft::Tree<K, T, C, A>::find ( const key_type & key )
	{
		if (this->_size == 0)
			return this->_nil;

		Node * cur = this->_root;
		while (cur != NULL)
		{
			if (this->_comp(cur->_value.first, key))
				cur = cur->_child[RIGHT];
			else if (this->_comp(key, cur->_value.first))
				cur = cur->_child[LEFT];
			else
				return cur;
		}
		return this->_nil;
	}

	template < class K, class T, class C, class A >
	const typename ft::Tree<K, T, C, A>::Node * ft::Tree<K, T, C, A>::find ( const key_type & key ) const
	{
		if (this->_size == 0)
			return this->_nil;

		const Node * cur = this->_root;
		while (cur != NULL)
		{
			if (this->_comp(cur->_value.first, key))
				cur = cur->_child[RIGHT];
			else if (this->_comp(key, cur->_value.first))
				cur = cur->_child[LEFT];
			else
				return cur;
		}
		return this->_nil;
	}

	template < class K, class T, class C, class A >
	typename ft::Tree<K, T, C, A>::Node * ft::Tree<K, T, C, A>::insert ( const_reference value )
	{
		Node * node;

		if (this->_size == 0)
		{
			node = this->_alloc.allocate(1);
			*node = Node(value);
			node->_parent = this->_nil;
			this->_root = node;
			this->_nil->_child[LEFT] = node;
			this->_nil->_child[RIGHT] = node;
			this->_size++;
			return node;
		}

		Node * parent = this->_root;
		dir_t dir;
		while (1)
		{
			if (this->_comp(parent->_value.first, value.first))
				dir = RIGHT;
			else if (this->_comp(value.first, parent->_value.first))
				dir = LEFT;
			else
				return this->_nil;
			if (parent->_child[dir] == NULL)
				break ;
			parent = parent->_child[dir];
		}
		node = this->_alloc.allocate(1);
		*node = Node(value);
		parent->_child[dir] = node;
		node->_parent = parent;
		if (this->_comp(value.first, this->_nil->_child[RIGHT]->_value.first))
			this->_nil->_child[RIGHT] = node;
		if (this->_comp(this->_nil->_child[LEFT]->_value.first, value.first))
			this->_nil->_child[LEFT] = node;
		this->_size++;
		return node;
	}

	template < class K, class T, class C, class A >
	typename ft::Tree<K, T, C, A>::Node * ft::Tree<K, T, C, A>::erase ( Node * target )
	{
		if (this->_size == 1)
		{
			this->_nil->_child[LEFT] = this->_nil;
			this->_nil->_child[RIGHT] = this->_nil;
			this->_root = this->_nil;
			this->_size--;
			target->~Node();
			this->_alloc.deallocate(target, 1);
		}
		else if (target == this->_nil->_child[LEFT]) // is the last
			this->_nil->_child[LEFT] = target->prev();
		else if (target == this->_nil->_child[RIGHT]) // is the first
			this->_nil->_child[LEFT] = target->next();

		if (target->_child[RIGHT] != NULL)
		{
			Node * following = target->_child[RIGHT];
			while (following->_child[LEFT] != NULL)
				following = following->_child[LEFT];
			memmove(&target->_value, &following->_value, sizeof(value_type));
			Node * temp = target;
			target = following;
			following = temp;
			if (target == target->_parent->_child[LEFT])
				target->_parent->_child[LEFT] = target->_child[RIGHT];
			else
				target->_parent->_child[RIGHT] = target->_child[RIGHT];
				this->_size--;
			target->~Node();
			this->_alloc.deallocate(target, 1);
			return following;
		}
		else // No bigger child
		{
			Node * following = target->next();
			if (target->_parent == this->_nil) // is root
			{
				target->_child[LEFT]->_parent = this->_nil;
				this->_root = target->_child[LEFT];
			}
			else if (target == target->_parent->_child[LEFT])
				target->_parent->_child[LEFT] = target->_child[LEFT];
			else
				target->_parent->_child[RIGHT] = target->_child[LEFT];
			target->~Node();
			this->_alloc.deallocate(target, 1);
			return following;
		}
	}

	template < class K, class T, class C, class A >
	void ft::Tree<K, T, C, A>::clear ( void )
	{
		if (this->_size == 0)
			return ;
		this->destroy(this->_root);
		this->_size = 0;
		this->_root = this->_nil;
		this->_nil->_child[LEFT] = this->_nil;
		this->_nil->_child[RIGHT] = this->_nil;
	}

	template < class K, class T, class C, class A >
	typename ft::Tree<K, T, C, A>::Node * ft::Tree<K, T, C, A>::begin ( void )
	{
		return this->_nil->_child[RIGHT];
	}

	template < class K, class T, class C, class A >
	const typename ft::Tree<K, T, C, A>::Node * ft::Tree<K, T, C, A>::begin ( void ) const
	{
		return this->_nil->_child[RIGHT];
	}

	template < class K, class T, class C, class A >
	typename ft::Tree<K, T, C, A>::Node * ft::Tree<K, T, C, A>::end ( void )
	{
		return this->_nil->_child[LEFT];
	}

	template < class K, class T, class C, class A >
	const typename ft::Tree<K, T, C, A>::Node * ft::Tree<K, T, C, A>::end ( void ) const
	{
		return this->_nil->_child[LEFT];
	}

	template < class K, class T, class C, class A >
	typename ft::Tree<K, T, C, A>::Node * ft::Tree<K, T, C, A>::lower_bound ( const key_type & key )
	{
		if (this->_size == 0)
			return this->_nil;
		Node * cur = this-> _root;
		Node * temp = cur;
		while (cur != NULL)
		{
			if (this->_comp(cur->_value.first, key))
				cur = cur->_child[RIGHT];
			else if (this->_comp(key, cur->_value.first))
			{
				temp = cur;
				cur = cur->_child[LEFT];
			}
			else
				return cur;
		}
		return temp;
	}

	template < class K, class T, class C, class A >
	const typename ft::Tree<K, T, C, A>::Node * ft::Tree<K, T, C, A>::lower_bound ( const key_type & key ) const
	{
		if (this->_size == 0)
			return this->_nil;
		Node * cur = this-> _root;
		Node * temp = cur;
		while (cur != NULL)
		{
			if (this->_comp(cur->_value.first, key))
				cur = cur->_child[RIGHT];
			else if (this->_comp(key, cur->_value.first))
			{
				temp = cur;
				cur = cur->_child[LEFT];
			}
			else
				return cur;
		}
		return temp;
	}

	template < class K, class T, class C, class A >
	typename ft::Tree<K, T, C, A>::Node * ft::Tree<K, T, C, A>::upper_bound ( const key_type & key )
	{
		if (this->_size == 0)
			return this->_nil;
		Node * cur = this-> _root;
		Node * temp = cur;
		while (cur != NULL)
		{
			if (this->_comp(cur->_value.first, key))
				cur = cur->_child[RIGHT];
			else if (this->_comp(key, cur->value.first))
			{
				temp = cur;
				cur = cur->_child[LEFT];
			}
			else
				return cur;
		}
		return temp;
	}

	template < class K, class T, class C, class A >
	const typename ft::Tree<K, T, C, A>::Node * ft::Tree<K, T, C, A>::upper_bound ( const key_type & key ) const
	{
		if (this->_size == 0)
			return this->_nil;
		Node * cur = this-> _root;
		Node * temp = cur;
		while (cur != NULL)
		{
			if (this->_comp(cur->_value.first, key))
				cur = cur->_child[RIGHT];
			else if (this->_comp(key, cur->value.first))
			{
				temp = cur;
				cur = cur->_child[LEFT];
			}
			else
				return cur;
		}
		return temp;
	}

	template < class K, class T, class C, class A >
	void ft::Tree<K, T, C, A>::destroy ( Node * target )
	{
		if (target->_child[LEFT] != NULL)
			this->destroy(target->_child[LEFT]);
		if (target->_child[RIGHT] != NULL)
			this->destroy(target->_child[RIGHT]);
		target->~Node();
		this->_alloc.deallocate(target, 1);
	}

} // namespace ft

#endif // FT_CONTAINERS_TREE_TPP
