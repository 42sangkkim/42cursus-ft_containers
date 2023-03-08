#ifndef FT_CONTAINERS_SET_TPP
# define FT_CONTAINERS_SET_TPP

# include "./set.hpp"
# include "./equal.hpp"
# include "./lexicographical_compare.hpp"

template < class Key, class Compare, class Allocator >
ft::set<Key, Compare, Allocator>::set ( void )
	: _tree(value_comp(), allocator_type())
{}

template < class Key, class Compare, class Allocator >
ft::set<Key, Compare, Allocator>::set ( const Compare & comp, const Allocator & alloc )
	: _tree(comp, alloc)
{}

template < class Key, class Compare, class Allocator >
template < class InputIt >
ft::set<Key, Compare, Allocator>::set ( InputIt first, InputIt last, const Compare & comp , const Allocator & alloc )
	: _tree(comp, alloc)
{
	this->insert(first, last);
}

template < class Key, class Compare, class Allocator >
ft::set<Key, Compare, Allocator>::set ( const set & other )
	: _tree(key_compare(), allocator_type())
{
	this->insert(other.begin(), other.end());
}

template < class Key, class Compare, class Allocator >
ft::set<Key, Compare, Allocator>::~set ( void )
{
	this->clear();
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator> & ft::set<Key, Compare, Allocator>::operator = ( const set & other )
{
	this->clear();
	this->insert(other.begin(), other.end());
	return *this;
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::allocator_type ft::set<Key, Compare, Allocator>::get_allocator ( void ) const
{
	return allocator_type();
}

//		Iterators
template < class Key, class Compare, class Allocator >
typename ft::set_iterator<Key> ft::set<Key, Compare, Allocator>::begin ( void )
{
	return iterator(this->_tree.begin());
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::const_iterator ft::set<Key, Compare, Allocator>::begin ( void ) const
{
	return const_iterator(this->_tree.begin());
}

template < class Key, class Compare, class Allocator >
typename ft::set_iterator<Key> ft::set<Key, Compare, Allocator>::end ( void )
{
	return iterator(this->_tree.end());
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::const_iterator ft::set<Key, Compare, Allocator>::end ( void ) const
{
	return const_iterator(this->_tree.end());
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::reverse_iterator ft::set<Key, Compare, Allocator>::rbegin ( void )
{
	return reverse_iterator(this->_tree.end());
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::const_reverse_iterator ft::set<Key, Compare, Allocator>::rbegin ( void ) const
{
	return const_reverse_iterator(this->_tree.end());
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::reverse_iterator ft::set<Key, Compare, Allocator>::rend ( void )
{
	return reverse_iterator(this->_tree.begin());
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::const_reverse_iterator ft::set<Key, Compare, Allocator>::rend ( void ) const
{
	return const_reverse_iterator(this->_tree.begin());
}

//		Capacity
template < class Key, class Compare, class Allocator >
bool ft::set<Key, Compare, Allocator>::empty ( void ) const
{
	return (this->_tree.size() == 0);
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::size_type ft::set<Key, Compare, Allocator>::size ( void ) const
{
	return this->_tree.size();
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::size_type ft::set<Key, Compare, Allocator>::max_size ( void ) const
{
	return this->_tree.max_size();
}

//		Modifiers
template < class Key, class Compare, class Allocator >
void ft::set<Key, Compare, Allocator>::clear ( void )
{
	this->_tree.clear();
}

template < class Key, class Compare, class Allocator >
ft::pair<typename ft::set_iterator<Key>, bool> ft::set<Key, Compare, Allocator>::insert ( const value_type & value )
{
	ft::pair<node_type *, bool> result = this->_tree.insert(value);
	return (ft::make_pair(iterator(result.first), result.second));
}

template < class Key, class Compare, class Allocator >
typename ft::set_iterator<Key> ft::set<Key, Compare, Allocator>::insert ( iterator pos, const value_type & value )
{
	(void)pos;
	return (this->insert(value).first);
}

template < class Key, class Compare, class Allocator >
template < class InputIt >
void ft::set<Key, Compare, Allocator>::insert ( InputIt first, InputIt last )
{
	for (; first != last; ++first)
		this->insert(*first);
}

template < class Key, class Compare, class Allocator >
typename ft::set_iterator<Key> ft::set<Key, Compare, Allocator>::erase ( iterator pos )
{
	node_type * following = this->_tree.erase(const_cast<node_type *>(pos._cur));
	return iterator(following);
}

template < class Key, class Compare, class Allocator >
typename ft::set_iterator<Key> ft::set<Key, Compare, Allocator>::erase ( iterator first, iterator last )
{
	iterator iter = last;
	iter--;
	while (iter != first)
		this->erase(iter--);
	this->erase(iter--);
	if (this->size() != 0)
		++iter;
	return iter;
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::size_type ft::set<Key, Compare, Allocator>::erase ( const key_type & key )
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

template < class Key, class Compare, class Allocator >
void ft::set<Key, Compare, Allocator>::swap ( set & other )
{
	this->_tree.swap(other._tree);
}

//		Lookup
template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::size_type ft::set<Key, Compare, Allocator>::count ( const key_type & key ) const
{
	return (this->find(key) == this->end() ? 0 : 1);
}

template < class Key, class Compare, class Allocator >
typename ft::set_iterator<Key> ft::set<Key, Compare, Allocator>::find ( const key_type & key )
{
	return iterator(this->_tree.find(key));
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::const_iterator ft::set<Key, Compare, Allocator>::find ( const key_type & key ) const
{
	return const_iterator(this->_tree.find(key));
}

template < class Key, class Compare, class Allocator >
ft::pair<typename ft::set_iterator<Key>, typename ft::set_iterator<Key> > ft::set<Key, Compare, Allocator>::equal_range ( const key_type & key )
{
	return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
}

template < class Key, class Compare, class Allocator >
ft::pair<typename ft::set<Key, Compare, Allocator>::const_iterator, typename ft::set<Key, Compare, Allocator>::const_iterator> ft::set<Key, Compare, Allocator>::equal_range ( const key_type & key ) const
{
	return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
}

template < class Key, class Compare, class Allocator >
typename ft::set_iterator<Key> ft::set<Key, Compare, Allocator>::lower_bound ( const key_type & key )
{
	return iterator(this->_tree.lower_bound(key));
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::const_iterator ft::set<Key, Compare, Allocator>::lower_bound ( const key_type & key ) const
{
	return const_iterator(this->_tree.lower_bound(key));
}

template < class Key, class Compare, class Allocator >
typename ft::set_iterator<Key> ft::set<Key, Compare, Allocator>::upper_bound ( const key_type & key )
{
	return iterator(this->_tree.upper_bound(key));
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::const_iterator ft::set<Key, Compare, Allocator>::upper_bound ( const key_type & key ) const
{
	return const_iterator(this->_tree.upper_bound(key));
}

//		Observers
template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::key_compare ft::set<Key, Compare, Allocator>::key_comp ( void ) const
{
	return key_compare();
}

template < class Key, class Compare, class Allocator >
typename ft::set<Key, Compare, Allocator>::value_compare ft::set<Key, Compare, Allocator>::value_comp ( void ) const
{
	return value_compare();
}

// Non-member functions
template < class Key, class Compare, class Allocator >
bool ft::operator == ( const ft::set<Key, Compare, Allocator> & lhs, const ft::set<Key, Compare, Allocator> & rhs )
{
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template < class Key, class Compare, class Allocator >
bool ft::operator != ( const ft::set<Key, Compare, Allocator> & lhs, const ft::set<Key, Compare, Allocator> & rhs )
{
	return !(lhs == rhs);
}

template < class Key, class Compare, class Allocator >
bool ft::operator < ( const ft::set<Key, Compare, Allocator> & lhs, const ft::set<Key, Compare, Allocator> & rhs )
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template < class Key, class Compare, class Allocator >
bool ft::operator > ( const ft::set<Key, Compare, Allocator> & lhs, const ft::set<Key, Compare, Allocator> & rhs )
{
	return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}

template < class Key, class Compare, class Allocator >
bool ft::operator <= ( const ft::set<Key, Compare, Allocator> & lhs, const ft::set<Key, Compare, Allocator> & rhs )
{
	return !(lhs > rhs);
}

template < class Key, class Compare, class Allocator >
bool ft::operator >= ( const ft::set<Key, Compare, Allocator> & lhs, const ft::set<Key, Compare, Allocator> & rhs )
{
	return !(lhs < rhs);
}

template < class Key, class Compare, class Allocator >
void  ft::swap ( ft::set<Key, Compare, Allocator> & lhs, ft::set<Key, Compare, Allocator> & rhs )
{
	lhs.swap(rhs);
}

#endif // FT_CONTAINERS_SET_TPP