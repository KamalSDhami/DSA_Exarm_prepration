#include <stdio.h>
#include <string.h>
int check (char *s1,char *s2){
    if (strlen(s1) != strlen(s2)){
        return 0;
    }
    int count [256] = {0};
    for (int i = 0 ; s1[i] && s2[i]; i++){
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for (int i =0 ; i<256;i++){
        if (count[i] != 0){
            return 0;
        }
    }
    return 1;
}

int main(){

    char s1[100],s2[100];
    printf("Enter the first string\n");
    gets(s1);
    printf("Enter the second string\n");
    gets(s2);
    if (check(s1,s2)){
        printf("Anagram\n");
    }
    else{
        printf("Not Anagram\n");
    }

    return 0;
}