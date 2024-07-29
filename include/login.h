#ifndef LOGIN_H
#define LOGIN_H

#include "usuario.h"

class login{
    private:
    string usu;
    string senha;
    public:
    login();
    login(string usu, string senha);
    string getUsu();
    string getSenha();
    bool autenticar(string usu, string senha);
    
};
#endif