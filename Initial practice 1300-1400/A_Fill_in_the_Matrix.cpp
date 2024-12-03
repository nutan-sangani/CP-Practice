#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void helper(int n,int m)
{
    int ans;
    if(m==1){
        ans=0;
    }
    else{
        if(n>=m){
            ans=m;
        }
        else ans=n+1;
    }
    vector<vector<int>> matrix(n,vector<int> (m,0));
    int row=0;
    int j=0;
    while(row<n)
    {
        if(j<m-1){
            j++;
        }
        int i=j;
        int col=0;
        while(col<m){
            matrix[row][col]=i;
            i=(i+1)%m;
            col++;
        }
        row++;
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            cout<<matrix[i][k]<<" ";
        }
        cout<<endl;
    }
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>n>>m;
        helper(n,m);
    }
    return 0;
}