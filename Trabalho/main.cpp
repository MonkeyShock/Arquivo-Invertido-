#include <iostream>
#include <string>
#include "Trie.h"
#include "Leitor.h"

using namespace std;

void exibirMenu() {
    cout << "Escolha uma opção:\n";
    cout << "1. Busca por palavra\n";
    cout << "2. Busca por frase\n";
    cout << "3. Sair\n";
    cout << "Opção: ";
}

int main() {
    Trie trie;
    string caminhoDiretorio = "C:/Users/ryanp/Downloads/Pdfs/ts.pdf";
    Documentos doc;
    doc.lerPDF(caminhoDiretorio);
    trie = doc.lerTXT(caminhoDiretorio);


    int opcao;
    do {
        exibirMenu();
        cin >> opcao;
        cin.ignore();  

        if (opcao == 1) {
            string palavra;
            cout << "Digite a palavra a ser buscada: ";
            getline(cin, palavra);
            if (!trie.pesquisar(palavra)) {
                cout << "Palavra não encontrada.\n";
            }
            else {
                cout << "Encontrou. \n";
            }
        }
        else if (opcao == 2) {
            string frase;
            cout << "Digite a frase a ser buscada: ";
            getline(cin, frase);
            if (!trie.palavra(frase)) {
                cout << "Palavra não encontrada.\n";
            }
            else {
                trie.palavra(frase);
                cout << "Encontrou a palavra " << frase << " na página ";
            }
        }
    } while (opcao != 3);

    cout << "Saindo...\n";
    return 0;
}
