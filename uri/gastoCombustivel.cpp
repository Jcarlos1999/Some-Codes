#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
	int h, v;
	
	cin >> h;
	cin >> v;
	
	cout << fixed << setprecision(3) <<(h*v)/12.0 << "\n";
	
	return 0;
}