//Programm to print numbers in ascending order using do_while loop
#include <stdio.h>
#include <conio.h>
int main()
{
	int N,i=1;
	printf("Enter your number: ");
	scanf("%d", &N);
	do
	{
		printf("%d", i);
		i++;
		
	}while(i<=N);
	
	return 0;
}
