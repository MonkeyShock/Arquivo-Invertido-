#pragma once
#include <string>
#include "Lista.h"

using namespace std;

class Trie {
public:
    Trie();
    bool buscar(const string& palavra, int i = 0);
    void insere(const string& palavra, const string& info, int i = 0, const string& linha = "");
    bool pesquisar(const string& palavra, int i = 0) const;
    bool palavra(const string& frase);

private:
    int valor(char c) const { return c - 'a'; }
    Trie* filhos[26];
    ListaEncadeada* lista = new ListaEncadeada();
};
