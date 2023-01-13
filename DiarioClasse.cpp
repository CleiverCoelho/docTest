#include "DiarioClasse.hpp"
using namespace std;

bool DiarioClasse::determinarAprovacao(double notaSemestre, double notaEspecial, double frequencia) {
    if( notaSemestre < 0 || notaSemestre > 100){
        throw ExcecaoNotaSemestreInvalida();
    }

    if(notaEspecial < 0 || notaEspecial > 100){
        throw ExcecaoNotaEspecialInvalida(); 
    }

    if(frequencia < 0 || frequencia > 1){
        throw ExcecaoFrequenciaInvalida();
    }

    if(notaSemestre < 40 && notaSemestre >= 0){
        return false;
    }

    if(notaSemestre >= 60 && frequencia < 0.75){
        return false;
    }

    if(notaSemestre >= 60 && frequencia >= 0.75){
        return true;
    }
    
    if(40 <= notaSemestre && notaSemestre < 60 && frequencia >= 0.75){
        // enttra na possibilidade de exame especial
        if(notaEspecial >= 60){
            return true;
        }else{
            return false;
        }
    }

    if(40 <= notaSemestre && notaSemestre < 60 && frequencia < 0.75 && notaEspecial > 0){
        throw ExcecaoNotaEspecialInvalida();
    }


    return false;
}