#include "TAD_ListaSE_HT.h"

struct node{
	Info info[1];
	struct node* prox;
};

struct lista{
	struct node* head;
	struct node* tail;
};

void lst_init(Lista *refLista){
	Lista lstAuxiliar;

    lstAuxiliar = malloc(sizeof(struct lista));

    if(lstAuxiliar != NULL){
    	*refLista = lstAuxiliar;
	}

	(*refLista)->head = NULL;
	(*refLista)->tail = NULL;
}

Node* criarNode(Info dado){
	Node* ptr;

	ptr = malloc(sizeof(struct node));
	if(ptr != NULL){
		ptr->info[0] = dado;
		ptr->prox = NULL;
	}

	return ptr;
}

Boolean lst_isFull(Lista lista){
	Node* ptr;
	ptr = malloc(sizeof(struct node));
	return (ptr==NULL)?TRUE:FALSE;
}

Boolean lst_isEmpty(Lista lista){
	Boolean estaVazia;
	estaVazia = FALSE;
	if(lista->head==NULL){
		estaVazia = TRUE;
	}
	return estaVazia;
}

Boolean lst_addLast(Lista *refLista, Info dado){
	Node* ajudante;
	Node* novo;
	Boolean deuCerto;

	novo = criarNode(dado);
	deuCerto = FALSE;
	if(novo != NULL){
		if(*refLista != NULL){
			if(lst_isEmpty(*refLista)){
			    (*refLista)->head = novo;
			}else{
				ajudante = ((*refLista)->tail);
                ajudante->prox = novo;
			}
			(*refLista)->tail = novo;
			deuCerto = TRUE;
		}
	}
	return deuCerto;
}

void lst_removeFirst(Lista *refLista){
	Node* ajudante;
	if(*refLista != NULL){
		if(!lst_isEmpty(*refLista)){
			ajudante = (*refLista)->head;
			(*refLista)->head = ajudante->prox;
			if(ajudante == (*refLista)->tail){
				(*refLista)->tail = NULL;
			}
			free(ajudante);
		}
	}
}

int lst_viewNext(Lista lista,Info key){
    int indice=0;
    Node *ajudante;
    if(!lst_isEmpty(lista)){
        ajudante = ((lista)->head)->prox;
        if(ajudante->info[0] != key){
            indice=1;
        }
    }
    return indice;
}
Boolean lst_setData(Lista *refLista,Info dado){
    Boolean deuCerto = FALSE;
    Node *ajudante;

    if(!lst_isEmpty(*refLista)){
        ajudante=(*refLista)->head;
        ajudante->info[0] = dado;
        deuCerto = TRUE;
    }

    return deuCerto;
}

Boolean lst_viewCar(Lista lista){
    Boolean achou = FALSE;

    if((lista->head)->info[0] == '>'){
        achou = TRUE;
    }
    return achou;
}

Lista pistaCarro(Lista lista1, Lista lista2, Lista lista3){
	Lista carro;
	int faixa = posicaoCarrinho(lista1, lista2, lista3);

	if(faixa == 1){
		carro = lista1;
	}else{
		if(faixa == 2){
			carro = lista2;
		}else{
			carro = lista3;
		}
	}
	return carro;
}

void caminhar(Lista faixa){
	Node *caminhante;
    caminhante = (faixa)->head;
    while(caminhante->prox != NULL){
    	printf("%c",caminhante->info[0]);
		caminhante = caminhante->prox;	
	}  
}
