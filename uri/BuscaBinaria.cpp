#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int pesquisa_binaria( vector <int> &list, int item)
{

	int low = 0;
	int high = list.size() -1;
	int middle = 0;
	int shot = 0;
	int count = 1;
	
	while(low <= high)
	{
		middle = (low + high) / 2;
		shot = list[middle];
		cout << "Try " << count << ": " << shot << "\n";
		if (shot == item)
		{
			return list[middle];
		}
		else if (shot > item)
		{
			high = middle - 1;
		}
		else
		{
			low = middle + 1;
		}
		count++;
	}
	return -1;

}


int main(int argc, char** argv)
{
	vector<int> list;
	int item = 787;
	int rd = 0;

	for(int i = 0; i < 1000; i++)
	{
		rd = rand() % 1000 + 165;
		list.push_back(rd);
	}

	sort(list.begin(),list.end());

	cout << "\n";
	int result = pesquisa_binaria(list, item);

	if(result == -1)
	{
		cout << "Valor nao existe na lista";
	}
	else
	{
		cout << "Valor = " << result;
	}


	return 0;
}
