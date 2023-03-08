#ifndef FT_CONTAINERS_SET_ITERATOR_TPP
# define FT_CONTAINERS_SET_ITERATOR_TPP

# include "./set_iterator.hpp"

template < class Key >
ft::set_iterator<Key>::set_iterator ( void )
	: _cur(NULL)
{}

template < class Key >
ft::set_iterator<Key>::set_iterator ( const set_iterator & other )
	: _cur(other._cur)
{}

template < class Key >
ft::set_iterator<Key>::set_iterator ( const node_type * cur )
	: _cur(cur)
{}

template < class Key >
ft::set_iterator<Key>::~set_iterator ( void )
{}

template < class Key >
typename ft::set_iterator<Key> & ft::set_iterator<Key>::operator = ( const set_iterator & other )
{
	this->_cur = other._cur;
	return *this;
}

template < class Key >
bool ft::set_iterator<Key>::operator == ( const set_iterator & other ) const
{
	return (this->_cur == other._cur);
}

template < class Key >
bool ft::set_iterator<Key>::operator != ( const set_iterator & other ) const
{
	return !(this->operator==(other));
}

template < class Key >
typename ft::set_iterator<Key>::value_type & ft::set_iterator<Key>::operator * ( void ) const
{
	return this->_cur->value;
}

template < class Key >
typename ft::set_iterator<Key>::value_type * ft::set_iterator<Key>::operator -> ( void ) const
{
	return &this->_cur->value;
}

template < class Key >
typename ft::set_iterator<Key> & ft::set_iterator<Key>::operator ++ ( void )
{
	this->_cur = this->_cur->next();
	return *this;
}

template < class Key >
typename ft::set_iterator<Key> ft::set_iterator<Key>::operator ++ ( int n )
{
	(void)n;
	set_iterator iter = *this;
	this->operator++();
	return iter;
}

template < class Key >
typename ft::set_iterator<Key> & ft::set_iterator<Key>::operator -- ( void )
{
	this->_cur = this->_cur->prev();
	return *this;
}

template < class Key >
typename ft::set_iterator<Key> ft::set_iterator<Key>::operator -- ( int n )
{
	(void)n;
	set_iterator iter = *this;
	this->operator--();
	return iter;
}

#endif // FT_CONTAINERS_SET_ITERATOR_TPP