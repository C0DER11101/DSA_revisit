#ifndef SandL_H
#define SandL_H

int Board[10][10], num=1;
int adjMat[100][100];

void initBoard()
{
	int num=1;
	for(int i=1; i<=10; i++)
	{
		for(int j=1; j<10; j++)
		{
			Board[i][j]=num;
			num++;
		}
	}
}

void defaultEdges()  // by-default: the vertices that we can reach through a dice!!
{
	for(int i=1; i<=100; i++)
	{
		for(int j=1; j<=12; j++) // 2 times 6 is valid!!
		{
			adjMat[i][i+j]=1;
		}
	}
}

void edge(int iV, int tV)
{
	adjMat[iV][tV]=1;
}

void MinThrows(int sV) // BFS
{
	int temp;
	pred[sV]=-1;
	nq(sV);
	state[sV]=waiting;

	while(frt()!=-1)
	{
		temp=dq();
		state[temp]=visited;

		for(int i=1; i<=MAX; i++)
		{
			if(adjMat[temp][i]==1 && state[i]==initial)
			{
				nq(i);
				pred[i]=temp;
				state[i]=waiting;
			}
		}
	}
}

void showPath(int num)
{
	while(pred[num]!=-1)
	{
		SPath[Spidx]=num;
		Spidx++;
		num=pred[num];
	}

	SPath[Spidx]=num;


	for(int i=Spidx; i>=0; i--)
		cout<<SPath[i]<<" ";
}


/*void showBoard()
{
	for(int i=1; i<=MAX; i++)
	{
		for(int j=1; j<=MAX; j++)
			cout<<Board[i][j]<<" ";
		cout<<endl;
	}
}

void showMat()
{
	for(int i=1; i<=MAX; i++)
	{
		for(int j=1; j<=MAX; j++)
			cout<<adjMat[i][j]<<" ";
		cout<<endl;
	}
}
*/
#endif // SandL_H
