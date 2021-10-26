#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
    int random[10];
    FILE *file = open("/dev/random", O_RDONLY, 0644);
    int error = read(file, random, 40);
    if (error == -1){
        printf("error %d when reading\n", error);
    }
    printf("Generating random numbers: \n");
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("\trandom %d: %d\n", i+1, random[i]);
    }
    printf("Writing numbers to file\n");
    remove("randomresult.bin");
    file = open("randomresult.bin", O_WRONLY | O_CREAT, 0644);
    error = write(file, random, 40);
    if (error == -1){
        printf("error %d when writing\n", error);
    }
    file = open("randomresult.bin", O_RDONLY, 0644);
    for (i = 0; i < 10; i++)
    {
        random[i] = NULL;
    }
    error = read(file, random, 40);
    if (error == -1){
        printf("error %d when reading\n", error);
    }
    printf("Reading numbers from file\n");
    printf("Verifying that written values are the same: \n");
    for (i = 0; i < 10; i++)
    {
        printf("\trandom %d: %d\n", i+1, random[i]);
    }
}