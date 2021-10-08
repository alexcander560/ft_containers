# ft_containers

Запуск всех тестов

    bash test.sh

Запуск отдельных блоков

    bash test.sh Acc    (Element access)
    
    bash test.sh Cap    (Capacity)
    
    bash test.sh Alloc  (Allocator)
    
    bash test.sh Iter   (Iterators)
    
    bash test.sh Non    (Non-member function overloads)
    
    bash test.sh Mod    (Modifiers)
    
Запуск отдельных функций

    Element access:
    1) bash test.sh acc               (test [])
    2) bash test.sh acc_const         (test [] const)
    3) bash test.sh at
    4) bash test.sh at_const
    5) bash test.sh front
    6) bash test.sh front_const
    7) bash test.sh bask
    8) bash test.sh bask_const
    
    Capacity:
    1) bash test.sh size
    2) bash test.sh max_size
    3) bash test.sh capacity
    4) bash test.sh reserve
    5) bash test.sh empty
    6) bash test.sh resize
    
    Allocator:
    1)bash test.sh get_allocator
    
    Iterators:
    1) bash test.sh iterator
    2) bash test.sh iterator_const
    3) bash test.sh r_iterator        (reverse iterators)
    4) bash test.sh r_iterator_const  (reverse iterators const)
    
    Non-member function overloads:
    1) bash test.sh operator          (==, !=, <, <=, >, >=)
    2) bash test.sh Non_swap          (bash test.sh swap все тесты для swap)
    
    Modifiers:
    1) bash test.sh assign            (все тесты)
    1.1) bash test.sh assign_1        (assign(InputIterator first, InputIterator last))
    1.2) bash test.sh assign_2        (assign(size_type n, const value_type& val))
    2) bash test.sh push_back
    3) bash test.sh pop_back
    4) bash test.sh insert            (все тесты)
    4.1) bash test.sh insert_1        (insert(iterator position, const value_type& val))
    4.2) bash test.sh insert_2        (insert(iterator position, size_type n, const value_type& val))
    4.3) bash test.sh insert_3        (insert(iterator position, InputIterator first, InputIterator last))
    5) bash test.sh erase             (все тесты)
    5.1) bash test.sh erase_1         erase(iterator position)
    5.2) bash test.sh erase_2         erase(iterator first, iterator last)
    6) bash test.sh Mod_swap          (bash test.sh swap все тесты для swap)
    7) bash test.sh clear
    
