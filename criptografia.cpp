#include <iostream>
#include <string>
using namespace std;

// Aprensentando Presentation error, logica 100%

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


string primeira_passada(string text)
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
	return text;
}


int main(int argc, char** argv)
{
	string text, text_result;
	int n;
	cin >> n;
	
	for(int i = 0; i <= n; i++)
	{
		getline(cin, text);
		text_result = primeira_passada(text);
		
	}

	return 0;
}
