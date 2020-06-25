#include "BibliotecaTetris.h"

/* TECLAS USADAS
27 - Esc – encerra o jogo a qualquer momento. Antes de encerrar confirma com o usuário que
deseja mesmo encerrar;
122– Z – Rotaciona a peça para a esquerda;
120– X – Rotaciona a peça para a direita;
115– S – Salva o estado do jogo;
108– L – Carrega o estado do jogo;
114– R – Reinicia o nível;
– Enter – Pausa o jogo;
75– Seta ← – move a peça uma posição para esquerda;
77– Seta → – move a peça uma posição para direita;
72– Seta ↑ – move a peça todas as posições possíveis para baixo;
80– Seta ↓ – move a peça uma posição para baixo.
*/

/*TIPOS DE PECAS
Normal - com um comportamento igual ao das peças do Tetris clássico;

– Explosiva - o comportamento é semelhante ao normal, a diferença é que quando chegam
na posição final estas peças explodem e esvaziam as casas que ocupam junto às casas
adjacentes (duas casas são adjacentes se são contíguas na mesma linha, na mesma coluna
ou na mesma diagonal);

– Variável - se diferenciam das normais na rotação, ao invés de rotacionar a peça, de forma
randômica ela é substituída por uma outra das peças, mantendo a categoria variável e a
posição pela que está no tabuleiro.

*/

/*PECAS
Para fazer as peças vamos criar uma struct peca que tod vez que uma peca for comecar a cair
vai ser sorteado o o formato dela, que só vai mudar as coordenadas da peca porque depois so
vai ser manipulado por aumentar um pra esquerda ou pra direita ou pra baixo
*/

/*PECAS DO CAMPO
Laterais:186
Solo:205
*/

int main(){
    CAMPO campo;
    PECA peca;

    int i;
    int k = 0;//ele quando ir para o jogo
    int m = 0;//esse inteiro vai indicar os momentos em que o bloco atingiu o solo, entao toda vez q ele for 1 vai atualizar peca
    //int troca_peca;//esse inteiro vai indicar qunado uma peca atingiu o solo pra gerar uma nova;

    peca.pontos = 100;
    while(1){
        if(k == 2)
            k = 1;
        if(k == 0){
            Limpar_Tela_Jogo(&campo);
            Print_Campo_Jogo(&campo);
            Desenhar_Menu_Inicial(&campo);
            switch(getch()){
                case 49:
                    //comecar um novo jogo

                    k = 1;

                    break;
                case 50:
                    //continuar de um mapa que ja tava salvo


                    k=1;
                    break;
                case 51:
                    //printar as pontuacoes salvas em um arquivo

                    break;
            }
        }
        if(k == 1){
            Limpar_Tela_Jogo(&campo);
            Desenhar_Campo(&campo);
            Print_Campo_Jogo(&campo);
            Tipo_Peca(&peca, Sortear_Tipo_Peca(&peca));
            Sortear_Modo_Peca(&peca);

            while(k == 1){
                if(Fim_Jogo(&campo) == 1){
                    Desenhar_Game_Over(&campo);
                    k = 0;
                    Sleep(5000);
                    break;
                }

                if(m == 1){
                    Verificacao_Linhas(&campo);
                    Tipo_Peca(&peca, Sortear_Tipo_Peca(&peca));
                    Sortear_Modo_Peca(&peca);
                    Print_Campo_Jogo(&campo);
                    m = 0;
                }

                if(peca.pontos <=10000){
                    if(clock() % CLOCKS_PER_SEC == 0 ){
                        if(peca.modo == 2){
                            m = Mov_Peca_Baixo_Explosiva(&peca, &campo);
                        }
                        else{
                            m = Mov_Peca_Baixo(&peca, &campo);
                        }
                        Print_Peca(&peca);
                    }
                }
                else{
                    if(clock() % (CLOCKS_PER_SEC/2) == 0 ){
                        if(peca.modo == 2){
                            m = Mov_Peca_Baixo_Explosiva(&peca, &campo);
                        }
                        else{
                            m = Mov_Peca_Baixo(&peca, &campo);
                        }
                        Print_Peca(&peca);
                    }
                }

                if(kbhit()){
                    switch(getch()){
                        /*ASCII DAS SETAS:
                        direita: 77
                        esquerda: 75
                        cima: 72
                        baixo: 80
                        ESC 27
                        Z: 122
                        X: 120
                        Enter: 13
                        */
                            //->
                        case 77://clica seta para direita entao anda para direita
                            Mov_Peca_Direita(&peca, &campo);
                            Print_Peca(&peca);
                            break;
                            //<-
                        case 75://clica sta para a esquerda entao anda para a esquerda
                            Mov_Peca_Esquerda(&peca, &campo);
                            Print_Peca(&peca);
                            break;
                            //baixo
                        case 80://aperta seta para baixo entao desce uma posicao
                            if(peca.modo == 2){
                                m = Mov_Peca_Baixo_Explosiva(&peca, &campo);
                            }
                            else{
                                m = Mov_Peca_Baixo(&peca, &campo);
                            }
                            Print_Peca(&peca);
                            break;
                            //^
                        case 72://clica seta pra cima, entao tem q alocar no lugar final
                            if(peca.modo == 2){
                                while(Mov_Peca_Baixo_Explosiva(&peca, &campo) != 1);
                                m = 1;
                            }
                            else{
                                while(Mov_Peca_Baixo(&peca, &campo) != 1);
                                m = 1;
                            }
                            break;
                            //Z
                        case 122://aperta a letra Z, rotaciona pra esquerda
                            if(peca.modo == 3){
                                Girar_Peca_Variavel(&peca, &campo);
                            }
                            else{
                                Girar_Peca_Esquerda(&peca, &campo);
                            }
                            break;
                            //X
                        case 120://aperta X entao tem que rotacionar para a direita
                            if(peca.modo == 3){
                                Girar_Peca_Variavel(&peca, &campo);
                            }
                            else{
                                Girar_Peca_Direita(&peca, &campo);
                            }
                            break;
                            //R
                        case 114://tem q reiniciar o nivel, entao vou mexer com k para ir pro comeco desse while
                            k = 2;
                            break;
                            //ESC
                        case 27://clica ESC pra ver sair do jogo
                            k = 0;
                            break;
                            //Enter
                        case 13:

                            while(!kbhit()){
                                Desenhar_Jogo_Pausado();
                                if(getch() == 13){

                                    for(i=0; i<Largura_Campo;i++)
                                        printf("%c", campo.campo_jogo[0][i]);
                                    break;
                                }
                            }
                            break;
                            //L
                        case 108:

                            break;
                            //S
                        case 115:

                            break;
                    }
                }
            }
        }
    }
}

