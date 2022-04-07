#include <iostream>
#include <string>
using namespace std;

string segunda_passada(string text)
{
	int tam = text.length();

	for(int i = 0; i < tam / 2; i++ )
	{
		swap(text[i], text[tam - i - 1]);
	}

	return text;
}

void terceira_passada(string text)
{
	int tam = text.length();

	for(int i = tam / 2; i <= tam; i++)
	{
		text[i] -= 1;
	}
	cout << text << "\n";
}


void primeira_passada(string text)
{
	int tam = text.length();

	for(int i = 0; i <= tam; i++)
	{
		if(int(text[i]) >= 'A' && int(text[i]) <= 'Z')
		{
			text[i] += 3;
		}
		else if(int(text[i]) >= 'a' && int(text[i]) <= 'z')
		{
			text[i] += 3;
		}
	}

	string text_aux = segunda_passada(text);
	terceira_passada(text_aux);
}


int main(int argc, char** argv)
{
	string text;
	int n;
	cin >> n;
	cin.ignore();
	
	for(int i = 0; i < n; i++)
	{
		getline(cin, text);
		primeira_passada(text);
		
	}

	return 0;
}