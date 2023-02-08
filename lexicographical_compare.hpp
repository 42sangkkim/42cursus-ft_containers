#ifndef FT_CONATAINERS_LEXICOGRAPHICLA_COMPARE_HPP
# define FT_CONATAINERS_LEXICOGRAPHICLA_COMPARE_HPP

namespace ft
{
	template < class InputIt1, class InputIt2 >
	bool lexicographical_compare ( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 )
	{
		while (true)
		{
			if (first2 == last2)
				return false;
			else if (first1 == last1)
				return true;
			else if (*first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			first1++;
			first2++;
		}
	}

	template < class InputIt1, class InputIt2, class Compare >
	bool lexicographical_compare ( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp )
	{
		while (true)
		{
			if (first2 == last2)
				return false;
			else if (first1 == last1)
				return true;
			else if (comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			first1++;
			first2++;
		}
	}


} // namespace ft

#endif // FT_CONATAINERS_LEXICOGRAPHICLA_COMPARE_HPP
