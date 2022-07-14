#include <iostream>
#include <vector>

using namespace std;

int calculaHoras(int inicio, int fim, int minIni, int minFim)
{
	int vec[2];
	
	vec[0] = fim - inicio;
	vec[1] = minFim - minIni;
	
	if( vec[0] < 0)
	{
		vec[0] += 24; 
		vec[1] += 60;
	}	

	return vec;

}

int main(int argc, char** argv)
{
	int horaInicial;
	int minInicial;
	int horaFinal;
	int minFinal;
	int resultado[2];
	
	cin >> horaInicial >> minInicial >> horaFinal >> minFinal;

	resultado = calculaHoras(horaInicial, horaFinal);

	cout << "O JOGO DUROU " << resultado << " HORA(S)\n";

	return 0;
}
