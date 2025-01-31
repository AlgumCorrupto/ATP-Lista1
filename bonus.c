// Jogo da velha em C

#include <stdio.h>
#include <stdlib.h>

#define SIZE 3
#define AT(X,Y) (SIZE*(Y))+(X)

typedef enum {
	NOBODY = 0,
	O = 1,
	X = 2,
} turn;
 
// like the functional langs reduce
int ReduceAnd(int *array, int size) {
	int buff = 1;

	for(int i = 0; i < size; i++) {
		buff = buff & array[i];
	}

	return buff;
}

int CheckWinCond(turn *field, turn currTurn) {
	// check if achieved horizontal win
	for(int i = 0; i < SIZE; i++) {
		int hWin[3] = {0,0,0};
		for(int j = 0; j < SIZE; j++) {
			if(field[AT(i,j)] == currTurn) {
				hWin[j] = 1;	
			}		
		}
		if (ReduceAnd(hWin, SIZE) == 1) {
			return 1;
		}
	}
	// check if achieved vertical win
	// NOTE: I dont quite know if this scheisse is right
	for(int j = 0; j < SIZE; j++) {
		int vWin[3] = {0,0,0};
		for(int i = 0; i < SIZE; i++) {
			if(field[AT(i,j)] == currTurn) {
				vWin[i] = 1;	
			}		
		}
		if (ReduceAnd(vWin, SIZE) == 1) {
			return 1;
		}
	}
	// check if achieved diagonals win
	int d1Win[3] = {0,0,0};
	int d2Win[3] = {0,0,0};
	for(int i = 0; i < SIZE; i++) {
		if(field[AT(i,i)] ==  currTurn) {
			d1Win[i] = 1;
		}	
		if(field[AT(i, SIZE - i - 1)] == currTurn) {
			d2Win[i] = 1;
		}
	}	
	if (ReduceAnd(d1Win, SIZE) == 1) {
		return 1;
	}
	if (ReduceAnd(d2Win, SIZE) == 1) {
		return 1;
	}

	return 0;
}

void BuildField(turn *field) {
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			field[AT(i,j)] = NOBODY;
		}
	}	
}

void PrintTurn(turn myTurn) {
	switch(myTurn) {
		case NOBODY:
			printf("-");
			break;
		case O:
			printf("O");
			break;
		case X: 
			printf("X");
			break;

	}
}

int PlayTurn(turn *field, turn currTurn) {
	printf("Digite a coordenada do lugar para jogar: ");
	PrintTurn(currTurn);
	printf("\n");
	int x, y = 1;
	scanf("%d %d", &y, &x);
	//printf("X: ");
	//scanf("%d", &x);
	//printf("\nY: ");
	//scanf("%d", &y);
	//printf("\n");

	if(x > SIZE && y > SIZE) {
		printf("Coordenada fora dos limites.\n");
		return 0;		
	}
	if(field[AT(x-1,y-1)] != NOBODY) {
		printf("Essa posicao ja esta ocupada.\n");
		return 0;
	}
	field[AT(x-1,y-1)] = currTurn;
	printf("\n");
	return 1;
}

void DrawField(turn *field) {
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			PrintTurn(field[AT(i,j)]);
			printf(" ");		
		}	
		printf("\n");
	}
}

int main() {
	turn whoWon = NOBODY;
	int turnCount = 0;
	turn currTurn = X;
	turn field[SIZE * SIZE];
       	BuildField(field);
	while((whoWon == NOBODY) && (turnCount <= 9)) {
		turnCount++;
		DrawField(field);
		int successfullTurn = 0;
		while (successfullTurn == 0) {
			successfullTurn = PlayTurn(field, currTurn);	
		}
		int won = CheckWinCond(field, currTurn);
		if(won == 1) {
			whoWon = currTurn;	
		}
		// switchup turns
		switch(currTurn) {
			case X:
				currTurn = O;
				break;
			case O: 
				currTurn = X;
				break;	
		}
	}
	if (whoWon == NOBODY) {
		printf("Ninguem ganhou essa partida!\n");	
	} else {
		printf("O jogador que ganhou essa partida foi: ");	
		PrintTurn(whoWon);
		printf("\n");
	}
	return 0;
}
