#include "stdio.h"
#include "string.h"


    // strcpy function copy the string from source to destination
    // strcpy funtion dosnt check the size of the buffer when the buffer is longer than 72 bytes the cocntent of the toher memory is overwrited
    // this cause the buffer overflow

int main(int argc, char **argv)
{
    char buffer[72];
    strcpy(buffer, argv[1]);
    printf("Buffer: %s\n", buffer);
    return 0;
}

