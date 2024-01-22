#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define PI 3.141592653589

void entradaValores(double *freq);
double calcCap(double *freq);
double calcRes(double *freq, double *C);
void exibirValores(double freq, double R, double C);
double corte(double R, double C);
void atualizarComercial(double *C, char *op);

int main() {
    setlocale(LC_ALL, "");
    double freq, R, C;
    char op;

    entradaValores(&freq);
    C = calcCap(&freq);
    R = calcRes(&freq, &C);
    exibirValores(freq, R, C);

    do {
        atualizarComercial(&C, &op);
        R = calcRes(&freq, &C);
        exibirValores(freq, R, C);
    } while(op != 's' && op != 'n');

    printf("\n\nFrequência de corte RC: %.12lf\n", corte(R, C));
    return 0;
}

void entradaValores(double *freq) {
    printf("Digite o valor da frequência (Hz): ");
    scanf("%lf", freq);
}

double calcCap(double *freq) {
    double C;
    C = 10.0/(*freq);
    C *= 1.0e-6;

    return C;
}

double calcRes(double *freq, double *C) {
    double R;
    double denominador = 2*PI*(*freq)*(*C);
    R = 1.0/denominador;

    return R;
}

void exibirValores(double freq, double R, double C) {
    printf("\nFrequência: %.3lf", freq);
    printf("\nResistência: %.12lf", R);
    printf("\nCapacitância: %.12e", C);
}

double corte(double R, double C) {
    double freqCorte, denominador;

    denominador = 2*PI*R*C;
    freqCorte = 1/denominador;

    return freqCorte;
}

void atualizarComercial(double *C, char *op) {
    printf("\nDeseja aproximar o capacitor (s: sim) ou (n: não)? ");
    scanf(" %c", op);

    if(*op == 's') {
        printf("\nDigite o valor do capacitor (F): ");
        scanf("%lf", C);
    }
}
