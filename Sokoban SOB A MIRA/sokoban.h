#ifndef SOKOBAN_H
#define SOKOBAN_H
#include "jogo.h"
struct TABULEIRO{
       int jogo[MAX][MAX];
};                 //classe din�mica. herda de jogo
class sokoban: public jogo{//Classe que manipula as informa��es de forma a permitir o funcionamento din�mico do jogo
      private:
          TABULEIRO tab;//guarda todas as informa��es de posi��es de caixas, do personagem e de paredes. 
          int mov;//Guarda a informa��o do ultimo movimento feito para permitir a impress�o da imagem correta do personagem
          int testamovimentocima(void);// Testa se � possivel o personagem mover-se para cima
          int testamovimentobaixo(void);// Testa se � possivel o personagem mover-se para baixo
          int testamovimentodireita(void);// Testa se � possivel o personagem mover-se para a direita
          int testamovimentoesquerda(void);// Testa se � possivel o personagem mover-se para a esquerda
          POSIC retornaposic(void);// retorna a posi��o atual do personagem
      public:          
          sokoban(void);//Construtor
          //M�todos que movimentam o personagem, fazendo as altera��es nescess�rias na configura��o do jogo
          void movercima(void);
          void moverbaixo(void);
          void moveresquerda(void);
          void moverdireita(void);
          
          TABULEIRO gettab(void);//retorna o tabuleiro
          int testafimdejogo(void);//testa se o jogo acabou
          void tabuleiroinit(void);//inicia o tabuleiro, passando para ele todas as informa��es contidas nos atributos da classe jogo.
          int getmov(void);//retorna mov
          };
#endif
