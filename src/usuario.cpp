#include "usuario.h"

usuario::usuario(){};

usuario::usuario(float id, string nome, string endereco, string email, string telefone, char sexo, string data_nas){
    this->id = id;
    this->nome = nome;
    this->endereco = endereco;
    this->email = email;
    this->telefone = telefone;
    this->sexo = sexo;
    this->data_nascimento = data_nas;
}

float usuario::getId() const{
    return this->id;
}

string usuario::getNome() const{
    return this->nome;
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
    cout << "----------------Dados do Usuário----------------" << endl;
    cout << "Nome:" << getNome() << endl;
    cout << "E-mail: " << getEmail() << endl;
    cout << "Telefone: " << getTelefone() << endl;
    cout << "Endereço: " << getEndereco() << endl;
    cout << "CPF: " << getId() << endl;
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

void usuario::attHistorico(string data_devolucao){
    hist.back().registrarDevolucao(data_devolucao);
}

void usuario::salvarUsuario(ofstream& arquivo){
    arquivo << "----------------Dados do Usuário----------------" << endl;
    arquivo << "Nome:" << nome << endl;
    arquivo << "E-mail:" << email << endl;
    arquivo << "Telefone:" << telefone << endl;
    arquivo << "Endereço:" << endereco << endl;
    arquivo << "CPF:" << id << endl;
    arquivo << "Sexo:" << sexo<< endl;
    arquivo << "Data Nascimento: " << data_nascimento << endl;
    arquivo << "Empréstimos Registrados: " << hist.size() << endl;
     if (hist.size() > 0){
        for (int i = 0; i < hist.size(); i++){
            arquivo << "---------------------------" << endl;
            arquivo << "Empréstimo " << i + 1 << endl;
            arquivo << "Titulo: " << hist[i].getTitulo() << endl;
            arquivo << "Autor: " << hist[i].getAutor() << endl;
            arquivo << "localizacao: " << hist[i].getLocalizacao() << endl;
            arquivo << "Data de Emprestimo: " << hist[i].getDataEmprestimo() << endl;
            arquivo << "Prazo de devolução: " << hist[i].getPrazo() << endl;
            if(hist[i].getDataDevolucao().empty()){
                arquivo << "Data de Devolução: --/--/----" << endl;
            } else{
                arquivo << "Data de Devolução: " << hist[i].getDataDevolucao() << endl;
            }
            if(hist[i].getEmAberto()){
                arquivo << "Processo: Em aberto" << endl;
            } else {
                arquivo << "Processo: Encerrado"<< endl;
            }
        }
        arquivo << "---------------------------" << endl;
    } else if (hist.size() == 0){
        arquivo << "---------------------------" << endl;
    }
}