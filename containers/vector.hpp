#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "utils.hpp"

namespace ft
{
	template < typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		class MyIterator;
		class ConstMyIterator;
		public:
			//------------------------------------------------------typedef(12/12)---------------------------------------------------------
			typedef T																value_type;
			typedef Allocator														allocator_type;
			typedef typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference						const_reference;
			typedef typename allocator_type::pointer								pointer;
			typedef typename allocator_type::const_pointer							const_pointer;
			typedef MyIterator														iterator;
			typedef ConstMyIterator													const_iterator;
			typedef ft::reverse_iterator<iterator>									reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;
			typedef std::ptrdiff_t													difference_type;
			typedef std::size_t														size_type;

		private:
			allocator_type	_alloc;
			pointer			_begin;
			pointer			_end;
			pointer 		_capacity;
			//------------------------------------------------------MyIterator-------------------------------------------------------------
			class MyIterator: public ft::iterator<std::random_access_iterator_tag, value_type>
			{
				typedef ft::iterator<std::random_access_iterator_tag, value_type>	parent;

				private:
					pointer	_ptr;
					template <typename, typename> friend class vector;

				public:
					typedef typename parent::reference								reference;
					typedef typename parent::pointer								pointer;
					// constructor/destructor
					MyIterator(pointer begin = NULL): _ptr(begin) {}
					MyIterator(const MyIterator &copy): _ptr(copy._ptr) {}
					~MyIterator() {}
					// operator
					const MyIterator		&operator=(const MyIterator &it)
					{
						if (this != &it)
							_ptr = it._ptr;
						return (*this);
					}
					reference				operator*()														{ return (*_ptr); }
					pointer					operator->()													{ return (_ptr); }
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
						--_ptr;
						return (*this);
					}
					MyIterator				operator--(int)
					{
						MyIterator tmp = *this;
						--(*this);
						return (tmp);
					}
					friend difference_type	operator- (const MyIterator& a, const MyIterator& b)			{ return (a._ptr - b._ptr); }
					friend bool				operator== (const MyIterator& a, const MyIterator& b)			{ return (a._ptr == b._ptr); }
					friend bool				operator!= (const MyIterator& a, const MyIterator& b)			{ return !(a == b); }
					friend bool				operator< (const MyIterator lhs, const MyIterator rhs)			{ return (lhs._ptr < rhs._ptr); }
					friend bool				operator<= (const MyIterator lhs, const MyIterator rhs)			{ return (!(rhs._ptr < lhs._ptr)); }
					friend bool				operator> (const MyIterator lhs, const MyIterator rhs)			{ return (rhs < lhs); }
					friend bool				operator>= (const MyIterator lhs, const MyIterator rhs)			{ return !(lhs < rhs); }
					MyIterator				operator+ (difference_type n) const								{ return (MyIterator(_ptr + n)); }
					friend MyIterator		operator+(int n, MyIterator& p)
					{
						p._ptr = p._ptr + n;
						return (p._ptr);
					}
					MyIterator				&operator+= (difference_type n)
					{
						MyIterator(_ptr + n);
						return (*this);
					}
					MyIterator				operator- (difference_type n) const								{ return (*this + (-n)); }
					MyIterator				&operator-=(difference_type n)									{ return (*this += -n); }
					reference				operator[](difference_type n) const								{ return (_ptr[n]); }
			};
			//------------------------------------------------------ConstMyIterator--------------------------------------------------------
			class ConstMyIterator: public ft::iterator<std::random_access_iterator_tag, const value_type>
			{
				typedef ft::iterator<std::random_access_iterator_tag, const value_type>	parent;
				typedef MyIterator														nonconst_v;
			
				public:
					typedef typename parent::reference									reference;
					typedef typename parent::pointer									pointer;
					// constructor/destructor
					ConstMyIterator(const nonconst_v &it): _ptr(it._ptr) {}
					ConstMyIterator(pointer begin = NULL): _ptr(begin) {}
					ConstMyIterator(const ConstMyIterator &copy): _ptr(copy._ptr) {}
					~ConstMyIterator() {}
					// operator
					const ConstMyIterator	&operator=(const ConstMyIterator &it)
					{
						if (this != &it)
							_ptr = it._ptr;
						return (*this);
					}
					reference				operator*()															{ return (*_ptr); }
					pointer					operator->()														{ return (_ptr); }
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
					friend bool				operator<= (const ConstMyIterator lhs, const ConstMyIterator rhs)	{ return (!(rhs._ptr < lhs._ptr)); }
					friend bool				operator> (const ConstMyIterator lhs, const ConstMyIterator rhs)	{ return (rhs < lhs); }
					friend bool				operator>= (const ConstMyIterator lhs, const ConstMyIterator rhs)	{ return (!(lhs < rhs)); }
					ConstMyIterator			operator+ (difference_type n) const									{ return (ConstMyIterator(_ptr + n)); }
					friend ConstMyIterator	operator+(difference_type n, ConstMyIterator& p)
					{
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

			template <class InputIterator>
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type
			validate_iterator_values(InputIterator first,InputIterator last, size_type range)
			{
				pointer		reserved_buffer = _alloc.allocate(range);
				bool		result = true;
				size_t		i = 0;

				for (;first != last; ++first, ++i) {
					try { reserved_buffer[i] = *first; }
					catch (...) { result = false; break; }
				}
				_alloc.deallocate(reserved_buffer, range);
				return result;
			}
			
		public:
			//---------------------------------------------------------constructor(4/4)----------------------------------------------------
			// Конструктор без параметров
			explicit vector (const allocator_type& alloc = allocator_type()): _alloc(alloc)
			{
				_begin = _end = _capacity = NULL;
			}
			// Конструктор с 1 параметром (длина вектора)
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc)
			{
				if (n > max_size())
					throw std::length_error("vector");
				_begin = _alloc.allocate(n);
				_end = _capacity = _begin + n;
				for (pointer i = _begin; i != _end; i++)
					_alloc.construct(i, val);
			}
			// Конструктор с 2 параметрами (набор значений)
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type* = 0): _alloc(alloc)
			{
				size_type n = ft::distance(first, last);

				if (n > max_size())
					throw std::length_error("vector");
				_begin = _alloc.allocate(n);
				_end = _capacity = _begin + n;
				for (pointer i = _begin; first != last; first++, i++)
					_alloc.construct(i, *first);
			}
			// Конструктор копирования
			vector (const vector& x): _alloc(x.get_allocator())
			{
				size_type n = x.size();
				pointer pos, pos_copy = x._begin;

				_begin = pos = _alloc.allocate(n);
				_end = _capacity = _begin + n;
				for (size_type i = 0; i < n; i++, pos++, pos_copy++)
					_alloc.construct(pos, *(pos_copy));
			}
			//---------------------------------------------------------destructor(1/1)-----------------------------------------------------
			~vector ()
			{
				if (_begin != NULL)
				{
					clear();
					_alloc.deallocate(_begin, capacity());
					_begin = _end = _capacity = NULL;
				}
			}
			//---------------------------------------------------------operator=(1/1)------------------------------------------------------
			const vector			&operator=(const vector &x)
			{
				if (this != &x)
					assign(x._begin, x._end);
				return (*this);
			}
			//---------------------------------------------------------Iterators(8/8)------------------------------------------------------
			iterator				begin()										{ return (iterator(_begin)); }
			const_iterator			begin() const								{ return (const_iterator(_begin)); }
			iterator				end()										{ return (iterator(_end)); }
			const_iterator			end() const									{ return (const_iterator(_end)); }
			reverse_iterator		rbegin()									{ return (reverse_iterator(end())); }
			const_reverse_iterator	rbegin() const								{ return (const_reverse_iterator(end())); }
			reverse_iterator		rend()										{ return (reverse_iterator(begin())); }
			const_reverse_iterator	rend() const								{ return (const_reverse_iterator(begin())); }
			//---------------------------------------------------------Capacity(6/6)-------------------------------------------------------
			// Возвращает кол-во элементов вектора
			size_type				size() const								{ return (_end - _begin); }
			// Возвращает максимальное количество элементов, которое может содержать вектор
			size_type				max_size() const							{ return (_alloc.max_size()); }
			// Изменяет размер контейнера, чтобы он содержал n элементов
			void					resize(size_type n, value_type val = value_type())
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
			// Возвращает размер памяти выделенный для вектора в элементах
			size_type				capacity() const							{ return (_capacity - _begin); }
			// Пустой ли вектор?
			bool					empty() const								{ return (size() ? false : true); }
			// Пытается сделать ёмкость вектора как минимум достаточной для размещения n элементов
			void					reserve (size_type n)
			{
				pointer		begin_old = _begin, begin_temp = _begin, end_old = _end;
				size_type	capacity_old = capacity(), size_old = size();

				if (n > max_size())
					throw std::length_error("vector");
				else if (n > capacity())
				{
					_begin = _end = _alloc.allocate(n);
					_capacity = _begin + n;
					while (begin_old != end_old)
						_alloc.construct(_end++, *begin_old++);
					for (size_t i = 0; i < size_old; i++)
						_alloc.destroy(begin_temp + i);
					_alloc.deallocate(begin_temp, capacity_old);
				}
			}
			//------------------------------------------------------Element access(8/8)----------------------------------------------------
			// Доступ к элементу без защиты
			reference				operator[](size_type n)						{ return (*(_begin + n)); }
			const_reference			operator[](size_type n) const				{ return (*(_begin + n)); }
			// Доступ к элементу с защитой
			reference				at(size_type n)
			{
				if (n >= size())
					throw std::out_of_range("vector");
				return (*(_begin + n));
			}
			const_reference			at(size_type n) const
			{
				if (n >= size())
					throw std::out_of_range("vector");
				return (*(_begin + n));
			}
			// Возвращает ссылку на первый элемент вектора
			reference				front()										{ return (*_begin); }
			const_reference			front() const								{ return (*_begin); }
			// Возвращает ссылку на последний элемент вектора
			reference				back()										{ return (*(_end - 1)); }
			const_reference			back() const								{ return (*(_end - 1)); }
			//--------------------------------------------------------Modifiers(11/11)-----------------------------------------------------
			// Присваивает вектору новое содержимое, заменяя его текущее содержимое и соответствующим образом изменяя его размер
			template <class InputIterator>
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
			assign (InputIterator first, InputIterator last)
			{
				size_type	n = static_cast<size_type>(ft::distance(first, last));

				if (n >= 0)
				{
					size_type	capacity = this->capacity();

					clear();
					if (capacity >= n)
					{
						for(; first != last; first++, _end++)
							_alloc.construct(_end, *first);
					}
					else
					{
						pointer		begin_new = _alloc.allocate(n), end_new = begin_new, capacity_new = begin_new + n;

						for(; first != last; first++, end_new++)
							_alloc.construct(end_new, *first);
						_alloc.deallocate(_begin, capacity);
						_begin = begin_new;
						_end = end_new;
						_capacity = capacity_new;
					}
				}
			}
			void					assign (size_type n, const value_type& val)
			{
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
			// Добавляет новый элемент в конец вектора
			void					push_back (const value_type& val)
			{
				size_t size = this->size();

				if (_end == _capacity)
					reserve (size == 0 ? 1 : size * 2);
				_alloc.construct(_end, val);
				_end++;
			}
			// Удаляет последний элемент в векторе (вектор пуст -> неопределённое поведение)
			void					pop_back()
			{
				_alloc.destroy(&back());
				_end--;
			}
			// Вектор увеличивается путем вставки новых элементов (1 или нескольких)
			iterator				insert (iterator position, const value_type& val)
			{
				pointer		new_pos = NULL;
				size_type	size = this->size(), len_pos = position._ptr - _begin;

				if (_end == _capacity)
					reserve(size > 0 ? capacity() * 2 : 1);
				new_pos = _begin + len_pos;
				if (size > 0)
				{
					for (pointer i = _end; i >= new_pos; i--)
						_alloc.construct(i + 1, *i);
				}
				_alloc.construct(new_pos, val);
				_end++;
				return (iterator(new_pos));
			}
			void					insert (iterator position, size_type n, const value_type& val)
			{
				if (n != 0)
				{
					pointer		new_pos = NULL;
					size_type	size = this->size(), len_pos = position._ptr - _begin;

					if (_end + n > _capacity)
						reserve (std::max(size + n, capacity() * 2));
					new_pos = _begin + len_pos;
					if (size > 0)
					{
						for (pointer i = _end; i >= new_pos; i--)
							_alloc.construct(i + n, *i);
					}
					for (size_type i = 0; i < n; i++)
						_alloc.construct(new_pos + i, val);
					_end = _end + n;
				}
			}
			template <class InputIterator>
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
			insert (iterator position, InputIterator first, InputIterator last)
			{
				// }{уЁвый Алгоритм
				size_type	n = static_cast<size_type>(std::distance(first, last));

				if (!validate_iterator_values(first, last, n))
					throw std::exception();

				if (first != last)
				{
					pointer		new_pos = NULL;
					size_type	size = this->size(), len_pos = position._ptr - _begin;
					pointer		begin_new = _alloc.allocate(n), end_new = begin_new;


					for (; first != last; end_new++, first++)
						_alloc.construct(end_new, *first);

					if (_end + n > _capacity)
						reserve (std::max(capacity() + n, capacity() * 2));

					new_pos = _begin + len_pos;
					if (size > 0)
					{
						for (pointer i = _end - 1; i >= new_pos; i--)
							_alloc.construct(i + n, *i);
					}
					for (size_type i = 0; i < n; i++)
					{
						if (i < size - len_pos)
						{
							_alloc.destroy(new_pos + i);
							_alloc.construct(new_pos + i, *(begin_new + i));
						}
						else
							_alloc.construct(new_pos + i, *(begin_new + i));
					}
					_end = _end + n;

					for (size_type i = 0; i < n; i++)
						_alloc.destroy(begin_new + i);
					_alloc.deallocate(begin_new, n);
				}
			}
			// Удаляет из вектора элементы (1 или несколько) 
			iterator				erase (iterator position)
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
			iterator				erase (iterator first, iterator last)
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
			// Заменяет содержимое контейнера содержимым x , который является другим векторным объектом того же типа
			void					swap (vector& x)
			{
				if (this != &x)
				{
					std::swap(_begin, x._begin);
					std::swap(_end, x._end);
					std::swap(_capacity, x._capacity);
				}
			}
			// Удаляет все элементы из вектора
			void					clear()
			{
				size_type size = this->size();

				for (size_type i = 0; i < size; i++)
					_alloc.destroy(_end--);
			}
			//--------------------------------------------------------Allocator(1/1)-------------------------------------------------------
			allocator_type			get_allocator() const						{ return (_alloc); }
	};

	//---------------------------------------------------Non-member function overloads(7/7)------------------------------------------------
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
};

#endif
