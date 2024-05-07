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
	vector<int> vec(1);
	int num = 0;
	cout << "Enter number ";
	cin >> num;
	vec[0] = num;
	while (true)
	{
		cout << "Enter number ";
		cin >> num;
		assert(int(num));
		vec = add(vec, num);
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
		cout << endl;
	}
}

// Повторите программу из теоретического материала. Напишите электронную очередь для андроидов. 
// Их количество неизвестно заранее. Каждый андроид вводит с клавиатуры свой идентификационный 
// номер - целое число. Нужно сохранить их номера в векторе в том порядке, в котором они записывались в очередь.