#ifndef FT_CONTAINERS_MAP_TPP
# define FT_CONTAINERS_MAP_TPP

# include "./map.hpp"
# include "./equal.hpp"
# include "./lexicographical_compare.hpp"

#include <iostream>
// ft::map::value_compare

namespace ft
{
	template < class K, class T, class C, class A >
	ft::map<K, T, C, A>::value_compare::value_compare ( C c )
		: comp(c)
	{}

	template < class K, class T, class C, class A >
	bool ft::map<K, T, C, A>::value_compare::operator () ( const value_type & lhs, const value_type & rhs ) const
	{
		return this->comp(lhs.first, rhs.first);
	}

} // namespace ft

// ft::map::iterator

namespace ft
{
	template < class K, class T, class C, class A >
	ft::map<K, T, C, A>::iterator::iterator ( void )
		: _cur(NULL)
	{}

	template < class K, class T, class C, class A >
	ft::map<K, T, C, A>::iterator::iterator ( const iterator & other )
		: _cur(other._cur)
	{}

	template < class K, class T, class C, class A >
	ft::map<K, T, C, A>::iterator::iterator ( node_type * cur )
		: _cur(cur)
	{}

	template < class K, class T, class C, class A >
	ft::map<K, T, C, A>::iterator::~iterator ( void )
	{}

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator & ft::map<K, T, C, A>::iterator::operator = ( const iterator & other )
	{
		this->_cur = other._cur;
		return *this;
	}

	template < class K, class T, class C, class A >
	bool ft::map<K, T, C, A>::iterator::operator == ( const iterator & other ) const
	{
		return (this->_cur == other._cur);
	}

	template < class K, class T, class C, class A >
	bool ft::map<K, T, C, A>::iterator::operator != ( const iterator & other ) const
	{
		return !(this->operator==(other));
	}

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::value_type & ft::map<K, T, C, A>::iterator::operator * ( void )
	{
		return this->_cur->value;
	}

	template < class K, class T, class C, class A >
	const typename ft::map<K, T, C, A>::value_type & ft::map<K, T, C, A>::iterator::operator * ( void ) const
	{
		return this->_cur->value;
	}

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::value_type * ft::map<K, T, C, A>::iterator::operator -> ( void )
	{
		return &this->_cur->value;
	}

	template < class K, class T, class C, class A >
	const typename ft::map<K, T, C, A>::value_type * ft::map<K, T, C, A>::iterator::operator -> ( void ) const
	{
		return &this->_cur->value;
	}

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator & ft::map<K, T, C, A>::iterator::operator ++ ( void )
	{
		this->_cur = this->_cur->next();
		return *this;
	}

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::iterator::operator ++ ( int n )
	{
		(void)n;
		iterator iter = *this;
		this->operator++();
		return iter;
	}

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator & ft::map<K, T, C, A>::iterator::operator -- ( void )
	{
		this->_cur = this->_cur->prev();
		return *this;
	}

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::iterator::operator -- ( int n )
	{
		(void)n;
		iterator iter = *this;
		this->operator--();
		return iter;
	}
} // namespace ft

// ft::map::const_iterator
namespace ft
{
	template < class K, class T, class C, class A >
	ft::map<K, T, C, A>::const_iterator::const_iterator ( void )
		: _cur(NULL)
	{}

	template < class K, class T, class C, class A >
	ft::map<K, T, C, A>::const_iterator::const_iterator ( const const_iterator & other )
		: _cur(other._cur)
	{}

	template < class K, class T, class C, class A >
	ft::map<K, T, C, A>::const_iterator::const_iterator ( const iterator & it )
		: _cur(it._cur)
	{}

	template < class K, class T, class C, class A >
	ft::map<K, T, C, A>::const_iterator::const_iterator ( const node_type * cur )
		: _cur(cur)
	{}

	template < class K, class T, class C, class A >
	ft::map<K, T, C, A>::const_iterator::~const_iterator ( void )
	{}

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::const_iterator & ft::map<K, T, C, A>::const_iterator::operator = ( const const_iterator & other )
	{
		this->_cur = other._cur;
		return *this;
	}

	template < class K, class T, class C, class A >
	bool ft::map<K, T, C, A>::const_iterator::operator == ( const const_iterator & other ) const
	{
		return (this->_cur == other._cur);
	}

	template < class K, class T, class C, class A >
	bool ft::map<K, T, C, A>::const_iterator::operator != ( const const_iterator & other ) const
	{
		return !(this->operator==(other));
	}

	template < class K, class T, class C, class A >
	const typename ft::map<K, T, C, A>::value_type & ft::map<K, T, C, A>::const_iterator::operator * ( void ) const
	{
		return this->_cur->value;
	}

	template < class K, class T, class C, class A >
	const typename ft::map<K, T, C, A>::value_type * ft::map<K, T, C, A>::const_iterator::operator -> ( void ) const
	{
		return &this->_cur->value;
	}

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::const_iterator & ft::map<K, T, C, A>::const_iterator::operator ++ ( void )
	{
		this->_cur = this->_cur->next();
		return *this;
	}

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::const_iterator ft::map<K, T, C, A>::const_iterator::operator ++ ( int n )
	{
		(void)n;
		const_iterator iter = *this;
		this->operator++();
		return iter;
	}

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::const_iterator & ft::map<K, T, C, A>::const_iterator::operator -- ( void )
	{
		this->_cur = this->_cur->prev();
		return *this;
	}

	template < class K, class T, class C, class A >
	typename ft::map<K, T, C, A>::const_iterator ft::map<K, T, C, A>::const_iterator::operator -- ( int n )
	{
		(void)n;
		const_iterator iter = *this;
		this->operator--();
		return iter;
	}
} // namespace ft

// ft::map

namespace ft
{
	template < class K ,class T, class C, class A >
	ft::map<K, T, C, A>::map ( void )
		: _key_comp(), _alloc(), _value_comp(this->_key_comp), _tree(this->_key_comp, this->_alloc)
	{}

	template < class K ,class T, class C, class A >
	ft::map<K, T, C, A>::map ( const key_compare & comp, const allocator_type & alloc )
		: _key_comp(comp), _alloc(alloc), _value_comp(this->_key_comp), _tree(this->_key_comp, this->_alloc)
	{}

	template < class K ,class T, class C, class A >
	template < class InputIt >
	ft::map<K, T, C, A>::map ( InputIt first, InputIt last, const allocator_type & alloc )
		: _key_comp(), _alloc(alloc), _value_comp(this->_key_comp), _tree(this->_key_comp, this->_alloc)
	{
		this->insert(first, last);
	}

	template < class K ,class T, class C, class A >
	ft::map<K, T, C, A>::map ( const map & other )
		: _key_comp(other._key_comp), _alloc(other._alloc), _value_comp(this->_key_comp), _tree(this->_key_comp, this->_alloc)
	{
		this->insert(other.begin(), other.end());
	}

	template < class K ,class T, class C, class A >
	ft::map<K, T, C, A>::~map ( void )
	{
		this->clear();
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A> & ft::map<K, T, C, A>::operator = ( const map & other )
	{
		this->clear();
		this->insert(other.begin(), other.end());
		return *this;
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::allocator_type ft::map<K, T, C, A>::get_allocator ( void ) const
	{
		return this->_alloc;
	}

	// Element accesses
	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::mapped_type & ft::map<K, T, C, A>::at ( const key_type & key )
	{
		iterator iter = this->find(key);
		if (iter == this->end())
			throw (std::out_of_range("ft::map"));
		return iter->second;
	}

	template < class K ,class T, class C, class A >
	const typename ft::map<K, T, C, A>::mapped_type & ft::map<K, T, C, A>::at ( const key_type & key ) const
	{
		const_iterator iter = this->find(key);
		if (iter == this->end())
			throw (std::out_of_range("ft::map"));
		return iter->second;
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::mapped_type & ft::map<K, T, C, A>::operator [] ( const key_type & key )
	{
		iterator iter = this->insert(ft::make_pair(key, mapped_type())).first;
		return iter->second;
	}

	// Iterators
	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::begin ( void )
	{
		return iterator(this->_tree.begin());
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::const_iterator ft::map<K, T, C, A>::begin ( void ) const
	{
		return const_iterator(this->_tree.begin());
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::end ( void )
	{
		return iterator(this->_tree.end());
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::const_iterator ft::map<K, T, C, A>::end ( void ) const
	{
		return const_iterator(this->_tree.end());
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::reverse_iterator ft::map<K, T, C, A>::rbegin ( void )
	{
		return reverse_iterator(this->end());
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::const_reverse_iterator ft::map<K, T, C, A>::rbegin ( void ) const
	{
		return const_reverse_iterator(this->end());
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::reverse_iterator ft::map<K, T, C, A>::rend ( void )
	{
		return reverse_iterator (this->begin());
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::const_reverse_iterator ft::map<K, T, C, A>::rend ( void ) const
	{
		return const_reverse_iterator(this->begin());
	}

	// Capacity
	template < class K ,class T, class C, class A >
	bool ft::map<K, T, C, A>::empty ( void ) const
	{
		return (this->_tree.size() == 0);
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::size_type ft::map<K, T, C, A>::size ( void ) const
	{
		return this->_tree.size();
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::size_type ft::map<K, T, C, A>::max_size ( void ) const
	{
		size_type	size_max = std::numeric_limits<size_type>::max() / sizeof(node_type);
		size_type	diff_max = std::numeric_limits<difference_type>::max();
		return (size_max < diff_max ? size_max : diff_max);
	}

	// Modifiers
	template < class K ,class T, class C, class A >
	void ft::map<K, T, C, A>::clear ( void )
	{
		this->_tree.clear();
	}

	template < class K ,class T, class C, class A >
	ft::pair<typename ft::map<K, T, C, A>::iterator, bool> ft::map<K, T, C, A>::insert ( const value_type & value )
	{
		ft::pair<node_type *, bool> result = this->_tree.insert(value);
		return (ft::make_pair(iterator(result.first), result.second));
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::insert ( iterator pos, const value_type & value )
	{
		(void)pos;
		return (this->insert(value).first);
	}

	template < class K ,class T, class C, class A >
	template < class InputIt >
	void ft::map<K, T, C, A>::insert ( InputIt first, InputIt last )
	{
		for (; first != last; ++first)
			this->insert(*first);
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::erase ( iterator pos )
	{
		node_type * following = this->_tree.erase(pos._cur);
		return iterator(following);
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::erase ( iterator first, iterator last )
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

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::size_type ft::map<K, T, C, A>::erase ( const key_type & key )
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

	template < class K ,class T, class C, class A >
	void ft::map<K, T, C, A>::swap ( map & other )
	{
		this->_tree.swap(other._tree);
	}

	// Lookup
	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::size_type ft::map<K, T, C, A>::count ( const key_type & key ) const
	{
		return (this->find(key) == this->end() ? 0 : 1);
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::find ( const key_type & key )
	{
		return iterator(this->_tree.find(key));
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::const_iterator ft::map<K, T, C, A>::find  ( const key_type & key ) const
	{
		return const_iterator(this->_tree.find(key));
	}

	template < class K ,class T, class C, class A >
	ft::pair<typename ft::map<K, T, C, A>::iterator, typename ft::map<K, T, C, A>::iterator> ft::map<K, T, C, A>::equal_range ( const key_type & key )
	{
		return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
	}

	template < class K ,class T, class C, class A >
	ft::pair<typename ft::map<K, T, C, A>::const_iterator, typename ft::map<K, T, C, A>::const_iterator> ft::map<K, T, C, A>::equal_range ( const key_type & key ) const
	{
		return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::lower_bound ( const key_type & key )
	{
		return iterator(this->_tree.lower_bound(key));
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::const_iterator ft::map<K, T, C, A>::lower_bound ( const key_type & key ) const
	{
		return const_iterator(this->_tree.lower_bound(key));
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::iterator ft::map<K, T, C, A>::upper_bound ( const key_type & key )
	{
		return iterator(this->_tree.upper_bound(key));
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::const_iterator ft::map<K, T, C, A>::upper_bound ( const key_type & key ) const
	{
		return const_iterator(this->_tree.upper_bound(key));
	}

	// Observers
	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::key_compare ft::map<K, T, C, A>::key_comp ( void ) const
	{
		return this->_key_comp;
	}

	template < class K ,class T, class C, class A >
	typename ft::map<K, T, C, A>::value_compare ft::map<K, T, C, A>::value_comp ( void ) const
	{
		return this->_value_comp;
	}

	// Non-member functions
	template < class Key, class T, class Compare, class Allocator >
	bool operator == ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs )
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template < class Key, class T, class Compare, class Allocator >
	bool operator != ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs )
	{
		return !(lhs == rhs);
	}
 
	template < class Key, class T, class Compare, class Allocator >
	bool operator < ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template < class Key, class T, class Compare, class Allocator >
	bool operator > ( const ft::map<Key, T, Compare, Allocator> & lhs, const ft::map<Key, T, Compare, Allocator> & rhs )
	{
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
	void swap ( ft::map<Key, T, Compare, Allocator> & lhs, ft::map<Key, T, Compare, Allocator> & rhs )
	{
		lhs.swap(rhs);
	}

} // namespace ft

#endif // FT_CONTAINERS_MAP_TPP
