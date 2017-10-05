/*
	Exemplo de emprego de unions, inclui enderecamento de campos.
	gcc -std=c99 -fno-builtin -o unions.out unions.c
*/

#include <stdint.h>
#include <stdio.h>

typedef union
{
	char caracteres[10];
	uint16_t inteiros	[10];
} tVetor;

void main(void)
{
	uint8_t i;
	tVetor valores;

	for(i = 0; i < 10; i++)
		valores.inteiros[i] = i;
	printf("\nLendo como inteiros:\n");
	for(i = 0; i < 10; i++)
		printf("%u", valores.inteiros[i]);
	printf("\nLendo como caracteres:\n");
	for(i = 0; i < 10; i++)
		printf("%c", valores.caracteres[i]);
	printf("Foram lidos os primeiros bytes dos numeros (zeros)\n\n");
	valores.inteiros[0] = 65;
	printf("Lendo primeiro elemento como um char: %c \n", valores.caracteres[0]);
}
