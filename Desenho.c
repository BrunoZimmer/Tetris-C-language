#include "BibliotecaTetris.h"


void Desenhar_Menu_Inicial(pCAMPO campo){
    COORD Novo_Jogo, Continuar, Pontuacoes, fim;
    Novo_Jogo.X = 5;
    Novo_Jogo.Y = 5;
    Continuar.X = 5;
    Continuar.Y = 7;
    Pontuacoes.X = 5;
    Pontuacoes.Y = 9;
    fim.X = Largura_Campo;
    fim.Y = Altura_Campo;
    /*LUGAR DO MENU
    Novo jogo
        x=5
        y=10
    Continuar
        x=7
        y=10
    Pontuacoes
        x=9
        y=10
    */
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Novo_Jogo);
    printf("1. Novo Jogo\n");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Continuar);
    printf("2. Continuar\n");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pontuacoes);
    printf("3. Pontuacoes\n");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), fim);
}

void Desenhar_Game_Over(pCAMPO campo){
    COORD game_over, fim;
    game_over.X = 6;
    game_over.Y = 11;
    fim.X = Largura_Campo;
    fim.Y = Altura_Campo;
    /*lugar onde fica escrito game over
    x=6
    y=11
    */
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), game_over);
    printf("GAME OVER");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), fim);
}

void Desenhar_Jogo_Pausado(){
    COORD pause, inicio;
    inicio.X = 0;
    inicio.Y = 0;
    pause.X = 4;
    pause.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pause);
    printf("JOGO PAUSADO");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), inicio);
}

void Desenhar_Campo(pCAMPO campo){
    int i, j;
    for(i=0; i < Altura_Campo; ++i){
        for(j=0; j < Largura_Campo; j++){
            if(j == 0 || j == (Largura_Campo-1))
                campo->campo_jogo[i][j] = Borda;
            if( i == (Altura_Campo-1))
                campo->campo_jogo[i][j] = Solo;
            if(i == (Altura_Campo-1) &&  j == (Largura_Campo-1))
                campo->campo_jogo[i][j] = 188;// o canto direito inferior
            if( i == (Altura_Campo-1) && j == 0)
                campo->campo_jogo[i][j] = 200;// canto esquerdo inferior
        }
    }
}

