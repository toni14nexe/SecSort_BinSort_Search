#include <stdio.h>
#include <stdlib.h>

void gen_arr(int[], int, int, int);
int sekv_pret(int[], int, int);
void sort( int[], int);
void zamijena(int*, int*);
int bin_pret(int[], int, int);
int brojac;

int main(){
	int V[100];
	int n = sizeof(V) / sizeof(int);
	int dg, gg, x, ind = 0;
	printf("Unesite donju granicu: ");
	scanf("%d", &dg);
	printf("Unesite gornju granicu: ");
	scanf("%d", &gg);
	printf("Unesite trazeni broj: ");
	scanf("%d", &x);
	printf("\n");
	gen_arr(V, n, dg, gg);
	ind = sekv_pret(V, n, x);
	printf("\n");
	if(ind > 0){
		printf("\nUneseni broj je pronaden na mjestu: %d\n\n", ind+1);
	}
	else{
		printf("\nUneseni broj nije pronaden!\n\n");
	}
	sort(V, n);
}
	
void gen_arr(int V[], int n, int dg, int gg){
	for(int i=0; i<n; i++){
		V[i] = rand() % gg +dg;
		printf("%d ", V[i]);
	}
}
	
int sekv_pret(int V[], int n, int x ){
	for(int i=0; i<n; i++){
		if(V[i] == x){
			return i;;
		}
	}
	return 0;
}

void sort(int V[], int n ){
	int priv;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(V[j] > V[j+1]){
				zamijena(&V[j], &V[j+1]);
			}
		}
	}  
	for(int i=0; i<n; i++){
		printf("%d ", V[i]);
	}
	printf("\n\nUnesite trazeni broj: ");
	int x;
	scanf("%d", &x);
	printf("\n");
	bin_pret(V, n ,x);
}

void zamijena(int *x, int *y)  
{  
    int priv = *x;  
    *x = *y;  
    *y = priv;  
} 

int bin_pret(int V[], int n, int x ){
	int dg=0;
	int gg=sizeof(V) / sizeof(int);
	int i=-1;
	int brojac=0;
	while(dg<=dg){
		i=(dg+gg)/2;
		brojac++;
		if(V[i] == x){
			printf("\nUneseni broj je pronaden na mjestu: %d\n\n", i+1);
			return i;
		}
		else if (V[i] > x){
			gg=i-1;
		}
		else{
			dg=i+1;
		}
		if(brojac>n){
			printf("\nUneseni broj nije pronaden!\n\n");
			return -1;
		}
	}
	return -1;
}
