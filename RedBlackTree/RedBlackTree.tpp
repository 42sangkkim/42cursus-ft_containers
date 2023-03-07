#ifndef FT_CONTAINERS_RED_BLACK_TREE_TPP
# define FT_CONTAINERS_RED_BLACK_TREE_TPP

# include "./RedBlackTree.hpp"

template < class T, class Compare, class Allocator >
ft::RedBlackTree<T, Compare, Allocator>::RedBlackTree ( const compare & comp, const allocator_type & alloc )
	: _size(0), _comp(comp), _alloc(alloc), _node_alloc()
{
	this->_head = this->_node_alloc.allocate(1);
	this->_node_alloc.construct(this->_head, node_type());
	this->_head->child[RIGHT] = this->_head;
	this->_head->child[LEFT] = this->_head;
	this->_root = this->_head;
}

template < class T, class Compare, class Allocator >
ft::RedBlackTree<T, Compare, Allocator>::~RedBlackTree ( void )
{
	this->clear();
	this->_node_alloc.destroy(this->_head);
	this->_node_alloc.deallocate(this->_head, 1);
}

template < class T, class Compare, class Allocator >
size_t ft::RedBlackTree<T, Compare, Allocator>::size ( void ) const
{
	return this->_size;
}

template < class T, class Compare, class Allocator >
size_t ft::RedBlackTree<T, Compare, Allocator>::max_size ( void ) const
{
	return (std::numeric_limits<size_t>::max() / sizeof(node_type));
}

template < class T, class Compare, class Allocator >
 typename ft::RedBlackNode<T> * ft::RedBlackTree<T, Compare, Allocator>::begin ( void )
{
	return this->_head->child[RIGHT];
}

template < class T, class Compare, class Allocator >
const typename ft::RedBlackNode<T> * ft::RedBlackTree<T, Compare, Allocator>::begin ( void ) const
{
	return this->_head->child[RIGHT];
}

template < class T, class Compare, class Allocator >
typename ft::RedBlackNode<T> * ft::RedBlackTree<T, Compare, Allocator>::end ( void )
{
	return this->_head;
}

template < class T, class Compare, class Allocator >
const typename ft::RedBlackNode<T> * ft::RedBlackTree<T, Compare, Allocator>::end ( void ) const
{
	return this->_head;
}

template < class T, class Compare, class Allocator >
typename ft::RedBlackNode<T> * ft::RedBlackTree<T, Compare, Allocator>::find ( const value_type & value )
{
	node_type * cur = this->_root;

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
const typename ft::RedBlackNode<T> * ft::RedBlackTree<T, Compare, Allocator>::find ( const value_type & value ) const
{
	const node_type * cur = this->_root;

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
typename ft::RedBlackNode<T> * ft::RedBlackTree<T, Compare, Allocator>::lower_bound ( const value_type & value )
{
	node_type * cur = this->_root;
	node_type * tmp = this->_head;

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
const typename ft::RedBlackNode<T> * ft::RedBlackTree<T, Compare, Allocator>::lower_bound ( const value_type & value ) const
{
	const node_type * cur = this->_root;
	const node_type * tmp = this->_head;

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
typename ft::RedBlackNode<T> * ft::RedBlackTree<T, Compare, Allocator>::upper_bound ( const value_type & value )
{
	node_type * cur = this->_root;
	node_type * tmp = this->_head;

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
const typename ft::RedBlackNode<T> * ft::RedBlackTree<T, Compare, Allocator>::upper_bound ( const value_type & value ) const
{
	const node_type * cur = this->_root;
	const node_type * tmp = this->_head;

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
ft::pair<typename ft::RedBlackNode<T> *, bool> ft::RedBlackTree<T, Compare, Allocator>::insert ( const value_type & value )
{
	node_type *	cur = this->_root;

	if (cur == this->_head) // size == 0
	{
		this->_root = this->_node_alloc.allocate(1);
		this->_node_alloc.construct(this->_root, node_type(value));
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
			this->_node_alloc.construct(cur->child[dir], node_type(value));
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
typename ft::RedBlackNode<T> * ft::RedBlackTree<T, Compare, Allocator>::erase ( node_type * target )
{
	node_type * following = target->next();

	if (target == this->_head)
		return this->_head;

	following = target->next();
	if (target == this->_head->child[RIGHT]) // update first
		this->_head->child[RIGHT] = following;
	if (target == this->_head->child[LEFT]) // update last
		this->_head->child[LEFT] = target->prev();

	if (target->child[RIGHT] != NULL) // following->child[LEFT] = NULL
	{
		node_type * temp_node[3];
		color_t temp_color = target->color;
		temp_node[0] = target->parent;
		temp_node[1] = target->child[LEFT];
		temp_node[2] = target->child[RIGHT];
		target->color = following->color;
		target->parent = following->parent;
		target->child[LEFT] = NULL;					// following->child[LEFT]
		target->child[RIGHT] = following->child[RIGHT];

		following->color = temp_color;				// target->color
		following->parent = temp_node[0];			// target->parent
		following->child[LEFT] = temp_node[1];		// target->child[LEFT]
		following->child[RIGHT] = temp_node[2];		// target->child[RIGHT]

		if (target->child[RIGHT] != NULL)
			target->child[RIGHT]->parent = target;
		if (following->parent == this->_head)
			this->_root = following;
		else if (following->parent->child[LEFT] == target)
			following->parent->child[LEFT] = following;
		else // (following->parent->child[RIGHT] == target)
			following->parent->child[RIGHT] = following;
		if (following->child[LEFT] != NULL)
			following->child[LEFT]->parent = following;

		if (target->parent == target)
		{
			following->child[RIGHT] = target;
			target->parent = following;
		}
		else
		{
			following->child[RIGHT]->parent = following;
			target->parent->child[LEFT] = target;
		}
	}

	node_type * parent = target->parent;
	node_type * child = (target->child[LEFT] == NULL ? target->child[RIGHT] : target->child[LEFT]);
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
void ft::RedBlackTree<T, Compare, Allocator>::clear ( void )
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
void ft::RedBlackTree<T, Compare, Allocator>::destroy_node ( node_type * node )
{
	if (node->child[RIGHT] != NULL)
		this->destroy_node(node->child[RIGHT]);
	if (node->child[LEFT] != NULL)
		this->destroy_node(node->child[LEFT]);
	this->_node_alloc.destroy(node);
	this->_node_alloc.deallocate(node, 1);
}

template < class T, class Compare, class Allocator >
void ft::RedBlackTree<T, Compare, Allocator>::swap ( RedBlackTree & other )
{
	node_type * tmp_head		= this->_head;
	node_type * tmp_root		= this->_root;
	size_t tmp_size			= this->_size;
	this->_head				= other._head;
	this->_root				= other._root;
	this->_size				= other._size;
	other._head				= tmp_head;
	other._root				= tmp_root;
	other._size				= tmp_size;
}

template < class T, class Compare, class Allocator >
void ft::RedBlackTree<T, Compare, Allocator>::rotate ( node_type * target, dir_t dir)
{
	node_type * child = target->child[(dir == LEFT ? RIGHT : LEFT)];
	node_type * parent = target->parent;

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
void ft::RedBlackTree<T, Compare, Allocator>::check_double_red ( node_type * target )
{
	while (true)
	{
		if (target->parent->color == BLACK)
			return ;
		node_type * parent = target->parent;
		node_type * grand = parent->parent;
		node_type * uncle = (parent == grand->child[RIGHT] ? grand->child[LEFT] : grand->child[RIGHT]);

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
void ft::RedBlackTree<T, Compare, Allocator>::extra_black ( node_type * target, node_type * parent )
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
		node_type * sibling = parent->child[revDir];
		node_type * close   = sibling->child[dir];
		node_type * distant = sibling->child[revDir];

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

#endif // FT_CONTAINERS_RED_BLACK_TREE_TPP