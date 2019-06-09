#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main() {
	// your code goes here
	int n,co_1=0;
	cin >> n;
	int P[n];
	memset(P,0,sizeof(P));
	string S[n];
	for(int i=0;i<n;i++) cin>>S[i];
	vector <int> v[10];
	for(int i=0;i<n;i++)
	{
	    v[ S[i][0] - '0' ].pb(i);
	}
/*	
	for(int i=0;i<10;i++)
	{
	    cout<<i<<"  || ";
	    for(int j=0;j<v[i].size() ; j++  )
	     cout<<v[i][j]<<" ";
	     cout<<endl;
	}
*/
	while(co_1<n)
	{
	
	for(int i=0;i<10;i++)
	{
	    if(v[i].size()>0)
	    {
	        vector <int> temp;
	       // cout << v[i][0]+1 << " ";
	        int si=v[i].size(),siz;
	        for(int j=0;j<si;j++) 
	        {
	             cout << v[i][j]+1 << " ";
	            if(P[v[i][j]] >=0  )
	            P[v[i][j]]++;
	            if( P[v[i][j]] == S[v[i][j]].size() ) 
	                {
	                    P[v[i][j] ]=-1;
	                    co_1++;
	                }
	            else
	           {
	                 v[S[ v[i][j] ][ P[v[i][j]] ] - '0'].pb( v[i][j] );  
	           }
	            temp.pb(v[i][j]);
	            siz=temp.size();
	            
	        }
	        while(siz--)
	        {
	            v[i].erase(v[i].begin());
	        }
	        
	        break;
	    }
	}
	
	}
//	for(int i=0 ; i<n ; i++)
//	  cout<<i<<" | "<<P[i]<<endl;
	
	
	
	return 0;
}