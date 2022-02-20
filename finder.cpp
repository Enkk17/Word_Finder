#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//dichiariamo le funzioni
string file_content();
bool badchar(char c);
int has_word(string pattern, string text);


int main()
{
string pattern;
cout<<"inserisci la parola che stai cercando : ";
cin>>pattern;

//lettura del file
string text = file_content();


//sostituiamo tutti i badchar con uno spazio
replace_if(text.begin(), text.end(), badchar, ' ');

int conteggio = has_word(pattern, text);


//stampa dei risultati

if (conteggio == 0) 
	{
  	cout << "la parola " << pattern << " non  e presente nel testo!";
	} else {
  	cout << "la parola " << pattern << " e' presente nel testo ed e' presente " << conteggio << " volte! ";
	}

return 0;
}

//questa funzione prende il contenuto del file
string file_content() 
{
	// filestream variabili
    fstream file;
    string filename;
 
    //dichiariamo filename che corrisponde al file che vogliamo aprire
    filename = "file.txt";
 
    //apertura del file
    file.open(filename.c_str());
  	
	// crea uno stringstream
	stringstream buffer;  
	
	// passa allo stringstream il buffer del file
	buffer << file.rdbuf();

	//lettura file
	return buffer.str(); 
  	
}

//questa funzione controlla se pattern è una parola (stringa separata da spazi) in text.
int has_word(string pattern, string text)
 {
  istringstream stream(text);
  int contatore=0;
  for (string word; stream >> word;)  // per ogni parola nel testo
	{
		if(word == pattern) 
		{
		contatore++;
		}	
	}
	return contatore;
}

// Tutto ciò che non è alfabetico né uno spazio è "bad" (da scartare).
bool badchar(char c) 
{ 
return !isalpha(c) && !isspace(c); 
}
