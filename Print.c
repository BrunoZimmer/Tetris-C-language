#include "BibliotecaTetris.h"

void Print_Peca(pPECA peca){
    int forma_peca;

    if(peca->modo == 1)
        forma_peca = Peca_Normal;
    if(peca->modo == 2)
        forma_peca = Peca_Explosiva;
    if(peca->modo == 3)
        forma_peca = Peca_Variavel;

    if(peca->bloco1.Y >= 0){
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), peca->bloco1 );
        printf("%c", forma_peca);
    }
    if(peca->bloco2.Y >= 0){
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), peca->bloco2 );
        printf("%c", forma_peca);
    }
    if(peca->bloco3.Y >= 0){
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), peca->bloco3 );
        printf("%c", forma_peca);
    }
    if(peca->bloco4.Y >= 0){
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), peca->bloco4 );
        printf("%c", forma_peca);
    }
}

void Print_Campo_Jogo(pCAMPO campo){
    int i, j;
    system("cls");
    for(i=0; i < Altura_Campo; ++i){
        for(j=0; j < Largura_Campo; j++){
            printf("%c", campo->campo_jogo[i][j]);
        }
        printf("\n");
    }
}

void Limpar_Tela_Jogo(pCAMPO campo){
    int i, j;
    for(i=0; i < Altura_Campo; ++i){
        for(j=0; j < Largura_Campo; j++){
            campo->campo_jogo[i][j] = ' ';
        }
        printf("\n");
    }
    Desenhar_Campo(campo);
}

void Limpar_Peca(pPECA peca){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), peca->bloco1 );
        printf("%c", ' ');
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), peca->bloco2 );
        printf("%c", ' ');
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), peca->bloco3 );
        printf("%c", ' ');
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), peca->bloco4 );
        printf("%c", ' ');
}



