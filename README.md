# ft_containers

Для этого проекта были написаны собстенные тесты, если вы не переопределили нужные типы данны, не реализовали все необходимые конструторы и функции, как этого требует задание, то ваши результаты будут достаточно низкими.

================================================================================================
    
Запуск всех тестов для vector

    bash test_vector.sh

<details>
<summary>Запуск отдельных блоков vector</summary>

    bash test_vector.sh Acc    (Element access)
    
    bash test_vector.sh Cap    (Capacity)
    
    bash test_vector.sh Alloc  (Allocator)
    
    bash test_vector.sh Iter   (Iterators)
    
    bash test_vector.sh Non    (Non-member function overloads)
    
    bash test_vector.sh Mod    (Modifiers)
    
</details>

<details>
<summary>Запуск отдельных функций vector</summary>

    Element access:
    1) bash test_vector.sh acc               (test [])
    2) bash test_vector.sh acc_const         (test [] const)
    3) bash test_vector.sh at
    4) bash test_vector.sh at_const
    5) bash test_vector.sh front
    6) bash test_vector.sh front_const
    7) bash test_vector.sh bask
    8) bash test_vector.sh bask_const
    
    Capacity:
    1) bash test_vector.sh size
    2) bash test_vector.sh max_size
    3) bash test_vector.sh capacity
    4) bash test_vector.sh reserve
    5) bash test_vector.sh empty
    6) bash test_vector.sh resize
    
    Allocator:
    1) bash test_vector.sh get_allocator
    
    Iterators:
    1) bash test_vector.sh iterator
    2) bash test_vector.sh iterator_const
    3) bash test_vector.sh r_iterator        (reverse iterators)
    4) bash test_vector.sh r_iterator_const  (reverse iterators const)
    
    Non-member function overloads:
    1) bash test_vector.sh operator          (==, !=, <, <=, >, >=)
    2) bash test_vector.sh Non_swap          (bash test_vector.sh swap все тесты для swap)
    
    Modifiers:
    1) bash test_vector.sh assign            (все тесты)
        1.1) bash test_vector.sh assign_1    (assign(InputIterator first, InputIterator last))
        1.2) bash test_vector.sh assign_2    (assign(size_type n, const value_type& val))
    2) bash test_vector.sh push_back
    3) bash test_vector.sh pop_back
    4) bash test_vector.sh insert            (все тесты)
        4.1) bash test_vector.sh insert_1    (insert(iterator position, const value_type& val))
        4.2) bash test_vector.sh insert_2    (insert(iterator position, size_type n, const value_type& val))
        4.3) bash test_vector.sh insert_3    (insert(iterator position, InputIterator first, InputIterator last))
    5) bash test_vector.sh erase             (все тесты)
        5.1) bash test_vector.sh erase_1     erase(iterator position)
        5.2) bash test_vector.sh erase_2     erase(iterator first, iterator last)
    6) bash test_vector.sh Mod_swap          (bash test_vector.sh swap все тесты для swap)
    7) bash test_vector.sh clear
    
</details>

================================================================================================

Запуск всех тестов для stack

    bash test_stack.sh 

<details>
<summary>Запуск отдельных блоков stack</summary>
    
    bash test_stack.sh Member   (Member functions)
    
    bash test_stack.sh Non      (Non-member function overloads)
    
</details>
    
<details>
<summary>Запуск отдельных функций stack</summary>
    
    Member functions:
    1) bash test_stack.sh empty
    2) bash test_stack.sh size
    3) bash test_stack.sh top
    4) bash test_stack.sh top_const
    5) bash test_stack.sh push
    6) bash test_stack.sh pop
    
    Non-member function overloads:
    1) bash test_stack.sh operator          (==, !=, <, <=, >, >=)
    
</details>

================================================================================================

Запуск всех тестов для map

    bash test_???.sh 

<details>
<summary>Запуск отдельных блоков map</summary>
    
   Ничего нет
    
</details>
    
<details>
<summary>Запуск отдельных функций map</summary>
    
     Ничего нет
    
</details>

================================================================================================

[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/gmother/ft_containers)](https://github.com/JaeSeoKim/badge42)
