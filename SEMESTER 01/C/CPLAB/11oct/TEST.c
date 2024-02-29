//Programm to print sum of digits using for loop
#include <stdio.h>
#include <conio.h>
int main()
{
	int rem,N,sum=0;
	printf("Enter your number: ");
	scanf("%d", &N);
	for(N;N!=0;N=N/10)
	{
		rem=N%10;
		sum=sum+rem;
		
	}
	
	printf("%d",sum);
	
	return 0;
}
