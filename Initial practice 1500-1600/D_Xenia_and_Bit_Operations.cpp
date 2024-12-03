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
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

int main()
{
    FASTIO
    
    {
        int n,m;
        cin>>n>>m;
        vector<vecll> matrix((n+1),vecll((pow(2,n)+1),0));
        forn(0,pow(2,n)){
            int a;
            cin>>a;
            matrix[0][i+1]=a;
        }
        int size = pow(2,n);
        forn(0,n){
            int j=1;
            while(j<=size){
                ll val = -1;
                if(i==0 || i%2==0){
                    val = matrix[i][j] | matrix[i][j+1];
                }
                else{
                    val = matrix[i][j] ^ matrix[i][j+1];
                }
                int parent = (j+1)/2;
                j+=2;
                matrix[i+1][parent]=val;
            }
            size/=2;
        }
        forn(0,m){
            int a,b;
            cin>>a>>b;
            matrix[0][a] = b;
            int j = 0;
            while(j<n){
                if(a%2==0) --a;
                int parent = (a+1)/2;
                int val = -1;
                if(j==0 || j%2==0)
                    val = matrix[j][a] | matrix[j][a+1];
                else val = matrix[j][a] ^ matrix[j][a+1];
                matrix[j+1][parent] = val;
                a=parent;
                ++j;
            }
            cout<<matrix[n][1]<<endl;
        }
    }
    return 0;
}