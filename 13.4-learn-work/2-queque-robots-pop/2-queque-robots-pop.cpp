#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec(0);
	int num = 0;
	cout << "Enter number ";
	cin >> num;
	vec.push_back(num);
	while (num != -1)
	{
		cout << "Enter number ";
		cin >> num;
		assert(int(num));
		if (num >= vec[vec.size() - 1]) vec.pop_back();
		vec.push_back(num);
	}
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

/*
Робот приходит в очередь и заставляет уходить из конца очереди всех,
 чей номер меньше, чем у него, а потом становится в очередь сам.
 Последний робот будет иметь номер - 1 (и, соответственно, не сможет никого выгнать,
 так как остальные имеют положительные номера).Когда он пришёл, нужно вывести все номера в очереди на экран.
*/ 