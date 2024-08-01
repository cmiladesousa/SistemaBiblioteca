#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <fstream>
#include <vector>
#include "historico.h"
using namespace std;

class usuario{
    private:
        float id;
        string nome;
        string endereco; 
        string email;
        string telefone; 
        char sexo;
        string data_nascimento;
        std::vector<historico> hist;
        public:
        usuario();
        usuario(float id, string nome, string endereco, string email, string telefone, char sexo, string data_nas);
        float getId() const;
        string getNome() const;
        string getEndereco() const;
        string getEmail() const;
        string getTelefone() const;
        char getSexo() const;
        string getData_nasc() const;
        vector<historico> getHistorico();
        historico getHistoricoById(int id);
        void printDadosUsuario();
        void adicionarHistorico(historico h);
        void attHistorico(string data_devolucao);
        void salvarUsuario(ofstream& arquivo);
};

#endif