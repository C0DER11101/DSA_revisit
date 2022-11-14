#include<iostream>
#include<stdlib.h>
#include "Hash"

int main(void)
{
	Hash<int>arr(11); // size of the hash table!! 
	
	arr.insert(0); // 0 means "perform linear probing"

	arr.showTable();
	return 0;
}
