#include "BibliotecaTetris.h"

int Mov_Peca_Baixo(pPECA peca, pCAMPO campo){
    Limpar_Peca(peca);

    if(Teste_Mov_Baixo(peca, campo) == 1){
        peca->bloco1.Y ++;
        peca->bloco2.Y ++;
        peca->bloco3.Y ++;
        peca->bloco4.Y ++;
        return 0;
    }
    else{
        campo->campo_jogo[peca->bloco1.Y][peca->bloco1.X] = Campo_Fixo;
        campo->campo_jogo[peca->bloco2.Y][peca->bloco2.X] = Campo_Fixo;
        campo->campo_jogo[peca->bloco3.Y][peca->bloco3.X] = Campo_Fixo;
        campo->campo_jogo[peca->bloco4.Y][peca->bloco4.X] = Campo_Fixo;
        return 1;
    }
    return 0;
}

void Mov_Peca_Direita(pPECA peca, pCAMPO campo){
    Limpar_Peca(peca);

    if (Teste_Mov_Direita(peca, campo) == 1){
        peca->bloco1.X ++;
        peca->bloco2.X ++;
        peca->bloco3.X ++;
        peca->bloco4.X ++;
    }
}

void Mov_Peca_Esquerda(pPECA peca, pCAMPO campo){
    Limpar_Peca(peca);

    if (Teste_Mov_Esquerda(peca, campo) == 1){
        peca->bloco1.X --;
        peca->bloco2.X --;
        peca->bloco3.X --;
        peca->bloco4.X --;
    }
}

void Baixar_Linha_Pronta(pCAMPO campo, int linha){
    int i;
    for(; linha > 0; linha--){
        for(i=1; i < (Largura_Campo-1); i++){
            campo->campo_jogo[linha][i] = campo->campo_jogo[linha - 1][i];
        }
    }
}

int Mov_Peca_Baixo_Explosiva(pPECA peca, pCAMPO campo){
    Limpar_Peca(peca);

    if(Teste_Mov_Baixo(peca, campo) == 1){
            peca->bloco1.Y ++;
            peca->bloco2.Y ++;
            peca->bloco3.Y ++;
            peca->bloco4.Y ++;
            return 0;
        }
    else{
        campo->campo_jogo[peca->bloco1.X][peca->bloco1.Y] = ' ';
        campo->campo_jogo[peca->bloco2.X][peca->bloco2.Y] = ' ';
        campo->campo_jogo[peca->bloco3.X][peca->bloco3.Y] = ' ';
        campo->campo_jogo[peca->bloco4.X][peca->bloco4.Y] = ' ';

        if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)] == Campo_Teste)
            campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)] = ' ';

        if(campo->campo_jogo[(peca->bloco1.X)][(peca->bloco1.Y)+1] == Campo_Teste)
            campo->campo_jogo[(peca->bloco1.X)][(peca->bloco1.Y)+1] = ' ';

        if(campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)+1] == Campo_Teste)
            campo->campo_jogo[(peca->bloco1.X)+1][(peca->bloco1.Y)+1] = ' ';



        if(campo->campo_jogo[(peca->bloco2.X)+1][(peca->bloco2.Y)] == Campo_Teste)
            campo->campo_jogo[(peca->bloco2.X)+1][(peca->bloco2.Y)] = ' ';

        if(campo->campo_jogo[(peca->bloco2.X)][(peca->bloco2.Y)+1] == Campo_Teste)
            campo->campo_jogo[(peca->bloco2.X)][(peca->bloco2.Y)+1] = ' ';

        if(campo->campo_jogo[(peca->bloco2.X)+1][(peca->bloco2.Y)+1] == Campo_Teste)
            campo->campo_jogo[(peca->bloco2.X)+1][(peca->bloco2.Y)+1] = ' ';


        if(campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)] == Campo_Teste)
            campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)] = ' ';

        if(campo->campo_jogo[(peca->bloco3.X)][(peca->bloco3.Y)+1] == Campo_Teste)
            campo->campo_jogo[(peca->bloco3.X)][(peca->bloco3.Y)+1] = ' ';

        if(campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)+1] == Campo_Teste)
            campo->campo_jogo[(peca->bloco3.X)+1][(peca->bloco3.Y)+1] = ' ';


        if(campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)] == Campo_Teste)
            campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)] = ' ';

        if(campo->campo_jogo[(peca->bloco4.X)][(peca->bloco4.Y)+1] == Campo_Teste)
            campo->campo_jogo[(peca->bloco4.X)][(peca->bloco4.Y)+1] = ' ';

        if(campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)+1] == Campo_Teste)
            campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)+1] = ' ';


        if(campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)] != Lado_Teste)
            campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)] = ' ';

        if(campo->campo_jogo[(peca->bloco4.X)][(peca->bloco4.Y)+1] != Lado_Teste)
            campo->campo_jogo[(peca->bloco4.X)][(peca->bloco4.Y)+1] = ' ';

        if(campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)+1] != Lado_Teste)
            campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)+1] = ' ';


        if(campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)] != Solo)
            campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)] = ' ';

        if(campo->campo_jogo[(peca->bloco4.X)][(peca->bloco4.Y)+1] != Solo)
            campo->campo_jogo[(peca->bloco4.X)][(peca->bloco4.Y)+1] = ' ';

        if(campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)+1] != Solo)
            campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)+1] = ' ';


        if(campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)] != Borda)
            campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)] = ' ';

        if(campo->campo_jogo[(peca->bloco4.X)][(peca->bloco4.Y)+1] != Borda)
            campo->campo_jogo[(peca->bloco4.X)][(peca->bloco4.Y)+1] = ' ';

        if(campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)+1] != Borda)
            campo->campo_jogo[(peca->bloco4.X)+1][(peca->bloco4.Y)+1] = ' ';


        Print_Campo_Jogo(campo);

        return 1;
    }
}
