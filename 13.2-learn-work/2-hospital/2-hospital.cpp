#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

vector<int> add(vector<int> vec, int val)
{
	vector<int> newVec(vec.size() + 1);
	for (int i = 0; i < vec.size(); i++) {
		newVec[i] = vec[i];
	}
	newVec[vec.size()] = val;
	return newVec;
}

int main()
{
	vector<int> vec;
	int num = 0;
	while (num != -1)
	{
		cout << "Enter age ";
		cin >> num;
		assert(int(num));
		if (num > 0) vec = add(vec, num);
	}
	float sum = 0.f;
	for (int i = 0; i < vec.size(); i++) sum += vec[i];
	if (vec.size() > 1) cout << "Avg age: " << sum / vec.size() << "Sum: " << vec.size();
	else cout << "Avg age: " << vec[0] << "Sum: " << vec.size();
}

/* Напишите программу для картотеки пациентов лечебницы. 
С клавиатуры вводится неизвестное количество целых положительных 
чисел - возрастов пациентов. Когда пациенты заканчиваются, медсестра 
вводит число -1. Это говорит программе о том, что пора заканчивать с 
приемом пациентов и переходить к расчету статистики.
 
Напишите программу, складывающую в вектор целые положительные числа, 
пока не поступит отрицательное число.После этого выведите среднее 
значение всех введенных чисел и их количество.
*/