#include <stdlib.h>
#include<windows.h>
#include<string.h>
#include<stdio.h>

#define TRUE 1
#define FALSE 0

typedef int Boolean;

typedef struct node Node;
typedef struct lista* Lista;
typedef char Info;

/*
 * M�todo para alocar na mem�ria o espa�o da estrutura Node,
 * atribuir o dado � vari�vel alocada e retornar um ponteiro
 * para o endere�o de mem�ria reservada.
 */
Node* criarNode(Info dado);

/*
 * M�todo para iniciar a lista atribuindo-se NULL para ambos
 * os ponteiros (head e tail).
 */
void lst_init(Lista *refLista);

/*
 * M�todo para verificar se a lista est� vazia ou n�o, retornando
 * TRUE para lista vazia e FALSE para lista n�o-vazia, analisando
 * o ponteiro recebido como par�metro.
 */
Boolean lst_isEmpty(Lista lista);

/*
 * M�todo para verificar se a lista est� cheia ou n�o, retornando
 * FALSE pois aloca-se mem�ria din�micamente.
 */
Boolean lst_isFull(Lista lista);

/*
 * M�todo para adicionar o elemento no final da lista.
 *   1� caso:
 *      -Lista vazia. Neste caso, os campos head e tail apontam
 *       para o novo elemento e retorna-se TRUE;
 *
 *   2� caso:
 *      -Lista n�o-vazia. Neste caso, o ponteiro next do campo
 *       tail passa a apontar para o novo elemento, e o campo tail
 *       passa a apontar para o novo. E, retorna-se TRUE;
 *
 * OBS.: Se a refer�ncia para a lista for nula, a fun��o retorna FALSE;
 */
Boolean lst_addLast(Lista *refLista, Info dado);

/*
 * M�todo para remover o elemento no inicio da lista.
 *
 *   1� caso:
 *      -Lista vazia. Neste caso, a fun��o retorna FALSE;
 *
 *   2� caso:
 *      -Lista n�o-vazia. Neste caso, usaremos um ponteiro auxiliar
 *       para facilitar na remo��o do primeiro elemento da lista,
 *       que aponta para o campo head. Em seguida
 *       o campo head passa a apontar para o segundo elemento da lista
 *       e libera-se o auxiliar da mem�ria e retorna TRUE;
 *
 * OBS.: Se a refer�ncia para a lista for nula, a fun��o retorna FALSE;
 */
void lst_removeFirst(Lista *refLista);

/*
 * M�todo para verificar a info da segunda posi��o da lista, retornando
 * 1 caso seja diferente da chave e 0 para igual a chave.
 */
int lst_viewNext(Lista lista,Info key);

/*
 * M�todo para reconfigurar um elemento da lista.
 *   1� caso:
 *      -Lista vazia. Neste caso, a fun��o retorna FALSE;
 *
 *   2� caso:
 *      -Lista n�o-vazia. Neste caso, configuramos 
 *       info do campo head da lista e retorna-se TRUE;
 *
 * OBS.: Se a refer�ncia para a lista for nula, a fun��o retorna FALSE;
 */
Boolean lst_setData(Lista *refLista,Info dado);

/*
 * M�todo para reconfigurar um elemento da lista.
 *   1� caso:
 *      -Lista vazia. Neste caso, a fun��o retorna FALSE;
 *
 *   2� caso:
 *      -Lista n�o-vazia. Neste caso, verificamos a
 *       info do campo head da lista e caso ela for
 *		 igual ao carro (>) retorna-se TRUE;
 *
 * OBS.: Se a refer�ncia para a lista for nula, a fun��o retorna FALSE;
 */
Boolean lst_viewCar(Lista lista);

/*
 * Metodos para retornar a faixa que est� o carrinho, atravez das faixas recebidas como par�metro!
 */
Lista pistaCarro(Lista, Lista, Lista);

/*
 * M�todo para caminhar e imprimir uma lista
 */
void caminhar(Lista faixa);
