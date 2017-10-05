//@@ -0,0 //1,105 @@
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <float.h>

typedef struct
{
    uint16_t inicio, fim, tamanho, tamanho_maximo;
    float* elementos;
}Tfila;

uint16_t incrementar(uint16_t i, Tfila* f)
{
    return (i+1)%f->tamanho_maximo;
}

Tfila* criar_fila (uint16_t tamanho_maximo){
    Tfila* fila = (Tfila*) malloc(sizeof(Tfila));
    if (fila == NULL){
        printf ("Memoria insuficiente para struct Tfila!\n");
        exit (1);
    }
	fila->elementos = (float*)malloc(sizeof(float)*tamanho_maximo);
    if (fila->elementos == NULL){
        printf ("Memoria insuficiente para elementos!\n");
        exit (1);
    }
    fila->inicio = fila->fim = fila->tamanho = 0;
	fila->tamanho_maximo = tamanho_maximo;
    return fila;
}

void inserir_elemento(Tfila* f, float v)
{
    if(f->fim == f->inicio && f->tamanho > 0)
         	printf("Nao inserido: fila cheia !!!!\n");
	else
	{
	    f->elementos[f->fim] = v;
	    f->fim = incrementar(f->fim, f);
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
	    f->inicio = incrementar(f->inicio, f);
		f->tamanho--;
	    return v;
	}
}

void destruir_fila(Tfila* f)
{
	free(f->elementos);
    free (f);
}

void imprimir_fila(Tfila* f)
{
    uint16_t i, j;
	j = 0;
    for (i = f->inicio; j < f->tamanho; i = incrementar(i, f))
	{
        printf ("%f \n", f->elementos[i]);
		j++;
    }
}

int main()
{
	Tfila* fila;
	uint16_t t;

	printf("Entre com o numero de elementos: \n");
	scanf("%d", &t);
	fila = criar_fila(t);
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
