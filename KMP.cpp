/**
����ı����ĳ���Ϊn��
ģʽ���ĳ���Ϊm����ôƥ����̵�ʱ�临�Ӷ�ΪO(n)��
���ϼ���next��O(m)ʱ�䣬KMP������ʱ�临�Ӷ�ΪO(m + n)��
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
	*�ɻ�Next( , ) ���յĲ���ֵ�����𣬻�û�з��������飬�����Ļ������ڲ�����next���鲻��������ʲôҲû���� 
	*���ͣ����������������֣��������ô��ݣ�����������������׵�ַ����ַ�����Ժ��ǲ����ģ�����Next()���������Ժ�ֻ�������
	*���޸����������ݣ��Ե�ַ��û��Ӱ�졣 
	*/
	printf("%x \n",next);
	Next(pattern,next);
	printf("%x \n",next);
	int length1 = text.length();
	int length2 = pattern.length();
	cout<<length1<<endl;
	cout<<length2<<endl;
	/*
	*�����Ҵ�ӡ��Next�����е����� 
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
