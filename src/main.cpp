#include <iostream>
#include "arvore.h"

int main(){
    arvore user;
    node *novoNo = new node();
    int option, valor;

    cout << "Boas vindas ao sistema da bilioteca de Alexandria" << endl;
    do{
        cout << "O que você deseja fazer?" << endl;
        cout << "1. Inserir novo usuário" << endl;
        cout << "2. Buscar usuário" << endl;
        cout << "3. Remover usuário" << endl;
        cout << "4. Adicionar novo empréstimo" << endl;
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
                string nome, cpf, endereco, email, telefone, data_nascimento;
                char sexo;
                cout << "Insira o nome do usuário:" << endl;
                getline(cin, nome);
                cout << "Insira o CPF:" << endl;
                getline(cin, cpf);
                cout << "Insira o endereço:" << endl;
                getline(cin, endereco);
                cout << "Insira o email:" << endl;
                getline(cin, email);
                cout << "Insira o telefone no formato (xx)xxxxx-xxxx:" << endl;
                getline(cin, telefone);
                cout << "Insira o sexo: Homem(H)/ Mulher (M)/ Outro (O):" << endl;
                cin >> sexo;
                cin.ignore();
                cout << "Insira a data de nascimento:" << endl;
                getline(cin, data_nascimento);
                usuario a = usuario(valor, nome, cpf, endereco, email, telefone, sexo, data_nascimento);
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
            cout <<"Insira o CPF do usuário: " << endl;
            cin >> valor;
            cin.ignore();
            novoNo = user.buscaNo(user.getRaiz(), valor);
            if(novoNo != NULL){
                string titulo, autor, localizacao, data_devolucao, data_emprestimo, prazo, processo;
                int id_livro;
                bool em_aberto;
                cout << "Insira o ID do livro:" << endl;
                cin >> id_livro;
                cin.ignore();
                cout << "Insira o título:" << endl;
                getline(cin, titulo);
                cout << "Insira o autor:" << endl;
                getline(cin, autor);
                cout << "Insira a localização:" << endl;
                getline(cin, localizacao);
                cout << "Insira a data de empréstimo:" << endl;
                getline(cin, data_emprestimo);
                cout << "Insira o prazo de devolução:" << endl;
                getline(cin, prazo);
                cout << "Insira a data de devolução(Caso tenha):" <<endl;
                getline(cin, data_devolucao);
                cout << "O processo de empréstimo já foi concluido?" << endl;
                getline(cin, processo);

                if(processo == "S" || processo == "s" || processo == "SIM" || processo == "Sim")
                    em_aberto = true;
                else
                    em_aberto = false;

                historico h = historico(id_livro, titulo, autor, localizacao, data_devolucao, data_emprestimo, prazo, em_aberto);
                novoNo->ajustaHistorico(h);

            } else{
                cout << "Usuário não encontrado" << endl;
            }
            break;
        default:
            break;
        }
    } while (option != 0);

    return 0;
}