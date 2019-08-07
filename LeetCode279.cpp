#include<iostream>
#include<cmath>
using namespace std;
int numSquares(int n){
	while(n%4 == 0){
		n/=4;
	}
	if(n%8 == 7){
		return 4;
	}
	for(int a=0;a*a<=n;a++){
		int b = sqrt(n-a*a);
		if(a*a + b*b == n){
			return !!a + !!b;
		}
		
	} 
	return 3;	
};
int main(){
	
	
	int n;
	cin>>n;
	int num = numSquares(n);
	cout<<num<<endl;
	int k;
	//cin>>k;
	//cout<<!!k;
	return 0;
}
