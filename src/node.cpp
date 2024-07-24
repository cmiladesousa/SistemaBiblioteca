#include "node.h"

node::node(){
    this->esc = NULL;
    this->dir = NULL;
}

node::node(usuario a){
    this->uso = a;
    this->esc = NULL;
    this->dir = NULL;
}

usuario node::getUsuario(){
    return this->uso;
}

node* node::getDir(){
    return this->dir;
}

node* node::getEsc(){
    return this->esc;
}

void node::setEsc(node *novoNo){
    this->esc = novoNo;
}

void node::setDir(node *novoNo){
    this->dir = novoNo;
}

void node::setUsuario(usuario novoUso){
    this->uso = novoUso;
}

void node::ajustaHistorico(historico h){
    this->uso.adicionarHistorico(h);
}