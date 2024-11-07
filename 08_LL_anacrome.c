// find 2 string are anacrome or not

#include <stdio.h>
#include <string.h>

int is_anagram(char *s1, char *s2){
    int count[256] = {0};
    if (strlen(s1) != strlen(s2)){
        return 0;
    }
    for (int i = 0; s1[i] && s2[i]; i++){
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for (int i = 0; i < 256; i++){
        if (count[i] != 0){
            return 0;
        }
    }
    return 1;
}
// what is anacrome
// two string are anacrome if they have same character with same frequency
int main(){
    char s1[] = "listen";
    char s2[] = "silent";
    if (is_anagram(s1,s2)){
        printf("Anagram\n");
    }
    else{
        printf("Not Anagram\n");
    }
    return 0;
}
