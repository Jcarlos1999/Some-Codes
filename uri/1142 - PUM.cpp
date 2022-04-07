#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int n;
	int aux = 1;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(j == 3)
			{
				cout << "PUM\n";
				aux++;
			}
			else
			{
				cout << aux << " ";
				aux++;
			}

		}
	}
	return 0;
}