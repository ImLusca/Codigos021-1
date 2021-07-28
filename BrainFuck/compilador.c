//Lucas Pereira Pacheco. nºusp:12543930 
//Compilador JIT de Brainf*ck
#include<stdio.h>
#include<stdlib.h>

void InicializaMemoria(char *memoria){
    for(int i=0; i < 30000; i++){
        memoria[i] = 0;
    }
}

void PrintaMemoria(char *memoria){
    printf("\n");
    for(int i=0; i < 30000; i++){
        if(memoria[i] != 0){
            printf("%c", memoria[i]);
        }
    }
    printf("\n");
}


int main(){
    char memoria[30000];
    FILE *fp;
    
    fp = fopen("programa_C.c","a");
    
    //Cabeçalho
    fprintf(fp, "#include<stdio.h>\n");
    fprintf(fp, "int main(){\n");
    fprintf(fp, "char memoria[3000];\n");
    fprintf(fp, " \n");
    fprintf(fp, "\n");


    PrintaMemoria(memoria);

    return 0;
}

