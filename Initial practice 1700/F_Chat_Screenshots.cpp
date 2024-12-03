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

bool checkAns(vecll& ans,vecll& given){
    int first = given[0];
    int n = given.size();
    int i=0,j=1;
    while(i<n && j<n){
        if(ans[i]==first){
            i+=1;
            continue;
        }
        if(ans[i]!=given[j]){
            return false;
        }
        else{
            i+=1;
            j+=1;
        }
    }
    return true;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<vecll> matrix(k,vecll (n,0));
    forn(0,k){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    if(k==1 || n==2){ //since n==1 hua means k==1
        cout<<"YES"<<endl;
        return;
    }
    pll firstKa,secondKa;
    ll first,second;
    first = matrix[0][0];
    second = matrix[1][0];
    if(k==2){
        int i,j;
        i=j=1;
        while(i<n && j<n){
            if(matrix[0][i]==first || matrix[0][i]==second){
                i+=1;
                continue;
            }
            else if(matrix[1][j]==first || matrix[1][j]==second){
                j+=1;
                continue;
            }
            else if(matrix[0][i]==matrix[1][j]){
                i+=1;
                j+=1;
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
        return;
    }
    forn(1,n){
        if(matrix[1][i]==first){
            int prev = i>1 ? matrix[1][i-1] : -1;
            firstKa.first = prev;
            int next = i<(n-1) ? matrix[1][i+1] : -1;
            firstKa.second = next;
        }
        if(matrix[0][i]==second){
            int prev = i>1 ? matrix[0][i-1] : -1;
            secondKa.first = prev;
            int next = i<(n-1) ? matrix[0][i+1] : -1;
            secondKa.second = next;
        }
    }
    vecll ans;
    //-1,1
    //1,-1
    if(firstKa.first==secondKa.first && firstKa.second==secondKa.second){
        //means k>=3
        pll order;
        forn(1,n){
            if(matrix[2][i]==first || matrix[2][i]==second){
                order.first = matrix[2][i];
                order.second = matrix[2][i+1];
                break;
            }
        }
        forn(1,n){
            if(matrix[0][i]==first || matrix[0][i]==second){
                ans.pb(order.first);
                ans.pb(order.second);
                continue;
            }
            else {
                ans.pb(matrix[0][i]);
            }
        }
    }
    else{
        int prev=-1;
        forn(1,n){
            if(prev==firstKa.first){
                ans.pb(first);
            }
            ans.pb(matrix[0][i]);
            prev=matrix[0][i];
        }
        if(prev==firstKa.first){
            ans.pb(first);
        }
    }
    if(ans.size()!=n){
        cout<<"hag diya code ne"<<endl;
    }
    forn(0,k){
        if(!checkAns(ans,matrix[i])){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}