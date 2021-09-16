#include <iostream>

using namespace std;

#define m 11

int h1(int k,int i) // sondagem linear
{
	return (k + i) % m;
}

int h2(int k,int i) // sondagem quadratica
{
	return (k + i*1 + i*i*3) % m;
}

int h3(int k,int i) // double hashing
{
	return (k % m) + i * (1+k % (m-1)) % m; 
}

// insere uma chave k na tabela
// retorna a posicao ou -1 se a estiver cheia
int hash_insert(int *T,int k)
{
	int i; // tentativa (numero de colisoes)
	int j; // posicao
	i = 0;
	do
	{
		j = h1(k,i);
		/*
			h1 = sondagem linear
			h2 = sondagem quadratica
			h3 = double hashing
		*/
		if(T[j] == -1)
		{
			T[j] = k;
			return j;
		}
		i++;
	}while(i != m);
	return -1;
}

// Busca
// retorna a posicao que encontrou ou -1 se nao encontrar
int hash_search(int *T,int k)
{
	int i; // tentativa (numero de colisoes)
	int j; // posicao
	i = 0;
	do
	{
		j = h1(k,i);
		/*
			h1 = sondagem linear
			h2 = sondagem quadratica
			h3 = double hashing
			* TEM QUE UTILIZAR A MESMA FUNCAO HASH QUE FOI UTILIZADA PARA INSERCAO
		*/
		
		if(T[j] == k) // encontrou
		{
			return j;
		}
		i++;
	}while(i != m && T[j] != -1); // procura enquanto nao acabou de ver na tabela e nao encontrou uma posicao vazia
	return -1;
}

// Inicializa a tabela hash
void init(int T[])
{
	// Inicialmente inicializa a tabela com -1, indicando que todas as posicoes estao vazias
	for(int i = 0;i < m;i++)
		T[i] = -1;
}

int main()
{
	int T[m]; // tabela hash
	int q; // quantidade de buscas na tabela
	int pos; // posicao que o numero foi encontrado na tabela (ou -1, se nao foi encontrado)
	int x; // numero a ser buscado na tabela
	
	init(T); // inicializa a tabela
	
	// Inserindo alguns valores na tabela
	hash_insert(T,13);
	hash_insert(T,5);
	hash_insert(T,27);
	hash_insert(T,17);
	hash_insert(T,92);
	
	cout << "Entre com a quantidade de numeros a serem buscados na tabela" << endl;
	cin >> q;
	
	for(int i = 0;i < q; i++)
	{
		cout << "Entre com o numero a ser buscado na tabela: ";
		cin >> x;
		pos = hash_search(T,x);
		
		if(pos == -1) // nao encontrou
		{
			cout << "Numero nao encontrado" << endl;
		}
		else
		{
			cout << "Numero encontrado na posicao " << pos << endl;
		}
	}
	return 0;
}