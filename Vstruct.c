/*
	Exemplo de emprego de struct, inclui enderecamento de campos.
	gcc -std=c99 -fno-builtin -o vstruct.out vstruct.c
*/

#include <stdint.h>
#include <stdio.h>

typedef struct
{
	uint8_t dia;
	uint8_t mes;
	uint16_t ano;
} tData;

void main(void)
{
	tData uma_data;
	tData aniversarios[10];

	uma_data.dia = 16;
	uma_data.mes = 6;
	uma_data.ano = 2000;

	printf("\nDia: %u, endereco do campo: %x", uma_data.dia, &uma_data.dia);
	printf("\nMes: %u, endereco do campo: %x", uma_data.mes, &uma_data.mes);
	printf("\nAno: %u, endereco do campo: %x\n", uma_data.ano, &uma_data.ano);

	for(uint8_t i = 0; i < 10; i++)
	{
		printf("\nEndereco do campo dia[%u]: %u", i, &aniversarios[i].dia);
		printf("\nEndereco do campo mes[%u]: %u", i, &aniversarios[i].mes);
		printf("\nEndereco do campo ano[%u]: %u \n", i, &aniversarios[i].ano);
	}
}
