#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template<typename T1, typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair(): first(), second() {
			//std::cout << "----------\nHello\n-------------\n";
		}

		template<class U, class V>
		pair (const pair<U,V>& pr): first(pr.first), second(pr.second) {
			//std::cout << "----------\nHello\n-------------\n";
		}

		pair (const first_type& a, const second_type& b) : first(a), second(b) {
			//std::cout << "----------\nHello\n-------------\n";
		}

		pair& operator=(pair const& pr)
		{
			if (*this == pr)
				return (*this);
			first = pr.first;
			second = pr.second;
			return (*this);
		}
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first==rhs.first && lhs.second==rhs.second); }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(lhs==rhs)); }

	template <class T1, class T2>
	bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second)); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(rhs<lhs)); }

	template <class T1, class T2>
	bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (rhs<lhs); }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(lhs<rhs)); }

	template <typename T1, typename T2>
	inline pair<T1,T2> make_pair(T1 x, T2 y) { return (pair<T1, T2>(x, y)); }
}

#endif
