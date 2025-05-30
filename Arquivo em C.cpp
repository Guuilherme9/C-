#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USUARIOS 10
#define MAX_ALUNOS 100

// estrutura de Login
typedef struct {
    char usuario[10];
    int senha;
} Login;

// estrutura do Aluno
typedef struct {
    int rgm;
    float nota1;
    float nota2;
    float recuperacao;
    float soma;
    bool aprovado;
} Aluno;

Login usuarios[MAX_USUARIOS];
int totalUsuarios = 0;
Aluno alunos[MAX_ALUNOS];
int totalAlunos = 0;

// funções
void cadastrarUsuario() {
    if (totalUsuarios >= MAX_USUARIOS) {
        printf("Limite de usuários atingido.\n");
        return;
    }
    printf("\n--- Cadastro de Usuário ---\n");
    printf("Usuário (máx 9 letras): ");
    scanf("%s", usuarios[totalUsuarios].usuario);
    printf("Senha (somente números): ");
    scanf("%d", &usuarios[totalUsuarios].senha);
    totalUsuarios++;
    printf("Usuário cadastrado com sucesso!\n");
}

bool login() {
    char nome[10];
    int senha;
    printf("\n--- Login ---\n");
    printf("Usuário: ");
    scanf("%s", nome);
    printf("Senha: ");
    scanf("%d", &senha);

    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(nome, usuarios[i].usuario) == 0 && senha == usuarios[i].senha) {
            printf("Login bem-sucedido!\n");
            return true;
        }
    }
    printf("Usuário ou senha inválidos!\n");
    return false;
}

void cadastrarAluno() {
    if (totalAlunos >= MAX_ALUNOS) {
        printf("Limite de alunos atingido.\n");
        return;
    }

    printf("\n--- Cadastro de Aluno ---\n");
    printf("RGM: ");
    scanf("%d", &alunos[totalAlunos].rgm);

    do {
        printf("Nota 1 (0 a 5): ");
        scanf("%f", &alunos[totalAlunos].nota1);
    } while (alunos[totalAlunos].nota1 < 0 || alunos[totalAlunos].nota1 > 5);

    do {
        printf("Nota 2 (0 a 5): ");
        scanf("%f", &alunos[totalAlunos].nota2);
    } while (alunos[totalAlunos].nota2 < 0 || alunos[totalAlunos].nota2 > 5);

    alunos[totalAlunos].soma = alunos[totalAlunos].nota1 + alunos[totalAlunos].nota2;

    if (alunos[totalAlunos].soma >= 6) {
        alunos[totalAlunos].aprovado = true;
    } else {
        do {
            printf("Nota da recuperação (0 a 5): ");
            scanf("%f", &alunos[totalAlunos].recuperacao);
        } while (alunos[totalAlunos].recuperacao < 0 || alunos[totalAlunos].recuperacao > 5);

        // substitui a nota menor
        if (alunos[totalAlunos].recuperacao > alunos[totalAlunos].nota1 ||
            alunos[totalAlunos].recuperacao > alunos[totalAlunos].nota2) {
            if (alunos[totalAlunos].nota1 < alunos[totalAlunos].nota2) {
                alunos[totalAlunos].nota1 = alunos[totalAlunos].recuperacao;
            } else {
                alunos[totalAlunos].nota2 = alunos[totalAlunos].recuperacao;
            }
        }

        alunos[totalAlunos].soma = alunos[totalAlunos].nota1 + alunos[totalAlunos].nota2;
        alunos[totalAlunos].aprovado = alunos[totalAlunos].soma >= 6;
    }

    totalAlunos++;
    printf("Aluno cadastrado com sucesso!\n");
}

void consultarAluno() {
    int rgmBusca;
    printf("\nDigite o RGM do aluno para consulta: ");
    scanf("%d", &rgmBusca);

    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].rgm == rgmBusca) {
            printf("RGM: %d\n", alunos[i].rgm);
            printf("Nota 1: %.2f\n", alunos[i].nota1);
            printf("Nota 2: %.2f\n", alunos[i].nota2);
            printf("Nota Final: %.2f\n", alunos[i].soma);
            printf("Status: %s\n", alunos[i].aprovado ? "Aprovado" : "Reprovado");
            return;
        }
    }

    printf("Aluno não encontrado.\n");
}

int main() {
    int opcao;

    // cadastro de professor/usuario/adm
    printf("--- Sistema de Login e Notas ---\n");
    cadastrarUsuario(); // pode ser repetido quantas vezes o usuario quiser

    // tela de login
    if (!login()) return 0;

    // menu principal
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("[1] Cadastrar Aluno\n");
        printf("[2] Consultar Aluno\n");
        printf("[0] Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarAluno(); break;
            case 2: consultarAluno(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
