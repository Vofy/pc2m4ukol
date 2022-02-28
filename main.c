#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

unsigned short int toDecimal(unsigned short int *array) {
    unsigned short int decimal = 0;

    for(int i = 0; i < 16; i++)
        decimal += array[15 - i] * pow(2, i);

    return decimal;
}

void fillArray(unsigned short int *array) {
    for(int i = 0; i < 16; i++)
        array[i] = rand() % 2;
}

void printArray(unsigned short int *array) {
    for(int i = 0; i < 16; i++)
        printf("%d ", array[i]);
}

int main(void) {
	unsigned short int a_bin[16], b_bin[16], c_bin[16];     // des�tkov� ��sla
	unsigned short int a_dec=0, b_dec=0, c_dec, d_dec;		// dvojkov� ��sla
	int w, bshift;										    // ��d pro bin�rn� konverzi, n�hodn� ��slo pro bitov� posun
	int n;													// po��tadlo cykl�
	char c;													// char pro na�ten� znaku

	srand(time(NULL));


	// Naplneni pole a_bin nahodnymi cisly
	printf("Two binary inputs and their decimal values :\n\na_bin:     ");
	fillArray(&a_bin);
	a_dec = toDecimal(a_bin);
	printArray(&a_bin);
    printf("     a_dec: %5d\n", a_dec);


	// Naplneni pole b_bin nahodnymi cisly
	printf("b_bin:     ");
	fillArray(&b_bin);
	b_dec = toDecimal(b_bin);
	printArray(&b_bin);
    printf("     b_dec: %5d\n\n", b_dec);


    // Provedeni logickeho soucinu
    printf("Bit-wise conjunction (AND):\n\nc_dec:     ");

    for(int i = 0; i < 16; i++)
        c_bin[i] = a_bin[i] && b_bin[i] ? 1 : 0;

    d_dec = a_dec & b_dec;

    printArray(c_bin);
    printf("     c_dec: %5d     d_dec: %5d\n\n", toDecimal(c_bin), d_dec);


    // Provedeni logickeho souctu
    printf("Bit-wise disjunction (OR):\n\nc_dec:     ");

    for(int i = 0; i < 16; i++)
        c_bin[i] = a_bin[i] || b_bin[i] ? 1 : 0;

    d_dec = a_dec | b_dec;

    printArray(c_bin);
    printf("     c_dec: %5d     d_dec: %5d\n\n", toDecimal(c_bin), d_dec);


    // Provedeni logickeho rozdilu
    printf("Bit-wise inequality (XOR):\n\nc_dec:     ");

    for(int i = 0; i < 16; i++)
        c_bin[i] = a_bin[i] != b_bin[i] ? 1 : 0;

    d_dec = a_dec ^ b_dec;

    printArray(c_bin);
    printf("     c_dec: %5d     d_dec: %5d\n\n", toDecimal(c_bin), d_dec);


    // Posunuti bitu o 6 pozic doprava
    printf("Bit shift to right: 6 bits of a_bin/a_dec:\n\nc_dec:     ");

    for(int i = 0; i < 16; i++)
        c_bin[i] = i >= 6 ? a_bin[i - 6] : 0;

    d_dec = a_dec >> 6;

    printArray(c_bin);
    printf("     c_dec: %5d     d_dec: %5d\n\n", toDecimal(c_bin), d_dec);


    // Proveden� logick� negace
    printf("Bit-wise complement (NOT) to a_bin/a_dec:\n\nc_dec:     ");

    for(int i = 0; i < 16; i++)
        c_bin[i] = a_bin[i] == 0 ? 1 : 0;

    d_dec = ~a_dec;

    printArray(c_bin);
    printf("     c_dec: %5d     d_dec: %5d\n\n", toDecimal(c_bin), d_dec);

	scanf("%c", &c);										// �ek�n� na zm��knut� kl�vesy
	return 0;
}
