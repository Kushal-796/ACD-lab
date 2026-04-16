{%
  #include<stdio.h>
  int words=0, num=0, c_letters=0, s_letters=0, lines=0, spl_chars=0;
%}

%%
  /n{lines++, words++;}
  [/t' '] words++;
  [0-9] num++;
  [a-z] s_letters++;
  [A-Z] c_letters++;
  . spl_chars++;
%%

main(void){
    yyin=fopen("file.txt", "r");
    yylex();
    total=s_letters+c_letters+num+spl_char;
    print("File contains:\n");
    printf("%d Lines\n", lines);
    printf("%d words\n", words);
    printf("%d digits\n", num);
    printf("%d special chars\n", spl_chars);
    printf("total - %d chars\n", total);
}
int yywrap{
  return(1);
}
