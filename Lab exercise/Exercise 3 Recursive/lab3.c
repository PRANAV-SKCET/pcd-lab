#include<stdio.h>
char input[50];
int i=0;
void E()
{
    if(input[i]=='(')
    {
        i++;
        T();
        i++;
        if(input[i]==')')
        {
            return;
        }
    }
}
void T()
{
    if(input[i]=='b')
    {
        i++;
        Tdash();
    }
}
void Tdash()
{
    if(input[i]=='a')
    {
        i++;
        Tdash();
    }
    else
    {
        return;
    }
}
void main()
{
    printf("enter the input:\n");
    gets(input);
    E();
    if(strlen(input)==i)
    {
        printf("Parsing successful");
    }
    else
    {
        printf("error");
    }
}
