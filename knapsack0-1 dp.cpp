#include<bits/stdc++.h>
using namespace std;
int max_profit(int w[],int v[],int c,int n,vector<pair<int,int> > &e){
	int dp[c+1][n+1];
	for(int i=0;i<=c;i++)
		dp[i][0]=0;
	for(int i=0;i<=n;i++){
		dp[0][i]=0;
		
	}
				
	for(int i=1;i<=c;i++){
		for(int j=1;j<=n;j++){
			if(i<w[j-1])
				dp[i][j]=dp[i][j-1];
			else{
				if(dp[i-w[j-1]][j-1]+v[j-1]>dp[i][j-1]){
					dp[i][j]=dp[i-w[j-1]][j-1]+v[j-1];
					
					
				}
				else{
					dp[i][j]=dp[i][j-1];
					
				}
				
			}
				
		}
	}
	int max=dp[c][n],wt=c;
	for(int i=n;i>0;i--){
		if(max==dp[wt][i-1])
			continue;
		else{
			max-=v[i-1];
			wt-=w[i-1];
			pair<int,int> t;
			t.first=v[i-1];
			t.second=w[i-1];
			e.push_back(t);
		}
		if(!max)
			break;
	}
	return dp[c][n];
}
int main(void){
	int n;
	cout<<"Total number of items-";
	cin>>n;
	int v[n],w[n];
	cout<<"Weights of items-";
	for(int i=0;i<n;i++)
		cin>>w[i];
	int item[n];
	cout<<"Values of items-";
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<"Total capacity-";
	int c;
	cin>>c;
	vector<pair<int,int> > e;
	cout<<max_profit(w,v,c,n,e)<<endl;
	cout<<"The Elements That has been taken-"<<endl;
	cout<<"Values-";
	for(int i=0;i<e.size();i++){
		cout<<e[i].first<<" ";
	}
	cout<<endl<<"Weights-";
	for(int i=0;i<e.size();i++){
		cout<<e[i].second<<" ";
	}
}


