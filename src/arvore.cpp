#include "arvore.h"

arvore::arvore(){
    raiz = NULL;
}
bool arvore::arvoreVazia(){
    if(raiz == NULL){
        return true;
    } else {
        return false;
    }
}

node* arvore::getRaiz(){
    return this->raiz;
}

void arvore::setRaiz(node *novoNo){
    cout << "teste" << endl;
    this->raiz = novoNo;
}
int arvore::getAltura(node *raiz){
    if(raiz == NULL)
        return -1;
    else{
        int alturaE = getAltura(raiz->getEsc());
        int alturaD = getAltura(raiz->getDir());

        if(alturaE > alturaD)
            return(alturaE + 1);
        else return(alturaD + 1);
    }
}
int arvore::getBalancoNo(node *no){
    if(no == NULL)
        return -1;
    return getAltura(no->getEsc()) - getAltura(no->getDir());
}

node* arvore::balancoDireita(node *p){
    node *u = p->getEsc();
    node *A2 = u->getDir();

    u->setDir(p);
    p->setEsc(A2);

    return u;
}

node* arvore::balancoEsquerda(node *p){
    node *z = p->getDir();
    node *A2 = z->getEsc();

    z->setEsc(p);
    p->setDir(A2);
    
    return z;
}

node* arvore::inserirNo(node *raiz, node *novoNo){
    if(raiz == NULL){
        raiz = novoNo;
        return raiz;
    }

    int idRaiz = raiz->getUsuario().getId();
    int idNovo = novoNo->getUsuario().getId();
    if(idNovo < idRaiz){
        raiz->setEsc(inserirNo(raiz->getEsc(), novoNo));
    } else if(idNovo > idRaiz){
        raiz->setDir(inserirNo(raiz->getDir(), novoNo));
    }
    else{
        return raiz;
    }

    int balanco = getBalancoNo(raiz);
    int idDirRaiz;
    int idEscRaiz;
    if(raiz->getDir() != NULL){
       idDirRaiz = raiz->getDir()->getUsuario().getId();
    }
    if(raiz->getEsc() != NULL){
        idEscRaiz = raiz->getEsc()->getUsuario().getId();
    }
    //Esquerda
    
    if(balanco > 1 && idNovo < idEscRaiz){
        return balancoDireita(raiz);
    }

    //Direita
    if(balanco < -1 && idNovo > idDirRaiz){
        return balancoEsquerda(raiz);
    }

    //esquerda-direita
    if(balanco > 1 && idNovo > idEscRaiz){
        raiz->setEsc(balancoEsquerda(raiz->getEsc()));
        return balancoDireita(raiz);
    }
    //direita-esquerda
    if(balanco < -1 && idNovo < idDirRaiz){
        raiz->setDir(balancoDireita(raiz->getDir()));
        return balancoEsquerda(raiz);
    }

    return raiz;
}

node* arvore::buscaNo(node *raiz, int id){
    if(raiz == NULL){
        return raiz;
    }
    int idRaiz = raiz->getUsuario().getId();
    if(idRaiz == id){
        return raiz;
    }
    else if(id < idRaiz){
        return buscaNo(raiz->getEsc(), id);
    }
    else
        return buscaNo(raiz->getDir(), id);
}

node* arvore::valorminimo(node *no){
    node *noAtual = no;
    while (noAtual->getEsc() != NULL)
    {
        noAtual = noAtual->getEsc();
    }
     return noAtual;
}

node* arvore::deletarNo(node *raiz, int id){
    int idRaiz = raiz->getUsuario().getId();
    if(raiz == NULL){
        return NULL;
    } 
    else if(id < idRaiz){
        raiz->setEsc(deletarNo(raiz->getEsc(), id));
    }
    else if(id > idRaiz){
        raiz->setDir(deletarNo(raiz->getDir(), id));
    }
    else{
        if(raiz->getEsc() == NULL){
            node *temp = raiz->getDir();
            delete raiz;
            return temp;
        }
        else if(raiz->getDir() == NULL){
            node *temp = raiz->getEsc();
            delete raiz;
            return temp;
        }
        else{
            node *temp = valorminimo(raiz->getDir());
            
            raiz->setUsuario(temp->getUsuario());
            raiz->setDir(deletarNo(raiz->getDir(), temp->getUsuario().getId()));

        }
    }

    int balanco = getBalancoNo(raiz);

    //Esquerda
    if(balanco == 2 && getBalancoNo(raiz->getEsc()) >= 0)
        return balancoDireita(raiz);
    
    //Dupla Direita
    else if (balanco == 2 && getBalancoNo(raiz->getEsc()) == -1){
        raiz->setEsc(balancoEsquerda(raiz->getEsc()));
        return balancoDireita(raiz);
    }
    //direita
    else if(balanco == -2 && getBalancoNo(raiz->getDir()) <= 0){
        return balancoEsquerda(raiz);
    }
    //dupla esquerda
    else if(balanco == -2 && getBalancoNo(raiz->getDir()) == 1){
        raiz->setDir(balancoDireita(raiz->getDir()));
        return balancoEsquerda(raiz);
    }

    return raiz;
}

/*
void arvore::salvarArvore(node *raiz, string nomeArquivo){
    std::ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        salvarEmOrdem(raiz, arquivo);
        arquivo.close();
        std::cout << "Os animais foram salvos em arquivo com sucesso" << endl;
    } else {
        std::cout << "Erro ao abrir o arquivo" << endl;
    }

}

void arvore::salvarEmOrdem(node *raiz, ofstream& arquivo) {
    if (raiz != nullptr) {
        salvarEmOrdem(raiz->getEsc(), arquivo);
        raiz->getUsuario().salvarUsuario(arquivo);
        salvarEmOrdem(raiz->getDir(), arquivo);
    }
}

void arvore::iniciaArvoreArquivo(node *raiz, string nomeArquivo){
}
*/