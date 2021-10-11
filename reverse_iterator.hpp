#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"

namespace ft
{
	template<typename _Iter>
	class reverse_iterator: public ft::iterator <	typename iterator_traits<_Iter>::iterator_category,
													typename iterator_traits<_Iter>::value_type,
													typename iterator_traits<_Iter>::difference_type,
													typename iterator_traits<_Iter>::pointer,
													typename iterator_traits<_Iter>::reference	>
	{
		protected:
			_Iter current;

		public:
			typedef _Iter												iterator_type;
			typedef typename iterator_traits<_Iter>::iterator_category	iterator_category;
			typedef typename iterator_traits<_Iter>::difference_type	difference_type;
			typedef typename iterator_traits<_Iter>::reference			reference;
			typedef typename iterator_traits<_Iter>::pointer			pointer;
			typedef typename iterator_traits<_Iter>::value_type			value_type;

			explicit reverse_iterator(): current() {}
			explicit reverse_iterator(_Iter itr): current(itr) {
				//std::cout << "Hello 111\n";
			}

			// new ??? походу заработало, я думал, что помру
			template <class Iter>
                reverse_iterator (const reverse_iterator<Iter>& rev_it)
                :
                    current(rev_it.base())
                {}

			iterator_type base() const { return (current); }

			reference			operator*() const					{ iterator_type tmp = current; return (*--tmp); }
			pointer				operator->() const					{ return (&(operator*())); }
			reverse_iterator	&operator++()						{ --current; return (*this); }
			reverse_iterator	operator++(int)						{ reverse_iterator tmp(*this); --current; return (tmp); }
			reverse_iterator	&operator--()						{ ++current; return (*this); }
			reverse_iterator	operator--(int)						{ reverse_iterator tmp(*this); ++current; return (tmp); }
			reverse_iterator	operator+ (difference_type n) const	{ return (reverse_iterator(current - n)); }
			reverse_iterator	&operator+=(difference_type n)		{ current -= n; return (*this); }
			reverse_iterator	operator- (difference_type n) const	{ return (reverse_iterator(current + n)); }
			reverse_iterator	&operator-=(difference_type n)		{ current += n; return (*this); }
			reference			operator[](difference_type n) const	{ return (*(*this + n)); }
	};

	template <class _Iter1, class _Iter2>
	inline bool operator==(const reverse_iterator<_Iter1>& x, const reverse_iterator<_Iter2>& y) { return (x.base() == y.base()); }

	template <class _Iter1, class _Iter2>
	inline bool operator<(const reverse_iterator<_Iter1>& x, const reverse_iterator<_Iter2>& y) { return (x.base() > y.base()); }

	template <class _Iter1, class _Iter2>
	inline bool operator!=(const reverse_iterator<_Iter1>& x, const reverse_iterator<_Iter2>& y) { return (x.base() != y.base()); }

	template <class _Iter1, class _Iter2>
	inline bool operator>(const reverse_iterator<_Iter1>& x, const reverse_iterator<_Iter2>& y) { return (x.base() < y.base()); }

	template <class _Iter1, class _Iter2>
	inline bool operator>=(const reverse_iterator<_Iter1>& x, const reverse_iterator<_Iter2>& y) { return (x.base() <= y.base()); }

	template <class _Iter1, class _Iter2>
	inline bool operator<=(const reverse_iterator<_Iter1>& x, const reverse_iterator<_Iter2>& y) { return (x.base() >= y.base()); }

	template <class _Iter1, class _Iter2>
	inline typename reverse_iterator<_Iter1>::difference_type operator-(const reverse_iterator<_Iter1>& x, const reverse_iterator<_Iter2>& y) { return (y.base() - x.base()); }

	template <class _Iter>
	inline reverse_iterator<_Iter> operator+(typename reverse_iterator<_Iter>::difference_type __n, const reverse_iterator<_Iter>& x) { return (reverse_iterator<_Iter>(x.base() - __n)); }
}

#endif
