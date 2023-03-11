#ifndef FT_CONTAINERS_MAP_TPP
# define FT_CONTAINERS_MAP_TPP

# include "./map.hpp"
# include "./equal.hpp"
# include "./lexicographical_compare.hpp"

template < class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::map ( void )
	: _tree(value_comp(), allocator_type())
{}

template < class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::map ( const key_compare & comp, const allocator_type & alloc )
	: _tree(value_compare(comp), alloc)
{}

template < class Key, class T, class Compare, class Allocator>
template < class InputIt >
ft::map<Key, T, Compare, Allocator>::map ( InputIt first, InputIt last, const key_compare & comp, const allocator_type & alloc )
	: _tree(value_compare(key_compare(comp)), alloc)
{
	this->insert(first, last);
}

template < class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::map ( const map & other )
	: _tree(value_compare(key_compare()), allocator_type())
{
	this->insert(other.begin(), other.end());
}

template < class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::~map ( void )
{
	this->clear();
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator> & ft::map<Key, T, Compare, Allocator>::operator = ( const map & other )
{
	this->clear();
	this->insert(other.begin(), other.end());
	return *this;
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::allocator_type ft::map<Key, T, Compare, Allocator>::get_allocator ( void ) const
{
	return allocator_type();
}

// Element accesses
template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::mapped_type & ft::map<Key, T, Compare, Allocator>::at ( const key_type & key )
{
	iterator iter = this->find(key);
	if (iter == this->end())
		throw (std::out_of_range("ft::map"));
	return iter->second;
}

template < class Key, class T, class Compare, class Allocator>
const typename ft::map<Key, T, Compare, Allocator>::mapped_type & ft::map<Key, T, Compare, Allocator>::at ( const key_type & key ) const
{
	const_iterator iter = this->find(key);
	if (iter == this->end())
		throw (std::out_of_range("ft::map"));
	return iter->second;
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::mapped_type & ft::map<Key, T, Compare, Allocator>::operator [] ( const key_type & key )
{
	iterator iter = this->insert(ft::make_pair(key, mapped_type())).first;
	return iter->second;
}

// Iterators
template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::begin ( void )
{
	return iterator(this->_tree.begin());
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::begin ( void ) const
{
	return const_iterator(this->_tree.begin());
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::end ( void )
{
	return iterator(this->_tree.end());
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::end ( void ) const
{
	return const_iterator(this->_tree.end());
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::reverse_iterator ft::map<Key, T, Compare, Allocator>::rbegin ( void )
{
	return reverse_iterator(this->end());
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator ft::map<Key, T, Compare, Allocator>::rbegin ( void ) const
{
	return const_reverse_iterator(this->end());
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::reverse_iterator ft::map<Key, T, Compare, Allocator>::rend ( void )
{
	return reverse_iterator (this->begin());
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator ft::map<Key, T, Compare, Allocator>::rend ( void ) const
{
	return const_reverse_iterator(this->begin());
}

// Capacity
template < class Key, class T, class Compare, class Allocator>
bool ft::map<Key, T, Compare, Allocator>::empty ( void ) const
{
	return (this->_tree.size() == 0);
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type ft::map<Key, T, Compare, Allocator>::size ( void ) const
{
	return this->_tree.size();
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type ft::map<Key, T, Compare, Allocator>::max_size ( void ) const
{
	return this->_tree.max_size();
}

// Modifiers
template < class Key, class T, class Compare, class Allocator>
void ft::map<Key, T, Compare, Allocator>::clear ( void )
{
	this->_tree.clear();
}

template < class Key, class T, class Compare, class Allocator>
ft::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, bool> ft::map<Key, T, Compare, Allocator>::insert ( const value_type & value )
{
	ft::pair<node_type *, bool> result = this->_tree.insert(value);
	return (ft::make_pair(iterator(result.first), result.second));
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::insert ( iterator pos, const value_type & value )
{
	(void)pos;
	return (this->insert(value).first);
}

template < class Key, class T, class Compare, class Allocator>
template < class InputIt >
void ft::map<Key, T, Compare, Allocator>::insert ( InputIt first, InputIt last )
{
	for (; first != last; ++first)
		this->insert(*first);
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::erase ( iterator pos )
{
	node_type * following = this->_tree.erase(pos._cur);
	return iterator(following);
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::erase ( iterator first, iterator last )
{
	while (first != last)
		first = erase(first);
	return last;
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type ft::map<Key, T, Compare, Allocator>::erase ( const key_type & key )
{
	iterator iter = this->find(key);
	if (iter == this->end())
		return 0;
	else
	{
		this->erase(iter);
		return 1;
	}
}

template < class Key, class T, class Compare, class Allocator>
void ft::map<Key, T, Compare, Allocator>::swap ( map & other )
{
	this->_tree.swap(other._tree);
}

// Lookup
template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type ft::map<Key, T, Compare, Allocator>::count ( const key_type & key ) const
{
	return (this->find(key) == this->end() ? 0 : 1);
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::find ( const key_type & key )
{
	return iterator(this->_tree.find(value_type(key, mapped_type())));
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::find  ( const key_type & key ) const
{
	return const_iterator(this->_tree.find(value_type(key, mapped_type())));
}

template < class Key, class T, class Compare, class Allocator>
ft::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, typename ft::map<Key, T, Compare, Allocator>::iterator> ft::map<Key, T, Compare, Allocator>::equal_range ( const key_type & key )
{
	return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
}

template < class Key, class T, class Compare, class Allocator>
ft::pair<typename ft::map<Key, T, Compare, Allocator>::const_iterator, typename ft::map<Key, T, Compare, Allocator>::const_iterator> ft::map<Key, T, Compare, Allocator>::equal_range ( const key_type & key ) const
{
	return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::lower_bound ( const key_type & key )
{
	return iterator(this->_tree.lower_bound(value_type(key, mapped_type())));
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::lower_bound ( const key_type & key ) const
{
	return const_iterator(this->_tree.lower_bound(value_type(key, mapped_type())));
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::upper_bound ( const key_type & key )
{
	return iterator(this->_tree.upper_bound(value_type(key, mapped_type())));
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::upper_bound ( const key_type & key ) const
{
	return const_iterator(this->_tree.upper_bound(value_type(key, mapped_type())));
}

// Observers
template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::key_compare ft::map<Key, T, Compare, Allocator>::key_comp ( void ) const
{
	return key_compare();
}

template < class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::value_compare ft::map<Key, T, Compare, Allocator>::value_comp ( void ) const
{
	return value_compare(key_compare());
}

// Non-member functions
template < class Key, class T, class Compare, class Allocator >
bool ft::operator == ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs )
{
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template < class Key, class T, class Compare, class Allocator >
bool ft::operator != ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs )
{
	return !(lhs == rhs);
}

template < class Key, class T, class Compare, class Allocator >
bool ft::operator < ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs )
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template < class Key, class T, class Compare, class Allocator >
bool ft::operator > ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs )
{
	return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}

template < class Key, class T, class Compare, class Allocator >
bool ft::operator <= ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs )
{
	return !(lhs > rhs);
}

template < class Key, class T, class Compare, class Allocator >
bool ft::operator >= ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs )
{
	return !(lhs < rhs);
}

namespace std
{
	template < class Key, class T, class Compare, class Allocator >
	void swap ( ft::map<Key, T, Compare, Allocator> & lhs, ft::map<Key, T, Compare, Allocator> & rhs )
	{
		lhs.swap(rhs);
	}
}

// ft::map::value_compare

template < class Key, class T, class Compare, class Allocator >
ft::map<Key, T, Compare, Allocator>::value_compare::value_compare ( Compare c )
	: comp(c)
{}

template < class Key, class T, class Compare, class Allocator >
bool ft::map<Key, T, Compare, Allocator>::value_compare::operator () ( const value_type & lhs, const value_type & rhs ) const
{
	return this->comp(lhs.first, rhs.first);
}

#endif // FT_CONTAINERS_MAP_TPP
