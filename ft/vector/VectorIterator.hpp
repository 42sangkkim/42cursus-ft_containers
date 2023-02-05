#ifndef FT_CONTAINERS_FT_VECTOR_VECTOR_ITERATOR_HPP_
# define FT_CONTAINERS_FT_VECTOR_VECTOR_ITERATOR_HPP_

# include "./vector.hpp"

namespace ft
{
	template < 
		class T, 
		class Distance = std::ptrdiff_t, 
		class Pointer = T *, 
		class Reference = T & >
	class VectorIterator
		: std::iterator <
			std::random_access_iterator_tag, 
			T, 
			Distance, 
			Pointer, 
			Reference >
	{
	public:
		// Member types
		typedef std::random_access_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef Distance							difference_type;
		typedef Pointer								pointer;
		typedef Reference							reference;

	protected:
		// Member Objects
		pointer										_current;

	public:
		// Member functions

		//		Constructor
		VectorIterator ( void );
		VectorIterator ( pointer current );
		VectorIterator ( const Iterator & other );

		//		Destructor
		~Iterator ( void );

		//		Assignment operators
		Iterator & operator = ( const Iterator & other );
		Iterator & operator += ( difference_type n );
		Iterator & operator -= ( difference_type n );

		//		Increment operators
		Iterator & operator ++ ( void ); //pre increment
		Iterator operator ++ ( int ); //post increment
		Iterator & operator -- ( void ); // pre decrement
		Iterator operator-- ( int ); // post decrement
		// TODO : *++
		// TODO : *--

		//		Arithmetic operators
		Iterator operator + ( difference_type n );
		Iterator operator - ( difference_type n );

		//		Comparison operators
		bool operator == ( const Iterator & rhs ) const;
		bool operator != ( const Iterator & rhs ) const;
		bool operator < ( const Iterator & rhs ) const;
		bool operator <= ( const Iterator & rhs ) const;
		bool operator > ( const Iterator & rhs ) const;
		bool operator >= ( const Iterator & rhs ) const;

		//		Member access operators
		reference operator [] ( difference_type n );
		reference operator * ( void );
		const_reference operator * ( void ) const;
		reference operator -> ( void );
		const_reference operator -> ( void ) const;
	} // class VectorIterator

	//		Constructor
	template < class T, class Difference, class Pointer, class Reference >
	VectorIterator<T, Difference, Pointer, Reference>::VectorIterator ( void )
		: _current(NULL);
	{

	}

	template < class T, class Difference, class Pointer, class Reference >
	VectorIterator<T, Difference, Pointer, Reference>::VectorIterator ( pointer current )
		: _current(current);
	{

	}

	template < class T, class Difference, class Pointer, class Reference >
	VectorIterator<T, Difference, Pointer, Reference>::VectorIterator ( const VectorIterator & other )
		: _current(other._current);
	{

	}


	//		Destructor
	template < class T, class Difference, class Pointer, class Reference >
	VectorIterator<T, Difference, Pointer, Reference>::~VectorIterator ( const VectorIterator & other )
	{

	}

	//		Assignment operators
	template < class T, class Difference, class Pointer, class Reference >
	VectorIterator & VectorIterator<T, Difference, Pointer, Reference>::operator = ( const Iterator & other )
	{
		this->_current = other._current;
		return *this;
	}

	template < class T, class Difference, class Pointer, class Reference >
	VectorIterator & VectorIterator<T, Difference, Pointer, Reference>::operator += ( difference_type n )
	{
		this->_current += n;
		return *this;
	}

	template < class T, class Difference, class Pointer, class Reference >
	VectorIterator & VectorIterator<T, Difference, Pointer, Reference>::operator -= ( difference_type n )
	{
		this->_current -= n;
		return *this;
	}

	//		Increment operators
	template < class T, class Difference, class Pointer, class Reference >
	VectorIterator & VectorIterator<T, Difference, Pointer, Reference>::operator ++ ( void ) //pre increment
	{
		this->_current++;
		return *this;
	}

	template < class T, class Difference, class Pointer, class Reference >
	VectorIterator VectorIterator<T, Difference, Pointer, Reference>::operator ++ ( int ) //post increment
	{
		VectorIterator	temp(*this);
		this->_current++;
		return temp;
	}

	template < class T, class Difference, class Pointer, class Reference >
	VectorIterator & VectorIterator<T, Difference, Pointer, Reference>::operator -- ( void ) // pre decrement
	{
		this->_current--;
		return *this;
	}

	template < class T, class Difference, class Pointer, class Reference >
	VectorIterator VectorIterator<T, Difference, Pointer, Reference>::operator-- ( int ) // post decrement
	{
		VectorIterator	temp(*this);
		this->_current--;
		return temp;
	}

	// TODO : *++
	// TODO : *--

	//		Arithmetic operators
	template < class T, class Difference, class Pointer, class Reference >
	VectorIterator VectorIterator<T, Difference, Pointer, Reference>::operator + ( difference_type n )
	{
		VectorIterator	result(*this);
		return (result += n);
	}

	template < class T, class Difference, class Pointer, class Reference >
	VectorIterator VectorIterator<T, Difference, Pointer, Reference>::operator - ( difference_type n )
	{
		VectorIterator	result(*this);
		return (result -= n);
	}

	//		Comparison operators
	template < class T, class Difference, class Pointer, class Reference >
	bool VectorIterator<T, Difference, Pointer, Reference>::operator == ( const Iterator & rhs ) const
	{
		return (this->_current == rhs._current);
	}

	template < class T, class Difference, class Pointer, class Reference >
	bool VectorIterator<T, Difference, Pointer, Reference>::operator != ( const Iterator & rhs ) const
	{
		return (this->_current != rhs._current);
	}

	template < class T, class Difference, class Pointer, class Reference >
	bool VectorIterator<T, Difference, Pointer, Reference>::operator < ( const Iterator & rhs ) const
	{
		return (this->_current < rhs._current);
	}

	template < class T, class Difference, class Pointer, class Reference >
	bool VectorIterator<T, Difference, Pointer, Reference>::operator <= ( const Iterator & rhs ) const
	{
		return (this->_current <= rhs._current);
	}

	template < class T, class Difference, class Pointer, class Reference >
	bool VectorIterator<T, Difference, Pointer, Reference>::operator > ( const Iterator & rhs ) const
	{
		return (this->_current > rhs._current);
	}

	template < class T, class Difference, class Pointer, class Reference >
	bool VectorIterator<T, Difference, Pointer, Reference>::operator >= ( const Iterator & rhs ) const
	{
		return (this->_current >= rhs._current);
	}

	//		Member access operators
	template < class T, class Difference, class Pointer, class Reference >
	reference VectorIterator<T, Difference, Pointer, Reference>::operator [] ( difference_type n )
	{
		return this->_current[n];
	}

	template < class T, class Difference, class Pointer, class Reference >
	reference VectorIterator<T, Difference, Pointer, Reference>::operator * ( void )
	{
		return *this->_current;
	}

	template < class T, class Difference, class Pointer, class Reference >
	const_reference VectorIterator<T, Difference, Pointer, Reference>::operator * ( void ) const
	{
		return *this->_current;
	}

	template < class T, class Difference, class Pointer, class Reference >
	reference VectorIterator<T, Difference, Pointer, Reference>::operator -> ( void )
	{
		return *this->_current;
	}

	template < class T, class Difference, class Pointer, class Reference >
	const_reference VectorIterator<T, Difference, Pointer, Reference>::operator -> ( void ) const
	{
		return *this->_current;
	}

} // namespace ft

#endif // FT_CONTAINERS_FT_VECTOR_VECTOR_ITERATOR_HPP_
