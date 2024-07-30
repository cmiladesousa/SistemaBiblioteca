#include "historico.h"

historico::historico(){}

historico::historico(int id_livro, string titulo, string autor, string localizacao, string data_devolucao, string data_emprestimo, string prazo, bool em_aberto){
    this->id_livro = id_livro;
    this->titulo = titulo;
    this->autor = autor;
    this->localizacao = localizacao;
    this->data_devolucao = data_devolucao;
    this->data_emprestimo = data_emprestimo;
    this->prazo = prazo;
    this->em_aberto = em_aberto;
}

int historico::getIdLivro(){
    return this->id_livro;
}

string historico::getTitulo(){
    return this->titulo;
}

string historico::getAutor(){
    return this->autor;
}

string historico::getLocalizacao(){
    return this->localizacao;
}

string historico::getDataDevolucao(){
    return this->data_devolucao;
}

string historico::getDataEmprestimo(){
    return this->data_emprestimo;
}

string historico::getPrazo(){
    return this->prazo;
}

bool historico::getEmAberto(){
    return this->em_aberto;
}

void historico::imprimirHistorico(){
    cout << "-------------------------------------------------" << endl;
    cout << "Titulo: " << getTitulo() << endl;
    cout << "Autor: " << getAutor() << endl;
    cout << "localizacao: " << getLocalizacao() << endl;
    cout << "Data de Emprestimo: " << getDataEmprestimo() << endl;
    cout << "Prazo de devolução: " << getPrazo() << endl;
    if(getDataDevolucao().empty()){
        cout << "Data de Devolução: --/--/----" << endl;
    } else{
        cout << "Data de Devolução: " << getDataDevolucao() << endl;
    }
    if(getEmAberto()){
        cout << "Processo: Em aberto" << endl;
    } else {
        cout << "Processo: Encerrado"<< endl;
    }
    cout << endl;
}

void historico::registrarDevolucao(string data_devolucao){
    if(getEmAberto()){
        this->data_devolucao = data_devolucao;
        this->em_aberto = false;
    } else{
        cout << "O livro já foi devolvido" << endl;
    }
}