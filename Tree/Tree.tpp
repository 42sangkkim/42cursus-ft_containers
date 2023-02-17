#ifndef FT_CONTAINERS_TREE_TPP
# define FT_CONTAINERS_TREE_TPP

# include "./Tree.hpp"

namespace ft
{
	// Node

	ft::Tree::Node::Node ( int value )
		: _value(value), _parent(NULL)
	{
		this->_child[LEFT] = NULL;
		this->_child[RIGHT] = NULL;
	}

	ft::Tree::Node::~Node ( void )
	{}

	ft::Tree::Node * ft::Tree::Node::prev ( void )
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

	const ft::Tree::Node * ft::Tree::Node::prev ( void ) const
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

	ft::Tree::Node * ft::Tree::Node::next ( void )
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

	const ft::Tree::Node * ft::Tree::Node::next ( void ) const
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

	ft::Tree::Tree ( void )
		: __NIL_NODE__(0), _nil(&this->__NIL_NODE__), _root(&this->__NIL_NODE__), _size(0)
	{
		this->__NIL_NODE__._child[LEFT] = this->_nil;
		this->__NIL_NODE__._child[RIGHT] = this->_nil;
	}

	ft::Tree::~Tree ( void )
	{
		this->clear();
	}

	ft::Tree::Node * ft::Tree::find ( int value )
	{
		Node * cur = this->_root;

		while (cur != this->_nil)
		{
			if (cur->_value < value)
				cur = cur->_child[RIGHT];
			else if (value < cur->_value)
				cur = cur->_child[LEFT];
			else
				return cur;
		}
		return this->_nil;
	}

	const ft::Tree::Node * ft::Tree::find ( int value ) const
	{
		const Node * cur = this->_root;

		while (cur != NULL)
		{
			if (cur->_value < value)
				cur = cur->_child[RIGHT];
			else if (value < cur->_value)
				cur = cur->_child[LEFT];
			else
				return cur;
		}
		return this->_nil;
	}

	ft::Tree::Node * ft::Tree::insert ( int value )
	{
		Node * node;

		if (this->_size == 0)
		{
			node = new Node(value);
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
			if (parent->_value < value)
				dir = RIGHT;
			else if (value < parent->_value)
				dir = LEFT;
			else
				return this->_nil;
			if (parent->_child[dir] == NULL)
				break ;
			parent = parent->_child[dir];
		}
		node = new Node (value);
		parent->_child[dir] = node;
		node->_parent = parent;
		if (value < this->_nil->_child[RIGHT]->_value)
			this->_nil->_child[RIGHT] = node;
		if (this->_nil->_child[LEFT]->_value < value)
			this->_nil->_child[LEFT] = node;
		this->_size++;
		return node;
	}

	ft::Tree::Node * ft::Tree::erase ( Node * target )
	{
		if (this->_size == 1)
		{
			this->_nil->_child[LEFT] = this->_nil;
			this->_nil->_child[RIGHT] = this->_nil;
			this->_root = this->_nil;
			this->_size--;
			delete target;
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
			target->_value = following->_value; // TODO : memmove
			Node * temp = target;
			target = following;
			following = temp;
			if (target == target->_parent->_child[LEFT])
				target->_parent->_child[LEFT] = target->_child[RIGHT];
			else
				target->_parent->_child[RIGHT] = target->_child[RIGHT];
				this->_size--;
			delete target;
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
			delete target;
			return following;
		}
	}

	void ft::Tree::clear ( void )
	{
		if (this->_size == 0)
			return ;
		this->destroy(this->_root);
		this->_size = 0;
		this->_root = this->_nil;
		this->_nil->_child[LEFT] = this->_nil;
		this->_nil->_child[RIGHT] = this->_nil;
	}

	ft::Tree::Node * ft::Tree::lower_bound ( int value )
	{
		if (this->_size == 0)
			return this->_nil;
		Node * cur = this-> _root;
		Node * temp = cur;
		while (cur != NULL)
		{
			if (cur->_value < value)
				cur = cur->_child[RIGHT];
			else if (value < cur->_value)
			{
				temp = cur;
				cur = cur->_child[LEFT];
			}
			else
				return cur;
		}
		return temp;
	}

	ft::Tree::Node * ft::Tree::upper_bound ( int value )
	{
		if (this->_size == 0)
			return this->_nil;
		Node * cur = this-> _root;
		Node * temp = cur;
		while (cur != NULL)
		{
			if (cur->_value < value)
				cur = cur->_child[RIGHT];
			else if (value < cur->_value)
			{
				temp = cur;
				cur = cur->_child[LEFT];
			}
			else
				return cur;
		}
		return temp;
	}

	void ft::Tree::destroy ( Node * target )
	{
		if (target->_child[LEFT] != NULL)
			this->destroy(target->_child[LEFT]);
		if (target->_child[RIGHT] != NULL)
			this->destroy(target->_child[RIGHT]);
		delete target;
	}

} // namespace ft

#endif // FT_CONTAINERS_TREE_TPP
