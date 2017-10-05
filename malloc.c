/*
	Exemplo de emprego de malloc e free para criacao de vetor dinamico.
	gcc -std=c99 -fno-builtin -o vdinamico.out vdinamico.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void main(void)
{
	int16_t *pi;
	uint8_t n, i;

	printf("Entre com o numero de elementos do vetor de inteiros (maior que 5): ");
	scanf("%d", &n);
	pi = (int16_t*)malloc(n*sizeof(int16_t));
	if(pi == NULL)
	{
		printf("Memoria insuficiente!!!!!\n");
		exit(1);
	}
	printf("Ponteiro: %X (em hexa), %d (como inteiro)\n", pi, pi);
	for(i = 0; i < n; i++)
	{
		pi[i] = i+5;
		printf("Elemento %d: %d \n", i, pi[i]);
	}
	pi = (int16_t*)realloc(pi, 5*sizeof(int16_t));
	/*
		Apesar de ter realocado apenas 5 elementos, como nao houve uso da area desalocada,
		eh possivel acessar o que estava lah originalmente, portanto, cuidado!
		Muitas vezes codigo lambao funciona!!!!!!
	*/
	printf("\n\n");
	for(i = 0; i < n; i++)
	{
		printf("Elemento %d: %d \n", i, pi[i]);
	}
	free(pi);
	/*
		Cuidado!!! free() nao atribui NULL para o ponteiro, apenas libera a memoria por
		ele apontada.
	*/
	printf("Ponteiro: %X (em hexa), %d (como inteiro)\n", pi, pi);
}
