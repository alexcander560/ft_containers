#ifndef MAP_HPP
#define MAP_HPP

#include <iterator>
#include <cstddef>
#include <algorithm>
#include <stdexcept>
#include <functional>

#include "utils.hpp"

namespace ft
{		
	template < typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<pair<const Key,T> > >
	class map
	{
		struct node;
		class AVLTree;
		class BidirectionalMapIterator;
		class ConstBidirectionalMapIterator;

		public:
			//---------------------------typedef(15/15)-------------------------------
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef	pair<const key_type, mapped_type>			value_type;
			typedef Alloc										allocator_type;
			typedef Compare										key_compare;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef	BidirectionalMapIterator					iterator;
			typedef ConstBidirectionalMapIterator				const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef	std::size_t									size_type;

			class value_compare: public std::binary_function <value_type, value_type, bool>
			{
				protected:
					Compare	comp;
					value_compare (Compare c): comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const { return (comp(x.first, y.first)); }
			};

		private:
			AVLTree					__tree;

			AVLTree&				_tree()						{ return __tree; }

			const AVLTree&			_tree() const				{ return __tree; }

			void					_throw_out_of_range() const	{ throw std::out_of_range("map"); }

		public:
			//------------------------------constructor(0/3)--------------------------
			// Конструктор без параметров
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): __tree(comp, alloc){}
			// Конструктор с 2 параметрами (набор значений)
			template <typename InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), typename enable_if<is_iterator<InputIterator>::value>::type* = 0): __tree(comp, alloc)
			{
				insert(first, last);
			}
			// Конструктор копирования
			map (const map& x): __tree(x.__tree){}
			//------------------------------destructor(0/1)---------------------------
			~map () {}
			//------------------------------operator=(0/1)----------------------------
			const map							&operator=(const map &c)
			{
				_tree() = c._tree();
				return *this;
			}
			//------------------------------Iterators(0/8)----------------------------
			iterator							begin()												{ return _tree().begin(); }
			const_iterator						begin() const										{ return _tree().begin(); }
			iterator							end()												{ return _tree().end(); }
			const_iterator						end() const											{ return _tree().end(); }
			reverse_iterator					rbegin()											{ return reverse_iterator(begin()); }
			const_reverse_iterator				rbegin() const										{ return const_reverse_iterator(begin()); }
			reverse_iterator					rend()												{ return reverse_iterator(end()); }
			const_reverse_iterator				rend() const										{ return const_reverse_iterator(end()); }
			//------------------------------Capacity(0/3)-----------------------------
			// Пустая ли мапа?
			bool								empty() const										{ return _tree().size() == 0; }
			// Возвращает кол-во элементов мапы
			size_type							size() const 										{ return _tree().size(); }
			// Возвращает максимальное количество элементов, которое может содержать мапа
			size_type							max_size() const									{ return (_tree().get_allocator().max_size()); }
			//---------------------------Element access(0/1)--------------------------
			// Если k соответствует ключу элемента в контейнере, функция возвращает ссылку на его отображаемое значение
			mapped_type& 						operator[] (const key_type& k)						{ return (*insert(make_pair(k, mapped_type())).first).second; }
			//-----------------------------Modifiers(0/8)-----------------------------
			// Мапа увеличивается путем вставки нового элемента, если ключ уникален
			pair<iterator, bool>				insert (const value_type& val)						{ return _tree().insert(val); }
			// Мапа увеличивается путем вставки новых элементов, только с уникальными ключами
			iterator							insert (iterator position, const value_type& val)	{ return _tree().insert(position, val); }
			// Мапа увеличивается путем вставки новых элементов, только с уникальными ключами
			template <typename InputIterator>
			void								insert (InputIterator first, InputIterator last, typename enable_if<is_iterator<InputIterator>::value>::type* = 0)
			{
				for (; first != last; ++first)
					insert(*first);
			}
			// Удаляет из мапы один элемент(по позиции)
			void								erase(iterator position)							{ _tree().erase(position); }
			// Удаляет из мапы один элемент (по ключу)
			size_type							erase(const key_type& k)							{ return _tree().erase(k); }
			// Удаляет из мапы диапазон элементов
			void erase(iterator first, iterator last)
			{
				while (first != last)
					erase(first++);
			}
			// Заменяет содержимое контейнера содержимым x ,который является другим объектом того же типа
			void								swap (map& x)										{ _tree().swap(x._tree()); }
			// Удаляет все элементы из мапы
			void								clear()												{ _tree().clear(); }
			//-----------------------------Observers(0/2)-----------------------------
			// Возвращает копию объекта сравнения, используемого контейнером для сравнения ключей
			key_compare 						key_comp() const									{ return key_compare(); }
			// Возвращает объект сравнения, который можно использовать для сравнения двух элементов
			value_compare 						value_comp() const									{ return value_compare(); }


			//-----------------------------Allocator(0/1)-----------------------------
			allocator_type						get_allocator() const								{ return _tree().get_allocator(); }
			//-----------------------------Operations(0/9)----------------------------
			// Ищет в контейнере элемент с ключом, эквивалентным k, и возвращает ему итератор, если он найден
			iterator							find (const key_type& k)							{ return _tree().find(k); }
			const_iterator						find (const key_type& k) const						{ return _tree().find(k); }
			// Ищет в контейнере элементы с ключом, эквивалентным k, и возвращает количество совпадений
			size_type							count (const key_type& k) const						{ return _tree().count(k); }
			// Возвращает итератор, указывающий на первый элемент в контейнере, ключ которого не считается предшествующим k
			iterator							lower_bound (const key_type& k)						{ return _tree().lower_bound(k); }
			const_iterator						lower_bound (const key_type& k) const				{ return _tree().lower_bound(k); }
			// Возвращает итератор, указывающий на первый элемент в контейнере, ключ которого считается идущим после k
			iterator							upper_bound (const key_type& k)						{ return _tree().upper_bound(k); }
			const_iterator						upper_bound (const key_type& k) const				{ return _tree().upper_bound(k); }
			// Возвращает границы диапазона, который включает все элементы в контейнере с ключом, эквивалентным k
			pair<const_iterator,const_iterator>	equal_range (const key_type& k) const				{ return make_pair(lower_bound(k), upper_bound(k)); }
			pair<iterator,iterator>				equal_range (const key_type& k)						{ return make_pair(lower_bound(k), upper_bound(k)); }

    private:
			// ----------------------!!!!!!!! РЕАЛИЗАЦИЯ ДЕРЕВА !!!!!!!!------------------------------
			struct node {
                pointer data;
                size_t height;
                node *parent;
                node *left;
                node *right;

                node(pointer d, node* p = NULL) :
                        data(d), height(1), parent(p), left(NULL), right(NULL)
                        {};
			};

			class AVLTree
			{
				private:
					node*           _root;
					key_compare     _kc;
					size_type       _size;
					allocator_type  _alloc;

					node *_newnode(const_reference v, node* parent = NULL)
                    {
					    pointer data = _alloc.allocate(1);
					    _alloc.construct(data, v);
					    return new node(data, parent);
                    }

                    void _delnode(node* p)
                    {
                        _alloc.destroy(p->data);
                        _alloc.deallocate(p->data, 1);
                        delete p;
                    }

                    static size_t _height(node* p)
					{
						return p ? p->height : 0;
					}

					static int _bfactor(node* p)
					{
						return _height(p->right) - _height(p->left);
					}

					static void _fixheight(node* p)
					{
						p->height = std::max(_height(p->left), _height(p->right)) + 1;
					}

					static bool _is_left_branch(const node *n)
					{
						return n->parent != NULL && n->parent->left == n;
					}

					static void _assign_new_parent(node *n, node *new_parent, bool is_left)
					{
						if (n != NULL)
							n->parent = new_parent;
						if (new_parent != NULL)
						{
							if (is_left)
								new_parent->left = n;
							else
								new_parent->right = n;
						}
					}

					static void _make_parent(node *new_parent, node *n)
					{
						_assign_new_parent(new_parent, n->parent, _is_left_branch(n));
						n->parent = new_parent;
					}

					static void	_assign_branch(node **dest, node *new_branch, node* parent)
					{
						*dest = new_branch;
						if (*dest) (*dest)->parent = parent;
					}

					static node* _rotateright(node* p)
					{
						node* q = p->left;
						_assign_branch(&p->left, q->right, p);
						q->right = p;
						_make_parent(q, p);
						_fixheight(p);
						_fixheight(q);
						return q;
					}

					static node* _rotateleft(node* q)
					{
						node* p = q->right;
						_assign_branch(&q->right, p->left, q);
						p->left = q;
						_make_parent(p, q);
						_fixheight(q);
						_fixheight(p);
						return p;
					}

					static node* __balance(node* p)
					{
						_fixheight(p);
						if (_bfactor(p) == 2)
						{
							if (_bfactor(p->right) < 0)
                                p->right = _rotateright(p->right);
							return _rotateleft(p);
						}
						if (_bfactor(p) == -2)
						{
							if (_bfactor(p->left) > 0)
								p->left = _rotateleft(p->left);
							return _rotateright(p);
						}
						return p;
					}
			
					static node* _balance(node* p)
					{
                        for (;;)
						{
							p = __balance(p);
							if (p->parent)
								p = p->parent;
							else
								return p;
						}
                    }

					static node* _findmin(node* p)
					{
						return p && p->left ? _findmin(p->left) : p;
					}

					static node* _removemin(node* p)
					{
						if (p->left == NULL)
							return p->right;
						p->left = _removemin(p->left);
						return __balance(p);
					}

                    node* _delnode_with_rebalance(node* p)
                    {
                        node* q = p->left;
                        node* r = p->right;
						node* parent = p->parent;
                        node* res;

						if (r == NULL)
						{
							_assign_new_parent(q, parent, _is_left_branch(p));
							res = q;
						}
						else
						{
                        	node* min = _findmin(r);
							_assign_new_parent(min, parent, _is_left_branch(p));
							_assign_branch(&min->right, _removemin(r), min);
                        	_assign_branch(&min->left, q, min);
							res = min;
						}
						_delnode(p);
						return res ? _balance(res) : 
									parent ? _balance(parent) : NULL;
                    }

                    node* _find(node* n, const key_type k) const
                    {
                        if (n == NULL)
                            return NULL;
                        if (_kc(k, n->data->first))
                            return _find(n->left, k);
                        if (_kc(n->data->first, k))
                            return _find(n->right, k);
                        else
                            return n;
                    }

                    pair<iterator, bool> _make_insert_pair(node* n, bool is_inserted) const
                    {
					    return make_pair(iterator(n, this), is_inserted);
                    }

                    pair<iterator, bool> _insert(node* p, const_reference v)
					{
					    if (p == NULL) return _make_insert_pair(_newnode(v), true);
                        for (node* cur = p; cur != NULL; )
                        {
                            p = cur;
                            if (_kc(v.first, cur->data->first))
                                cur = cur->left;
                            else if (_kc(cur->data->first, v.first))
                                cur = cur->right;
                            else return _make_insert_pair(p, false);
                        }
                        node **newn = _kc(v.first, p->data->first) ? &p->left : &p->right;
                        *newn = _newnode(v, p);
                        return _make_insert_pair(*newn, true);
					}

                    pair<iterator, bool> _insert_with_rebalance(node* p, const_reference v)
					{
						pair<iterator, bool> res = _insert(p, v);

						if (res.second)
						{
							_root = _balance(res.first._node);
							++_size;
						}
						return res;
					}

					pair<iterator, bool> _insert_with_rebalance(iterator pos, const_reference v)
					{
						for (; pos._node != NULL && _kc(pos._node->data->first, v.first); ++pos)
							;
						if (pos._node == NULL) --pos;
						return _insert_with_rebalance(pos._node, v);
					}

					node* _remove(node* p, const key_type& k)
					{
                        while (p != NULL)
                        {
                            if (_kc(k, p->data->first))
                                p = p->left;
                            else if (_kc(p->data->first, k))
                                p = p->right;
                            else
							{
								--_size;
								return _delnode_with_rebalance(p);
							}
						}
                        return _root;
					}
					
                    void _clear(node *n)
                    {
                        if (n == NULL) return;
                        _clear(n->left);
                        _clear(n->right);
                        _delnode(n);
                    }

					node* _lower_bound(node* root, const key_type& k) const
					{
						node* larger = NULL;
                        
						for (node* cur = root; cur != NULL; )
                        {
                            if (_kc(k, cur->data->first))
                            {
								larger = cur;
							    cur = cur->left;
							}
                            else if (_kc(cur->data->first, k))
                                cur = cur->right;
                            else return cur;
						}
						return larger;
					}

					node* _upper_bound(node* root, const key_type& k) const
					{
						node* larger = NULL;
                        
						for (node* cur = root; cur != NULL; )
                        {
                            if (_kc(k, cur->data->first))
                            {
								larger = cur;
							    cur = cur->left;
							}
                            else if (_kc(cur->data->first, k))
                            {
								cur = cur->right;
							}
							else 
							{
								if (cur->right)
								{
									larger = cur->right;
									while (larger->left)
										larger = larger->left;
								}
								break ;
							}
						}
						return larger;
					}

				public:
					AVLTree(const key_compare &key_comp, const allocator_type& alloc) :
						_root(NULL),
						_kc(key_comp),
						_size(0),
						_alloc(alloc)
					{}

					~AVLTree()
					{
						clear();
					}

                    void clear()
                    {
					    _clear(_root);
                        _size = 0;
                        _root = NULL;
                    }

                    void                clone(const AVLTree &copy)
                    {
                        if (_root != NULL) clear();
                        if (copy._root == NULL) return;
                        _root = _newnode(*copy._root->data);
                        node* clone = _root;
                        node* original = copy._root;

                        while (original != NULL)
                        {
                            if (original->left != NULL && clone->left == NULL)
                            {
                                clone->left = _newnode(*original->left->data, clone);
                                original = original->left;
                                clone = clone->left;
                            }
                            else if (original->right != NULL && clone->right == NULL)
                            {
                                clone->right = _newnode(*original->right->data, clone);
                                original = original->right;
                                clone = clone->right;
                            }
                            else
                            {
                                original = original->parent;
                                clone = clone->parent;
                            }
                        }
                        _size = copy._size;
                    }

                    AVLTree(const AVLTree& copy)
                            : _root(NULL), _kc(copy._kc), _size(0), _alloc(copy._alloc)
                    {
                        clone(copy);
                    }

                    AVLTree& operator=(const AVLTree& tree)
                    {
					    if (this != &tree)
					        clone(tree);
                        return *this;
                    }

                    size_type           size() const        { return  _size; }

                    iterator			begin() 			{ return iterator(_findmin(_root), this); }

                    iterator			end()				{ return iterator(NULL, this); }

                    const_iterator		begin() const 		{ return const_iterator(_findmin(_root), this); }

                    const_iterator		end() const 		{ return const_iterator(NULL, this); }

                    pair<iterator, bool> insert(const_reference val)
                    {
						return _insert_with_rebalance(_root, val);
                    }

                    iterator insert (iterator position, const_reference val)
                    {
						if (position._node != NULL && _kc(position._node->data->first, val.first))
                        {
							return _insert_with_rebalance(++position, val).first;
						}
						else
							return insert(val).first;
                    }

                    void erase(iterator position)
                    {
                        _root = _delnode_with_rebalance(position._node);
                        --_size;
                    }

                    size_t erase(const key_type& k)
					{
					    const size_type old_size = _size;

					    _root = _remove(_root, k);
                        return old_size != _size;
					}

					void swap(AVLTree& x)
                    {
                        if (this != &x)
                        {
                            std::swap(_root, x._root);
                            std::swap(_size, x._size);
                        }
                    }

                    iterator find (const key_type& k)
                    {
                        node* n = _find(_root, k);

                        return iterator(n, this);
                    }

					const_iterator find (const key_type& k) const
                    {
                        node* n = _find(_root, k);

                        return const_iterator(n, this);
                    }

                    size_type count (const key_type& k) const
                    {
                        return _find(_root, k) != NULL;
                    }

					iterator lower_bound (const key_type& k)
					{
						node* n = _lower_bound(_root, k);
						
						return iterator(n, this);
					}

					const_iterator lower_bound (const key_type& k) const
					{
						node* n = _lower_bound(_root, k);
						
						return const_iterator(n, this);
					}

					iterator upper_bound (const key_type& k)
					{
						node* n = _upper_bound(k);

						return iterator(n, this);
					}

					const_iterator upper_bound (const key_type& k) const
					{
						node* n = _upper_bound(_root, k);
						
						return const_iterator(n, this);
					}

                    allocator_type	get_allocator() const { return _alloc; }

                    node*   get_root() const { return _root; }
            };

			class BidirectionalMapIterator : public ft::iterator<std::bidirectional_iterator_tag, value_type>
			{
				typedef ft::iterator<std::bidirectional_iterator_tag, value_type> 	parent;
				typedef BidirectionalMapIterator									self;

				public:
					typedef typename parent::reference							reference;
					typedef typename parent::pointer							pointer;

					BidirectionalMapIterator(node* begin = NULL, const AVLTree* tree = NULL)
						: _node(begin), _tree(tree) {}
					BidirectionalMapIterator(const self &copy)
						: _node(copy._node), _tree(copy._tree) {}
					~BidirectionalMapIterator() {};

					const self &operator=(const self &it)
					{
						if (this != &it)
						{
							_node = it._node;
							_tree = it._tree;
						}
						return *this;
					}

					reference	operator*()		{ return *_node->data; }

					pointer		operator->()	{ return _node->data; }

					self&		operator++()
					{
						if (_node == NULL)
						{
							_node = _tree->get_root();
							if (_node == NULL)
								throw std::underflow_error("++ requested for an empty iterator");
							while (_node->left != NULL)
								_node = _node->left;
						}
						else if (_node->right != NULL)
						{
							_node = _node->right;
							while (_node->left != NULL)
								_node = _node->left;
						}
						else
						{
							node *p = _node->parent;

							while (p != NULL && _node == p->right)
							{
								_node = p;
								p = p->parent;
							}
							_node = p;
						}
						return *this;
					}

					self		operator++(int) { self tmp = *this; ++(*this);  return tmp; }

					self&		operator--()
					{
						if (_node == NULL)
						{
							_node = _tree->get_root();
							if (_node == NULL)
								throw std::underflow_error("-- requested for an empty iterator");
							while (_node->right != NULL)
								_node = _node->right;
						}
						else if (_node->left != NULL)
						{
							_node = _node->left;
							while (_node->right != NULL)
								_node = _node->right;
						}
						else
						{
							node *p = _node->parent;

							while (p != NULL && _node == p->left)
							{
								_node = p;
								p = p->parent;
							}
							_node = p;
						}
						return *this;
					}

					self		operator--(int) { self tmp = *this; --(*this);  return tmp; }

					friend bool operator== (const self& a, const self& b) { return a._node == b._node; }

					friend bool operator!= (const self& a, const self& b) { return !(a == b); }

				private:
					friend class ConstBidirectionalMapIterator;
			        friend class AVLTree;
					node	*_node;
                    const AVLTree *_tree;
			};
			
			class ConstBidirectionalMapIterator : public ft::iterator<std::bidirectional_iterator_tag, const value_type>
			{
				typedef ft::iterator<std::bidirectional_iterator_tag, const value_type>	parent;
				typedef BidirectionalMapIterator										nonconst_v;
				typedef ConstBidirectionalMapIterator									self;

                public:
                    typedef typename parent::reference							reference;
                    typedef typename parent::pointer							pointer;

                    ConstBidirectionalMapIterator(node* begin = NULL, const AVLTree* tree = NULL)
                        : _node(begin), _tree(tree) {};
                    ConstBidirectionalMapIterator(const self &copy)
                        : _node(copy._node), _tree(copy._tree) {};
                    ConstBidirectionalMapIterator(const nonconst_v &it)
                        : _node(it._node), _tree(it._tree) {};
                    ~ConstBidirectionalMapIterator() {};

                    const self &operator=(const self &it)
                    {
                        if (this != &it)
                        {
                            _node = it._node;
                            _tree = it._tree;
                        }
                        return *this;
                    }

                    reference	operator*()		{ return *_node->data; }

                    pointer		operator->()	{ return _node->data; }

                    self&		operator++()
                    {
                        if (_node == NULL)
                        {
                            _node = _tree->get_root();
                            if (_node == NULL)
                                throw std::underflow_error("++ requested for an empty iterator");
                            while (_node->left != NULL)
								_node = _node->left;
                        }
                        else if (_node->right != NULL)
                        {
                            _node = _node->right;
                            while (_node->left != NULL)
                                _node = _node->left;
                        }
                        else
                        {
                            node *p = _node->parent;

                            while (p != NULL && _node == p->right)
                            {
                                _node = p;
                                p = p->parent;
                            }
                            _node = p;
                        }
                        return *this;
                    }

                    self		operator++(int) { self tmp = *this; ++(*this);  return tmp; }

                    self&		operator--()
                    {
                        if (_node == NULL)
                        {
                            _node = _tree->get_root();
                            if (_node == NULL)
                                throw std::underflow_error("-- requested for an empty iterator");
                            while (_node->right != NULL)
                                _node = _node->right;
                        }
                        else if (_node->left != NULL)
                        {
                            _node = _node->left;
                            while (_node->right != NULL)
                                _node = _node->right;
                        }
                        else
                        {
                            node *p = _node->parent;

                            while (p != NULL && _node == p->left)
                            {
                                _node = p;
                                p = p->parent;
                            }
                            _node = p;
                        }
                        return *this;
                    }

                    self		operator--(int) { self tmp = *this; --(*this);  return tmp; }

                    friend bool operator== (const self& a, const self& b) { return a._node == b._node; }

                    friend bool operator!= (const self& a, const self& b) { return !(a == b); }

                private:
                    friend class AVLTree;
                    node	*_node;
                    const AVLTree *_tree;
			};
	};

	template <typename T, typename Alloc>
	bool operator== (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin())); }
	template <typename T, typename Alloc>
	bool operator!= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (!(lhs == rhs)); }
	template <typename T, typename Alloc>
	bool operator< (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
	template <typename T, typename Alloc>
	bool operator<= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (!(rhs < lhs)); }
	template <typename T, typename Alloc>
	bool operator> (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (rhs < lhs); }
	template <typename T, typename Alloc>
	bool operator>= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return !(lhs < rhs); }
	template <typename T, typename Alloc>
	void swap (map<T,Alloc>& x, map<T,Alloc>& y)						{ x.swap(y); }
};

#endif
