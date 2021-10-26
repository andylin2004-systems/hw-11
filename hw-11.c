#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int * readRandomFile(){
    int random[10];
    FILE *file = fopen("/dev/random", "r");
    read(file, random, 40);
    return random;
}

int main(){
    int i;
    int *random = readRandomFile();
    char buffer[] = "";
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", random[i]);
    }
    FILE *createFile = fopen("randomresult", "a");
    write(createFile, random, 40);
}