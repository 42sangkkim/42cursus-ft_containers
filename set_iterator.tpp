#ifndef FT_CONTAINERS_SET_ITERATOR_TPP
# define FT_CONTAINERS_SET_ITERATOR_TPP

# include "./set_iterator.hpp"

template < class Key, class Compare, class Allocator >
ft::set<Key, Compare, Allocator>::iterator::iterator ( void )
	: _cur(NULL)
{}

template < class Key, class Compare, class Allocator >
ft::set<Key, Compare, Allocator>::iterator::iterator ( const iterator & other )
	: _cur(other._cur)
{}

template < class Key, class Compare, class Allocator >
ft::set<Key, Compare, Allocator>::iterator::iterator ( const node_type * cur )
	: _cur(cur)
{}

template < class Key, class Compare, class Allocator >
ft::set<Key, Compare, Allocator>::iterator::~iterator ( void )
{}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::iterator & ft::set<Key, Compare, Allocator>::iterator::operator = ( const iterator & other )
{
	this->_cur = other._cur;
	return *this;
}

template < class Key, class Compare, class Allocator >
bool ft::set<Key, Compare, Allocator>::iterator::operator == ( const iterator & other ) const
{
	return (this->_cur == other._cur);
}

template < class Key, class Compare, class Allocator >
bool ft::set<Key, Compare, Allocator>::iterator::operator != ( const iterator & other ) const
{
	return !(this->operator==(other));
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::iterator::value_type & ft::set<Key, Compare, Allocator>::iterator::operator * ( void ) const
{
	return this->_cur->value;
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::iterator::value_type * ft::set<Key, Compare, Allocator>::iterator::operator -> ( void ) const
{
	return &this->_cur->value;
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::iterator & ft::set<Key, Compare, Allocator>::iterator::operator ++ ( void )
{
	this->_cur = this->_cur->next();
	return *this;
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::iterator ft::set<Key, Compare, Allocator>::iterator::operator ++ ( int n )
{
	(void)n;
	iterator iter = *this;
	this->operator++();
	return iter;
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::iterator & ft::set<Key, Compare, Allocator>::iterator::operator -- ( void )
{
	this->_cur = this->_cur->prev();
	return *this;
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::iterator ft::set<Key, Compare, Allocator>::iterator::operator -- ( int n )
{
	(void)n;
	iterator iter = *this;
	this->operator--();
	return iter;
}

#endif // FT_CONTAINERS_SET_CONST_ITERATOR_TPP