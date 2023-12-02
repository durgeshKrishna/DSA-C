#include <stdio.h>
#include <ctype.h>
int s[100];
int top = -1;
int flag = 0;

int pop()
{
  return (s[top--]);
}

int push(int elem)
{
  if (flag == 1)
  {
    int num;
    num = pop();
    s[++top] = elem + 10 * num;
  }
  else if (flag == 0)
  {
    s[++top] = elem;
    flag = 1;
  }
}

int main()
{
  char str[50];
  int i = 0, op1, op2;
  printf("Enter the Postfix Expression:");
  scanf("%[^\n]s", str);
  while (str[i] != '\0')
  {
    if (isdigit(str[i]))
      push(str[i] - '0');
    else if (str[i] == ' ')
      flag = 0;
    else
    {
      flag = 0;
      op2 = pop();
      op1 = pop();
      switch (str[i])
      {
      case '+':
        push(op1 + op2);
        break;
      case '-':
        push(op1 - op2);
        break;
      case '*':
        push(op1 * op2);
        break;
      case '/':
        push(op1 / op2);
        break;
      default:
        printf("Invalid Input");
      }
    }
    i++;
  }
  printf("Result: %d\n", s[top]);
}

