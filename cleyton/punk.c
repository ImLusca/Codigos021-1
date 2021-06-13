// Lucas Pereira Pacheco. nºusp: 12543930
/* Cleyton, o      _    
                  | |   
 _ __  _   _ _ __ | | __
| '_ \| | | | '_ \| |/ /
| |_) | |_| | | | |   < 
| .__/ \__,_|_| |_|_|\_\
| |                     
|_|    
de 2077
*/


#include<stdio.h>
    int fita[513];
    int add1, add2, dest;
void ADD(int indiceOperacao){
    add1 = fita[indiceOperacao + 1];
    add2 = fita[indiceOperacao + 2];
    dest = fita[indiceOperacao + 3];
    fita[dest] = fita[add1] + fita[add2];    
    return;
}
void MUL(int indiceOperacao){
    add1 = fita[indiceOperacao + 1];
    add2 = fita[indiceOperacao + 2];
    dest = fita[indiceOperacao + 3];
    fita[dest] = fita[add1] * fita[add2];
    return;
}
void CLT(int indiceOperacao){
    add1 = fita[indiceOperacao + 1];
    add2 = fita[indiceOperacao + 2];
    dest = fita[indiceOperacao + 3];
    fita[dest] = (fita[add1] < fita[add2]);
    return;
}
void CEQ(int indiceOperacao){
    add1 = fita[indiceOperacao + 1];
    add2 = fita[indiceOperacao + 2];
    dest = fita[indiceOperacao + 3];
    fita[dest] = (fita[add1] == fita[add2]);
    return;
}
int  JMP(int indiceOperacao){
    add1 = fita[indiceOperacao + 1];    
    return fita[add1];
}
int  JEQ(int indiceOperacao){
    add1 = fita[indiceOperacao + 1];
    add2 = fita[indiceOperacao + 2];
    return (fita[add1] != 0)?(fita[add2]):(indiceOperacao + 3);
}
void CPY(int indiceOperacao){
    add1 = fita[indiceOperacao + 1];
    dest = fita[indiceOperacao + 2];
    fita[dest] = fita[add1];
}
void PUT(int indiceOperacao){
    add1 = fita[indiceOperacao + 1];
    printf("%c", fita[add1]);
    return;
}
void PTN(int indiceOperacao){
    add1 = fita[indiceOperacao + 1];
    printf("%i", fita[add1]);
    return;
}


int main(){
    for(int i=0; i<512; i++){        
        scanf("%i", &fita[i]);        
    }
    int indiceOpAtual=0;
    printf("Saida do programa:\n");
    while(fita[indiceOpAtual]!= 0){        
        switch(fita[indiceOpAtual]){
            case 1: ADD(indiceOpAtual);
                indiceOpAtual += 4;
                break;
            case 2: MUL(indiceOpAtual);
                indiceOpAtual += 4;
                break;
            case 3: CLT(indiceOpAtual);
                indiceOpAtual += 4;
                break;
            case 4: CEQ(indiceOpAtual);
                indiceOpAtual += 4;
                break;
            case 5: indiceOpAtual = JMP(indiceOpAtual);
                break;
            case 6: indiceOpAtual = JEQ(indiceOpAtual);
                break;
            case 7: CPY(indiceOpAtual);
                indiceOpAtual += 3;
                break;
            case 8: PUT(indiceOpAtual);
                indiceOpAtual += 2;
                break;
            case 9: PTN(indiceOpAtual);
                indiceOpAtual += 2;
                break;
        }
    }
    printf("\nEstado final da fita:");
    for(int i =0; i<512;i++){
        printf("\n%i", fita[i]);
    }



    return 0;    
}