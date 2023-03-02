#ifndef FT_CONTAINERS_MAP_CONST_ITERATOR_TPP
# define FT_CONTAINERS_MAP_CONST_ITERATOR_TPP

# include "./map_const_iterator.hpp"

template < class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::const_iterator::const_iterator ( void )
	: _cur(NULL)
{}

template < class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::const_iterator::const_iterator ( const const_iterator & other )
	: _cur(other._cur)
{}

template < class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::const_iterator::const_iterator ( const iterator & it )
	: _cur(it._cur)
{}

template < class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::const_iterator::const_iterator ( const node_type * cur )
	: _cur(cur)
{}

template < class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::const_iterator::~const_iterator ( void )
{}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator & ft::map<Key, T, Compare, Allocator>::const_iterator::operator = ( const const_iterator & other )
{
	this->_cur = other._cur;
	return *this;
}

template < class Key, class T, class Compare, class Allocator>
bool ft::map<Key, T, Compare, Allocator>::const_iterator::operator == ( const const_iterator & other ) const
{
	return (this->_cur == other._cur);
}

template < class Key, class T, class Compare, class Allocator>
bool ft::map<Key, T, Compare, Allocator>::const_iterator::operator != ( const const_iterator & other ) const
{
	return !(this->operator==(other));
}

template < class Key, class T, class Compare, class Allocator>
const typename ft::map<Key, T, Compare, Allocator>::value_type & ft::map<Key, T, Compare, Allocator>::const_iterator::operator * ( void ) const
{
	return this->_cur->value;
}

template < class Key, class T, class Compare, class Allocator>
const typename ft::map<Key, T, Compare, Allocator>::value_type * ft::map<Key, T, Compare, Allocator>::const_iterator::operator -> ( void ) const
{
	return &this->_cur->value;
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator & ft::map<Key, T, Compare, Allocator>::const_iterator::operator ++ ( void )
{
	this->_cur = this->_cur->next();
	return *this;
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::const_iterator::operator ++ ( int n )
{
	(void)n;
	const_iterator iter = *this;
	this->operator++();
	return iter;
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator & ft::map<Key, T, Compare, Allocator>::const_iterator::operator -- ( void )
{
	this->_cur = this->_cur->prev();
	return *this;
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::const_iterator::operator -- ( int n )
{
	(void)n;
	const_iterator iter = *this;
	this->operator--();
	return iter;
}

#endif // FT_CONTAINERS_MAP_CONST_ITERATOR_TPP