#include <iostream>
using namespace std;

int main (void){

int n1, n2, n3, res;

    printf("Digite aqui o primeiro número:");
    scanf("%i", &n1);

    printf("Digite aqui o segundo número:");
    scanf("%i", &n2);

    printf("Digite aqui o terceiro número:");
    scanf("%i", &n3);

    //comparar a e b
    if (n1 > n2) {
    res = n1;
    n1 = n2;
    n2 = res;
    }
    //comparar a e c
    if (n1 > n3) {
    res = n1;
    n1 = n3;
    n3 = res;
    }
    //comparar b e c
    if (n2 > n3) {
    res = n2;
    n2 = n3;
    n3 = res;
    }
    
    printf("Ordem crescente ficou assim: %i, %i, %i\n", n1, n2, n3);

    return 0;
}