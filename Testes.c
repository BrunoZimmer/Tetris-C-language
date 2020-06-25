#include "BibliotecaTetris.h"

int Teste_Mov_Baixo(pPECA peca, pCAMPO campo){
    if(campo->campo_jogo[(peca->bloco1.Y)+1][peca->bloco1.X] == Campo_Teste ||
       campo->campo_jogo[(peca->bloco2.Y)+1][peca->bloco2.X] == Campo_Teste ||
       campo->campo_jogo[(peca->bloco3.Y)+1][peca->bloco3.X] == Campo_Teste ||
       campo->campo_jogo[(peca->bloco4.Y)+1][peca->bloco4.X] == Campo_Teste ||
       peca->bloco1.Y > Altura_Campo -3 || peca->bloco2.Y > Altura_Campo -3 ||
       peca->bloco3.Y > Altura_Campo -3 || peca->bloco4.Y > Altura_Campo -3 ){

        return 0;
    }
    else{
        return 1;
    }
}

int Teste_Mov_Direita(pPECA peca, pCAMPO campo){
    if((campo->campo_jogo[(peca->bloco1.Y)][peca->bloco1.X+1] == Lado_Teste || campo->campo_jogo[(peca->bloco1.Y)][peca->bloco1.X+1] == Campo_Teste) ||
       (campo->campo_jogo[(peca->bloco2.Y)][peca->bloco2.X+1] == Lado_Teste || campo->campo_jogo[(peca->bloco2.Y)][peca->bloco2.X+1] == Campo_Teste) ||
       (campo->campo_jogo[(peca->bloco3.Y)][peca->bloco3.X+1] == Lado_Teste || campo->campo_jogo[(peca->bloco3.Y)][peca->bloco3.X+1] == Campo_Teste) ||
       (campo->campo_jogo[(peca->bloco4.Y)][peca->bloco4.X+1] == Lado_Teste || campo->campo_jogo[(peca->bloco4.Y)][peca->bloco4.X+1] == Campo_Teste)){
        return 0;
    }
    else{
        return 1;
    }
}

int Teste_Mov_Esquerda(pPECA peca, pCAMPO campo){
    if((campo->campo_jogo[(peca->bloco1.Y)][peca->bloco1.X-1] == Lado_Teste || campo->campo_jogo[(peca->bloco1.Y)][peca->bloco1.X-1] == Campo_Teste) ||
       (campo->campo_jogo[(peca->bloco2.Y)][peca->bloco2.X-1] == Lado_Teste || campo->campo_jogo[(peca->bloco2.Y)][peca->bloco2.X-1] == Campo_Teste) ||
       (campo->campo_jogo[(peca->bloco3.Y)][peca->bloco3.X-1] == Lado_Teste || campo->campo_jogo[(peca->bloco3.Y)][peca->bloco3.X-1] == Campo_Teste) ||
       (campo->campo_jogo[(peca->bloco4.Y)][peca->bloco4.X-1] == Lado_Teste || campo->campo_jogo[(peca->bloco4.Y)][peca->bloco4.X-1] == Campo_Teste)){
        return 0;
    }
    else{
        return 1;
    }
}

int Teste_Peca(pPECA peca, pCAMPO campo){
     if((campo->campo_jogo[(peca->bloco1.Y)][peca->bloco1.X] == Borda || campo->campo_jogo[(peca->bloco1.Y)][peca->bloco1.X] == Campo_Fixo) ||
        (campo->campo_jogo[(peca->bloco2.Y)][peca->bloco2.X] == Borda || campo->campo_jogo[(peca->bloco2.Y)][peca->bloco2.X] == Campo_Fixo) ||
        (campo->campo_jogo[(peca->bloco3.Y)][peca->bloco3.X] == Borda || campo->campo_jogo[(peca->bloco3.Y)][peca->bloco3.X] == Campo_Fixo) ||
        (campo->campo_jogo[(peca->bloco4.Y)][peca->bloco4.X] == Borda || campo->campo_jogo[(peca->bloco4.Y)][peca->bloco4.X] == Campo_Fixo) ){
        return 0;
    }
    else{
        return 1;
    }
}

void Verificacao_Linhas(pCAMPO campo){
    int i, j, verificador;
    for(i=0; i < (Altura_Campo-1); ++i){
        for(j=1, verificador=0; j < (Largura_Campo-1); j++){
            if(campo->campo_jogo[i][j] != ' ')
                verificador++;
        }
        if(verificador == (Largura_Campo-2))
            Baixar_Linha_Pronta(campo, i);
    }
}

int Fim_Jogo(pCAMPO campo){
    int i;
    for(i=1; i < (Largura_Campo-1); i++){
        if(campo->campo_jogo[0][i] == Campo_Teste)
            return 1;
    }
    return 0;
}
