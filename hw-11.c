#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
    int random[10];
    FILE *file = open("/dev/random", O_RDONLY, 0);
    printf("%s", strerror(read(file, random, 40)));
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", random[i]);
    }
    remove("randomresult.bin");
    FILE *createFile = open("randomresult.bin", O_WRONLY | O_CREAT, 0);
    printf("%s", strerror(write(createFile, random, 40)));
    createFile = open("randomresult.bin", O_RDONLY, 0);
    read(createFile, random, 40);
    printf("new data read");
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", random[i]);
    }
}