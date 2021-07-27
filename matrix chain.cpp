#include<bits/stdc++.h>
using namespace std;
int min_chain(int a[],int **s,int n){
	int dp[n][n];
/*	for(int i=0;i<n-1;i++){
		dp[i][i+1]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			dp[i][j]=0;
		
	}*/
	for(int i=1;i<n-1;i++){
		s[i][i+2]=i+1;	
	}	
	for(int gap=2;gap<n;gap++){
		for(int i=0;i<n-gap;i++){
			int j=i+gap;
			dp[i][j]=INT_MAX;
			for(int k=i+1;k<j;k++){
				if(dp[i][j]>dp[i][k]+dp[k][j]+a[i]*a[j]*a[k]){
					dp[i][j]=dp[i][k]+dp[k][j]+a[i]*a[j]*a[k];
					s[i+1][j]=k;
				}
				
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	return dp[0][n-1];
}
void printPar(int **s,int i,int j){

	if(i==j)
		cout<<"A"<<i;
	else{
		cout<<"{";
		printPar(s,i,s[i][j]);
		printPar(s,s[i][j]+1,j);
		cout<<"}";
	}
	
}
int main(void){
	int n;
	
	cin>>n;
	int a[n];
	int **s=(int **)malloc(sizeof(int*)*(n-1));
	for(int i=0;i<n;i++){
		int *f=(int*)malloc(sizeof(int)*(n-1));
		for(int j=0;j<n;j++)
			*(f+j)=0;
		*(s+i)=f;
	}
	for(int i=0;i<n;i++)
		cin>>a[i];

	cout<<min_chain(a,s,n)<<endl;
	printPar(s,1,n-1);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<s[i][j]<<" ";
		cout<<endl;
	}	
}
