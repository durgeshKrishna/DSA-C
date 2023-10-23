#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int size,i,top=-1;
char str[100],stack[100];
int post[100];
bool condn = true;
bool is_empty()
{
    return top==-1;
 }
bool is_full()
{
    return top==size-1;
}
int pop()
{
    int n=post[top];
    stack[top];
    top--;
    return n;
}
void push(char data, int pos)
{
    top++;
    stack[top] = data;
    post[top] = pos;
}
int peek() 
    {return stack[top];}


void validbraces()
{
    for (i = 0; i < size; i++)
    {
        switch (str[i])
        {
        case '(':
            push(str[i], i);
            break;
        case '[':
            push(str[i], i);
            break;
        case '{':
            push(str[i], i);
            break;
        }
        if (!is_empty())
        {
            switch (str[i])
            {
            case ')':
                if (peek() == '(')
                {
                    pop();
                }
                else
                {
                    printf("\n %d  \n", pop());
                    condn = false;
                }
                break;
            case ']':
                if (peek() == '[')
                {
                    pop();
                }
                else
                {
                    printf(" \n %d  \n", pop());
                    condn = false;
                }
                break;
            case '}':
                if (peek() == '{')
                {
                    pop();
                }
                else
                {
                    printf(" %d ", pop());
                    condn = false;
                }
                break;
            }
        }
        else
        {
            printf("\n INVALID BRACE %d \n", i);
            condn = false;
        }
    }
    while(!is_empty())
    {
        condn=false;
        printf("%d   ",pop());
    }
    if (condn)
        printf(" VALID BRACES \n");
    else
        printf(" INVALID BRACES \n");
}
void main()
{
     printf("\n ENTER THE STRING \n");
    scanf("%s",str);
    size = strlen(str);
    validbraces();

}
