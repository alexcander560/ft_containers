#ifndef MAP_HPP
#define MAP_HPP

#include "utils.hpp"

namespace ft
{		
	template < typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<pair<const Key,T> > >
	class map
	{
		struct	node;
		class	AVLTree;
		class	MyIterator;
		class	ConstMyIterator;

		public:
			//-----------------------------------------------------------typedef(15/15)-----------------------------------------------------------------------------------
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef	pair<const key_type, mapped_type>			value_type;
			typedef Alloc										allocator_type;
			typedef Compare										key_compare;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef	MyIterator									iterator;
			typedef ConstMyIterator								const_iterator;
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
					typedef	bool		result_type;
					typedef	value_type	first_argument_type;
					typedef	value_type	second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const { return (comp(x.first, y.first)); }
			};

		private:
			AVLTree					_tree;															// АВЛ дерево на котором стоит вся мапа
			void					_throw_out_of_range() const										{ throw std::out_of_range("map"); }

		public:
			//------------------------------------------------------------constructor(3/3)--------------------------------------------------------------------------------
			// Конструктор без параметров
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _tree(comp, alloc){}
			// Конструктор с 2 параметрами (набор значений)
			template <typename InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type(), 
				typename enable_if<is_iterator<InputIterator>::value>::type* = 0)
				: _tree(comp, alloc)																{ insert(first, last); }
			// Конструктор копирования
			map (const map& x): _tree(x._tree){}
			//------------------------------------------------------------destructor(1/1)---------------------------------------------------------------------------------
			~map () {}
			//------------------------------------------------------------operator=(1/1)----------------------------------------------------------------------------------
			const map							&operator=(const map &c)							{ _tree = c._tree; return (*this); }
			//------------------------------------------------------------Iterators(8/8)----------------------------------------------------------------------------------
			iterator							begin()												{ return (_tree.begin()); }
			const_iterator						begin() const										{ return (_tree.begin()); }
			iterator							end()												{ return (_tree.end()); }
			const_iterator						end() const											{ return (_tree.end()); }
			reverse_iterator					rbegin()											{ return (reverse_iterator(_tree.end())); }
			const_reverse_iterator				rbegin() const										{ return (const_reverse_iterator(_tree.end())); }
			reverse_iterator					rend()												{ return (reverse_iterator(_tree.begin())); }
			const_reverse_iterator				rend() const										{ return (const_reverse_iterator(_tree.begin())); }
			//------------------------------------------------------------Capacity(3/3)-----------------------------------------------------------------------------------
			// Пустая ли мапа?
			bool								empty() const										{ return (_tree._size_AVL() ? false : true); }
			// Возвращает кол-во элементов мапы
			size_type							size() const 										{ return (_tree._size_AVL()); }
			// Возвращает максимальное количество элементов, которое может содержать мапа
			size_type							max_size() const									{ return (_tree.get_allocator().max_size()/2); }
			//----------------------------------------------------------Element access(1/1)-------------------------------------------------------------------------------
			// Если k соответствует ключу элемента в контейнере, функция возвращает ссылку на его отображаемое значение
			mapped_type& 						operator[] (const key_type& k)						{ return (*insert(ft::make_pair(k, mapped_type())).first).second; }
			//------------------------------------------------------------Modifiers(8/8)----------------------------------------------------------------------------------
			// Мапа увеличивается путем вставки нового элемента, если ключ уникален (одного или нескольких)
			pair<iterator, bool>				insert (const value_type& val)						{ return (_tree.insert(val)); }
			iterator							insert (iterator position, const value_type& val)	{ return (_tree.insert(position, val)); }
			template <typename InputIterator>
			void								insert (InputIterator first, InputIterator last, typename enable_if<is_iterator<InputIterator>::value>::type* = 0)
			{
				if (first == last)
					return ;
				for (; first != last; first++)
					insert(*first);
			}
			// Удаляет из мапы один или несколько элемент(по позиции или ключу)
			void								erase(iterator position)							{ _tree.erase(position); }
			size_type							erase(const key_type& k)							{ return (_tree.erase(k)); }
			void								erase(iterator first, iterator last)
			{
				for (; first != last;)
					erase(first++);
			}
			// Заменяет содержимое контейнера содержимым x ,который является другим объектом того же типа
			void								swap (map& x)										{ _tree.swap(x._tree); }
			// Удаляет все элементы из мапы
			void								clear()												{ _tree.clear(); }
			//--------------------------------------------------------Observers(2/2)--------------------------------------------------------------------------------------
			// Возвращает копию объекта сравнения, используемого контейнером для сравнения ключей
			key_compare							key_comp() const									{ return (key_compare()); }
			// Возвращает объект сравнения, который можно использовать для сравнения двух элементов
			value_compare						value_comp() const									{ return (value_compare(key_compare())); }
			//---------------------------------------------------------Allocator(1/1)-------------------------------------------------------------------------------------
			allocator_type						get_allocator() const								{ return (_tree.get_allocator()); }
			//---------------------------------------------------------Operations(9/9)------------------------------------------------------------------------------------
			// Ищет в контейнере элемент с ключом, эквивалентным k, и возвращает ему итератор, если он найден
			iterator							find (const key_type& k)							{ return (_tree.find(k)); }
			const_iterator						find (const key_type& k) const						{ return (_tree.find(k)); }
			// Ищет в контейнере элементы с ключом, эквивалентным k, и возвращает количество совпадений
			size_type							count (const key_type& k) const						{ return (_tree.count(k)); }
			// Возвращает итератор, указывающий на первый элемент в контейнере, ключ которого равен или считается следующим после k
			iterator							lower_bound (const key_type& k)						{ return (_tree.lower_bound(k)); }
			const_iterator						lower_bound (const key_type& k) const				{ return (_tree.lower_bound(k)); }
			// Возвращает итератор, указывающий на первый элемент в контейнере, ключ которого считается следующим после k
			iterator							upper_bound (const key_type& k)						{ return (_tree.upper_bound(k)); }
			const_iterator						upper_bound (const key_type& k) const				{ return (_tree.upper_bound(k)); }
			// Возвращает границы диапазона, который включает все элементы в контейнере с ключом, эквивалентным k
			pair<iterator,iterator>				equal_range (const key_type& k)						{ return (make_pair(lower_bound(k), upper_bound(k))); }
			pair<const_iterator,const_iterator>	equal_range (const key_type& k) const				{ return (make_pair(lower_bound(k), upper_bound(k))); }
			//---------------------------------------------------------My function(9/9)-----------------------------------------------------------------------------------
			// Функции печати мапы (её на самом деле нет)
			void								print_tree(int mod = 0)								{ _tree.AVLTreePrint(mod); }

	private:
			//----------------------------------------------------------AVL Tree Implementation---------------------------------------------------------------------------
			struct node							// структура данных для узла дерева
			{
				pointer				data;		// данные узла
				size_t				height;		// высота дерева
				node				*parent;	// родитель узла
				node				*left;		// левый ребёнок узла
				node				*right;		// правый ребёнок узла

				node(pointer d, node* p = NULL): data(d), height(1), parent(p), left(NULL), right(NULL) {};
			};
			class AVLTree						// Класс дерева
			{
				private:
					node*			_root;		// корень дерева
					node*			_end;		// последний элемент дерева
					key_compare		_kc;		// ключ сравнения
					size_type		_size;		// кол-во элементов
					allocator_type	_alloc;		// аллокатор

					//---------------------------------------------------Функции для печати мапы на экран-----------------------------------------------------------------
					// Переводит число в строку (число, символ заполнения если длина числа меньше)
					// Алгоритм может корректно распечатывать только число от 0 до 999
					std::string							_print_num_AVL(int num, char ch)
					{
						std::string temp = "";

						if (num < 0 || num > 999)
							temp += "???";
						else
						{
							if (num < 10)
								temp = temp + ch + ch;
							else if (num < 100)
								temp += ch;
							temp += std::to_string(num);
						}

						return (temp);
					}
					// Правильно добавляет данные для печати (tree - дерево, lev_tree массив строк для записи элементов дерева,
					// lev_tree_height - массив строк для записи доп. данных(глубина, слой), lev - слой дерева, mod - нужный отступ,
					// mod_h - режим доп. данных(1 - добовлять глубину, 2 - добавлять родиетля, по умолчанию ничего не добавляется))
					void								_fill_depth_AVL(node *tree, std::string *lev_tree, std::string *lev_tree_height, int lev, int mod, int mod_h = 0)
					{
						if (tree == NULL)
							return ;

						int			d = _depth_AVL(tree), skip_pred = pow(2, d - 1) - 2, arm = pow(2, d - 1);
						std::string	num_str = _print_num_AVL(tree->data->first, '0'), height_str;

						if (mod == -1)
							mod = pow(2, d) - 2;

						if (mod_h == 1)
							height_str = _print_num_AVL(tree->height, '.');
						else if (mod_h == 2)
							height_str = _print_num_AVL(tree->parent ? tree->parent->data->first : 0, '.');
						
						lev_tree[lev].replace(mod, 3, num_str);
						if (mod_h)
							lev_tree_height[lev].replace(mod, 3, height_str);

						lev++;
						if (tree->left != NULL)
						{
							if (mod_h)
								lev_tree_height[lev - 1].replace(mod - arm, arm, arm, '_');
							else
								lev_tree[lev - 1].replace(mod - arm, arm, arm, '_');
							_fill_depth_AVL(tree->left, lev_tree, lev_tree_height, lev, mod - skip_pred - 2, mod_h);
						}
						if (tree->right != NULL)
						{
							if (mod_h)
								lev_tree_height[lev - 1].replace(mod + 3, arm, arm, '_');
							else
								lev_tree[lev - 1].replace(mod + 3, arm, arm, '_');
							_fill_depth_AVL(tree->right, lev_tree, lev_tree_height, lev, mod + skip_pred + 2, mod_h);
						}
					}
					// Удаляет пустые столбцы из массива строк
					void								_delete_columns_AVL(std::string	*lev_tree, std::string *lev_tree_height, int skip, int d, int mod_h = 0)
					{
						int		start = -1, end = -1, _size_AVL_del = -1;
						bool	flag = false;

						for (int i = skip - 1; i >= 0; i--)
						{
							flag = true;

							for (size_t j = 0; j < d; j++)
							{
								if (lev_tree[j][i] != ' ' && lev_tree[j][i] != '_')
								{
									flag = false;
									break ;
								}
							}
							if (flag == true && start == -1)
								start = i;
							if (flag == false && start != -1)
							{
								end = i;
								_size_AVL_del = start - i;
								for (size_t j = 0; j < d; j++)
								{
									lev_tree[j].erase(end + 1, _size_AVL_del);
									if (mod_h)
										lev_tree_height[j].erase(end + 1, _size_AVL_del);
								}
								start = end = -1;
							}
						}
						if (start != - 1)
						{
							_size_AVL_del = start - end;
							for (size_t j = 0; j < d; j++)
							{
								lev_tree[j].erase(0, _size_AVL_del);
								if (mod_h)
									lev_tree_height[j].erase(0, _size_AVL_del);
							}
						}
					}
					// Печать дерева (tree - дерево, mod_h - режим доп. данных(1 - добавлять глубину, 2 - добавлять родителя, по умолчанию ничего не добавляется))
					void								_print_tree_AVL(node *tree, int mod_h)
					{
						int		time_tree = clock(), d = _depth_AVL(tree), s = _size_AVL(tree), skip = (pow(2, d) - 2) * 2 + 3;
						std::string	lev_tree[d], lev_tree_height[d];

						std::cout << "Tree\n" << "depth= " << d << std::endl << "size= " << s << std::endl;
						// std::cout << "skip(max)= " << skip << std::endl;
						std::cout << "Заполненно: " << (float)s/(float)(pow(2, d) - 1) * 100 << "%" << std::endl;

						if (mod_h != 1 && mod_h != 2)
							mod_h = 0;
						// Заполняем строки пробелами
						if (d > 0)
						{
							lev_tree[0].insert(0, skip, ' ');
							if (mod_h == 1 || mod_h == 2)
								lev_tree_height[0] = lev_tree[0];
						}
						for (size_t i = 1; i < d; i++)
						{
							lev_tree[i] = lev_tree[0];
							if (mod_h == 1 || mod_h == 2)
								lev_tree_height[i] = lev_tree[0];
						}
						// Заполняем строки нужными данными (0, -1 ОБЯЗАТЕЛЬНО!!!)
						_fill_depth_AVL(tree, lev_tree, lev_tree_height, 0, -1, mod_h);
						// Удаляем лишнии столбцы
						_delete_columns_AVL(lev_tree, lev_tree_height, skip, d, mod_h);
						// Печатаем дерево
						for (size_t i = 0; i < d; i++)
						{
							std::cout << "|" << lev_tree[i] << std::endl;
							if (mod_h == 1 || mod_h == 2)
								std::cout << "|" << lev_tree_height[i] << std::endl;
						}
						std::cout << "\nTime: " << (float)(clock() - time_tree) / (float)1000000 << " c" << std::endl;
						if (_check_parent_AVL(tree) == 0)
							std::cout << "OK" << std::endl;
						else
						{
							std::cout << "KO" << std::endl;
							exit (1);
						}
					}
					// Считает кол-во элементов в дереве (функция была добавленна для корректного тестирвоания при создании мапы)
					int									_size_AVL(node *tree)
					{
						int s = 0;

						if (tree == NULL)
							return (0);

						s++;
						s += _size_AVL(tree->left);
						s += _size_AVL(tree->right);

						return (s);
					}
					// Считает глубину дерева (функция была добавленна для корректного тестирвоания при создании мапы)
					int									_depth_AVL(node *tree)
					{
						if (tree == NULL)
							return (0);

						int left_Depth_AVL = _depth_AVL(tree->left);
						int right_Depth_AVL = _depth_AVL(tree->right);

						return (left_Depth_AVL > right_Depth_AVL ? left_Depth_AVL + 1 : right_Depth_AVL + 1);
					}
					// Проверяет правильно ли определились родители
					int									_check_parent_AVL(node *tree)
					{
						int rez = 0;

						if (tree == NULL)
							return (0);
						if (tree->left != NULL)
						{
							if (tree->left->parent->data->first != tree->data->first)
								rez++;
							else
								rez += _check_parent_AVL(tree->left);
						}
						if (tree->right != NULL)
						{
							if (tree->right->parent->data->first != tree->data->first)
								rez++;
							else
								rez += _check_parent_AVL(tree->right);
						}
						return (rez);
					}
					//----------------------------------------------------------------------------------------------
					//---------------------------Функции для корректной вставки узла в дерево-----------------------
					//----------------------------------------------------------------------------------------------
					// Создать новый узел
					node*								_newnode(const_reference v, node* parent = NULL)
					{
						pointer data = _alloc.allocate(1);
						_alloc.construct(data, v);
						return new node(data, parent);
					}
					node*								_newnode_zero()
					{
						pointer data = _alloc.allocate(1);
						return new node(data);
					}
					// Cоздаёт копию узлов
					void								_clone_nodes(node* original, node* clone)
					{
						if (original->left != NULL)
						{
							clone->left = _newnode(*original->left->data, clone);
							clone->left->height = original->left->height;
							_clone_nodes(original->left, clone->left);
						}
						if (original->right != NULL)
						{
							clone->right = _newnode(*original->right->data, clone);
							clone->right->height = original->right->height;
							_clone_nodes(original->right, clone->right);
						}
					}
					// Создать копию дерева
					void								_clone(const AVLTree &copy)
					{
						if (_root != NULL)
							clear();
						if (copy._root == NULL)
							return ;

						_root = _newnode(*copy._root->data);
						_root->height = (*copy._root).height;
						_clone_nodes(copy._root, _root);
						_size = copy._size;
					}
					// Помогает определять глубину дерева
					size_t								_height_AVL(node* p)
					{
						return (p ? p->height : 0);
					}
					// Высчитывает необходимость в кручение дерева
					int									_bfactor_AVL(node* p)
					{
						return (_height_AVL(p->right) - _height_AVL(p->left));
					}
					// Восстанавливает корректную глубину дерева
					void								_fixheight_AVL(node* p)
					{
						p->height = std::max(_height_AVL(p->left), _height_AVL(p->right)) + 1;
					}
					// правый поворот вокруг p
					node*								_rotateright_AVL(node* p)
					{
						node* q = p->left;

						p->left->parent = p->parent;
						p->parent = p->left;
						if (p->left->right)
							p->left->right->parent = p;

						p->left = q->right;
						q->right = p;

						_fixheight_AVL(p);
						_fixheight_AVL(q);

						return (q);
					}
					// левый поворот вокруг q
					node*								_rotateleft_AVL(node* q)
					{
						node* p = q->right;

						q->right->parent = q->parent;
						q->parent = q->right;
						if (q->right->left)
							q->right->left->parent = q;

						q->right = p->left;
						p->left = q;

						_fixheight_AVL(q);
						_fixheight_AVL(p);

						return (p);
					}
					// балансировка узла p
					node*								_balance_AVL(node* p)
					{
						_fixheight_AVL(p);
						if(_bfactor_AVL(p) == 2)
						{
							if(_bfactor_AVL(p->right) < 0 )
								p->right = _rotateright_AVL(p->right);
							return (_rotateleft_AVL(p));
						}
						if(_bfactor_AVL(p) == -2)
						{
							if(_bfactor_AVL(p->left) > 0)
								p->left = _rotateleft_AVL(p->left);
							return (_rotateright_AVL(p));
						}
						return (p);
					}
					// Вставка ключа k в дерево с корнем p (Основной алгоритм)
					pair<node*, pair <node*, bool> >	_insert_AVL(node *p, const_reference k, node *parent)
					{
						pair<node*, pair <node*, bool> > res;
						
						if(!p)
						{
							res.first = _newnode (k, parent);
							res.second.first = res.first;
							res.second.second = true;
							return (res);
						}
						if (_kc(k.first, p->data->first))
						{
							res = _insert_AVL(p->left, k, p);
							p->left = res.first;
						}
						else if (_kc(p->data->first, k.first))
						{
							res = _insert_AVL(p->right, k, p);
							p->right = res.first;
						}
						else
							res.second.first = p;

						res.first = _balance_AVL(p);
						return (res);
					}
					// Вставка элемента с балансированеим (Правильно вернёт пару)
					pair<iterator, bool>				_insert_tree(const_reference v)
					{
						pair<node*, pair <node*, bool> >	my_par= _insert_AVL(_root, v, _root);
						pair<iterator, bool>				res = make_pair(iterator(my_par.second.first, this), my_par.second.second);

						_root = my_par.first;
						if (res.second)
							_size++;

						return (res);
					}
					//----------------------------------------------------------------------------------------------
					//---------------------------Функции для корректного удаления элементов дерева------------------
					//----------------------------------------------------------------------------------------------
					// Удалить узел
					void								_delnode(node* p)
					{
						_alloc.destroy(p->data);
						_alloc.deallocate(p->data, 1);
						delete p;
					}
					void								_delnode_zero(node* p)
					{
						_alloc.deallocate(p->data, 1);
						delete p;
					}
					// Удалить все узлы
					void								_clear(node *n)
					{
						if (n == NULL)
							return ;
						_clear(n->left);
						_clear(n->right);
						_delnode(n);
					}
					// Поиск узла с минимальным ключом в дереве
					node*								_findmin_AVL(node* p)
					{
						return (p && p->left ? _findmin_AVL(p->left) : p);
					}
					node*								_findmin_AVL(node* p) const
					{
						return (p && p->left ? _findmin_AVL(p->left) : p);
					}
					// Поиск узла с максимальным ключом в дереве
					node*								_findmax_AVL(node* p)
					{
						return (p && p->right ? _findmax_AVL(p->right) : p);
					}
					node*								_findmax_AVL(node* p) const
					{
						return (p && p->right ? _findmax_AVL(p->right) : p);
					}
					// Удаление узла с минимальным ключом из дерева
					node*								_removemin_AVL(node* p) // удаление узла с минимальным ключом из дерева p
					{
						if(p->left == NULL)
						{
							if (p->right)
								p->right->parent = p->parent;
							return (p->right);
						}
						p->left = _removemin_AVL(p->left);
						return (_balance_AVL(p));
					}
					// Удаляет элемент из дерева
					node*								_remove_AVL(node* p, const key_type& k) // удаление ключа k из дерева p
					{
						if(!p)
							return (NULL);
						if(_kc(k, p->data->first))
							p->left = _remove_AVL(p->left ,k);
						else if(_kc(p->data->first, k))
							p->right = _remove_AVL(p->right, k);
						else
						{
							node* q = p->left;
							node* r = p->right;
							node *temp_parent = p->parent;

							_delnode(p);
							_size--;
							if(!r)
							{
								if (q)
									q->parent = temp_parent;
								return (q);
							}
							node* min = _findmin_AVL(r);
							min->right = _removemin_AVL(r);
							if (min->right)
								min->right->parent = min;
							min->left = q;
							if (min->left)
								min->left->parent = min;
							min->parent = temp_parent;
							return (_balance_AVL(min));
						}
						return (_balance_AVL(p));
					}
					//----------------------------------------------------------------------------------------------
					//---------------------------Поиск нужных элементов дерева--------------------------------------
					//----------------------------------------------------------------------------------------------
					// Ищет элемент с переданным ключом во всём дереве
					node*								_find(node* n, const key_type k) const
					{
						if (n == NULL)
							return (NULL);
						if (_kc(k, n->data->first))
							return (_find(n->left, k));
						if (_kc(n->data->first, k))
							return (_find(n->right, k));
						else
							return (n);
					}
					// Возвращает итератор, указывающий на первый элемент в контейнере, ключ которого равен или считается следующим после k
					node*								_lower_bound(node* root, const key_type& k) const
					{
						node*	node_more = NULL;

						for (node* i = root; i != NULL; )
						{
							if (_kc(k, i->data->first))
							{
								node_more = i;
								i = i->left;
							}
							else if (_kc(i->data->first, k))
								i = i->right;
							else
								return (i);
						}
						return (node_more ? node_more : _end);
					}
					// Возвращает итератор, указывающий на первый элемент в контейнере, ключ которого считается следующим после k
					node*								_upper_bound(node* root, const key_type& k) const
					{
						node*	node_more = NULL;

						for (node* i = root; i != NULL; )
						{
							if (_kc(k, i->data->first))
							{
								node_more = i;
								i = i->left;
							}
							else if (_kc(i->data->first, k))
								i = i->right;
							else										// В случае совпадений ключей, нужно вернуть узел, который будет считаться следующим после узла с ключом k
							{
								if (i->right)							// Если есть правая ветка, то искомый узел находится имеено здесь
								{
									node_more = i->right;				// Сохраним этот узел и попытаемся найти ключ ещё меньше
									while (node_more->left)				// Такой ключ будет у узла, который находится более левее
										node_more = node_more->left;	// Будем переходить каждый раз к левому ребёнку, пока не дойдём до NULL узла
								}
								return (node_more);						// Если правой ветки нет, то искомый узел уже просчитан в node_more
							}
						}
						return (node_more ? node_more : _end);
					}
				public:
					// Конструктор дерева
					AVLTree(const key_compare &key_comp, const allocator_type& alloc): _root(NULL), _end(_newnode_zero()), _kc(key_comp), _size(0), _alloc(alloc) {}
					// Конструктор копирования
					AVLTree(const AVLTree& copy): _root(NULL), _end(_newnode_zero()), _kc(copy._kc), _size(0), _alloc(copy._alloc) { _clone(copy); }
					// Перегрузка оператора =
					AVLTree&				operator=(const AVLTree& tree)
					{
						if (this != &tree)
							_clone(tree);
						return (*this);
					}
					// Деструктор дерева
					~AVLTree()
					{
						_delnode_zero(_end);
						clear();
					}
					// Распечатать дерево (создано для тестирвония AVL дерева)
					void					AVLTreePrint(int mod)
					{
						std::cout << "Печатаем дерево" << std::endl;
						std::cout << "================================================" << std::endl;
						_print_tree_AVL(_root, mod);
						std::cout << "================================================" << std::endl;
					}
					//	Удаляет все элементы из дерева
					void					clear()
					{
						_clear(_root);
						_size = 0;
						_root = NULL;
					}
					// Возвращает кол-во элементов дерева
					size_type				_size_AVL() const						{ return (_size); }
					// Правильно возвращает итераторы
					iterator				begin() 								{ return (_size ? iterator(_findmin_AVL(_root), this) : iterator(_end, this)); }
					iterator				end()									{ return (iterator(_end, this)); }
					const_iterator			begin() const							{ return (_size ? const_iterator(_findmin_AVL(_root), this) : const_iterator(_end, this)); }
					const_iterator			end() const								{ return (const_iterator(_end, this)); }
					// Вставка элемента, запускает вставку в дерево, при этом дерево автоматически балансируется
					pair<iterator, bool>	insert(const_reference val)				{ return (_insert_tree(val)); }
					iterator				insert (iterator position, const_reference val)
					{
						(void)position;
						return (_insert_tree(val).first);
					}
					// Удаляет элемент (по позиции или ключу), автоматически балансирует дерево
					void					erase(iterator position)				{ _root = _remove_AVL(_root, (*position).first); }
					size_t					erase(const key_type& k)
					{
						size_type old_size = _size;

						_root = _remove_AVL(_root, k);
						return (old_size != _size);
					}
					// Ищет элемент с переданным ключом
					iterator				find (const key_type& k)				{ return (count(k) ? iterator(_find(_root, k), this) : iterator(_end, this)); }
					const_iterator			find (const key_type& k) const			{ return (count(k) ? const_iterator(_find(_root, k), this) : const_iterator(_end, this)); }
					// Есть ли элемент с переданным ключом
					size_type				count (const key_type& k) const			{ return (_find(_root, k) != NULL ? 1 : 0); }
					// Возвращает итератор, указывающий на первый элемент в контейнере, ключ которого не считается предшествующим за k
					iterator				lower_bound (const key_type& k)			{ return (iterator(_lower_bound(_root, k), this)); }
					const_iterator			lower_bound (const key_type& k) const	{ return (const_iterator(_lower_bound(_root, k), this)); }
					// Возвращает итератор, указывающий на первый элемент в контейнере, ключ которого не считается идущим после k
					iterator				upper_bound (const key_type& k)			{ return (iterator(_upper_bound(_root, k), this)); }
					const_iterator			upper_bound (const key_type& k) const	{ return (const_iterator(_upper_bound(_root, k), this)); }
					// Обмен данными
					void					swap(AVLTree& x)
					{
						if (this != &x)
						{
							std::swap(_root, x._root);
							std::swap(_size, x._size);
						}
					}
					// Возвращает аллокатор
					allocator_type			get_allocator() const					{ return (_alloc); }
					// Возвращает корень дерева
					node*					get_root() const						{ return (_root); }
					// Возвращает последний элемент дерева
					node*					get_end() const							{ return (_end); }
					// Возвращает максимальный элемент дерева
					node*					get_max() const							{ return (_findmax_AVL(_root)); }
					// возвращает минимальный элемент дерева
					node*					get_min() const							{ return (_findmin_AVL(_root)); }
			};


			class Iterator_base: public ft::iterator<std::bidirectional_iterator_tag, value_type>
			{
				typedef ft::iterator<std::bidirectional_iterator_tag, value_type>	parent;

				public:
					Iterator_base(node* begin = NULL, const AVLTree* tree = NULL): _node(begin), _tree(tree) {}
					Iterator_base(Iterator_base const &copy): _node(copy._node), _tree(copy._tree){}
					~Iterator_base() {};

				public:
					node*			_node;
					const AVLTree*	_tree;
			};

			class MyIterator: public Iterator_base
			{
				public:

					MyIterator(node* begin = NULL, const AVLTree* tree = NULL): Iterator_base(begin, tree) {}
					MyIterator(MyIterator const &copy): Iterator_base(copy._node, copy._tree) {}
					~MyIterator() {};

					const MyIterator&	operator=(const MyIterator &it)
					{
						if (this != &it)
						{
							this->_node = it._node;
							this->_tree = it._tree;
						}
						return (*this);
					}
					reference	operator*()									{ return (*this->_node->data); }
					pointer		operator->()								{ return (this->_node->data); }
					MyIterator&		operator++()
					{
						if (this->_node == this->_tree->get_max())				// Что бы с максимального элемента перейти на последний
							this->_node = this->_tree->get_end();
						else if (this->_node->right != NULL)				// Если есть узел справа, то искомый узел будет находиться в правом поддереве
						{
							this->_node = this->_node->right;
							while (this->_node->left != NULL)				// Что бы найти следующйй узел от текущего нужно перейти к самому левому потомку
								this->_node = this->_node->left;				// правого поддерева
						}
						else										// Если узла справа нет, то для искомый узел один из предков
						{
							node *p = this->_node->parent;

							while (p != NULL && this->_node == p->right)	// Перехоим каждый раз на уровень выше
							{										// Искомым узлом будет являться первый предок,
								this->_node = p;							// у которого переданный узел будет находиться в левом поддереве
								p = p->parent;
							}
							this->_node = p;
						}
						return (*this);
					}
					MyIterator		operator++(int)
					{
						MyIterator	tmp = *this;
						++(*this);
						return (tmp);
					}
					MyIterator&		operator--()
					{
						if (this->_node == this->_tree->get_end())					// Что бы с последнего элемента перейти на максимальный
							this->_node = this->_tree->get_max();
						else if (this->_node->left != NULL)					// Противоположное ++
						{
							this->_node = this->_node->left;
							while (this->_node->right != NULL)
								this->_node = this->_node->right;
						}
						else
						{
							node *p = this->_node->parent;

							while (p != NULL && this->_node == p->left)
							{
								this->_node = p;
								p = p->parent;
							}
							this->_node = p;
						}
						return (*this);
					}
					MyIterator		operator--(int)
					{
						MyIterator	tmp = *this;
						--(*this);
						return (tmp);
					}
					friend bool	operator== (const MyIterator& a, const MyIterator& b)	{ return (a._node == b._node); }
					friend bool	operator!= (const MyIterator& a, const MyIterator& b)	{ return (!(a == b)); }

			};
			
			class ConstMyIterator: public Iterator_base
			{

				public:

					ConstMyIterator(node* begin = NULL, const AVLTree* tree = NULL): Iterator_base(begin, tree) {}
					ConstMyIterator(const ConstMyIterator &copy): Iterator_base(copy._node, copy._tree) {}
					ConstMyIterator(const MyIterator &copy): Iterator_base(NULL, NULL)
					{
						Iterator_base& k = (Iterator_base&)copy;

						this->_node = k._node;
						this->_tree = k._tree;
					}
					~ConstMyIterator() {};

					const ConstMyIterator&	operator=(const ConstMyIterator &it)
					{
						if (this != &it)
						{
							this->_node = it._node;
							this->_tree = it._tree;
						}
						return *this;
					}
					reference	operator*()									{ return (*this->_node->data); }
					pointer		operator->()								{ return (this->_node->data); }
					ConstMyIterator&		operator++()
					{
						if (this->_node == this->_tree->get_max())				// Что бы с максимального элемента перейти на последний
							this->_node = this->_tree->get_end();
						else if (this->_node->right != NULL)
						{
							this->_node = this->_node->right;
							while (this->_node->left != NULL)
								this->_node = this->_node->left;
						}
						else
						{
							node *p = this->_node->parent;

							while (p != NULL && this->_node == p->right)
							{
								this->_node = p;
								p = p->parent;
							}
							this->_node = p;
						}
						return (*this);
					}
					ConstMyIterator		operator++(int)
					{
						ConstMyIterator tmp = *this;
						++(*this);
						return (tmp);
					}
					ConstMyIterator&		operator--()
					{
						if (this->_node == this->_tree->get_end())					// Что бы с последнего элемента перейти на максимальный
							this->_node = this->_tree->get_max();
						else if (this->_node->left != NULL)
						{
							this->_node = this->_node->left;
							while (this->_node->right != NULL)
								this->_node = this->_node->right;
						}
						else
						{
							node *p = this->_node->parent;

							while (p != NULL && this->_node == p->left)
							{
								this->_node = p;
								p = p->parent;
							}
							this->_node = p;
						}
						return (*this);
					}
					ConstMyIterator		operator--(int)
					{
						ConstMyIterator tmp = *this;
						--(*this);
						return (tmp);
					}
					friend bool	operator== (const ConstMyIterator& a, const ConstMyIterator& b)	{ return (a._node == b._node); }
					friend bool	operator!= (const ConstMyIterator& a, const ConstMyIterator& b)	{ return (!(a == b)); }
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
	bool operator>= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (!(lhs < rhs)); }
	template <typename T, typename Alloc>
	void swap (map<T,Alloc>& x, map<T,Alloc>& y)						{ x.swap(y); }
};

#endif
