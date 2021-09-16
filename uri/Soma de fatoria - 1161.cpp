#include <iostream>
#include <iomanip>
using namespace std;

// logita ta certa, mas a para com eof ainda falta

double calc_fatorial(int m)
{
	double m_result = 1;

	if(m == 0)
	{
		return 1;
	}
	else
	{
		while(m != 0)
		{
			m_result *= m;
			m--;
		}
	}

	return m_result;
}

int main(int argc, char** argv)
{
	int m , n;
	double resultado_fatorial;

	

	while(1)
	{
		cin >> m;
		if( m == -1) {break;}
		cin >> n;
		resultado_fatorial = calc_fatorial(m) + calc_fatorial(n);
		cout << resultado_fatorial << "\n";
	}
	

	return 0;
}
