#ifndef FT_CONTAINERS_MAP_TPP
# define FT_CONTAINERS_MAP_TPP

# include "./map.hpp"

// ft::map::value_compare

namespace ft
{
	template < class Key, class T, class Compare, class Allocator >
	ft::map<Key, T, Compare, Allocator>::value_compare::value_compare ( Compare c )
		: comp(c)
	{}

	template < class Key, class T, class Compare, class Allocator >
	bool ft::map<Key, T, Compare, Allocator>::value_compare::operator () ( const value_type & lhs, const value_type) const
	{
		return comp(lhs.first, rhs.first);
	}
}

// ft::map

namespace ft
{
	template < class Key, class T, class Compare, class Allocator >
	ft::map<Key, T, Compare, Allocator>::map ( void )
		: _key_comp(), _alloc()
	{
		this->_map = tree_type(this->_key_comp, this->_alloc);
		this->_value_comp = value_compare(this->_key_comp);
	}

	template < class Key, class T, class Compare, class Allocator >
	ft::map<Key, T, Compare, Allocator>::map ( const key_compare & comp, const allocator_type & alloc = allocator_type() )
		: _key_comp(comp), _alloc(alloc)
	{
		this->_map = tree_type(this->_key_comp, this->_alloc);
		this->_value_comp = value_compare(this->_key_comp);
	}

	template < class Key, class T, class Compare, class Allocator >
	template < class InputIt >
	ft::map<Key, T, Compare, Allocator>::map ( InputIt first, InputIt last, const allocator_type & alloc = allocator_type() )
		: _key_comp(), _alloc(alloc)
	{
		this->_map = tree_type(this->_key_comp, this->_alloc);
		this->_value_comp = value_compare(this->_key_comp);
		this->insert(first, last);
	}

	template < class Key, class T, class Compare, class Allocator >
	ft::map<Key, T, Compare, Allocator>::map ( const map & other )
		: _key_comp(other._key_comp), _alloc(other._alloc)
	{
		this->_map = tree_type(this->_key_comp, this->_alloc);
		this->_value_comp = value_compare(this->_key_comp);
		this->insert(other.begin(), other.end());
	}

	template < class Key, class T, class Compare, class Allocator >
	ft::map<Key, T, Compare, Allocator>::~map ( void )
	{
		this->clear();
	}

	template < class Key, class T, class Compare, class Allocator >
	ft::map<Key, T, Compare, Allocator> & ft::map<Key, T, Compare, Allocator>::operator = ( const map & other )
	{
		this->clear();
		this->insert(other.begin(), other.end());
		return *this;
	}

	template < class Key, class T, class Compare, class Allocator >
	Allocator ft::map<Key, T, Compare, Allocator>::get_allocator ( void ) const
	{
		return this->_alloc;
	}

	// Element accesses
	template < class Key, class T, class Compare, class Allocator >
	T & ft::map<Key, T, Compare, Allocator>::at ( const key_type & key )
	{
		node_type * node = this->_tree.find(key);
		if (node == this->_tree.end())
			throw (std::out_of_range("ft::map"));
		return node->value.second;
	}

	template < class Key, class T, class Compare, class Allocator >
	const T & ft::map<Key, T, Compare, Allocator>::at ( const key_type & key ) const
	{
		node_type * node = this->_tree.find(key);
		if (node == this->_tree.end())
			throw (std::out_of_range("ft::map"));
		return node->value.second;
	}

	template < class Key, class T, class Compare, class Allocator >
	T & ft::map<Key, T, Compare, Allocator>::operator [] (const key_type & key )
	{
		node_type * node = this->insert(ft::make_pair(key, mapped_type())).first;
		return node->value.second;
	}

	// iterators
	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::begin ( void )
	{
		return iterator(this->_tree.begin());
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::begin ( void ) const
	{
		return const_iterator(this->_tree.begin());
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::end ( void )
	{
		return iterator(this->_tree.end());
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::end ( void ) const
	{
		return const_iterator(this->_tree.end());
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::reverse_iterator ft::map<Key, T, Compare, Allocator>::rbegin ( void )
	{
		return reverse_iterator(this->end());
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator ft::map<Key, T, Compare, Allocator>::rbegin ( void ) const
	{
		return const_reverse_iterator(this->end());
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::reverse_iterator ft::map<Key, T, Compare, Allocator>::rend ( void )
	{
		return reverse_iterator(this->begin());
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator ft::map<Key, T, Compare, Allocator>::rend ( void ) const
	{
		return const_reverse_iterator(this->begin());
	}

	// Capacity
	template < class Key, class T, class Compare, class Allocator >
	bool ft::map<Key, T, Compare, Allocator>::empty ( void ) const
	{
		return (this->_tree.size() == 0);
	}

	template < class Key, class T, class Compare, class Allocator >
	size_t ft::map<Key, T, Compare, Allocator>::size ( void ) const
	{
		return this->_tree.size();
	}

	template < class Key, class T, class Compare, class Allocator >
	size_t ft::map<Key, T, Compare, Allocator>::max_size ( void ) const
	{
		size_type	size_max = std::numeric_limits<size_type>::max() / sizeof(value_type);
		size_type	diff_max = std::numeric_limits<difference_type>::max();
		return size_max < diff_max ? size_max : diff_max;
	}

	// Modifiers
	template < class Key, class T, class Compare, class Allocator >
	void ft::map<Key, T, Compare, Allocator>::clear ( void )
	{
		this->_tree.clear();
	}

	template < class Key, class T, class Compare, class Allocator >
	ft::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, bool> ft::map<Key, T, Compare, Allocator>::insert ( const value_type & value )
	{
		iterator it = iterator(this->_tree.insert(value));
		if (it == this->end())
			return ft::pair<iterator, bool>(it, false);
		else
			return ft::pair<iterator, bool>(it, true);
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::insert ( iterator pos, const value_type & value )
	{
		(void)pos;
		return (this->_insert(value).first);
	}

	template < class Key, class T, class Compare, class Allocator >
	template < class InputIt >
	void ft::map<Key, T, Compare, Allocator>::insert ( InputIt first, InputIt last )
	{
		for (; first != last; ++first)
			this->insert(*first);
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::erase ( iterator pos )
	{
		// TODO
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::erase ( iterator first, iterator last )
	{
		// TODO
	}

	template < class Key, class T, class Compare, class Allocator >
	size_t ft::map<Key, T, Compare, Allocator>::erase ( const key_type & key )
	{
		// TODO
	}

	template < class Key, class T, class Compare, class Allocator >
	void ft::map<Key, T, Compare, Allocator>::swap ( map & other )
	{
		this->_tree.swap(other._tree);
	}

	// Lookup
	template < class Key, class T, class Compare, class Allocator >
	size_t ft::map<Key, T, Compare, Allocator>::count ( const key_type & key ) const
	{
		node_type * node = this->_tree.find(key);
		return (mode == this->_tree.end() ? 1 : 0);
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::find ( const key_type & key )
	{
		return iterator(this->_tree.find(key));
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::find ( const key_type & key ) const
	{
		return const_iterator(this->_tree.find(key));
	}

	template < class Key, class T, class Compare, class Allocator >
	ft::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, typename ft::map<Key, T, Compare, Allocator>::iterator> ft::map<Key, T, Compare, Allocator>::equal_range ( const key_type & key )
	{
		// TODO
	}

	template < class Key, class T, class Compare, class Allocator >
	ft::pair<typename ft::map<Key, T, Compare, Allocator>::const_iterator, typename ft::map<Key, T, Compare, Allocator>::const_iterator> ft::map<Key, T, Compare, Allocator>::equal_range ( const key_type & key ) const
	{
		// TODO
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::lower_bound ( const key_type & key )
	{
		return iterator(this->_tree.lower_bound(key));
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::lower_bound ( const key_type & key ) const
	{
		return const_iterator(this->_tree.lower_bound(key));
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::upper_bound ( const key_type & key )
	{
		return iterator(this->_tree.upper_bound(key));
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::upper_bound ( const key_type & key ) const
	{
		return const_iterator(this->_tree.upper_bound(key));
	}

	// Observers
	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::key_compare ft::map<Key, T, Compare, Allocator>::key_comp ( void ) const
	{
		return this->_key_comp;
	}

	template < class Key, class T, class Compare, class Allocator >
	typename ft::map<Key, T, Compare, Allocator>::value_compare ft::map<Key, T, Compare, Allocator>::value_comp ( void ) const
	{
		return this->_value_comp;
	}

	// Non-member functions
	template < class Key, class T, class Compare, class Allocator >
	bool operator == ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs )
	{
		struct compare
		{
			Compare _comp = lhs.value_compare;
			bool operator () (const ft::pair<const Key, T> & lhs, const ft::pair<const Key, T> & rhs) {
				return (!_comp(lhs, rhs) && !_comp(rhs, lhs) && lhs.second == rhs.second);
			}
		}
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(). rhs.begin(), compare));
	}

	template < class Key, class T, class Compare, class Allocator >
	bool operator != ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs )
	{
		return !(lhs == rhs);
	}

	template < class Key, class T, class Compare, class Allocator >
	bool operator < ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs )
	{
		struct compare
		{
			Compare _comp = lhs.value_compare;
			bool operator () (const ft::pair<const Key, T> & lhs, const ft::pair<const Key, T> & rhs) {
				if (_comp(lhs, rhs))
					return true;
				else if (_comp(rhs, lhs))
					return false;
				return lhs.second < rhs.second;
			}
		}
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), compare);
	}

	template < class Key, class T, class Compare, class Allocator >
	bool operator > ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs )
	{
		struct compare
		{
			Compare _comp = lhs.value_compare;
			bool operator () (const ft::pair<const Key, T> & lhs, const ft::pair<const Key, T> & rhs) {
				if (_comp(lhs, rhs))
					return true;
				else if (_comp(rhs, lhs))
					return false;
				return lhs.second < rhs.second;
			}
		}
		return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
	}

	template < class Key, class T, class Compare, class Allocator >
	bool operator <= ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs )
	{
		return !(lhs > rhs);
	}

	template < class Key, class T, class Compare, class Allocator >
	bool operator >= ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs )
	{
		return !(lhs < rhs);
	}

	template < class Key, class T, class Compare, class Allocator >
	void ft::swap ( ft::map<Key, T, Compare, Allocator> & lhs, ft::map<Key, T, Compare, Allocator> & rhs )
	{
		lhs.swap(rhs);
	}

} // namespace ft

#endif // FT_CONTAINERS_MAP_TPP
