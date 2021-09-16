#include <iostream>
#include <algorithm>

using namespace std;

struct item{
	int peso; // peso do item
	int val; // valor do item
};

int main(){
	item v[100]; // vetor de itens
	int n; // qnt. de itens
	int cap; // capacidade da mochila
	
	// Entrada
	cout << "Entre com a quantidade de itens: ";
	cin>> n;
	for(int i=0; i<n; i++)
	{
		cout << "Qual o peso do item " << i+1 << endl;
		cin >> v[i].peso;
		cout << "Qual o val. do item " << i+1 <<endl;
		cin >> v[i].val;	

	}
	cout << "Qual a cap. da mochila? " << endl;
	cin >> cap;
	
	int pd [100][100]; // Matriz PD
	// i -> item
	// j -> cap. restante
	
	for(int i = n; i>=0; i--)
	{
		for(int j = 0; j<=cap; j++)
		{
			if(i == n)// nao consigo valores do item 'n' em diante (os itens vão de 0 a n-1)
				pd[i][j] = 0;
			else if(j == 0) // nao consigo valores quando a capacidade é 0
				pd[i][j] = 0;
			else
			{
				int pega, npega;
				pega = 0;// inicializar a opção pega com 0
				npega = pd[i+1][j]; // opção não pegar, mantem a capacidade e vai para o proximo item
				
				if(j >= v[i].peso) // Se posso pegar o item
				{
					pega = pd[i+1][j-v[i].peso] + v[i].val;//diminui a capacidade, vai para o proximo item e soma o valor do item atual
 	 	 	 	 	      // pd[i+1][cap-v[i].peso] já foi calculado antes
				}
				// A resposta sera o maior entre pega e nao pega
				if(pega > npega)
					pd[i][j] = pega;
				else 
					pd[i][j] = npega;
			}		
		}
	}
	
	// Mostra a matriz PD
	for (int i = 0; i<=n; i++){
		for (int j = 0; j<= cap; j++)
		{
			cout << pd[i][j] << " ";
		}
		cout << endl;
	}
	
	// A respota esta armazenada na posicao 0,cap
	// Observa a partir do item 0, usando a capacidade maxima
	cout << pd[0][cap];
	 
}	





