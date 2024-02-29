//Programm to print sum of digits using while loop
#include <stdio.h>
#include <conio.h>
int main()
{
	int rem,N,sum;
	printf("Enter your number: ");
	scanf("%d", &N);
	while(N!=0)
	 {
	    rem=N%10;
	    sum=sum+rem;
	    N=N/10;
	 	
	 }
	
	printf("%d",sum);
	
	return 0;
}
