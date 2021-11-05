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

	template<typename T, T v>
	struct integral_constant
	{
		static T value = v;
		typedef T value_type;
		typedef integral_constant type;
		operator value_type() const		{ return (value); }
		value_type operator()() const	{ return (value); }
	};

	template <bool is_integral, typename T> struct is_integral_res
	{
		typedef T type;
		static const bool value = is_integral;
	};

	template <typename>
	struct is_integral_type : public is_integral_res<false, bool> {};
	template <>
	struct is_integral_type<bool> : public is_integral_res<true, bool> {};
	template <>
	struct is_integral_type<char> : public is_integral_res<true, char> {};
	template <>
	struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};
	template <>
	struct is_integral_type<short int> : public is_integral_res<true, short int> {};
	template <>
	struct is_integral_type<int> : public is_integral_res<true, int> {};
	template <>
	struct is_integral_type<long int> : public is_integral_res<true, long int> {};
	template <>
	struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};
	template <>
	struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};
	template <>
	struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};
	template <>
	struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};
	template <>
	struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
	template <>
	struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

	// Проверяет, является ли тип T целым
	template <typename T>
	struct is_integral : public is_integral_type<T> { };


	// Условно создает экземпляр типа для разрешения перегрузки
	template<bool B, typename T = void> struct enable_if {};
	// enable_if<Condition,Type>::type существует — и является синонимом для Type — только в том случае, если Condition имеет значение true
	template<typename T> struct enable_if<true, T> { typedef T type; };

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
}

#endif
