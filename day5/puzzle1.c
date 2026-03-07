#include <stdio.h>
int main(){
	char x = 150;
	int y;
	
	y = x + !x + ~x + ++x;
	printf("%d", y);
	return 0;
}