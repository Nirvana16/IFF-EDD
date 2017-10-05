#include <stdio.h>
#include <stdlib.h>

typedef struct No //Necessario para evitar warnings com a forward declaration usada por proximo
{
	float valor;
	struct No* proximo;
} No;

typedef struct
{
	No* inicio;
	No* fim;
} Fila;

Fila* criar_fila(void)
{
	Fila* f;
	f = (Fila*)malloc(sizeof(Fila));
	if(!f)
	{
		printf("Memoria insuficiente para alocar header de fila\n");
		exit(1);
	}
	f->inicio = f->fim = NULL;
	return f;
}

No* inserir_fim(No* fim, float v)
{
	No* p;
	p = (No*)malloc(sizeof(No));
	if(!p)
	{
		printf("Memoria insuficiente para alocar no\n");
		exit(2);
	}
	p->valor = v;
	p->proximo = NULL;
	if (fim != NULL) // lista não vazia?
		fim->proximo = p;
	return p;
}

No* retirar_inicio(No* inicio)
{
	No* p;
	p = inicio->proximo;
	free(inicio);
	return p;
}

void inserir(Fila* f, float v)
{
	f->fim = inserir_fim(f->fim, v);
	if (f->inicio == NULL) // Insercao do primeiro
		f->inicio = f->fim;
}

int vazia(Fila* f)
{
	return (f->inicio == NULL);
}

float retirar(Fila* f)
{
	float v;
	if (vazia(f))
	{
		printf("Fila vazia.\n");
		exit(3);
	}
	v = f->inicio->valor;
	f->inicio = retirar_inicio(f->inicio);
	if (f->inicio == NULL) // fila ficou vazia?
		f->fim = NULL;
	return v;
}

void liberar(Fila* f)
{
	No* q;
	q = f->inicio;
	while (q != NULL) //Desaloca nos
	{
		No* t = q->proximo;
		free(q);
		q = t;
	}
	free(f); //Desaloca header
}

void imprimir(Fila* f)
{
	No* q;
	for (q = f->inicio; q != NULL; q = q->proximo)
		printf("%f\n", q->valor);
}

void main(void)
{
	Fila* f;
	f = criar_fila();
	inserir(f,20.0);
	inserir(f,20.8);
	inserir(f,20.2);
	inserir(f,20.3);
	imprimir(f);
	printf("Primeiro elemento: %f\n", retirar(f));
	printf("Segundo elemento: %f\n", retirar(f));
	printf("Configuracao da fila:\n");
	imprimir(f);
	liberar(f);
}
