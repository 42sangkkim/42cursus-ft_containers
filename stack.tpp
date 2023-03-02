#ifndef FT_CONTAINERS_STACK_TPP
# define FT_CONTAINERS_STACK_TPP

# include "./stack.hpp"

template < class T, class Container >
ft::stack<T, Container>::stack ( const Container & cont )
	: C(cont)
{}


template < class T, class Container >
ft::stack<T, Container>::stack ( const stack & other )
	: C(other.C)
{}

template < class T, class Container >
ft::stack<T, Container>::~stack ( void )
{}

template < class T, class Container >
typename ft::stack<T, Container> & ft::stack<T, Container>::operator = ( const stack & other )
{
	this->C = other.C;
	return *this;
}

template < class T, class Container >
typename ft::stack<T, Container>::reference ft::stack<T, Container>::top ( void )
{
	return this->C.back();
}

template < class T, class Container >
typename ft::stack<T, Container>::const_reference ft::stack<T, Container>::top ( void ) const
{
	return this->C.back();
}

template < class T, class Container >
bool ft::stack<T, Container>::empty ( void ) const
{
	return C.empty();
}

template < class T, class Container >
typename ft::stack<T, Container>::size_type ft::stack<T, Container>::size ( void ) const
{
	return C.size();
}

template < class T, class Container >
void ft::stack<T, Container>::push ( const value_type & value )
{
	this->C.push_back(value);
}

template < class T, class Container >
void ft::stack<T, Container>::pop ( void )
{
	this->C.pop_back();
}

template < class T, class Container >
bool ft::operator == ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs )
{
	return lhs.C == rhs.C;
}

template < class T, class Container >
bool ft::operator != ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs )
{
	return !(lhs == rhs);
}

template < class T, class Container >
bool ft::operator < ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs )
{
	return lhs.C < rhs.C;
}

template < class T, class Container >
bool ft::operator > ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs )
{
	return lhs.C > rhs.C;
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