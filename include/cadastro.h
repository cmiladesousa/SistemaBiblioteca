#ifndef CADASTROLIVRO_H
#define CADASTROLIVRO_H

#include <iostream>

using namespace std;

#include "organizacaoBiblioteca.h"
#include "livro.h"

void cadastro(Biblioteca& biblioteca) {
string titulo, autor, editora, isbn, categoria, secao;
            int dataPublicacao, qtndDisponivel;

            cin.ignore();
            cout<<"Título: ";
            getline(cin, titulo);
            cout<<"Autor(a): ";
            getline(cin, autor);
            cout<<"Categoria: ";
            getline(cin, categoria);
            cout<<"Editora: ";
            getline(cin, editora);
            cout<<"Ano em que foi publicado: ";
            cin>>dataPublicacao;
            cin.ignore();
            cout<<"ISBN: ";
            getline(cin, isbn);
            cout<<"Quantidade disponível: ";
            cin>>qtndDisponivel;
            cin.ignore();
            cout<<"Seção: ";
            getline(cin, secao);

            biblioteca.adicionarLivro(titulo, autor, categoria, editora, dataPublicacao, isbn, qtndDisponivel, secao);
}
#endif