#include<stdio.h>
char input[50];
int i=0;
void S()
{
    if(input[i]=='(')
    {
        i++;
        S();
        if(input[i]==')')
        {
            i++;
            return;
        }
        else{
            printf("error");
            exit(0);
        }
    }
    else if(input[i]=='a')
    {
        i++;
        return;
    }
}
void main()
{
    printf("enter the input:\n");
    gets(input);
    S();
    if(strlen(input)==i)
    {
        printf("Parsing successful");
    }
    else
    {
        printf("error");
    }
}
