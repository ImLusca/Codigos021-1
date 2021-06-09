//nome: Lucas Pereira Pacheco nºusp: 12543930
// O Enigma
#include<stdio.h>
#include<ctype.h>

int main(){
    int rotor1[26],rotor2[26],rotor3[26];
    int contador1=0, contador2=0, contador3=0;
    char caractere;
    scanf("%*[^\r\n]s");
    for(int i = 0; i< 26;i++){
        scanf(" %i ", &rotor1[i]);
    }
    for(int i = 0; i< 26;i++){
        scanf(" %i ", &rotor2[i]);
    }
    for(int i = 0; i< 26;i++){
        scanf(" %i ", &rotor3[i]);
    }

    scanf("%*[^\r\n]s");

    while(scanf("%c", &caractere) != EOF ){
        // letras minúsculas
        if(caractere >= 97 && caractere <= 122){            
            caractere = caractere - 97;
            caractere = rotor3[rotor2[rotor1[(int)caractere]]];
        }
        if(caractere >= 65 && caractere <= 90){            
            caractere = caractere - 65;
            caractere = rotor3[rotor2[rotor1[(int)caractere]]];            
        }
        printf("%c", caractere);
        //gira o rotor
        char finalRotor;
        finalRotor = rotor1[25];
        rotor1[25] = rotor1[0];
        for(int i =0;i < 24;i++){
            rotor1[i] = rotor1[i+1];
        }
        rotor1[24] = finalRotor;
        contador1++;

        //gira outros rotores
        if(contador1 == 25){
            finalRotor = rotor2[25];
            rotor2[25] = rotor2[0];
            for(int i =0;i < 24;i++){
                rotor2[i] = rotor2[i+1];
            }
            rotor2[24] = finalRotor;
            contador2++;        
        }
        if(contador2 == 25){
            finalRotor = rotor3[25];
            rotor3[25] = rotor3[0];
            for(int i =0;i < 24;i++){
                rotor3[i] = rotor3[i+1];
            }
            rotor3[24] = finalRotor;             
            contador3++;
        }        
    }
    

    return 0;
}