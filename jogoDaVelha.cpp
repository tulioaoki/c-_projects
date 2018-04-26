/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   jogoDaVelha.cpp
 * Author: tulioaoki
 * 
 * Created on April 26, 2018, 2:17 PM
 */
#include <iostream>
#include <stdio.h>
#include <cmath>       
#include <string>
#include "jogoDaVelha.h"
#include <cstdlib>
#include <ctime>
using namespace std;

jogoDaVelha::jogoDaVelha() {
}

jogoDaVelha::jogoDaVelha(const jogoDaVelha& orig) {
}

jogoDaVelha::~jogoDaVelha() {
}

void jogoDaVelha::zerarJogo(int JOGO[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            JOGO[i][j] = 0;
        }
    }
}

int jogoDaVelha::// <editor-fold defaultstate="collapsed" desc="comment">
verificar(int JOGO[3][3])// </editor-fold>
{
    int soma = 0;
    int L1 = (JOGO[0][0] + JOGO[0][1] + JOGO[0][2]);
    int L2 = (JOGO[1][0] + JOGO[1][1] + JOGO[1][2]);
    int L3 = (JOGO[2][0] + JOGO[2][1] + JOGO[2][2]);
    int C1 = (JOGO[0][0] + JOGO[1][0] + JOGO[2][0]);
    int C2 = (JOGO[0][1] + JOGO[1][1] + JOGO[2][1]);
    int C3 = (JOGO[0][2] + JOGO[1][2] + JOGO[2][2]);
    int D1 = (JOGO[0][0] + JOGO[1][1] + JOGO[2][2]);
    int D2 = (JOGO[0][2] + JOGO[1][1] + JOGO[2][0]);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            soma = soma + JOGO[i][j];
        }
    }
    if (D1 == 12 || D2 == 12 || L1 == 12 || L2 == 12 || L3 == 12 || C1 == 12 || C2 == 12 || C3 == 12) {
        return 1;
    } else if (D1 == 15 || D2 == 15 || L1 == 15 || L2 == 15 || L3 == 15 || C1 == 15 || C2 == 15 || C3 == 15) {
        return 2;
    } else if (soma >= 40) { // empate (o mínimo valor possível da soma de todos os espaços TODOS PREENCHIDOS é 40)
        return 3;
    }
    soma = 0;
    return 0;
}

void jogoDaVelha::exibeJogo(int JOGO[3][3]) {
    cout << endl;
    for (int i = 0; i <3; i++) {
        for (int j = 0; j < 3; j++) {
            if (JOGO[i][j] == 4) {
                cout << ("X");
            } else if (JOGO[i][j] == 5) {
                cout << ("O");
            } else {
                if (i < 2) {
                    cout << ("_");
                } else {
                    cout << (" ");
                }
            }
            if (j < 2) {
                cout << ("|");
            }
        }
        cout << endl;
    }
    cout << endl;
}

int jogoDaVelha::menu() {
    int opcao = 0;
    while (opcao < 1 || opcao > 2) {
        cout << ("") << endl;
        cout << ("1 - Jogar") << endl;
        cout << ("2 - Sair") << endl;
        cout << ("Digite sua opção: ") << endl;
        cin >> opcao;
        cout << ("") << endl;
    }
    return opcao;
}

int jogoDaVelha::escolherModo() {
    int opcao = 0;
    while (opcao < 1 || opcao > 2) {
        cout << ("1 - Um Jogador") << endl;
        cout << ("2 - Dois Jogadores") << endl;
        cout << ("Digite sua opção: ") << endl;
        cin >> opcao;
        cout << ("") << endl;
    }
    return opcao;
}


void jogoDaVelha::preencherDificil(int JOGO[][3]) {
    int L1 = (JOGO[0][0] + JOGO[0][1] + JOGO[0][2]);
    int L2 = (JOGO[1][0] + JOGO[1][1] + JOGO[1][2]);
    int L3 = (JOGO[2][0] + JOGO[2][1] + JOGO[2][2]);
    int C1 = (JOGO[0][0] + JOGO[1][0] + JOGO[2][0]);
    int C2 = (JOGO[0][1] + JOGO[1][1] + JOGO[2][1]);
    int C3 = (JOGO[0][2] + JOGO[1][2] + JOGO[2][2]);
    int D1 = (JOGO[0][0] + JOGO[1][1] + JOGO[2][2]);
    int D2 = (JOGO[0][2] + JOGO[1][1] + JOGO[2][0]);
    if (D1 == 10) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (JOGO[i][i] == 0) {
                    JOGO[i][i] = 5;
                }
            }
        }
    } else if (D2 == 10) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (JOGO[0][2] == 0) {
                    JOGO[0][2] = 5;
                } else if (JOGO[1][1] == 0) {
                    JOGO[1][1] = 5;
                } else if (JOGO[2][0] == 0) {
                    JOGO[2][0] = 5;
                }
            }
        }
    } else if (C1 == 10) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (JOGO[i][0] == 0) {
                    JOGO[i][0] = 5;
                }
            }
        }
    } else if (C2 == 10) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (JOGO[i][1] == 0) {
                    JOGO[i][1] = 5;
                }
            }
        }
    } else if (C3 == 10) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (JOGO[i][2] == 0) {
                    JOGO[i][2] = 5;
                }
            }
        }
    } else if (L1 == 10) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (JOGO[0][j] == 0) {
                    JOGO[0][j] = 5;
                }
            }
        }
    } else if (L2 == 10) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (JOGO[1][j] == 0) {
                    JOGO[1][j] = 5;
                }
            }
        }
    } else if (L3 == 10) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (JOGO[2][j] == 0) {
                    JOGO[2][j] = 5;
                }
            }
        }
    } else {
        preencher("facil", JOGO);
    }
}

void jogoDaVelha::preencher(string tipo, int JOGO [][3]) {
    string jogador = tipo;
    if (tipo == "facil") {
        int L = rand()%3;
        int C = rand()%3;
        cout << L << " "<<C;
        if (JOGO[L][C] == 0) {
            JOGO[L][C] = 5;
        } else {
            preencher("facil", JOGO);
        }
    } else if (tipo == "J1") {
        int L, C;
        do {
            cout << ("Informe a linha: ") << endl;
            cin >> L;
            L--;
            cout << ("Informe a coluna: ") << endl;
            cin >> C;
            C--;
            if (L < 0 || L > 2 || C < 0 || L > 2) {
                cout << ("Informe posições válidas") << endl;
            }
        } while (L < 0 || L > 2 || C < 0 || L > 2);
        if (JOGO[L][C] == 0) {
            JOGO[L][C] = 4;
        } else {
            cout << ("Posição já preenchida, insira outra.") << endl;
            preencher("J1", JOGO);
        }
    } else if (tipo == "J2") {
        int L, C;
        do {
            cout << ("Informe a linha: ") << endl;
            cin >> L;
            L--;
            cout << ("Informe a coluna: ") << endl;
            cin >> C;
            C--;
            if (L < 0 || L > 2 || C < 0 || L > 2) {
                cout << ("Informe posições válidas") << endl;
            }
        } while (L < 0 || L > 2 || C < 0 || L > 2);
        if (JOGO[L][C] == 0) {
            JOGO[L][C] = 5;
        } else {
            cout << ("Posição já preenchida, insira outra.") << endl;
            preencher("J2", JOGO);
        }
    } else {
        preencherDificil(JOGO);
    }
}

void jogoDaVelha::jogaFacil(string nome, int JOGO[][3]) {
    srand(time(0));
    const int inicia = (rand() % 2);
    if (inicia == 0) {
        cout << ("Sorteando quem vai começar... " + nome + " começa.") << endl;
    } else {
        cout << ("Sorteando quem vai começar... o computador começa.") << endl;
    }
    while (verificar(JOGO) == 0) {
        if (inicia == 0) {
            exibeJogo(JOGO);
            cout << ("É a vez de " + nome + " jogar !") << endl;
            preencher("J1", JOGO);
            exibeJogo(JOGO);
            if (verificar(JOGO) == 0) {
                preencher("facil", JOGO);
                cout << ("O computador jogou : ") << endl;
            }
        } else {
            cout << ("O computador jogou : ") << endl;
            preencher("facil", JOGO);
            exibeJogo(JOGO);
            if (verificar(JOGO) == 0) {
                cout << ("É a vez de " + nome + " jogar !") << endl;
                preencher("J1", JOGO);
            }
        }
    }
    if (verificar(JOGO) == 1) {
        cout << (nome + " VENCEU\n") << endl;
    } else if (verificar(JOGO) == 2) {
        cout << ("PC VENCEU\n") << endl;
    } else if (verificar(JOGO) == 3) {
        cout << ("EMPATOU\n") << endl;
    }
}

void jogoDaVelha::jogaDificil(string nome, int JOGO[][3]) {
    srand(time(0));
    int X = rand() % 2;
    const int inicia = X;
    if (inicia == 0) {
        cout << ("Sorteando quem vai começar... " + nome + " começa.") << endl;
    } else {
        cout << ("Sorteando quem vai começar... o computador começa.") << endl;
    }
    while (verificar(JOGO) == 0) {
        if (inicia == 0) {
            exibeJogo(JOGO);
            cout << ("É a vez de " + nome + " jogar !") << endl;
            preencher("J1", JOGO);
            exibeJogo(JOGO);
            if (verificar(JOGO) == 0) {
                preencher("dificil", JOGO);
                cout << ("O computador jogou : ") << endl;
            }
            exibeJogo(JOGO);
        } else {
            cout << ("O computador jogou : ") << endl;
            preencher("dificil", JOGO);
            exibeJogo(JOGO);
            if (verificar(JOGO) == 0) {
                cout << ("É a vez de " + nome + " jogar !") << endl;
                preencher("J1", JOGO);
            }
        }
    }
    if (verificar(JOGO) == 1) {
        cout << (nome + " VENCEU\n") << endl;
    } else if (verificar(JOGO) == 2) {
        cout << ("PC VENCEU\n") << endl;
    } else if (verificar(JOGO) == 3) {
        cout << ("EMPATOU\n") << endl;
    }
}

void jogoDaVelha::umJogador() {
    cout << ("Informe o nome do jogador humano: ") << endl;
    string nome;
    cin >> nome;
    cout << endl;
    int jogo[3][3];
    zerarJogo(jogo);
    int dificuldade = 0;
    do {
        cout << ("") << endl;
        cout << ("NIVEL DO JOGO") << endl;
        cout << ("1- Facil") << endl;
        cout << ("2- Difícil") << endl;
        cout << ("Digite sua opção") << endl;
        cout << ("") << endl;
        cin >> dificuldade;
    } while (dificuldade < 1 || dificuldade > 2);
    if (dificuldade == 1) {
        jogaFacil(nome, jogo);
    } else {
        jogaDificil(nome, jogo);
    }
}

void jogoDaVelha::jogarDois(string J1, string J2, string nome1, string nome2, int JOGO[][3]) {
    exibeJogo(JOGO);
    while (verificar(JOGO) == 0) {
        cout << ("É a vez de " + nome1 + " jogar !") << endl;
        preencher(J1, JOGO);
        exibeJogo(JOGO);
        if (verificar(JOGO) == 0) {
            preencher(J2, JOGO);
            cout << ("É a vez de " + nome2 + " jogar !") << endl;
            exibeJogo(JOGO);
        }
    }
}

void jogoDaVelha::doisJogadores() {
    cout << ("Informe o nome do jogador 1: ") << endl;

    string nome1;
    cin >> nome1;
    string J1 = "J1";
    cout << ("Informe o nome do jogador 2: ") << endl;
    string nome2;
    cin >> nome2;
    string J2 = "J2";
    cout << ("\n X- " + nome1 + "\n O- " + nome2 + "\n");
    int JOGO[3][3];
    zerarJogo(JOGO);
    srand(time(0));
    int inicia = (rand() % 2);
    if (inicia == 0) {
        cout << "Sorteando quem vai começar... " + nome1 + " começa." << endl;
        jogarDois(J1, J2, nome1, nome2, JOGO);
    } else {
        cout << ("Sorteando quem vai começar... " + nome2 + " começa.") << endl;
        jogarDois(J1, J2, nome1, nome2, JOGO);
    }
    if (verificar(JOGO) == 1) {
        cout << (nome1 + " venceu!") << endl;
    } else if (verificar(JOGO) == 2) {
        cout << (nome2 + " venceu!") << endl;
    } else if (verificar(JOGO) == 3) {
        cout << ("EMPATOU") << endl;
    }

}

void jogoDaVelha::Start() {
    int opcao = 0;
    do {
        opcao = menu();
        if (opcao == 2) {
            cout << ("Fim de jogo !") << endl;
        } else {
            if (escolherModo() == 1) {
                umJogador();
            } else {
                doisJogadores();
            }
        }
    } while (opcao == 1);
}
