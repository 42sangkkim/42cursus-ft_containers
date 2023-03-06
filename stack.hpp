#ifndef FT_CONTAINERS_STACK_HPP
# define  FT_CONTAINERS_STACK_HPP

# include "./vector.hpp"

namespace ft
{
	template < class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			// Member types
			typedef Container								container_type;
			typedef typename Container::value_type			value_type;
			typedef typename Container::size_type			size_type;
			typedef typename Container::reference			reference;
			typedef typename Container::const_reference 	const_reference;

		protected:
			// Member objects
			Container										c;

		public:
			// Member functions
			explicit stack ( const Container & cont = Container() );
			stack ( const stack & other );

			~stack ( void );

			stack & operator = ( const stack & other );

			reference top ( void );
			const_reference top ( void ) const;

			bool empty ( void ) const;
			size_type size ( void ) const;

			void push ( const value_type & value );
			void pop ( void );

			friend bool ft::operator == ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs );
			friend bool ft::operator < ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs );
			friend bool ft::operator > ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs );
	}; // class stack

	// Non-member functions
	template < class T, class Container >
	bool operator == ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs );
	template < class T, class Container >
	bool operator != ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs );
	template < class T, class Container >
	bool operator < ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs );
	template < class T, class Container >
	bool operator > ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs );
	template < class T, class Container >
	bool operator <= ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs );
	template < class T, class Container >
	bool operator >= ( const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs );
	
} // namespace ft

# include "./stack.tpp"

#endif // FT_CONTAINERS_STACK_HPP