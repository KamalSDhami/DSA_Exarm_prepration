/*Given a matrix of size n X n, where every row and every column is sorted in increasing order.
Write an algorithm and a program to find whether the given key element is present in the matrix
or not. (Linear time complexity)*/
#include<stdio.h>

int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n][n], target, i=0, j=n-1, flag=0;
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Enter the target: ");
    scanf("%d", &target);
    while(i<n && j>-1){
        if(arr[i][j]==target){
            flag=1;
            break;
        }
        else if(target<arr[i][j]){
            j--;
        }
        else{
            i++;
        }
    }
    if(flag==1){
        printf("Present");
    }
    else{
        printf("Not Present");
    }
    return 0;
}