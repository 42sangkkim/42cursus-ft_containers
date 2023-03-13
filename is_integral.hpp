#ifndef FT_CONTAINERS_IS_INTEGRAL_HPP
# define FT_CONTAINERS_IS_INTEGRAL_HPP

namespace ft
{
	template < class T >
	struct is_integral {
		typedef bool				value_type;

		static const value_type value = false;

		operator bool ( void ) const { return value; }
		bool operator () ( void ) const { return value; }
	};

	template < class T >
	struct is_integral < const T > { static const bool value = ft::is_integral<T>::value; };

	template <>
	struct is_integral<bool> { static const bool value = true; };
	template <>
	struct is_integral<char> { static const bool value = true; };
	template <>
	struct is_integral<char16_t> { static const bool value = true; };
	template <>
	struct is_integral<char32_t> { static const bool value = true; };
	template <>
	struct is_integral<wchar_t> { static const bool value = true; };
	template <>
	struct is_integral<short> { static const bool value = true; };
	template <>
	struct is_integral<int> { static const bool value = true; };
	template <>
	struct is_integral<long> { static const bool value = true; };
	template <>
	struct is_integral<long long> { static const bool value = true; };

}

#endif // FT_CONTAINERS_IS_INTEGRAL_HPP
