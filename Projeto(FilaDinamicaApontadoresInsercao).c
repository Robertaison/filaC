//Prof. Msc. José Eduardo Ribeiro
//Disciplina: Estrutura de Dados

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct no{
       int dado;           //dado a ser armazenado
       struct no * prox;   //ponteiro para próximo nó
}tno;

typedef struct fila{
       tno * comeco;       //começo da fila, na opearação de remoção esse ponteiro precisa ser atualizado
       tno * fim;          //fim da fila, na operação de inserção esse ponteiro precisa ser atualizado
       int dimensao;    //Variável de controle de dimensão
}tfila;

void criar(tfila * ppf){
     ppf->comeco = ppf->fim = NULL;
     ppf->dimensao = 0;
}

bool enfileirar(tfila * ppf, int valor){
     tno * novo;
     novo = (tno *) malloc(sizeof(tno));
     if(novo == NULL)
             return false;
     else
         if(ppf->comeco == NULL){
            novo->dado = valor;
            novo->prox = NULL;
            ppf->comeco = novo;
            ppf->fim = novo;
            printf("Fila[%d] \n", novo->dado);
            ppf->dimensao++;
            return true;
         }
         else
             if(ppf->comeco != NULL){
               novo->dado = valor;
               novo->prox = NULL;
               (ppf->fim)->prox = novo;
               ppf->fim = novo;
               printf("Fila[%d] \n", novo->dado);
               ppf->dimensao++;
               return true;
             }
}

bool desinfileirar(tfila * ppf, int * valor){
     tno * aux;
     if(ppf->comeco == NULL)
        return false;
     else{
          aux = ppf->comeco;
          *valor = (ppf->comeco)->dado;      // *valor = aux->dado;
          ppf->comeco = (ppf->comeco)->prox; // ppf->comeco = aux->prox;
          free(aux);
          ppf->dimensao--;
          return true;
     }
}

void separaImparEPar(tfila *pp, tfila *ppp, tfila *ppi){
	int retorno;
	
		while(desinfileirar(pp, &retorno)){
			if(retorno%2==0){
				printf("Fila par recebe: [%d]");
				if(enfileirar(ppp, retorno))
					printf("PAr ok!");
			}else{
				printf("Fila impar recebe.");
				if(enfileirar(ppi, retorno))
					printf("Impar ok!");
			}	
		}
		/*printf("\n\tFila par.\n");
		imprimeFila(&par);
		printf("\n\tFila impar.\n");
		imprimeFila(&impar);*/	
    
}

int getDimensao(tfila *pp){
    int dimensao;
    dimensao = pp->dimensao;
    return dimensao;
}

void imprimeFila(tfila *pp){
	int elemento;
    int dimen;
    dimen = getDimensao(pp);
    if(dimen!=0){
    	printf("\n\tFila:\n");
        while(dimen!=0){
            desinfileirar(pp,&elemento);
            printf("\n\t%d",elemento);
            dimen--;
        }
    }else{
        printf("Sua fila esta vazia!\n\n");
    }
}

void main(){

     tfila * pf;
     tfila * pfPar;
     tfila * pfImpar;
     
     int valor = 0, op = 0, pegaValor = 0, dimensao=0;

     criar(&pf);
      criar(&pfPar);
       criar(&pfImpar);

     do{
        system("CLS");
        system("PAUSE");
        printf("\n\t Informe a opcao: ");
        printf("\n\t 1: Enfileirar. ");
        printf("\n\t 2: Desinfileirar. ");
        printf("\n\t 3: Imprimir a quantidadede elementos.");
        printf("\n\t 4: Imprimir e desmontar a fila.");
        printf("\n\t-1: Sair. \n");
        scanf("%d", &op);
        switch(op){
                   case 1: do{
                              printf("Informe o valor ou (-1 para Sair): ");
                              scanf("%d", &valor);
                              if(valor == -1)
                                       printf("Saindo...\n");
                              else{
                                   if(!enfileirar(&pf, valor)){
                                       printf("Nao foi possivel enfileirar! \n");
                                   }
                              }
                           }while(valor != -1);
                           break;
                   case 2: do{
                              printf("Digite alguma tecla para desinfileirar ou (-1 para Sair): ");
                              scanf("%d", &valor);
                              if(valor == -1)
                                       printf("Saindo...\n");
                              else{
                                   if(desinfileirar(&pf, &pegaValor)){
                                      printf("Removido %d elemento da fila! \n", pegaValor);
                                   }
                                   else{
                                        printf("Fila Vazia! \n");
                                   }
                              }
                           }while(valor != -1);
                           break;

				  case 3: do{
				  			printf("\n\tDigite\n\t 1 para imprimir a dimensao da fila.\n\t-1 Para retornar ao menu.\n\n");
                              scanf("%d", &valor);
                              if(valor == -1)
                                       printf("Saindo...\n");
                              else if(valor==1){
                                   dimensao = getDimensao(&pf);
                                   if(dimensao!=0){
                                        printf("A fila posssui %d elementos.\n", dimensao);
                                   }
                                   else{
                                        printf("Fila Vazia! \n");
                                   }
                              }else{
                                printf("O que gostaria de fazer?");
                              }
                            }while(valor != -1);
							break;

                  case 4: do{
                            printf("\n\n\tDigite\n\t 1 para imprimir a fila\n\t-1 para sair do menu\n");
                            scanf("%d",&valor);
                            if(valor==1){
                                separaImparEPar(&pf, &pfPar, &pfImpar);
                            }else{
                            	printf("Digite uma opcao correta.");
							}
                    	  }while(valor != -1);
                    	  break;
        }
     }while(op != -1);


     system("PAUSE");
}
