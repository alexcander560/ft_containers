#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iterator>
# include <iterator>
# include <cstddef>
# include <iostream>
# include <string>

namespace ft
{		
	template < typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		//class RandomAccessVectorIterator;
		//class ConstRandomAccessVectorIterator;

		public:
			//------------------------------------------------------------------------
			//---------------------------typedef(7/12)--------------------------------
			//------------------------------------------------------------------------
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			//typedef RandomAccessVectorIterator				iterator;
			//typedef ConstRandomAccessVectorIterator			const_iterator;
			//typedef ft::reverse_iterator<iterator>			reverse_iterator;
			//typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			//typedef std::ptrdiff_t							difference_type;
			typedef std::size_t									size_type;

		private:
			allocator_type	_alloc;
			pointer			_begin;
			pointer			_end;
			pointer 		_capacity;

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
			void					clear()
			{
				_destruct_at_end(_begin());
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
				if (n > max_size())
					throw std::length_error("vector");
				_begin = _alloc.allocate(n);
				_end = _begin + n;
				_capacity = _end;
				for (pointer i = _begin; i != _end; i++)
					_alloc.construct(i, val);
			}
			// Конструктор с 2 параметрами (набор значений)
			//template <class InputIterator>
			//vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			// Конструктор копирования
			vector (const vector& x): _alloc(x.get_allocator())
			{
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
			}
			//------------------------------------------------------------------------
			//------------------------------destructor(1/1)---------------------------
			//------------------------------------------------------------------------
			~vector ()
			{
				if (_begin != NULL)
				{
					while (_end != _begin)
						_alloc.destroy(--_end);
					_alloc.deallocate(_begin, capacity());
					_begin = NULL;
					_end = NULL;
					_capacity = NULL;
				}
			}
			//------------------------------------------------------------------------
			//------------------------------operator=(0/1)----------------------------
			//------------------------------------------------------------------------
			// const vector &operator=(const vector &x);
			//------------------------------------------------------------------------
			//------------------------------Iterators(0/8)----------------------------
			//------------------------------------------------------------------------
			// iterator					begin()			{ return iterator(_begin); }
			// const_iterator			begin() const	{ return const_iterator(_begin); }
			// iterator					end()			{ return iterator(_end); }
			// const_iterator			end() const 	{ return const_iterator(_end); }
			// reverse_iterator			rbegin() 		{ return reverse_iterator(begin()); }
			// const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(begin()); }
			// reverse_iterator			rend()			{ return reverse_iterator(end()); }
			// const_reverse_iterator	rend() const	{ return const_reverse_iterator(end()); }
			//------------------------------------------------------------------------
			//------------------------------Capacity(4/6)-----------------------------
			//------------------------------------------------------------------------
			// Возвращает длину вектора
			size_type	size() const					{ return (_end - _begin); }
			// Возвращает максимальное количество элементов, которое может содержать вектор
			size_type	max_size() const				{ return (_alloc.max_size()); }
			// Изменяет размер контейнера, чтобы он содержал n элементов
			//void		resize(size_type n, value_type val = value_type());
			// Возвращает размер памяти выделенный для вектора в элементах
			size_type	capacity() const				{ return _capacity - _begin; }
			// Пустой ли вектор?
			bool		empty() const					{ return (size() ? false : true); }
			// Пытается сделать ёмкость вектора как минимум достаточной для размещения n элементов
			// void		reserve (size_type n);
			//------------------------------------------------------------------------
			//---------------------------Element access(8/8)--------------------------
			//------------------------------------------------------------------------
			// Доступ к элементу без защиты
			reference		operator[](size_type n)			{ return *(_begin + n); }
			// Доступ к элементу без защиты
			const_reference operator[](size_type n) const	{ return *(_begin + n); }
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
			//-----------------------------Modifiers(0/11)----------------------------
			//------------------------------------------------------------------------
			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last);
			// void assign (size_type n, const value_type& val);
			// void push_back (const value_type& val);
			// void pop_back();
			// iterator insert (iterator position, const value_type& val);
			// void insert (iterator position, size_type n, const value_type& val);
			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last);
			// iterator erase (iterator position);
			// iterator erase (iterator first, iterator last);
			// void swap (vector& x);
			// void clear();
			//------------------------------------------------------------------------
			//-----------------------------Allocator(1/1)-----------------------------
			//------------------------------------------------------------------------
			allocator_type	get_allocator() const	{ return (_alloc); }
		private:
	};

	//------------------------------------------------------------------------
	//-------------------Non-member function overloads(6/7)-------------------
	//------------------------------------------------------------------------
	typedef	std::size_t		size_type;
	template <typename T, typename Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		size_type lhs_size = lhs.size(), rhs_size = rhs.size();

		if (lhs_size != rhs_size)
			return (false);
		for (size_type i = 0; i < lhs_size; i++)
		{
			if (lhs[i] != rhs[i])
				return (false);
		}
		return (true);
	};
	template <typename T, typename Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs == rhs); }
	template <typename T, typename Alloc> bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
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
	};
	template <typename T, typename Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)										{ return (!(rhs < lhs)); }
	template <typename T, typename Alloc> bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return (rhs < lhs); }
	template <typename T, typename Alloc> bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return (!(lhs < rhs)); }
	//void swap (vector& x);

	//vector<bool> необязательно!
};

#endif
