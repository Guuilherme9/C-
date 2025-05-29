#include <iostream>
#include <cstring>

using namespace std;

#define MAX_USUARIOS 10
#define MAX_ALUNOS 100

// Structs
struct Login {
    char usuario[10];
    int senha;
};

struct Aluno {
    int rgm;
    float nota1;
    float nota2;
    float recuperacao;
    float soma;
    bool aprovado;
};

// Globais
Login usuarios[MAX_USUARIOS];
int totalUsuarios = 0;
Aluno alunos[MAX_ALUNOS];
int totalAlunos = 0;

// Funções
void cadastrarUsuario() {
    if (totalUsuarios >= MAX_USUARIOS) {
        cout << "Limite de usuários atingido.\n";
        return;
    }
    cout << "\n--- Cadastro de Usuário ---\n";
    cout << "Usuário (máx 9 letras): ";
    cin >> usuarios[totalUsuarios].usuario;
    cout << "Senha (somente números): ";
    cin >> usuarios[totalUsuarios].senha;
    totalUsuarios++;
    cout << "Usuário cadastrado com sucesso!\n";
}

bool login() {
    char nome[10];
    int senha;
    cout << "\n--- Login ---\n";
    cout << "Usuário: ";
    cin >> nome;
    cout << "Senha: ";
    cin >> senha;

    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(nome, usuarios[i].usuario) == 0 && senha == usuarios[i].senha) {
            cout << "Login bem-sucedido!\n";
            return true;
        }
    }

    cout << "Usuário ou senha inválidos!\n";
    return false;
}

void cadastrarAluno() {
    if (totalAlunos >= MAX_ALUNOS) {
        cout << "Limite de alunos atingido.\n";
        return;
    }

    cout << "\n--- Cadastro de Aluno ---\n";
    cout << "RGM: ";
    cin >> alunos[totalAlunos].rgm;

    do {
        cout << "Nota 1 (0 a 5): ";
        cin >> alunos[totalAlunos].nota1;
    } while (alunos[totalAlunos].nota1 < 0 || alunos[totalAlunos].nota1 > 5);

    do {
        cout << "Nota 2 (0 a 5): ";
        cin >> alunos[totalAlunos].nota2;
    } while (alunos[totalAlunos].nota2 < 0 || alunos[totalAlunos].nota2 > 5);

    alunos[totalAlunos].soma = alunos[totalAlunos].nota1 + alunos[totalAlunos].nota2;

    if (alunos[totalAlunos].soma >= 6) {
        alunos[totalAlunos].aprovado = true;
    } else {
        do {
            cout << "Nota da recuperação (0 a 5): ";
            cin >> alunos[totalAlunos].recuperacao;
        } while (alunos[totalAlunos].recuperacao < 0 || alunos[totalAlunos].recuperacao > 5);

        // Substituir a menor nota
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
    cout << "Aluno cadastrado com sucesso!\n";
}

void consultarAluno() {
    int rgmBusca;
    cout << "\nDigite o RGM do aluno para consulta: ";
    cin >> rgmBusca;

    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].rgm == rgmBusca) {
            cout << "RGM: " << alunos[i].rgm << "\n";
            cout << "Nota 1: " << alunos[i].nota1 << "\n";
            cout << "Nota 2: " << alunos[i].nota2 << "\n";
            cout << "Nota Final: " << alunos[i].soma << "\n";
            cout << "Status: " << (alunos[i].aprovado ? "Aprovado" : "Reprovado") << "\n";
            return;
        }
    }

    cout << "Aluno não encontrado.\n";
}

int main() {
    int opcao;

    // Cadastro inicial de usuários
    cout << "--- Sistema de Login e Notas ---\n";
    cadastrarUsuario(); // Pode ser repetido depois se quiser mais usuários

    // Tela de login
    if (!login()) return 0;

    // Menu principal
    do {
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "[1] Cadastrar Aluno\n";
        cout << "[2] Consultar Aluno\n";
        cout << "[0] Sair\n";
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrarAluno(); break;
            case 2: consultarAluno(); break;
            case 0: cout << "Saindo...\n"; break;
            default: cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

    return 0;
}
