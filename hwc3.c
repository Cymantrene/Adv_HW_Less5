#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int datatype;


void push(datatype);
datatype pop(void);
void operate(char);

#define SIZE 255

datatype stack[SIZE];

datatype LevelFullStack = 0;

void push(datatype InputData)
{

    if(LevelFullStack >= SIZE)
    {
        fprintf(stderr, "Stack overflow\n");
        exit(1);
    }

    stack[LevelFullStack++] = InputData;
}


datatype pop()
{

    if(LevelFullStack <= 0)
    {
        fprintf(stderr, "Stack underflow\n");
        exit(1);
    }

    return stack[--LevelFullStack];
}

void operate(char c)
{
    datatype arg1 = pop();
    datatype arg2 = pop();

    switch(c)
    {
    case '+':
        push(arg1 + arg2);
        break;
    case '-':
        push(arg2 - arg1);
        break;
    case '*':
        push(arg1 * arg2);
        break;
    case '/':

        if (arg1 == 0)
        {
            fprintf(stderr, "Error div 0!!!.\n");
            exit(1);
        }
        push(arg2 / arg1);
        break;
    }
}

bool isDigit(char c)
{
    return ((c >= '0') && (c <= '9'));
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int main(void)
{
    char c;
    char str[1000]= {0};
    int len = 0;
    while((c = getchar()) != '\n')
        str[len++] = c;
    for(int i = 0; i < len; i++)
    {
        if(isDigit(str[i]))
        {
            datatype num;
            for(num = 0; isDigit(str[i]); i++)
            num =   num*10 + str[i] - '0';
            push(num);
        }
        else if (isOperator(str[i]))
        {
            operate(str[i]);
        }
    }
    printf("%d\n", pop());
    return 0;
}
