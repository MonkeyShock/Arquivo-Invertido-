#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Trie.h"

using namespace std;

class Documentos {
public:
    void lerPDF(const string& caminhoArquivo);
    Trie lerTXT(const string& caminhoArquivo);
private:
    int linha;
    int pag;
    void escreverTXT(const string& inf, string caminhoArquivo);
    void ProcessarTXT(const string& caminhoArquivo);
};
