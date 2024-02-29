//BINARY SEARCH
#include <stdio.h>
int binary_search(int a[], int n, int l, int h);
int main()
{
    int arr[]={10, 20, 30, 40, 50};
    int l=0;
    int h=sizeof(arr)/sizeof(arr[0]);
    int n;
    scanf("%d", &n);
    int result=binary_search(arr, n, l, h);
    printf("%d", result);
    return 0;
}

int binary_search(int a[], int n, int l, int h)
{
    int mid=l+(h-l)/2;
    if (a[mid]==n)
    {
        return mid;
    }  
    if (a[mid]<n)
    {
        return binary_search(a, n, l, mid-1);
    }
    if (a[mid]>n)
    {
        return binary_search(a, n, mid+1, h);
    }
    return 1;

}