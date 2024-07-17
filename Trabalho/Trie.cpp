#include "Trie.h"
#include "Lista.h"
#include <iostream>
#include <sstream>

using namespace std;

Trie::Trie() {
    for (int i = 0; i < 26; i++) {
        filhos[i] = nullptr;
    }
    lista = nullptr; 
}

void Trie::insere(const string& palavra, const string& info, int i, const string& linha) {
    if (i >= palavra.size()) {
        if (lista == nullptr) {
            lista = new ListaEncadeada();
        }
        lista->inserir(info, linha);
        return;
    }

    int id = valor(palavra[i]);
    if (filhos[id] == nullptr) {
        filhos[id] = new Trie();
    }

    filhos[id]->insere(palavra, info, i + 1, linha);
}

bool Trie::pesquisar(const string& palavra, int i) const {
    if (i >= palavra.size()) {
        if (lista != nullptr) {
            lista->imprimir();
            return true;
        }
        return false;
    }

    int id = valor(palavra[i]);
    if (filhos[id] == nullptr) {
        return false;
    }
    else {
        return filhos[id]->pesquisar(palavra, i + 1);
    }
}

bool Trie::buscar(const string& palavra, int i) {
    if (i >= palavra.size()) {
        if (lista != nullptr) {
            cout << "Palavra encontrada: " << palavra << endl;
            lista->imprimir();
            return true;
        }
        return false;
    }

    int id = valor(palavra[i]);
    if (filhos[id] == nullptr) {
        cout << "Palavra não encontrada" << endl;
        return false;
    }
    else {
        return filhos[id]->buscar(palavra, i + 1);
    }
}

bool Trie::palavra(const string& frase) {
    stringstream ss(frase);
    string palavra;
    Trie* atual = this;

    while (ss >> palavra) {
        for (int i = 0; i < palavra.size(); ++i) {
            int id = valor(palavra[i]);

            if (atual->filhos[id] == nullptr) {
                cout << "Frase não encontrada" << endl;
                return false;
            }

            atual = atual->filhos[id];
        }

        if (atual->lista != nullptr) {
            cout << "Palavra encontrada: " << palavra << endl;
            atual->lista->imprimir();
        }
        else {
            cout << "Palavra não encontrada: " << palavra << endl;
            return false;
        }

        atual = this;
    }

    return true;
}
