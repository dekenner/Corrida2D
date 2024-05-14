#include <conio.h>
#include"TAD_ListaSE_HT.h"
#include"jogo.h"

int main(){
	system("color 0F");
    int resposta;

    /* Menu inicial do game:
     *  1 - iniciará um novo jogo;
     *  2 - exbirá o ranking
     *  0 - definirá o fim do jogo;
     */
    printf("Menu inicial!\n\n1-INICIAR\n2-RANKING\n0-SAIR\n");
    do{
        scanf("%d",&resposta);
    }while(resposta<0 || resposta>2);

    switch(resposta){
        case 1:{
            iniciarJogo();
            break;
        }
        case 2:{
            exibirRanking();
            break;
        }
        case 0:{
            exit(0);
        }
    }

    system("PAUSE");
    return 0;
}

