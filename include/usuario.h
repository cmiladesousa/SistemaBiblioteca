#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <fstream>
#include <vector>
#include "historico.h"
using namespace std;

class usuario{
    private:
        int id;
        string nome;
        string cpf;
        string endereco; 
        string email;
        string telefone; 
        char sexo;
        string data_nascimento;
        std::vector<historico> hist;
        public:
        usuario();
        usuario(int id, string nome, string cpf, string endereco, string email, string telefone, char sexo, string data_nas);
        int getId() const;
        string getNome() const;
        string getCPF() const;
        string getEndereco() const;
        string getEmail() const;
        string getTelefone() const;
        char getSexo() const;
        string getData_nasc() const;
        vector<historico> getHistorico();
        historico getHistoricoById(int id);
        void printDadosUsuario();
        void adicionarHistorico(historico h);
        void salvarUsuario(ofstream& arquivo);
};

#endif