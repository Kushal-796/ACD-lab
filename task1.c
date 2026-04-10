#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char *s=(char *)calloc(sizeof(char), 20000);
    char *t=(char *)calloc(sizeof(char), 20000);
    
    FILE *fp;
    int i=0, j=0, k=0, c=0;
    char f[20], ch;
    char keywords[32][20]={};
    
    printf("Enter file name:");
    scanf("%s", f);
    
    fp=fopen(f, "r");
    
    
    if(fp==NULL)    {
        printf("File cannot be opened");
        return 0;
    }
    
    while(ch=fgetc(fp)!=EOF){
        *(s+i)=ch;
        i++;
    }
    

    *(s+i)='\0';
    printf("-----Analysis------");
    i=0;
    
    while(*(s+i)!='\0'){
        
        
        // Preprocessor directive
        if(*(s+i)=='#'){
            i++;
            while(*(s+i)!='\n'){
                printf("%c", *(s+i));
            }
            printf("-> is a preprocessor directive");
        }
        
        
        //Keyword, function or identifier
        else if(isalpha(*(s+i)) || *(s+i)=='_'){
            j=0;
            *(t+j)=*(s=i);
            while((isalnum(*(s+i))||*(s+i)=='_')&&*(s+i)!='\0'){
                *(t+j)=*(s+i);
            }
            *(t+j)='\0';
            
            for(k=0;k<32;k++){
                if(strcmp(*(t+j), keywords[k])==0){
                    c=1;
                }
            }
            if(c==1){
                printf("%s is a keyword", *(t+j));
            }
            else if(*(s+i)=='('){
                printf("%s is a function", *(t+j));
            }else{
                printf("%s is a identifier", *(t+j));
            }
        }
        
        
        
        //Strings
        else if(*(s+i)=='"'){
            i++;
            while(*(s+i)!='"'){
                printf("%c", *(s+i));
            }
            printf(" is a string");
        }
        
        
        
        //Comments
        else if(*(s+i)=='/' && (*(s+i+1)=='/')||(*(s+i+1)=='*')){
            i++;
            if(*(s+i)=='/'){
                i++;
                while(*(s+i)!='\n'){
                    printf("%c", *(s+i));
                }
            }else{
                i++;
                while(*(s+i)=='*' && *(s+i+1)=='/'){
                    printf("%c", *(s=i));
                }
            }
            i+=2;
            printf(" is a comment");
        }
        
        
        //Number
        else if(isdigit(*(s+i))){
            while(isdigit(*(s+i))||*(s+i)=='.'){
                printf("%c", *(s+i));
            }
            i++;
            printf(" is a number");
        }
        
        
        
        //Spl symbol
        else if(strchr("[]{}()", *(s+i))){
            printf("%c is a special symbol", *(s+i));
            i++;
        }
        
        
        
        //Operator
        else if(strchr("+-*/%=<>!&|", *(s+i))){
            printf("%c is an operator", *(s+i));
            i++;
        }
        
        
        
        //Terminator
        else if(*(s+i)==';'){
            printf("%c is terminator", *(s+i));
            i++;
        }
        
        
        
        else{
            i++;
        }
    }
    
    fclose(fp);
    return 0;
    
    
    
}
