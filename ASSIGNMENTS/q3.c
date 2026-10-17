#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char value)
{
    stack[++top] = value;
}

char pop()
{
    return stack[top--];
}

int priority(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;

    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i = 0, k = 0;
    char ch;

    scanf("%s", infix);

    while (infix[i] != '\0')
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();

            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 && stack[top] != '(' &&
                   priority(stack[top]) >= priority(ch))
            {
                postfix[k++] = pop();
            }

            push(ch);
        }

        i++;
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("Postfix: %s\n", postfix);

    return 0;
}