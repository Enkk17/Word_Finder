#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	
	string research;
	bool verify=false;
	cout<<"enter what you want to search for: ";
	
	getline(cin,research);
	
	// filestream variables
    fstream file;
    string word, t, q, filename;
  
    // we declare the variable filename which corresponds to the name of the file
    filename = "file.txt";
  
    //open file
    file.open(filename.c_str());
    
    
    //we declare for loop to read all the words in the file
    for(int x=0 ; file >> word; x++)
    {
    	//comparison of words with user input
    	if(word==research)
    	{
		verify=true;
    	}
    }
    
    //print the result
    if(verify==true)
    {
    cout<<"the word " << research << " is present in the text!";
	}else
	{
	cout<<"the word " << research << " is not present in the text!";
	}
    return 0;
}
