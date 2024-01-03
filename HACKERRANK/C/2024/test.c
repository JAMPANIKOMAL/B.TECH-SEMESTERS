#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
    int m=(n+(n-1));
    int o=n;
  	for (int i=0; i<n; i++)
    {
        if (i==0)
        {
            for (int x=0; x<n; x++)
            {
                printf("%d ", n);
            }
            printf("\n");
        }
        else
        {    
            printf("%d ", n);
            for (int x=1; x<n; x++)
            {
                printf("%d ", o-i);
            }
            printf("\n"); 
        }
      }
    
        return 0;
}
