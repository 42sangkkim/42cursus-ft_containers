#ifndef FT_CONTAINERS_RESERSE_ITERATOR_TPP
# define FT_CONTAINERS_RESERSE_ITERATOR_TPP

# include "./reverse_iterator.hpp"

namespace ft
{
	template < class Iter >
	reverse_iterator<Iter>::reverse_iterator ( void )
		: current()
	{

	}

	template < class Iter >
	reverse_iterator<Iter>::reverse_iterator ( iterator_type x )
		: current(x)
	{

	}

	template < class Iter >
	template < class U >
	reverse_iterator<Iter>::reverse_iterator ( const reverse_iterator < U > & other )
		: current(other.current)
	{

	}

	template < class Iter >
	reverse_iterator<Iter> & reverse_iterator<Iter>::operator = ( const reverse_iterator < U > & other )
	{
		this->current = other.current;
		return *this;
	}

	template < class Iter >
	typename reserse_iterator<Iter>::iterator_type reverse_iterator<Iter>::base ( void ) const
	{
		return this->current;
	}

	template < class Iter >
	typename reserse_iterator<Iter>::reference reverse_iterator<Iter>::operator * ( void ) const
	{
		iterator_type	ret = this->current;
		return *(--ret);
	}

	template < class Iter >
	typename reserse_iterator<Iter>::pointer reverse_iterator<Iter>::operator -> ( void ) const
	{
		return &(this->operator*());
	}

	template < class Iter >
	typename reserse_iterator<Iter>::reference reverse_iterator<Iter>::operator [] ( difference_type ) const
	{
		base[-n - 1];
	}

	template < class Iter >
	reserse_iterator<Iter> & reverse_iterator<Iter>::operator ++ ( void )
	{
		this->current.operator--();
		return *this;
	}

	template < class Iter >
	reserse_iterator<Iter> & reverse_iterator<Iter>::operator -- ( void )
	{
		this->current.operator++();
		return *this;
	}

	template < class Iter >
	reserse_iterator<Iter> reverse_iterator<Iter>::operator ++ ( int n )
	{
		(void)n;
		reverse_iterator<Iterator>	tmp(this);
		return --tmp;
	}

	template < class Iter >
	reserse_iterator<Iter> reverse_iterator<Iter>::operator -- ( int n )
	{
		(void)n;
		reverse_iterator<Iterator>	tmp(this);
		return ++tmp;
	}

	template < class Iter >
	reserse_iterator<Iter> reverse_iterator<Iter>::operator + ( difference_type n ) const
	{
		return reverse_iterator<Iter>(base - n);
	}

	template < class Iter >
	reserse_iterator<Iter> reverse_iterator<Iter>::operator - ( difference_type n ) const
	{
		return reverse_iterator<Iter>(base + n);
	}

	template < class Iter >
	reserse_iterator<Iter> & reverse_iterator<Iter>::operator += ( difference_type n )
	{
		this->current -= n;
		return *this;
	}

	template < class Iter >
	reserse_iterator<Iter> & reverse_iterator<Iter>::operator -= ( difference_type n )
	{
		this->current += n;
		return *this;
	}

	// Non-member functions

	template < class Iterator1, class Iterator2 >
	bool operator == ( const ft::reverse_iterator<Iterator1> & lhs, const ft::reverse_iterator<Iterator2> & rhs )
	{
		return lhs.base() == rhs.base();
	}

	template < class Iterator1, class Iterator2 >
	bool operator != ( const ft::reverse_iterator<Iterator1> & lhs, const ft::reverse_iterator<Iterator2> & rhs )
	{
		return lhs.base() != rhs.base();
	}

	template < class Iterator1, class Iterator2 >
	bool operator < ( const ft::reverse_iterator<Iterator1> & lhs, const ft::reverse_iterator<Iterator2> & rhs )
	{
		return lhs.base() > rhs.base();
	}

	template < class Iterator1, class Iterator2 >
	bool operator <= ( const ft::reverse_iterator<Iterator1> & lhs, const ft::reverse_iterator<Iterator2> & rhs )
	{
		return lhs.base() >= rhs.base();
	}

	template < class Iterator1, class Iterator2 >
	bool operator > ( const ft::reverse_iterator<Iterator1> & lhs, const ft::reverse_iterator<Iterator2> & rhs )
	{
		return lhs.base() < rhs.base();
	}

	template < class Iterator1, class Iterator2 >
	bool operator >= ( const ft::reverse_iterator<Iterator1> & lhs, const ft::reverse_iterator<Iterator2> & rhs )
	{
		return lhs.base() <= rhs.base();
	}

	template < class Iter >
	reverse_iterator<Iter> operator + ( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> & it )
	{
		return reserve_iterator<Iter>(it.base - n);
	}

	template < class Iterator1, class Iterator2 >
	typename reverse_iterator<Iterator1>::difference_type operator - ( const reverse_iterator<Iterator1> & lhs, const reverse_iterator<Iterator2> & rhs )
	{
		return rhs.base() - lhs.base();
	}

}

#endif // FT_CONTAINERS_RESERSE_ITERATOR_TPP
