#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iterator>
#include <cstddef>
#include <algorithm>
#include <cstring>
#include <stdexcept>

#include "utils.hpp"

namespace ft
{		
	template < typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		class MyIterator;
		class ConstMyIterator;
		public:
			//------------------------------------------------------------------------
			//---------------------------typedef(12/12)-------------------------------
			//------------------------------------------------------------------------
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef MyIterator									iterator;
			typedef ConstMyIterator								const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;

		private:
			allocator_type	_alloc;
			pointer			_begin;
			pointer			_end;
			pointer 		_capacity;

			//------------------------------------------------------------------------
			//---------------------------MyIterator-----------------------------------
			//------------------------------------------------------------------------
			class MyIterator: public ft::iterator<std::random_access_iterator_tag, value_type>
			{
				typedef ft::iterator<std::random_access_iterator_tag, value_type>	parent;

				private:	
					pointer	_ptr;
					template<typename, typename> friend class vector;

				public:
					typedef typename parent::reference								reference;
					typedef typename parent::pointer								pointer;
			
					MyIterator(pointer begin = NULL): _ptr(begin) {}
					MyIterator(const MyIterator &copy): _ptr(copy._ptr) {}
					~MyIterator() {};

					const MyIterator		&operator=(const MyIterator &it)
					{
						//std::cout << "Hello NO const iter =\n";
						if (this != &it)
							_ptr = it._ptr;
						return (*this);
					}
					reference				operator*()
					{ //std::cout << "HEllo operator *\n";
						return (*_ptr); }
					pointer					operator->()											{
						//std::cout << "HEllo operator ->\n";
						return (_ptr); }
					MyIterator&				operator++()
					{
						++_ptr;
						return (*this);
					}
					MyIterator				operator++(int)
					{
						MyIterator tmp = *this;
						++(*this);
						return (tmp);
					}
					MyIterator&				operator--()
					{
						//std::cout << "HEllo operator --()\n";
						--_ptr;
						return (*this);
					}
					MyIterator				operator--(int)
					{
						//std::cout << "HEllo operator --(int)\n";
						MyIterator tmp = *this;
						--(*this);
						return (tmp);
					}
					friend difference_type	operator- (const MyIterator& a, const MyIterator& b)	{ return (a._ptr - b._ptr); }
					friend bool				operator== (const MyIterator& a, const MyIterator& b)	{ return (a._ptr == b._ptr); }
					friend bool				operator!= (const MyIterator& a, const MyIterator& b)	{ return !(a == b); }
					friend bool				operator< (const MyIterator lhs, const MyIterator rhs)	{ return (lhs._ptr < rhs._ptr); }
					friend bool				operator<= (const MyIterator lhs, const MyIterator rhs)	{ return (!(rhs._ptr < lhs._ptr)); }
					friend bool				operator> (const MyIterator lhs, const MyIterator rhs)	{ return (rhs < lhs); }
					friend bool				operator>= (const MyIterator lhs, const MyIterator rhs)	{ return !(lhs < rhs); }
					MyIterator				operator+ (difference_type n) const						{ 
						//std::cout << "Hello operator+\n";
						return (MyIterator(_ptr + n)); }
					friend MyIterator		operator+(int n, MyIterator& p)
					{
						//std::cout << "Hello operator+(int n, ConstMyIterator& p)\n";
						p._ptr = p._ptr + n;
						return (p._ptr);
					}
					MyIterator				&operator+= (difference_type n)
					{
						MyIterator(_ptr + n);
						return (*this);
					}
					MyIterator				operator- (difference_type n) const						{ return (*this + (-n)); }
					MyIterator				&operator-=(difference_type n)							{ return (*this += -n); }
					reference				operator[](difference_type n) const						{ return (_ptr[n]); }
			};

			//------------------------------------------------------------------------
			//---------------------------ConstMyIterator------------------------------
			//------------------------------------------------------------------------
			class ConstMyIterator: public ft::iterator<std::random_access_iterator_tag, const value_type>
			{
				typedef ft::iterator<std::random_access_iterator_tag, const value_type>	parent;
				typedef MyIterator														nonconst_v;
			
				public:
					typedef typename parent::reference									reference;
					typedef typename parent::pointer									pointer;
			
					ConstMyIterator(const nonconst_v &it): _ptr(it._ptr) {}
					ConstMyIterator(pointer begin = NULL): _ptr(begin) {}
					ConstMyIterator(const ConstMyIterator &copy): _ptr(copy._ptr) {}
					~ConstMyIterator() {};

					const ConstMyIterator	&operator=(const ConstMyIterator &it)
					{
						//std::cout << "Hello const iter =\n";
						if (this != &it)
							_ptr = it._ptr;
						return (*this);
					}
					reference				operator*()															{ return (*_ptr); }
					pointer					operator->()														{ 
						//std::cout << "Hello operator-> const\n";
						return (_ptr); }
					ConstMyIterator&		operator++()
					{
						++_ptr;
						return (*this);
					}
					ConstMyIterator			operator++(int)
					{
						ConstMyIterator tmp = *this;
						++(*this);
						return (tmp);
					} 
					ConstMyIterator&		operator--()
					{
						--_ptr;
						return (*this);
					}
					ConstMyIterator			operator--(int)
					{
						ConstMyIterator tmp = *this;
						--(*this);
						return (tmp);
					}
					friend difference_type	operator- (const ConstMyIterator& a, const ConstMyIterator& b)		{ return (a._ptr - b._ptr); }
					friend bool				operator== (const ConstMyIterator& a, const ConstMyIterator& b)		{ return (a._ptr == b._ptr); }
					friend bool				operator!= (const ConstMyIterator& a, const ConstMyIterator& b)		{ return (!(a == b)); }
					friend bool				operator< (const ConstMyIterator lhs, const ConstMyIterator rhs)	{ return (lhs._ptr < rhs._ptr); }
					friend bool				operator<= (const ConstMyIterator lhs, const ConstMyIterator rhs)	{ return !(rhs._ptr < lhs._ptr); }
					friend bool				operator> (const ConstMyIterator lhs, const ConstMyIterator rhs)	{ return rhs < lhs; }
					friend bool				operator>= (const ConstMyIterator lhs, const ConstMyIterator rhs)	{ return !(lhs < rhs); }
					ConstMyIterator			operator+ (difference_type n) const									{ 
						//std::cout << "Hello\n";
						return (ConstMyIterator(_ptr + n)); }
					friend ConstMyIterator	operator+(difference_type n, ConstMyIterator& p)
					{
						//std::cout << "Hello const operator+(difference_type n, ConstMyIterator& p)\n";
						p._ptr = p._ptr + n;
						return (p._ptr);
					}
					ConstMyIterator			&operator+= (difference_type n)
					{
						ConstMyIterator(_ptr + n);
						return (*this);
					}
					ConstMyIterator			operator- (difference_type n) const									{ return (*this + (-n)); }
					ConstMyIterator			&operator-=(difference_type n)										{ return (*this += -n); }
					reference				operator[](difference_type n) const									{ return (_ptr[n]); }

				private:	
					pointer	_ptr;
			};

			size_type				_get_new_cap(size_type new_size) const
			{
				const size_type ms 	= max_size();
				const size_type cap = capacity();

				if (new_size > max_size())
					throw std::length_error("vector");
				if (cap >= ms / 2)
					return ms;
				return std::max<size_type>(cap * 2, new_size);
			}
			void					_nallocate(size_type n)
			{
				if (n > max_size())
					throw std::length_error("vector");
				_begin = _end =	_alloc.allocate(n);
				_capacity = _begin + n;
			}
			void					_deallocate()
			{
				if (_begin != NULL)
				{
					clear();
					_alloc.deallocate(_begin, capacity());
					_begin = _end = _capacity = NULL;
				}
			}
			void					_reallocate(size_type n)
			{
				const size_type csz = size();

				pointer	new_buf = _alloc.allocate(n);
				_copy(new_buf, _begin, size());

		
				_deallocate();
				_begin = new_buf;
				_end = new_buf + csz;
				_capacity = new_buf + n;
			}
			void					_copy(pointer dst, pointer src, size_type n)
			{
				for (size_type i = 0; i < n; ++i)
					_alloc.construct(dst + i, src[i]);
			}
			void					_construct_at_end(size_type n, const_reference val)
			{
				const_pointer new_end = _end + n;

				for (pointer pos = _end; pos != new_end; ++pos)
					_alloc.construct(pos, val);
				_end += n;
			}
			void					_construct_one_at_end(const_reference val)
			{
				_alloc.construct(_end++, val);
			}
			void					_destruct_at_end(pointer new_last)
			{
				pointer p = _end;

				while (p != new_last)
					_alloc.destroy(--p);
				_end = new_last;
			}
			template <typename InputIterator>
			void					_construct_at_end(InputIterator first, InputIterator last, typename enable_if<is_iterator<InputIterator>::value>::type* = 0)
			{	
				pointer pos = _end; 
				for (; first != last; ++first, ++pos)
					_alloc.construct(pos, *first);
				_end = pos;
			}
			pointer					_reallocate_with_insert(pointer position, const_reference val, size_type n = 1)
			{
				const size_type	newsz	= size() + n;
				const size_type sz_p1	= static_cast<size_type>(position - _begin);
				const size_type sz_p2	= static_cast<size_type>(_end - position);
				const size_type	new_cap	= _get_new_cap(newsz);
				pointer			new_buf	= _alloc.allocate(new_cap);

				_copy(new_buf, _begin, sz_p1);
				_copy(new_buf + sz_p1 + n, _begin + sz_p1, sz_p2);
				for (size_type i = sz_p1; i < sz_p1 + n; ++i)
					_alloc.construct(new_buf + i, val);
				_deallocate();
				_begin = new_buf;
				_end = new_buf + newsz;
				_capacity = new_buf + new_cap;
				return new_buf + sz_p1;
			}
			template <typename InputIterator>
			pointer					_reallocate_with_insert(pointer position, InputIterator first, InputIterator last, typename enable_if<is_iterator<InputIterator>::value>::type* = 0)
			{
				const size_type n		= static_cast<size_type>(std::distance(first, last));
				const size_type	newsz	= size() + n;
				const size_type sz_p1	= static_cast<size_type>(position - _begin);
				const size_type sz_p2	= static_cast<size_type>(_end - position);
				const size_type	new_cap	= _get_new_cap(newsz);
				pointer			new_buf	= _alloc.allocate(new_cap);

				_copy(new_buf, _begin, sz_p1);
				_copy(new_buf + sz_p1 + n, _begin + sz_p1, sz_p2);
				for (size_type i = sz_p1; i < sz_p1 + n; ++i, ++first)
					_alloc.construct(new_buf + i, *first);
				_deallocate();
				_begin = new_buf;
				_end = new_buf + newsz;
				_capacity = new_buf + new_cap;
				return new_buf + sz_p1;
			}
			void					_insert_not_end(pointer position, const_reference val, size_type n = 1)
			{
				pointer end_copy_pos;
				
				for (size_type i = 1; i <= n; ++i)
				{
					const_pointer pval;
					
					end_copy_pos = _end - i;	
					if (end_copy_pos >= _begin)
						pval = end_copy_pos;
					else
						pval = &val;
					_alloc.construct(_end + n - i, *pval);
				}
				for (pointer p = end_copy_pos - 1; p > position - 1; --p)
					*(p + n) = *p;
				for (pointer p = position; p != position + n; ++p)
					*p = val;
				_end += n;
			}
			template <typename InputIterator>
			void					_insert_not_end(pointer position, InputIterator first, InputIterator last, typename enable_if<is_iterator<InputIterator>::value>::type* = 0)
			{
				//std::cout << "ALLO BLAT 2\n";
				const size_type n		= static_cast<size_type>(std::distance(first, last));

				//std::cout << "n: " << n << std::endl;
				//std::cout << "dop: " << first - _begin << std::endl;

				pointer			end_copy_pos;
				
				for (size_type i = 1; i <= n; ++i)
				{
					const_pointer pval;
					
					end_copy_pos = _end - i;	
					if (end_copy_pos >= _begin)
					{
						//std::cout << "1\n";
						pval = end_copy_pos;
					}
					else
					{
						//std::cout << "2\n";
						pval = &(*--last);
					}
					_alloc.construct(_end + n - i, *pval);

					//std::cout << "pos start: " << *(pval) << "\n";
				}
				for (pointer p = end_copy_pos - 1; p > position - 1; --p)
				{
					//std::cout << "pos mid: " << *p << std::endl;
					*(p + n) = *p;
				}

				for (; first != last;)
				{
					//std::cout << "pos end до: " << *position << std::endl;
					*(position + n - 1) = *(last - 1);
					//std::cout << "pos end по: " << *position << std::endl;
					--last;
					--position;
				}
				_end += n;
			}

		public:
			//------------------------------------------------------------------------
			//------------------------------constructor(4/4)--------------------------
			//------------------------------------------------------------------------
			// ПРОВЕРЕНО Конструктор без параметров
			explicit vector (const allocator_type& alloc = allocator_type()): _alloc(alloc)
			{
				_begin = _end = _capacity = NULL;
			}
			// ПРОВЕРЕНО Конструктор с 1 параметром (длина вектора)
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc)
			{
				if (n > max_size())
					throw std::length_error("vector");
				_begin = _alloc.allocate(n);
				_end = _capacity = _begin + n;
				for (pointer i = _begin; i != _end; i++)
					_alloc.construct(i, val);
			}
			// ПРОВЕРЕНО Конструктор с 2 параметрами (набор значений)
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _alloc(alloc)
			{
				size_type n = std::distance(first, last);

				if (n > max_size())
					throw std::length_error("vector");
				_begin = _alloc.allocate(n);
				_end = _capacity = _begin + n;
				for (pointer i = _begin; first != last; first++, i++)
					_alloc.construct(i, *first);
			}
			// ПРОВЕРЕНО Конструктор копирования
			vector (const vector& x): _alloc(x.get_allocator())
			{
				//std::cout << "Конструктор копирования\n";
				size_type n = x.size();
				pointer pos, pos_copy = x._begin;

				_begin = pos = _alloc.allocate(n);
				_end = _capacity = _begin + n;
				for (size_type i = 0; i < n; i++, pos++, pos_copy++)
					_alloc.construct(pos, *(pos_copy));
			}
			//------------------------------------------------------------------------
			//------------------------------destructor(1/1)---------------------------
			//------------------------------------------------------------------------
			// ПРОВЕРЕНО Деструктор
			~vector ()
			{
				//std::cout << "Деструктор\n";
				if (_begin != NULL)
				{
					clear();
					_alloc.deallocate(_begin, capacity());
					_begin = _end = _capacity = NULL;
				}
			}
			//------------------------------------------------------------------------
			//------------------------------operator=(1/1)----------------------------
			//------------------------------------------------------------------------
			// ПРОВЕРЕНО
			const vector &operator=(const vector &x)
			{
				if (this != &x)
					assign(x._begin, x._end);
				return (*this);
			}
			//------------------------------------------------------------------------
			//------------------------------Iterators(8/8)----------------------------
			//------------------------------------------------------------------------
			// ПРОВЕРЕНО ВЕСЬ БЛОК
			iterator				begin()					{ return (iterator(_begin)); }
			const_iterator			begin() const			{ return (const_iterator(_begin)); }
			iterator				end()					{ return (iterator(_end)); }
			const_iterator			end() const				{ return (const_iterator(_end)); }
			reverse_iterator		rbegin()				{ return (reverse_iterator(end())); }
			const_reverse_iterator	rbegin() const			{ return (const_reverse_iterator(end())); }
			reverse_iterator		rend()					{ return (reverse_iterator(begin())); }
			const_reverse_iterator	rend() const			{ return (const_reverse_iterator(begin())); }
			//------------------------------------------------------------------------
			//------------------------------Capacity(6/6)-----------------------------
			//------------------------------------------------------------------------
			// ПРОВЕРЕНО Возвращает длину вектора
			size_type	size() const						{ return (_end - _begin); }
			// ПРОВЕРЕНО Возвращает максимальное количество элементов, которое может содержать вектор
			size_type	max_size() const					{ return (_alloc.max_size()); }
			// ПРОВЕРЕНО Изменяет размер контейнера, чтобы он содержал n элементов
			void		resize(size_type n, value_type val = value_type())
			{
				size_type size = this->size();

				if (n > max_size())
					throw std::length_error("vector");
				else if (n < size)
				{
					while (size > n)
					{
						_end--;
						size--;
						_alloc.destroy(_end);
					}
				}
				else
					insert(end(), n - size, val);
			}
			// ПРОВЕРЕНО Возвращает размер памяти выделенный для вектора в элементах
			size_type	capacity() const					{ return _capacity - _begin; }
			// ПРОВЕРЕНО Пустой ли вектор?
			bool		empty() const						{ return (size() ? false : true); }
			// ПРОВЕРЕНО Пытается сделать ёмкость вектора как минимум достаточной для размещения n элементов
			void		reserve (size_type n)
			{
				pointer		begin_old = _begin, begin_temp = _begin, end_old = _end;
				size_type	capacity_old = capacity();

				if (n > max_size())
					throw std::length_error("vector");
				else if (n > capacity())
				{
					_begin = _end = _alloc.allocate( n );
					_capacity = _begin + n;
					while (begin_old != end_old)
						_alloc.construct(_end++, *begin_old++);
					_alloc.deallocate(begin_temp, capacity_old);
				}
			}
			//------------------------------------------------------------------------
			//---------------------------Element access(8/8)--------------------------
			//------------------------------------------------------------------------
			// ПРОВЕРЕНО Доступ к элементу без защиты
			reference		operator[](size_type n)			{ return *(_begin + n); }
			// ПРОВЕРЕНО Доступ к элементу без защиты
			const_reference operator[](size_type n) const	{ return *(_begin + n); }
			// ПРОВЕРЕНО Доступ к элементу с защитой
			reference 		at(size_type n)
			{
				if (n >= size())
					throw std::out_of_range("vector");
				return (*(_begin + n));
			}
			// ПРОВЕРЕНО Доступ к элементу с защитой
			const_reference at(size_type n) const
			{
				if (n >= size())
					throw std::out_of_range("vector");
				return (*(_begin + n));
			}
			// ПРОВЕРЕНО Возвращает ссылку на первый элемент вектора
			reference		front()							{ return (*_begin); }
			// ПРОВЕРЕНО Возвращает ссылку на первый элемент вектора
			const_reference front() const					{ return (*_begin); }
			// ПРОВЕРЕНО Возвращает ссылку на последний элемент вектора
			reference 		back()							{ return (*(_end - 1)); }
			// ПРОВЕРЕНО Возвращает ссылку на последний элемент вектора
			const_reference back() const					{ return (*(_end - 1)); }
			//------------------------------------------------------------------------
			//-----------------------------Modifiers(11/11)---------------------------
			//------------------------------------------------------------------------
			template <class InputIterator>
			// ПРОВЕРЕНО Присваивает вектору новое содержимое, заменяя его текущее содержимое и соответствующим образом изменяя его размер
			void assign (InputIterator first, InputIterator last)
			{
				// Может ли быть исключение, когда n > msx_size? хз другие тоже хз
				// Делаем временные переменные, так как Iterator может ссылаться на изменяемый массив
				size_type	n = static_cast<size_type>(std::distance(first, last)), capacity = this->capacity();
				pointer		first_ptr = first._ptr, last_ptr = last._ptr;
				pointer		begin_new = _alloc.allocate(n), end_new = begin_new, capacity_new = begin_new + n;

				clear();
				if (n == 0)
					return ;

				if (capacity >= n)
				{
					for(; first_ptr != last_ptr; first_ptr++, _end++)
						_alloc.construct(_end, *first_ptr);
				}
				else
				{
					for(; first_ptr != last._ptr; first_ptr++, end_new++)
						_alloc.construct(end_new, *first_ptr);
					_alloc.deallocate(_begin, capacity);
					_begin = begin_new;
					_end = end_new;
					_capacity = capacity_new;
				}
			}
			// ПРОВЕРЕНО Присваивает вектору новое содержимое, заменяя его текущее содержимое и соответствующим образом изменяя его размер
			void assign (size_type n, const value_type& val)
			{
				// Может ли быть исключение, когда n > msx_size? хз другие тоже хз
				size_type capacity = this->capacity();

				clear();
				if (n == 0)
					return ;
				if (capacity >= n)
				{
					for (; n; n--)
						_alloc.construct(_end++ , val);
				}
				else
				{
					_alloc.deallocate(_begin, capacity);
					_begin = _end = _alloc.allocate(n);
					_capacity = _begin + n;
					for (; n; n--)
						_alloc.construct(_end++, val);
				}
			}
			// ПРОВЕРЕНО Добавляет новый элемент в конец вектора
			void push_back (const value_type& val)
			{
				size_t size = this->size();

				if (_end == _capacity)
				{
					if (size == 0)
						reserve(1);
					else
						reserve(size * 2);
				}
				_alloc.construct(_end, val);
				_end++;
			}
			// ПРОВЕРЕНО Удаляет последний элемент в векторе (вектор пуст -> неопределённое поведение)
			void pop_back()
			{
				_alloc.destroy(&back());
				_end--;
			}
			// СЛОЖНО Вектор увеличивается путем вставки нового элемента до элемента в заданном положении
			iterator insert (iterator position, const value_type& val)
			{
				//std::cout << "IN 1\n";
				pointer p = position._ptr;

				if (_end < _capacity)
				{
					if (p == _end)
						_construct_one_at_end(val);
					else
						_insert_not_end(p, val);
				}
				else
					p = _reallocate_with_insert(p, val);
				return iterator(p);
			}
			// СЛОЖНО Вектор увеличивается путем вставки n новых элементов до элемента в заданном положении
			void insert (iterator position, size_type n, const value_type& val)
			{
				if (n == 0)
					return ;

				pointer p = position._ptr;

				if (_end + n <= _capacity)
				{
					if (p == _end)
						_construct_at_end(n, val);
					else
						_insert_not_end(p, val, n);
				}
				else
					_reallocate_with_insert(p, val, n);
			}
			// СЛОЖНО Вектор увеличивается путем вставки новых элементов до элемента в заданном положении
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last)
			{
				pointer p = position._ptr;

				if (first == last)
					return ;
				
				if (_end + (last - first) <= _capacity)
				{
					if (p == _end)
						_construct_at_end(first, last);
					else
					{
						//std::cout << "ALLO BLAT\n";
						_insert_not_end(p, first, last);
					}
				}
				else
					_reallocate_with_insert(p, first, last);
			}
			// ПРОВЕРЕНО Удаляет из вектора один элемент 
			iterator erase (iterator position)
			{
				pointer		p = position._ptr;
				size_type	size_new = static_cast<size_type>((_end - p - 1) * sizeof(value_type));

				if ( p == _end - 1)
					_alloc.destroy(position._ptr);
				else
				{				
					_alloc.destroy(p);
					std::memmove(p, p + 1, size_new);
				}
				_end--;
				return (iterator(p));
			}
			// ПРОВЕРЕНО Удаляет из вектора диапазон элементов
			iterator erase (iterator first, iterator last)
			{
				pointer		first_ptr = first._ptr, first_ptr_temp = first_ptr, last_ptr = last._ptr;
				size_type	size_new = static_cast<size_type>((_end - last_ptr) * sizeof(value_type));
					
				if (first_ptr != last_ptr)
				{
					for (size_type i = 0; first_ptr_temp != last_ptr; i++, first_ptr_temp++)
						_alloc.destroy(first_ptr);
					std::memmove(first_ptr, last_ptr, size_new);
					_end -= last_ptr - first_ptr;
				}
				return (iterator(first_ptr));
			}
			// ПРОВЕРЕНО Заменяет содержимое контейнера содержимым x , который является другим векторным объектом того же типа
			void swap (vector& x)
			{
				if (this != &x)
				{
					std::swap(_begin, x._begin);
					std::swap(_end, x._end);
					std::swap(_capacity, x._capacity);
				}
			}
			// ПРОВЕРЕНО Удаляет все элементы из вектора
			void clear()
			{
				size_type size = this->size();

				for (size_type i = 0; i < size; i++)
					_alloc.destroy(_end--);
			}
			//------------------------------------------------------------------------
			//-----------------------------Allocator(1/1)-----------------------------
			//------------------------------------------------------------------------
			// ПРОВЕРЕНО
			allocator_type	get_allocator() const			{ return (_alloc); }
	};

	//------------------------------------------------------------------------
	//-------------------Non-member function overloads(7/7)-------------------
	//------------------------------------------------------------------------
	// ПРОВЕРЕНО ВЕСЬ БЛОК
	typedef	std::size_t		size_type;
	template <typename T, typename Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{return (lhs.size() != rhs.size() ? false : equal(lhs.begin(), lhs.end(), rhs.begin())); }
	template <typename T, typename Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return !(lhs == rhs); }
	template <typename T, typename Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)		{ return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
	template <typename T, typename Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return (!(rhs < lhs)); }
	template <typename T, typename Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)		{ return (rhs < lhs); }
	template <typename T, typename Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return (!(lhs < rhs)); }
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)							{ x.swap(y); }

	//vector<bool> необязательно!
};

#endif
