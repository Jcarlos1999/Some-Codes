#include <iostream>

using namespace std;

void numeros_impares(int num){
	for(int i = 1; i <= num; i+=2)
	{
		cout << i << "\n";
	}
}

int main(int argc, char** argv)
{
	int num = 0;
	
	cin >> num;
	
	numeros_impares(num);
	
	return 0;
}