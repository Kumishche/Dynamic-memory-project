## Практическая работа №2. 
# Работа с динамическими массивами и указателями в C++

В работе необходимо реализовать следующие операции при работе с матрицами:
1. Ввод данных с консоли (матрицы, вектор)
2. Вывод данных на консоль (матрицы, вектор)
3. Выполнение вычислительной операции с матрицами или векторами (с учётом варианта)

Доступ к операциям реализовать через консольное меню. Программа должна допускать
многократное проведение операций с пользователем в произвольном порядке. В работе нужно
использовать динамические массивы, размеры массивов определяются во время выполнения
программы и могут изменяться пользователем. Необходимо предусмотреть обработку
некорректного пользовательского ввода, а также освобождение динамической памяти.

Программу необходимо структурировать следующим образом: файл с кодом консольного меню
(source.cpp), файл с определениями вычислительных функций (matrix.cpp) и файл с объявлениями
функций (matrix.h).

В реализации одной из функций (н-р, вывод на консоль) необходимо использовать указатели и
адресную арифметику для доступа к элементам массива без применения операции
индексирования.

Вычислительная операция при работе с массивами определяется в зависимости от варианта по
следующей формуле (вариант выводится на консоль):
int V = int(c) % 8, где с – первая буква фамилии студента на английском языке в верхнем регистре.
Например, вариант преподавателя V = int(‘T’) % 8 = 4. 
