#ifndef _LISTACONJUNTO_H_
#define _LISTACONJUNTO_H_

//declaração dos protótipos das funções e do tipo de dado
typedef struct no No;

No *criarNo(int numero);
void uniao(No *seti_1, No *Seti_2, No **Seti_Uniao);
int inserir(No **cabecaLista, int numero);
int removeElemento(No **cabecaLista, int numero);
void intersecao(No *Seti_1, No *Seti_2, No **Seti_Intersecao);
int buscaElemento(No *cabecaLista, int numero);
int conjuntoIgual(No *Seti_1, No *Seti_2);
int tamanhoLista(No *cabecaLista);
int listaVazia(No *cabecaLista);
void imprimeLista(No *cabecaLista, char *mensagem);
int validarResp(char *mensagem, int padrao);

#endif

