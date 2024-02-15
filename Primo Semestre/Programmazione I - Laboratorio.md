### Prof. Alessia Antelmi
### Info esame
# C
[CheatSheet](https://www.geeksforgeeks.org/c-cheatsheet/)
[[README]]
## Indice
[[Programmazione I - Laboratorio#Hello, World!|Hello, World!]]

## Hello, World!
helloWorld.c

```c
#include<stdio.h> //header files
int main() //main function
{
    // Your code here
    printf("Hello, World!");
    return(0); //returning value to int main()
};
```
Run:
```bash
gcc helloWorld.c -o helloWorld
./helloWorld
```
## Data types
Explicit declaration
```c
char c = 'a';
int integer = 24;
float f = 24.32;
double d = 24.3435;
```

![[Pasted image 20231008224748.png]]

## Operazioni aritmetiche e type cast
*vedi [[Lab/Esercizi-20231002/*]]*

## Espressioni booleane e costrutto if-else
*vedi [[Lab/Esercizi-20231009/*]]*

compiling warnings
```bash
gcc -Wall -Werror aritmetica.c -o aritmetica
```
