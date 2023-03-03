#ifndef FT_CONTAINERS_RB_TREE_TPP
# define FT_CONTAINERS_RB_TREE_TPP

# include "./RBtree.hpp"

template < class T, class Compare, class Allocator >
ft::RBtree<T, Compare, Allocator>::RBtree ( const compare & comp, const allocator_type & alloc )
	: _size(0), _comp(comp), _alloc(alloc), _node_alloc()
{
	this->_head = this->_node_alloc.allocate(1);
	this->_node_alloc.construct(this->_head, node());
	this->_head->child[RIGHT] = this->_head;
	this->_head->child[LEFT] = this->_head;
	this->_root = this->_head;
}

template < class T, class Compare, class Allocator >
ft::RBtree<T, Compare, Allocator>::~RBtree ( void )
{
	this->clear();
	this->_node_alloc.destroy(this->_head);
	this->_node_alloc.deallocate(this->_head, 1);
}

template < class T, class Compare, class Allocator >
size_t ft::RBtree<T, Compare, Allocator>::size ( void ) const
{
	return this->_size;
}

template < class T, class Compare, class Allocator >
size_t ft::RBtree<T, Compare, Allocator>::max_size ( void ) const
{
	return (std::numeric_limits<size_t>::max() / sizeof(node));
}

template < class T, class Compare, class Allocator >
typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::begin ( void )
{
	return this->_head->child[RIGHT];
}

template < class T, class Compare, class Allocator >
const typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::begin ( void ) const
{
	return this->_head->child[RIGHT];
}

template < class T, class Compare, class Allocator >
typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::end ( void )
{
	return this->_head;
}

template < class T, class Compare, class Allocator >
const typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::end ( void ) const
{
	return this->_head;
}

template < class T, class Compare, class Allocator >
typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::find ( const value_type & value )
{
	node * cur = this->_root;

	if (cur == this->_head)
		return this->_head;
	while (cur != NULL)
	{
		if (this->_comp(value, cur->value))
			cur = cur->child[LEFT];
		else if (this->_comp(cur->value, value))
			cur = cur->child[RIGHT];
		else
			return cur;
	}
	return this->_head;
}

template < class T, class Compare, class Allocator >
const typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::find ( const value_type & value ) const
{
	const node * cur = this->_root;

	if (cur == this->_head)
		return this->_head;
	while (cur != NULL)
	{
		if (this->_comp(value, cur->value))
			cur = cur->child[LEFT];
		else if (this->_comp(cur->value, value))
			cur = cur->child[RIGHT];
		else
			return cur;
	}
	return this->_head;
}

template < class T, class Compare, class Allocator >
typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::lower_bound ( const value_type & value )
{
	node * cur = this->_root;
	node * tmp = this->_head;

	if (cur == this->_head)
		return this->_head;
	while (cur != NULL)
	{
		if (this->_comp(value, cur->value)) // value < cur
		{
			tmp = cur;
			cur = cur->child[LEFT];
		}
		else if (this->_comp(cur->value, value))
			cur = cur->child[RIGHT];
		else
			return cur;
	}
	return tmp;
}

template < class T, class Compare, class Allocator >
const typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::lower_bound ( const value_type & value ) const
{
	const node * cur = this->_root;
	const node * tmp = this->_head;

	if (cur == this->_head)
		return this->_head;
	while (cur != NULL)
	{
		if (this->_comp(value, cur->value))
		{
			tmp = cur;
			cur = cur->child[LEFT];
		}
		else if (this->_comp(cur->value, value))
			cur = cur->child[RIGHT];
		else
			return cur;
	}
	return tmp;
}

template < class T, class Compare, class Allocator >
typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::upper_bound ( const value_type & value )
{
	node * cur = this->_root;
	node * tmp = this->_head;

	if (cur == this->_head)
		return this->_head;
	while (cur != NULL)
	{
		if (this->_comp(value, cur->value))
		{
			tmp = cur;
			cur = cur->child[LEFT];
		}
		else
			cur = cur->child[RIGHT];
	}
	return tmp;
}

template < class T, class Compare, class Allocator >
const typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::upper_bound ( const value_type & value ) const
{
	const node * cur = this->_root;
	const node * tmp = this->_head;

	if (cur == this->_head)
		return this->_head;
	while (cur != NULL)
	{
		if (this->_comp(value, cur->value))
		{
			tmp = cur;
			cur = cur->child[LEFT];
		}
		else
			cur = cur->child[RIGHT];
	}
	return tmp;
}

template < class T, class Compare, class Allocator >
ft::pair<typename ft::RBtree<T, Compare, Allocator>::node *, bool> ft::RBtree<T, Compare, Allocator>::insert ( const value_type & value )
{
	node *	cur = this->_root;

	if (cur == this->_head) // size == 0
	{
		this->_root = this->_node_alloc.allocate(1);
		this->_node_alloc.construct(this->_root, node(value));
		this->_size += 1;
		this->_head->child[LEFT] = this->_root;
		this->_head->child[RIGHT] = this->_root;
		this->_root->parent = this->_head;
		this->_root->color = BLACK;
		return ft::make_pair(this->_root, true);
	}

	while (true)
	{
		dir_t dir;
		if (this->_comp(value, cur->value))
			dir = LEFT;
		else if (this->_comp(cur->value, value))
			dir = RIGHT;
		else
			return ft::make_pair(cur, false);

		if (cur->child[dir] != NULL)
			cur = cur->child[dir];
		else
		{
			cur->child[dir] = this->_node_alloc.allocate(1);
			this->_node_alloc.construct(cur->child[dir], node(value));
			cur->child[dir]->parent = cur;
			cur = cur->child[dir];
			this->_size += 1;
			break ;
		}
	}

	if (this->_comp(cur->value, this->_head->child[RIGHT]->value)) // update first
		this->_head->child[RIGHT] = cur;
	if (this->_comp(this->_head->child[LEFT]->value, cur->value)) // update last
		this->_head->child[LEFT] = cur;
	check_double_red(cur);
	return ft::make_pair(cur, true);
}

template < class T, class Compare, class Allocator >
typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::erase ( node * target )
{
	node * following = target->next();

	if (target == this->_head)
		return this->_head;

	following = target->next();
	if (target == this->_head->child[RIGHT]) // update first
		this->_head->child[RIGHT] = following;
	if (target == this->_head->child[LEFT]) // update last
		this->_head->child[LEFT] = target->prev();

	if (target->child[RIGHT] != NULL)
	{
		memmove(&target->value, &following->value, sizeof(value_type));
		node * temp = target;
		target = following;
		following = temp;
		if (target == this->_head->child[RIGHT]) // update first
			this->_head->child[RIGHT] = following;
	}

	node * parent = target->parent;
	node * child = (target->child[LEFT] == NULL ? target->child[RIGHT] : target->child[LEFT]);
	if (this->_size == 1)
		this->_root = this->_head;
	else if (target == this->_root)
	{
		this->_root = child;
		child->parent = parent;
		child->color = BLACK;
	}
	else
	{
		// link parent - child
		if (target == parent->child[LEFT])
			parent->child[LEFT] = child;
		else // (target == parent->child[RIGHT])
			parent->child[RIGHT] = child;
		if (child != NULL)
			child->parent = parent;

		if (target->color == BLACK)
			extra_black(child, parent);
	}
	this->_node_alloc.destroy(target);
	this->_node_alloc.deallocate(target, 1);
	this->_size -= 1;
	return following;
}

template < class T, class Compare, class Allocator >
void ft::RBtree<T, Compare, Allocator>::clear ( void )
{
	if (this->_size == 0)
		return ;
	this->destroy_node(this->_root);
	this->_root = this->_head;
	this->_root->child[RIGHT] = this->_head;
	this->_root->child[LEFT] = this->_head;
	this->_size = 0;
}

template < class T, class Compare, class Allocator >
void ft::RBtree<T, Compare, Allocator>::destroy_node ( node * node )
{
	if (node->child[RIGHT] != NULL)
		this->destroy_node(node->child[RIGHT]);
	if (node->child[LEFT] != NULL)
		this->destroy_node(node->child[LEFT]);
	this->_node_alloc.destroy(node);
	this->_node_alloc.deallocate(node, 1);
}

template < class T, class Compare, class Allocator >
void ft::RBtree<T, Compare, Allocator>::swap ( RBtree & other )
{
	node * tmp_head		= this->_head;
	node * tmp_root		= this->_root;
	size_t tmp_size			= this->_size;
	this->_head				= other._head;
	this->_root				= other._root;
	this->_size				= other._size;
	other._head				= tmp_head;
	other._root				= tmp_root;
	other._size				= tmp_size;
}

template < class T, class Compare, class Allocator >
void ft::RBtree<T, Compare, Allocator>::rotate ( node * target, dir_t dir)
{
	node * child = target->child[(dir == LEFT ? RIGHT : LEFT)];
	node * parent = target->parent;

	// link [target - child.child]
	target->child[(dir == LEFT ? RIGHT : LEFT)] = child->child[dir];
	if (child->child[dir] != NULL)
		child->child[dir]->parent = target;

	// link [child - target]
	child->child[dir] = target;
	target->parent = child;

	// link [parent - child]
	child->parent = parent;
	if (target == this->_root)
		this->_root = child;
	else if (target == parent->child[LEFT])
		parent->child[LEFT] = child;
	else // (target == parent->child[RIGHT])
		parent->child[RIGHT] = child;
}

template < class T, class Compare, class Allocator >
void ft::RBtree<T, Compare, Allocator>::check_double_red ( node * target )
{
	while (true)
	{
		if (target->parent->color == BLACK)
			return ;
		node * parent = target->parent;
		node * grand = parent->parent;
		node * uncle = (parent == grand->child[RIGHT] ? grand->child[LEFT] : grand->child[RIGHT]);

		if (uncle == NULL || uncle->color == BLACK)
		{
			dir_t dir = (parent == grand->child[LEFT] ? LEFT : RIGHT); 
			if (target != parent->child[dir])
				rotate(parent, dir);
			grand->child[dir]->color = BLACK;
			rotate(grand, (dir == LEFT ? RIGHT : LEFT));
			grand->color = RED;
			return ;
		}
		else // uncle->color == RED
		{
			parent->color = BLACK;
			uncle->color = BLACK;
			if (grand == this->_root)
				return ;
			grand->color = RED;
			if (grand->parent->color == BLACK)
				return;
			target = grand;
		}
	}
}

template < class T, class Compare, class Allocator >
void ft::RBtree<T, Compare, Allocator>::extra_black ( node * target, node * parent )
{
	while (true)
	{
		if (target == this->_root)
			return ;

		// red and black
		if (target != NULL && target->color == RED)
		{
			target->color = BLACK;
			return ;
		}

		// doubly black
		dir_t dir = (parent->child[LEFT] == target ? LEFT : RIGHT);
		dir_t revDir = (dir == LEFT ? RIGHT : LEFT);
		node * sibling = parent->child[revDir];
		node * close   = sibling->child[dir];
		node * distant = sibling->child[revDir];

		int doubly_black_case;
		if (distant != NULL && distant->color == RED)
			doubly_black_case = 4;
		else if (close != NULL && close->color == RED)
			doubly_black_case = 3;
		else if (sibling->color == BLACK)
			doubly_black_case = 2;
		else // (sibling->color == RED)
			doubly_black_case = 1;

		switch (doubly_black_case)
		{
			case 1:
				rotate(parent, dir);
				parent->color = RED;
				sibling->color = BLACK;
				break ;
			case 2:
				sibling->color = RED;
				target = parent;
				parent = target->parent;
				break ;
			case 3:
				rotate(sibling, revDir);
				close->color = BLACK;
				sibling->color = RED;
				distant = sibling;
				sibling = close;
				close = sibling->child[dir];
				// continue to case 4
			case 4:
				rotate(parent, dir);
				sibling->color = parent->color;
				parent->color = BLACK;
				distant->color = BLACK;
				return ;
		}
	}
}

#endif // FT_CONTAINERS_RB_TREE_TPP