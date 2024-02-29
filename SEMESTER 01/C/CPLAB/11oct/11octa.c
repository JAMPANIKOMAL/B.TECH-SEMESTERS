//Programm to print numbers in ascending order using while loop
#include <stdio.h>
#include <conio.h>
int main()
{
	int N,i=1;
	printf("Enter your number: ");
	scanf("%d", &N);
	while(i<=N)
	 {
	 	printf("%d",i);
	 	i++;
	 }
	return 0;
}
