#include "sokoban.h"
#include "metodos.h"
#include "jogo.h"
#include <allegro.h>

volatile bool exit_program=FALSE; 
void fecha_programa();
void fase(sokoban &p, BITMAP*C, BITMAP*P, BITMAP*F, BITMAP*PE0, BITMAP*PE1, BITMAP*PE2, BITMAP*PE3, BITMAP*D, BITMAP*G, MIDI*,BITMAP*, BITMAP*);
int main() 
{	
	int teste = 0;
	sokoban primeira, segunda, terceira, quarta, quinta;
    //*****************Inicializações das fases: Cada fase é um objeto*********************
    primeira.setncaixas(7);//**************************Primeira fase***********************************
    primeira.setnespacos(15);
  	primeira.setpersonagemposic(7,4);
  	
    primeira.setcaixaposic(0,2,4); 
    primeira.setcaixaposic(1,2,6);
    primeira.setcaixaposic(2,4,3);
    primeira.setcaixaposic(3,4,6);
    primeira.setcaixaposic(4,6,3);
    primeira.setcaixaposic(5,6,4);
    primeira.setcaixaposic(6,6,5);
    
    primeira.setdestinosposic(0,4,2);
    primeira.setdestinosposic(1,3,3);
    primeira.setdestinosposic(2,3,7);
    primeira.setdestinosposic(3,3,5);
    primeira.setdestinosposic(4,5,3);  
    primeira.setdestinosposic(5,5,5);
    primeira.setdestinosposic(6,5,7);
    
    primeira.setespacosposic(0,1,3);
    primeira.setespacosposic(1,1,4);
    primeira.setespacosposic(2,1,5);
    primeira.setespacosposic(3,1,6);
    primeira.setespacosposic(4,1,7);
    primeira.setespacosposic(5,2,2);
    primeira.setespacosposic(6,2,3);
    primeira.setespacosposic(7,2,5);
    primeira.setespacosposic(8,2,7);
    primeira.setespacosposic(9,3,2);
    primeira.setespacosposic(10,4,4);
    primeira.setespacosposic(11,4,5);
    primeira.setespacosposic(12,4,7);
    primeira.setespacosposic(13,7,3);
    primeira.setespacosposic(14,7,5);
    
    
    segunda.setncaixas(5);//*****************Segunda Fase***************************************
    segunda.setnespacos(15);
    segunda.setpersonagemposic(2,2);
    
    segunda.setcaixaposic(0,3,5);
    segunda.setcaixaposic(1,4,4);
    segunda.setcaixaposic(2,5,3);
    segunda.setcaixaposic(3,5,5);
    segunda.setcaixaposic(4,6,4);  
    
    segunda.setdestinosposic(0,7,3);
    segunda.setdestinosposic(1,7,4);
    segunda.setdestinosposic(2,7,5);
    segunda.setdestinosposic(3,8,4);
    segunda.setdestinosposic(4,8,5);
 
    segunda.setespacosposic(0,1,4);
    segunda.setespacosposic(1,2,3);
    segunda.setespacosposic(2,2,4);
    segunda.setespacosposic(3,2,5);
    segunda.setespacosposic(4,2,6);
    segunda.setespacosposic(5,3,2);
    segunda.setespacosposic(6,3,4);
    segunda.setespacosposic(7,3,6);
    segunda.setespacosposic(8,4,2);
    segunda.setespacosposic(9,4,5);
    segunda.setespacosposic(10,5,2);
    segunda.setespacosposic(11,5,4);
    segunda.setespacosposic(12,6,3);
    segunda.setespacosposic(13,6,5);
    segunda.setespacosposic(14,1,5);
    
    terceira.setncaixas(6);//*********************************** Terceira Fase*********************
    terceira.setnespacos(14);
    terceira.setpersonagemposic(2,4);
      
    terceira.setcaixaposic(0,3,3);
    terceira.setcaixaposic(1,3,4);
    terceira.setcaixaposic(2,3,5);
    terceira.setcaixaposic(3,5,4);
    terceira.setcaixaposic(4,6,3);
    terceira.setcaixaposic(5,6,5);
    
    terceira.setespacosposic(0,2,2);
    terceira.setespacosposic(1,2,3);
    terceira.setespacosposic(2,2,5);
    terceira.setespacosposic(3,2,6);
    terceira.setespacosposic(4,3,2);
    terceira.setespacosposic(5,3,6);
    terceira.setespacosposic(6,5,2);
    terceira.setespacosposic(7,5,6);
    terceira.setespacosposic(8,6,2);
    terceira.setespacosposic(9,6,6);
    terceira.setespacosposic(10,7,2);
    terceira.setespacosposic(11,7,3);
    terceira.setespacosposic(12,7,5);
    terceira.setespacosposic(13,7,6);
    
    terceira.setdestinosposic(0,4,3);
    terceira.setdestinosposic(1,4,4);
    terceira.setdestinosposic(2,4,5);
    terceira.setdestinosposic(3,5,3);
    terceira.setdestinosposic(4,5,5);
    terceira.setdestinosposic(5,6,4);
    
    
    quarta.setncaixas(6);//******************************** Quarta fase************************************
    quarta.setnespacos(14);
    quarta.setpersonagemposic(7,6);
    
    quarta.setcaixaposic(0,2,4);
    quarta.setcaixaposic(1,2,5);
    quarta.setcaixaposic(2,3,4);
    quarta.setcaixaposic(3,4,3);
    quarta.setcaixaposic(4,5,5);
    quarta.setcaixaposic(5,6,4);
    
    quarta.setespacosposic(0,1,3);
    quarta.setespacosposic(1,1,4);
    quarta.setespacosposic(2,2,3);
    quarta.setespacosposic(3,3,3);
    quarta.setespacosposic(4,4,2);
    quarta.setespacosposic(5,4,4);
    quarta.setespacosposic(6,5,2);
    quarta.setespacosposic(7,5,4);
    quarta.setespacosposic(8,5,6);
    quarta.setespacosposic(9,6,2);
    quarta.setespacosposic(10,6,3);
    quarta.setespacosposic(11,6,6);
    quarta.setespacosposic(12,7,4);
    quarta.setespacosposic(13,7,5);
    
    quarta.setdestinosposic(0,1,5);
    quarta.setdestinosposic(1,1,6);
    quarta.setdestinosposic(2,2,6);
    quarta.setdestinosposic(3,3,5);
    quarta.setdestinosposic(4,3,6);
    quarta.setdestinosposic(5,4,6);
    
    
    quinta.setncaixas(8);//*****************************Quinta fase******************************
    quinta.setnespacos(8);
    quinta.setpersonagemposic(4,4);
    
    quinta.setcaixaposic(0,3,3);
    quinta.setcaixaposic(1,3,4);
    quinta.setcaixaposic(2,3,5);
    quinta.setcaixaposic(3,4,3);
    quinta.setcaixaposic(4,4,5);
    quinta.setcaixaposic(5,5,3);
    quinta.setcaixaposic(6,5,4);
    quinta.setcaixaposic(7,5,5);
    
    quinta.setespacosposic(0,2,3);
    quinta.setespacosposic(1,2,5);
    quinta.setespacosposic(2,3,2);
    quinta.setespacosposic(3,3,6);
    quinta.setespacosposic(4,5,2);
    quinta.setespacosposic(5,5,6);
    quinta.setespacosposic(6,6,3);
    quinta.setespacosposic(7,6,5);
    
    quinta.setdestinosposic(0,2,2);
    quinta.setdestinosposic(1,2,4);
    quinta.setdestinosposic(2,2,6);
    quinta.setdestinosposic(3,4,2);
    quinta.setdestinosposic(4,4,6);
    quinta.setdestinosposic(5,6,2);
    quinta.setdestinosposic(6,6,4);
    quinta.setdestinosposic(7,6,6);
    //*********inicialização das funções do allegro
    allegro_init();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    install_keyboard();
    install_mouse();
	
	set_window_title("Sob a Mira Sokoban"); 
    set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 500, 500, 0, 0);
	LOCK_VARIABLE(fecha_programa); 
	LOCK_FUNCTION(fecha_programa); 
	
	
	set_close_button_callback(fecha_programa);
	// BITMAP - Carregamento das imagens e sons
    BITMAP *CAIXA, *PAREDE, *FUNDO, *PERS0,*PERS1,*PERS2,*PERS3 , *DEST, *FIM, *MENU, *FASE, *GANHOU, *INFO, *CAIXA_CINZA;
	MIDI *MUS, *MEN;
	BITMAP *Buf = create_bitmap(500,500);
    CAIXA=load_bitmap("Box.bmp", NULL);
    CAIXA_CINZA= load_bitmap("Box_gray.bmp", NULL); 
    PAREDE=load_bitmap("Parede.bmp", NULL);
    FUNDO=load_bitmap("Fundo.bmp", NULL);
    
    PERS0=load_bitmap("Personagemcima1.bmp", NULL);
	PERS1=load_bitmap("Personagemfrente1.bmp", NULL);
	PERS2=load_bitmap("Personagemdireita1.bmp", NULL);
    PERS3=load_bitmap("Personagemesquerda1.bmp", NULL);

    DEST=load_bitmap("Destino.bmp", NULL);
    FIM=load_bitmap("Ganhou.bmp", NULL);
    GANHOU=load_bitmap("Ganhoutudo.bmp", NULL);
    MENU=load_bitmap("Menu.bmp", NULL);
    FASE=load_bitmap("Fases.bmp", NULL);
    INFO = load_bitmap("INFO.bmp", NULL);
    MUS= load_midi("GameofThrones.mid");
    MEN =  load_midi("hoho.mid");
      
    //GAME LOOP - Aqui começa o jogo propriamente dito
    while(!exit_program && !key[KEY_ESC])
    {
    	  	
        teste = 0;
        stop_midi();
        play_midi(MEN,TRUE);//música do menu
        while(!exit_program && !key[KEY_ESC]) 
        {
           
            draw_sprite(Buf,MENU,0,0);
            show_mouse(Buf);
            draw_sprite(screen,Buf,0,0);
            
        
            if(key[KEY_I]||((mouse_x > 25)&&(mouse_x < 356)&&(mouse_y > 161)&&(mouse_y < 259) &&(mouse_b)&& (1)))
                while(!exit_program && !key[KEY_ESC])//Modo de jogo "zerando"
                {
                	
                    teste = 1;
                    primeira.tabuleiroinit();
                    fase(primeira, CAIXA, PAREDE, FUNDO, PERS0, PERS1, PERS2, PERS3, DEST, FIM, MUS, INFO,CAIXA_CINZA);
                    segunda.tabuleiroinit();
                    fase(segunda, CAIXA, PAREDE, FUNDO,PERS0, PERS1, PERS2, PERS3,DEST, FIM,MUS, INFO,CAIXA_CINZA);
                    terceira.tabuleiroinit();
                    fase(terceira, CAIXA, PAREDE, FUNDO,PERS0, PERS1, PERS2, PERS3, DEST, FIM,MUS, INFO,CAIXA_CINZA);
                    quarta.tabuleiroinit();
                    fase(quarta, CAIXA, PAREDE, FUNDO, PERS0, PERS1, PERS2, PERS3, DEST, FIM,MUS, INFO,CAIXA_CINZA);
                    if(quarta.testafimdejogo() == 1)  
                           while(!key[KEY_O])
                           { 
                            draw_sprite(screen, GANHOU, 0, 0);
                            if(key[KEY_U])
                                while(!key[KEY_O])
                                    if(key[KEY_F])
                                        while(!key[KEY_O])
                                            if(key[KEY_C])
                                                while(!key[KEY_O])
                                                if(key[KEY_G])
                                                {
                                                quinta.tabuleiroinit();
                                                fase(quinta, CAIXA, PAREDE, FUNDO, PERS0, PERS1, PERS2, PERS3, DEST, FIM,MUS, INFO,CAIXA_CINZA);
                                                }
                           }
                    break;
                }
        
            if(key[KEY_S]||((mouse_x > 25)&&(mouse_x < 430)&&(mouse_y > 277)&&(mouse_y < 355) &&(mouse_b)&& (1)))  
                while(!key[KEY_ESC])
                {
                    rest(150);
                    draw_sprite(Buf,FASE,0,0);//Menu de fases
                    show_mouse(Buf);
                    draw_sprite(screen,Buf,0,0);
                    if(key[KEY_1]||((mouse_x > 100)&&(mouse_x < 222)&&(mouse_y > 153)&&(mouse_y < 207) &&(mouse_b)&& (1)))
                    {    
                        teste = 1;
                        primeira.tabuleiroinit();
                        fase(primeira, CAIXA, PAREDE, FUNDO, PERS0, PERS1, PERS2, PERS3, DEST, FIM,MUS, INFO,CAIXA_CINZA);
                        break;
                    }
                    if(key[KEY_2]||((mouse_x > 100)&&(mouse_x < 237)&&(mouse_y > 234)&&(mouse_y < 287) &&(mouse_b)&& (1)))
                    {
                        teste = 1;
                        segunda.tabuleiroinit();
                        fase(segunda, CAIXA, PAREDE, FUNDO, PERS0, PERS1, PERS2, PERS3, DEST, FIM,MUS, INFO,CAIXA_CINZA);
                        break;
                    }
                    if(key[KEY_3]||((mouse_x > 100)&&(mouse_x < 238)&&(mouse_y > 313)&&(mouse_y < 364) &&(mouse_b)&& (1)))
                    {
                        teste = 1;
                        terceira.tabuleiroinit();
                        fase(terceira, CAIXA, PAREDE, FUNDO, PERS0, PERS1, PERS2, PERS3, DEST, FIM,MUS, INFO,CAIXA_CINZA);
                        break;
                    }
                    if(key[KEY_4]||((mouse_x > 100)&&(mouse_x < 238)&&(mouse_y > 391)&&(mouse_y < 444) &&(mouse_b)&& (1)))
                    {   
                        teste = 1;
                        quarta.tabuleiroinit();
                        fase(quarta, CAIXA, PAREDE, FUNDO, PERS0, PERS1, PERS2, PERS3, DEST, FIM,MUS, INFO,CAIXA_CINZA);
                        break;
                    }
                    if(key[KEY_O])
                          break;
            }           
            if(teste == 1)
               break;
        } 
        
		       
    }
    

	return 0;
}
END_OF_MAIN();
//************************************Função que imprime o jogo na tela********************************************************
void fase(sokoban &p, BITMAP*C, BITMAP*P,BITMAP*F, BITMAP*PE0, BITMAP*PE1, BITMAP*PE2, BITMAP*PE3, BITMAP*D, BITMAP*G, MIDI*M, BITMAP*I, BITMAP*CZ)
{
	
    stop_midi();
    play_midi(M,TRUE);
    BITMAP *Buffer = create_bitmap(500,500);
    
    while(!exit_program && !key[KEY_ESC])
    {
        if(p.testafimdejogo() == 1)
            {
                while(!key[KEY_ENTER] && !exit_program && !key[KEY_ESC])
                     draw_sprite(screen,G,0 ,0);
                
                break;
            }
        
        if(key[KEY_UP])
            p.movercima();   
        if(key[KEY_DOWN])
            p.moverbaixo();
        if(key[KEY_RIGHT])
            p.moverdireita();
        if(key[KEY_LEFT])
            p.moveresquerda();
        if(key[KEY_R]||((mouse_x > 0)&&(mouse_x < 150)&&(mouse_y > 450)&&(mouse_y < 500) &&(mouse_b)&& (1)))
            p.tabuleiroinit();
        if(key[KEY_O]||((mouse_x > 200)&&(mouse_x < 450)&&(mouse_y > 450)&&(mouse_y < 500) &&(mouse_b)&& (1)))
            break;
    
    for(int i=0; i <10; i++)
	    for(int j = 0; j< 10; j++)
	    {
            if(p.gettab().jogo[i][j] == 6)
                draw_sprite(Buffer,P,50*i,50*j);
            if((p.gettab().jogo[i][j] == 7)||(p.gettab().jogo[i][j] == 8)||(p.gettab().jogo[i][j] == 4)||(p.gettab().jogo[i][j] == 10))
                draw_sprite(Buffer,F,50*i,50*j);
            if((p.gettab().jogo[i][j] == 5))
            	draw_sprite(Buffer,C,50*i,50*j);
            if((p.gettab().jogo[i][j] == 9)){
   	 	 	 	
				draw_sprite(Buffer,CZ,50*i,50*j);            	
			}
            if((p.gettab().jogo[i][j] == 4)||(p.gettab().jogo[i][j] == 10))
                switch(p.getmov())
                {
                    case 0:
                        draw_sprite(Buffer,PE0,50*i,50*j);
                        break;
                    case 1:
                        draw_sprite(Buffer,PE1,50*i,50*j);
                        break;
                    case 2:
                        draw_sprite(Buffer,PE2,50*i,50*j);
                        break;
                    case 3:
                        draw_sprite(Buffer,PE3,50*i,50*j);
                        break;
                    default:
                        break;   
                }
            if(p.gettab().jogo[i][j] == 8)
                draw_sprite(Buffer,D,50*i ,50*j);
         }
        
        draw_sprite(Buffer, I,0,450);
        show_mouse(Buffer);
        rest(150);
        draw_sprite(screen ,Buffer, 0, 0);
        clear_bitmap(Buffer);
    }
}

void fecha_programa(){
	exit_program = TRUE; 
}
END_OF_FUNCTION(fecha_programa);

