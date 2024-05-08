#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

vector<int> removingElement(vector<int> vec, int index)
{
	assert((vec.size() - 1) > 0);
	vector<int> newVec(vec.size() - 1);
	for (int i = 0; i < vec.size(); i++)
	{
		if (i < index) newVec[i] = vec[i];
		else if (i > index) newVec[i - 1] = vec[i];
	}
	return newVec;
}

int main()
{
	int num;
	int position = 0;
	cout << "Enter N: ";
	cin >> num;
	vector<int> vec(num);

	for (int i=0; i < num; i++)
	{
		cout << "Enter the robot number: " << i + 1 << ": ";
		// Введите номер робота
		cin >> vec[i];
	}

	cout << "There are robots in the window {";
	// На витрине стоят роботы
	for (int i = 0; i < vec.size(); i++)
	{
		if (i < vec.size()-1) cout << vec[i] << ", ";
		else cout << vec[i] << "}" << endl;
	}
	int sale = 0;
	cout << "Enter M: ";
	cin >> sale;
	for (int i = 0; i < sale; i++)
	{
		cout << "Enter index robots for sale: ";
		// Введите индекс робота для продажи
		int indexSale;
		cin >> indexSale;
		if (indexSale > vec.size() - 1 || indexSale < 0) cout << "There is no such index!" << endl;
		else
			vec = removingElement(vec, indexSale);
		cout << "They took the robot with the index " << indexSale << endl;
		// взяли робота с индексом
	}
	
	cout << "There are robots in the window {";
	// На витрине стоят роботы
	for (int i = 0; i < vec.size(); i++)
	{
		if (i < vec.size() - 1) cout << vec[i] << ", ";
		else cout << vec[i] << "}" << endl;
	}
}

/*
На витрине стоят несколько роботов, у каждого есть номер. 
Количество роботов и их номера задаются с клавиатуры. 
Сначала вводим количество роботов N, затем для каждой позиции робота от 0 до N 
последовательно вводим N номеров роботов. Далее вводится число M, не превышающее 
количество роботов, и после этого — последовательно M индексов (от 0 до количества 
оставшихся роботов на витрине). Когда введён очередной индекс — робота покупают, 
то есть он покидает витрину, а остальные роботы «группируются», смещаясь на один шаг назад. 
Необходимо вывести список оставшихся после всех покупок роботов.

Пример

Введите N: 4

Введите номер робота 1: 100

Введите номер робота 2: 200

Введите номер робота 3: 250

Введите номер робота 4: 300

На витрине стоят роботы {100, 200, 250, 300}.

Введите M: 2

Введите индекс робота для покупки: 1

Забрали робота с индексом 1

На витрине остались роботы {100, 250, 300}.

Введите индекс робота для покупки: 5

Такого индекса нет

Введите индекс робота для покупки: 0

Забрали робота с индексом 0

На витрине остались роботы {250, 300}.

*/
