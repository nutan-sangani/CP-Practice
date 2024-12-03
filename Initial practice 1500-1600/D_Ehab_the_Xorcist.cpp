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

void helper()
{
    
}

int main()
{
    FASTIO
    
    // int t;
    // cin>>t;
    // while(t--)
    {
        ll Xor,sum;
        cin>>Xor>>sum;
        ll diff = (sum-Xor);
        if(diff<0 || diff%2!=0){
            cout<<-1<<endl;
        }
        else{
            if(Xor==0 && diff==0){
                cout<<0<<endl;
            }
            else if(diff==0){
                cout<<1<<endl;
                cout<<Xor<<endl;
            }
            else{
                ll divided = diff/2;
                if((divided | Xor) == (divided+Xor)){
                    cout<<2<<endl;
                    cout<<(divided | Xor)<<" "<<divided<<endl;
                }
                else{
                    cout<<3<<endl;
                    cout<<Xor<<" "<<divided<<" "<<divided<<endl;
                }
            }
        }
    }
    return 0;
}