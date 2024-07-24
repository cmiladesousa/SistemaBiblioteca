#include "usuario.h"

usuario::usuario(){};

usuario::usuario(int id, string nome, string cpf, string endereco, string email, string telefone, char sexo, string data_nas){
    this->id = id;
    this->nome = nome;
    this->cpf = cpf;
    this->endereco = endereco;
    this->email = email;
    this->telefone = telefone;
    this->sexo = sexo;
    this->data_nascimento = data_nas;
}

int usuario::getId() const{
    return this->id;
}

string usuario::getNome() const{
    return this->nome;
}

string usuario::getCPF() const{
    return this->cpf;
}

string usuario::getEndereco() const{
    return this->endereco;
}

string usuario::getEmail() const{
    return this->email;
}

string usuario::getTelefone() const{
    return this->telefone;
}

char usuario::getSexo() const{
    return this->sexo;
}

string usuario::getData_nasc() const{
    return this->data_nascimento;
}

vector<historico> usuario::getHistorico(){
    return this->hist;
}

historico usuario::getHistoricoById(int id){
    return this->hist.at(id);
}

void usuario::adicionarHistorico(historico h){
    hist.push_back(h);
}

void usuario::printDadosUsuario(){
    cout << "Dados do Usuário:" << endl;
    cout << "Id: " << getId() << endl;
    cout << "Nome:" << getNome() << endl;
    cout << "E-mail: " << getEmail() << endl;
    cout << "Telefone: " << getTelefone() << endl;
    cout << "Endereço: " << getEndereco() << endl;
    cout << "CPF: " << getCPF() << endl;
    cout << "Sexo: " << getSexo() << endl;
    if(getData_nasc().empty()){
        cout << "Data de Nascimento: Desconhecida" << endl;
    }
    else{
        cout << "Data de Nascimento: " << getData_nasc() << endl;
    }
    int tam_his = hist.size();
    if(tam_his > 0){
        cout << "Histórico de Empréstimo: " << endl;
        cout << endl;
        for (int i = 0; i < tam_his; i++)
        {
            cout << "Registro "<< i + 1 << endl;
            hist.at(i).imprimirHistorico();

        }
        
    } else{
        cout << "Esse usuário ainda não pegou livro emprestado" << endl;
    }
}

