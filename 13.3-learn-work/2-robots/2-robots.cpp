#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

vector<int> removingElement(vector<int> vec, int index)
{
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
	int K, num, index, number;
	vector<int> vec(0);
	cout << "Enter K: ";
	cin >> K;
	for (int i = 0; i < K; i++)
		{
			cout << "Enter actions and index (number): ";
			cin >> num >> index;
			if (num == 1) vec.insert(vec.end(), index);
			else if (num == 2 && index >= 0 && index < vec.size()) 
				vec = removingElement(vec, index);
			else cout << "Incorrect input!" << endl;
	}
	cout << "There are robots in the window {";
	// На витрине остались роботы
	for (int i = 0; i < vec.size(); i++)
	{
		if (i < vec.size() - 1) cout << vec[i] << ", ";
		else cout << vec[i] << "}" << endl;
	}
}

/*
Представим, что роботов могут не только покупать, забирая с витрины, но и «выставлять» в конец витрины. 
Пусть с клавиатуры вводят число K, а потом — K запросов вида 1 n и 2 m. Запрос вида 1 n означает, 
что в конец витрины поставили робота с номером n. Запрос 2 m означает, что с витрины забрали робота 
по индексу m. Необходимо смоделировать такое взаимодействие и после проведения всех запросов вывести 
на экран оставшихся на витрине роботов.
*/
