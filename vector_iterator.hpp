#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "vector.hpp"

template < \
	class Category, \
	class T, \
	class Distance = ptrdiff_t, \
	class Pointer = T*, \
	class Reference = T& \
>
struct iterator
{
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};


ft
{
	vector
	{
		class iterator;
		{
			
		}
	};
};


#endif//VECTOR_ITERATOR_HPP
