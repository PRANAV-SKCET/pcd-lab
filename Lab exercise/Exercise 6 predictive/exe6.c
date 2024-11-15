#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char input[20];
char stack[20];
char table[3][5][20] = {{"S->aAb", "","S->cBd","",""},{"A->aA",
"A->e","","",""},{"","B->bB","","B->e",""}};
int i = -1;
char ch;

void push(char ch) {
    i++;
    stack[i] = ch;
}
char pop() {
    ch = stack[i];
    stack[i] = '\0';
    i--;
    return ch;
}
int getrow(char ch) {
    switch(ch) {
        case 'S': return 0;
        case 'A': return 1;
        case 'B': return 2;
    }
}
int getcolumn(char ch) {
    switch(ch) {
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case '$': return 4;
    }
}
int main() {
    printf("Enter the input: ");
    gets(input);

    push('$');
    push('S');

    int k = 0, row, col;
    char grammar[20];
    printf("\n%s\t%s\t%s\n", "Stack", "Input", "Action");

    while(input[k] != '\0') {
        ch = pop();
        if(input[k] != ch)
        {
            row = getrow(ch);
            col = getcolumn(input[k]);
            strcpy(grammar, table[row][col]);
            if(strcmp(grammar, "") == 0)
            {
                printf("\nParsing Error.\n");
                break;
            }
            for(int j = strlen(grammar)-1;j >= 0 && grammar[j] != '>';j--)
                if(grammar[j] != 'e')
                    push(grammar[j]);
        }

        else if(input[k] == '$' && ch == '$')
        {
            printf("\nParsing successful.\n");
        }

        else if(input[k] == ch)
        {
            input[k] = '_'; k++;
        }
        printf("%s\t%s\t%s\n", stack, input, grammar);
    }
    return 0;
}
