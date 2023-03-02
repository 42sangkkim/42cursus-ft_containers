#ifndef FT_CONTAINERS_RB_TREE_NODE_TPP
# define FT_CONTAINERS_RB_TREE_NODE_TPP

# include "./RBtree_node.hpp"

// node

template < class T, class Compare, class Allocator >
ft::RBtree<T, Compare, Allocator>::node::node ( void )
	: value(), parent(NULL), color(RED)
{
	child[RIGHT] = NULL;
	child[LEFT] = NULL;
}

template < class T, class Compare, class Allocator >
ft::RBtree<T, Compare, Allocator>::node::node ( const node & other )
	: value(other.value), parent(other.parent), color(other.color)
{
	child[RIGHT] = other.child[RIGHT];
	child[LEFT] = other.child[LEFT];
}

template < class T, class Compare, class Allocator >
ft::RBtree<T, Compare, Allocator>::node::node ( const value_type & value )
	: value(value), parent(NULL), color(RED)
{
	child[RIGHT] = NULL;
	child[LEFT] = NULL;
}

template < class T, class Compare, class Allocator >
ft::RBtree<T, Compare, Allocator>::node::~node ( void )
{}

template < class T, class Compare, class Allocator >
typename ft::RBtree<T, Compare, Allocator>::node & ft::RBtree<T, Compare, Allocator>::node::operator = ( const node & other )
{
	this->value = other.value;
	this->parent = other.parent;
	this->child[RIGHT] = other.child[RIGHT];
	this->child[LEFT] = other.child[LEFT];
	this->_color = other.color;
}

template < class T, class Compare, class Allocator >
typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::node::prev ( void )
{
	node * cur;
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

template < class T, class Compare, class Allocator >
const typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::node::prev ( void ) const
{
	const node * cur;
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

template < class T, class Compare, class Allocator >
typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::node::next ( void )
{
	node * cur;

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

template < class T, class Compare, class Allocator >
const typename ft::RBtree<T, Compare, Allocator>::node * ft::RBtree<T, Compare, Allocator>::node::next ( void ) const
{
	const node * cur;
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

#endif // FT_CONTAINERS_RB_TREE_NODE_TPP