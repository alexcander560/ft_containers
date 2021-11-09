#ifndef UTILS_HPP
#define UTILS_HPP

#include <iterator>
#include <cstddef>
#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <functional>
#include <cmath>

#include "reverse_iterator.hpp"
#include "iterator.hpp"
#include "pair.hpp"

namespace ft
{
	template <typename T>
	struct is_iterator
	{
		static T makeT();
		typedef void *twoptrs[2];
		static twoptrs &test(...);
		template <typename R> static typename R::iterator_category * test(R);
		template <typename R> static void * test(R *);

		static const bool value = sizeof(test(makeT())) == sizeof(void *);
	};

	template <class T, class A>
	class Vector;
	template <class Key, class T, class Compare, class A>
	class Map;

	template<class T, bool v>
	struct integral_constant
	{
		static const bool value = v;
		typedef T value_type;
		typedef integral_constant type;
		operator value_type() const { return value; }
	};
	template <class T> struct is_integral : public ft::integral_constant<T, false> {};
	template <> struct is_integral<bool> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<char> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<signed char> : public integral_constant<bool, true> {};
	template <> struct is_integral<unsigned char> : public integral_constant<bool, true> {};
	template <> struct is_integral<wchar_t> : public integral_constant<bool, true> {};
	template <> struct is_integral<char16_t> : public integral_constant<bool, true> {};
	template <> struct is_integral<short> : public integral_constant<bool, true> {};
	template <> struct is_integral<unsigned short> : public integral_constant<bool, true> {};
	template <> struct is_integral<int> : public integral_constant<bool, true> {};
	template <> struct is_integral<unsigned int> : public integral_constant<bool, true> {};
	template <> struct is_integral<long> : public integral_constant<bool, true> {};
	template <> struct is_integral<unsigned long> : public integral_constant<bool, true> {};
	template <> struct is_integral<long long> : public integral_constant<bool, true> {};
	template <> struct is_integral<unsigned long long> : public integral_constant<bool, true> {};

	template<bool B, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };


	template<class InputIt1, class InputIt2>
	inline bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}

	template<class InputIt1, class InputIt2>
	inline bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		while (first1!=last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			first1++;
			first2++;
		}
		return (first2!=last2);
	}

	template<class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
	distance (InputIterator first, InputIterator last)
	{
		typename ft::iterator_traits<InputIterator>::difference_type rtn = 0;
		while (first != last)
		{
			first++;
			rtn++;
		}
		return (rtn);
	}
}

#endif
