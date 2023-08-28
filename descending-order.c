// Descending order using merge sort
#include<stdio.h>
void printArray(int *a,int n)
{
    int i;
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",a[i]);
    }
}
void merge(int a[],int left,int right,int q)
{
    int i,j,k;
    int n1=q-left+1;
    int n2=right-q;
    int l[n1],r[n2];
    for(i=0;i<n1;i++)
    {
        l[i]=a[left+i];
    }
    for(j=0;j<n2;j++)
    {
        r[j]=a[q+1+j];
    }
    i=0;
    j=0;
    k=left;
    while(i<n1&&j<n2)
    {
        if(l[i]<=r[j])
        {
            a[k]=l[i];
            i++;
        }else
        {
            a[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=l[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=r[j];
        j++;
        k++;
    }
}
void mergeSort(int *a,int left,int right)
{
    int q;
    if(left<right)
    {
        q=(left+right)/2;
        mergeSort(a,left,q);
        mergeSort(a,q+1,right);
        merge(a,left,right,q);
    }
}
int main()
{
    int i,n;
    printf("Enter array size:");
    scanf("%d",&n);
    printf("Enter array elements:");
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,n-1);
    printArray(a,n);
}
