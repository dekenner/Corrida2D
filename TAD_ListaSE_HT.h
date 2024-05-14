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
 * Método para alocar na memória o espaço da estrutura Node,
 * atribuir o dado à variável alocada e retornar um ponteiro
 * para o endereço de memória reservada.
 */
Node* criarNode(Info dado);

/*
 * Método para iniciar a lista atribuindo-se NULL para ambos
 * os ponteiros (head e tail).
 */
void lst_init(Lista *refLista);

/*
 * Método para verificar se a lista está vazia ou não, retornando
 * TRUE para lista vazia e FALSE para lista não-vazia, analisando
 * o ponteiro recebido como parâmetro.
 */
Boolean lst_isEmpty(Lista lista);

/*
 * Método para verificar se a lista está cheia ou não, retornando
 * FALSE pois aloca-se memória dinâmicamente.
 */
Boolean lst_isFull(Lista lista);

/*
 * Método para adicionar o elemento no final da lista.
 *   1º caso:
 *      -Lista vazia. Neste caso, os campos head e tail apontam
 *       para o novo elemento e retorna-se TRUE;
 *
 *   2º caso:
 *      -Lista não-vazia. Neste caso, o ponteiro next do campo
 *       tail passa a apontar para o novo elemento, e o campo tail
 *       passa a apontar para o novo. E, retorna-se TRUE;
 *
 * OBS.: Se a referência para a lista for nula, a função retorna FALSE;
 */
Boolean lst_addLast(Lista *refLista, Info dado);

/*
 * Método para remover o elemento no inicio da lista.
 *
 *   1º caso:
 *      -Lista vazia. Neste caso, a função retorna FALSE;
 *
 *   2º caso:
 *      -Lista não-vazia. Neste caso, usaremos um ponteiro auxiliar
 *       para facilitar na remoção do primeiro elemento da lista,
 *       que aponta para o campo head. Em seguida
 *       o campo head passa a apontar para o segundo elemento da lista
 *       e libera-se o auxiliar da memória e retorna TRUE;
 *
 * OBS.: Se a referência para a lista for nula, a função retorna FALSE;
 */
void lst_removeFirst(Lista *refLista);

/*
 * Método para verificar a info da segunda posição da lista, retornando
 * 1 caso seja diferente da chave e 0 para igual a chave.
 */
int lst_viewNext(Lista lista,Info key);

/*
 * Método para reconfigurar um elemento da lista.
 *   1º caso:
 *      -Lista vazia. Neste caso, a função retorna FALSE;
 *
 *   2º caso:
 *      -Lista não-vazia. Neste caso, configuramos 
 *       info do campo head da lista e retorna-se TRUE;
 *
 * OBS.: Se a referência para a lista for nula, a função retorna FALSE;
 */
Boolean lst_setData(Lista *refLista,Info dado);

/*
 * Método para reconfigurar um elemento da lista.
 *   1º caso:
 *      -Lista vazia. Neste caso, a função retorna FALSE;
 *
 *   2º caso:
 *      -Lista não-vazia. Neste caso, verificamos a
 *       info do campo head da lista e caso ela for
 *		 igual ao carro (>) retorna-se TRUE;
 *
 * OBS.: Se a referência para a lista for nula, a função retorna FALSE;
 */
Boolean lst_viewCar(Lista lista);

/*
 * Metodos para retornar a faixa que está o carrinho, atravez das faixas recebidas como parâmetro!
 */
Lista pistaCarro(Lista, Lista, Lista);

/*
 * Método para caminhar e imprimir uma lista
 */
void caminhar(Lista faixa);
