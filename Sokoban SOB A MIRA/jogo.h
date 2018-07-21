#define MAX 10
#define CMAX 10
#define EMAX 50
#ifndef JOGO_H
#define JOGO_H
struct POSIC{
       int x, y;
};
             // Classe estática
class jogo{//Classe que guarda os dados das posições iniciais do jogo. Possui apenas métodos de inicialização e retorno de atributos
      private:
          POSIC personagemposic;//posição do personagem
          POSIC caixasposic[CMAX];//Guarda as posições iniciais das caixas
          int ncaixas;//número de caixas
          POSIC destinosposic[CMAX];//guarda as posições iniciais dos locais de destino
          int nespacos;//número de espaços vazios 
          POSIC espacosposic[EMAX];//guarda as posições iniciais dos espaços vazios
      public:
           //Métodos de inicialização
          jogo(void);//construtor
          void setncaixas(int);
          void setnespacos(int);
          void setcaixaposic(int, int, int);
          void setpersonagemposic(int, int);
          void setespacosposic(int, int, int);
          void setdestinosposic(int, int, int);
          //Métodos de retorno
          int getncaixas(void);
          int getnespacos(void);
          POSIC* getespacosposic(void);
          POSIC* getcaixasposic(void);
          POSIC* getdestinosposic(void);
          POSIC getpersonagemposic(void);
};
#endif
