#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#include "listaConjunto.h"

#ifndef _LISTACONJUNTO_C_
#define _LISTACONJUNTO_C_

struct no
{
	int numero;
	struct no *proximoNo;
};

No *criarNo(int numero){
	
	No *no = (No*)malloc(sizeof(No));
	if(no){
		no->numero = numero;
		no->proximoNo = NULL;
	}
	return no;
}

void uniao(No *Seti_1, No *Seti_2,No **Seti_Uniao)
{
	int tamSeti_1 =  tamanhoLista(Seti_1), i, cont = 0;
	int tamSeti_2 =  tamanhoLista(Seti_2), j;

	No *aux1 = Seti_1;
	No *aux2 = Seti_2;
	No *aux3 = Seti_2;

	while(aux1){
		inserirOrdenado(Seti_Uniao, aux1->numero);//insere os elementos de Seti_1 em Seti_União
		aux1 = aux1->proximoNo;
	}
	aux1 = Seti_1;
		
	for(i = 0; i < tamSeti_1; i++){//fixa o elemento do conjunto 1
		for(j = 0; j < tamSeti_2; j++){//percorre os elemntos do conjunto 2
			if(aux2->numero == aux1->numero){//se repetir incrementa cont
				cont++;
			}	
			aux2 = aux2->proximoNo;
		}
		if(cont == 0){//se contador for 0 não repetiu o numero
			inserirOrdenado(Seti_Uniao, aux3->numero);//insere no Seti_Uniao
		}
		cont = 0;//zera contador para próximo laço
		aux1 = aux1->proximoNo;
		aux2 = Seti_2;//retorna o ponteiro para o início do conjunto
		aux3 = aux3->proximoNo;
	}
}

int inserirOrdenado(No **cabecaLista, int numero){//insere elemento oredenado na lista
	
	if(listaVazia(*cabecaLista)){//se a lista está vazia
		No *aux = criarNo(numero);
		if(aux){//insere no início da lista
			aux->proximoNo = *cabecaLista;
			*cabecaLista = aux;
			return 1;//retorna 1 se sucesso na operação
		}
	}else{
		No *novo = criarNo(numero);
		if (novo){
			No *anterior = NULL;
			No *aux = *cabecaLista;
			while(aux && aux->numero < numero){//percorre a lista até achar o local de inserção
				anterior = aux;
				aux = aux->proximoNo;
			}
			if(anterior == NULL){//tem pelo menos um elemento significa que o elemento, será inserido no início da lista
				if(novo->numero != aux->numero){//retira elemnto repetido do conjunto
					novo->proximoNo = *cabecaLista;
					*cabecaLista = novo;
					return 1;
				}	
			}//elemento será inserido no local ordenado no meio ou no final da lista
				if(!aux && novo->numero != anterior->numero){//retira elemnto repetido do conjunto
					novo->proximoNo = anterior->proximoNo;
					anterior->proximoNo = novo;
					return 1;
				}else if(aux && (novo->numero != aux->numero) && (novo->numero != anterior->numero)){//retira elemnto repetido do conjunto
					novo->proximoNo = anterior->proximoNo;
					anterior->proximoNo = novo;
					return 1;
				}
		}
	}
	return 0;
}

int removeElemento(No **cabecaLista, int numero){//remove elemento da lista
	
	No *anterior = NULL;
	No *aux = *cabecaLista;
	int flag = 0;
	while(aux){//procura o elemento
		if(aux->numero == numero){//se encontrar
			flag = 1;
			break;
		}
		anterior = aux;
		aux = aux->proximoNo;
	}//fim do while
	
	if(flag){//se achou elemento
		if(anterior == NULL){//remove no inicio da lista
			*cabecaLista = aux->proximoNo;
			free(aux);
			return 1;
		}
		//remove elemento encontrado no meio ou no final da lista
		anterior->proximoNo = aux->proximoNo;
		free(aux);
		return 1;
	}
	return 0;
}
	
void intersecao(No *Seti_1, No *Seti_2, No **Seti_Intersecao){
	
	int tamSeti_1 =  tamanhoLista(Seti_1), i;
	int tamSeti_2 =  tamanhoLista(Seti_2), j;
	
	No *aux1 = Seti_1;
	No *aux2 = Seti_2;

	for(j = 0; j < tamSeti_2; j++){//fixa o elemento do conjunto 1
		for(i = 0; i < tamSeti_1;i++){//percorre os elemntos do conjunto 2
			if(aux2->numero == aux1->numero)//se elementos iguais
				inserirOrdenado(Seti_Intersecao, aux2->numero);//insere no Seti_Interseção
		aux1 = aux1->proximoNo;
		}
	aux2 = aux2->proximoNo;
	aux1 = Seti_1;
	}
}

int buscaElemento(No *cabecaLista, int numero)
{
	if(listaVazia(cabecaLista)){
		return 0;
	}
	while(cabecaLista){//percorre a lista para encontrar o elemento
		if(cabecaLista->numero == numero){
			return 1;//se encontrou retorna 1
		}
		cabecaLista = cabecaLista->proximoNo;
	}
	return 0;
}

int conjuntoIgual(No *Seti_1, No *Seti_2){
	
	int tamSeti_1 =  tamanhoLista(Seti_1), i;
	int tamSeti_2 =  tamanhoLista(Seti_2), j;
	int cont = 0;
	
	No *aux1 = Seti_1;
	No *aux2 = Seti_2;

	if((aux1 && aux2) && (tamSeti_1 == tamSeti_2)){//verifica se são válidos e possuem o mesmo tamanho
		for(j = 0; j < tamSeti_2; j++){//fixa o elemento do conjunto 1
			for(i = 0; i < tamSeti_1;i++){//percorre os elemntos do conjunto 2
				if(aux2->numero == aux1->numero){//se elementos iguais
					cont++;//incrementa contador
				}
			aux1 = aux1->proximoNo;
			}
		aux2 = aux2->proximoNo;
		aux1 = Seti_1;
		}
		if(cont == tamSeti_1)//se verdade conjuntos são iguais
			return 1;
	}
	return 0;
}

int tamanhoLista(No *cabecaLista){//calcula o tamanho da lista
	
	int tamanho = 0;
	while(cabecaLista){//enquanto existirn elemento na lista
		tamanho ++;//incrementa o tamanho
		cabecaLista = cabecaLista->proximoNo;
	}
	return tamanho;
}

int listaVazia(No *cabecaLista){//verifica se a lista é vazia
	return (cabecaLista == NULL);
}

void imprimeLista(No *cabecaLista, char *mensagem){//imprime a lista
	
	printf("%s", mensagem);
	while(cabecaLista){//percorre a lista
		printf("%d -> ", cabecaLista->numero);//imprime a lista
		cabecaLista = cabecaLista->proximoNo;
	}
	printf(" NULL\n\n");
}

int validarResp(char *mensagem, int padrao) {//função para confirmar comando pelo usuário
   int op;
   char cPadrao = (padrao ? 's' : 'n');

   do {
      printf("\n%s [S ou N] %c", mensagem, cPadrao);
      op = getch();
      printf("\n" );
   } while (op != 's' && op != 'S' && op != 'n' && op != 'N' && op != 13);

    if(op == 13)
        return padrao;

   return ((op == 's' || op == 'S') ? 1 : 0);
}

#endif
