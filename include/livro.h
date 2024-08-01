#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Livro{
    private:
        int id;
        string titulo;
        string autor;
        string categoria;
        string editora;
        int dataPublicacao;
        string isbn;
        int qtndDisponivel;
        string secao;

        public:
        Livro(){};

        Livro(int id, const string& titulo, const string& autor, const string& categoria, const string& editora, 
        int dataPublicacao, const string& isbn, int qtndDisponivel, const string& secao)
        : id(id), titulo(titulo), autor(autor), categoria(categoria), editora(editora), 
        dataPublicacao(dataPublicacao), isbn(isbn), qtndDisponivel(qtndDisponivel), secao(secao){}

        int getId() const{return id;}
        string getTitulo() const{return this->titulo; cout}
        string getAutor() const{return this->autor; cout}
        string getCategoria() const{return categoria;}
        string getEditora() const{return editora;}
        int getPublicacao() const{return dataPublicacao;}
        string getISBN() const{return isbn;}
        int getDisponivel() const{return this->qtndDisponivel;}
        string getSecao() const{return this->secao;}

        void setDisponivel(int qtndDisponivel) {
            this->qtndDisponivel = qtndDisponivel;
        }


        void salvarArquivo(ofstream& Inventario) const {
        Inventario << "ID: " << id << endl;
        Inventario << "Título: " << titulo << endl;
        Inventario << "Autor: " << autor << endl;
        Inventario << "Categoria: " << categoria << endl;
        Inventario << "Editora: " << editora << endl;
        Inventario << "Ano de Publicação: " << dataPublicacao << endl;
        Inventario << "ISBN: " << isbn << endl;
        Inventario << "Quantidade Disponível: " << qtndDisponivel << endl;
        Inventario << "Seção: " << secao << endl;
    }

        void livroInformacao() const{
            cout<< "Id: " << id << endl;
            cout<< "Título: " << titulo << endl;
            cout<< "Autor: " << autor << endl;
            cout<< "Categoria: " << categoria << endl;
            cout<< "Editora: " << editora << endl;
            cout<< "Ano de Publicação: " << dataPublicacao << endl;
            cout<< "ISBN: " << isbn << endl;
            cout<< "Disponivel no acervo: " << qtndDisponivel << endl;
            cout<< "Seção: " << secao << endl;
        }
    
};


#endif