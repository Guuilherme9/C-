#include <iostream>
using namespace std;

int main(void) {
    int a1, a2, media, notaAf;
    char nomeAluno[15];
    
    printf("Digite o nome do aluno: ");
    scanf("%s", nomeAluno);
    
    printf("Digite sua primeira nota: ");
    scanf("%i", &a1);

    printf("Digite sua segunda nota: ");
    scanf("%i", &a2);

    //calcular média
    media = (a1 + a2);
	
	printf("\nNome do aluno: %s", nomeAluno);
    if (media >= 6) {
        printf("\nAprovado.\n");
        return 0;
        
    } else {
        printf("\nVocê está de AF.\n");
    }
    
    //calcula a af
    printf("\nDigite sua nota da AF: ");
    scanf ("%i", &notaAf);
    
    //vê qual nota é menor entre a1 e a2 e substitui pela nota da AF
    if (a1 < a2) {
        a1 = notaAf;
    } else {
        a2 = notaAf;
    }
    
    media = (a1 + a2);
    
    if (media >= 6) {
        printf("\nAprovado na AF.\nNota final: %i\n", media);
    } else {
        printf("\nReprovado na AF.\nNota final: %i\n", media);
    }

    return 0;
}
