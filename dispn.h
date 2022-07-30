#ifndef DISP_H
#define DISP_H

void display(int num)
{
	if(num==0)
		return;

	display(num-1);
	printf("%d ", num);
}

#endif
