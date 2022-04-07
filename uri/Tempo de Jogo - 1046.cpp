#include <iostream>

using namespace std;

int calculaHoras(int inicio, int fim)
{
	int horas = 0;
	
	horas = fim - inicio;
	
	if( horas > 0)
	{
		return horas;
	}else {
		return horas + 24;
	}
	

	return horas;

}

int main(int argc, char** argv)
{
	int horaInicial;
	int horaFinal;
	int resultado;
	
	cin >> horaInicial >> horaFinal;

	resultado = calculaHoras(horaInicial, horaFinal);

	cout << "O JOGO DUROU " << resultado << " HORA(S)\n";

	return 0;
}
