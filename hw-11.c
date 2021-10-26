#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int * readRandomFile(){
    int random[10];
    FILE *file = open("/dev/random", O_RDONLY, 0);
    printf("%s", strerror(read(file, random, 40)));
    return random;
}

int main(){
    int i;
    int *random = readRandomFile();
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", random[i]);
    }
    FILE *createFile = open("randomresult", O_RDWR | O_CREAT, 0);
    printf("%s", strerror(write(createFile, random, 40)));
    int readRandom[10];
    read(createFile, readRandom, 40);
    printf("new data");
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", readRandom[i]);
    }
}