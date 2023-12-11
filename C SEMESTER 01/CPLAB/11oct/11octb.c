//Programm to print numbers in descending order using while loop
#include <stdio.h>
#include <conio.h>
int main()
{
	int N;
	printf("Enter your value: ");
	scanf("%d", &N);
	while(N>=1)
	 {
	 	printf("%d",N);
	 	N--;
	 }
	return 0;
}
