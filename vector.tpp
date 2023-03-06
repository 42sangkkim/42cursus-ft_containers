#ifndef FT_CONTAINERS_VECTOR_TPP
# define FT_CONTAINERS_VECTOR_TPP

# include "./vector.hpp"
# include "./equal.hpp"
# include "./lexicographical_compare.hpp"
# include "./enable_if.hpp"
# include "./is_integral.hpp"

template < class T, class A >
ft::vector<T, A>::vector ( void )
	: _data(NULL), _alloc(allocator_type()), _size(0), _capacity(0)
{

}

template < class T, class A >
ft::vector<T, A>::vector (const allocator_type & alloc )
	: _data(NULL), _alloc(alloc), _size(0), _capacity(0)
{

}

template < class T, class A >
ft::vector<T, A>::vector ( size_type count, const_reference value, const allocator_type & alloc )
	: _data(NULL), _alloc(alloc), _size(0), _capacity(0)
{
	this->insert(this->begin(), count, value);
}

template < class T, class A >
template < class InputIt >
ft::vector<T, A>::vector ( typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first, InputIt last, const allocator_type & alloc )
	: _data(NULL), _alloc(alloc), _size(0), _capacity(0)
{
	this->insert(this->begin(), first, last);
}

template < class T, class A >
ft::vector<T, A>::vector ( const vector & other )
	: _data(NULL), _alloc(other._alloc), _size(0), _capacity(0)
{
	this->insert(this->begin(), other.begin(), other.end());
}

template < class T, class A >
ft::vector<T, A>::~vector ( void )
{
	this->clear();
	this->_alloc.deallocate(this->_data, this->_capacity);
}

template < class T, class A >
ft::vector<T, A> & ft::vector<T, A>::operator = ( const vector & other )
{
	if (this == &other)
		return *this;
	this->clear();
	this->insert(this->begin(), other.begin(), other.end());
	return *this;
}

template < class T, class A >
void ft::vector<T, A>::assign ( size_type count, const_reference value )
{
	this->clear();
	this->insert(this->begin(), count, value);
}

template < class T, class A >
template < class InputIt >
typename ft::enable_if<!ft::is_integral<InputIt>::value, void>::type ft::vector<T, A>::assign ( InputIt first, InputIt last )
{
	this->clear();
	this->insert(this->begin(), first, last);
}

template < class T, class A >
typename ft::vector<T, A>::allocator_type ft::vector<T, A>::get_allocator ( void ) const
{
	return this->_alloc;
}

//	Element accesses

template < class T, class A >
typename ft::vector<T, A>::reference ft::vector<T, A>::at ( size_type pos )
{
	if (pos >= this->_size)
		throw std::out_of_range("ft::vector");
	return this->_data[pos];
}

template < class T, class A >
typename ft::vector<T, A>::const_reference ft::vector<T, A>::at ( size_type pos ) const
{
	if (pos >= this->_size)
		throw std::out_of_range("ft::vector");
	return this->_data[pos];
}

template < class T, class A >
typename ft::vector<T, A>::reference ft::vector<T, A>::operator [] ( size_type pos )
{
	return this->_data[pos];
}

template < class T, class A >
typename ft::vector<T, A>::const_reference ft::vector<T, A>::operator [] ( size_type pos ) const
{
	return this->_data[pos];
}

template < class T, class A >
typename ft::vector<T, A>::reference ft::vector<T, A>::front ( void )
{
	return this->_data[0];
}

template < class T, class A >
typename ft::vector<T, A>::const_reference ft::vector<T, A>::front ( void ) const
{
	return this->_data[0];
}

template < class T, class A >
typename ft::vector<T, A>::reference ft::vector<T, A>::back ( void )
{
	return this->_data[this->_size - 1];
}

template < class T, class A >
typename ft::vector<T, A>::const_reference ft::vector<T, A>::back ( void ) const
{
	return this->_data[this->_size - 1];
}

template < class T, class A >
typename ft::vector<T, A>::pointer ft::vector<T, A>::data ( void )
{
	return this->_data;
}

template < class T, class A >
typename ft::vector<T, A>::const_pointer ft::vector<T, A>::data ( void ) const
{
	return this->_data;
}

//	Iterators

template < class T, class A >
typename ft::vector<T, A>::iterator ft::vector<T, A>::begin ( void )
{
	return iterator(this->_data);
}

template < class T, class A >
typename ft::vector<T, A>::const_iterator ft::vector<T, A>::begin ( void ) const
{
	return const_iterator(this->_data);
}

template < class T, class A >
typename ft::vector<T, A>::iterator ft::vector<T, A>::end ( void )
{
	return iterator(this->_data + this->_size);
}

template < class T, class A >
typename ft::vector<T, A>::const_iterator ft::vector<T, A>::end ( void ) const
{
	return const_iterator(this->_data + this->_size);
}

template < class T, class A >
typename ft::vector<T, A>::reverse_iterator ft::vector<T, A>::rbegin ( void )
{
	return reverse_iterator(this->end());
}

template < class T, class A >
typename ft::vector<T, A>::const_reverse_iterator ft::vector<T, A>::rbegin ( void ) const
{
	return const_reverse_iterator(this->end());
}

template < class T, class A >
typename ft::vector<T, A>::reverse_iterator ft::vector<T, A>::rend ( void )
{
	return reverse_iterator(this->begin());
}

template < class T, class A >
typename ft::vector<T, A>::const_reverse_iterator ft::vector<T, A>::rend ( void ) const
{
	return const_reverse_iterator(this->begin());
}

//		Capacity

template < class T, class A >
bool ft::vector<T, A>::empty ( void ) const
{
	return (this->_size == 0);
}

template < class T, class A >
typename ft::vector<T, A>::size_type ft::vector<T, A>::size ( void ) const
{
	return this->_size;
}

template < class T, class A >
typename ft::vector<T, A>::size_type ft::vector<T, A>::max_size ( void ) const
{
	size_type	size_max = std::numeric_limits<size_type>::max() / sizeof(value_type);
	size_type	diff_max = std::numeric_limits<difference_type>::max();
	return size_max < diff_max ? size_max : diff_max;
}

template < class T, class A >
void ft::vector<T, A>::reserve ( size_type new_cap )
{
	if (new_cap > this->max_size())
		throw std::length_error("ft:vector");
	else if (new_cap <= this->_capacity)
		return ;
	else if (new_cap <= this->_size * 2)
		new_cap = this->_size * 2;
	if (new_cap > this->max_size())
		new_cap = this->max_size();

	pointer	new_data = this->_alloc.allocate(new_cap);
	memmove(new_data, this->_data, this->_size * sizeof(value_type));
	this->_alloc.deallocate(this->_data, this->_capacity);
	this->_capacity = new_cap;
	this->_data = new_data;
}

template < class T, class A >
typename ft::vector<T, A>::size_type ft::vector<T, A>::capacity ( void ) const
{
	return this->_capacity;
}

//		Modifiers

template < class T, class A >
void ft::vector<T, A>::clear ( void )
{
	for (; this->_size != 0; this->_size--)
		this->_alloc.destroy(this->_data + this->_size - 1);
}

template < class T, class A >
typename ft::vector<T, A>::iterator ft::vector<T, A>::insert ( const_iterator pos, const_reference value )
{
	return (this->insert(pos, 1, value));
}

template < class T, class A >
typename ft::vector<T, A>::iterator ft::vector<T, A>::insert ( const_iterator pos, size_type count, const_reference value )
{
	difference_type		idx;
	pointer				ptr;

	idx = pos - this->_data;
	this->reserve(this->_size + count);
	ptr = this->_data + idx;
	memmove(ptr + count, ptr, (this->_size - idx) * sizeof(value_type));
	for (; count != 0 ; count--, this->_size++)
		this->_data[idx++] = value;
	return iterator(this->_data + idx - 1);
}

template < class T, class A >
template < class InputIt >
typename ft::enable_if<!ft::is_integral<InputIt>::value, typename ft::vector<T, A>::iterator>::type ft::vector<T, A>::insert ( const_iterator pos, InputIt first, InputIt last )
{
	size_type			count;
	difference_type		idx;
	pointer				ptr;

	count = 0;
	for (InputIt it(first); it != last; it++)
		count++;
	idx = pos - this->_data;
	this->reserve(this->_size + count);
	ptr = this->_data + idx;
	memmove(ptr + count, ptr, (this->_size - idx) * sizeof(value_type));
	for (; first != last; first++, this->_size++)
		this->_data[idx++] = value_type(*first);
	return iterator(this->_data + idx - 1);
}

template < class T, class A >
typename ft::vector<T, A>::iterator ft::vector<T, A>::erase ( iterator pos )
{
	return this->erase(pos, pos + 1);
}

template < class T, class A >
typename ft::vector<T, A>::iterator ft::vector<T, A>::erase ( iterator first, iterator last )
{
	size_type	count;

	count = 0;
	for (iterator it(first); it != last; it++, count++)
		this->_alloc.destroy(it);
	memmove(first, last, (this->end() - last) * sizeof(value_type));
	this->_size -= count;
	return (first);
}

template < class T, class A >
void ft::vector<T, A>::push_back ( const_reference value )
{
	this->reserve(this->_size + 1);
	this->_data[this->_size++] = value;
}

template < class T, class A >
void ft::vector<T, A>::pop_back ( void )
{
	this->_alloc.destroy(this->_data + (--this->_size));
}

template < class T, class A >
void ft::vector<T, A>::resize ( size_type count, value_type value )
{
	if (this->_size > count)
	{
		for (; this->_size != count; this->_size--)
			this->_alloc.destroy(this->_data + this->_size - 1);
	}
	else if (this->_size < count)
	{
		this->reserve(count);
		for (; this->_size != count; this->_size++)
			this->_data[this->_size] = value;
	}
}

template < class T, class A >
void ft::vector<T, A>::swap ( vector & other )
{
	pointer		tmp_data		= this->_data;
	size_type	tmp_size		= this->_size;
	size_type	tmp_capacity	= this->_capacity;
	this->_data					= other._data;
	this->_size					= other._size;
	this->_capacity				= other._capacity;
	other._data					= tmp_data;
	other._size					= tmp_size;
	other._capacity				= tmp_capacity;
}

//	Non-member functions

template < class T, class A >
bool ft::operator == ( const ft::vector<T, A> & lhs, const ft::vector<T, A> & rhs )
{
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template < class T, class A >
bool ft::operator != ( const ft::vector<T, A> & lhs, const ft::vector<T, A> & rhs )
{
	return !(lhs == rhs);
}

template < class T, class A >
bool ft::operator < ( const ft::vector<T, A> & lhs, const ft::vector<T, A> & rhs )
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template < class T, class A >
bool ft::operator > ( const ft::vector<T, A> & lhs, const ft::vector<T, A> & rhs )
{
	return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}

template < class T, class A >
bool ft::operator <= ( const ft::vector<T, A> & lhs, const ft::vector<T, A> & rhs )
{
	return !(lhs > rhs);
}

template < class T, class A >
bool ft::operator >= ( const ft::vector<T, A> & lhs, const ft::vector<T, A> & rhs )
{
	return !(lhs < rhs);
}

template < class T, class A >
void ft::swap ( ft::vector<T, A> & lhs, ft::vector<T, A> & rhs )
{
	lhs.swap(rhs);
}

#endif // FT_CONTAINERS_VECTOR_TPP
