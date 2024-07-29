#include "login.h"

login::login(){}

login::login(string usu, string senha){
    this->usu = usu;
    this->senha = senha;
}

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

