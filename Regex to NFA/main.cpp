#include <iostream>
#include <conio.h>
#include <string.h>
#include <cstdio>

using namespace std;

char reg[20];
void postfix();
void e_nfa();
void disp(int, char, int);

int main(void)
{
    cin.sync_with_stdio(false);

    fflush(stdin);
    fflush(stdout);

    cin >> reg;
    postfix();
    cout << reg << endl;
    e_nfa();

    return 0;
}

void postfix()
{
    char str[10], stk[10];
    int string_n = 0, stk_n = 0;
    int n=0;
    strcat(reg,"X");

    while(reg[n]!='\0')
    {
        switch(reg[n])
        {
            case 'a':   str[string_n] = 'a';
                        string_n++;
                        str[string_n] = '\0';
                        break;

            case 'b':   str[string_n] = 'b';
                        string_n++;
                        str[string_n] = '\0';
                        break;

            case '*':   str[string_n] = '*';
                        string_n++;
                        str[string_n] = '\0';
                        break;

            case '(':   stk[stk_n] = '(';
                        stk_n++;
                        break;

            case ')':   stk_n--;
                        while(stk[stk_n] != '(')
                        {
                            str[string_n] = stk[stk_n];
                            stk[stk_n] = '\0';
                            string_n++;
                            str[string_n] = '\0';
                            stk_n--;
                        }
                        stk[stk_n] = '\0';
                        break;

            case 'X':   while(stk_n != 0)
                        {
                            stk_n--;
                            str[string_n] = stk[stk_n];
                            stk[stk_n] = '\0';
                            string_n++;
                            str[string_n] = '\0';
                        }
                        break;

            case '+':   if(stk[stk_n-1] != '+' && stk[stk_n-1] != '.')
                        {
                            stk[stk_n] = '+';
                            stk_n++;
                            stk[stk_n] = '\0';
                            break;
                        }
                        else
                        {
                            str[string_n] = stk[stk_n-1];
                            string_n++;
                            stk[stk_n-1]='+';
                            break;
                        }

            case '.':   if(stk[stk_n-1] != '+' && stk[stk_n-1] != '.')
                        {
                            stk[stk_n] = '.';
                            stk_n++;
                            stk[stk_n] = '\0';
                            break;
                        }
                        else
                        {
                            str[string_n] = stk[stk_n-1];
                            string_n++;
                            stk[stk_n-1] = '.';
                            break;
                        }

            default:    break;
        }
        n++;
    }
    strcpy(reg, str);
}


void e_nfa()
{
    int strt[3], last[3], s, l;
    int n=0, x=0, i=-1;

    while(reg[n] != '\0')
    {
        switch(reg[n])
        {
            case 'a':   i++;
                        strt[i] = x++;
                        last[i] = x++;
                        disp(strt[i], 'a', last[i]);
                        break;

            case 'b':   i++;
                        strt[i] = x++;
                        last[i] = x++;
                        disp(strt[i], 'b', last[i]);
                        break;

            case '+':   s = x++;
                        l = x++;
                        disp(s, 'e', strt[i]);
                        disp(s, 'e', strt[i-1]);
                        disp(last[i], 'e', l);
                        disp(last[i-1], 'e', l);
                        i--;
                        strt[i] = s;
                        last[i] = l;
                        break;

            case '.':   disp(last[i-1], 'e', strt[i]);
                        last[i-1] = last[i];
                        i--;
                        break;

            case '*':   s = x++;
                        l = x++;
                        disp(s, 'e', strt[i]);
                        disp(s, 'e', l);
                        disp(last[i], 'e', strt[i]);
                        disp(last[i-1], 'e', l);
                        strt[i] = s;
                        last[i] = l;
                        break;

            default:    break;
        }
        n++;
    }
    cout << i << "  " << strt[i] << "  " << last[i];
}


void disp(int qs, char a, int qf)
{
    cout << qs << "\t-->\t" << a << "\t-->\t" << qf << "\n";
}
