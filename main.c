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

void logicalAnd(unsigned short int *arrayA, unsigned short int *arrayB, unsigned short int *result) {
    for(int i = 0; i < 16; i++)
        result[i] = arrayA[i] && arrayB[i] ? 1 : 0;
}

void logicalOr(unsigned short int *arrayA, unsigned short int *arrayB, unsigned short int *result) {
    for(int i = 0; i < 16; i++)
        result[i] = arrayA[i] || arrayB[i] ? 1 : 0;
}

void logicalXor(unsigned short int *arrayA, unsigned short int *arrayB, unsigned short int *result) {
    for(int i = 0; i < 16; i++)
        result[i] = arrayA[i] != arrayB[i] ? 1 : 0;
}

void logicalNot(unsigned short int *array, unsigned short int *result) {
    for(int i = 0; i < 16; i++)
        result[i] = array[i] == 0 ? 1 : 0;
}

void bitShift(unsigned short int *array, int shift, unsigned short int *result) {
    for(int i = 0; i < 16; i++)
        result[i] =  i >= shift ? array[i - shift] : 0;
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
	unsigned short int a_bin[16], b_bin[16], c_bin[16];     // desítková èísla
	unsigned short int a_dec=0, b_dec=0, c_dec, d_dec;		// dvojková èísla
	int w, bshift;										    // øád pro binární konverzi, náhodné èíslo pro bitový posun
	int n;													// poèítadlo cyklù
	char c;													// char pro naètení znaku

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
    logicalAnd(&a_bin, &b_bin, &c_bin);
    d_dec = a_dec & b_dec;
    printArray(c_bin);
    printf("     c_dec: %5d     d_dec: %5d\n\n", toDecimal(c_bin), d_dec);

    // Provedeni logickeho souctu
    printf("Bit-wise disjunction (OR):\n\nc_dec:     ");
    logicalOr(&a_bin, &b_bin, &c_bin);
    d_dec = a_dec | b_dec;
    printArray(c_bin);
    printf("     c_dec: %5d     d_dec: %5d\n\n", toDecimal(c_bin), d_dec);

    // Provedeni logickeho rozdilu
    printf("Bit-wise inequality (XOR):\n\nc_dec:     ");
    logicalXor(&a_bin, &b_bin, &c_bin);
    d_dec = a_dec ^ b_dec;
    printArray(c_bin);
    printf("     c_dec: %5d     d_dec: %5d\n\n", toDecimal(c_bin), d_dec);

    // Posunuti bitu o 6 pozic doprava
    printf("Bit shift to right: 6 bits of a_bin/a_dec:\n\nc_dec:     ");
    bitShift(&a_bin, 6, &c_bin);
    d_dec = a_dec >> 6;
    printArray(c_bin);
    printf("     c_dec: %5d     d_dec: %5d\n\n", toDecimal(c_bin), d_dec);

    // Provedení logické negace
    printf("Bit-wise complement (NOT) to a_bin/a_dec:\n\nc_dec:     ");
    logicalNot(&a_bin, &c_bin);
    d_dec = ~a_dec;
    printArray(c_bin);
    printf("     c_dec: %5d     d_dec: %5d\n\n", toDecimal(c_bin), d_dec);

	scanf("%c", &c);										// èekání na zmáèknutí klávesy
	return 0;
}
