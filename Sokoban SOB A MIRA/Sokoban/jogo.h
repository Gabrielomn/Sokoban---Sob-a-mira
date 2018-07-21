#define MAX 10
#define CMAX 10
#define EMAX 50
#ifndef JOGO_H
#define JOGO_H
struct POSIC{
       int x, y;
};
             // Classe est�tica
class jogo{//Classe que guarda os dados das posi��es iniciais do jogo. Possui apenas m�todos de inicializa��o e retorno de atributos
      private:
          POSIC personagemposic;//posi��o do personagem
          POSIC caixasposic[CMAX];//Guarda as posi��es iniciais das caixas
          int ncaixas;//n�mero de caixas
          POSIC destinosposic[CMAX];//guarda as posi��es iniciais dos locais de destino
          int nespacos;//n�mero de espa�os vazios 
          POSIC espacosposic[EMAX];//guarda as posi��es iniciais dos espa�os vazios
      public:
           //M�todos de inicializa��o
          jogo(void);//construtor
          void setncaixas(int);
          void setnespacos(int);
          void setcaixaposic(int, int, int);
          void setpersonagemposic(int, int);
          void setespacosposic(int, int, int);
          void setdestinosposic(int, int, int);
          //M�todos de retorno
          int getncaixas(void);
          int getnespacos(void);
          POSIC* getespacosposic(void);
          POSIC* getcaixasposic(void);
          POSIC* getdestinosposic(void);
          POSIC getpersonagemposic(void);
};
#endif
