#include <iostream>

using namespace std;

int mdc(int a, int b)
{
	int r;

	while(b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main(int argc, char** argv)
{
	int a , b, n;
	int result;
	cin >> n;

	while(n != 0)
	{
		cin >> a >> b;
		cout << mdc(a, b) << "\n";
		n--;
	}

	
	return 0;
}
