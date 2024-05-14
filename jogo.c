#include "jogo.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
#include<conio.h>

#include<time.h>

void iniciarJogo(){
    Lista pista1;
    Lista pista2;
    Lista pista3;

	int pontos=0;
	int dif=100;

    lst_init(&pista1);
    lst_init(&pista2);
    lst_init(&pista3);

	aumentarPista(&pista1, ' ', &pista2, '>', &pista3, ' ');

	int i;
    for(i=0; i<30; i++){
        aumentarPista(&pista1, ' ',&pista2, ' ',&pista3, ' ');
    }
    imprimirPista(pista1,pista2,pista3,pontos);
    while(!bateu(pistaCarro(pista1, pista2, pista3))){
        andarPista(&pista1,&pista2,&pista3,pontos,dif);
        pontos++;
        if(pontos%100==0){
        	mudarBgcollor();
            dif = dif*0.90;
        }
    }
    pontos--;
    printf("\a\n------------GAME OVER!------------\n");
    printf("Pontuacao acumulada: %d", pontos);
    if(bateuRecorde(pontos)){
    	criarRanking(pontos);
    	printf("Parabens seu nome foi inserido no ranking!"); 
	}
	printf("\nAguarde 5s para voltar ao menu inicial.\n");
    Sleep(5000);

    system("cls");
    main();
}

void exibirRanking(){
	system("cls");
	
    lerRanking();
    printf("\nAguarde 5s para voltar ao menu inicial.\n");
    Sleep(5000);

    system("cls");
    main();
}

void gerarObstaculo(Lista *refLista1, Lista *refLista2, Lista *refLista3){
    int n = aleatorio();

    switch(n){
        case 1: {
            aumentarPista(&(*refLista1), decidirObstaculo(),&(*refLista2), ' ',&(*refLista3), ' ');
            break;
         }
         case 2: {
            aumentarPista(&(*refLista1), ' ',&(*refLista2), decidirObstaculo(),&(*refLista3), ' ');
            break;
         }
         case 3: {
            aumentarPista(&(*refLista1), ' ',&(*refLista2), ' ',&(*refLista3), decidirObstaculo());
            break;
         }
         default:{
            aumentarPista(&(*refLista1), ' ',&(*refLista2), ' ',&(*refLista3), ' ');
            break;
         }
    }
}

char decidirObstaculo(){
     char obstaculo = ' ';
     int n = 1+(rand() % 4);
     switch(n){
         case 1: {
             obstaculo = '%';
            break;
         }
         case 2: {
            obstaculo = '#';
            break;
         }
         case 3: {
            obstaculo = '&';
            break;
         }
         default:{
            obstaculo = '@';
            break;
         }
     }
     return obstaculo;
}

Boolean bateu(Lista listaCarro){
    Boolean bateu = FALSE;
    int n=lst_viewNext(listaCarro,' ');

    if(n==1){
        bateu = TRUE;
    }
    return bateu;
}

char lerComando(int dificult){
    char letra = ' ';
    int countdown=0;
    while(countdown++ <= dificult){  //Tempo para receber um clique, e também ajusta a velocidade do jogo
    if(letra=kbhit()){
    	letra = getch();
        break;               //Se pressionar uma tecla sai do loop
	}
    Sleep(1);
    countdown++;                //Se não aguarda 1ms e repete
    }
    letra = toupper(letra);// Torna maiúsculo a letra digitada
    if(letra == 'W' || letra == 'S'){
        return letra;
    }
    return 'D';
}

int aleatorio(){
    return 1+(rand() % 20);
}

void aumentarPista(Lista *refLista1, Info dado1, Lista *refLista2, Info dado2, Lista *refLista3, Info dado3){
    lst_addLast(&(*refLista1), dado1);
    lst_addLast(&(*refLista2), dado2);
    lst_addLast(&(*refLista3), dado3);
}

int posicaoCarrinho(Lista lista1, Lista lista2, Lista lista3){
	int posicao=0;

	if(lst_viewCar(lista1)){
        posicao =  1;
    }else{
        if(lst_viewCar(lista2)){
            posicao = 2;
        }else{
            posicao = 3;
        }
    }
    return posicao;
}

void andarPista(Lista *refLista1, Lista *refLista2, Lista *refLista3, int pont, int dif){
    int pos = posicaoCarrinho(*refLista1, *refLista2, *refLista3);

    char comando = lerComando(dif);

    lst_removeFirst(&(*refLista1));
    lst_removeFirst(&(*refLista2));
    lst_removeFirst(&(*refLista3));

    if(comando == 'D'){
        if(pos == 1){
        		lst_setData(&(*refLista1),'>');
			}else{
				if(pos == 2){
					lst_setData(&(*refLista2),'>');
				}else{
					lst_setData(&(*refLista3),'>');
				}
			}
    }else{
        if(comando == 'W'){
            /*Carro anda para cima independente dele estar na primeira lista*/
        	if(pos == 1){
        		lst_setData(&(*refLista3),'>');
			}else{
				if(pos == 2){
					lst_setData(&(*refLista1),'>');
				}else{
					lst_setData(&(*refLista2),'>');
				}
			}
		}else{
            /*Carro anda para baixo independente dele estar na última lista*/
            if(pos == 1){
        		lst_setData(&(*refLista2),'>');
			}else{
				if(pos == 2){
					lst_setData(&(*refLista3),'>');
				}else{
					lst_setData(&(*refLista1),'>');
				}
			}
        }
    }

    gerarObstaculo(&(*refLista1),&(*refLista2),&(*refLista3));
    imprimirPista(*refLista1,*refLista2,*refLista3,pont);
}

void mudarBgcollor(){
	int n = 1+(rand() % 4);
     switch(n){
         case 1: {
            system ("color 0B");
            break;
         }
         case 2: {
            system ("color 0C"); 
            break;
         }
         case 3: {
            system ("color 0D"); 
            break;
         }
         default:{
            system ("color 0B");
            break;
         }
     }
}

Boolean bateuRecorde(int pontos){
	Boolean novoRecorde = TRUE;
	FILE *file;

	file = fopen64("recorde.txt","r");

	if(file != NULL){
		char nome1[20], nome2[20], nome3[20], nome4[20], nome5[20];
		int p1, p2, p3, p4, p5;
		fscanf(file, "%s %d", &nome1, &p1);
		fscanf(file, "%s %d", &nome2, &p2);
		fscanf(file, "%s %d", &nome3, &p3);
		fscanf(file, "%s %d", &nome4, &p4);
		fscanf(file, "%s %d", &nome5, &p5);
		if(pontos < p5){
			novoRecorde = FALSE;
		}				
	}
	fclose(file);
	
	return novoRecorde;
}

void imprimirPista(Lista faixa1, Lista faixa2, Lista faixa3, int pont){
    system("cls");
    if(pont%2==0){
        printf("\n== == == == == == == == == == ==\n");
    } else {
        printf("\n= == == == == == == == == == == \n");
    }

    caminhar(faixa1);
    if(pont%2==0){
        printf("\n -  -  -  -  -  -  -  -  -  -  -\n");
    } else {
        printf("\n-  -  -  -  -  -  -  -  -  -  - \n");
    }
    caminhar(faixa2);
    if(pont%2==0){
        printf("\n -  -  -  -  -  -  -  -  -  -  -\n");
    } else {
        printf("\n-  -  -  -  -  -  -  -  -  -  - \n");
    }
    caminhar(faixa3);
    if(pont%2==0){
        printf("\n== == == == == == == == == == ==\n");
    } else {
        printf("\n= == == == == == == == == == == \n");
    }
    printf("%d", pont);
}

void criarRanking(int recorde){
    FILE *file;
    char nome[20];
	
	file = fopen64("recorde.txt","r");

    printf("\nInforme seu nome: ");
    scanf("%s", &nome);

	if(file == NULL){
        file = fopen64("recorde.txt","w");
		fprintf(file,"%s %d aaa 0 sss 0 aaa 0 sss 0", nome, recorde);
		printf("Arquivo recorde.txt criado com sucesso!");
	}else{
		char nome1[20], nome2[20], nome3[20], nome4[20];
		int p1, p2, p3, p4;
		fscanf(file, "%s %d", &nome1, &p1);
		fscanf(file, "%s %d", &nome2, &p2);
		fscanf(file, "%s %d", &nome3, &p3);
		fscanf(file, "%s %d", &nome4, &p4);
		if(recorde < p4){
			file = fopen64("recorde.txt", "a");
			fprintf(file, " %s %d", nome, recorde);	
		}else{
			file = fopen64("recorde.txt","w");
			if(recorde > p1){
				fprintf(file, "%s %d %s %d %s %d %s %d %s %d", nome, recorde, nome1, p1, nome2, p2, nome3, p3, nome4, p4);
			}else{
				if(recorde > p2){
					fprintf(file, "%s %d %s %d %s %d %s %d %s %d", nome1, p1,  nome, recorde, nome2, p2, nome3, p3, nome4, p4);
				}else{
					if(recorde > p3){
						fprintf(file, "%s %d %s %d %s %d %s %d %s %d", nome1, p1, nome2, p2, nome, recorde, nome3, p3, nome4, p4);	
					}else{
						if(recorde > p4){
							fprintf(file, "%s %d %s %d %s %d %s %d %s %d", nome1, p1, nome2, p2, nome3, p3, nome, recorde, nome4, p4);	 
						}
					}
				}
			}
		}	
	}
		
	fclose(file);
}

void lerRanking(){
    FILE *file;

	file = fopen64("recorde.txt","r");

	if(file != NULL){
		char nome1[20], nome2[20], nome3[20], nome4[20], nome5[20];
		int contador = 0;
		int p1, p2, p3, p4, p5;
		fscanf(file, "%s %d", &nome1, &p1);
		fscanf(file, "%s %d", &nome2, &p2);
		fscanf(file, "%s %d", &nome3, &p3);
		fscanf(file, "%s %d", &nome4, &p4);
		fscanf(file, "%s %d", &nome5, &p5);		
		printf("TOP 5 - Ranking\n%s\t%d\n%s\t%d\n%s\t%d\n%s\t%d\n%s\t%d\n", nome1, p1, nome2, p2, nome3, p3, nome4, p4, nome5, p5);
	}else{
		printf("ERRO - O arquivo nao existe!\n");
	}
	fclose(file);
}
