#include <iostream>
using namespace std;

int main (void){

int a, b, c, d;

    printf("Digite o primeiro número:");
    scanf("%i", &a);

    printf("Digite o segundo número:");
    scanf("%i", &b);

    printf("Digite o terceiro número:");
    scanf("%i", &c);

    printf("Digite o quarto número:");
    scanf("%i", &d);

    if  ( a % 2 == 0 && b % 2 == 0 && c % 2 == 0 && d % 2 == 0)
        printf("É divisivel por 2\n");

    else{
        printf("Não é divisivel por 2\n");
    }


    if  ( a % 3 == 0 && b % 3 == 0 && c % 3 == 0 && d % 3 == 0)
        printf("É divisivel por 3\n");

    else{
        printf("Não é divisivel por 3\n");
    }


    return 0;
}