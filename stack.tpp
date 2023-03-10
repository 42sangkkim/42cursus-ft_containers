#ifndef FT_CONTAINERS_STACK_TPP
# define FT_CONTAINERS_STACK_TPP

# include "./stack.hpp"

template < class T, class Container >
ft::stack<T, Container>::stack ( const Container & cont )
	: c(cont)
{}


template < class T, class Container >
ft::stack<T, Container>::stack ( const stack & other )
	: c(other.c)
{}

template < class T, class Container >
ft::stack<T, Container>::~stack ( void )
{}

template < class T, class Container >
typename ft::stack<T, Container> & ft::stack<T, Container>::operator = ( const stack & other )
{
	this->c = other.c;
	return *this;
}

template < class T, class Container >
typename ft::stack<T, Container>::reference ft::stack<T, Container>::top ( void )
{
	return this->c.back();
}

template < class T, class Container >
typename ft::stack<T, Container>::const_reference ft::stack<T, Container>::top ( void ) const
{
	return this->c.back();
}

template < class T, class Container >
bool ft::stack<T, Container>::empty ( void ) const
{
	return c.empty();
}

template < class T, class Container >
typename ft::stack<T, Container>::size_type ft::stack<T, Container>::size ( void ) const
{
	return c.size();
}

template < class T, class Container >
void ft::stack<T, Container>::push ( const value_type & value )
{
	this->c.push_back(value);
}

template < class T, class Container >
void ft::stack<T, Container>::pop ( void )
{
	this->c.pop_back();
}

template < class T, class Container >
bool ft::operator == ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs )
{
	return lhs.c == rhs.c;
}

template < class T, class Container >
bool ft::operator != ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs )
{
	return !(lhs == rhs);
}

template < class T, class Container >
bool ft::operator < ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs )
{
	return lhs.c < rhs.c;
}

template < class T, class Container >
bool ft::operator > ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs )
{
	return lhs.c > rhs.c;
}

template < class T, class Container >
bool ft::operator <= ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs )
{
	return !(lhs > rhs);
}

template < class T, class Container >
bool ft::operator >= ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs )
{
	return !(lhs < rhs);
}

#endif // FT_CONTAINERS_STACK_TPP