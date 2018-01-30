#include<stdio.h>

int main() {
    int x = 1;
    char *p;

p = (char *) &x;
if (*p) printf("little endian");
else printf("big endian");

}
