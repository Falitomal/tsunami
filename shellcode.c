#include "studio.h"
#include "windows.h"

//Este programa ejecuta la consola de windows y abrira la calculadora, obtendremos mediante shellcode

int main()
{
    LoadLibrary("msvcrt.dll");
    __asm{ //para ejecutar codigo ensamblador en C
        push ebp //Guardamos el puntero de pila
        mov ebp, esp //Movemos el puntero de pila a ebp
        xor edi, edi //Ponemos a 0 edi
        push edi //Ponemos a 0 el puntero de pila
        sub esp,08h //Reservamos 8 bytes en la pila
        mov byte ptr [ebp-09h],63h // Caracter c
        mov byte ptr [ebp-08h],61h // Caracter a   
        mov byte ptr [ebp-07h],6Ch // Caracter l
        mov byte ptr [ebp-06h],63h // Caracter c
        mov byte ptr [ebp-05h],2Eh // Caracter .
        mov byte ptr [ebp-04h],65h // Caracter e
        mov byte ptr [ebp-03h],78h // Caracter x
        mov byte ptr [ebp-02h],65h // Caracter e
        lea eax, [ebp-09h] //Carga la dirrecion efectiva de memoria (load effective address) con la cadena
        push eax //Guardamos en la pila la direccion de memoria de ebp-09h
        mov ebx, 0x77c293c7 // Aqui cargamos el valor hexadecimal de la libreria system
        call ebx //Llamamos a ebx que es la direccion de memoria de ebp-09h
    }
}
