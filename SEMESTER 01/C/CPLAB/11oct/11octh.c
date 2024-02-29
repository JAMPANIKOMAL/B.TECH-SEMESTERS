//Programm to print sum of digits using do_while loop
#include <stdio.h>
#include <conio.h>
int main()
{
	int rem,N,sum=0;
	printf("Enter your number: ");
	scanf("%d", &N);
	do
	 {
	    rem=N%10;
	    sum=sum+rem;
	    N=N/10;
	 	
	 }while(N!=0);
	
	printf("%d",sum);
	
	return 0;
}
