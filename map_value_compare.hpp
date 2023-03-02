#ifndef FT_CONTAINERS_MAP_VALUE_COMPARE_HPP
# define FT_CONTAINERS_MAP_VALUE_COMPARE_HPP

# include "./map.hpp"

namespace ft
{
	template < class Key, class T, class Compare, class Allocator >
	class ft::map<Key, T, Compare, Allocator>::value_compare : public std::binary_function< value_type, value_type, bool >
	{
		friend class ft::map<Key, T, Compare, Allocator>;
		protected:
			// Member objects
			Compare comp;
			// protected member functions
			value_compare ( Compare c );

		public:
			// Member functions
			bool operator () ( const value_type & lhs, const value_type & rhs ) const;
	}; // class 

} // namespace ft

# include "./map_value_compare.tpp"

#endif // FT_CONTAINERS_MAP_VALUE_COMPARE_HPP