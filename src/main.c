#include <genesis.h>

char textoTela[] = "Primeiro Game!";
char* mensagens[] = {
    "Botao START", "Botao CIMA", "Botao BAIXO", "Botao ESQUERDA",
    "Botao DIREITA", "Botao A", "Botao B", "Botao C"
};

#define TEXTO_Y 5
#define TEXTO_X 3

static void myGamePad(u16 device, u16 changed, u16 state);
static void mostrarMensagem(const char* botao, bool pressionado);

int main(u16 hard)
{
    SYS_disableInts();

    VDP_init();
    SPR_init();
    VDP_setScreenWidth320();
    VDP_setScreenHeight224();

    SYS_enableInts();

    VDP_drawText(textoTela, 10, 13);

    JOY_setEventHandler(&myGamePad);

    while(TRUE)
    {
        SYS_doVBlankProcess(); // Nenhum input direto aqui (apenas via evento)
    }

    return 0;
}

static void myGamePad(u16 device, u16 changed, u16 state)
{
    if (device != JOY_1) return;

    // Lista de botões e mensagens associadas
    const u16 botoes[] = {
        BUTTON_START, BUTTON_UP, BUTTON_DOWN,
        BUTTON_LEFT, BUTTON_RIGHT,
        BUTTON_A, BUTTON_B, BUTTON_C
    };

    const int count = sizeof(botoes) / sizeof(botoes[0]);
    for (int i = 0; i < count; i++)
    {
        if (state & botoes[i])
        {
            mostrarMensagem(mensagens[i], TRUE);
            return;
        }
        else if (changed & botoes[i])
        {
            mostrarMensagem(mensagens[i], FALSE);
            return;
        }
    }

    // Nenhum botão pressionado
    VDP_clearTextLine(TEXTO_Y);
}

static void mostrarMensagem(const char* botao, bool pressionado)
{
    char buffer[40];
    VDP_clearTextLine(TEXTO_Y);

    if (pressionado)
        sprintf(buffer, "%s pressionado", botao);
    else
        sprintf(buffer, "%s liberado", botao);

    VDP_drawText(buffer, TEXTO_X, TEXTO_Y);
}
