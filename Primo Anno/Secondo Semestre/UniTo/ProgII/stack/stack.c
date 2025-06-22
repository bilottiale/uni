#include<stdlib.h>
#include<stdio.h>

#define NOVALUE -1000
#define MAX 5

typedef struct {
    int top;
    int dato[MAX];
} stack;

void init(stack *s){
    if(s){
        s->top = 0;
    } else {
        printf("s non esistente\n");
    }
}

int empty(stack s){
    return s.top == 0;
}

int full(stack s){
    return s.top == MAX;
}

void push(stack *s, int value){
    if(s){
        if(!full(*s)){
            s->dato[s->top] = value;
            s->top++;
        } else {
            printf("Stack pieno\n");
        }
    } else {
        printf("s non esistente\n");
    }
}

int pop(stack *s){
    int result = NOVALUE;
    if(s){
        if(!empty(*s)){
            result = s->dato[s->top];
            s->top--;
        } else {
            printf("Stack vuoto\n");
        }
    } else {
        printf("s non esistente\n");
    }
}

int peek(stack s){
    int result = NOVALUE;
    if(!empty(s)){
        result = s.dato[s.top -1];
    } else {
        printf("Stack vuoto\n");
    }
    return result;
}