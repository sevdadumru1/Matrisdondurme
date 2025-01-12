#include "mylib.h"
void matriscopy(int **matris1, int **matris2, int boyut){
	int i,k;
	for(i=0;i<boyut;i++){
		for(k=0;k<boyut;k++){
			matris2[i][k]=matris1[i][k];
		}
	}
}
