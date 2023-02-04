#ifndef FT_VECTOR_TPP
# define FT_VECTOR_TPP

# include "./vector.hpp"

namespace ft
{
	template < class T, class Allocator >
	vector<T, Allocator>::vector ( void )
	 : _size(0), _capacity(vector::_min_capacity), _data(NULL)
	{
		// Allocate memory;
	}

	template < class T, class Allocator >
	vector<T, Allocator>::vector ( const allocator_type & alloc )
	 : _size(0), _capacity(vector::_min_capacity), _data(NULL)
	{

	}

	template < class T, class Allocator >
	vector<T, Allocator>::vector ( \
		size_type count, \
		const value_type & val = value_type(), \
		const allocator_type & alloc = allocator_type() \
	);

	template < class InputIterator >
	vector ( \
		InputIterator first, \
		InputIterator last, \
		const allocator_type & alloc = allocator_type() \
	);
	vector ( const vector & other );
}

#endif // FT_VECTOR_TPP
