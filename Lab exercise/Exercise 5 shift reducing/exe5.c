//E->E+E
//E->E*E
//E->(E) (a*a+a)
//E->a
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[20],input[20],action[20];
int i=0,j=0,k=0,n=0;
void reduce()
{
    strcpy(action,"Reduce");
    for(k=0;k<n;k++)
    {
        if(stack[k]=='a')
        {
            stack[k]='E';
            stack[k+1]='\0';
            printf("%s\t%s\t%s\n",stack,input,action);
        }
    }

    for(k=0;k<n-2;k++)
    {
        if(stack[k]=='E' && stack[k+1]=='+' && stack[k+2]=='E')
        {
            stack[k]='E';
            stack[k+1]='\0';
            stack[k+2]='\0';

            if(stack[k+3]!='\0')
            {
                stack[k+1] = stack[k+3];
                stack[k+2] = '\0';
            }
            printf("%s\t%s\t%s\n",stack,input,action);
            i=i-2;
        }
    }

    for(k=0;k<n-2;k++)
    {
        if(stack[k]=='E' && stack[k+1]=='*' && stack[k+2]=='E')
        {
            stack[k]='E';
            stack[k+1]='\0';
            stack[k+2]='\0';
            if(stack[k+3]!='\0')
            {
                stack[k+1] = stack[k+3];
                stack[k+2] = '\0';
            }
            printf("%s\t%s\t%s\n",stack,input,action);
            i=i-2;
        }
    }

    for(k=0;k<n-2;k++)
    {
        if(stack[k]=='(' && stack[k+1]=='E' && stack[k+2]==')')
        {
            stack[k]='E';
            stack[k+1]='\0';
            stack[k+2]='\0';
            if(stack[k+3]!='\0')
            {
                stack[k+1] = stack[k+3];
                stack[k+2] = '\0';
            }
            printf("%s\t%s\t%s\n",stack,input,action);
            i=i-2;
        }
    }
    return;
}
int main()
{
    printf("Enter input:\n");
    gets(input);
    n=strlen(input);

    printf("Stack\t input\t action\n");
    for(i=0;j<n;i++,j++)
    {
        strcpy(action,"Shift");
        stack[i]=input[j];
        stack[i+1] = '\0';
        input[j]=' ';
        printf("%s\t%s\t%s\t\n",stack,input,action);
        reduce();
    }

    reduce();
    if(stack[0]=='E' && stack[1]=='\0')
    {
        printf("Accept");
    }
    else
    {
        printf("Error");
    }
    return 1;
}
