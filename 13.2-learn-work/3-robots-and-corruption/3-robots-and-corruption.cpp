#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int main()
{

	int num = 0;
	int position = 0;
	cout << "Enter number ";
	cin >> num;
	vector<int> vec {num};
	while (true)
	{
		cout << "Enter number and position ";
		cin >> num >> position;
		assert(int(num));
		assert(int(position));
		vec.insert(vec.begin() + position - 1, num);
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
		cout << endl;
	}
}

/* Улучшите электронную очередь для роботов.К нам приходят роботы разного социального статуса.
Каждый робот вводит не только свой уникальный номер, но и свое место в очереди.Например, 
пусть в нашей очереди 10 роботов и к нам приходит 11 - й.Сначала он вводит свой номер, как и раньше, 
а затем свое место в очереди - например, 5. В этом случае он должен оказаться в очереди пятым, 
а все остальные, начиная со старого пятого - подвинуться дальше в конец очереди.
Реализуйте функцию std::vector<int> add_to_position(std::vector vec, int val, int position) 
*/