#ifndef NODE_H
#define NODE_H

#include "usuario.h"

class node{
    private:
        usuario uso;
        node *esc, *dir;

    public:
        node();
        node(usuario a);
        usuario getUsuario();
        node* getEsc();
        node* getDir();
        void setEsc(node *novoNo);
        void setDir(node *novoNo);
        void setUsuario(usuario novoUso);
        void ajustaHistorico(historico h);
};

#endif