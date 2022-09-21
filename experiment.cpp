#include<iostream>
#include<string.h>

using namespace std;

int main(void)
{
	char s[200][200], opnBrkt;
	int tracker=0;
	bool end=false;
	cin>>opnBrkt; //open bracket '{'
	getchar();
	for(int i=0; i<200 && end!=true; i++)
	{
		cin.getline(s[i], 4);
		for(int j=0; j<200; j++)
		{
			if(s[i][j]=='}')
			{
				end=true;
				break;
			}
		}

		tracker=i;
	}


	cout<<"{ ";
	for(int i=0; i<=tracker; i++)
		cout<<s[i];


	return 0;
}
