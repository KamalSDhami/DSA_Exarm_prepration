/*III. Given an array of nonnegative integers, where all numbers occur even number of times except
one number which occurs odd number of times. Write an algorithm and a program to find this
number. (Time complexity = O(n))*/
#include <stdio.h>
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
        int result = 0;
        for (int j = 0; j < n; j++) {
            result ^= arr[j];
        }
        printf("result : %d",result);

    }
}

/* m1 :xor, m2 : frequency
5 : 2 4 3 2 3 : 4
11 : 1 6 3 2 4 1 4 2 3 6 6 : 6
15 : 2 8 7 1 2 6 8 9 0 2 6 2 9 7 1 : 0
*/