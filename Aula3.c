#include<stdint.h>
#include<conio.h>

typedef struct {
    uint8_t dia;
    uint8_t mes;
    uint16_t ano;
} tData;


void main(void) {
    tData uma_data;
    tData aniversarios[10];

    uma_data.dia = 16;
    uma_data.mes = 6;
    uma_data.ano = 2000;

    printf("Dia %u, endereco do campos: %x \n", uma_data.dia, &uma_data.dia);
    printf("Mes %u, endereco do campos: %x \n", uma_data.mes, &uma_data.mes);
    printf("Ano %u, endereco do campos: %x \n", uma_data.ano, &uma_data.ano);

    for(uint8_t I = 0; i < 10; i++){
        aniversarios[i].dia = 16;
        aniversarios[i].mes = 6;
        aniversarios[i].ano = 2000;
    }
    for(uint8_t I = 0; i < 10; i++){

    printf("Endereco do campos: Dia[%u] \n %u", i, &uma_data.dia);
    printf("Endereco do campos: Mes[%u] \n", i, &uma_data.mes);
    printf("Endereco do campos: Ano[%u]\n", i, &uma_data.ano);
    }

    getch();
}

