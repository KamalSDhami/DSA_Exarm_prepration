/*Given a boolean matrix (contains only 0 and 1) of size m X n where each row is sorted, write an
algorithm and a program to find which row has maximum number of 1's. (Linear time
complexity)*/
#include<stdio.h>
int main()
{ //take input from user
    int n,m;
    scanf("%d %d",&n, &m);
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    //check the for higest 1
    int check=0,row=0 ;
    for (int i = 0;i<n;i++){
        for (int j =m -check ; j >=0 ; j--){
            if (a[i][j] == 1){
                check ++;
                row = i+1;
            }
            else{
                break;
            }
        }
    }
    printf("row : %d",row);
    return 0;
}
