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

char getOppositeColor(char a)
{
    return a=='B' ? 'R' : 'B';
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        vector<vector<char>> rows(n,vector<char> (m-1,'R'));
        vector<vector<char>> cols(n-1,vector<char> (m,'R'));
        ll firstPath = n-1+m-1;
        if(k-firstPath<0){
            cout<<"NO"<<endl;
        }
        else{
            k-=firstPath;
            if(k%2==0){
                cout<<"YES"<<endl;
                int checkNo = 1;
                if((n-1)%2!=0)
                    checkNo=0;
                forn(0,m-1){
                    if(i%2==checkNo)
                        rows[n-2][i] = rows[n-1][i] = 'B';
                }
                forn(0,n-1){
                    if(i%2!=0)
                        cols[i][0]='B';
                }
                cols[0][1]='B';
                char oppo = getOppositeColor(rows[n-1][m-2]);
                cols[n-2][m-1] = cols[n-2][m-2] = oppo;
                forn(0,n){
                    for(int j=0;j<m-1;j++)
                        cout<<rows[i][j]<<" ";
                    cout<<endl;
                }
                forn(0,n-1){
                    for(int j=0;j<m;j++)
                        cout<<cols[i][j]<<" ";
                    cout<<endl;
                }
            }
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}