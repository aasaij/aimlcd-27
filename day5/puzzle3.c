#include <stdio.h>
int main(){
//	char str[] = "Kavya";
	char str[100];
	int len;
	scanf("%s%n", str, &len);
//	int len = strlen(str);
//printf("%-*.*s",22,11,"Kavya is soooo beautiful!");
	for (int i = 1; i<=len; i++)
	printf("%*.*s%-*.*s\n",len,i, str,len, i, str);
	for (int i = len; i>=1; i--)
	printf("%*.*s%-*.*s\n",len,i, str,len, i, str);


//	printf("%5.2s\n", str);
//	printf("%5.3s\n", str);
//	printf("%5.4s\n", str);
//	printf("%5.5s\n", str);
//	printf("%05d", 12);
return 0;
}

kavya

k       k
 a     a
  v   v
   y y
    a
   y y
  v   v
 a     a
K       k