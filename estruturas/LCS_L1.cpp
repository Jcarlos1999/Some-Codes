#include <iostream>
using namespace std;

int main()
{
	int pd[100][100],caminho[100][100];
	int t1;
	int t2;
	char s1[100];
	char s2[100];
	cout << "Entre com o tamanho da sequencia 1: ";
	cin >> t1;
	cout << "Entre com o tamanho da sequencia 2: ";
	cin >> t2;
	
	for(int i = 0;i < t1;i++)
		cin >> s1[i];
	
	for(int i = 0;i < t2;i++)
		cin >> s2[i];  
	
	for(int i = 0;i < t2;i++)
		pd[i][t1] = 0;
	
	for(int i = 0; i < t1;i++)
		pd[t2][i] = 0; 
	
	for(int i = t1-1;i >= 0; i--)
		for(int j = t2-1;j >= 0; j--)
		{
			if(s1[i] == s2[j]) // se as duas forem iguais
			{
				pd[i][j] = pd[i+1][j+1] + 1; // 1 + valor da proxima linha e proxima coluna
				caminho[i][j] = 0;           // igual -> caminho = 0
			}
			else
			{
				if(pd[i+1][j] > pd[i][j+1]) // abaixo é maior que na frente -> caminho = 2;
				{
					pd[i][j] = pd[i+1][j];
					caminho[i][j] = 2;
				}
				else                       	// na frente é maior que abaixo -> caminho = 1;
				{
					pd[i][j] = pd[i][j+1];
					caminho[i][j] = 1;
				}
			}
		}
	cout <<"Mostrando a matriz pd: " << endl;
	for(int i = 0; i <t1; i++)
	{
		for(int j = 0; j < t2; j++)
			cout << pd[i][j] << " ";
		
		cout << endl;
	}
		
	cout << "O tamanho da LCS entre as sequencias 1 e 2 eh: " << pd[0][0] << endl;	
	
	// recuperação de caminho: tenho que recuperar "tam_LCS" caracteres das sequencias
	
	cout << "Subsequencia: ";
	int tam_LCS = pd[0][0];
	int i = 0,j = 0;
	while(tam_LCS > 0)
	{
		if(caminho[i][j] == 0) // eh igual (diagonal)
		{
			cout << s1[i] << " "; // cout << s2[j] << " "; tambem eh valido
			tam_LCS--; // recuperei 1 valor
			i++;
			j++;
		}
		else if(caminho[i][j] == 1) // na frente (proxima coluna)
		{
			j++;
		}
		else // caminho[i][j] == 2 -> abaixo (proxima linha)
		{
			i++;
		}  
	}
	
	return 0;	
}























