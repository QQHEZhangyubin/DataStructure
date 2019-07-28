/**
*Ï£¶ûÅÅĞò 
*/
#include<stdio.h>
void ShellInsert(int a[],int dk){
	int i,j;
	for(i = dk;i<19;i++){
		if(a[i]  < a[i-dk]){
			int temp = a[i];
			for(j =i-dk;j>=0 && temp < a[j];j = j-dk){
				a[j+dk] = a[j];
			}
			a[j+dk] = temp;
		}
	}
} ;
void Vprint(int a[]){
	for(int m =0;m<10;m++){
		printf("%d ",a[m]);
	}	
}
int main(){
	int a[] = {10,18,4,3,6,12,1,9,15,8,45,48,49,52,57,15,14,16,23};
	int d[5] = {9,7,5,3,1};
	
	for(int k=0;k<5;k++){
		ShellInsert(a,d[k]);
		Vprint(a);
		printf("\n");
	}
	/*
	int n  = 10;
	int h = 1;
	while(h < n/3){
		h = 3 * h +1;
	} 

	while(h >= 1){
		printf("ÔöÁ¿ĞòÁĞH=%d \n",h);
	for(int m =0;m<10;m++){
		printf("%d ",a[m]);
	}
	printf("\n");
		for(int i=h;i<n;i++){
			int e = a[i];
			int j ;
			for(j =i;j>=h&&e<a[j-h];j-=h){
				a[j]=a[j-h];
			}
			a[j] = e;
		}
		
		h/=3;
	}
	*/

	
	return 0;
}
