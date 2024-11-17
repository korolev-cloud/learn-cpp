#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int startInd = 0;
int endInd = 0;

// Функция для нахождения начального и конечного индекса
// подмассива с максимальной суммой элементов
void kadaneNeg(vector<int> const &arr)
{
	// инициализируем переменную минимальным значением
	int max_so_far = INT_MIN;
	// максимальная сумма подмассива, заканчивающегося в текущей позиции, инициализируем нулем
	int max_ending_here = 0;
	// проход по массиву
	for (int i = 0; i < arr.size(); i++)
	{
															// 0	1	2	3	4	5	6	7	8
		// обновление max_ending_here добавлением  			  -2	1	-3	4	-1	2	1	-5	6
		// текущего элемента к максимальной сумме c предыдущим индексом "i-1")
		max_ending_here = max_ending_here + arr[i]; 		//-2	-1	-2	2	3	5	6	1	7
		// если i элемент больше суммы подмассива
		// установим начало подмассива на текущий элемент
		if (arr[i] > max_ending_here) startInd = i; 		//0		1	1	3	3	3	3	3	3
		// обновление максимальной суммы элементов на текущей позиции 
		// элементом i
		max_ending_here = max(max_ending_here, arr[i]); 	//-2	1	-2	4	3	5	6	1	7
		// обновим max_so_far максимальным числом
		if (max_so_far < max_ending_here) endInd = i; 		//0		1	1	4	4	5	6	6	8
		// cout << endl << endInd << endl;
		max_so_far = max(max_so_far, max_ending_here); 		//-2	1	1	4	4	5	6	6	8
	}
}
int main()
{
	vector<int> arr = { -2, 1, -3, 4, -1 ,2 ,1 ,-5, 4};
	endInd = arr.size();
	kadaneNeg(arr);
	cout << "Indexes of the subarray with the maximum sum of elements " << startInd << " and " << endInd;
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