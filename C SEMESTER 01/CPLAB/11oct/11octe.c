//Programm to print numbers in ascending order using for loop
#include <stdio.h>
#include <conio.h>
int main()
{
	int N;
	printf("Enter your number: ");
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
	{
		printf("%d", i);
	}
	
	return 0;
}
