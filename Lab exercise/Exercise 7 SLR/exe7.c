#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ptable[5][5][20]={
                        {"s2","","","1",""},
                        {"","","accept","",""},
                        {"","s4","","","3"},
                        {"","","r1","",""},
                        {"","","r2","",""}
                      };
char stack[20];
char input[20];
char action[20];
int i=-1;
void push(char ch)
{
    i++;
    stack[i]=ch;
}
void pop()
{
    stack[i]=' ';
    i--;
}
int getrow(char ch)
{
    switch(ch)
    {
        case '0' : return 0;
        case '1' : return 1;
        case '2' : return 2;
        case '3' : return 3;
        case '4' : return 4;

    }
}
int getcol(char ch)
{
    switch(ch)
    {
        case 'a' : return 0;
        case 'b' : return 1;
        case '$' : return 2;
        case 'S' : return 3;
        case 'A' : return 4;

    }
}
int main()
{
    int k=0;
    int j=0;
    printf("Enter the input \n");
    gets(input);
    int n = strlen(input);
    push('0');
    while(input[k] != '\0')
    {
        int row = getrow(stack[i]);
        int col = getcol(input[k]);
        strcpy(action,ptable[row][col]);
        if(strcmp(action,"s2") == 0)
        {
            push(input[k]);
            push('2');
            input[k]=' ';

            printf("%s\%s\t%s\n",stack,input,action);
             k++;
        }
        else if(strcmp(action,"s4") == 0)
        {
            push(input[k]);
            push('4');
            input[k]=' ';

            printf("%s\%s\t%s\n",stack,input,action);
            k++;
        }
        else if(strcmp(action,"r2") == 0)
        {

            for(int i=0;i<2;i++)
            {
                pop();
            }

            push('A');
            int row = getrow(stack[i-1]);
            int col = getcol(stack[i]);


            if(strcmp(ptable[row][col],"3") == 0)
                push('3');


            printf("%s\%s\t%s\n",stack,input,action);

        }
        else if(strcmp(action,"r1") == 0)
        {
            for(int i=0;i<4;i++)
            {
                pop();
            }
            push('S');
            int row = getrow(stack[i-1]);
            int col = getcol(stack[i]);

            if(strcmp(ptable[row][col],"1") == 0)
                push('1');


            printf("%s\%s\t%s\n",stack,input,action);
        }
        else if(strcmp(action,"accept")==0)
        {
            printf("\n success");
            break;
        }
        else{
            printf("failure");
            break;
        }
    }
    return 1;
}
