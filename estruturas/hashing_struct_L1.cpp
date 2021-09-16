#include <iostream>
#include <cstring>

using namespace std;

#define m 11

struct heroi
{
	char nome[40];
	int poder;
	int hp;
	int chave;
	int status;
	/*
	0 - vazio
	1 - ocupado
	2 - removido
	*/	
};

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
	return ((k % m) + i * (1+k % (m-1))) % m; 
}

//calcula a chave a partir de um nome
int calcula_chave(char nome[])
{
	int k;
	k = 0;
	for(int i = 0;i < strlen(nome);i++)
		k = k + (int)nome[i];
	return k;
}

// insere uma chave k na tabela
// retorna a posicao ou -1 se a estiver cheia
int hash_insert(heroi *T,heroi novo)
{
	int i; // tentativa (numero de colisoes)
	int j; // posicao
	i = 0;
	novo.chave = calcula_chave(novo.nome);
	do
	{
		j = h1(novo.chave,i);
		/*
			h1 = sondagem linear
			h2 = sondagem quadratica
			h3 = double hashing
		*/
		if(T[j].status != 1)
		{
			T[j] = novo;
			T[j].status = 1;
			return j;
		}
		i++;
	}while(i != m);
	return -1;
}

// Busca
// retorna a posicao que encontrou ou -1 se nao encontrar
int hash_search(heroi *T,heroi B)
{
	int i; // tentativa (numero de colisoes)
	int j; // posicao
	i = 0;
	B.chave = calcula_chave(B.nome);
	do
	{
		j = h1(B.chave,i);
		/*
			h1 = sondagem linear
			h2 = sondagem quadratica
			h3 = double hashing
			* TEM QUE UTILIZAR A MESMA FUNCAO HASH QUE FOI UTILIZADA PARA INSERCAO
		*/
		
		// encontrou se bateu o nome e EH UMA POSICAO OCUPADA. Se for uma posição removida por exemplo, nao pode contar que encontrou
		if(strcmp(T[j].nome,B.nome) == 0  && T[j].status == 1) 
		{
			return j; // quando retorna, a funcao acaba, e o codigo volta para onde a funcao foi chamada
		}
		i++;
	}while(i != m && T[j].status != 0); // procura enquanto nao acabou de ver na tabela e nao encontrou uma posicao vazia
	return -1;
}

void hash_remove(heroi *T,heroi R)
{
	int pos;
	pos = hash_search(T,R);
	if(pos != -1)
	{
		T[pos].status = 2; // passa a ser uma posicao removida
	}
}

void listar(heroi *T)
{
	for(int i = 0;i < m;i++)
	{
		if(T[i].status == 1)
		{
			cout << "Nome: " << T[i].nome << endl;
			cout << "Poder: " << T[i].poder << endl;
			cout << "HP: "<<T[i].hp<<endl;
		}
	}
	cout << endl;
}

// Inicializa a tabela hash
void init(heroi T[])
{
	// Inicialmente inicializa a tabela com status = 0, indicando que todas as posicoes estao vazias
	for(int i = 0;i < m;i++)
		T[i].status = 0;
}

int main()
{
	heroi T[m]; // tabela hash
	int r; // quantidade de remocoes na tabela
	int pos; // posicao que o numero foi encontrado na tabela (ou -1, se nao foi encontrado)
	heroi x; // numero a ser removido/inserido na tabela
	int n; // numero de herois a serem inseridos
	
	init(T); // inicializa a tabela
	
	// numero de herois a serem inseridos
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin.ignore();
		cin.getline(x.nome,40);
		cin >> x.poder;
		cin >> x.hp;
		hash_insert(T,x);
	}
	
	listar(T);
	
	// numero de herois a serem removidos
	cin >> r;
	cin.ignore();
	for(int i = 0;i < r;i++)
	{
		cin.getline(x.nome,40);
		hash_remove(T,x);
	}
	
	listar(T);
	
	return 0;
}






