#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

void main(){
    printf("Enter string ending with $: \n");
    
    char s[20], ch;
    int i=0, j=0, k=0;
    void *p, *addr[5];
    char c, d[5];
    
    while((ch=getchar())!='$'){
        s[i++]=ch;
    }
    
    int n=i-1;
    
    printf("Symbol\tAddr\tType\n");
    
    while(j<=n){
        ch=s[j];
        if(isalpha(ch)){
            p=malloc(ch);
            addr[k]=p;
            d[k]=ch;
            printf("%c\t%d\tIdentifier\n", ch, p);
            k++;
            j++;
        }else{
            if(strchr("+-*/", ch)){
                p=malloc(ch);
                addr[k]=p;
                d[k]=ch;
                printf("%c\t%d\tOperator\n", ch, p);
                k++;
                j++;
            }
        }
    }
    
}
