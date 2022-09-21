#include<iostream>
#include<stdlib.h>

using namespace std;


char**s;
int main(void)
{
	int row;

	cout<<"enter number of rows: ";
	cin>>row;

	getchar(); // since cin leaves a newline character, it must be stored, otherwise it will hamper the inputs
	// that we are going to take using cin.getline() function

	s=new char*[row]; // allocating memory for row number of pointers to integer!!

	for(int i=0; i<row; i++)
		s[i]=new char[10]; // each pointer is allocated memory for an array of characters that has a length of col!!


	cout<<"enter strings:\n\n";

	for(int i=0; i<row; i++)
	{
		cout<<"String "<<i+1<<"\n";
		cin.getline(s[i], 10); // this is for taking string inputs!!!
	}

	for(int i=0; i<row; i++)
	{
		cout<<"String "<<i+1<<"\n";
		for(int j=0; j<10; j++)
		{
			if(s[i][j]==' ')
				;
			else
				cout<<s[i][j]-'0'+1<<endl;
		}
	}


	cout<<"\nthe strings are:\n\n";

	for(int i=0; i<row; i++)
		cout<<"String "<<i+1<<": "<<s[i]<<endl;


	for(int i=0; i<row; i++)
		delete s[i];

	delete s;

	return 0;
}
