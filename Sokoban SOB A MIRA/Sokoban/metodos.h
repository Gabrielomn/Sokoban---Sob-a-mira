/*Para TABULEIRO:                                   *Para mov:
  4 == PERSONAGEM;    8 == DESTINO VAZIO            * mov == 0 - cima    mov == 3 - esquerda
  5 == CAIXA;         9 == DESTINO COM CAIXA        * mov == 1 - baixo
  6 == PAREDE;        10 == DESTINO COM PERSONAGEM  * mov == 2 - direita
  7 == ESPAÇO VAZIO; */

#include "sokoban.h"
#include "jogo.h"
//*****************************Construtores************************************************
jogo::jogo(void)
{
    ncaixas = 0;
    nespacos = 0;
    personagemposic.x = 0;
    personagemposic.y = 0;
    for(int i=0; i<CMAX; i++)
    {
        caixasposic[i].x = 0;
        caixasposic[i].y = 0;
    }
    for(int i=0; i<CMAX; i++)
    {
        destinosposic[i].x = 0;
        destinosposic[i].y = 0;
    }
    for(int i=0; i<CMAX; i++)
    {
        espacosposic[i].x = 0;
        espacosposic[i].y = 0;
    }
}
sokoban::sokoban(void)
{
    jogo();
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
            tab.jogo[i][j] = 0;
}

//****************************Métodos de Teste de movimento***********************************
int sokoban::testamovimentocima(void)//Testa os movimentos para impedir movimentos inválidos
{
    int x, y;
    x = retornaposic().x;
    y = retornaposic().y;//Nas funções de movimentação, para cada possibilidade de movimento a função realiza as modificações
                        // nescessárias no TABULEIRO tab
    if((tab.jogo[x][y-1] == 5)||(tab.jogo[x][y-1] == 9))
    {
        if((tab.jogo[x][y-2] == 5)||(tab.jogo[x][y-2] == 6)||(tab.jogo[x][y-2] == 9))
            return 0;
        else
            if((tab.jogo[x][y-2] == 7)||(tab.jogo[x][y-2] == 8))
                return 1;
    }
    else
        if(tab.jogo[x][y-1] == 6)
            return 0;
        else
            if((tab.jogo[x][y-1] == 7)||(tab.jogo[x][y-1] == 8))
                return 1;
}

int sokoban::testamovimentobaixo(void)
{
    int x, y;
    x = retornaposic().x;
    y = retornaposic().y;
    
    if((tab.jogo[x][y+1] == 5)||(tab.jogo[x][y+1] == 9))
    {
        if((tab.jogo[x][y+2] == 5)||(tab.jogo[x][y+2] == 6)||(tab.jogo[x][y+2] == 9))
            return 0;
        else
            if((tab.jogo[x][y+2] == 7)||(tab.jogo[x][y+2] == 8))
                return 1;
    }
    else
        if(tab.jogo[x][y+1] == 6)
            return 0;
        else
            if((tab.jogo[x][y+1] == 7)||(tab.jogo[x][y+1] == 8))
                return 1;
}

int sokoban::testamovimentodireita(void)
{
    int x, y;
    x = retornaposic().x;
    y = retornaposic().y;
    
    if((tab.jogo[x+1][y] == 5)||(tab.jogo[x+1][y] == 9))
    {
        if((tab.jogo[x+2][y] == 5)||(tab.jogo[x+2][y] == 6)||(tab.jogo[x+2][y] == 9))
            return 0;
        else
            if((tab.jogo[x+2][y] == 7)||(tab.jogo[x+2][y] == 8))
                return 1;
    }
    else
        if(tab.jogo[x+1][y] == 6)
            return 0;
        else
            if((tab.jogo[x+1][y] == 7)||(tab.jogo[x+1][y] == 8))
                return 1;
}

int sokoban::testamovimentoesquerda(void)
{
    int x, y;
    x = retornaposic().x;
    y = retornaposic().y;
    
    if((tab.jogo[x-1][y] == 5)||(tab.jogo[x-1][y] == 9))
    {
        if(( tab.jogo[x-2][y] == 5)||( tab.jogo[x-2][y] == 6)||( tab.jogo[x-2][y] == 9))
            return 0;
        else
            if((tab.jogo[x-2][y] == 7)||(tab.jogo[x-2][y] == 8))
                return 1;
    }
    else
        if( tab.jogo[x-1][y] == 6)
            return 0;
        else
            if((tab.jogo[x-1][y] == 7)||(tab.jogo[x-1][y] == 8));
                return 1;
}

int sokoban::testafimdejogo(void)
{
    int teste = 0;
    
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++) 
            if(tab.jogo[i][j] == 9)
                teste += 1;
    
    if(teste == getncaixas())
        return 1;
    else
        return 0;
}  
          
//*********************************Métodos de movimentação*******************************************************
void sokoban::movercima(void)//*************************************************MOVER CIMA**********************
{
     int x, y, p;          
     x = retornaposic().x;
     y = retornaposic().y;
     mov = 0;
     if(testamovimentocima() == 1)
     {
         if(tab.jogo[x][y] == 4)
            switch(tab.jogo[x][y-1])
             {
                 case 5:
                     if(tab.jogo[x][y-2] == 7)
                     {
                         tab.jogo[x][y] = 7;
                         tab.jogo[x][y-1] = 4;
                         tab.jogo[x][y-2] = 5;
                     }
                     else
                         if(tab.jogo[x][y-2] == 8)
                         {
                             tab.jogo[x][y] = 7;
                             tab.jogo[x][y-1] = 4;
                             tab.jogo[x][y-2] = 9;
                         }
                     break;
                 case 7:
                     tab.jogo[x][y] = 7;
                     tab.jogo[x][y-1] = 4;
                     break;
                 case 8:
                     tab.jogo[x][y] = 7;
                     tab.jogo[x][y-1] = 10;
                     break;
                 case 9:
                     if(tab.jogo[x][y-2] == 7)
                     {
                         tab.jogo[x][y] = 7;
                         tab.jogo[x][y-1] = 10;
                         tab.jogo[x][y-2] = 5;
                     }
                     else
                         if(tab.jogo[x][y-2] == 8)
                         {
                             tab.jogo[x][y] = 7;
                             tab.jogo[x][y-1] = 10;
                             tab.jogo[x][y-2] = 9;
                         }
                     break;
                 default:
                     break;
             }
         else
             if(tab.jogo[x][y] == 10) 
                 switch(tab.jogo[x][y-1])
                 {
                     case 5:
                          if(tab.jogo[x][y-2] == 7)
                     {
                         tab.jogo[x][y] = 8;
                         tab.jogo[x][y-1] = 4;
                         tab.jogo[x][y-2] = 5;
                     }
                     else
                         if(tab.jogo[x][y-2] == 8)
                         {
                             tab.jogo[x][y] = 8;
                             tab.jogo[x][y-1] = 4;
                             tab.jogo[x][y-2] = 9;
                         }
                         break;
                     case 7:
                         tab.jogo[x][y] = 8;
                         tab.jogo[x][y-1] = 4;
                         break;
                     case 8:
                         tab.jogo[x][y] = 8;
                         tab.jogo[x][y-1] = 10;
                         break;
                     case 9:
                         if(tab.jogo[x][y-2] == 7)
                     {
                         tab.jogo[x][y] = 8;
                         tab.jogo[x][y-1] = 10;
                         tab.jogo[x][y-2] = 5;
                     }
                     else
                         if(tab.jogo[x][y-2] == 8)
                         {
                             tab.jogo[x][y] = 8;
                             tab.jogo[x][y-1] = 10;
                             tab.jogo[x][y-2] = 9;
                         }
                         break;
                     default:
                         break;
                 }       
     }
}

void sokoban::moverbaixo(void)//*************************MOVER BAIXO***********************************
{
     int x, y;          
     x = retornaposic().x;
     y = retornaposic().y;
     mov = 1;
     if(testamovimentobaixo() == 1)
     {
         if(tab.jogo[x][y] == 4)
            switch(tab.jogo[x][y+1])
             {
                 case 5:
                     if(tab.jogo[x][y+2] == 7)
                     {
                         tab.jogo[x][y] = 7;
                         tab.jogo[x][y+1] = 4;
                         tab.jogo[x][y+2] = 5;
                     }
                     else
                         if(tab.jogo[x][y+2] == 8)
                         {
                             tab.jogo[x][y] = 7;
                             tab.jogo[x][y+1] = 4;
                             tab.jogo[x][y+2] = 9;
                         }
                     break;
                 case 7:
                     tab.jogo[x][y] = 7;
                     tab.jogo[x][y+1] = 4;
                     break;
                 case 8:
                     tab.jogo[x][y] = 7;
                     tab.jogo[x][y+1] = 10;
                     break;
                 case 9:
                     if(tab.jogo[x][y+2] == 7)
                     {
                         tab.jogo[x][y] = 7;
                         tab.jogo[x][y+1] = 10;
                         tab.jogo[x][y+2] = 5;
                     }
                     else
                         if(tab.jogo[x][y+2] == 8)
                         {
                             tab.jogo[x][y] = 7;
                             tab.jogo[x][y+1] = 10;
                             tab.jogo[x][y+2] = 9;
                         }
                     break;
                 default:
                     break;
             }
         else
             if(tab.jogo[x][y] == 10) 
                 switch(tab.jogo[x][y+1])
                 {
                     case 5:
                          if(tab.jogo[x][y+2] == 7)
                     {
                         tab.jogo[x][y] = 8;
                         tab.jogo[x][y+1] = 4;
                         tab.jogo[x][y+2] = 5;
                     }
                     else
                         if(tab.jogo[x][y+2] == 8)
                         {
                             tab.jogo[x][y] = 8;
                             tab.jogo[x][y+1] = 4;
                             tab.jogo[x][y+2] = 9;
                         }
                         break;
                     case 7:
                         tab.jogo[x][y] = 8;
                         tab.jogo[x][y+1] = 4;
                         break;
                     case 8:
                         tab.jogo[x][y] = 8;
                         tab.jogo[x][y+1] = 10;
                         break;
                     case 9:
                         if(tab.jogo[x][y+2] == 7)
                     {
                         tab.jogo[x][y] = 8;
                         tab.jogo[x][y+1] = 10;
                         tab.jogo[x][y+2] = 5;
                     }
                     else
                         if(tab.jogo[x][y+2] == 8)
                         {
                             tab.jogo[x][y] = 8;
                             tab.jogo[x][y+1] = 10;
                             tab.jogo[x][y+2] = 9;
                         }
                         break;
                     default:
                         break;
                 }       
     }
}

void sokoban::moverdireita(void)//*********************************MOVER DIREITA**************************************
{
     int x, y;          
     x = retornaposic().x;
     y = retornaposic().y;
     mov = 2;
     if(testamovimentodireita() == 1)
     {
         if(tab.jogo[x][y] == 4)
            switch(tab.jogo[x+1][y])
             {
                 case 5:
                     if(tab.jogo[x+2][y] == 7)
                     {
                         tab.jogo[x][y] = 7;
                         tab.jogo[x+1][y] = 4;
                         tab.jogo[x+2][y] = 5;
                     }
                     else
                         if(tab.jogo[x+2][y] == 8)
                         {
                             tab.jogo[x][y] = 7;
                             tab.jogo[x+1][y] = 4;
                             tab.jogo[x+2][y] = 9;
                         }
                     break;
                 case 7:
                     tab.jogo[x][y] = 7;
                     tab.jogo[x+1][y] = 4;
                     break;
                 case 8:
                     tab.jogo[x][y] = 7;
                     tab.jogo[x+1][y] = 10;
                     break;
                 case 9:
                     if(tab.jogo[x+2][y] == 7)
                     {
                         tab.jogo[x][y] = 7;
                         tab.jogo[x+1][y] = 10;
                         tab.jogo[x+2][y] = 5;
                     }
                     else
                         if(tab.jogo[x+2][y] == 8)
                         {
                             tab.jogo[x][y] = 7;
                             tab.jogo[x+1][y] = 10;
                             tab.jogo[x+2][y] = 9;
                         }
                     break;
                 default:
                     break;
             }
         else
             if(tab.jogo[x][y] == 10) 
                 switch(tab.jogo[x+1][y])
                 {
                     case 5:
                          if(tab.jogo[x+2][y] == 7)
                     {
                         tab.jogo[x][y] = 8;
                         tab.jogo[x+1][y] = 4;
                         tab.jogo[x+2][y] = 5;
                     }
                     else
                         if(tab.jogo[x+2][y] == 8)
                         {
                             tab.jogo[x][y] = 8;
                             tab.jogo[x+1][y] = 4;
                             tab.jogo[x+2][y] = 9;
                         }
                         break;
                     case 7:
                         tab.jogo[x][y] = 8;
                         tab.jogo[x+1][y] = 4;
                         break;
                     case 8:
                         tab.jogo[x][y] = 8;
                         tab.jogo[x+1][y] = 10;
                         break;
                     case 9:
                         if(tab.jogo[x+2][y] == 7)
                     {
                         tab.jogo[x][y] = 8;
                         tab.jogo[x+1][y] = 10;
                         tab.jogo[x+2][y] = 5;
                     }
                     else
                         if(tab.jogo[x+2][y] == 8)
                         {
                             tab.jogo[x][y] = 8;
                             tab.jogo[x+1][y] = 10;
                             tab.jogo[x+2][y] = 9;
                         }
                         break;
                     default:
                         break;
                 }       
     }
}

void sokoban::moveresquerda(void)//*****************************************************MOVER ESQUERDA**************
{
     int x, y, p;          
     x = retornaposic().x;
     y = retornaposic().y;
     mov = 3;
     if(testamovimentoesquerda() == 1)
     {
         if(tab.jogo[x][y] == 4)
            switch(tab.jogo[x-1][y])
             {
                 case 5:
                 {   if(tab.jogo[x-2][y] == 7)
                     {
                         tab.jogo[x][y] = 7;
                         tab.jogo[x-1][y] = 4;
                         tab.jogo[x-2][y] = 5;
                     }
                     else
                         if(tab.jogo[x-2][y] == 8)
                         {
                             tab.jogo[x][y] = 7;
                             tab.jogo[x-1][y] = 4;
                             tab.jogo[x-2][y] = 9;
                         }
                  }
                     break;
                 case 7:
                 {   tab.jogo[x][y] = 7;
                     tab.jogo[x-1][y] = 4;
                     break;
                 }
                 case 8:
                 {   tab.jogo[x][y] = 7;
                     tab.jogo[x-1][y] = 10;
                     break;
                 }
                 case 9:
                 {    
                     if(tab.jogo[x-2][y] == 7)
                     {
                         tab.jogo[x][y] = 7;
                         tab.jogo[x-1][y] = 10;
                         tab.jogo[x-2][y] = 5;
                     }
                     else
                         if(tab.jogo[x-2][y] == 8)
                         {
                             tab.jogo[x][y] = 7;
                             tab.jogo[x-1][y] = 10;
                             tab.jogo[x-2][y] = 9;
                         }
                   }
                     break;
                 default:
                     break;
             }
         else
             if(tab.jogo[x][y] == 10) 
                 switch(tab.jogo[x-1][y])
                     case 5:
                     {
                          if(tab.jogo[x-2][y] == 7)
                          {
                              tab.jogo[x][y] = 8;
                              tab.jogo[x-1][y] = 4;
                              tab.jogo[x-2][y] = 5;
                          }
                         else
                              if(tab.jogo[x-2][y] == 8)
                              {
                                 tab.jogo[x][y] = 8;
                                 tab.jogo[x-1][y] = 4;
                                 tab.jogo[x-2][y] = 9;
                              }
                         break;
                     case 7:
                         tab.jogo[x][y] = 8;
                         tab.jogo[x-1][y] = 4;
                         break;
                     case 8:
                         tab.jogo[x][y] = 8;
                         tab.jogo[x-1][y] = 10;
                         break;
                     case 9:
                         if(tab.jogo[x-2][y] == 7)
                         {
                             tab.jogo[x][y] = 8;
                             tab.jogo[x-1][y] = 10;
                             tab.jogo[x-2][y] = 5;
                         }
                     else
                         if(tab.jogo[x-2][y] == 8)
                         {
                             tab.jogo[x][y] = 8;
                             tab.jogo[x-1][y] = 10;
                             tab.jogo[x-2][y] = 9;
                         }
                         break;
                     default:
                         break;
                 }       
     }
}
//*********************************************Métodos de inicialização de variáveis *******************************************************
void jogo::setpersonagemposic(int x,int y)
{
     personagemposic.x = x;
     personagemposic.y = y;
}

void jogo::setncaixas(int n)
{
     ncaixas = n;
}

void jogo::setnespacos(int n)
{
     nespacos = n;
}

void jogo::setcaixaposic(int a, int b, int c)
{
     caixasposic[a].x = b;
     caixasposic[a].y = c;
}

void jogo::setespacosposic(int a, int b, int c)
{
     espacosposic[a].x = b;
     espacosposic[a].y = c;
}

void jogo::setdestinosposic(int a, int b, int c)
{
     destinosposic[a].x = b;
     destinosposic[a].y = c;
}

void sokoban::tabuleiroinit(void)
{     
    mov = 1;//Inicializa o tabuleiro, colocando em cada posição do tabuleiro a informação do elemento do jogo que ocupa aquela posição
    for(int i=0; i<MAX; i++)                 //A codificação é da seguinte forma:
        for(int j=0; j<MAX; j++)             // 4 == personagem
            tab.jogo[i][j] = 6;              // 5 == caixa
                                            // 6 == Parede
    for(int i=0; i<getnespacos(); i++)     // 7 == espaço vazio 
        tab.jogo[getespacosposic()[i].x][getespacosposic()[i].y] = 7;//  8 == destino vazio
                                                                     // 9 == caixa no destino
    for(int i=0; i<getncaixas(); i++)                                // 10 == personagem no destino
        tab.jogo[getdestinosposic()[i].x][getdestinosposic()[i].y] = 8;
        
    for(int i = 0; i < getncaixas(); i++)       
        tab.jogo[getcaixasposic()[i].x][getcaixasposic()[i].y] = 5;
        
    tab.jogo[getpersonagemposic().x][getpersonagemposic().y] = 4;
}

//***********************************Métodos de acesso ás informações do jogo***********************************

TABULEIRO sokoban::gettab(void)
{
    return tab;
}

POSIC sokoban::retornaposic(void)
{
    POSIC g;
    for(int i = 0; i<MAX;i++)
        for(int j = 0; i<MAX; j++)
            if((tab.jogo[i][j] == 4)||(tab.jogo[i][j] == 10))
            {
                g.x =i;
                g.y = j;    
                return g;
            }
}

int jogo::getncaixas(void)
{
    return ncaixas;
}
int jogo::getnespacos(void)
{
    return nespacos;
}
POSIC* jogo::getespacosposic(void)
{
    return espacosposic;
}
POSIC* jogo::getcaixasposic(void)
{
    return caixasposic;
}
POSIC* jogo::getdestinosposic(void)
{
    return destinosposic;
}
POSIC jogo::getpersonagemposic(void)
{
    return personagemposic;
}

int sokoban::getmov(void)
{
    return mov;
}
