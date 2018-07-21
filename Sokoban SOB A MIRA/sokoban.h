#ifndef SOKOBAN_H
#define SOKOBAN_H
#include "jogo.h"
struct TABULEIRO{
       int jogo[MAX][MAX];
};                 //classe dinâmica. herda de jogo
class sokoban: public jogo{//Classe que manipula as informações de forma a permitir o funcionamento dinâmico do jogo
      private:
          TABULEIRO tab;//guarda todas as informações de posições de caixas, do personagem e de paredes. 
          int mov;//Guarda a informação do ultimo movimento feito para permitir a impressão da imagem correta do personagem
          int testamovimentocima(void);// Testa se é possivel o personagem mover-se para cima
          int testamovimentobaixo(void);// Testa se é possivel o personagem mover-se para baixo
          int testamovimentodireita(void);// Testa se é possivel o personagem mover-se para a direita
          int testamovimentoesquerda(void);// Testa se é possivel o personagem mover-se para a esquerda
          POSIC retornaposic(void);// retorna a posição atual do personagem
      public:          
          sokoban(void);//Construtor
          //Métodos que movimentam o personagem, fazendo as alterações nescessárias na configuração do jogo
          void movercima(void);
          void moverbaixo(void);
          void moveresquerda(void);
          void moverdireita(void);
          
          TABULEIRO gettab(void);//retorna o tabuleiro
          int testafimdejogo(void);//testa se o jogo acabou
          void tabuleiroinit(void);//inicia o tabuleiro, passando para ele todas as informações contidas nos atributos da classe jogo.
          int getmov(void);//retorna mov
          };
#endif
