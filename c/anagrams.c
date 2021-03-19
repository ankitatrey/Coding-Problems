#include <stdio.h>

int check(char a[], char b[]){
    int c = 0;
    int first[26] = {0}, second[26] = {0};
    printf(" %s--%s\n",a,b);
    while (a[c] != '\0'){
        first[a[c] - 'a']++;
        c++;
    }

    c = 0;
    while (b[c] != '\0'){
        second[b[c] - 'a']++;
        c++;
    }

    for (int c = 0; c < 26; c++){
        if (first[c] != second[c])
            return 0;
        else
            return 1;
    }
                      
}

int main(int argc, char *argv[]){
    if(argc == 3){      

        if (check(argv[1], argv[2]))
            printf("yes, strings are ansgrams of each other.\n");
        else
            printf("no, not a anagram string.\n");
    }
    else
    {
        printf("Provide two lowercase strings.\n");
    }   
}