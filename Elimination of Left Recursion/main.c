#include <stdio.h>
#include <string.h>
#define SIZE 10

int main()
{
    char non_terminal;
    char beta;
    char alpha;
    int num;
    int i;

    char production[10][SIZE];

    int index = 3;
    printf("\n Enter number of productions : ");
    scanf("%d",&num);

    printf("\n Enter the grammar as E->E-A : \n");

    for(i=0 ; i<num ; i++)
        scanf("%s",production[i]);

    for(i=0 ; i<num ; i++)
    {
        printf("\nGrammar ::: %s",production[i]);
        non_terminal = production[i][0];

        if(non_terminal == production[i][index])
        {
            alpha = production[i][index+1];
            printf(" is left recursive.\n");
            while(production[i][index] != 0 && production[i][index] != '|')
                index++;

            if(production[i][index] != 0)
            {
                beta = production[i][index+1];
                printf("Grammar without left recursion:\n");
                printf("%c -> %c%c\'",non_terminal,beta,non_terminal);
                printf("\n%c\' -> %c%c%c\'|e\n",non_terminal,alpha,beta,non_terminal);
            }
            else
                printf("Can\'t be reduced\n");
        }
        else
            printf("Not recursive...\n");

        index = 3;
    }
    return 0;
}
