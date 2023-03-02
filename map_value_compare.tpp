#ifndef FT_CONTAINERS_MAP_VALUE_COMPARE_TPP
# define FT_CONTAINERS_MAP_VALUE_COMPARE_TPP

# include "./map_value_compare.hpp"

template < class Key, class T, class Compare, class Allocator >
ft::map<Key, T, Compare, Allocator>::value_compare::value_compare ( Compare c )
	: comp(c)
{}

template < class Key, class T, class Compare, class Allocator >
bool ft::map<Key, T, Compare, Allocator>::value_compare::operator () ( const value_type & lhs, const value_type & rhs ) const
{
	return this->comp(lhs.first, rhs.first);
}

#endif // FT_CONTAINERS_MAP_VALUE_COMPARE_TPP