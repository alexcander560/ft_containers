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
	template < typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		class RandomAccessVectorIterator;
		class ConstRandomAccessVectorIterator;
		public:
			//------------------------------------------------------------------------
			//---------------------------typedef(7/12)--------------------------------
			//------------------------------------------------------------------------
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef RandomAccessVectorIterator					iterator;
			typedef ConstRandomAccessVectorIterator				const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;

		private:
			allocator_type	_alloc;
			pointer			_begin;
			pointer			_end;
			pointer 		_capacity;

			class RandomAccessVectorIterator : public ft::iterator<std::random_access_iterator_tag, value_type>
			{
				typedef ft::iterator<std::random_access_iterator_tag, value_type>	parent;
				typedef RandomAccessVectorIterator									self;
			
				public:
					typedef typename parent::reference							reference;
					typedef typename parent::pointer							pointer;
			
					RandomAccessVectorIterator(pointer begin = NULL) : _ptr(begin) {}
					RandomAccessVectorIterator(const self &copy) : _ptr(copy._ptr) {}
					~RandomAccessVectorIterator() {};

					const self &operator=(const self &it) { if (this != &it) _ptr = it._ptr; return *this; }
						
					reference	operator*()		{ return *_ptr; }

					pointer		operator->()	{ return _ptr; }

					self&		operator++()	{ ++_ptr; return *this; }

					self		operator++(int) { self tmp = *this; ++(*this);  return tmp; } 

					self&		operator--()	{ --_ptr; return *this; }
					
					self		operator--(int) { self tmp = *this; --(*this);  return tmp; }
					
					friend difference_type operator- (const self& a, const self& b) { return a._ptr - b._ptr; }
					
					friend bool operator== (const self& a, const self& b) { return a._ptr == b._ptr; }
					
					friend bool operator!= (const self& a, const self& b) { return !(a == b); }
					
					friend bool operator< (const self lhs, const self rhs)		{ return lhs._ptr < rhs._ptr; }

					friend bool operator<= (const self lhs, const self rhs)	{ return !(rhs._ptr < lhs._ptr); }

					friend bool operator> (const self lhs, const self rhs)		{ return rhs < lhs; }

					friend bool operator>= (const self lhs, const self rhs)	{ return !(lhs < rhs); }
					
					self  operator+ (difference_type n) const	{ return self(_ptr + n); }

					self& operator+=(difference_type n)			{ _ptr + n; return *this; }

					self  operator- (difference_type n) const	{ return *this + (-n); }

					self& operator-=(difference_type n)			{ return *this += -n; }

					reference operator[](difference_type n) const { return _ptr[n]; }

				private:	
					pointer	_ptr;
					template<typename, typename> friend class vector;
			};
			class ConstRandomAccessVectorIterator : public ft::iterator<std::random_access_iterator_tag, const value_type>
			{
				typedef ft::iterator<std::random_access_iterator_tag, const value_type> 	parent;
				typedef RandomAccessVectorIterator										nonconst_v;
				typedef ConstRandomAccessVectorIterator									self;
			
				public:
					typedef typename parent::reference									reference;
					typedef typename parent::pointer									pointer;
			
					ConstRandomAccessVectorIterator(const nonconst_v &it) : _ptr(it._ptr) {}
					ConstRandomAccessVectorIterator(pointer begin = NULL) : _ptr(begin) {}
					ConstRandomAccessVectorIterator(const self &copy) : _ptr(copy._ptr) {}
					~ConstRandomAccessVectorIterator() {};

					const self &operator=(const self &it) { if (this != &it) _ptr = it._ptr; return *this; }
						
					reference	operator*()		{ return *_ptr; }

					pointer		operator->()	{ return _ptr; }

					self&		operator++()	{ ++_ptr; return *this; }

					self		operator++(int) { self tmp = *this; ++(*this);  return tmp; } 

					self&		operator--()	{ --_ptr; return *this; }
					
					self		operator--(int) { self tmp = *this; --(*this);  return tmp; }
					
					friend difference_type operator- (const self& a, const self& b) { return a._ptr - b._ptr; }

					friend bool operator== (const self& a, const self& b) { return a._ptr == b._ptr; }
					
					friend bool operator!= (const self& a, const self& b) { return !(a == b); }
					
					friend bool operator< (const self lhs, const self rhs)		{ return lhs._ptr < rhs._ptr; }

					friend bool operator<= (const self lhs, const self rhs)	{ return !(rhs._ptr < lhs._ptr); }

					friend bool operator> (const self lhs, const self rhs)		{ return rhs < lhs; }

					friend bool operator>= (const self lhs, const self rhs)	{ return !(lhs < rhs); }
					
					self  operator+ (difference_type n) const	{ return self(_ptr + n); }

					self& operator+=(difference_type n)			{ _ptr + n; return *this; }

					self  operator- (difference_type n) const	{ return *this + (-n); }

					self& operator-=(difference_type n)			{ return *this += -n; }

					reference operator[](difference_type n) const { return _ptr[n]; }

				private:	
					pointer	_ptr;
			};

			size_type				_sz() const			{ return _end - _begin; }
			void					_throw_length_error() const { throw std::length_error("vector"); }
			void					_throw_out_of_range() const { throw std::out_of_range("vector"); }
			size_type				_get_new_cap(size_type new_size) const
			{
				const size_type ms 	= max_size();
				const size_type cap = capacity();

				if (new_size > max_size())
					_throw_length_error();
				if (cap >= ms / 2)
					return ms;
				return std::max<size_type>(cap * 2, new_size);
			}
			void					_nallocate(size_type n)
			{
				if (n > max_size())
					_throw_length_error();
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
				const size_type csz = _sz();
				pointer new_buf		= _allocate_and_copy(n);
		
				_deallocate();
				_begin = new_buf;
				_end = new_buf + csz;
				_capacity = new_buf + n;
			}
			pointer					_allocate_and_copy(const size_type new_cap)
			{
				pointer	new_buf = _alloc.allocate(new_cap);
				
				_copy(new_buf, _begin, _sz());
				return new_buf;
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
			void					_construct_at_end(InputIterator first, InputIterator last,
										typename enable_if<is_iterator<InputIterator>::value>::type* = 0)
			{	
				pointer pos = _end; 
				for (; first != last; ++first, ++pos)
					_alloc.construct(pos, *first);
				_end = pos;
			}
			void					_append(size_type n, const_reference val)
			{
				if (static_cast<size_type>(_capacity - _end) >= n)
					_construct_at_end(n, val);
				else
				{
					_reallocate(_get_new_cap(_sz() + n));
					_construct_at_end(n, val);
				}
			}
			pointer					_reallocate_with_insert(pointer position, const_reference val, size_type n = 1)
			{
				const size_type	newsz	= _sz() + n;
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
			pointer					_reallocate_with_insert(pointer position, InputIterator first, InputIterator last,
															typename enable_if<is_iterator<InputIterator>::value>::type* = 0)
			{
				const size_type n		= static_cast<size_type>(std::distance(first, last));
				const size_type	newsz	= _sz() + n;
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
			void					_insert_not_end(pointer position, InputIterator first, InputIterator last,
													typename enable_if<is_iterator<InputIterator>::value>::type* = 0)
			{
				const size_type n		= static_cast<size_type>(std::distance(first, last));
				pointer			end_copy_pos;
				
				for (size_type i = 1; i <= n; ++i)
				{
					const_pointer pval;
					
					end_copy_pos = _end - i;	
					if (end_copy_pos >= _begin)
						pval = end_copy_pos;
					else
						pval = &(*--last);
					_alloc.construct(_end + n - i, *pval);
				}
				for (pointer p = end_copy_pos - 1; p > position - 1; --p)
					*(p + n) = *p;
				for (; first != last; ++first, ++position)
					*position = *first;
				_end += n;
			}

		public:
			//------------------------------------------------------------------------
			//------------------------------constructor(3/4)--------------------------
			//------------------------------------------------------------------------
			// Конструктор без параметров
			explicit vector (const allocator_type& alloc = allocator_type()): _begin(NULL), _end(NULL), _capacity(NULL), _alloc(alloc) {}
			// Конструктор с 1 параметром (длина вектора)
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc)
			{
				_nallocate(n);
				_construct_at_end(n, val);
				/*
				if (n > max_size())
					throw std::length_error("vector");
				_begin = _alloc.allocate(n);
				_end = _begin + n;
				_capacity = _end;
				for (pointer i = _begin; i != _end; i++)
					_alloc.construct(i, val);
				*/
			}
			// Конструктор с 2 параметрами (набор значений)
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			{
				_nallocate(std::distance(first, last));
				_construct_at_end(first, last);
			}
			// Конструктор копирования
			vector (const vector& x): _alloc(x.get_allocator())
			{
				pointer pos;
				size_type n = x.size();

				_nallocate(n);
				pos = _begin;
				for (size_type i = 0; i < n; ++i, ++pos)
					_alloc.construct(pos, *(x._begin + i));
				_end = pos;
				/*
				pointer pos;
				size_type n = x.size();

				if (n > max_size())
					throw std::length_error("vector");
				_begin = _alloc.allocate(n);
				pos = _begin;
				_end = _begin + n;
				_capacity = _end;
				for (size_type i = 0; i < n; i++, ++pos)
					_alloc.construct(pos, *(x._begin + i));
				*/
			}
			//------------------------------------------------------------------------
			//------------------------------destructor(1/1)---------------------------
			//------------------------------------------------------------------------
			~vector ()
			{
				_deallocate();
				/*
				if (_begin != NULL)
				{
					while (_end != _begin)
						_alloc.destroy(--_end);
					_alloc.deallocate(_begin, capacity());
					_begin = NULL;
					_end = NULL;
					_capacity = NULL;
				}
				*/
			}
			//------------------------------------------------------------------------
			//------------------------------operator=(0/1)----------------------------
			//------------------------------------------------------------------------
			const vector &operator=(const vector &x)
			{
				if (this != &x)
				{
					assign(x.begin, x.end);
				}
				return *this;
			}
			//------------------------------------------------------------------------
			//------------------------------Iterators(0/8)----------------------------
			//------------------------------------------------------------------------
			iterator				begin()			{ return iterator(_begin); }
			const_iterator			begin() const	{ return const_iterator(_begin); }
			iterator				end()			{ return iterator(_end); }
			const_iterator			end() const 	{ return const_iterator(_end); }
			reverse_iterator		rbegin() 		{ return reverse_iterator(begin()); }
			const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(begin()); }
			reverse_iterator		rend()			{ return reverse_iterator(end()); }
			const_reverse_iterator	rend() const	{ return const_reverse_iterator(end()); }
			//------------------------------------------------------------------------
			//------------------------------Capacity(5/6)-----------------------------
			//------------------------------------------------------------------------
			// Возвращает длину вектора
			size_type	size() const					{ return (_end - _begin); }
			// Возвращает максимальное количество элементов, которое может содержать вектор
			size_type	max_size() const				{ return (_alloc.max_size()); }
			// Изменяет размер контейнера, чтобы он содержал n элементов
			void		resize(size_type n, value_type val = value_type())
			{
				const size_type size_temp = size();

				if (size_temp < n)
					_append(n - size_temp, val);
				else if (size_temp > n)
					_destruct_at_end(_begin + n);
			}
			// Возвращает размер памяти выделенный для вектора в элементах
			size_type	capacity() const				{ return _capacity - _begin; }
			// Пустой ли вектор?
			bool		empty() const					{ return (size() ? false : true); }
			// Пытается сделать ёмкость вектора как минимум достаточной для размещения n элементов
			void		reserve (size_type n)
			{
				if (n > capacity())
				{
					_reallocate(n);
				}
				/*
				if (n > max_size())
					throw std::length_error("vector");
				else if (n > capacity())
				{
					size_type size_temp = size();
					pointer	new_buf = _alloc.allocate(n);

					for (size_type i = 0; i < n; ++i)
						_alloc.construct(new_buf + i, _begin[i]);
					if (_begin != NULL)
					{
						while (_end != _begin)
							_alloc.destroy(--_end);
						_alloc.deallocate(_begin, capacity());
					}
					_begin = new_buf;
					_end = new_buf + size_temp;
					_capacity = new_buf + n;
				}
				*/
			}
			//------------------------------------------------------------------------
			//---------------------------Element access(8/8)--------------------------
			//------------------------------------------------------------------------
			// Доступ к элементу без защиты
			reference		operator[](size_type n)			{ return *(_begin + n); }
			// Доступ к элементу без защиты
			const_reference operator[](size_type n) const	{
				//std::cout << "Hello\n"; 
				return *(_begin + n); }
			// Доступ к элементу с защитой
			reference 		at(size_type n)
			{
				if (n >= size())
					throw std::out_of_range("vector");
				return (*(_begin + n));
			}
			// Доступ к элементу с защитой
			const_reference at(size_type n) const
			{
				if (n >= size())
					throw std::out_of_range("vector");
				return (*(_begin + n));
			}
			// Возвращает ссылку на первый элемент вектора
			reference		front()							{ return (*_begin); }
			// Возвращает ссылку на первый элемент вектора
			const_reference front() const					{ return (*_begin); }
			// Возвращает ссылку на последний элемент вектора
			reference 		back()							{ return (*(_end - 1)); }
			// Возвращает ссылку на последний элемент вектора
			const_reference back() const					{ return (*(_end - 1)); }
			//------------------------------------------------------------------------
			//-----------------------------Modifiers(3/11)----------------------------
			//------------------------------------------------------------------------
			template <class InputIterator>
			//Присваивает вектору новое содержимое, заменяя его текущее содержимое и соответствующим образом изменяя его размер
			void assign (InputIterator first, InputIterator last)
			{
				size_type csz = static_cast<size_type>(std::distance(first, last));

				if (capacity() < csz)
				{
					_deallocate();
					_nallocate(csz);
					_construct_at_end(first, last);
				}
				else
				{
					size_t n = static_cast<size_type>(std::min(csz, _sz()));

					for (size_type i = 0; i < n; ++i, ++first)
						*(_begin + i) = *first;
					if (_sz() > n)	
						_destruct_at_end(_begin + n);
					else
						_construct_at_end(first, last);
				}
			}
			//Присваивает вектору новое содержимое, заменяя его текущее содержимое и соответствующим образом изменяя его размер
			void assign (size_type n, const value_type& val)
			{
				if (capacity() < n)
				{
					_deallocate();
					_nallocate(n);
					_construct_at_end(n, val);
				}
				else
				{
					size_t sz  = _sz();
					size_t end = static_cast<size_type>(std::min(sz, n));

					for (size_type i = 0; i < end; ++i)
						*(_begin + i) = val;
					if (sz > n)
						_destruct_at_end(_begin + n);
					else
						_construct_at_end(n - sz, val);
				}
			}
			// Добавляет новый элемент в конец вектора
			void push_back (const value_type& val)
			{
				if (_end == _capacity)
					_reallocate(_get_new_cap(_sz() + 1));
				_construct_one_at_end(val);
			}
			// Удаляет последний элемент в векторе (вектор пуст -> неопределённое поведение)
			void pop_back()
			{
				_destruct_at_end(_end - 1);
				/*
				_alloc.destroy(_end - 1);
				_end = _end - 1;
				*/
			}
			// Вектор увеличивается путем вставки новых элементов до элемента в заданном положении
			iterator insert (iterator position, const value_type& val)
			{
				pointer p = position._ptr;

				if (_end < _capacity)
				{
					if (p == _end)
						_construct_one_at_end(val);
					else
						_insert_not_end(p, val);
				}
				else
				{
					p = _reallocate_with_insert(p, val);
				}
				return iterator(p);
			}
			// Вектор увеличивается путем вставки новых элементов до элемента в заданном положении
			void insert (iterator position, size_type n, const value_type& val)
			{
				//std::cout << "Hello\n";
				pointer p = position._ptr;

				if (_end < _capacity)
				{
					if (p == _end)
						_construct_at_end(n, val);
					else
						_insert_not_end(p, val, n);
				}
				else
					_reallocate_with_insert(p, val, n);
			}
			// Вектор увеличивается путем вставки новых элементов до элемента в заданном положении
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last)
			{
				//std::cout << "SSS\n";
				pointer p = position._ptr;
				
				if (_end < _capacity)
				{
					if (p == _end)
						_construct_at_end(first, last);
					else
						_insert_not_end(p, first, last);
				}
				else
					_reallocate_with_insert(p, first, last);
			}
			//Удаляет из вектора один элемент 
			iterator erase (iterator position)
			{
				pointer p = position._ptr;

				if ( p == _end - 1)
					_destruct_at_end(p);
				else
				{
					size_type sz = static_cast<size_type>((_end - p - 1) * sizeof(value_type));
					
					_alloc.destroy(p);
					std::memmove(p, p + 1, sz);
					--_end;
				}
				return iterator(p);
			}
			//Удаляет из вектора диапазон элементов
			iterator erase (iterator first, iterator last)
			{
				pointer		fp = first._ptr;
				pointer		lp = last._ptr;

				//std::cout << "Hello\n";

				if (lp == _end)
					_destruct_at_end(fp);
				else
				{
					size_type i		= 0; 
					size_type sz	= static_cast<size_type>((_end - lp) * sizeof(value_type));
					
					for (; fp + i != lp; ++i)
						_alloc.destroy(fp + i);
					std::memmove(fp, lp, sz);
					_end -= i;
				}
				return iterator(fp);
			}
			// Заменяет содержимое контейнера содержимым x , который является другим векторным объектом того же типа
			void swap (vector& x)
			{
				if (this != &x)
				{
					std::swap(_begin, x._begin);
					std::swap(_end, x._end);
					std::swap(_capacity, x._capacity);
				}
			}
			// Удаляет все элементы из вектора
			void clear()
			{
				_destruct_at_end(_begin);
				/*
				while (_end != _begin)
					_alloc.destroy(--_end);
				_end = _begin;
				*/
			}
			//------------------------------------------------------------------------
			//-----------------------------Allocator(1/1)-----------------------------
			//------------------------------------------------------------------------
			allocator_type	get_allocator() const	{ return (_alloc); }
	};

	//------------------------------------------------------------------------
	//-------------------Non-member function overloads(7/7)-------------------
	//------------------------------------------------------------------------
	typedef	std::size_t		size_type;
	template <typename T, typename Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin());
		/*
		size_type lhs_size = lhs.size(), rhs_size = rhs.size();

		if (lhs_size != rhs_size)
			return (false);
		for (size_type i = 0; i < lhs_size; i++)
		{
			if (lhs[i] != rhs[i])
				return (false);
		}
		return (true);
		*/
	};
	template <typename T, typename Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return !(lhs == rhs); }
	template <typename T, typename Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		/*
		size_type lhs_size = lhs.size(), rhs_size = rhs.size();

		if (lhs_size < rhs_size)
			return (true);
		else if (lhs_size > rhs_size)
			return (true);
		else
		{
			for (size_type i = 0; i < lhs_size; i++)
			{
				if (lhs[i] < rhs[i])
					return (true);
				else if (lhs[i] > rhs[i])
					return (false);
			}
		}
		return (false);
		*/
	};
	template <typename T, typename Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return (!(rhs < lhs)); }
	template <typename T, typename Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return (rhs < lhs); }
	template <typename T, typename Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return (!(lhs < rhs)); }
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)							{ x.swap(y); }

	//vector<bool> необязательно!
};

#endif
