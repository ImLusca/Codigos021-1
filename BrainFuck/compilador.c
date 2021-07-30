//Lucas Pereira Pacheco. nºusp:12543930 
//Compilador JIT de Brainf*ck
#include<stdio.h>
#include<stdlib.h>

void EscreveCabecalho(FILE *fp){
    fprintf(fp, "#include<stdio.h>\n");
    fprintf(fp, "int main(){\n");
    fprintf(fp, "char mem[30000];int i=0;\n");
    fprintf(fp, "for(int j=0; j< 30000;j++){ mem[j] = 0; } \n");
}

void EscrevePrint(FILE *fp){
    fprintf(fp, "printf(\"\\n\");\n");
    fprintf(fp, "for(int j =0;j < 30000; j++){ if(mem[j] != 0){ printf(\"%%i\",mem[j]); }}\n");    
    fprintf(fp, "printf(\"\\n\");\n");
    fprintf(fp,"return 0; }");
}


int main(){
    char comandoBF;
    FILE *fp;
    
    fp = fopen("Arquivo.c","w");

    EscreveCabecalho(fp);

    while( (comandoBF = getchar()) != EOF ){

        switch (comandoBF){
            case '+': fprintf(fp,"mem[i]++;\n");
            break;
            
            case '-': fprintf(fp,"mem[i]--;\n");
            break;

            case '>': fprintf(fp,"i++;\n");
            break;

            case '<': fprintf(fp,"i--;\n");
            break;

            case '.': fprintf(fp,"putchar(mem[i]);\n");
            break;

            case '[': fprintf(fp,"while(mem[i]){ ");
            break;

            case ']': fprintf(fp,"}");
            break;
        }
    }

    EscrevePrint(fp);

    fclose(fp);

    system("gcc Arquivo.c -o Compilado");
    system("./Compilado");

    return 0;
}

