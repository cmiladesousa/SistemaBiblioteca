#ifndef HISTORICO_H
#define HISTORICO_H

#include <iostream>
#include <iomanip>
using namespace std;

class historico{
    private:
        int id_livro;
        string titulo;
        string autor;
        string localizacao;
        string data_devolucao;
        string data_emprestimo;
        string prazo;
        bool em_aberto;
    public:
        historico();
        historico(int id_livro, string titulo, string autor, string localizacao, string data_devolucao, string data_emprestimo, string prazo, bool em_aberto);
        int getIdLivro();
        string getTitulo();
        string getAutor();
        string getLocalizacao();
        string getDataDevolucao();
        string getDataEmprestimo();
        string getPrazo();
        bool getEmAberto();
        void imprimirHistorico();
        void registrarDevolucao(string data_devolucao);
};

#endif