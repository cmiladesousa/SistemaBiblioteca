#ifndef ARVORE_H
#define ARVORE_H
#include "node.h"
#include <fstream>

class arvore{
    private:
        node *raiz;
    public:
        arvore();
        node* getRaiz();
        void setRaiz(node *novoNo);
        bool arvoreVazia();
        int getAltura(node *raiz);
        int getBalancoNo(node *no);
        node* balancoDireita(node *p);
        node* balancoEsquerda(node *p);
        node* inserirNo(node *raiz, node *novoNo);
        node* buscaNo(node *raiz, int id);
        node* valorminimo(node* no);
        node* deletarNo(node* raiz, int id);
        void salvarArvore(node *raiz, string arquivo);
        void salvarEmOrdem(node *raiz, ofstream& arquivo);
        void iniciaArvoreArquivo(node *raiz, string nomeArquivo);
        
    };

#endif