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
};
#endif