#include<iostream>
#include<stdlib.h>
#include "Hash"

int main(void)
{
	Hash<char>arr(11); // size of the hash table!! 
	
	arr.insert(0); // 0 means "perform linear probing"

	arr.showTable();
	return 0;
}
