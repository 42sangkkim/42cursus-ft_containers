#ifndef FT_CONTAINERS_RB_TREE_TPP
# define FT_CONTAINERS_RB_TREE_TPP

# include "./RBtree.hpp"

// RBtreed

// template < class T, class Compare, class Allocator >
// ft::RBtree<T, Compare, Allocator>::RBtree ( void )
// 	: _size(0), _comp(), _alloc(), _node_alloc()
// {
// 	this->_nil = this->_node_alloc.allocate(1);
// 	this->_alloc.construct(this->_nil, node());
// 	this->_nil->child[RIGHT] = this->_nil;
// 	this->_nil->child[LEFT] = this->_nil;
// 	this->_root = this->_nil;
// }

template < class T, class Compare, class Allocator >
ft::RBtree<T, Compare, Allocator>::RBtree ( const compare & comp, const allocator_type & alloc )
	: _size(0), _comp(comp), _alloc(alloc), _node_alloc()
{
	this->_nil = this->_node_alloc.allocate(1);
	this->_node_alloc.construct(this->_nil, node());
	this->_nil->child[RIGHT] = this->_nil;
	this->_nil->child[LEFT] = this->_nil;
	this->_root = this->_nil;
}

template < class T, class Compare, class Allocator >
ft::RBtree<T, Compare, Allocator>::~RBtree ( void )
{
	this->clear();
	this->_node_alloc.destroy(this->_nil);
	this->_node_alloc.deallocate(this->_nil, 1);
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
	return this->_nil->child[RIGHT];
}

template < class T, class Compare, class Allocator >
const typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::begin ( void ) const
{
	return this->_nil->child[RIGHT];
}

template < class T, class Compare, class Allocator >
typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::end ( void )
{
	return this->_nil;
}

template < class T, class Compare, class Allocator >
const typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::end ( void ) const
{
	return this->_nil;
}

template < class T, class Compare, class Allocator >
typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::find ( const value_type & value )
{
	node * cur = this->_root;

	if (cur == this->_nil)
		return this->_nil;
	while (cur != NULL)
	{
		if (this->_comp(value, cur->value))
			cur = cur->child[LEFT];
		else if (this->_comp(cur->value, value))
			cur = cur->child[RIGHT];
		else
			return cur;
	}
	return this->_nil;
}

template < class T, class Compare, class Allocator >
const typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::find ( const value_type & value ) const
{
	const node * cur = this->_root;

	if (cur == this->_nil)
		return this->_nil;
	while (cur != NULL)
	{
		if (this->_comp(value, cur->value))
			cur = cur->child[LEFT];
		else if (this->_comp(cur->value, value))
			cur = cur->child[RIGHT];
		else
			return cur;
	}
	return this->_nil;
}

template < class T, class Compare, class Allocator >
typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::lower_bound ( const value_type & value )
{
	node * cur = this->_root;
	node * tmp = this->_nil;

	if (cur == this->_nil)
		return this->_nil;
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
	const node * tmp = this->_nil;

	if (cur == this->_nil)
		return this->_nil;
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
	node * tmp = this->_nil;

	if (cur == this->_nil)
		return this->_nil;
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
	const node * tmp = this->_nil;

	if (cur == this->_nil)
		return this->_nil;
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

	if (cur == this->_nil)
	{
		this->_root = this->_node_alloc.allocate(1);
		this->_node_alloc.construct(this->_root, node(value));
		this->_size += 1;
		this->_nil->child[LEFT] = this->_root;
		this->_nil->child[RIGHT] = this->_root;
		this->_root->parent = this->_nil;
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
		// TODO: Red Black Operation
	}

	if (this->_comp(cur->value, this->_nil->child[RIGHT]->value)) // update first
		this->_nil->child[RIGHT] = cur;
	if (this->_comp(this->_nil->child[LEFT]->value, cur->value)) // update last
		this->_nil->child[LEFT] = cur;
	return ft::make_pair(cur, true);
}

template < class T, class Compare, class Allocator >
typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::erase ( node * target )
{
	node * following = target->next();

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
		node * temp = target;
		target = following;
		following = temp;
	}
	else if (target == this->_nil->child[RIGHT]) // update first
		this->_nil->child[RIGHT] = target->next();
	if (target == this->_nil->child[LEFT]) // update last
		this->_nil->child[LEFT] = target->prev();

	// TODO: Red Black Operation

	node * child = (target->child[RIGHT] != NULL ? target->child[RIGHT] : target->child[LEFT]);
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

template < class T, class Compare, class Allocator >
void ft::RBtree<T, Compare, Allocator>::clear ( void )
{
	if (this->_size == 0)
		return ;
	this->destroy_node(this->_root);
	this->_root = this->_nil;
	this->_root->child[RIGHT] = this->_nil;
	this->_root->child[LEFT] = this->_nil;
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
	node * tmp_nil		= this->_nil;
	node * tmp_root		= this->_root;
	size_t tmp_size			= this->_size;
	this->_nil				= other._nil;
	this->_root				= other._root;
	this->_size				= other._size;
	other._nil				= tmp_nil;
	other._root				= tmp_root;
	other._size				= tmp_size;
}

#endif // FT_CONTAINERS_RB_TREE_TPP