/*
	Exemplo de aritmetica de ponteiros.
	gcc -std=c99 -fno-builtin -o aritmetica.out aritmetica.c
*/

#include <stdint.h>
#include <stdio.h>


void main(void)
{
	int16_t x;
	int16_t *p;

	p = &x;
	*p = -10;
	printf("x: %d\n", x);
	printf("p: %d, endereco de x %d\n", p, &x);
	//Operacao nao segura abaixo...
	++p;
	printf("p: %d, conteudo de p (lixo...) %d\n", p, *p);
}
