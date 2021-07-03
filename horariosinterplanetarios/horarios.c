#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long unsigned int numerao;

numerao converteSegundos(numerao *SegundosPlaneta,int equivalenciaSegs){
    numerao numSegundos = *SegundosPlaneta / equivalenciaSegs;
    *SegundosPlaneta -= numSegundos * equivalenciaSegs;
    return numSegundos;
}

int main(){
    numerao SegundosPlaneta;
    long int diaParaSeg;
    char* planeta=malloc(sizeof(char)*10);
    scanf("%Lu",&SegundosPlaneta);
    scanf("%s", planeta);
    printf("%Lu segundos no planeta %s equivalem a:\n", SegundosPlaneta, planeta);


    if(!strcmp(planeta,"Terra")){
        diaParaSeg = 86400;
    }else if(!strcmp(planeta,"Venus")){
        diaParaSeg = 20995200;
    }else if(!strcmp(planeta,"Mercurio")){
        diaParaSeg = 5068800;
    }else{
        diaParaSeg = 35760;
    }

    printf("%Lu dias, ",converteSegundos(&SegundosPlaneta,diaParaSeg));
    printf("%Lu horas, ",converteSegundos(&SegundosPlaneta,3600));
    printf("%Lu minutos e ",converteSegundos(&SegundosPlaneta,60));
    printf("%Lu segundos",SegundosPlaneta);

    free(planeta);

    return 0;
}