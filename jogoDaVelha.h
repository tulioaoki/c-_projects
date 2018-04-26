/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   jogoDaVelha.h
 * Author: tulioaoki
 *
 * Created on April 26, 2018, 2:17 PM
 */
#include <iostream>
#include <stdio.h>
#include <cmath>       
#include <string>
#ifndef JOGODAVELHA_H
#define JOGODAVELHA_H

using namespace std;

class jogoDaVelha {
public:
    void Start();    
    jogoDaVelha();
    jogoDaVelha(const jogoDaVelha& orig);
    virtual ~jogoDaVelha();
private:
    string J1,J2,nome1,nome2;
    int JOGO [3][3];
    void zerarJogo(int JOGO[][3]);
    void exibeJogo(int JOGO[][3]);
    void preencherDificil(int JOGO[][3]);
    void preencher(string tipo, int JOGO[][3]);
    void umJogador();
    void doisJogadores();
    int escolherModo();
    int menu();
    void zerarJogo();
    int verificar(int JOGO[][3]);
    void jogaFacil(string nome, int JOGO[][3]);
    void jogaDificil(string nome, int JOGO[][3]);
    void jogarDois(string J1, string J2, string nome1, string nome2, int JOGO[][3]);
};

#endif /* JOGODAVELHA_H */

