#ifndef HISTORICO_H
#define HISTORICO_H

#include <iostream>
#include <iomanip>
using namespace std;

class historico{
    private:
        string data_avaliacao;
        float temperatura; 
        float altura;
        float peso;
        bool amostra_coletada;
        string exame_fisico;
    public:
        historico();
        historico(string data_avaliacao, float peso, float temp, float altura, bool amostra, string exame);
        string getDataAvaliacao();
        float getTemperatura();
        float getAltura();
        float getPeso();
        bool getAmostra();
        string getExame();
        void imprimirHistorico();
};

#endif