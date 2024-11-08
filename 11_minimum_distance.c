/*Given an unsorted array of integers and two numbers a and b. Design an algorithm and write a
program to find minimum distance between a and b in this array. Minimum distance between any
two numbers a and b present in array is the minimum difference between their indices*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
int main(){
    int tc;
    printf("enter the tc : ");
    scanf("%d",&tc);
    for (int i =0;i<tc;i++){
        int n;
        printf("Enter the value of n : ");
        scanf("%d",&n);
        int arr[n];
        printf("Enter the element of array : ");
        for (int j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        int a,b;
        printf("Enter the value of a and b : ");
        scanf("%d%d",&a,&b);
        int min_diff=INT_MAX;
        for (int j =0;j<n;j++){
            for (int k =j+1; k<n;k++){
                if ((arr[j] == a&& arr[k]==b) || (arr[j] ==b && arr[k] ==a)){
                    if (min_diff >abs(k-j)){
                        min_diff = abs(k-j);
                    }
                }
            }
        }printf("min_diff : %d\n",min_diff);
    }
}

//Enter the value of n : 15
// Enter the element of array : -2 8 7 1 2 6 8 9 0 2 -6 12 9 7 1
// Enter the value of a and b : 7 2