/*
	Exemplo de vetor dinamico de struct.
	gcc -std=c99 -fno-builtin -o vdstruct.out vdstruct.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
	char nome[32];
	float nota;
} aluno_t;

void main(void)
{
	aluno_t *pa;
	uint8_t n, i;

	printf("Entre com o numero de elementos do vetor de alunos: ");
	scanf("%d", &n);
	pa = (aluno_t *)malloc(n*sizeof(aluno_t));
	if(pa == NULL)
	{
		printf("Memoria insuficiente!!!!!\n");
		exit(1);
	}
	for(i = 0; i < n; i++)
	{
		printf("Entre com o nome do aluno %d: ", i+1);
		scanf("%s", pa[i].nome);
		printf("Entre com a nota do aluno %d: ", i+1);
		scanf("%f", &pa[i].nota);
		printf("Elemento %d: %s (nome), %f (nota) \n", i+1, pa[i].nome, pa[i].nota);
	}
	free(pa);
}
