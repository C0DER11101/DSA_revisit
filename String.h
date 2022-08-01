#ifndef STRF_H
#define STRF_H

int len(char*s) // find length of the string
{
	if(*s=='\0')
		return 0;

	return 1+len(s+1); // str+1 points to the next address of the array of characters!!
}

void showstr(char*s)
{
	if(*s=='\0')
		return;

	printf("%c", *s);
	showstr(s+1);
}

void rev(char*s)
{
	if(*s=='\0')
		return;

	rev(s+1);
	printf("%c", *s);
}

#endif
