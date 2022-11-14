#include<iostream>
#include<stdlib.h>
#include "Hash"

using namespace std;

int main(void)
{
	Hash<int>arr(11);

	arr.insert(1); // perform quadratic probing
	
	arr.showTable();

	return 0;
}
