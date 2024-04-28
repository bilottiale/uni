# Appunti

## `typedef`

È una parola chiave per dare un nome ad un nuovo *tipo*.

```c
typedef int kilometer;

kilometer newyork, losangeles;

newyork = 4000;
losangeles = 3000;
```

## `struct`

Raggruppare variabili di tipo diverso in un'unica struttura.

```c
struct Student {
    char name[50];
    int age;
    int grade[5];
};

struct Student kevin;

strcpy(kevin.name, "Kevin");
kevin.age = 20;
kevin.grade[0] = 30;
kevin.grade[1] = 25;
kevin.grade[2] = 28;
kevin.grade[3] = 27;
kevin.grade[4] = 29;
```

Con `typedef` per avere codice più pulito:

```c
typedef struct {
    char name[50];
    int age;
    int grade[5];
} Student;

Student kevin;

strcpy(kevin.name, "Kevin");
kevin.age = 20;
kevin.grade[0] = 30;
kevin.grade[1] = 25;
kevin.grade[2] = 28;
kevin.grade[3] = 27;
kevin.grade[4] = 29;
```

Possiamo passare ciò a funzioni:

```c
void printStudentGrades(Student student) {
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("Grades: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", student.grade[i]);
    }
}
```

### Inizializzare `struct`

```c
typedef struct {
    int x;
    int y;
} p1, p2;

Point p1 = {5, 10};
Point p2 = {.x = 5, .y = 10};
```
## Puntatori in `struct`

```c
typedef struct {
    int *array;
} Data;

Data x;
Data y;

x.array = malloc(sizeof(int) * 5); // memoria allocata dinamicamente
y.array = malloc(sizeof(int) * 5); // memoria allocata dinamicamente

x.array[0] = 1;
x.array[1] = 2;
x.array[2] = 3;
x.array[3] = 4;
x.array[4] = 5;

y.array[0] = 9;
y.array[1] = 9;
y.array[2] = 9;
y.array[3] = 9;
y.array[4] = 9;

free(x.array); // memoria deallocata
free(y.array); // memoria deallocata
```

## Arrow operator `->`

Permettere di accedere ai membri di una `struct` attraverso un puntatore. È un modo più pulito per scrivere `(*p).x`.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

int main(void){
    Point p1;

    p1.x = 3;
    p1.y = 4;

    Point *p2;
    p2 = &p1;

    p2->x = 5;
    p2->y = 6;

    // Stampa i valori in modo analogo
    printf("x: %d, y: %d\n", p1.x, p1.y);
    printf("x: %d, y: %d\n", p2->x, p2->y);

    Point *p3;
    p3 = malloc(sizeof(Point));

    p3->x = 7;
    p3->y = 8;

    printf("x: %d, y: %d\n", p3->x, p3->y);

    // In modo analogo, ma meno leggibile
    (*p3).x = 9;
    (*p3).y = 10;

    printf("x: %d, y: %d\n", (*p3).x, (*p3).y);


    return 0;
}
```
