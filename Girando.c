#include "BibliotecaTetris.h"

void Girar_Peca_Direita(pPECA peca, pCAMPO campo){
    int tipo_peca = peca->tipo;

    switch(tipo_peca){
        // tipo O
        case 1:
            break;
        // tipo I
        // a peca I vai ter como o centro o 2, com os perifericos movendo em volta dele
        case 2:
            if( peca->estado == 1 ){
                if(campo->campo_jogo[(peca->bloco2.X)-1][(peca->bloco2.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)+2][(peca->bloco4.Y)-2] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)-1] == ' ' ){
                    Limpar_Peca(peca);

                    peca->bloco1.X -= 1;
                    peca->bloco1.Y += 1;

                    peca->bloco4.X += 2;
                    peca->bloco4.Y -= 2;

                    peca->bloco3.X += 1;
                    peca->bloco3.Y -= 1;

                    Print_Peca(peca);

                    peca->estado = 2;
                    break;
                }
            }
            if(peca->estado == 2){
                if(campo->campo_jogo[(peca->bloco2.X)+1][(peca->bloco2.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)-2][(peca->bloco4.Y)+2] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)-1][(peca->bloco3.Y)+1] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X += 1;
                    peca->bloco1.Y -= 1;

                    peca->bloco4.X -= 2;
                    peca->bloco4.Y += 2;

                    peca->bloco3.X -= 1;
                    peca->bloco3.Y += 1;

                    peca->estado = 1;
                    break;
                }
            }

            break;

        // tipo S
        // a peca de tipo s vai ter como centro o bloco 1
        case 3:
            if(peca->estado == 1){
                if(campo->campo_jogo[(peca->bloco2.X)-1][(peca->bloco2.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)+2][(peca->bloco3.Y)] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco2.X -= 1;
                    peca->bloco2.Y -= 1;

                    peca->bloco4.X += 1;
                    peca->bloco4.Y -= 1;

                    peca->bloco3.X += 2;

                    peca->estado = 2;
                    break;
                }
            }
            if(peca->estado == 2){
                if(campo->campo_jogo[(peca->bloco2.X)+1][(peca->bloco2.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)-1][(peca->bloco4.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)-2][(peca->bloco3.Y)] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco2.X += 1;
                    peca->bloco2.Y += 1;

                    peca->bloco4.X -= 1;
                    peca->bloco4.Y += 1;

                    peca->bloco3.X -= 2;

                    peca->estado = 1;
                    break;
                }
            }

            break;
        // tipo Z
        //o tipo Z vai adotar como centro o bloco2
        case 4:
            if(peca->estado == 1){
                if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)-1][(peca->bloco3.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)-2][(peca->bloco4.Y)] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X += 1;
                    peca->bloco1.Y -= 1;

                    peca->bloco3.X -= 1;
                    peca->bloco3.Y -= 1;

                    peca->bloco4.X -= 2;

                    peca->estado = 2;
                    Print_Peca(peca);
                    break;
                }
            }
            if(peca->estado == 2){
                if(campo->campo_jogo[(peca->bloco1.X)-1][(peca->bloco1.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)+2][(peca->bloco4.Y)] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X -= 1;
                    peca->bloco1.Y += 1;

                    peca->bloco3.X += 1;
                    peca->bloco3.Y += 1;

                    peca->bloco4.X += 2;

                    peca->estado = 1;
                    break;
                }
            }

            break;
        // tipo L
        //essa peca vai ter como centro o bloco 2
        case 5:
            if(peca->estado == 1){
                if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)-1][(peca->bloco3.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)-2][(peca->bloco4.Y)] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X += 1;
                    peca->bloco1.Y += 1;

                    peca->bloco3.X -= 1;
                    peca->bloco3.Y -= 1;

                    peca->bloco4.X -= 2;

                    peca->estado = 2;
                    break;
                }
            }
            if(peca->estado == 2){
                if(campo->campo_jogo[(peca->bloco1.X)-1][(peca->bloco1.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)][(peca->bloco4.Y)-2] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X -= 1;
                    peca->bloco1.Y += 1;

                    peca->bloco3.X += 1;
                    peca->bloco3.Y -= 1;

                    peca->bloco4.Y -= 2;

                    peca->estado = 3;
                    break;
                }
            }
            if(peca->estado == 3){
                if(campo->campo_jogo[(peca->bloco1.X)-1][(peca->bloco1.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)+2][(peca->bloco4.Y)] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X -= 1;
                    peca->bloco1.Y -= 1;

                    peca->bloco3.X += 1;
                    peca->bloco3.Y += 1;

                    peca->bloco4.X += 2;

                    peca->estado = 4;
                    break;
                }
            }
            if(peca->estado == 4){
                 if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)-1][(peca->bloco3.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)][(peca->bloco4.Y)+2] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X += 1;
                    peca->bloco1.Y -= 1;

                    peca->bloco3.X -= 1;
                    peca->bloco3.Y += 1;

                    peca->bloco4.Y += 2;

                    peca->estado = 1;
                    break;
                }
            }

            break;

        // tipo J
        //essa funcao tambem vai ter como centro o bloco2
        //o bloco J tem somente o bloco4 diferente do bloco L, portanto ficam bem parecidos
        case 6:
            if(peca->estado == 1){
                if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)-1][(peca->bloco4.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)][(peca->bloco3.Y)-2]   == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X += 1;
                    peca->bloco1.Y += 1;

                    peca->bloco4.X -= 1;
                    peca->bloco4.Y -= 1;

                    peca->bloco3.Y -= 2;

                    peca->estado = 2;
                    break;
                }
            }
            if(peca->estado == 2){
                if(campo->campo_jogo[(peca->bloco1.X)-1][(peca->bloco1.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)+2][(peca->bloco3.Y)] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X -= 1;
                    peca->bloco1.Y += 1;

                    peca->bloco4.X += 1;
                    peca->bloco4.Y -= 1;

                    peca->bloco3.X += 2;

                    peca->estado = 3;
                    break;
                }
            }
            if(peca->estado == 3){
                if(campo->campo_jogo[(peca->bloco1.Y)-1][(peca->bloco1.X)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.Y)+1][(peca->bloco4.X)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.Y)+2][(peca->bloco3.X)] == ' ' ){
                    Limpar_Peca(peca);

                    peca->bloco1.X -= 1;
                    peca->bloco1.Y -= 1;

                    peca->bloco4.X += 1;
                    peca->bloco4.Y += 1;

                    peca->bloco3.Y += 2;

                    peca->estado = 4;
                    break;
                   }
            }
            if(peca->estado == 4){
                if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)-1][(peca->bloco4.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)-2][(peca->bloco3.Y)] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X += 1;
                    peca->bloco1.Y -= 1;

                    peca->bloco4.X -= 1;
                    peca->bloco4.Y += 1;

                    peca->bloco3.X -= 2;

                    peca->estado = 1;
                    break;
                   }
            }

            break;

        // tipo T
        //a peca T tambem vai ter como centro o bloco2
        case 7:
            if(peca->estado == 1){
                if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)-1][(peca->bloco3.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)-1][(peca->bloco4.Y)-1] == ' ' ){
                    Limpar_Peca(peca);

                    peca->bloco1.X += 1;
                    peca->bloco1.Y -= 1;

                    peca->bloco3.X -= 1;
                    peca->bloco3.Y += 1;

                    peca->bloco4.X -= 1;
                    peca->bloco4.Y -= 1;

                    peca->estado = 2;
                    break;
                }
            }
            if(peca->estado == 2){
                if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)-1][(peca->bloco3.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)-1] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X += 1;
                    peca->bloco1.Y += 1;

                    peca->bloco3.X -= 1;
                    peca->bloco3.Y -= 1;

                    peca->bloco4.X += 1;
                    peca->bloco4.Y -= 1;

                    peca->estado = 3;
                    break;
                }
            }
            if(peca->estado == 3){
                if(campo->campo_jogo[(peca->bloco1.X)-1][(peca->bloco1.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)+1] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X -= 1;
                    peca->bloco1.Y += 1;

                    peca->bloco3.X += 1;
                    peca->bloco3.Y -= 1;

                    peca->bloco4.X += 1;
                    peca->bloco4.Y += 1;

                    peca->estado = 4;
                    break;
                }
            }
            if(peca->estado == 4){
                if(campo->campo_jogo[(peca->bloco1.X)-1][(peca->bloco1.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)-1][(peca->bloco4.Y)+1] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X -= 1;
                    peca->bloco1.Y -= 1;

                    peca->bloco3.X += 1;
                    peca->bloco3.Y += 1;

                    peca->bloco4.X -= 1;
                    peca->bloco4.Y += 1;

                    peca->estado = 1;
                    break;
                }
            }
            break;
    }
    Print_Peca(peca);
}

void Girar_Peca_Esquerda(pPECA peca, pCAMPO campo){
    int tipo_peca = peca->tipo;

    switch(tipo_peca){
        // tipo O
        case 1:
            break;
        // tipo I
        // a peca I vai ter como o centro o 2, com os perifericos movendo em volta dele
        case 2:
            if( peca->estado == 1 ){
                if(campo->campo_jogo[(peca->bloco2.X)-1][(peca->bloco2.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)+2][(peca->bloco4.Y)-2] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)-1] == ' ' ){
                    Limpar_Peca(peca);

                    peca->bloco1.X -= 1;
                    peca->bloco1.Y += 1;

                    peca->bloco4.X += 2;
                    peca->bloco4.Y -= 2;

                    peca->bloco3.X += 1;
                    peca->bloco3.Y -= 1;

                    Print_Peca(peca);

                    peca->estado = 2;
                    break;
                }
            }
            if(peca->estado == 2){
                if(campo->campo_jogo[(peca->bloco2.X)+1][(peca->bloco2.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)-2][(peca->bloco4.Y)+2] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)-1][(peca->bloco3.Y)+1] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X += 1;
                    peca->bloco1.Y -= 1;

                    peca->bloco4.X -= 2;
                    peca->bloco4.Y += 2;

                    peca->bloco3.X -= 1;
                    peca->bloco3.Y += 1;

                    peca->estado = 1;
                    break;
                }
            }

            break;

        // tipo S
        // a peca de tipo s vai ter como centro o bloco 1
        case 3:
            if(peca->estado == 1){
                if(campo->campo_jogo[(peca->bloco2.X)-1][(peca->bloco2.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)+2][(peca->bloco3.Y)] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco2.X -= 1;
                    peca->bloco2.Y -= 1;

                    peca->bloco4.X += 1;
                    peca->bloco4.Y -= 1;

                    peca->bloco3.X += 2;

                    peca->estado = 2;
                    break;
                }
            }
            if(peca->estado == 2){
                if(campo->campo_jogo[(peca->bloco2.X)+1][(peca->bloco2.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)-1][(peca->bloco4.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)-2][(peca->bloco3.Y)] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco2.X += 1;
                    peca->bloco2.Y += 1;

                    peca->bloco4.X -= 1;
                    peca->bloco4.Y += 1;

                    peca->bloco3.X -= 2;

                    peca->estado = 1;
                    break;
                }
            }

            break;
        // tipo Z
        //o tipo Z vai adotar como centro o bloco2
        case 4:
            if(peca->estado == 1){
                if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)-1][(peca->bloco3.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)-2][(peca->bloco4.Y)] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X += 1;
                    peca->bloco1.Y -= 1;

                    peca->bloco3.X -= 1;
                    peca->bloco3.Y -= 1;

                    peca->bloco4.X -= 2;

                    peca->estado = 4;
                    Print_Peca(peca);
                    break;
                }
            }
            if(peca->estado == 2){
                if(campo->campo_jogo[(peca->bloco1.X)-1][(peca->bloco1.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)+2][(peca->bloco4.Y)] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X -= 1;
                    peca->bloco1.Y += 1;

                    peca->bloco3.X += 1;
                    peca->bloco3.Y += 1;

                    peca->bloco4.X += 2;

                    peca->estado = 1;
                    break;
                }
            }

            break;
        // tipo L
        //essa peca vai ter como centro o bloco 2
        case 5:
            if(peca->estado == 1){
                if(campo->campo_jogo[(peca->bloco1.X)-1][(peca->bloco1.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)][(peca->bloco4.Y)-2] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X -= 1;
                    peca->bloco1.Y += 1;

                    peca->bloco3.X += 1;
                    peca->bloco3.Y -= 1;

                    peca->bloco4.Y -= 2;

                    peca->estado = 4;
                    break;
                }
            }
            if(peca->estado == 2){
                if(campo->campo_jogo[(peca->bloco1.X)-1][(peca->bloco1.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)+2][(peca->bloco4.Y)] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X -= 1;
                    peca->bloco1.Y -= 1;

                    peca->bloco3.X += 1;
                    peca->bloco3.Y += 1;

                    peca->bloco4.X += 2;

                    peca->estado = 1;
                    break;
                }
            }
            if(peca->estado == 3){
                if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)-1][(peca->bloco3.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)][(peca->bloco4.Y)+2] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X += 1;
                    peca->bloco1.Y -= 1;

                    peca->bloco3.X -= 1;
                    peca->bloco3.Y += 1;

                    peca->bloco4.Y += 2;

                    peca->estado = 2;
                    break;
                }
            }
            if(peca->estado == 4){
                 if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)-1][(peca->bloco3.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)-2][(peca->bloco4.Y)] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X += 1;
                    peca->bloco1.Y += 1;

                    peca->bloco3.X -= 1;
                    peca->bloco3.Y -= 1;

                    peca->bloco4.X -= 2;

                    peca->estado = 3;
                    break;
                }
            }

            break;

        // tipo J
        //essa funcao tambem vai ter como centro o bloco2
        //o bloco J tem somente o bloco4 diferente do bloco L, portanto ficam bem parecidos
        case 6:
            if(peca->estado == 1){
                if(campo->campo_jogo[(peca->bloco1.X)-1][(peca->bloco1.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)+2][(peca->bloco3.Y)]   == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X -= 1;
                    peca->bloco1.Y += 1;

                    peca->bloco4.X += 1;
                    peca->bloco4.Y -= 1;

                    peca->bloco3.X += 2;

                    peca->estado = 4;
                    break;
                }
            }
            if(peca->estado == 2){
                if(campo->campo_jogo[(peca->bloco1.X)-1][(peca->bloco1.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)][(peca->bloco3.Y)+2] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X -= 1;
                    peca->bloco1.Y -= 1;

                    peca->bloco4.X += 1;
                    peca->bloco4.Y += 1;

                    peca->bloco3.Y += 2;

                    peca->estado = 1;
                    break;
                }
            }
            if(peca->estado == 3){
                if(campo->campo_jogo[(peca->bloco1.Y)-1][(peca->bloco1.X)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.Y)+1][(peca->bloco4.X)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.Y)][(peca->bloco3.X)-2] == ' ' ){
                    Limpar_Peca(peca);

                    peca->bloco1.X += 1;
                    peca->bloco1.Y -= 1;

                    peca->bloco4.X -= 1;
                    peca->bloco4.Y += 1;

                    peca->bloco3.X -= 2;

                    peca->estado = 2;
                    break;
                   }
            }
            if(peca->estado == 4){
                if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)-1][(peca->bloco4.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)][(peca->bloco3.Y)-2] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X += 1;
                    peca->bloco1.Y += 1;

                    peca->bloco4.X -= 1;
                    peca->bloco4.Y -= 1;

                    peca->bloco3.Y -= 2;

                    peca->estado = 3;
                    break;
                   }
            }

            break;

        // tipo T
        //a peca T tambem vai ter como centro o bloco2
        case 7:
            if(peca->estado == 1){
                if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)-1][(peca->bloco3.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)-1] == ' ' ){
                    Limpar_Peca(peca);

                    peca->bloco1.X += 1;
                    peca->bloco1.Y += 1;

                    peca->bloco3.X -= 1;
                    peca->bloco3.Y -= 1;

                    peca->bloco4.X += 1;
                    peca->bloco4.Y -= 1;

                    peca->estado = 4;
                    break;
                }
            }
            if(peca->estado == 2){
                if(campo->campo_jogo[(peca->bloco1.X)-1][(peca->bloco1.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)+1] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X -= 1;
                    peca->bloco1.Y += 1;

                    peca->bloco3.X += 1;
                    peca->bloco3.Y -= 1;

                    peca->bloco4.X += 1;
                    peca->bloco4.Y += 1;

                    peca->estado = 1;
                    break;
                }
            }
            if(peca->estado == 3){
                if(campo->campo_jogo[(peca->bloco1.X)-1][(peca->bloco1.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)-1][(peca->bloco4.Y)+1] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X -= 1;
                    peca->bloco1.Y -= 1;

                    peca->bloco3.X += 1;
                    peca->bloco3.Y += 1;

                    peca->bloco4.X -= 1;
                    peca->bloco4.Y += 1;

                    peca->estado = 2;
                    break;
                }
            }
            if(peca->estado == 4){
                if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)-1] == ' ' &&
                   campo->campo_jogo[(peca->bloco3.X)-1][(peca->bloco3.Y)+1] == ' ' &&
                   campo->campo_jogo[(peca->bloco4.X)-1][(peca->bloco4.Y)-1] == ' ' ){
                    Limpar_Peca(peca);
                    peca->bloco1.X += 1;
                    peca->bloco1.Y -= 1;

                    peca->bloco3.X -= 1;
                    peca->bloco3.Y += 1;

                    peca->bloco4.X -= 1;
                    peca->bloco4.Y -= 1;

                    peca->estado = 3;
                    break;
                }
            }
            break;
    }
}

void Girar_Peca_Variavel(pPECA peca, pCAMPO campo){
    int tipo_peca;

    tipo_peca = peca->tipo;

    Limpar_Peca(peca);

    switch(tipo_peca){
         //tipo O
        case 1:
            if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)-1] == ' ' &&
               campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)]   == ' ' &&
               campo->campo_jogo[(peca->bloco4.X)][(peca->bloco4.Y)+1]   == ' ' ){

                peca->bloco1.X += 1;
                peca->bloco1.Y -= 1;

                peca->bloco3.X += 1;

                peca->bloco4.Y += 1;

                peca->estado = 1;
                peca->tipo = 2;
                break;
            }
        // tipo I
        case 2:
            if(campo->campo_jogo[(peca->bloco1.X)][(peca->bloco1.Y)+1] == ' ' &&
               campo->campo_jogo[(peca->bloco2.X)+1][(peca->bloco2.Y)] == ' ' &&
               campo->campo_jogo[(peca->bloco3.X)-1][(peca->bloco3.Y)] == ' ' &&
               campo->campo_jogo[(peca->bloco4.X)-1][(peca->bloco4.Y)] == ' ' ){
                peca->bloco1.Y += 1;

                peca->bloco2.X += 1;

                peca->bloco3.X -= 1;

                peca->bloco4.Y -= 1;

                peca->estado = 1;
                peca->tipo = 3;
                break;
            }

        // tipo S
        case 3:
            if(campo->campo_jogo[(peca->bloco1.X)-1][(peca->bloco1.Y)] == ' ' &&
               campo->campo_jogo[(peca->bloco2.X)-1][(peca->bloco2.Y)] == ' ' &&
               campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)] == ' ' &&
               campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)] == ' ' ){
                peca->bloco1.X -= 1;

                peca->bloco2.X -= 1;

                peca->bloco3.X += 1;

                peca->bloco4.X += 1;

                peca->estado = 1;
                peca->tipo = 4;
                break;
            }

        // tipo Z
        case 4:
            if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)-1] == ' ' ){

                peca->bloco1.X += 1;
                peca->bloco1.Y -= 1;

                peca->estado = 1;
                peca->tipo = 5;
                break;
            }

        // tipo L
        case 5:
            if(campo->campo_jogo[(peca->bloco3.X)-1][(peca->bloco3.Y)]  == ' ' &&
               campo->campo_jogo[(peca->bloco4.X)-1][(peca->bloco4.Y)]  == ' ' ){
                peca->bloco3.X -= 1;

                peca->bloco4.X -= 1;

                peca->estado = 1;
                peca->tipo = 6;
                break;
            }

        // tipo J
        case 6:
            if(campo->campo_jogo[(peca->bloco1.X)-1][(peca->bloco1.Y)+1] == ' ' &&
               campo->campo_jogo[(peca->bloco3.X)+2][(peca->bloco3.Y)-1] == ' ' ){
                peca->bloco1.X -= 1;
                peca->bloco1.Y += 1;

                peca->bloco3.X += 2;
                peca->bloco3.Y -= 1;

                peca->estado = 1;
                peca->tipo = 7;
                break;
            }

        // tipo T
        case 7:
            if(campo->campo_jogo[(peca->bloco3.X)-2][(peca->bloco3.Y)+1] == ' ' ){
                peca->bloco3.X -= 2;
                peca->bloco3.Y += 1;

                peca->estado = 1;
                peca->tipo = 1;
                break;
            }
    }
    Print_Peca(peca);
}

