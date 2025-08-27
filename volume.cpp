#include <iostream>
using namespace std;

int main (void) {
    
int comprimento, largura, altura, volume;

    printf("Digite aqui o comprimento:");
    scanf("%i", &comprimento);

    printf("Digite aqui a largura:");
    scanf("%i", &largura);

    printf("Digite aqui o comprimento:");
    scanf("%i", &altura);

    volume = comprimento * largura * altura;
    printf("O volume é: %i\n", volume);

    return 0;
}