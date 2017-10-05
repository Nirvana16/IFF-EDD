#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    char fornecedor[32];
	float valor;
	struct TTransacao* proximo;
} TTransacao;

typedef struct
{
	TTransacao* inicio;
	TTransacao* fim;
} Fila;

Fila* criar_fila(void)
{
	Fila* f = (Fila*)malloc(sizeof(Fila));
	if (!f) return NULL;
	f->inicio = f->fim = NULL;
	return f;
}

TTransacao* inserir_no_fim(TTransacao* fim, float valor,char nome[32])
{
	TTransacao* p = (TTransacao*)malloc(sizeof(TTransacao));
	if (!p) return NULL;
	p->valor = valor;
	strcpy(p->fornecedor,nome);
	p->proximo = NULL;
	if (fim != NULL) fim->proximo = p;
	return p;
}

TTransacao* remover_do_inicio(TTransacao* inicio)
{
	TTransacao* p = inicio->proximo;
	free(inicio);
	return p;
}

void inserir(Fila* f, float valor, char nome[32])
{
	f->fim = inserir_no_fim(f->fim, valor,nome);
	if (f->inicio == NULL)
		f->inicio = f->fim;
}

int retirar(Fila* f)
{
	float valor;
	if (vazia(f))
	{
		printf("Fila vazia.\n");
		exit(1);
	}
	valor = f->inicio->valor;
	f->inicio = remover_do_inicio(f->inicio);
	if (f->inicio == NULL) f->fim = NULL;
	return valor;
}

int vazia(Fila* f)
{
	return (f->inicio == NULL);
}

void liberar_fila(Fila* f)
{
	TTransacao* iterator = f->inicio;
	while (iterator != NULL)
	{
		TTransacao* proximo = iterator->proximo;
		free(iterator);
		iterator = proximo;
	}
	free(f);
}

void imprimir_fila(Fila* f)
{
	TTransacao* iterator;
	for (iterator = f->inicio; iterator != NULL; iterator = iterator->proximo)
        printf("Fornecedor : %s = Valor  : %f.2\n", iterator->fornecedor,iterator->valor);
}

void main(void)
{
	Fila* a_fila;
	int retorno,quantidade;
	char fornece[32];
	float val;

	a_fila = criar_fila();
	printf("Numero de transacoes: \n");
	scanf("%d", &quantidade);
	do{
          printf("Informe o fornecedor: \n");
          scanf("%s",&fornece);
          printf("Informe o valor: \n");
	      scanf("%f", &val);
          inserir(a_fila,val,fornece);
          quantidade--;
    }while(quantidade > 0);
	imprimir_fila(a_fila);
	printf("Primerio Elemeno: %f\n",retirar(a_fila));
	printf("Segundo Elemeno: %f\n",retirar(a_fila));
	printf("Configuracao da fila: \n");
	imprimir_fila(a_fila);
	printf(" Liberando Memoria...\n");
	liberar_fila(a_fila);
	printf(" Fila: %d \n", a_fila);
	getch();
}
