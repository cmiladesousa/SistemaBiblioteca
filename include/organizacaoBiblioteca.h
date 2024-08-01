#ifndef ORGANIZACAOBIBLIOTECA_H
#define ORGANIZACAOBIBLIOTECA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "livro.h"

using namespace std;

class Biblioteca{
private:
    vector<Livro> livros;
    int proximoId;

public:
    Biblioteca():proximoId(1){}

    void adicionarLivro(const string& titulo, const string& autor, const string& categoria, const string& editora, int dataPublicacao, 
    const string& isbn,int qtndDisponivel ,const string& secao){
        Livro novoLivro(proximoId++, titulo, autor, categoria, editora, dataPublicacao, isbn, qtndDisponivel, secao);
        livros.push_back(novoLivro);
        cout<< "Novo livro adicionado!"<<endl;
    }

    void salvarArquivo(const string& Inventario)const{
        ofstream Arquivo(Inventario);
            if(Arquivo.is_open()){
                for(const Livro& livro : livros){
                    livro.salvarArquivo(Arquivo);
                    Arquivo << '\n';
                }
                Arquivo.close();
            }
            else{
                cout<<"Não foi possível realizar essa ação."<<endl;
            }
    }
    void listar()const{
        if (livros.empty()){
            cout<< "Nenhum livro disponivel!"<<endl;
            return;
        }
        for(const Livro& livro : livros){
            livro.livroInformacao();
        }
    }

    void listarporSecao()const{
        if (livros.empty()){
            cout<< "Nenhum livro disponivel!"<<endl;
            return;
        }

        map<string, vector<Livro>> livrosSecao; //ogarnizar os livros por seçao registrada
        for(const auto&livro : livros){
                livrosSecao[livro.getSecao()].push_back(livro);
        }

        for (auto it = livrosSecao.begin(); it != livrosSecao.end(); ++it) {
        const string& secao = it->first;
        const vector<Livro>& livrosnasecao = it->second;
        
        cout<< "Seção: "<< secao<<endl;
            for(const Livro& livro : livrosnasecao){
                livro.livroInformacao();
                }
                cout<<endl;
            }


    }

    void emprestimo(int id){
        int i = id - 1;
        int novaqtd = livros.at(i).getDisponivel() - 1;
        livros.at(i).setDisponivel(novaqtd);
    }

    void devolucao(int id){
        int i = id - 1;
        int novaqtd = livros.at(i).getDisponivel() + 1;
        livros.at(i).setDisponivel(novaqtd);
    }

    string infoT(int id){
        int i = id - 1;
        string titulo = livros.at(i).getTitulo();

        return titulo;
    }

    string infoA(int id){
        int i = id - 1;
        string autor = livros.at(i).getAutor();

        return autor;
    }

    string infoS(int id){
        int i = id - 1;
        string secao = livros.at(i).getSecao();

        return secao;
    }
   bool buscarLivroPorID( int idProcurado, Livro livro) {
        int tam = livros.size();
        int i = idProcurado - 1;
        if(tam > i){
            return true;
        }else{
            return false;
        }
    }
};
#endif

