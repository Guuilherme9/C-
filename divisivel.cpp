#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;

    printf("Digite o primeiro número: ");
    scanf("%i", &a);

    printf("Digite o segundo número: ");
    scanf("%i", &b);

    printf("Digite o terceiro número: ");
    scanf("%i", &c);

    printf("Digite o quarto número: ");
    scanf("%i", &d);

    int numeros[] = {a, b, c, d};

    for (int i = 0; i < 4; i++) {
        printf("o Número %d:\n", numeros[i]);

        if (numeros[i] % 2 == 0)
            printf("É divisível por 2\n");
        else
            printf("Não é divisível por 2\n");

        if (numeros[i] % 3 == 0)
            printf("É divisível por 3\n");
        else
            printf("Não é divisível por 3\n");
    }

    return 0;
}
