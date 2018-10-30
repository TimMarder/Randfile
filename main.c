#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int rand() {

    int file = open("/dev/random", O_RDONLY);
    int r;
    read( file , &r , sizeof(r) );
    close( file );
    return r;

}

int main() {

    int one[10];
    int two[10];
    int result;

    for (int i = 0 ; i < 10 ; i++) {
        printf("Array one --> #%d: %d", i , result = rand());
        printf("\n");
        one[i] = result;
    }

    int file = open("numbers.txt", O_CREAT | O_WRONLY);
    write( file , one , sizeof(one) );
    close( file );

    file = open("numbers.txt", O_RDONLY);
    read( file , two , sizeof(one) );
    close( file );

    printf("==============================\n");

    for (int i = 0 ; i < 10 ; i++) {
        printf("Array two --> #%d: %d", i , two[i]);
        printf("\n");
    }
    return 0;

}
