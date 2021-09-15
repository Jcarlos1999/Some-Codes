#include <iostream>
#include <climits>

using namespace std;

// inicializa o vetor de visitados com  false (no começo nenhuma cidade foi visitada)
void init(bool *vis,int n)
{
	for(int i = 1;i <= n;i++)
		vis[i] = false;
}

int main()
{
	int custo[100][100];
	int n; // numero de cidades
	int ci; // cidade inicial
	
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
	cout << "Entre com a cidade inicial: "<<endl;
	cin >> ci;
	
	
	int menor_atual;
	int menor_id;
	int at;
	bool vis[100];
	int resultado;
	
	resultado = 0;
	
	init(vis,n); // inicializa o vetor de visitados (ninguem foi visitado ainda)
	
	at = ci; // comeca pela cidade inicial
	
	for(int i = 0;i < n-1;i++)
	{
		vis[at] = true; // marca que visitou a cidade atual
		menor_atual = INT_MAX; // comeca com o maior valor do int (pois desejamos pegar o menor valor)
		
		for(int j = 1;j <= n;j++) // ve, dentre as cidades que ainda nao foram visitadas, qual esta mais perto da cidade atual
		{
			if(!vis[j] && custo[at][j] < menor_atual)// nao foi visitada e esta mais perto no momento
			{
				menor_atual = custo[at][j];
				menor_id = j;
			}
		}
		
		at = menor_id;// "foi" da cidade atual para a que esta mais perto da cidade atual e por isso...
		resultado = resultado + menor_atual; // ... somou o custo
	}
	resultado = resultado + custo[at][ci]; // soma o custo de ir da ultima cidade para voltar à cidade inicial
	
	cout << "Menor custo: " << resultado;
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	