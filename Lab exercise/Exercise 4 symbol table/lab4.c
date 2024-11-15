#include<stdio.h>
#include<string.h>
#include<malloc.h>
int main()
{
    char input[20];
    char lexeme[10];
    char tokentype[10][20];
    int *address[10]={0,0,0,0,0,0,0,0,0,0};
    int *mem;
    printf("Enter expression : \n");
    gets(input);
    int i=0;
    int n=strlen(input);
    for(i=0;i<n;i++)
    {
        if(input[i]=='x' || input[i]=='y')
        {
            lexeme[i]=input[i];
            strcpy(tokentype[i],"keyword");
        }
        else if(input[i]>='a' && input[i]<='z')
        {
            lexeme[i]=input[i];
            strcpy(tokentype[i],"identifier");
            mem=malloc(input[i]);
            address[i]=mem;
        }
        else if(input[i]>='0' && input[i]<='9')
        {
            lexeme[i]=input[i];
            strcpy(tokentype[i],"constant");
            mem=malloc(input[i]);
            address[i]=mem;
        }
        else if(input[i]=='=')
        {
            lexeme[i]=input[i];
            strcpy(tokentype[i],"assign_operator");
        }
        else if(input[i]=='+')
        {
            lexeme[i]=input[i];
            strcpy(tokentype[i],"add_operator");
        }
        else if(input[i]=='-')
        {
            lexeme[i]=input[i];
            strcpy(tokentype[i],"sub_operator");
        }
        else if(input[i]=='*')
        {
            lexeme[i]=input[i];
            strcpy(tokentype[i],"mul_operator");
        }
    }
    printf("-------------------------------------------------------------------------\n");
    printf("|\tLEXEME\t\t|\tADDRESS\t\t|\tTOKEN TYPE\t|\n");
    printf("-------------------------------------------------------------------------\n");


    for(i=0;i<n;i++)
    {
        if(address[i]!=0)
        {
            printf("|\t%C\t\t|\t%u\t|\t%s\t|\n",lexeme[i],address[i],tokentype[i]);
        }
        else{
            printf("|\t%c\t\t|\t\t\t|\t%s\t|\n",lexeme[i],tokentype[i]);
        }
    }
    printf("-------------------------------------------------------------------------\n");

    return 0;
}
