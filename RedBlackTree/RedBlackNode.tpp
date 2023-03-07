#ifndef FT_CONTAINERS_RED_BLACK_NODE_TPP
# define FT_CONTAINERS_RED_BLACK_NODE_TPP

# include "./RedBlackNode.hpp"

// RedBlackNode

template < class T >
ft::RedBlackNode<T>::RedBlackNode ( const value_type & value )
	: parent(NULL), child(), value(value), color(RED)
{
	child[LEFT] = NULL;
	child[RIGHT] = NULL;
}

template < class T >
ft::RedBlackNode<T>::RedBlackNode ( const RedBlackNode & other )
	: parent(other.parent), value(other.value), color(other.color)
{
	this->child[LEFT] = other.child[LEFT];
	this->child[RIGHT] = other.child[RIGHT];
}

template < class T >
ft::RedBlackNode<T>::~RedBlackNode ( void )
{}

template < class T >
typename ft::RedBlackNode<T> & ft::RedBlackNode<T>::operator = ( const RedBlackNode & other )
{
	this->parent		= other.parent;
	this->child[RIGHT]	= other.child[RIGHT];
	this->child[LEFT]	= other.child[LEFT];
	this->value			= other.value;
	this->_color		= other.color;
}

template < class T >
typename ft::RedBlackNode<T> * ft::RedBlackNode<T>::prev ( void )
{
	RedBlackNode * cur;
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

template < class T >
const typename ft::RedBlackNode<T> * ft::RedBlackNode<T>::prev ( void ) const
{
	const RedBlackNode * cur;
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

template < class T >
typename ft::RedBlackNode<T> * ft::RedBlackNode<T>::next ( void )
{
	RedBlackNode * cur;

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

template < class T >
const typename ft::RedBlackNode<T> * ft::RedBlackNode<T>::next ( void ) const
{
	const RedBlackNode * cur;
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

#endif // FT_CONTAINERS_RED_BLACK_NODE_TPP