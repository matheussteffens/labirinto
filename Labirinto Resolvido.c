#include <stdio.h>

#define FIM -5
#define LIVRE -1
#define PAREDE -2

int labirinto[][12] = {
    {-1, -1, -2, -2, -2, -2, -2, -2, -1, -2, -2, -2},
    {-2, -1, -2, -2, -2, -2, -2, -2, -1, -2, -2, -2},
    {-1, -1, -1, -1, -1, -1, -2, -2, -1, -1, -1, -2},
    {-1, -2, -1, -2, -2, -1, -2, -2, -2, -2, -1, -2},
    {-1, -2, -1, -2, -2, -1, -1, -2, -1, -1, -1, -2},
    {-1, -2, -1, -1, -1, -2, -1, -1, -2, -2, -2, -2},
    {-1, -1, -2, -2, -2, -2, -2, -1, -1, -2, -2, -2},
    {-1, -2, -1, -2, -2, -2, -2, -2, -1, -2, -2, -1},
    {-1, -2, -1, -1, -2, -2, -2, -2, -1, -2, -2, -1},
    {-1, -2, -2, -1, -1, -2, -2, -2, -1, -1, -1, -1},
    {-1, -1, -2, -2, -1, -1, -1, -1, -1, -2, -2, -1},
    {-2, -1, -1, -2, -1, -1, -2, -1, -1, -1, -2, -1},
    {-2, -2, -1, -2, -1, -1, -2, -1, -2, -1, -1, -1},
    {-2, -2, -1, -2, -2, -1, -2, -2, -2, -2, -2, -1},
    {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -2, -1, -2, -2, -2, -1, -1, -1, -1, -2, -2},
    {-1, -1, -1, -2, -2, -2, -1, -2, -1, -1, -1, -2},
    {-1, -2, -1, -2, -2, -2, -1, -1, -1, -2, -1, -2},
    {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -5},
    {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2}
};

void imprimir(int lab[20][12]) {
    int i, j;

    for (i = 0; i < 20; i++) {
        printf("|");
        for (j = 0; j < 12; j++) {
            int n = lab[i][j];
            switch (n) {
                case -1:
                    printf("[   ]\t");
                    break;
                case -2:
                    printf("[ X ]\t");
                    break;
                case -5:
                    printf("[ F ]\t");
                    break;
                default:
                    printf("[%d]\t", n);
                    break;
            }
        }
        printf("|\n");
    }
}

int preencher(int matriz[][12], int i, int j, int contador) {
    if (i < 0 || i >= 20 || j < 0 || j >= 12) {
        return 0;
    }

    if (matriz[i][j] == -5) {
        return 1;
    }

    if (matriz[i][j] != -1) {
        return 0;
    }

    matriz[i][j] = contador++;

    if (preencher(matriz, i + 1, j, contador)) {
        return 1;
    }

    if (preencher(matriz, i - 1, j, contador)) {
        return 1;
    }

    if (preencher(matriz, i, j + 1, contador)) {
        return 1;
    }

    if (preencher(matriz, i, j - 1, contador)) {
        return 1;
    }

    matriz[i][j] = LIVRE;
    return 0;
}

int caminho(int lab[20][12]) {
    int i = 0;
    int j = 0;
    int aux = 0;
    int aux2 = 1;

    while (aux2 == 1) {
        aux2 = preencher(lab, i, j, aux);
    }

    return 0;
}

int main() {
    printf("Labirinto:\n");
    imprimir(labirinto);

    caminho(labirinto);

    printf("Resultado:\n");
    imprimir(labirinto);

    return 0;
}
