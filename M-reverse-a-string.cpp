#include<iostream>
using namespace std;

// Sol1
void swap(char *a,char *b){
    *a= *a^*b;
    *b= *a^*b;
    *a= *a^*b;
}

void reverse1 (char *s){
    if (*(s+1) == '\0') return;
    reverse1(s+1);
    swap(s, s+1);
}

void reverseAll (char *s){
    if((*s=='\0'))return;
    while(*(s+1) != '\0'){
        reversOne(s);
        s++;
    }
}

// Sol2
void reverse(char *s){
    int begin, end, count = 0;
    while (s[count] != '\0')
        count++;

    end = count - 1;

    for (begin = 0; begin < count; begin++) {
        r[begin] = s[end];
        end--;
    }

    r[begin] = '\0';

    printf("%s\n", r);

    return 0;
}