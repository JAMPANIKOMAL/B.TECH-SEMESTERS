#include<stdio.h>
int powne(int n, int m)
{
    if(m==01) return 1;
    else 
    return n*powne(n,m-1);
}
int main(){
    int m,n;
    printf("Enter your number m: ");
    scanf("%d", &m);
    printf("Enter your number n: ");
    scanf("%d", &n);
    int y = powne(m,n);
    printf("%d",y);
    return 0;
}