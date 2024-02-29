//Programm to print numbers in descending order using do_while loop
#include <stdio.h>
#include <conio.h>
int main()
{
	int N;
	printf("Enter your number: ");
	scanf("%d", &N);
	do
	{
		printf("%d", N);
		N--;
		
	}while(1<=N);
	
	return 0;
}
