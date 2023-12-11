//Programm to print numbers in descending order using for loop
#include <stdio.h>
#include <conio.h>
int main()
{
	int N;
	printf("Enter your number: ");
	scanf("%d", &N);
	for(N;1<=N;N--)
	{
		printf("%d", N);
	}
	
	return 0;
}
