#include <stdio.h>
#include <stdlib.h>


int somaR(int n){
	if(n == 1 || n == 0){
		return n;
	}
	
	return n + somaR(n-1);
}

int somaParR(int n){
	if(n == 2){
		return 2;
	}
	
	if (n == 1 || n == 0){
		return 0;
	}
	
	if(n % 2 == 1){
		n--;
	}
	
	return n + somaParR(n-2);
}

int buscaSequencialR(int *vet, int tam, int n, int i){
	// critério de parada
	// elemento não encontrado no vetor
	if(i == tam){
		return -1;
	}
	
	// elemento encontrado
	if(n == vet[i]){
		return i;
	}
	
	return buscaSequencialR(vet, tam, n, i+1);	
}

void mostraVetorR(int *vet, int tam, int i){
	if(i == tam){
		printf("\n");
		return;
	}
	
	printf("%d ", vet[i]);
	mostraVetorR(vet, tam, i+1);
}

int somaElementosParesR(int *vet, int tam, int i){
	if(i == tam){
		return 0;
	}
	
	if(vet[i] % 2 == 0){
		return vet[i] + somaElementosParesR(vet, tam, i+1);
	} else {
		return 0 + somaElementosParesR(vet, tam, i+1);
	}
}

int somaPosicoesParesR(int *vet, int tam, int i){
	if(i >= tam){
		return 0;
	}
	
	if(i % 2 == 1){
		i++;
	}
	
	return vet[i] + somaPosicoesParesR(vet, tam, i+2);
}

int buscaBinariaR(int *vet, int n, int i, int j){
	if(i > j){
		return -1;
	}
	
	int k = (i + j) / 2;
	
	if(n == vet[k]){
		return k;
	} else if(n > vet[k]){
		return buscaBinariaR(vet, n, k+1, j);
	} else {
		return buscaBinariaR(vet, n, i, k-1);
	}
	
}



main(){
	int vet[5] = {10, 5, 9, 4, 3};
	int pos = buscaSequencialR(vet, 5, 19, 0);
	printf("Posicao: %d\n", pos);
	mostraVetorR(vet, 5, 0);
	
	int soma = somaElementosParesR(vet, 5, 0);
	printf("Soma: %d\n", soma);
	
	int vet2[7] = {10, 5, 9, 4, 3, 2, 8};
	pos = buscaSequencialR(vet2, 7, 2, 0);
	printf("Posicao: %d\n", pos);
	mostraVetorR(vet2, 7, 0);
	
	
	
	
	soma = somaR(5);
	printf("Soma recursiva: %d\n", soma);
	
	soma = somaParR(7);
	printf("Soma par recursiva: %d\n", soma);
}
