#ifndef FT_CONTAINERS_VECTOR_ITERATOR_TPP
# define FT_CONTAINERS_VECTOR_ITERATOR_TPP

# include "./vector_iterator.hpp"

// ft::vector_iterator

template < class T >
ft::vector_iterator<T>::vector_iterator ( void )
	: _cur(NULL)
{}

template < class T >
ft::vector_iterator<T>::vector_iterator ( const vector_iterator & other )
	: _cur(other._cur)
{}

template < class T >
ft::vector_iterator<T>::vector_iterator ( T * cur )
	: _cur(cur)
{}

template < class T >
ft::vector_iterator<T>::~vector_iterator ( void )
{}

template < class T >
typename ft::vector_iterator<T> & ft::vector_iterator<T>::operator = ( const vector_iterator & other )
{
	this->_cur = other._cur;
	return *this;
}

template < class T >
bool ft::vector_iterator<T>::operator == ( const vector_iterator & other ) const
{
	return (this->_cur == other._cur);
}

template < class T >
bool ft::vector_iterator<T>::operator != ( const vector_iterator & other ) const
{
	return (this->_cur != other._cur);
}

template < class T >
T & ft::vector_iterator<T>::operator * ( void )
{
	return *this->_cur;
}

template < class T >
const T & ft::vector_iterator<T>::operator * ( void ) const
{
	return *this->_cur;
}

template < class T >
T * ft::vector_iterator<T>::operator -> ( void )
{
	return this->_cur;
}

template < class T >
const T * ft::vector_iterator<T>::operator -> ( void ) const
{
	return this->_cur;
}

template < class T >
T & ft::vector_iterator<T>::operator [] ( difference_type n )
{
	return this->_cur[n];
}

template < class T >
const T & ft::vector_iterator<T>::operator [] ( difference_type n ) const
{
	return this->_cur[n];
}

template < class T >
typename ft::vector_iterator<T> & ft::vector_iterator<T>::operator ++ ( void )
{
	++(this->_cur);
	return *this;
}

template < class T >
typename ft::vector_iterator<T> ft::vector_iterator<T>::operator ++ ( int n )
{
	(void)n;
	return vector_iterator(this->_cur++);
}

template < class T >
typename ft::vector_iterator<T> & ft::vector_iterator<T>::operator -- ( void )
{
	--(this->_cur);
	return *this;
}

template < class T >
typename ft::vector_iterator<T> ft::vector_iterator<T>::operator -- ( int n )
{
	(void)n;
	return vector_iterator(this->_cur--);
}

template < class T >
typename ft::vector_iterator<T>::difference_type ft::vector_iterator<T>::operator - ( const vector_iterator & other ) const
{
	return (this->_cur - other._cur);
}

template < class T >
bool ft::vector_iterator<T>::operator < ( const vector_iterator & other ) const
{
	return (this->_cur < other._cur);
}

template < class T >
bool ft::vector_iterator<T>::operator > ( const vector_iterator & other ) const
{
	return (this->_cur > other._cur);
}

template < class T >
bool ft::vector_iterator<T>::operator <= ( const vector_iterator & other ) const
{
	return (this->_cur <= other._cur);
}

template < class T >
bool ft::vector_iterator<T>::operator >= ( const vector_iterator & other ) const
{
	return (this->_cur >= other._cur);
}


template < class T >
typename ft::vector_iterator<T> & ft::vector_iterator<T>::operator += ( difference_type n )
{
	this->_cur += n;
	return *this;
}

template < class T >
typename ft::vector_iterator<T> & ft::vector_iterator<T>::operator -= ( difference_type n )
{
	this->_cur -= n;
	return *this;
}

template < class T >
typename ft::vector_iterator<T> ft::operator + ( const ft::vector_iterator<T> & lhs, typename ft::vector_iterator<T>::difference_type rhs )
{
	return ft::vector_iterator<T>(lhs._cur + rhs);
}

template < class T >
typename ft::vector_iterator<T> ft::operator + ( typename ft::vector_iterator<T>::difference_type lhs, const ft::vector_iterator<T> & rhs )
{
	return ft::vector_iterator<T>(lhs + rhs._cur);
}

template < class T >
typename ft::vector_iterator<T> ft::operator - ( const ft::vector_iterator<T> & lhs, typename ft::vector_iterator<T>::difference_type rhs )
{
	return ft::vector_iterator<T>(lhs._cur - rhs);
}


// ft::const_vector_iterator

template < class T >
ft::const_vector_iterator<T>::const_vector_iterator ( void )
	: _cur(NULL)
{}

template < class T >
ft::const_vector_iterator<T>::const_vector_iterator ( const const_vector_iterator & other )
	: _cur(other._cur)
{}

template < class T >
ft::const_vector_iterator<T>::const_vector_iterator ( const ft::vector_iterator<T> & iter )
	: _cur(iter._cur)
{}

template < class T >
ft::const_vector_iterator<T>::const_vector_iterator ( const T * cur )
	: _cur(cur)
{}

template < class T >
ft::const_vector_iterator<T>::~const_vector_iterator ( void )
{}

template < class T >
typename ft::const_vector_iterator<T> & ft::const_vector_iterator<T>::operator = ( const const_vector_iterator & other )
{
	this->_cur = other._cur;
	return *this;
}

template < class T >
bool ft::const_vector_iterator<T>::operator == ( const const_vector_iterator & other ) const
{
	return (this->_cur == other._cur);
}

template < class T >
bool ft::const_vector_iterator<T>::operator != ( const const_vector_iterator & other ) const
{
	return (this->_cur != other._cur);
}

template < class T >
const T & ft::const_vector_iterator<T>::operator * ( void ) const
{
	return *this->_cur;
}

template < class T >
const T * ft::const_vector_iterator<T>::operator -> ( void ) const
{
	return this->_cur;
}

template < class T >
const T & ft::const_vector_iterator<T>::operator [] ( difference_type n ) const
{
	return this->_cur[n];
}

template < class T >
typename ft::const_vector_iterator<T> & ft::const_vector_iterator<T>::operator ++ ( void )
{
	++(this->_cur);
	return *this;
}

template < class T >
typename ft::const_vector_iterator<T> ft::const_vector_iterator<T>::operator ++ ( int n )
{
	(void)n;
	return const_vector_iterator(this->_cur++);
}

template < class T >
typename ft::const_vector_iterator<T> & ft::const_vector_iterator<T>::operator -- ( void )
{
	--(this->_cur);
	return *this;
}

template < class T >
typename ft::const_vector_iterator<T> ft::const_vector_iterator<T>::operator -- ( int n )
{
	(void)n;
	return const_vector_iterator(this->_cur--);
}

template < class T >
typename ft::const_vector_iterator<T>::difference_type ft::const_vector_iterator<T>::operator - ( const const_vector_iterator & other ) const
{
	return (this->_cur - other._cur);
}

template < class T >
bool ft::const_vector_iterator<T>::operator < ( const const_vector_iterator & other ) const
{
	return (this->_cur < other._cur);
}

template < class T >
bool ft::const_vector_iterator<T>::operator > ( const const_vector_iterator & other ) const
{
	return (this->_cur > other._cur);
}

template < class T >
bool ft::const_vector_iterator<T>::operator <= ( const const_vector_iterator & other ) const
{
	return (this->_cur <= other._cur);
}

template < class T >
bool ft::const_vector_iterator<T>::operator >= ( const const_vector_iterator & other ) const
{
	return (this->_cur >= other._cur);
}


template < class T >
typename ft::const_vector_iterator<T> & ft::const_vector_iterator<T>::operator += ( difference_type n )
{
	this->_cur += n;
	return *this;
}

template < class T >
typename ft::const_vector_iterator<T> & ft::const_vector_iterator<T>::operator -= ( difference_type n )
{
	this->_cur -= n;
	return *this;
}

template < class T >
typename ft::const_vector_iterator<T> ft::operator + ( const ft::const_vector_iterator<T> & lhs, typename ft::const_vector_iterator<T>::difference_type rhs )
{
	return ft::const_vector_iterator<T>(lhs._cur + rhs);
}

template < class T >
typename ft::const_vector_iterator<T> ft::operator + ( typename ft::const_vector_iterator<T>::difference_type lhs, const ft::const_vector_iterator<T> & rhs )
{
	return ft::const_vector_iterator<T>(lhs + rhs._cur);
}

template < class T >
typename ft::const_vector_iterator<T> ft::operator - ( const ft::const_vector_iterator<T> & lhs, typename ft::const_vector_iterator<T>::difference_type rhs )
{
	return ft::const_vector_iterator<T>(lhs._cur - rhs);
}



template < class T >
typename ft::const_vector_iterator<T> ft::operator + ( const ft::vector_iterator<T> & lhs, const ft::const_vector_iterator<T> & rhs )
{
	return ft::const_vector_iterator<T>(lhs._cur + rhs._cur);
}

template < class T >
typename ft::const_vector_iterator<T> ft::operator + ( const ft::const_vector_iterator<T> & lhs, const ft::vector_iterator<T> & rhs )
{
	return ft::const_vector_iterator<T>(lhs._cur + rhs._cur);
}

template < class T >
typename ft::const_vector_iterator<T>::difference_type ft::operator - ( const ft::vector_iterator<T> & lhs, const ft::const_vector_iterator<T> & rhs )
{
	return (lhs._cur - rhs._cur);
}

template < class T >
typename ft::const_vector_iterator<T>::difference_type ft::operator - ( const ft::const_vector_iterator<T> & lhs, const ft::vector_iterator<T> & rhs )
{
	return (lhs._cur - rhs._cur);
}

template < class T >
bool ft::operator == ( const ft::vector_iterator<T> & lhs, const ft::const_vector_iterator<T> & rhs )
{
	return (lhs._cur == rhs._cur);
}

template < class T >
bool ft::operator == ( const ft::const_vector_iterator<T> & lhs, const ft::vector_iterator<T> & rhs )
{
	return (lhs._cur == rhs._cur);
}

template < class T >
bool ft::operator != ( const ft::vector_iterator<T> & lhs, const ft::const_vector_iterator<T> & rhs )
{
	return (lhs._cur != rhs._cur);
}

template < class T >
bool ft::operator != ( const ft::const_vector_iterator<T> & lhs, const ft::vector_iterator<T> & rhs )
{
	return (lhs._cur != rhs._cur);
}

template < class T >
bool ft::operator < ( const ft::vector_iterator<T> & lhs, const ft::const_vector_iterator<T> & rhs )
{
	return (lhs._cur < rhs._cur);
}

template < class T >
bool ft::operator < ( const ft::const_vector_iterator<T> & lhs, const ft::vector_iterator<T> & rhs )
{
	return (lhs._cur < rhs._cur);
}

template < class T >
bool ft::operator > ( const ft::vector_iterator<T> & lhs, const ft::const_vector_iterator<T> & rhs )
{
	return (lhs._cur > rhs._cur);
}

template < class T >
bool ft::operator > ( const ft::const_vector_iterator<T> & lhs, const ft::vector_iterator<T> & rhs )
{
	return (lhs._cur > rhs._cur);
}

template < class T >
bool ft::operator <= ( const ft::vector_iterator<T> & lhs, const ft::const_vector_iterator<T> & rhs )
{
	return (lhs._cur <= rhs._cur);
}

template < class T >
bool ft::operator <= ( const ft::const_vector_iterator<T> & lhs, const ft::vector_iterator<T> & rhs )
{
	return (lhs._cur <= rhs._cur);
}

template < class T >
bool ft::operator >= ( const ft::vector_iterator<T> & lhs, const ft::const_vector_iterator<T> & rhs )
{
	return (lhs._cur >= rhs._cur);
}

template < class T >
bool ft::operator >= ( const ft::const_vector_iterator<T> & lhs, const ft::vector_iterator<T> & rhs )
{
	return (lhs._cur >= rhs._cur);
}

#endif // FT_CONTAINERS_VECTOR_ITERATOR_TPP