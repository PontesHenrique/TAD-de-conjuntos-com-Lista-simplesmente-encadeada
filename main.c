/*
	UFPB - Universidade Federal da Paraíba
	
	Exercício de fixação da disciplina de Estrutura de dados
	TAD sobre conjunto com lista simplesmente encadeada
	Professor: Leandro
	Aluno: Luis Henrique Pontes
	Mátricula: 20180163467
*/

#include "listaConjunto.c"

int main(void)
{
	int numero = 0, i, numSeti_1, numSeti_2, remove;
	int continuar;
	srand(time(NULL));
	
	setlocale(LC_ALL, "Portuguese");
	
	No *Seti_1 = NULL;
	No *Seti_2 = NULL;
	No *Seti_Uniao = NULL;
	No *Seti_Intersecao = NULL; 
	
	char opcao_char = ' ';
	int opcao = opcao_char;
	
    while(opcao){
        printf(" *** Lista Encadeada ***\n\n");
        printf("1) União de dois Seti\n");//49
        printf("2) Inserção de um elemento em um Seti\n");//50
        printf("3) Remoção de um elemento em um Seti\n");//51
        printf("4) Intersecção de dois Seti\n");//52
        printf("5) Testa se um valor pertence a um Seti\n");//53
        printf("6) Testa se dois Seti são iguais\n");//54
        printf("7) Retorna o Tamanho de um Seti\n");//55
        printf("8) Testa se o Seti é vazio\n");//56
        printf("0) Encerrar\n");//48

        do{
        	fflush(stdin);
            printf("Opção:");
            scanf("%c", &opcao_char);
            fflush(stdin);
            opcao = opcao_char;
            if(opcao == 48){
            	free(Seti_1);
            	free(Seti_2);
				printf("\nMemória liberada com sucesso");
            	return EXIT_SUCCESS;
			}
        }while((opcao < 49 || opcao > 56));
  
        fflush(stdin);
        system("CLS");//limpa a tela

        switch(opcao){
            case 49:
            	imprimeLista(Seti_1, "Conjunto Seti_1: ");
    			imprimeLista(Seti_2, "Conjunto Seti_2: ");
    			
    			if(tamanhoLista(Seti_1) == 0){
    				imprimeLista(Seti_2, "Conjunto Seti_Uniao: ");	
				}
				if(tamanhoLista(Seti_2) == 0){
    				imprimeLista(Seti_1, "Conjunto Seti_Uniao: ");	
				}
				if(tamanhoLista(Seti_1) == 0 && tamanhoLista(Seti_2) == 0){
					printf("Os dois conjuntos são vazios a união é o conjunto vazio!!!\n");
				}
            	if(tamanhoLista(Seti_1) != 0 && tamanhoLista(Seti_2) != 0){
            		uniao(Seti_1, Seti_2, &Seti_Uniao);
            		printf("União realizada com sucesso!!!\n\n");
            		imprimeLista(Seti_Uniao, "Conjunto Seti_Uniao: ");
				}
            break;
            
            case 50:
            	
				//cria dosi Seti's aletórios
            	printf("Digite o número de elementos do Seti_1: ");
            	scanf("%d", &numSeti_1);
            	for(i = 0; i < numSeti_1; i++){
            		inserirOrdenado(&Seti_1, rand() % 100);
				}
				imprimeLista(Seti_1, "Conjunto Seti_1: ");
				
            	printf("Digite o número de elementos do Seti_2: ");
            	scanf("%d", &numSeti_2);
				for(i = 0; i < numSeti_2; i++){
            		inserirOrdenado(&Seti_2, rand() % 100);
				}
                imprimeLista(Seti_2, "Conjunto Seti_2: ");
            break;
            
            case 51:
            	continuar = validarResp("Confirma Remover elemento?", 1);//Retorna 1 se a resposta for verdadeira
    			system("CLS");
    			imprimeLista(Seti_1, "Conjunto Seti_1: ");
    			imprimeLista(Seti_2, "Conjunto Seti_2: ");
    			if(continuar){
    				printf("1) Remover do Seti_1: \n2) Remover do Seti_2: \nopção: ");
	            	scanf("%d", &remove);
    				switch(remove){
			            case 1:
			            	printf("Digite o elemento para remover: ");
	            			scanf("%d", &remove);
			            	if(!removeElemento(&Seti_1, remove)){
			                	printf("ID %d não pertence a lista\n");
							}else{
								printf("Elemento excluido com sucesso!!!\n");
			                	imprimeLista(Seti_1, "Seti_1: ");
							}
			            break;
			            
			            case 2:
			            	printf("Digite o elemento para remover: ");
	            			scanf("%d", &remove);
			            	if(!removeElemento(&Seti_2, remove)){
			                	printf("ID %d não pertence a lista\n");
							}else{
								printf("Elemento excluido com sucesso!!!\n");
			                	imprimeLista(Seti_2, "Seti_2: ");
							}
			            break;
			   		}

				}
            break;
            
            case 52:
            
            	imprimeLista(Seti_1, "Conjunto Seti_1: ");
    			imprimeLista(Seti_2, "Conjunto Seti_2: ");
    			
            	if(tamanhoLista(Seti_1) == 0){
    				imprimeLista(Seti_2, "Conjunto Seti_Intersecao: ");	
				}
				if(tamanhoLista(Seti_2) == 0){
    				imprimeLista(Seti_1, "Conjunto Seti_Intersecao: ");	
				}
				if(tamanhoLista(Seti_1) == 0 && tamanhoLista(Seti_2) == 0){
					printf("Os dois conjuntos são vazios a Intersecao é o conjunto vazio!!!\n");
				}
            	if(tamanhoLista(Seti_1) != 0 && tamanhoLista(Seti_2) != 0){
            		intersecao(Seti_1, Seti_2, &Seti_Intersecao);
            		printf("Intersecao realizada com sucesso!!!\n\n");
            		imprimeLista(Seti_Intersecao, "Conjunto Seti_Intersecao: ");
				}
            break;
            
            case 53:
    			printf("\n1) Busca do Seti_1: \n2) Busca do Seti_2: \nopção: ");
	           	scanf("%d", &remove);
    			switch(remove){
			        case 1:
			            printf("Digite o elemento para remover: ");
	            		scanf("%d", &remove);
			            if(!buscaElemento(Seti_1, remove)){
			                printf("O numero %d não pertence a lista\n", remove);
						}else{
							printf("O numero %d pertence a lista\n", remove);
						}
			        break;
			            
			        case 2:
			            printf("Digite o elemento para remover: ");
	            		scanf("%d", &remove);
			            if(!buscaElemento(Seti_2, remove)){
			                printf("O numero %d não pertence a lista\n", remove);
						}else{
							printf("O numero %d pertence a lista\n", remove);
						}
			        break;
			   	}
            	
            break;
            
            case 54:
            	if(conjuntoIgual(Seti_1, Seti_2))
            		printf("Conjuntos são iguais!!!\n");
            	printf("Os Conjuntos não são iguais!!!\n");
				
            break;
            
            case 55:
            	printf("O Seti_1 tem %d elementos\n", tamanhoLista(Seti_1));
				printf("O Seti_2 tem %d elementos\n", tamanhoLista(Seti_2));
            break;
          
            case 56:
            	
            	if(listaVazia(Seti_1))
            		printf("Conjunto Seti_1 é um conjunto vazio\n\n");
            	if(listaVazia(Seti_2))
            		printf("Conjunto Seti_2 é um conjunto vazio\n\n");
            	else
            		printf("Conjunto Seti_1 e Seti_2 são um conjuntos vazios\n\n");	

            break;
          
        }
    }//fim do while

}









		












