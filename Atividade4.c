//
//  main.cpp
//  
//
//  Created by Vitor Carneiro Borela 14056626
// and Rafael Sperandio Scheiner 12014569
//
//  
//
#include<stdio.h>
#include<stdlib.h>
#define __fpurge(stdin) getchar();
typedef struct no No;
struct no {
    int chave;
    No *prox;
};
 
// Questao 1
void insereInicio (No **pLista, int n)
{
    No *novo = (No *) malloc (sizeof(No));
    novo->chave = n;
    novo->prox = NULL;
    No *aux;
   
    if (*pLista==NULL)
    {
        *pLista = novo;
        return;
    }else
    {
        aux = (*pLista);
        (*pLista) = novo;
        novo->prox = aux;
    }
   
   
}
 
// Questao 2
void insereFim (No **pLista, int n) {
   
    No *novo = (No *) malloc (sizeof(No));
    novo->chave = n;
    novo->prox = NULL;
   
    if (*pLista==NULL)
    {
        *pLista = novo;
        return;
    }
   
    No *atual = (*pLista);
    while(atual->prox!=NULL)
    {
        atual = atual->prox;
    }
   
    atual->prox = novo;
}
 
// Questao 3
void insereK (No **pLista, int n, int k) {
   
    int pos=1;
    No *novo = (No *) malloc (sizeof(No));
    novo->chave = n;
    novo->prox = NULL;
   
    if (*pLista==NULL)
    {
        *pLista = novo;
        return;
    }
   
    No *atual = (*pLista);
   
    No *aux=NULL;
   
    if(pos==k)
    {
        aux = (*pLista);
        (*pLista) = novo;
        novo->prox = aux;
 
   
    }
    while(atual->prox!=NULL && pos!=k-1)
    {
        atual = atual->prox;
        pos++;
       
    }
   
    if (pos==k-1)
    {
        aux = atual->prox;
        atual->prox = novo;
        novo->prox = aux;
    }
}
 
// Questao 4
void exibePrimeiro (No *Lista)
{
    if (Lista!=NULL)
    {
        printf("A chave do primeiro e %d\n",(Lista)->chave);
    }else
    {
        printf("Lista vazia\n");
    }
}
 
// Questao 5
void exibeUltimo (No *Lista)
{
   
    No *atual = (Lista);
    if(Lista!=NULL)
    {
        while(atual->prox!=NULL)
        {
            atual = atual->prox;
           
        }
        printf("A chave do ultimo e %d\n",atual->chave);
    }
}
 
// Questao 6
void exibeK (No *Lista, int k)
{
   
    int pos=1;
    No *atual = (Lista);
    if(Lista!=NULL)
    {
       
        while(atual->prox!=NULL && pos != k)
        {
            atual = atual->prox;
            pos++;
        }
       
        if (pos==k)
        {
            printf("A chave do k-%d e %d\n",k,atual->chave);
        }
        else
        {
            printf("Nao ha chave nesta posicao");
        }
    }
}
 
// Questao 7
int procuraN (No *Lista, int n)
{
    No *atual = (Lista);
    int pos=1;
    if(Lista!=NULL)
    {
        while(atual->prox!=NULL && atual->chave!=n)
        {
            atual = atual->prox;
        }
           
            return atual->chave;
    } 
    
    return 0;
}
 
// Questao 8
int quantidade (No *Lista)
{
    int pos=0;
    No *atual = (Lista);
    if(Lista!=NULL)
        while(atual->prox!=NULL )
        {
            atual = atual->prox;
            pos++;
        }
    else
    {
        pos=0;
        printf("a qtd de nos eh %d \n" ,pos);
        return pos;
    }
   
    printf("A quantidade de nos eh:%d\n",pos+1);
    return pos+1;
}
 
// Questao 9
int soma (No *Lista)
{
    No *atual = (Lista);
    int soma=0;
    if(Lista!=NULL)
    {
        while(atual)
        {
            soma = soma + atual->chave;
            atual = atual->prox;
           
        }
        return soma;
    }
    return 0;
}
 
// Questao 10
float media (No *Lista)
{
    No *atual = (Lista);
    int soma=0;
    float pos=0;
    if(Lista!=NULL){
        while(atual)
        {
            soma = soma + atual->chave;
            atual = atual->prox;
            pos++;
        }
        return soma/(float)pos;
    }
    return 0;
}
 
// Questao 11
void excluiPrimeiro (No **pLista)
{
    No *aux;
    if (*pLista==NULL)return;
    aux= (*pLista)->prox;
    free((*pLista));
    (*pLista) = aux;
}
 
// Questao 12
void excluiUltimo (No **pLista)
{
    No *atual = (*pLista);
    No *aux=NULL;
    if (*pLista!=NULL)
    {
        while(atual->prox!=NULL)
        {
            aux = atual;
            atual = atual->prox;
        }
        if(!aux)
	{
	  free(atual);
	}
	else
	{
	  if(!atual->prox)
	  {
	    aux->prox=NULL;
	    free(atual);
	  }
	} 
        printf("Excluido com sucesso");
      }
    else
    {
        printf("lista vazia");
    }
}
 
// Questao 13
void excluiK (No **pLista, int k)
{
    No *atual = (*pLista);
    No *aux=NULL;
    int pos=1;
    if (*pLista!=NULL)
    {
        while(atual->prox!=NULL && pos!=k)
        {
            aux = atual;
            atual = atual->prox;
            pos++;
        }
        if (pos==k)
        {
            if (pos==1)
            {
                (*pLista)=atual->prox;
                printf("Excluido com sucesso");
            }else
            {
                aux->prox = atual->prox;
                printf("Excluido com sucesso");
               
                    if(atual->prox==NULL)
                    {
                        aux->prox=NULL;
                    }
            }
            free(atual);
           
           
           
           
        }else
        {
            printf("Nao possivel excluir esta posicao");
        }
       
    }
}
 
// Questao 14
void excluiN (No **pLista, int n)
{
    No *atual = (*pLista);
    No *aux=NULL;
    if (*pLista!=NULL)
    {
        while(atual->prox!=NULL && atual->chave!=n)
        {
            aux = atual;
            atual = atual->prox;
        }
              
          if (!aux)
            {
                (*pLista)=atual->prox;
		free(atual);
                printf("Excluido com sucesso");
            }else
            {
                aux->prox = atual->prox;
                printf("Excluido com sucesso");
               
                if(atual->prox==NULL)
                {
                    aux->prox=NULL;
		    free(atual);
                }
                free(atual);
            }
            
      }else
        {
            printf("Nao possivel excluir esta posicao");
        }
       
    
}
 
// Cria uma lista vazia
void criaVazia (No **pLista)
{
    *pLista = NULL;
}
 
// DEBUG: Exibe todos os elementos de uma Lista
void exibe (No *Lista) {
    while (Lista!=NULL) {
        printf("%d ",Lista->chave);
        Lista = Lista->prox;
    }
}
 
int main() {
    int opcao = -1, n, k;
    No *Lista;
    criaVazia(&Lista);
    while (opcao != 0) {
        do {
            printf("\n");
            printf("(0) Finalizar o programa\n");
            printf("(1) Inserir elemento no inicio da lista (Q-1)\n");
            printf("(2) Inserir elemento no final da lista (Q-2)\n");
            printf("(3) Inserir elemento na k-esima posicao da lista (Q-3)\n");
            printf("(4) Exibir o primeiro elemento da lista (Q-4)\n");
            printf("(5) Exibir o ultimo elemento da lista (Q-5)\n");
            printf("(6) Exibir o k-esimo elemento da lista (Q-6)\n");
            printf("(7) Procurar um elemento da lista (Q-7)\n");
            printf("(8) Exibir a quantidade de elementos da lista (Q-8)\n");
            printf("(9) Exibir a soma dos valores da lista (Q-9)\n");
            printf("(10) Exibir a media dos valores da lista (Q-10)\n");
            printf("(11) Excluir o primeiro elemento da lista (Q-11)\n");
            printf("(12) Excluir o ultimo elemento da lista (Q-12)\n");
            printf("(13) Excluir o k-esimo elemento da lista (Q-13)\n");
            printf("(14) Excluir um elemento procurado da lista (Q-14)\n");
            printf("Opcao: ");
            scanf("%d", &opcao);
            printf("\n");
            if ((opcao<0) || (opcao>14))
                printf("Opcao invalida!\n");
        } while ((opcao<0) || (opcao>14));
        switch (opcao) {
            case 0:
                printf("Finalizando o programa.\n");
                return 0;
            case 1:
                // Insere um elemento no inicio da lista
                printf("Q-1 Insere um elemento no inicio\n");
                printf("Chave: ");
                __fpurge(stdin);
                scanf("%d",&n);
                insereInicio(&Lista,n);
                break;
            case 2:
                // Insere um elemento no fim da lista
                printf("Q-2 Insere um elemento no fim\n");
                printf("Chave: ");
                __fpurge(stdin);
                scanf("%d",&n);
                insereFim(&Lista,n);
                break;
            case 3:
                // Insere um elemento na k-esima posicao da lista
                printf("Q-3 Insere um elemento na k-esima posicao\n");
                printf("Chave: ");
                __fpurge(stdin);
                scanf("%d",&n);
                printf("k: ");
                __fpurge(stdin);
                scanf("%d",&k);
                insereK(&Lista,n,k);
                break;
            case 4:
                // Exibe o primeiro elemento da lista
                printf("Q-4 Exibe o primeiro elemento\n");
                printf("Chave: ");
                exibePrimeiro(Lista);
                printf("\n");
                break;
            case 5:
                // Exibe o ultimo elemento da lista
                printf("Q-5 Exibe o ultimo elemento\n");
                printf("Chave: ");
                exibeUltimo(Lista);
                printf("\n");
                break;
            case 6:
                // Exibe o k-esimo elemento da lista
                printf("Q-6 Exibe o k-esimo elemento\n");
                printf("k: ");
                __fpurge(stdin);
                scanf("%d",&k);
                printf("Chave: ");
                exibeK(Lista,k);
                printf("\n");
                break;
            case 7:
                // Procura por um elemento da lista
                printf("Q-7 Procura por um elemento\n");
                printf("Chave: ");
                __fpurge(stdin);
                scanf("%d",&n);
                if (procuraN(Lista,n))
                    printf("Elemento %d encontrado.\n", n);
                else
                    printf("Elemento %d não encontrado.\n", n);
                break;
            case 8:
                // Exibe a quantidade de elementos da lista
                printf("Q-8 Exibe a quantidade de elementos\n");
                printf("Quantidade de elementos: %d\n", quantidade(Lista));
                break;
            case 9:
                // Exibe a soma dos elementos da lista
                printf("Q-9 Exibe a soma dos elementos\n");
                printf("Soma: %d\n", soma(Lista));
                break;
            case 10:
                // Exibe a media dos elementos da lista
                printf("Q-10 Exibe a media dos elementos\n");
                printf("Media: %f\n", media(Lista));
                break;
            case 11:
                // Exclui o primeiro elemento da lista
                printf("Q-11 Exclui o primeiro elemento\n");
                excluiPrimeiro(&Lista);
                break;
            case 12:
                // Exclui o ultimo elemento da lista
                printf("Q-12 Exclui o ultimo elemento\n");
                excluiUltimo(&Lista);
                break;
            case 13:
                // Exclui o k-esimo elemento da lista
                printf("Q-13 Exclui o k-esimo elemento\n");      
                printf("k: ");
                __fpurge(stdin);
                scanf("%d",&k);
                excluiK(&Lista,k);
                break;
            case 14:
                // Exclui um elemento procurado da lista
                printf("Q-14 Exclui um elemento procurado\n");       
                printf("Chave: ");
                __fpurge(stdin);
                scanf("%d",&n);
                excluiN(&Lista,n);
                break;            
            default:
                break;
        }
#ifdef DEBUG
        printf("\n[DEBUG] Lista: ");
        exibe(Lista);
        printf("\n");
#endif
    }
}
