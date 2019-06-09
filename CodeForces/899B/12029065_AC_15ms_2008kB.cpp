#include<stdio.h>
#include <iostream>
using namespace std;
int a[30];
int main(){
	int arr[]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
	int n;
	cin>>n;
	int i,j;
	for(i=0;i<n;i++) cin>>a[i];
	
	for(j=0;j<36;j++){
		for(i=0;i<n;i++){
			if(arr[(i+j)%36]!=a[i])
				break;
		}
		if(i==n){
		 cout<<"Yes\n"; exit(0);
		}
	}
	cout<<"No"<<endl;
}
