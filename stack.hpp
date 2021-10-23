#ifndef STACK_HPP
#define	STACK_HPP

#include "vector.hpp"

namespace ft
{		
	template < typename T, typename Container = vector<T> >
	class stack
	{
		public:
			//---------------------------typedef(3/3)---------------------------------
			typedef T							value_type;
			typedef Container					container_type;
			typedef	std::size_t					size_type;

			//------------------------------constructor(1/1)--------------------------
			explicit stack (const container_type& ctnr = container_type()): cont(ctnr) {}
			//------------------------------destructor(1/1)---------------------------
			~stack() {}
			//------------------------------Member functions(5/5)----------------------
			// Пустой ли вектор?
			bool				empty() const										{ return (cont.empty()); }
			// Возвращает длину вектора
			size_type			size() const 										{ return (cont.size()); }
			// Возвращает ссылку на верхний элемент в куче
			value_type& 		top()												{ return (cont.back()); }
			// Возвращает ссылку на верхний элемент в куче
			const value_type&	top() const											{ return (cont.back()); }
			// Вставляет новый элемент вверху кучи, над текущим верхним элементом
			void				push(const value_type& val)							{ cont.push_back(val); }
			// Удаляет верхний элемент кучи
			void				pop()												{ cont.pop_back(); }
			
		protected:
			container_type						cont;

		template <typename _T, typename _Container>
		friend bool operator== (const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
		template <typename _T, typename _Container>
		friend bool operator!= (const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
		template <typename _T, typename _Container>
		friend bool operator< (const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
		template <typename _T, typename _Container>
		friend bool operator<= (const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
		template <typename _T, typename _Container>
		friend bool operator> (const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
		template <typename _T, typename _Container>
		friend bool operator>= (const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
	};

	template <typename T, typename Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{ return (lhs.cont == rhs.cont); }
	template <typename T, typename Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{ return (lhs.cont != rhs.cont); }
	template <typename T, typename Container>
	bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{ return (lhs.cont < rhs.cont); }
	template <typename T, typename Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{ return (lhs.cont <= rhs.cont); }
	template <typename T, typename Container>
	bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{ return (lhs.cont > rhs.cont); }
	template <typename T, typename Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs.cont >= rhs.cont); }
};

#endif
