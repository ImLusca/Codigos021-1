// #include<stdio.h>

// //(+ (/ 1 2) (* (+ (- 1 (* 1 2) ) 1 ) (/ 1 2)) )

// int CalculaExpressao(){
//     char operacao, tempNumero;
//     int numerosOperacao[2];

//     operacao = getchar();

//     for(int i =0;i< 2; i++){

//         while( (tempNumero = getchar() ) == ' ');


//         if((tempNumero < 58 && tempNumero > 47) || tempNumero == 45){
//             ungetc(tempNumero,stdin);
//             scanf("%i", &numerosOperacao[i]);
//         }else if(tempNumero == 40){
//             numerosOperacao[i] = CalculaExpressao();
//         }
//     }

//     //Descartando ')'
//     getchar();

//     switch (operacao)
//     {
//         case'+': return numerosOperacao[0] + numerosOperacao[1];
//         break;
//         case'-': return numerosOperacao[0] - numerosOperacao[1];
//         break;
//         case'*': return numerosOperacao[0] * numerosOperacao[1];
//         break;
//         case'/': return numerosOperacao[0] / numerosOperacao[1];
//         break;
//         default : return 0; 
//         break;
//     }
    
// }


// int main(){
//     int numerofinal;
//     getchar();

//     numerofinal = CalculaExpressao();
//     printf("%i\n", numerofinal);

//     return 0;
// }

/* Calculadora LISP*/
//Eric Rodrigues das Chagas, NºUSP: 12623971

#include <stdio.h>

/* Observações da Tabela ASCII:

0 em ASCII é: 48	
9 em ASCII é: 57

*/
// (+ (* 2 2) (- 25 10)) \n

/* Calculadora LISP*/
//Eric Rodrigues das Chagas, NºUSP: 12623971

#include <stdio.h>

/* Observações da Tabela ASCII:

0 em ASCII é: 48	
9 em ASCII é: 57

*/

double Calculadora(){
    double num1, num2;
    char operador, Caractere;


    operador=getchar();
    Caractere= getchar(); //retirar espaço

    Caractere= getchar();
    //se o caractere lido for um numero;
    if( Caractere >= 48 && Caractere <= 57  ){
        ungetc(Caractere,stdin);
        scanf(" %lf", &num1);

    }else if (Caractere=='(' ){
        num1= Calculadora();
        
    }
    getchar();// Retirar espaço

    //Leitura do segundo numero
    Caractere=getchar(); 
    if( Caractere >= 48 && Caractere <= 57 ){
        ungetc(Caractere,stdin);
        scanf(" %lf", &num2);
        
    }else if (Caractere=='(' ){
        num2= Calculadora();
        
    }
    getchar(); //Retirar o ')'


    //Calculo e retorno 
    switch (operador){
        case '+': return num1+num2;
        break;

        case '-': return num1-num2;
        break;

        case '*': return num1*num2;
        break;

        case '/': return num1/num2;
        break;

        default : return 0;
        break;
    }    
}

int main (){
    double Resultado;
    char PalavraVer;

    
    while ((PalavraVer=getchar()) != EOF){
        Resultado= Calculadora();

        //Descartando \n
        getchar();
        
        printf("%.6lf\n", Resultado);
    }
    
    return 0;
}