#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <float.h>

#define N 5

typedef struct
{
    uint16_t inicio, fim, tamanho;
    float elementos[N];
}Tfila;

uint16_t incrementa(uint16_t i)
{
    return (i+1)%N;
}

Tfila* criar_fila (void){
    Tfila* fila = (Tfila*) malloc(sizeof(Tfila));
    if (fila == NULL){
        printf ("Memoria insuficiente!\n");
        exit (1);
    }
    fila->inicio = fila->fim = fila->tamanho = 0;
    return fila;
}

void inserir_elemento(Tfila* f, float v)
{
    if(f->fim == f->inicio && f->tamanho > 0)
         	printf("Nao inserido: fila cheia !!!!\n");
	else
	{
	    f->elementos[f->fim] = v;
	    f->fim = incrementa(f->fim);
	    f->tamanho++;
	}
}

float retirar_elemento(Tfila* f)
{
    float v;
	if(f->tamanho == 0)
	{
        printf ("Fila vazia !!!!\n");
        return FLT_MAX;
    }
	else
	{
	    v = f->elementos[f->inicio];
	    f->inicio = incrementa(f->inicio);
		f->tamanho--;
	    return v;
	}
}

void destruir_fila(Tfila* f)
{
    free (f);
}

void imprimir_fila(Tfila* f)
{
    uint16_t i, j;
	j = 0;
    for (i = f->inicio; j < f->tamanho; i = incrementa(i))
	{
        printf ("%f \n", f->elementos[i]);
		j++;
    }
}

int main()
{
	Tfila* fila;

	fila = criar_fila();
	inserir_elemento(fila, 8.1);
	inserir_elemento(fila, 3.4);
	inserir_elemento(fila, 18);
	inserir_elemento(fila, 11);
	inserir_elemento(fila, 3);
	inserir_elemento(fila, 10);
	imprimir_fila(fila);
	printf("Elemento retirado: %f \n", retirar_elemento(fila));
	imprimir_fila(fila);
	inserir_elemento(fila, 50);
	imprimir_fila(fila);
	printf("Elemento retirado: %f \n", retirar_elemento(fila));
	printf("Elemento retirado: %f \n", retirar_elemento(fila));
	printf("Elemento retirado: %f \n", retirar_elemento(fila));
	printf("Elemento retirado: %f \n", retirar_elemento(fila));
	printf("Elemento retirado: %f \n", retirar_elemento(fila));
	retirar_elemento(fila);
	destruir_fila(fila);
	getch();
}
