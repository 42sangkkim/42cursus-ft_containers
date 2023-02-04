#ifndef FT_LEXICOGRAPHICAL_COMPARE_HPP
# define FT_LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{
	template < \
		class InputIterator1, \
		class InputIterator2 \
	>
	bool lexicographical_compare (\
		InputIterator1	first1, \
		InputIterator1	last1, \
		InputIterator2	first2, \
		InputIterator2	last2 \
	)
	{
		while (true)
		{
			if (first1 == last1)
				return true;
			else if (first2 == last2)
				return false;
			else if (*first1 < *first2)
				return true;
			else if (*first > *first2)
				return false;
			first1++;
			first2++;
		}
		return false;
	}

	template < \
		class InputIterator1, \
		class InputIterator2, \
		class Compare \
	>
	bool lexicographical_compare (\
		InputIterator1	first1, \
		InputIterator1	last1, \
		InputIterator2	first2, \
		InputIterator2	last2, \
		Compare			comp \
	){
		while (true)
		{
			if (first1 == last1)
				return true;
			if (first2 == last2)
				return false;
			if (comp(*first1, *first2))
				return true;
			else if (comp(*first2 > *first1))
				return false;
			first1++;
			first2++;
		}
		return false;
		return true;
	}

}; // namespace  ft

#endif // FT_LEXICOGRAPHICAL_COMPARE_HPP
