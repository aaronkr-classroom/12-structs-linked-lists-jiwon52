//us.c
#include <stdio.h>

typedef unsigned short int us;

int main(void) {
	us data = 5;
	us temp;

	temp = data;
	printf("temp = %d\n", temp);

	return 0;
}