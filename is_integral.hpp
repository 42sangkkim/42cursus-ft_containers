#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template < class T >
	struct ft_is_integral : std::integral_constant<bool, \
		std::is_same<T, bool>::value \
		|| std::is_same<T, char>::value \
		|| std::is_same<T, char16_t>::value \
		|| std::is_same<T, char32_t>::value \
		|| std::is_same<T, wchar_t>::value \
		|| std::is_same<T, signed char>::value \
		|| std::is_same<T, short int>::value \
		|| std::is_same<T, int>::value \
		|| std::is_same<T, long int>::value \
		|| std::is_same<T, long long int>::value \
		|| std::is_same<T, unsigned char>::value \
		|| std::is_same<T, unsigned short int>::value \
		|| std::is_same<T, unsigned int>::value \
		|| std::is_same<T, unsigned long int>::value \
		|| std::is_same<T, unsigned long long int>::value
	>{};
}

#endif//IS_INTEGRAL_HPP
