#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;

    printf("Digite o primeiro n�mero: ");
    scanf("%i", &a);

    printf("Digite o segundo n�mero: ");
    scanf("%i", &b);

    printf("Digite o terceiro n�mero: ");
    scanf("%i", &c);

    printf("Digite o quarto n�mero: ");
    scanf("%i", &d);

    int numeros[] = {a, b, c, d};

    for (int i = 0; i < 4; i++) {
        printf("o N�mero %d:\n", numeros[i]);

        if (numeros[i] % 2 == 0)
            printf("� divis�vel por 2\n");
        else
            printf("N�o � divis�vel por 2\n");

        if (numeros[i] % 3 == 0)
            printf("� divis�vel por 3\n");
        else
            printf("N�o � divis�vel por 3\n");
    }

    return 0;
}
