#work
В этой работе реализован алгоритм поиска локальных значимых точек экстреммума для не аналитической функции(реальной или случайной выборки).
 Описание алноритма: 1. Находим просто точки экстремума без учета их значимости(%).
		     2. Оставляем только значимые.
		     3. Заменяем множество соседних максимумов(минимумов) на отрезках значимого 			возрастания убывания на один в этом орезке.

Для 3-го пункта используем вектор пар - где первый элемент пары значение экстреммумв, второй элемент - тип bool(0 - для минимума, 1 - для максимума). Если вектор пуст добавляем элемент иначе если значение второго параметра последнего элемента вектора совпадает с текущим до переписываем последний элемент иначе добавляем в конец новый элемент вектора.
