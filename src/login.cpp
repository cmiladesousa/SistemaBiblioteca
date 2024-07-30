#include "login.h"

login::login(){}

string login::getUsu(){
    this->usu = "admin";
    return this->usu;
}

string login::getSenha(){
    this->senha = "54321";
    return this->senha;
}

bool login::autenticar(string usu, string senha){
    if(getUsu() == usu && getSenha() == senha){
        return true;
    } else{
        return false;
    }
}

