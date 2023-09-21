#include <genesis.h>

char textoTela[23] = "Primeiro Game!";

static void myGamePad(u16 device, u16 changed, u16 state);

static void myInput();

int main(u16 hard)
{
    //Desabilita acesso ao VDP
    SYS_disableInts();

    VDP_init();
    SPR_init();
    VDP_setScreenWidth320();
    VDP_setScreenHeight224();

    //Reabilita acesso ao VDP    
    SYS_enableInts();

    VDP_drawText(textoTela, 10, 13);

    JOY_setEventHandler(&myGamePad);

    while(TRUE)
    {
        myInput();
        SYS_doVBlankProcess();

    }
    return 0;
}

void myGamePad(u16 device, u16 changed, u16 state ){
    if(device == JOY_1){
        
        if(state & BUTTON_START){
            VDP_clearTextLine(5);
            VDP_drawText("Botao START pressionado", 3, 5);
        } else if (changed & BUTTON_START){
            VDP_clearTextLine(5);
            VDP_drawText("Botao START liberado", 3, 5);
        }
        
        if(state & BUTTON_UP){
            VDP_clearTextLine(5);
            VDP_drawText("Botao CIMA pressionado", 3, 5);
        } else if (changed & BUTTON_UP){
            VDP_clearTextLine(5);
            VDP_drawText("Botao CIMA liberado", 3, 5);            
        }
        
        if(state & BUTTON_DOWN){
            VDP_clearTextLine(5);
            VDP_drawText("Botao BAIXO pressionado", 3, 5);

        } else if (changed & BUTTON_DOWN){
            VDP_clearTextLine(5);
            VDP_drawText("Botao BAIXO liberado", 3, 5);            
        }
        
        if(state & BUTTON_LEFT){
            VDP_clearTextLine(5);
            VDP_drawText("Botao ESQUERDA pressionado", 3, 5);

        } else if (changed & BUTTON_LEFT){
            VDP_clearTextLine(5);
            VDP_drawText("Botao ESQUERDA liberado", 3, 5);            
        }
        
        if(state & BUTTON_RIGHT){
            VDP_clearTextLine(5);
            VDP_drawText("Botao DIREITA pressionado", 3, 5);
        } else if (changed & BUTTON_RIGHT){
            VDP_clearTextLine(5);
            VDP_drawText("Botao DIREITA liberado", 3, 5);            
        }
        
        if(state & BUTTON_A){
            VDP_clearTextLine(5);
            VDP_drawText("Botao A pressionado", 3, 5);
        } else if (changed & BUTTON_A){
            VDP_clearTextLine(5);
            VDP_drawText("Botao A liberado", 3, 5);            
        }
        
        if(state & BUTTON_B){
            VDP_clearTextLine(5);
            VDP_drawText("Botao B pressionado", 3, 5);
        } else if (changed & BUTTON_B){
            VDP_clearTextLine(5);
            VDP_drawText("Botao B liberado", 3, 5);            
        }
        
        if(state & BUTTON_C){
            VDP_clearTextLine(5);
            VDP_drawText("Botao C pressionado", 3, 5);
        } else if (changed & BUTTON_C){
            VDP_clearTextLine(5);
            VDP_drawText("Botao C liberado", 3, 5);            
        }
    }
}

static void myInput(){

    u16 value = JOY_readJoypad(JOY_1);

    if(value & BUTTON_START){
        VDP_clearTextLine(5);
        VDP_drawText("Botao START pressionado", 1, 1);
    }

    if(value & BUTTON_UP){
        VDP_clearTextLine(5);
        VDP_drawText("Botao CIMA pressionado", 1, 1);        
    } else if(value & BUTTON_DOWN){
        VDP_clearTextLine(5);
        VDP_drawText("Botao BAIXO pressionado", 1, 1);
    }

    if(value & BUTTON_LEFT){
        VDP_clearTextLine(5);
        VDP_drawText("Botao ESQUERDO pressionado", 1, 1);
    } else if(value & BUTTON_RIGHT){
        VDP_clearTextLine(5);
        VDP_drawText("Botao DIREITO pressionado", 1, 1);
    }

    if(value & BUTTON_A){
        VDP_clearTextLine(5);
        VDP_drawText("Botao A pressionado", 1, 1);
    }
    
    if(value & BUTTON_B){
        VDP_clearTextLine(5);
        VDP_drawText("Botao B pressionado", 1, 1);
    }
    
    if(value & BUTTON_C){
        VDP_clearTextLine(5);
        VDP_drawText("Botao C pressionado", 1, 1);
    }

    VDP_clearTextLine(5);
    VDP_drawText("Nenhum botao pressionado", 1, 1);
}