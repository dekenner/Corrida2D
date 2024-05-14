#include"TAD_ListaSE_HT.h"

/*
 * Fun��o para gerar obst�culos e inseri-los nas faixa.
 * OBS.: Essa fun��o sera chamada a partir de um controle de
 * probabilidade atrav�s da fun��o aleat�rio.
 */
void gerarObstaculo(Lista*, Lista*, Lista*);

/* Fun��o para gerar obst�culos a partir de um n�mero aleat�rio
     * recebido como par�metro tendo em vista a diversidade de at�
     * 3 obst�culos diferentes.
     */
char decidirObstaculo();

/*
 * Esta fun�ao retorna TRUE se o n� seguinte ao ve�culo contiver um objeto(obst�culo).
 */
Boolean bateu(Lista);

/*
 * Esta funcao � responsavel por receber o comando do teclado e retorna-lo apos um tempo determinado
 */
char lerComando(int);

/*Fun��o aleat�rio*/
int aleatorio();

/*
 * Funcao responsavel por adicionar um elemento ao final da lista armazenando as informacoes necessarias.
 */
void aumentarPista(Lista*, Info, Lista*, Info, Lista*, Info);

/*
 * Funcao respons�vel por identificar qual � a faixa onde o carro se encontra, fazer a leitura do movimento,
 * verificar se existem obstaculos colidindo, remove o inicio de todas as faixas atualizando a posicao do
 * ve�culo e insere um novo n� no final das faixas de acordo com a aleatoriedade dos obstaculos, imprimindo
 * as pistas.
 */
void andarPista(Lista*, Lista*, Lista*, int, int);

/*
 * Metodos para retornar a posi��o do carrinho, atravez das faixas recebidas como par�metro!
 */
int posicaoCarrinho(Lista, Lista, Lista);

/*
 * M�todo para mudar a cor de fundo do console! 
 */
void mudarBgcollor();

/*
 * M�todo para verificar se o jogador bateu um recorde para entao 
 *  chamar a fun��o criarRanking!
 */
Boolean bateuRecorde(int);

/*
 * Fun��o para imprimir as 3 pistas do jogo!
 */
void imprimirPista(Lista, Lista, Lista, int);

/*
 * M�todo para criar um arquivo no diret�rio do jogo caso ele ainda nao esteja criado! 
 */
void criarRanking(int);

/*
 * M�todo para ler um arquivo no diret�rio do jogo contendo o ranking! 
 */
void lerRanking();

/*
 [*refLista1]-------------------------#---fim
 [*refLista2]-->>-------------&-----------fim
 [*refLista3]------T----------------------fim

 legenda:
 >> Carro
*/
