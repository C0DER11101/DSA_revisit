/*

   Given a 10 x 10 board of snake and ladder game, marked with numbers in the range [1-100], find the minimum
   number of throws required to win it (reach board #1 to board #100).

Input: Map of snakes and ladders

Ladder = {80=99, 1=38, 51=67, 4=14, 21=42, 72=91, 9=31, 28=84}
Snake = {64=60, 17=7, 98=79, 54=34, 87=36, 93=73, 62=19, 95=75}

Output: 7

Explanation: The game requires at least 7 dice throws to win.

*/


// YET TO BE COMPLETED!!!



#include<iostream>
#include<stdlib.h>
#include "maxm.h"
#include "SnLQ.h"
#include "SandL.h"


int main(void)
{
	int init, fnal;
	cout<<"enter the coordinates for ladder: ";
	cout<<"enter 0 or a negative number to stop:\n";

	initBoard(); // mark the numbers in the board!!
	defaultEdges();

	while(true)
	{
		cout<<"initial: ";
		cin>>init;
		cout<<"final: ";
		cin>>fnal;

		if(init<=0 || fnal<=0)
		{
			cout<<"Aborted\n";
			break;
		}

		else if(init>100 || fnal>100)
		{
			cout<<"\n\ninvalid.....try again....\n";
			continue;
		}

		edge(init, fnal);

	}

	MinThrows(1); // assuming the game will start from square 1
	showPath(100);
	return 0;
}
