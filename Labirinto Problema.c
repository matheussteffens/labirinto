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

void imprimir(int lab[20][12]){
	int i, j;

	for(i = 0; i < 20; i++){
		printf("|");
		for(j = 0; j < 12; j++){
			int n = lab[i][j];
			switch(n){
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


int main(){
	printf("Labirinto:\n");
	imprimir(labirinto);
}
