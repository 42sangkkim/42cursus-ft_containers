#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>
# include "./vector_iterator.hpp"
# include "../iterator_traits.hpp"
# include "../reverse_iterator.hpp"
# include <cstring> // memcpy

namespace ft
{
	template < \
		class T, \
		class Allocator = std::allocator<T> \
	>
	class vector
	{
		// Iterator
		class iterator;

		// Member types
	public:
		typedef T										value_type;
		typedef Allocator								allocator_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef Allocator::reference					reference;
		typedef Allocator::const_reference				const_reference;
		typedef Allocator::pointer						pointer;
		typedef Allocator::const_pointer				const_pointer;
		//typedef iterator<T>								iterator;
		//typedef iterator<T &>							const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		// Member Objects
	protected:
		size_type					_size;
		size_type					_capacity;
		allocator_type				_alloc;
		value_type					*_data;

		// Member functions
	public:
		// Constructor
		vector ( void ) : \
		_size(0), \
		_capacity(0), \
		_data(NULL), \
		_alloc(allocator_type())
		{

		}

		explicit vector ( const allocator_type & alloc ) : \
		_size(0), \
		_capacity(0), \
		_data(NULL), \
		_alloc(alloc)
		{
			
		}

		explicit vector ( \
			size_type count, \
			const value_type & val = value_type(), \
			const allocator_type & alloc = allocator_type() \
		) : \
		_size(count), \
		_capacity(count), \
		_data(NULL), \
		_alloc(alloc)
		{
			if (count == 0)
				return ;
			this->reserve(count);
			for (size_type idx = 0; idx < count; idx++)
				this->_data[idx] = val;
		}

		template < class InputIterator >
		vector ( \
			InputIterator first, \
			InputIterator last, \
			const allocator_type & alloc = allocator_type() \
		) : \
		_size(last - first), \
		_capacity(last - first), \
		_data(NULL), \
		_alloc(alloc)
		{
			if (first > last)
				throw std::exception;
			this->reserve(this->_size);
			for (size_type idx = 0; idx < this->_size && first != last; idx++, first++)
				_data[idx] = *first;
		}

		vector ( const vector & other ) : \
		_size(other._size), \
		_capacity(other._size), \
		_data(NULL), \
		_alloc(allocator_type(other.alloc))
		{
			this->reserve(this->_size);
			for (size_type idx = 0; idx < this->_size; idx++)
				this->data[idx] = other.data[idx];
		}

		// Destructor
		~vector ( void )
		{
			this->clear();
			this->_alloc.deallocate(this->_data, this->_capacity);
			this->_data = NULL;
		}

		// Copy assignment
		vector<value_type, allocator_type> & operator= ( const vector<value_type, allocator_type> & other )
		{
			if (this == *other)
				return *this;
			this->assign(other.begin(), other.end());
			return *this;
		}

		void assign (size_type count, const value_type & val )
		{
			this->clear();
			this->reserve(count);
			for (size_type idx = 0; idx < count; idx++)
				this->_data[idx] = val;
		}

		template < class InputIterator >
		void assign ( InputIterator first, InputIterator last )
		{
			size_type	count = last - count;
			this->clear();
			this->reserve(count);
			for (size_type idx = 0; idx < count && first != last; idx++, first++)
				this->_data[idx] = *first;
		}

		allocator_type get_allocator ( void ) const
		{
			return this->_alloc;
		}

		// Element accesses
		reference at ( size_type pos )
		{
			return this->_data[pos];
		}

		const_reference at ( size_type pos ) const
		{
			return this->_data[pos];
		}

		reference operator[] ( size_type pos )
		{
			return this->_data[pos];
		}

		const_reference operator[] ( size_type pos ) const
		{
			return this->_data[pos];
		}

		reference front ( void )
		{
			return this->_data[0];
		}

		const_reference front ( void ) const
		{
			return this->_data[0];
		}

		reference back ( void )
		{
			return this->_data[this->_size - 1];
		}

		const_reference back ( void ) const
		{
			return this->_data[this->_size - 1];
		}

		value_type * data ( void )
		{
			return this->_data;
		}

		const value_type * data ( void ) const
		{
			return this->_data;
		}

		// Iterators
		iterator begin ( void )
		{
			this->iterator(0);
		}

		const_iterator begin ( void ) const;
		iterator end ( void );
		const_iterator end ( void ) const;
		reverse_iterator rbegin ( void );
		const_reverse_iterator rbegin ( void ) const;
		reverse_iterator rend ( void );
		const_reverse_iterator rend ( void ) const;

		// Capacity
		bool empty ( void ) const
		{
			return (this->_size == 0);
		}

		size_type size ( void ) const
		{
			return this->_size;
		}

		size_type max_size ( void ) const
		{
			return size_type(-1);
		}

		void reserve ( size_type count )
		{
			if (this->_capacity >= count)
				return ;
			value_type	*new_data = this->_alloc.allocate(count);
			memcpy(new_data, this->_data, sizeof(value_type) * this->_size);
			this->_alloc.deallocate(this->_data, sizeof(this->_capacity));
			this->_data = new_data;
			this->_capacity = count;
		}

		size_type capacity ( void ) const
		{
			return this->_capacity;
		}

		// Modifiers
		void clear ( void )
		{
			for (size_type idx = 0; idx < this->_size; idx++)
				this->_data[idx].~value_type;
			this->_size = 0;
		}

		iterator insert ( const_iterator pos, const value_type & val )
		iterator insert ( const_iterator pos, size_type count, const value_type & val );
		template < class InputIterator >
		iterator insert ( const_iterator pos, InputIterator first, InputIterator last );
		iterator erase ( iterator pos);
		iterator erase ( iterator first, iterator last );
		void push_back ( const value_type & val )
		{
			if (this->_capacity == 0)
				this->reserve(1);
			if (this->_size == this->_capacity)
				this->reserve(this->_capacity * 2);
			this->_data[this->_size++] = val;
		}

		void pop_back ( void )
		{
			this->_data[this->_size--].~value_type;
		}

		void resize ( size_type count, value_type val = value_type())
		{
			if (this->_capacity > count)
				return ;
			reserve(this->_capacity * 2);
			reserve(count);
			for (size_type idx = this->size; idx < count; idx++)
				this->_data[idx] = val;
			this->_size = count;
		}

		void swap ( vector & other )
		{
			size_type			tmp_size = this->_size;
			size_type			tmp_capacity = this->_capacity;
			allocator_type		tmp_alloc = this->_alloc;
			value_type			*tmp_data = this->_data;
			this->_size = other.size;
			this->_capacity = other._capacity;
			this->_alloc = other._alloc;
			this->_data = other._data;
			other.size = tmp_size;
			other._capacity = tmp_capacity;
			other._alloc = tmp_alloc;
			other._data = tmp_data;
		}

	}; // class vector

	// Non-member functions
	// Relational operators
	template < class T, class Alloc >
	bool operator== ( const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs )
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template < class T, class Alloc >
	bool operator!= ( const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs )
	{
		if (lhs.size() != rhs.size())
			return true;
		return (!ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template < class T, class Alloc >
	bool operator< ( const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template < class T, class Alloc >
	bool operator<= ( const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs )
	{
		return !(lhs > rhs);
	}

	template < class T, class Alloc >
	bool operator> ( const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs )
	{
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template < class T, class Alloc >
	bool operator>= ( const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs )
	{
		return !(lhs < rhs);
	}

	template < class T, class Alloc >
	void swap ( ft::vector<T, Alloc> & lhs, ft::vector<T, Alloc> & rhs )
	{
		lhs.swap(rhs);
	}

} // namespace ft

#endif // FT_VECTOR_HPP
