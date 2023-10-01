#include <stdio.h>

char* nextToken(char* &str, char delimiter = ' ') {
    int count = 0;
    while (*str!=delimiter && *str!='\0') {
        str++;
        count++;
    }
    if (*str=='\0') {
        return str-count;
    }
    return (str++) - count;
}

int strlen_new(char* str) {
    int len = 0;
    while (*str !='\0') {
        char* beginningOfNextToken = nextToken(str);
        len += str - beginningOfNextToken;
    }
    return len;
}

void test_nextToken() {
    char* test_string = "Every Good Boy Does Fine!";
    while (*test_string!='\0') {
        printf("%c is the first character of the next token\n", *(nextToken(test_string)));
    }   
}

void test_strlen_new() {
    char* test_string = "Hello World!";
    printf("%d is the length of the input string %s", strlen_new(test_string), test_string);
}

int main() {
    test_nextToken();
    test_strlen_new(); 
}