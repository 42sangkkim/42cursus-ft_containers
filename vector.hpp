#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		// Member types

		typedef T									value_type;
		typedef Alloc								allocator_type;
		typedef allocator_type::reference			reference;
		typedef allocator_type::const_reference		const_reference;
		typedef allocator_type::pointer				pointer;
		typedef allocator_type::const_pointer		const_pointer;
		// typedef 									iterator;
		// typedef 									const_iterator;
		// typedef 									reverse_iterator;
		// typedef 									const_reverse_iterator;
		// typedef iterator_traits<iterator>::difference_type	difference_type;
		// typedef 									size_type;

		class iterator : public std::iterator< std::random_access_iterator_tag, T >
		{
			public:
			// Constructor
				random_access_iterator ( void );
				random_access_iterator ( const random_access_iterator & other );
				random_access_iterator & operator= ( const random_access_iterator & other);
			
			// Destructor
				~random_access_iterator ( void );

			// Copy assignment
				random_access_iterator & operator= ( const random_access_iterator & other);

			// Compare
				bool operator== ( const random_access_iterator & other ) const;
				bool operator!= ( const random_access_iterator & other ) const;

			// rvalue
			*a;
			a->m;

			// lvalue
			*a = t;

			// Increment
				random_access_iterator operator++ ( void ); // prefix
				random_access_iterator operator++ ( int );  // postfix

			// Decrement
				random_access_iterator operator-- ( void ); // prefix
				random_access_iterator operator-- ( int );  // postfix

			// Arithmetic operator
				random_access_iterator operator+ ( size_type n );
				random_access_iterator operator- ( size_type n );

			// Compound assignment operator
				+=;
				-=;

			// Dereference operator
				reference operator[] ( size_type n );
				const_reference operator[] ( size_type n ) const;
		}


		public:
		// Constructor
			explicit vector ( \
				const allocator_type & alloc = allocator_type() \
			);
			explicit vector ( \
				size_type n, \
				const value_type & val = value_type(), \
				const allocator_type & alloc = allocator_type() \
			);
			template < class InputIterator >
			vector ( \
				InputIterator first, \
				InputIterator last, \
				const allocator_type & alloc = allocator_type() \
			);
			vector ( \
				const vector & x \
			);

		// Destructor
			~vector ( void );

		// Copy assignment
			vector & operator= ( const vector & other );

		// Iterators:
			iterator begin ( void );
			const_iterator begin ( void ) const;
			iterator end ( void );
			const_iterator end ( void ) const;
			reverse_iterator rbegin ( void );
			const_reverse_iterator rbegin ( void ) const;
			reverse_iterator rend ( void );
			const_reverse_iterator rend ( void ) const;
			// const_iterator cbegin ( void ) const noexcept;						C++11
			// const_iterator cend ( void ) const noexcept;							C++11
			// const_reverse_iterator crbegin ( void ) const noexcept;				C++11
			// const_reverse_iterator crend ( void ) const noexcept;				C++11

			// Capacity:
			size_type size ( void ) const;
			size_type max_size ( void ) const;
			void resize ( size_type n, value_type val = value_type());
			size_type capacity ( void ) const;
			bool empty ( void ) const;
			void reserve ( size_type n );
			// void shrink_to_fit ( void );											C++11

			// Element access:
			reference operator[] ( size_type n );
			const_reference operator[] ( size_type n ) const;
			reference at ( size_type n );
			const_reference at ( size_type n ) const;
			reference front ( void );
			const_reference front ( void ) const;
			reference back ( void );
			const_reference back ( void ) const;
			value_type * data ( void );
			const value_type * data ( void ) const;

			// Modifiers:
			template < class InputIterator >
			void assign ( InputIterator first, InputIterator last );
			void assign (size_type n, const value_type & val );
			void push_back ( const value_type & val );
			void pop_back ( void );
			iterator insert ( iterator position, const value_type & val );
			void insert ( iterator position, size_type n, const value_type & val );
			template < class InputIterator >
			void insert ( iterator position, InputIterator first, InputIterator last );
			iterator erase ( iterator position );
			iterator erase ( iterator first, iterator last );
			void swap ( vector & x );
			void clear ( void );
			// template < class... Args >
			// iterator emplace ( const_iterator position, Args &&... args);		C++11
			// template < class... Args >
			// iterator emplace_back ( const_iterator position, Args &&... args);	C++11


		// Allocator:
			allocator_type get_allocator ( void ) const;
	}; // class vector

	// Non member function overloads

	// Relational operators
	template < class T, class Alloc >
	bool operator== ( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs );
	template < class T, class Alloc >
	bool operator!= ( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs );
	template < class T, class Alloc >
	bool operator< ( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs );
	template < class T, class Alloc >
	bool operator<= ( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs );
	template < class T, class Alloc >
	bool operator> ( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs );
	template < class T, class Alloc >
	bool operator>= ( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs );

	template < class T, class Alloc >
	void swap ( vector<T, Alloc> & x, vector<T, Alloc> & y );
} // namespace ft

#endif//VECTOR_HPP
