#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float bubble(int *vet, int n){
	int i, j, aux;
	
	clock_t c1, c2;
	float t1;

	c1=clock();
		
	for(i=0;i<n;i++){
    	for(j=i;j<n;j++){
    		if(vet[i]>vet[j]){
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			
			}
		}
    	
	}
	c2 = clock();	
	t1 = ((c2 - c1) * 1000 )/ CLOCKS_PER_SEC;
	
	return t1;
	
	
}

float insert(int *vet, int n){
	
	int i, j, escolha;
	
		clock_t c1, c2;
		float t1;

		c1=clock();
	
	for(i=1;i<n;i++){
		escolha = vet[i];
		j=i-1;
		
			while(j>=0 && escolha < vet[j] ){
			
				vet[j+1] = vet[j];
				j--;
					
			}	
		vet[j+1] = escolha;
	}
	
	c2 = clock();	
	t1 = ((c2 - c1) * 1000 )/ CLOCKS_PER_SEC;
	
	return t1;	
}


float select(int *vet, int n){
	
	int menor, aux;
	
		clock_t c1, c2;
		float t1;

		c1=clock();
	
	for(int i=0;i<n-1;i++){
		menor=i;
		for(int j=i+1;j<n;j++){
			if(vet[j]<vet[menor])
				menor=j;
		}
	
	aux=vet[i];
	vet[i]=vet[menor];
	vet[menor]=aux;
	
	
	}
	
	c2 = clock();	
	t1 = ((c2 - c1) * 1000 )/ CLOCKS_PER_SEC;
	
	return t1;
	
}


int particiona(int *vet, int inicio, int fim){
	int esq, dir, escolha, aux;
	esq = inicio;
	dir = fim;
	escolha = vet[inicio];
	
	while(esq < dir ){
		while(vet[esq] <= vet[dir])
			esq++;
			
		while(vet[dir] > escolha)
			dir--;
			
		if(esq < dir){
			aux = vet[esq];
			vet[esq] = vet[dir];
			vet[dir] = aux;
		}
	}
	vet[inicio] = vet[dir];
	vet[dir] = escolha;
	return dir;
}


float quick(int *vet, int inicio, int fim){
	int escolha;
	
		clock_t c1, c2;
		float t1;

		c1=clock();	
	
	if(fim> inicio){
		escolha = particiona(vet, inicio, fim);
		quick(vet, inicio, escolha-1);
		quick(vet, escolha+1, fim);
	}
	c2 = clock();	
	t1 = ((c2 - c1) * 1000 )/ CLOCKS_PER_SEC;
	return t1;
	
}


void merge(int *vet, int inicio,int meio, int fim){
	int i, j, k;
	int n1= meio - inicio + 1;
	int n2 = fim - meio;
	int Inicio[n1] , Fim[n2];
	
	for(i=0; i<n1;i++)
		Inicio[i] = vet[inicio + i];
	for(j=0;j<n2;j++)
		Fim[j]= vet[meio + 1 + j];
		
	i=0;
	j=0;
	k=1;
	
	while(inicio < n1 && j < n2){
		if(Inicio[i]<=Fim[j]){
			vet[k]=Inicio[i];
			i++;
		}
		else{
			vet[k]= Fim[j];
			j++;
		}
		k++;
	}
	while(j<n2){
		vet[k]=Fim[j];
		j++;
		k++;
	}
}


float mergeSort(int *vet, int inicio, int fim){
	int meio;
	
	clock_t c1, c2;
	float t1;

	c1=clock();
	
	if(inicio < fim){
		meio = (inicio+fim)/2;
		mergeSort(vet,inicio,meio);
		mergeSort(vet, meio+1, fim);
		merge(vet, inicio, meio, fim);
	}
	
	c2 = clock();	
	t1 = ((c2 - c1) * 1000 )/ CLOCKS_PER_SEC;
	return t1;
	
}



int main(){
	int i , j=1000;
	int v1[1000];
	int n1 = 1000;
	int inicio1=0, fim1=1000;
	
	int x; long int y=100000;
	int v2[100000];
	long int n2 = 100000;	
	long int inicio2=0, fim2=100000; 
	
	
	for(i=0;i<n1;i++){
		v1[i]=j;
		j--;
	}
	
	
	for(x=0;x<n2;x++){
			v2[x]=y;
			y--;
	}
	
	
	printf("Bubble Sort\n\n");
	printf("1000 - tempo : %f ms\n", bubble(v1, n1));//funciona
	printf("100000 - tempo : %f ms\n", bubble(v2, n2));
	
	printf("\n\nInsertion Sort\n\n");
	printf("1000 - tempo : %f ms\n", insert(v1, n1));//nao mede
	printf("100000 - tempo : %f ms\n", insert(v2, n2));
	
	printf("\n\nSelection Sort\n\n");
	printf("\n1000 - tempo : %f ms\n", select(v1, n1));//funciona
	printf("\n100000 - tempo : %f ms\n", select(v2, n2));
	
	printf("\n\nMERGE Sort\n\n");
	printf("\n1000 - tempo : %f ms\n", mergeSort(v1, inicio1, fim1));
	printf("\n100000 - tempo : %f ms\n", mergeSort(v2,inicio2, fim2));
	
	printf("\n\nQUICK Sort\n\n");
	printf("\n1000 - tempo : %f ms\n", quick(v1, inicio1, fim1));
	printf("\n100000 - tempo : %f ms\n", quick(v2, inicio2, fim2));
	
	
	
/*	printf("\n\nMerge Sort\n\n");
	clock_t c1, c2;
		float t1;

		c1=clock();
		mergeSort(v1, inicio1, fim1);
		c2 = clock();	
		t1 = ((c2 - c1) * 1000 )/ CLOCKS_PER_SEC;
		printf("%f\n\n", t1);
		
	clock_t c3 , c4 ;
	float t2;	
		
		c3=clock();
		mergeSort(v2, inicio2, fim2);
		c4 = clock();	
		t1 = ((c4 - c3) * 1000 )/ CLOCKS_PER_SEC;
		printf("%f\n\n", t2);*/
		
		
	
	
/*	printf("\n\nQuick Sort\n\n");
	
	
	clock_t c5, c6;
	float t3;
	
	c5=clock();	
	quick(v1, inicio1 , fim1);
	c6 = clock();	
	t3 = ((c6 - c5) * 1000 )/ CLOCKS_PER_SEC;
	printf("%f\n\n",t3);
	
	clock_t c7, c8;
	float t4;

	c7=clock();
	quick(v2, inicio2, fim2);
	c8 = clock();	
	t4 = ((c8 - c7) * 1000 )/ CLOCKS_PER_SEC;
	printf("%d\n\n",t4);*/
	
	
	
}

