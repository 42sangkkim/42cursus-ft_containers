#ifndef FT_CONTAINERS_MAP_ITERATOR_TPP
# define FT_CONTAINERS_MAP_ITERATOR_TPP

# include "./map_iterator.hpp"

// ft::map_iterator

template < class Key, class T >
ft::map_iterator<Key, T>::map_iterator ( void )
	: _cur(NULL)
{}

template < class Key, class T >
ft::map_iterator<Key, T>::map_iterator ( const map_iterator & other )
	: _cur(other._cur)
{}

template < class Key, class T >
ft::map_iterator<Key, T>::map_iterator ( node_type * cur )
	: _cur(cur)
{}

template < class Key, class T >
ft::map_iterator<Key, T>::~map_iterator ( void )
{}

template < class Key, class T >
typename ft::map_iterator<Key, T> & ft::map_iterator<Key, T>::operator = ( const map_iterator & other )
{
	this->_cur = other._cur;
	return *this;
}

template < class Key, class T >
bool ft::map_iterator<Key, T>::operator == ( const map_iterator & other ) const
{
	return (this->_cur == other._cur);
}

template < class Key, class T >
bool ft::map_iterator<Key, T>::operator != ( const map_iterator & other ) const
{
	return !(this->operator==(other));
}

template < class Key, class T >
typename ft::map_iterator<Key, T>::value_type & ft::map_iterator<Key, T>::operator * ( void )
{
	return this->_cur->value;
}

template < class Key, class T >
const typename ft::map_iterator<Key, T>::value_type & ft::map_iterator<Key, T>::operator * ( void ) const
{
	return this->_cur->value;
}

template < class Key, class T >
typename ft::map_iterator<Key, T>::value_type * ft::map_iterator<Key, T>::operator -> ( void )
{
	return &this->_cur->value;
}

template < class Key, class T >
const typename ft::map_iterator<Key, T>::value_type * ft::map_iterator<Key, T>::operator -> ( void ) const
{
	return &this->_cur->value;
}

template < class Key, class T >
typename ft::map_iterator<Key, T> & ft::map_iterator<Key, T>::operator ++ ( void )
{
	this->_cur = this->_cur->next();
	return *this;
}

template < class Key, class T >
typename ft::map_iterator<Key, T> ft::map_iterator<Key, T>::operator ++ ( int n )
{
	(void)n;
	map_iterator iter = *this;
	this->operator++();
	return iter;
}

template < class Key, class T >
typename ft::map_iterator<Key, T> & ft::map_iterator<Key, T>::operator -- ( void )
{
	this->_cur = this->_cur->prev();
	return *this;
}

template < class Key, class T >
typename ft::map_iterator<Key, T> ft::map_iterator<Key, T>::operator -- ( int n )
{
	(void)n;
	map_iterator iter = *this;
	this->operator--();
	return iter;
}

// ft::const_map_iterator

template < class Key, class T >
ft::const_map_iterator<Key, T>::const_map_iterator ( void )
	: _cur(NULL)
{}

template < class Key, class T >
ft::const_map_iterator<Key, T>::const_map_iterator ( const const_map_iterator & other )
	: _cur(other._cur)
{}

template < class Key, class T >
ft::const_map_iterator<Key, T>::const_map_iterator ( const node_type * cur )
	: _cur(cur)
{}

template < class Key, class T >
ft::const_map_iterator<Key, T>::const_map_iterator ( const ft::map_iterator<Key, T> & iter )
	: _cur(iter._cur)
{}

template < class Key, class T >
ft::const_map_iterator<Key, T>::~const_map_iterator ( void )
{}

template < class Key, class T >
typename ft::const_map_iterator<Key, T> & ft::const_map_iterator<Key, T>::operator = ( const const_map_iterator & other )
{
	this->_cur = other._cur;
	return *this;
}

template < class Key, class T >
bool ft::const_map_iterator<Key, T>::operator == ( const const_map_iterator & other ) const
{
	return (this->_cur == other._cur);
}

template < class Key, class T >
bool ft::const_map_iterator<Key, T>::operator != ( const const_map_iterator & other ) const
{
	return !(this->operator==(other));
}

template < class Key, class T >
const typename ft::const_map_iterator<Key, T>::value_type & ft::const_map_iterator<Key, T>::operator * ( void ) const
{
	return this->_cur->value;
}

template < class Key, class T >
const typename ft::const_map_iterator<Key, T>::value_type * ft::const_map_iterator<Key, T>::operator -> ( void ) const
{
	return &this->_cur->value;
}

template < class Key, class T >
typename ft::const_map_iterator<Key, T> & ft::const_map_iterator<Key, T>::operator ++ ( void )
{
	this->_cur = this->_cur->next();
	return *this;
}

template < class Key, class T >
typename ft::const_map_iterator<Key, T> ft::const_map_iterator<Key, T>::operator ++ ( int n )
{
	(void)n;
	const_map_iterator iter = *this;
	this->operator++();
	return iter;
}

template < class Key, class T >
typename ft::const_map_iterator<Key, T> & ft::const_map_iterator<Key, T>::operator -- ( void )
{
	this->_cur = this->_cur->prev();
	return *this;
}

template < class Key, class T >
typename ft::const_map_iterator<Key, T> ft::const_map_iterator<Key, T>::operator -- ( int n )
{
	(void)n;
	const_map_iterator iter = *this;
	this->operator--();
	return iter;
}

#endif // FT_CONTAINERS_MAP_ITERATOR_TPP