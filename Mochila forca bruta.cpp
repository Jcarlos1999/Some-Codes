#include <iostream>
#include <algorithm>

using namespace std;

struct item{
	int peso; // peso do item
	int val; // valor do item
};

int mochila_fb(item *v, int n, int i, int cap)
{
	if (i == n) // Se cheguei em um item inexistente 
		return 0; // retorno 0
	int pega, npega; // valor de pegar ou nao pegar o item
	pega = 0; // Inicializa o pega com 0, pois nem sempre consigo pegar o item
	npega = mochila_fb(v,n,i+1,cap); // Avanço para o proximo item, mantendo a capacidade
	if(cap >= v[i].peso) // se eu tenho capacidade na mochila 
	{
	// avanço para o proximo item, subtraindo da capacidade e somando o valor do item
		pega = mochila_fb(v,n,i+1,cap - v[i].peso) + v[i].val;
	}
	
	// Retorno o maior entre pegar e nao pegar
	if(pega > npega)
		return pega;
	else 
		return npega;
}

int main(){
	item v[100]; // vetor de itens
	int n; // qnt. de itens
	int cap;// capacidade da mochila
	
	//Entrada
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
	
	int resp;
	resp = mochila_fb(v,n,0,cap); // Vou analizar a partir do item 0, com capacidade maxima
	cout << resp << endl;
	return 0;
}