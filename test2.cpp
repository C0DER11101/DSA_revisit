#include<iostream>
#include<stdlib.h>

using namespace std;

int main(void)
{
	char*s=new char[100];

	cout<<"First input:\n";
	cin.getline(s, 3); // can take a string of length 3-1(whitespaces are counted)

	cout<<"Second input:\n";
	cin.getline(s, 4); // string of length 4-1

	cout<<"Third input:\n";
	cin.getline(s, 2); // string of length 2-1

	cout<<"Fourth input:\n";
	cin.getline(s, 10); // string of lenfth 10-1

	cout<<"Fifth input:\n";
	cin.getline(s, 1); // string of length 0

	cout<<"Sixth input:\n";
	cin.getline(s, 9); // string of length 9-1


	delete s;

	return 0;
}
