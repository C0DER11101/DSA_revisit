#include<stdio.h>
#include<stdlib.h>
#include "stringrev.h"


int main(void)
{
	char*string;

	string=(char*)malloc(100*sizeof(char));
	printf("\nenter a string: ");
	scanf("%s", string);

	for(int i=0; string[i]!='\0'; i++)
	{
		push(string[i]);
	}

	printf("\n\nString in reverse order is\n\n");


	/* --- printing the entered string in reverse order --- */
	char str=pop();

	while(str!='\0')
	{
		printf("%c", str);
		str=pop();
	}

	printf("\n");


	free(string);

	return 0;
}
