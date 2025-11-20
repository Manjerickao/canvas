
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "gl_canvas2d.h"


int mx, my; //coordenadas do mouse
int clicou = 0;
int mbutton;
int mstate;
int Num_binario[10];
int NUm_ajuda[10];
int NUm_ajuda_0[10];
int Y = 0;
int estado = 0;


void Manchester(){
    float x = 20;
    float y = 100;
    color(5);
    text(170, 80, "Codigo Manchester");
    for(int c = 0; c < 10; c++){
        if(Num_binario[c] == 1){
            color(2);
            line(x+5,y+50, x+25, y+50);
            line(x+25,y, x+50, y);
            line(x+25,y, x+25, y+50);
        }
        else if(Num_binario[c] == 0){
            color(2);
            line(x+5,y, x+25, y);
            line(x+25,y+50, x+50, y+50);
            line(x+25,y, x+25, y+50);
        }
        if(c != 0 && (Num_binario[c] == 1 && Num_binario[c-1]== 1 || Num_binario[c] == 0 && Num_binario[c-1]== 0)){
             color(2);
             line(x+5,y, x+5, y+50);
        }
        color(0);
        if(Num_binario[c] == 0)
            text(x+20, y+130, "0");
        else
            text(x+20, y+130, "1");
         x = x + 45;
    }

}

void pseudoternary(){
    float x = 20;
    float y = 100;
    color(5);
    text(170, 80, "Codigo Pseudoternary");
    for(int c = 0; c < 10; c++){
        if(Num_binario[c] == 1){
            color(2);
            line(x+5,y+50, x+50, y+50);
        }
        else if(Num_binario[c] == 0 && NUm_ajuda_0[c] == 1){
            color(2);
            line(x+5,y+5, x+50, y+5 );
        }
        else if(Num_binario[c] == 0 && NUm_ajuda_0[c] == 2){
            color(2);
            line(x+5,y+95, x+50, y+95);
        }
        if(c != 0 && NUm_ajuda_0[c] == 1 && NUm_ajuda_0[c-1] == 0)
            line(x+5,y, x+5, y+50);
        else if(c != 0 && NUm_ajuda_0[c] == 1 && NUm_ajuda_0[c-1] == 2 || c != 0 && NUm_ajuda_0[c] == 2 && NUm_ajuda_0[c-1] == 1)
            line(x+5,y, x+5, y+95);
        else if(c != 0 && NUm_ajuda_0[c] == 2 && NUm_ajuda_0[c-1] == 0)
             line(x+5,y+50, x+5, y+95);
        else if(c != 0 && NUm_ajuda_0[c] == 1 && NUm_ajuda_0[c-1] == 0)
             line(x+5,y-50, x+5, y);
        else if(c != 0 && NUm_ajuda_0[c] == 0 && NUm_ajuda_0[c-1] == 1 )
            line(x+5,y, x+5, y+50);
        else if(c != 0 && NUm_ajuda_0[c] == 0 && NUm_ajuda_0[c-1] == 2 )
            line(x+5,y+50, x+5, y+95);
        color(0);
        if(Num_binario[c] == 0)
            text(x+20, y+130, "0");
        else
            text(x+20, y+130, "1");
         x = x + 45;
    }

}

void Manchester_D(){
 float x = 20;
    float y = 100;
    color(5);
    text(170, 80, "Codigo Manchester Diferencial");
    for(int c = 0; c < 10; c++){
        if(Num_binario[c] == 1){
            color(2);
            line(x+5,y+50, x+25, y+50);
            line(x+25,y, x+50, y);
            line(x+25,y, x+25, y+50);
        }
        else if(Num_binario[c] == 0){
            color(2);
            line(x+5,y, x+25, y);
            line(x+25,y+50, x+50, y+50);
            line(x+25,y, x+25, y+50);
        }
        if(c != 0 && (Num_binario[c] == 1 && Num_binario[c-1]== 1 || Num_binario[c] == 0 && Num_binario[c-1]== 0)){
             color(2);
             line(x+5,y, x+5, y+50);
        }
        color(0);
        if(Num_binario[c] == 0)
            text(x+20, y+130, "0");
        else
            text(x+20, y+130, "1");
         x = x + 45;
    }

}

void AMI(){
    float x = 20;
    float y = 100;
    color(5);
    text(170, 80, "Codigo AMI");
    for(int c = 0; c < 10; c++){
        if(Num_binario[c] == 0){
            color(2);
            line(x+5,y+50, x+50, y+50);
        }
        else if(Num_binario[c] == 1 && NUm_ajuda[c] == 1){
            color(2);
            line(x+5,y+5, x+50, y+5 );
        }
        else if(Num_binario[c] == 1 && NUm_ajuda[c] == 2){
            color(2);
            line(x+5,y+95, x+50, y+95);
        }
        if(c != 0 && NUm_ajuda[c] == 1 && NUm_ajuda[c-1] == 0)
            line(x+5,y, x+5, y+50);
        else if(c != 0 && NUm_ajuda[c] == 1 && NUm_ajuda[c-1] == 2 || c != 0 && NUm_ajuda[c] == 2 && NUm_ajuda[c-1] == 1)
            line(x+5,y, x+5, y+95);
        else if(c != 0 && NUm_ajuda[c] == 2 && NUm_ajuda[c-1] == 0)
             line(x+5,y+50, x+5, y+95);
        else if(c != 0 && NUm_ajuda[c] == 1 && NUm_ajuda[c-1] == 0)
             line(x+5,y-50, x+5, y);
        else if(c != 0 && NUm_ajuda[c] == 0 && NUm_ajuda[c-1] == 1 )
            line(x+5,y, x+5, y+50);
        else if(c != 0 && NUm_ajuda[c] == 0 && NUm_ajuda[c-1] == 2 )
            line(x+5,y+50, x+5, y+95);
        color(0);
        if(Num_binario[c] == 0)
            text(x+20, y+130, "0");
        else
            text(x+20, y+130, "1");
         x = x + 45;
    }

}

void nrz_L(){
    float x = 20;
    float y = 100;
    color(5);
    text(170, 80, "Codigo NRZ_L");
    for(int c = 0; c < 10; c++){
        if(Num_binario[c] == 0){
            color(2);
            line(x+5,y+5, x+50, y+5 );
        }
        else if(Num_binario[c] == 1){
            color(2);
            line(x+5,y+50, x+50, y+50);
        }
        if(c != 0 && (NUm_ajuda[c] == 1 || NUm_ajuda[c] == 2) && NUm_ajuda[c-1] == 0)
            line(x+5,y, x+5, y+50);
        if(c != 0 && NUm_ajuda[c] == 0 && (NUm_ajuda[c-1] == 1 || NUm_ajuda[c-1]== 2) )
            line(x+5,y, x+5, y+50);
        color(0);
        if(Num_binario[c] == 0)
            text(x+20, y+130, "0");
        else
            text(x+20, y+130, "1");
         x = x + 45;
    }

}

void nrz_I(){
    float x = 20;
    float y = 100;
    color(5);
    text(170, 80, "Codigo NRZ_I");
    for(int c = 0; c < 10; c++){
        if(Num_binario[c] == 0){
            color(2);
            line(x+5,y+50, x+50, y+50);
        }
        else if(Num_binario[c] == 1 && NUm_ajuda[c] == 1){
            color(2);
            line(x+5,y+5, x+50, y+5 );
        }
        else if(Num_binario[c] == 1 && NUm_ajuda[c] == 2){
            color(2);
            line(x+5,y+50, x+50, y+50);
        }
        if(c != 0 && NUm_ajuda[c] == 1 || (NUm_ajuda[c-1]!= 0 && NUm_ajuda[c] == 2))
            line(x+5,y, x+5, y+50);
        if(c != 0 && NUm_ajuda[c] == 0 && NUm_ajuda[c-1] == 1 )
            line(x+5,y, x+5, y+50);
        color(0);
        if(Num_binario[c] == 0)
            text(x+20, y+130, "0");
        else
            text(x+20, y+130, "1");
         x = x + 45;
    }
}

void desenha_fundo(){
    float x = 20;
    float y = 100;
    color(1, 0, 1);
    rectFill(0,0, 1000, 1000);
    for(int c = 0; c< 10 ; c++){
            color(1, 1, 1);
            line(x,y+5, x+45, y+5 );
            color(0);
            line(x,y+50, x+45, y+50 );
            color(1, 1, 1);
            line(x,y+95, x+45, y+95);
            if(c == 0){
                color(0);
                line(x+5,y, x+5, y+100);
            }
            else  line(x+5,y, x+5, y+140);
        x = x + 45;
    }
    line(x,y, x, y+140 );
    color(0);
    text(7, 153, "0");
}

void desenha_codigo(){
   switch(estado){
        case 1:
            desenha_fundo();
            nrz_I();
            break;
        case 2:
            desenha_fundo();
            nrz_L();
            break;
        case 3:
            desenha_fundo();
            AMI();
            break;
        case 4:
            desenha_fundo();
            pseudoternary();
            break;
        case 5:
            desenha_fundo();
            Manchester();
            break;
        case 6:
            desenha_fundo();
            Manchester_D();
            break;
        case 7:
             break;
        case 8:
            break;
   }

}

void menu(int y){
    color(3);
    rectFill(180, y+ 50, 330, y+80);
    rectFill(180, y+100, 330, y+130);
    rectFill(180, y+150, 330, y+180);
    rectFill(180, y+200, 330, y+230);
    rectFill(180, y+250, 330, y+280);
    rectFill(180, y+300, 330, y+330);
    rectFill(180, y+350, 330, y+380);
    rectFill(180, y+400, 330 ,y+430);
    color(0);
    text(175, y+30,"Codigos de Linha" );
    text(230, y+70,"NRZ-I" );
    text(230, y+120,"NRZ-L" );
    text(240, y+170,"AMI" );
    text(190, y+220,"Pseudoternario" );
    text(200, y+270,"Mancherster" );
    text(200, y+320,"Manchester D");
}

void seleciona_codigo(){
    if(clicou == 1 && mx >= 180 && mx <=330 && my>= Y+50 && my <= Y+ 80 ){
        printf("ok");
        clicou = 0;
        Y = 100000000;
        estado =1;
    }
    else if(clicou == 1 && mx >= 180 && mx <=330 && my>= Y+100 && my <= Y+ 130 ){
        printf("ok2");
        clicou = 0;
        Y = 100000000;
        estado =2;
    }
    else if(clicou == 1 && mx >= 180 && mx <=330 && my>= Y+150 && my <= Y+ 180){
        printf("ok3");
        clicou = 0;
        Y = 100000000;
        estado =3;
    }
    else if(clicou == 1 && mx >= 180 && mx <=330 && my>= Y+200 && my <= Y+ 230 ){
        printf("ok4");
        clicou = 0;
        Y = 100000000;
        estado =4;
    }
    else if(clicou == 1 && mx >= 180 && mx <=330 && my>= Y+250 && my <= Y+ 280 ){
        printf("ok5");
        clicou = 0;
        Y = 100000000;
        estado =5;
    }
    else if(clicou == 1 && mx >= 180 && mx <=330 && my>= Y+300 && my <= Y+ 330){
        printf("ok6");
        clicou = 0;
        Y = 100000000;
        estado =6;
    }
    else if(clicou == 1 && mx >= 180 && mx <=330 && my>= Y+350 && my <= Y+ 380 ){
        printf("ok7");
        clicou = 0;
        Y = 100000000;
        estado =7;
    }
    else if(clicou == 1 && mx >= 180 && mx <=330 && my>= Y+400 && my <= Y+ 430 ){
        printf("ok8");
        clicou = 0;
        Y = 100000000;
        estado =8;
    }

}


//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render()
{

    menu(Y);
    seleciona_codigo();
    desenha_codigo();

}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
 //  printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);

   mx = x; //guarda as coordenadas do mouse para exibir dentro da render()
   my = y;
   if (state == 0)
        clicou = 1;
    else
    clicou = 0;
}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
   printf("\nClicou Tecla: %d" , key);
}


//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   printf("\nLiberou Tecla: %d" , key);
}


int main(void)
{
    printf("\nDigite um numero binario de 5 digitos (1 digito de cada vez):");
    for(int c = 0;c < 10;c++){
        printf("\n\n Digite o digito %d: ", c);
        scanf("%d", &Num_binario[c]);
    }
    int anterior = 0;
    int anterior_0 = 0;
    for(int c = 0; c< 10; c++){
        if(Num_binario[c] == 0)
            NUm_ajuda[c] = 0;
        else if(Num_binario[c] == 1 && anterior == 0){
            NUm_ajuda[c] = 1;
            anterior = 1;
        }
        else if(Num_binario[c] == 1 && anterior == 1){
            NUm_ajuda[c] = 2;
            anterior = 0;
        }

   }
   for(int c = 0; c< 10; c++){
        if(Num_binario[c] == 1)
            NUm_ajuda_0[c] = 0;
        else if(Num_binario[c] == 0 && anterior == 0){
            NUm_ajuda_0[c] = 1;
            anterior = 1;
        }
        else if(Num_binario[c] == 0 && anterior == 1){
            NUm_ajuda_0[c] = 2;
            anterior = 0;
        }

   }
   int screenWidth = 500, screenHeight = 500; //largura e altura inicial da tela. Alteram com o redimensionamento de tela.
   init(&screenWidth, &screenHeight, "Canvas 2D");
   run();
}
