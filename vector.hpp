#ifndef FT_CONTAINERS_VECTOR_HPP
# define FT_CONTAINERS_VECTOR_HPP

# include <memory>
# include "./reverse_iterator.hpp"
# include "./enable_if.hpp"
# include "./is_integral.hpp"

# include "./vector_iterator.hpp"

namespace ft
{

	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		// Member types
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef T &												reference;
		typedef const T &										const_reference;
		typedef typename Allocator::pointer						pointer;
		typedef typename Allocator::const_pointer				const_pointer;

		// Iterators
		typedef typename ft::vector_iterator<T>					iterator;
		typedef typename ft::const_vector_iterator<T>			const_iterator;
		typedef	typename ft::reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	protected:
		//	Member objects
		pointer													_data;
		allocator_type											_alloc;
		size_type												_size;
		size_type												_capacity;

	public:
		// Member functions

		vector ( void );
		explicit vector (const allocator_type & alloc );
		explicit vector ( size_type count, const_reference value = T(), const allocator_type & alloc = allocator_type() );
		template < class InputIt >
		vector ( typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first, InputIt last, const allocator_type & alloc = allocator_type() );
		vector ( const vector & other );
		~vector ( void );
		vector & operator = ( const vector & other );
		void assign ( size_type count, const_reference value );
		template < class InputIt >
		typename ft::enable_if<!ft::is_integral<InputIt>::value, void>::type assign ( InputIt first, InputIt last );
		allocator_type get_allocator ( void ) const;

		//		Element accesses
		reference at ( size_type pos );
		const_reference at ( size_type pos ) const;
		reference operator [] ( size_type pos );
		const_reference operator [] ( size_type pos ) const;
		reference front ( void );
		const_reference front ( void ) const;
		reference back ( void );
		const_reference back ( void ) const;
		pointer data ( void );
		const_pointer data ( void ) const;

		//		Iterators
		iterator begin ( void );
		const_iterator begin ( void ) const;
		iterator end ( void );
		const_iterator end ( void ) const;
		reverse_iterator rbegin ( void );
		const_reverse_iterator rbegin ( void ) const;
		reverse_iterator rend ( void );
		const_reverse_iterator rend ( void ) const;

		//		Capacity
		bool empty ( void ) const;
		size_type size ( void ) const;
		size_type max_size ( void ) const;
		void reserve ( size_type new_cap );
		size_type capacity ( void ) const;

		//		Modifiers
		void clear ( void );
		iterator insert ( const_iterator pos, const_reference value );
		iterator insert ( const_iterator pos, size_type count, const_reference value );
		template < class InputIt >
		typename ft::enable_if<!ft::is_integral<InputIt>::value, iterator>::type insert ( const_iterator pos, InputIt first, InputIt last );
		iterator erase ( iterator pos );
		iterator erase ( iterator first, iterator last );
		void push_back ( const_reference value );
		void pop_back ( void );
		void resize ( size_type count, value_type value = value_type() );
		void swap ( vector & other );

	}; // class vector

	// Non-member functions

	template < class T, class A >
	bool operator == ( const ft::vector<T, A> & lhs, const ft::vector<T, A> & rhs );
	template < class T, class A >
	bool operator != ( const ft::vector<T, A> & lhs, const ft::vector<T, A> & rhs );
	template < class T, class A >
	bool operator < ( const ft::vector<T, A> & lhs, const ft::vector<T, A> & rhs );
	template < class T, class A >
	bool operator > ( const ft::vector<T, A> & lhs, const ft::vector<T, A> & rhs );
	template < class T, class A >
	bool operator <= ( const ft::vector<T, A> & lhs, const ft::vector<T, A> & rhs );
	template < class T, class A >
	bool operator >= ( const ft::vector<T, A> & lhs, const ft::vector<T, A> & rhs );
	
} // namespace ft

# include "./vector.tpp"

#endif // FT_CONTAINERS_VECTOR_HPP
