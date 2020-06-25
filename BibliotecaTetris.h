#include  <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define Largura_Campo 22
#define Altura_Campo 26
#define Matriz_Peca 4
#define Meio_Campo_X 10
#define Campo_Fixo 184
#define Borda 186
#define Solo 205
#define Peca_Normal 254
#define Peca_Explosiva 158
#define Peca_Variavel 168
#define Lado_Teste -70
#define Campo_Teste -72

typedef struct Peca{
COORD bloco1;
COORD bloco2;
COORD bloco3;
COORD bloco4;
int estado;
int modo;
int tipo;
int pontos;
}PECA, *pPECA;

typedef struct Campo{
char campo_jogo[Altura_Campo][Largura_Campo];
char campo_limpo[Altura_Campo][Largura_Campo];
}CAMPO, *pCAMPO;

//vai desenhar o menu inicial
void Desenhar_Menu_Inicial(pCAMPO);//ok
//vai desenhar o game over na tela
void Desenhar_Game_Over(pCAMPO);//ok
//vai desenhar as bordas no campo;
void Desenhar_Campo(pCAMPO);//ok
//essa funcao de print só vai ser usada quando uma peca encostar no chao, ou no menu principal, ou no game over
void Print_Campo_Jogo(pCAMPO);//ok
//funcao de mexer peca para o lado direito
void Mov_Peca_Direita (pPECA, pCAMPO);//ok
//funcao de mexer para o ladoesquerdo
void Mov_Peca_Esquerda (pPECA, pCAMPO);//ok
//essa funcao vai mexer um para baixo a peca
/*PORQUE INT
essa funcao vai ser um int para retornar 1 se ela for printada na matriz porque dai a matriz vai
ter q ser reprintada, se nao ela só vai printar na tela e sair
*/
int Mov_Peca_Baixo(pPECA, pCAMPO);//ok
//função para limpar o interior do jogo
void Limpar_Tela_Jogo(pCAMPO);//ok
//essa função vai colocar as coord da peca no lugar certo para que comece a descer
void Tipo_Peca(pPECA, int);//ok
//funcao que vai printar a peca no campo sem fixá-la na matriz
void Print_Peca(pPECA);
//faz baixar todas as linhas depois de verificar se tem uma cheia
void Baixar_Linha_Pronta(pCAMPO, int);
//verifica se tem uma linha cheia tirando a primeira
void Verificacao_Linhas(pCAMPO);
//verifica se a primeira linha ta cheia, se sim retorna 1 indicando fim do jogo
int Fim_Jogo(pCAMPO);
//verificar se a peca ao ser girada ou movida nao vai bater em uma parede a sua direita
int Teste_Mov_Direita(pPECA, pCAMPO);
//verificar se a peca ao ser girada ou movida nao vai bater em uma parede a sua esquerda
int Teste_Mov_Esquerda(pPECA, pCAMPO);
//verificar se a peca ao ser girada ou movida nao vai bater em um bloco embaixo
int Teste_Mov_Baixo(pPECA, pCAMPO);
/*Girar a peca
Essa funcao vai ser um tanto quanto importante e tambem um tanto quando complicada, nela nos vamos girar a peca.
Mas como nos temos só uma struct de peca que atualiza o formato a cada rodada, nós vamos ter q partir do formato da peca
para girar ela de um certo modo. Porem quando girar essa pecas elas podem bater na parede ou embaixo...
Entao decidimos fazer de certo modo que, sabendo a peca a qual esta mexendo, deixe seu centro estatico(normalmente o
bloco2) e modificando as coordenadas dos perifericos de tal modo que a peca gire, mas em todos os giros a peca devera sofrer testes
se os testes laterais baterem na peca vamos mover ela para o lado contrario até que essa posição seja possivel dentro do tabuleiro
*/
void Girar_Peca_Direita(pPECA, pCAMPO);

void Girar_Peca_Esquerda(pPECA, pCAMPO);
//sortear qual vai ser o modo da peca que vai cair
void Sortear_Modo_Peca(pPECA);
//sortear qual vai ser a peca a comecar a cair
int Sortear_Tipo_Peca(pPECA);
//testar se a peca quando girada nao ta em cima de um bloco
int Teste_Peca(pPECA, pCAMPO);
// funcao que vai fazer trocar de peca quand ela for do tipo variavel
void Girar_Peca_Variavel(pPECA, pCAMPO);
//funcao que vai colocar jogo pausado na primeira linha qunado pausar
void Desenhar_Jogo_Pausado();
//funcao que vai colocar a matriz de volta onde estava escrito jogo pausado
void Apagar_Jogo_Pausado();
//funcao que vai colocar ' ' no lugar da peca para nao ficar duplicada
void Limpar_Peca(pPECA);
//essa funcao vai mover pra baixo as pecas explosivas
int Mov_Peca_Baixo_Explosiva(pPECA, pCAMPO);
