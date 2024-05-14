#include"TAD_ListaSE_HT.h"

/*
 * Função para gerar obstáculos e inseri-los nas faixa.
 * OBS.: Essa função sera chamada a partir de um controle de
 * probabilidade através da função aleatório.
 */
void gerarObstaculo(Lista*, Lista*, Lista*);

/* Função para gerar obstáculos a partir de um número aleatório
     * recebido como parâmetro tendo em vista a diversidade de até
     * 3 obstáculos diferentes.
     */
char decidirObstaculo();

/*
 * Esta funçao retorna TRUE se o nó seguinte ao veículo contiver um objeto(obstáculo).
 */
Boolean bateu(Lista);

/*
 * Esta funcao é responsavel por receber o comando do teclado e retorna-lo apos um tempo determinado
 */
char lerComando(int);

/*Função aleatório*/
int aleatorio();

/*
 * Funcao responsavel por adicionar um elemento ao final da lista armazenando as informacoes necessarias.
 */
void aumentarPista(Lista*, Info, Lista*, Info, Lista*, Info);

/*
 * Funcao responsável por identificar qual é a faixa onde o carro se encontra, fazer a leitura do movimento,
 * verificar se existem obstaculos colidindo, remove o inicio de todas as faixas atualizando a posicao do
 * veículo e insere um novo nó no final das faixas de acordo com a aleatoriedade dos obstaculos, imprimindo
 * as pistas.
 */
void andarPista(Lista*, Lista*, Lista*, int, int);

/*
 * Metodos para retornar a posição do carrinho, atravez das faixas recebidas como parâmetro!
 */
int posicaoCarrinho(Lista, Lista, Lista);

/*
 * Método para mudar a cor de fundo do console! 
 */
void mudarBgcollor();

/*
 * Método para verificar se o jogador bateu um recorde para entao 
 *  chamar a função criarRanking!
 */
Boolean bateuRecorde(int);

/*
 * Função para imprimir as 3 pistas do jogo!
 */
void imprimirPista(Lista, Lista, Lista, int);

/*
 * Método para criar um arquivo no diretório do jogo caso ele ainda nao esteja criado! 
 */
void criarRanking(int);

/*
 * Método para ler um arquivo no diretório do jogo contendo o ranking! 
 */
void lerRanking();

/*
 [*refLista1]-------------------------#---fim
 [*refLista2]-->>-------------&-----------fim
 [*refLista3]------T----------------------fim

 legenda:
 >> Carro
*/
