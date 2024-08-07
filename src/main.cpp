#include <iostream>
#include <fstream>
#include "arvore.h"
#include "login.h"
#include "organizacaoBiblioteca.h"
#include "livro.h"
#include "cadastro.h"

int main(int argc, char* argv[]){
    arvore user;
    login entrar;
    Biblioteca biblioteca;
    Livro livro;
    node *novoNo = new node();
    int option, valorl;
    float valor;
    string usu, senha;

    if(argc > 1){
        std::ifstream arquivo(argv[1]);
        if(arquivo.is_open()){
            int qtdHistoricos, qtdUsuarios, id_livro;
            float id;
            string linha, nome, endereco, email, telefone, data_nascimento, titulo, autor, localizacao, data_devolucao, data_emprestimo, prazo;
            char sexo;
            bool em_aberto;
            if(getline(arquivo, linha)){
                qtdUsuarios = stoi(linha);
                for (int i = 0; i < qtdUsuarios; i++){
                    getline(arquivo, linha);
                    id = stof(linha);
                    getline(arquivo, nome);
                    getline(arquivo, endereco);
                    getline(arquivo, email);
                    getline(arquivo, telefone);
                    getline(arquivo, linha);
                    sexo = linha[0];
                    getline(arquivo, data_nascimento);
                    getline(arquivo, linha);
                    qtdHistoricos = stoi(linha);
                    novoNo = user.buscaNo(user.getRaiz(), id);
                    if(novoNo == NULL){
                        usuario a = usuario(id, nome, endereco, email, telefone, sexo, data_nascimento);
                        node *no2 = new node();
                        no2->setUsuario(a);
                        user.setRaiz(user.inserirNo(user.getRaiz(), no2));
                        for(int j = 0; j < qtdHistoricos; j++){
                            getline(arquivo, linha);
                            id_livro = stoi(linha);
                            getline(arquivo, titulo);
                            getline(arquivo, autor);
                            getline(arquivo, localizacao);
                            getline(arquivo, data_devolucao);
                            getline(arquivo, data_emprestimo);
                            getline(arquivo, prazo);
                            getline(arquivo, linha);
                            em_aberto = stoi(linha);
                            historico h = historico(id_livro, titulo, autor, localizacao, data_devolucao, data_emprestimo, prazo, em_aberto);
                            no2->ajustaHistorico(h);
                        }
                    } else{
                        for(int j = 0; j < qtdHistoricos * 8; j++){
                            getline(arquivo, linha);
                        }
                    }
                }
            }
        }
        arquivo.close();
    } else{
        std::cout << "Erro ao abrir o arquivo inicial de usuario" << endl;
    }
    cout << "--------------Biblioteca de Alexandria-----------" << endl;
    cout << "-----------------Login no sistema----------------" << endl;
    cout << "Usuário:" << endl;
    getline(cin, usu);
    cout << "Senha:" << endl;
    getline(cin, senha);
    
    cout << "-------------------------------------------------" << endl;
    if(entrar.autenticar(usu, senha)){
            cout << "Boas vindas ao sistema da bilioteca de Alexandria" << endl;
        do{
            cout << "O que você deseja fazer?" << endl;
            cout << "1. Inserir novo usuário" << endl;
            cout << "2. Buscar usuário" << endl;
            cout << "3. Remover usuário" << endl;
            cout << "4. Adicionar Livro " <<endl;
            cout << "5. Listar Livros " <<endl;
            cout << "6. Listar por Seção" <<endl;
            cout << "7. Adicionar novo empréstimo" << endl;
            cout << "8. Registrar devolução" << endl;
            cout << "9. Salvar usuários em arquivo" <<endl;
            cout << "0. Sair do programa" << endl;

            cin >> option;

            switch (option)
            {
            case 0:
                cout << "Saindo do Sistema..." << endl;
                break;
            case 1:
                cout <<"Insira o CPF do usuário: " << endl;
                cin >> valor;
                cin.ignore();
                novoNo = user.buscaNo(user.getRaiz(), valor);
                if(novoNo != NULL){
                    cout << "Erro! Esse CPF já existe!" << endl;
                } else {
                    string nome, endereco, email, telefone, data_nascimento;
                    char sexo;
                    cout << "Insira o nome do usuário:" << endl;
                    getline(cin, nome);
                    cout << "Insira o endereço:" << endl;
                    getline(cin, endereco);
                    cout << "Insira o email:" << endl;
                    getline(cin, email);
                    cout << "Insira o telefone" << endl;
                    getline(cin, telefone);
                    cout << "Insira o sexo: Homem(M)/ Mulher (F)/ Outro (O):" << endl;
                    cin >> sexo;
                    cin.ignore();
                    cout << "Insira a data de nascimento:" << endl;
                    getline(cin, data_nascimento);
                    usuario a = usuario(valor, nome, endereco, email, telefone, sexo, data_nascimento);
                    node *no2 = new node();
                    no2->setUsuario(a);
                    user.setRaiz(user.inserirNo(user.getRaiz(), no2));
                    cout << "Usuário inserido com sucesso!" << endl;
                }
                break;
            case 2:
                cout <<"Insira o CPF do usuário: " << endl;
                cin >> valor;
                novoNo = user.buscaNo(user.getRaiz(), valor);
                if(novoNo != NULL){
                    novoNo->getUsuario().printDadosUsuario();
                } else{
                    cout << "Usuário não encontrado" << endl;
                }
                break;
            case 3:
                cout <<"Insira o CPF do usuário: " << endl;
                cin >> valor;
                novoNo = user.buscaNo(user.getRaiz(), valor);
                if(novoNo != NULL){
                    user.setRaiz(user.deletarNo(user.getRaiz(), valor));
                    cout << "Usuário removido com sucesso!"<< endl;
                } else {
                    cout << "Usuário não encontrado" << endl;
                }
                cout<<endl;
                break;
            case 4:
                cadastro(biblioteca);
                cout<<"Livro cadastrado com sucesso!" << endl;
                break;
            case 5:
                biblioteca.listar();
                break;
            case 6:
                biblioteca.listarporSecao();
                break;
            case 7:
                cout <<"Insira o CPF do usuário: " << endl;
                cin >> valor;
                cout << "Insira o Id do livro:" << endl;
                cin >> valorl;
                cin.ignore();

                novoNo = user.buscaNo(user.getRaiz(), valor);
                if(novoNo != NULL && biblioteca.buscarLivroPorID( valorl, livro)){
                    string titulo, autor, localizacao, data_devolucao, data_emprestimo, prazo;
                    bool em_aberto;
                    titulo = biblioteca.infoT(valorl);
                    autor = biblioteca.infoA(valorl);
                    localizacao = biblioteca.infoS(valorl);
                    cout << "Insira a data de empréstimo:" << endl;
                    getline(cin, data_emprestimo);
                    cout << "Insira o prazo de devolução:" << endl;
                    getline(cin, prazo);
                    em_aberto = true;

                    biblioteca.emprestimo(valorl);
                    historico h = historico(valorl, titulo, autor, localizacao, data_devolucao, data_emprestimo, prazo, em_aberto);
                    novoNo->ajustaHistorico(h);

                } else{
                    cout << "Usuário não encontrado" << endl;
                }
                break;
            case 8:
                cout <<"Insira o CPF do usuário: " << endl;
                cin >> valor;
                cout << "Insira o Id do livro:" << endl;
                cin >> valorl;
                cin.ignore();
                
                novoNo = user.buscaNo(user.getRaiz(), valor);
                if(novoNo != NULL && biblioteca.buscarLivroPorID(valorl, livro)){
                    string data_devolucao;
                    cout <<"Digite a data de devolução:" << endl;
                    getline(cin, data_devolucao);

                    novoNo->atualizarDevolucao(data_devolucao);
                    biblioteca.devolucao(valorl);
                } else{
                    cout << "Usuário não encontrado" << endl;
                }
                break;
            case 9:
                user.salvarArvore(user.getRaiz(), "../DadosUser.txt");
                break;
            default:
                break;
            }
        } while (option != 0);
    } else{
        std::cout << "Erro! Usuário ou senha estão incorretos." << endl;
    }

    return 0;
}