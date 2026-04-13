#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    FILE *fp;
    char ch, word[50];
    int i = 0, j, k, isKey;

    // Keyword list (as you asked)
    char key[32][12] = {
        "auto","break","case","char","const","continue","default","do","double",
        "else","enum","extern","float","for","goto","if","int","long","register",
        "return","short","signed","sizeof","static","struct","switch","typedef",
        "union","unsigned","void","volatile","while"
    };

    fp = fopen("input.txt", "r");   // keep fixed file (simple)

    if (fp == NULL) {
        printf("File not found\n");
        return 0;
    }

    printf("---- Analysis ----\n");

    while ((ch = fgetc(fp)) != EOF) {

        // Identifier / Keyword
        if (isalpha(ch) || ch == '_') {
            i = 0;
            word[i++] = ch;

            while (isalnum(ch = fgetc(fp)) || ch == '_') {
                word[i++] = ch;
            }
            word[i] = '\0';

            // Check keyword
            isKey = 0;
            for (k = 0; k < 32; k++) {
                if (strcmp(word, key[k]) == 0) {
                    isKey = 1;
                    break;
                }
            }

            if (isKey)
                printf("%s -> Keyword\n", word);
            else if (ch == '(')
                printf("%s -> Function\n", word);
            else
                printf("%s -> Identifier\n", word);

            ungetc(ch, fp);
        }

        // Number
        else if (isdigit(ch)) {
            printf("%c", ch);
            while (isdigit(ch = fgetc(fp)) || ch == '.') {
                printf("%c", ch);
            }
            printf(" -> Number\n");
            ungetc(ch, fp);
        }

        // Operator
        else if (strchr("+-*/%=<>!&|", ch)) {
            printf("%c -> Operator\n", ch);
        }

        // Special symbols
        else if (strchr("(){}[]", ch)) {
            printf("%c -> Special Symbol\n", ch);
        }

        // String
        else if (ch == '"') {
            printf("\"");
            while ((ch = fgetc(fp)) != '"') {
                printf("%c", ch);
            }
            printf("\" -> String\n");
        }

        // Comments
        else if (ch == '/') {
            char next = fgetc(fp);

            if (next == '/') {
                while ((ch = fgetc(fp)) != '\n') {
                    printf("%c", ch);
                }
                printf(" -> Comment\n");
            }
            else if (next == '*') {
                while (!((ch = fgetc(fp)) == '*' && (ch = fgetc(fp)) == '/'));
                printf("Multi-line Comment\n");
            }
            else {
                printf("/ -> Operator\n");
                ungetc(next, fp);
            }
        }

        // Terminator
        else if (ch == ';') {
            printf("; -> Terminator\n");
        }
    }

    fclose(fp);
    return 0;
}
