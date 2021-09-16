#include <iostream>
#include <algorithm> // next_permutation
#include <climits> // INT_MAX

using namespace std;

int main()
{
	int custo[100][100]; // custo[i][j] -> custo de ir da cidade i para a cidade j
	int n; // numero de cidades
	int ci; // cidade inicial
	int v[100]; // armazenar as cidades a serem permutadas
	
	// Entrada
	cout << "Entre com o numero de cidades: ";
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		for(int j = i+1;j<=n;j++)
		{
			cout << "Entre com o custo de ir da cidade "<< i <<" para a cidade "<< j <<endl;
			cin >> custo[i][j];
			custo[j][i] = custo[i][j];
		}
	}
	cout << "Entre com a cidade inicial: " <<endl;
	cin >> ci;
	
	
	for(int i = 1,p = 0;i <= n;i++) // coloca em um vetor as cidades a serem permutadas (todas exceto a inicial)
	{
		if(i != ci)
		{
			v[p] = i;
			p++;
		}
	}
	
	int menor_custo = INT_MAX; // comeca com um valor muito grande (o maior valor do int)
	int custo_atual;
	int at;
	do{
		custo_atual = 0;
		at = ci; // sai da cidade inicial
		for(int i = 0;i < n-1;i++) // passa por todas as outras
		{
			custo_atual = custo_atual + custo[at][v[i]];
			at = v[i];
		}
		custo_atual = custo_atual + custo[at][ci];// e volta pra inicial
		
		if(custo_atual < menor_custo) // salva o menor custo geral
			menor_custo = custo_atual;
	
	}while(next_permutation(v,v + (n-1)); // faz as permutações das cidades (exceto a inicial)
	// (vetor , vetor + tamanho do vetor)
	// ATENÇÃO -> para usar o next_permutation, o vetor tem que estar ordenado, senao ele nao faz todas as permutações
	
	cout << "Menor custo: " << menor_custo << endl;
	return 0;
}









