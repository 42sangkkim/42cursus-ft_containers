#ifndef FT_CONTAINERS_MAP_ITERATOR_TPP
# define FT_CONTAINERS_MAP_ITERATOR_TPP

# include "./map_iterator.hpp"

template < class Key, class T, class Compare, class Allocator >
ft::map<Key, T, Compare, Allocator>::iterator::iterator ( void )
	: _cur(NULL)
{}

template < class Key, class T, class Compare, class Allocator >
ft::map<Key, T, Compare, Allocator>::iterator::iterator ( const iterator & other )
	: _cur(other._cur)
{}

template < class Key, class T, class Compare, class Allocator >
ft::map<Key, T, Compare, Allocator>::iterator::iterator ( node_type * cur )
	: _cur(cur)
{}

template < class Key, class T, class Compare, class Allocator >
ft::map<Key, T, Compare, Allocator>::iterator::~iterator ( void )
{}

template < class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::iterator & ft::map<Key, T, Compare, Allocator>::iterator::operator = ( const iterator & other )
{
	this->_cur = other._cur;
	return *this;
}

template < class Key, class T, class Compare, class Allocator >
bool ft::map<Key, T, Compare, Allocator>::iterator::operator == ( const iterator & other ) const
{
	return (this->_cur == other._cur);
}

template < class Key, class T, class Compare, class Allocator >
bool ft::map<Key, T, Compare, Allocator>::iterator::operator != ( const iterator & other ) const
{
	return !(this->operator==(other));
}

template < class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::value_type & ft::map<Key, T, Compare, Allocator>::iterator::operator * ( void )
{
	return this->_cur->value;
}

template < class Key, class T, class Compare, class Allocator >
const typename ft::map<Key, T, Compare, Allocator>::value_type & ft::map<Key, T, Compare, Allocator>::iterator::operator * ( void ) const
{
	return this->_cur->value;
}

template < class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::value_type * ft::map<Key, T, Compare, Allocator>::iterator::operator -> ( void )
{
	return &this->_cur->value;
}

template < class Key, class T, class Compare, class Allocator >
const typename ft::map<Key, T, Compare, Allocator>::value_type * ft::map<Key, T, Compare, Allocator>::iterator::operator -> ( void ) const
{
	return &this->_cur->value;
}

template < class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::iterator & ft::map<Key, T, Compare, Allocator>::iterator::operator ++ ( void )
{
	this->_cur = this->_cur->next();
	return *this;
}

template < class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::iterator::operator ++ ( int n )
{
	(void)n;
	iterator iter = *this;
	this->operator++();
	return iter;
}

template < class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::iterator & ft::map<Key, T, Compare, Allocator>::iterator::operator -- ( void )
{
	this->_cur = this->_cur->prev();
	return *this;
}

template < class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::iterator::operator -- ( int n )
{
	(void)n;
	iterator iter = *this;
	this->operator--();
	return iter;
}

#endif // FT_CONTAINERS_MAP_ITERATOR_TPP