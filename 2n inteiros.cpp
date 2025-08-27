#include <iostream>
using namespace std;

int main (void) {

int n1, n2, res;

    printf("Digite aqui o primeiro número:");
    scanf("%d", &n1);

    printf("Digite aqui o segundo número:");
    scanf("%d", &n2);

    res = (n1 - n2) * (n1 - n2);
    printf("O quadrado da diferença é: %d\n", res);


    return 0;
}