#include <iostream>
#include <algorithm>

using namespace std;

struct item{
	int peso; // peso do item
	int val; // valor do item
};

// 1º criterio - maior valor
// 2º criterio - menor peso
bool cmp(item a, item b)
{
	if(a.val != b.val)
	{
		return a.val > b.val;
	}
	else
	{
		return a.peso < b.peso;
	}
}

int main(){
	item v[100]; // vetor de itens
	int n; // qnt. de itens
	int cap;
	
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
	
	// 1º criterio - maior valor
	// 2º criterio - menor peso
	sort(v, v+n, cmp);
	// sort(nome do vetor, nome do vetor + tam, funcao de comparacao
	int resp;
	resp=0;
	for(int i=0; i<n; i++)
	{
		if(cap>= v[i].peso)
		{
			resp = resp + v[i].val;
			cap = cap - v[i].peso;
		}
	}
	cout << "O valor maximo eh " << resp << endl;
	
}










