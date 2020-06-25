#include "BibliotecaTetris.h"

void Tipo_Peca (pPECA peca, int tipo_peca){

    switch(tipo_peca){
         //tipo O
        case 1:
            peca->bloco1.X =Meio_Campo_X;
            peca->bloco1.Y = -2;

            peca->bloco2.X =Meio_Campo_X+1;
            peca->bloco2.Y = -2;

            peca->bloco3.X =Meio_Campo_X;
            peca->bloco3.Y = -1;

            peca->bloco4.X =Meio_Campo_X+1;
            peca->bloco4.Y = -1;

            peca->estado = 1;
            peca->tipo = 1;
            break;

        // tipo I
        case 2:
            peca->bloco1.X =Meio_Campo_X;
            peca->bloco1.Y = -4;

            peca->bloco2.X =Meio_Campo_X;
            peca->bloco2.Y = -3;

            peca->bloco3.X =Meio_Campo_X;
            peca->bloco3.Y = -2;

            peca->bloco4.X =Meio_Campo_X;
            peca->bloco4.Y = -1;

            peca->estado = 1;
            peca->tipo = 2;
            break;

        // tipo S
        case 3:
            peca->bloco1.X =Meio_Campo_X;
            peca->bloco1.Y = -2;

            peca->bloco2.X =Meio_Campo_X+1;
            peca->bloco2.Y = -2;

            peca->bloco3.X =Meio_Campo_X-1;
            peca->bloco3.Y = -1;

            peca->bloco4.X =Meio_Campo_X;
            peca->bloco4.Y = -1;

            peca->estado = 1;
            peca->tipo = 3;
            break;

        // tipo Z
        case 4:
            peca->bloco1.X =Meio_Campo_X-1;
            peca->bloco1.Y = -2;

            peca->bloco2.X =Meio_Campo_X;
            peca->bloco2.Y = -2;

            peca->bloco3.X =Meio_Campo_X;
            peca->bloco3.Y = -1;

            peca->bloco4.X =Meio_Campo_X+1;
            peca->bloco4.Y = -1;

            peca->estado = 1;
            peca->tipo = 4;
            break;

        // tipo L
        case 5:
            peca->bloco1.X =Meio_Campo_X;
            peca->bloco1.Y = -3;

            peca->bloco2.X =Meio_Campo_X;
            peca->bloco2.Y = -2;

            peca->bloco3.X =Meio_Campo_X;
            peca->bloco3.Y = -1;

            peca->bloco4.X =Meio_Campo_X+1;
            peca->bloco4.Y = -1;

            peca->estado = 1;
            peca->tipo = 5;
            break;

        // tipo J
        case 6:
            peca->bloco1.X =Meio_Campo_X;
            peca->bloco1.Y = -3;

            peca->bloco2.X =Meio_Campo_X;
            peca->bloco2.Y = -2;

            peca->bloco3.X =Meio_Campo_X-1;
            peca->bloco3.Y = -1;

            peca->bloco4.X =Meio_Campo_X;
            peca->bloco4.Y = -1;

            peca->estado = 1;
            peca->tipo = 6;
            break;

        // tipo T
        case 7:
            peca->bloco1.X =Meio_Campo_X-1;
            peca->bloco1.Y = -2;

            peca->bloco2.X =Meio_Campo_X;
            peca->bloco2.Y = -2;

            peca->bloco3.X =Meio_Campo_X+1;
            peca->bloco3.Y = -2;

            peca->bloco4.X =Meio_Campo_X;
            peca->bloco4.Y = -1;

            peca->estado = 1;
            peca->tipo = 7;
            break;
    }
}

void Sortear_Modo_Peca(pPECA peca){
    int n;

    n = rand() % 3 + 1;
    peca->modo = n;
}

int Sortear_Tipo_Peca(pPECA peca){
    int n;

    n = rand() % 7 + 1;
    peca->tipo = n;

    return n;
}


