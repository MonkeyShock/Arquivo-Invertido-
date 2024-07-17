#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Inf {
	string info;
	Inf* proximo;
};

struct Chave {
	string chave;
	Inf* info;
	Chave* proximo;
};

class ListaEncadeada {
public:
	ListaEncadeada();
	~ListaEncadeada();
	void inserir(const string& chave, const string& info);
	string buscar(const string& chave);
	void imprimir();

private:
	Chave* lista;
};
