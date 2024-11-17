#include <iostream>
#include <vector>
#include <climits>

int startInd = 0;
int endInd = 0;

// Функция нахождения начального и конечного индекса
// подмассива с максимальной суммой элементов по алгоритму Кадане
void kadane(std::vector<int> const &arr)
{
	// инициализируем переменную минимальным значением
	int max_so_far = 0;
	// максимальная сумма подмассива, заканчивающегося в текущей позиции, инициализируем нулем
	int max_ending_here = 0;
	// проход по массиву
	for (int i = 0; i < arr.size(); i++)
	{
		// обновление max_ending_here добавлением 
		// текущего элемента к максимальной сумме c предыдущим индексом "i-1"
		max_ending_here = max_ending_here + arr[i];
		// если i элемент больше суммы подмассива
		// установим начало подмассива на текущий элемент
		if (arr[i] > max_ending_here) startInd = i;
		// обновление максимальной суммы элементов на текущей позиции элементом i
		max_ending_here = std::max(max_ending_here, arr[i]);
		// обновим max_so_far максимальным числом
		if (max_so_far < max_ending_here) endInd = i;
		// cout << endl << endInd << endl;
		max_so_far = std::max(max_so_far, max_ending_here);
	}
}
int main()
{
	std::vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	endInd = arr.size();
	kadane(arr);
	std::cout << "Indexes of the subarray with the maximum sum of elements " << startInd << " and " << endInd;
	return 0;
}

/*
Вам даётся массив целых чисел.Необходимо найти в массиве такие два индекса i и j, 
что сумма a[i], a[i + 1], a[i + 2], …, a[j] будет максимально возможной, и вывести их.
Пример
a = { −2, 1, −3, 4, −1 ,2 ,1 ,−5 ,4 }
Наибольшая сумма последовательных элементов находится между 
индексами 3 и 6: {4, −1, 2, 1}, сумма = 6. Необходимо вывести 3 и 6.
*/  