/**
如果文本串的长度为n，
模式串的长度为m，那么匹配过程的时间复杂度为O(n)，
算上计算next的O(m)时间，KMP的整体时间复杂度为O(m + n)。
*/ 
#include<iostream>
#include<string>
#include<iterator>
using namespace std;
 void Next(string pattern,int next[]){
	int length = pattern.length();
	next[0] = -1;
	int j = -1;
	for(int i=1;i<length;i++){
		while(j>-1 && pattern[j+1] != pattern[i]){
			j = next [j];
		}
		if(pattern[j+1] == pattern[i]){
			j++;
		}
			next[i] = j;
	}  
	
};

void Match(string text,string pattern,int next[]){
	/**
	*疑惑：Next( , ) 接收的不是值传递吗，还没有返回新数组，这样的话，后期操作的next数组不就是里面什么也没有吗？ 
	*解释：函数本身传数组名字，就是引用传递，数组名就是数组的首地址，地址分配以后是不会变的，所以Next()函数接收以后，只是在添加
	*和修改数组中数据，对地址并没有影响。 
	*/
	printf("%x \n",next);
	Next(pattern,next);
	printf("%x \n",next);
	int length1 = text.length();
	int length2 = pattern.length();
	cout<<length1<<endl;
	cout<<length2<<endl;
	/*
	*这里我打印了Next数组中的数据 
	*/ 
	for(int i=0;i<7;i++){
		cout<<next[i]<<" ";
	}
	cout<<endl;
	int j = -1;
	for(int i=0;i<length1;i++){
		while(j>-1 && pattern[j+1] != text[i]){
			j = next[j];
		}
		if(pattern[j+1] == text[i]){
			j++;
		}
		if(j == length2-1){
			cout<<"Pattern occurs with shift "<<i-length2+1<<endl;
			j = next[j];
		}
	}
	
	
}
int main(){
	string text = "bbcabcdababcdabcdabde";
	string pattern = "abcdabd";
	int next[7];
	Match(text,pattern,next);
} 
