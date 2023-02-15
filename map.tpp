#ifndef FT_CONTAINERS_MAP_TPP
# define FT_CONTAINERS_MAP_TPP

# include "./map.hpp"

namespace ft
{
	// value_compare
	template < class K, class T, class C, class A >
	ft::map<K, T, C, A>::value_compare::value_compare ( void )
		: comp()
	{}

	template < class K, class T, class C, class A >
	ft::map<K, T, C, A>::value_compare::value_compare ( C c )
		: comp(c)
	{}

	template < class K, class T, class C, class A >
	bool ft::map<K, T, C, A>::value_compare::operator () ( const value_type & lhs, const value_type) const
	{
		return comp(lhs, rhs);
	}

	// Member functions
	template < class K, class T, class C, class A >
	ft::map<K, T, C, A>::map ( void ); // TODO

	template < class K, class T, class C, class A >
	ft::map<K, T, C, A>::map ( const key_compare & comp, const allocator_type & alloc = allocator_type() ); // TODO

	template < class K, class T, class C, class A >
	template < class InputIt >
	ft::map<K, T, C, A>::map ( InputIt first, InputIt last, const allocator_type & alloc = allocator_type() ); // TODO

	template < class K, class T, class C, class A >
	ft::map<K, T, C, A>::map ( const map & other ); // TODO

	
	template < class K, class T, class C, class A >
	ft::map<K, T, C, A>::~map ( void )
	{
		this->clear();
	}

	template < class K, class T, class C, class A >
	map & ft::map<K, T, C, A>::operator = ( const map & other ); // TODO

	template < class K, class T, class C, class A >
	A ft::map<K, T, C, A>::get_allocator ( void ) const
	{
		return allocator_type();
	}

	// Element accesses
	template < class K, class T, class C, class A >
	T & ft::map<K, T, C, A>::at ( const key_type & key );				// std::out_of_range // TODO

	template < class K, class T, class C, class A >
	const T & ft::map<K, T, C, A>::at ( const key_type & key ) const;	// std::out_of_range // TODO

	template < class K, class T, class C, class A >
	T & ft::map<K, T, C, A>::operator [] (const key_type & key ); // TODO

	// iterators
	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::begin ( void ); // TODO

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::const_iterator ft::map<K, T, C, A>::begin ( void ) const; // TODO

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::end ( void ); // TODO

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::const_iterator ft::map<K, T, C, A>::end ( void ) const; // TODO

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::reverse_iterator ft::map<K, T, C, A>::rbegin ( void ); // TODO

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::const_reverse_iterator ft::map<K, T, C, A>::rbegin ( void ) const; // TODO

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::reverse_iterator ft::map<K, T, C, A>::rend ( void ); // TODO

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::const_reverse_iterator ft::map<K, T, C, A>::rend ( void ) const; // TODO

	// Capacity
	template < class K, class T, class C, class A >
	bool ft::map<K, T, C, A>::empty ( void ) const
	{
		return this->_size == 0;
	}

	template < class K, class T, class C, class A >
	size_t ft::map<K, T, C, A>::size ( void ) const
	{
		return this->_size;
	}

	template < class K, class T, class C, class A >
	size_t ft::map<K, T, C, A>::max_size ( void ) const
	{
		size_type	size_max = std::numeric_limits<size_type>::max() / sizeof(value_type);
		size_type	diff_max = std::numeric_limits<difference_type>::max();
		return size_max < diff_max ? size_max : diff_max;
	}

	// Modifiers
	template < class K, class T, class C, class A >
	void ft::map<K, T, C, A>::clear ( void ); // TODO

	template < class K, class T, class C, class A >
	ft::pair<iterator, bool> ft::map<K, T, C, A>::insert ( const value_type & value ); // TODO

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::insert ( iterator pos, const value_type & value ); // TODO

	template < class K, class T, class C, class A >
	template < class InputIt >
	void ft::map<K, T, C, A>::insert ( InputIt first, InputIt last ); // TODO

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::erase ( iterator pos ); // TODO

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::erase ( iterator first, iterator last ); // TODO

	template < class K, class T, class C, class A >
	size_t ft::map<K, T, C, A>::erase ( const key_type & key ); // TODO

	template < class K, class T, class C, class A >
	void ft::map<K, T, C, A>::swap ( map & other ); // TODO

	// Lookup
	template < class K, class T, class C, class A >
	size_t ft::map<K, T, C, A>::count ( const key_type & key ) const; // TODO

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::find ( const key_type & key ); // TODO

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::const_iterator ft::map<K, T, C, A>::find ( const key_type & key ) const; // TODO

	template < class K, class T, class C, class A >
	ft::pair<iterator, iterator> ft::map<K, T, C, A>::equal_range ( const key_type & key ); // TODO

	template < class K, class T, class C, class A >
	ft::pair<const_iterator, const_iterator> ft::map<K, T, C, A>::equal_range ( const key_type & key ) const; // TODO

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::lower_bound ( const key_type & key ); // TODO

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::const_iterator ft::map<K, T, C, A>::lower_bound ( const key_type & key ) const; // TODO

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::upper_bound ( const key_type & key ); // TODO

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::const_iterator ft::map<K, T, C, A>::upper_bound ( const key_type & key ) const; // TODO

	// Observers
	typename ft::map<K, T, C, A>::key_compare ft::map<K, T, C, A>::key_comp ( void ) const
	{
		return key_compare();
	}

	typename ft::map<K, T, C, A>::value_compare ft::map<K, T, C, A>::value_comp ( void ) const
	{
		return value_compare();
	}

	// Non-member functions
	template < class K, class T, class C, class A >
	bool operator == ( const ft::map<K, T, C, A> & lhs, const ft::map<K, T, C, A> & rhs )
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(). rhs.begin()));
	}

	template < class K, class T, class C, class A >
	bool operator != ( const ft::map<K, T, C, A> & lhs, const ft::map<K, T, C, A> & rhs )
	{
		return !(lhs == rhs);
	}

	template < class K, class T, class C, class A >
	bool operator < ( const ft::map<K, T, C, A> & lhs, const ft::map<K, T, C, A> & rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template < class K, class T, class C, class A >
	bool operator > ( const ft::map<K, T, C, A> & lhs, const ft::map<K, T, C, A> & rhs )
	{
		return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
	}

	template < class K, class T, class C, class A >
	bool operator <= ( const ft::map<K, T, C, A> & lhs, const ft::map<K, T, C, A> & rhs )
	{
		return !(lhs > rhs);
	}

	template < class K, class T, class C, class A >
	bool operator >= ( const ft::map<K, T, C, A> & lhs, const ft::map<K, T, C, A> & rhs )
	{
		return !(lhs < rhs);
	}

	template < class K, class T, class C, class A >
	void ft::swap ( ft::map<K, T, C, A> & lhs, ft::map<K, T, C, A> & rhs )
	{
		lhs.swap(rhs);
	}

} // namespace ft

#endif // FT_CONTAINERS_MAP_TPP
