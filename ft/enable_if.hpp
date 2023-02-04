#ifndef FT_ENABLE_IF_HPP
# define FT_ENABLE_IF_HPP

namespace ft
{
	template < \
		bool Cond, \
		typename T = void \
	>
	struct enable_if;

	template < \
		typename T \
	>
	struct enable_if <true, T>
	{
		typedef	T				type;
	}; // struct enable_if <true, T>

}; // namespace ft

#endif // FT_ENABLE_IF_HPP
