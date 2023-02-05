#ifndef FT_CONTAINERS_VECTOR_VECTOR_H_
# define FT_CONTAINERS_VECTOR_VECTOR_H_

# include <memory>

namespace ft
{

	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		// Member types
		typedef T										value_type;
		typedef Allocator								allocator_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef T &										reference;
		typedef const T &								const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;

		// Iterators
//		typedef											iterator;
//		typedef	ft::reverse_iterator<iterator>			reverse_iterator;
//		typedef											const_iterator;
//		typedef ft::reverse_iterator<const_iteraotr>	const_reverse_iterator;

	protected:
		//	Member objects
		pointer											_data;
		allocator_type									_alloc;
		size_type										_size;
		size_type										_capacity;

	public:
		// Member functions

		//		Constructor
		vector ( void );
		explicit vector (const allocator_type & alloc );
		explicit vector ( size_type count, const_reference value = T(), const allocator_type & alloc = allocator_type() );
		template < class InputIt >
		vector ( InputIt first, InputIt last, const cllocator_type & alloc = allocator_type() );
		vector ( const vector & other );

		//		Destructor
		~vector ( void );

		//		Assignment operator
		vector & operator = ( const vector & other );
		void assign ( size_type count, const_reference value );
//		template < class InputIt >
//		void assign ( InputIt first, InputIt last );

		//		Get allocator
//		allocator_type get_allocator ( void ) const;

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
//		iterator begin ( void );
//		const_iterator begin ( void ) const;
//		iterator end ( void );
//		const_iterator end ( void ) const;
//		reverse_iterator rbegin ( void );
//		const_reverse_iterator rbegin ( void ) const;
//		reverse_iterator rend ( void );
//		const_reverse_iterator rend ( void ) const;

		//		Capacity
		bool empty ( void ) const;
		size_type size ( void ) const;
//		size_type max_size ( void ) const;
		void reserve ( size_type new_cap );
		size_type capacity ( void ) const;

		//		Modifiers
		void clear ( void );
//		iterator insert ( const_iterator pos, const_reference value );
//		iterator insert ( const_iterator pos, size_type count, const_reference value );
//		template < class InputIt >
//		iterator insert ( const_iterator pos, InputIt first, InputIt last );
//		iterator erase ( iterator pos );
//		iterator erase ( iterator first, iteratoe last );
		void push_back ( const_reference value );
		void pop_back ( void );
		void resize ( size_type count, value_type value = value_type() );
//		void swap ( vector & other );

	}; // class vector






	// Define functions

	template < class T, class A >
	vector<T, A>::vector ( void )
		: _data(NULL), _alloc(allocator_type()), _size(0), _capacity(0)
	{

	}

	template < class T, class A >
	vector<T, A>::vector (const allocator_type & alloc )
		: _data(NULL), _alloc(alloc), _size(0), _capacity(0)
	{

	}

	template < class T, class A >
	vector<T, A>::vector ( size_type count, const_reference value, const allocator_type & alloc )
		: _data(NULL), _alloc(alloc), _size(0), _capacity(0)
	{
		this->reserve(count);
		for (; this->_size != count; this->_size++)
			this->_data[this->_size] = value;
	}

	template < class T, class A, class It >
	vector<T, A>::vector ( It first, It last, const cllocator_type & alloc )
		: _data(NULL), _alloc(alloc), _size(0), _capacity(0)
	{
		size_type	count = 0;

		for (It	it = first; it != end; it++)
			count++;

		this->reserve(count);
		for (this->_size < count && first != last; this->_size++, first++)
			this->_data[this->_size] = *first;
	}

	template < class T, class A >
	vector<T, A>::vector ( const vector & other )
		: _data(NULL), _alloc(other._alloc), _size(0), _capacity(0)
	{
		*this = other;
	}

	template < class T, class A >
	vector<T, A>::~vector ( void )
	{
		this->clear();
		this->_alloc.deallocate(this->_data, this->_capacity);
	}

	template < class T, class A >
	vector<T, A> & vector<T, A>::operator = ( const vector & other )
	{
		if (this == &other)
			return *this;
		this->clear();
		this->reserve(other._size);
		for (; this->_size != other._size; this->_size++)
			this->_data[this->_size] = other._data[this->_size];
		return *this;
	}

	template < class T, class A >
	void vector<T, A>::assign ( size_type count, const_reference value )
	{
		this->clear();
		this->reserve(count);
		for (; this->_size != count; this->_size++)
			this->_data[this->_size] = value;
	}

	template < class T, class A >
	typename vector<T, A>::reference vector<T, A>::at ( size_type pos )
	{
		if (pos >= this->_size)
			throw std::out_of_range("ft::vector");
		return this->_data[pos];
	}

	template < class T, class A >
	typename vector<T, A>::const_reference vector<T, A>::at ( size_type pos ) const
	{
		if (pos >= this->_size)
			throw std::out_of_range("ft::vector");
		return this->_data[pos];
	}

	template < class T, class A >
	typename vector<T, A>::reference vector<T, A>::operator [] ( size_type pos )
	{
		return this->_data[pos];
	}

	template < class T, class A >
	typename vector<T, A>::const_reference vector<T, A>::operator [] ( size_type pos ) const
	{
		return this->_data[pos];
	}

	template < class T, class A >
	typename vector<T, A>::reference vector<T, A>::front ( void )
	{
		return this->_data[0];
	}

	template < class T, class A >
	typename vector<T, A>::const_reference vector<T, A>::front ( void ) const
	{
		return this->_data[0];
	}

	template < class T, class A >
	typename vector<T, A>::reference vector<T, A>::back ( void )
	{
		return this->_data[this->_size - 1];
	}

	template < class T, class A >
	typename vector<T, A>::const_reference vector<T, A>::back ( void ) const
	{
		return this->_data[this->_size - 1];
	}

	template < class T, class A >
	typename vector<T, A>::pointer vector<T, A>::data ( void )
	{
		return this->_data;
	}

	template < class T, class A >
	typename vector<T, A>::const_pointer vector<T, A>::data ( void ) const
	{
		return this->_data;
	}

	template < class T, class A >
	bool vector<T, A>::empty ( void ) const
	{
		return this->_size == 0;
	}

	template < class T, class A >
	typename vector<T, A>::size_type vector<T, A>::size ( void ) const
	{
		return this->_size;
	}

	template < class T, class A >
	void vector<T, A>::reserve ( size_type new_cap )
	{
		if (this->_capacity >= new_cap)
			return ;
		if (this->_capacity * 2 > new_cap)
			new_cap = this->_capacity * 2;
		pointer	new_data = this->_alloc.allocate(new_cap);
		if (this->_capacity > 0)
		{
			memmove(new_data, this->_data, this->_size * sizeof(value_type));
			this->_alloc.deallocate(this->_data, this->_capacity);
		}
		this->_capacity = new_cap;
		this->_data = new_data;
	}

	template < class T, class A >
	typename vector<T, A>::size_type vector<T, A>::capacity ( void ) const
	{
		return this->_capacity;
	}

	template < class T, class A >
	void vector<T, A>::clear ( void )
	{
		for (; this->_size != 0; this->_size--)
			this->_data[this->_size - 1].~value_type();
	}

	template < class T, class A >
	void vector<T, A>::push_back ( const_reference value )
	{
		this->reserve(this->_size + 1);
		this->_data[this->_size++] = value;
	}

	template < class T, class A >
	void vector<T, A>::pop_back ( void )
	{
		this->_data[this->_size--].~value_type();
	}

	template < class T, class A >
	void vector<T, A>::resize ( size_type count, value_type value )
	{
		if (this->_size < count)
		{
			this->reserve(count);
			for (; this->_size != count; this->_size++)
				this->_data[this->_size] = value;
		}
		else if (this->_size > count)
		{
			for (; this->_size != count; this->size--)
				this->_data[this->_size - 1].~value_type();
		}
	}

} // namespace ft

#endif // FT_CONTAINERS_VECTOR_VECTOR_H_
