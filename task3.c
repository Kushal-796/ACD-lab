#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void main()
{
    int i = 0, n;
    void * p, * add[5]; // because these store addresses
    char ch, srch, b[15], d[15], c;
    
    
    while ((c = getchar()) != '$'){
        b[i++] = c;
    }
    
    n = i - 1;
    printf("Given Expression:");
    i = 0;
    
    while (i <= n){
        printf("%c", b[i++]);
    }
    
    printf("\n Symbol Table\n");
    printf("Symbol \t addr \t type");
    
    int j=0, x=0;
    
    while (j <= n){
        c = b[j];
        if (isalpha(c)){
            p = malloc(c);
            add[x] = p;
            d[x] = c;
            printf("\n%c \t %d \t identifier\n", c, p);
            x++;
            j++;
        }
        else{
            ch = c;
            if (ch == '+' || ch == '-' || ch == '*' || ch == '='){
                p = malloc(ch);
                add[x] = p;
                d[x] = ch;
                printf("\n %c \t %d \t operator\n", ch, p);
                x++;
                j++;
            }
        }
    }
}
