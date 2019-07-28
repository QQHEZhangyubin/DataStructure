//https://www.cnblogs.com/jingmoxukong/p/4302718.html
#include<stdio.h>
int main(){
	int a[] = {10,18,4,3,6,12,1,9,15,8,45,48,49,52,57,15,14,16,23};
	int alength = sizeof(a)/sizeof(a[0]);
	for(int i=0;i< alength-1;i++){
		bool flag = false;
		for(int j=alength-1;j>i;j--){
			//从后往前，两两比较 
			if(a[j-1]>a[j]){
				int temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
				flag = true;
			}
		}
		if(!flag){
			break;	
		}
	}
	for(int k =0;k<alength;k++){
		printf("%d " ,a[k]);
	}
	return 0;
} 
