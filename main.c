#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
int main(){
	int n,i,k;
	
	do{
	printf("Kare matrisinizin boyutunu giriniz.");
	scanf("%d",&n);
	}while(n<=0);
	
	int **matris = (int **)malloc(n * sizeof(int *));
	if (*matris == NULL) {
        printf("Hata\n");
        return -1; }
              
    for (i = 0; i < n; i++) {
        matris[i] = (int *)malloc(n * sizeof(int));
        if (matris[i] == NULL) {
        printf("Hata\n");
        return -1; }
    }
    
    int **yedek = (int **)malloc(n * sizeof(int *));
	if (*yedek == NULL) {
        printf("Hata\n");
        return -1; }
              
    for (i = 0; i < n; i++) {
        yedek[i] = (int *)malloc(n * sizeof(int));
        if (yedek[i] == NULL) {
        printf("Hata\n");
        return -1; }
    }
    
	for(i=0;i<n;i++){
		printf("\nMatrisin %d. satiri: ", i+1);
		for(k=0;k<n;k++){
			scanf("%d",&matris[i][k]);
		}
	}
	
	char choose;
	
	do{
		printf("\n\nYapmak istediginiz islemi girin saga dondurmek icin(R),\n");
		printf("Yapmak istediginiz islemi girin sola dondurmek icin(L),\n");
		printf("Cikis yapmak icin(E).\n");
		
		scanf(" %c",&choose);
		
	    if(choose=='R'){
	    	matriscopy(matris,yedek,n);
	    	for(i=0;i<n;i++){
	    		for(k=0;k<n;k++){
	    			matris[k][n-1-i]=yedek[i][k];
				}
			}
			for(i=0;i<n;i++){
				printf("\n");
				for(k=0;k<n;k++){
					printf("%d ",matris[i][k]);
				}
			}
			printf("\n");
		}
		
		if(choose=='L'){
			matriscopy(matris,yedek,n);
	    	for(i=0;i<n;i++){
	    		for(k=0;k<n;k++){
	    			matris[n-i-1][k]=yedek[k][i];
				}
			}
			for(i=0;i<n;i++){
				printf("\n");
				for(k=0;k<n;k++){
					printf("%d ",matris[i][k]);
				}
			}
			printf("\n");
		}
	}while(choose!='E');
	
	for(i=0;i<n;i++){
		printf("\nSon durum\n");
		for(k=0;k<n;k++){
			printf("%d",matris[i][k]);
		}
	}
	
	for (i = 0; i < n; i++) {
        free(yedek[i]);
        free(matris[i]);
    }
    free(matris);
    free(yedek);
	
	
	}
