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

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int valid=0;
        vector<string> arr(n,".");
        string ans;
        um<ll,vecll> index; //index:wrong
        int maxWrong=0;
        int flag=0;
        umll mistakeCount;
        forn(0,n){
            cin>>arr[i];
            if(i==0){
                ans=arr[i];
            }
            else{
                int cnt = 0;
                for(int j=0;j<m;j++){
                    if(arr[i][j]!=ans[j]){
                        index[j].pb(i);
                        cnt++;
                    }
                }
                maxWrong = max(maxWrong,cnt);
                mistakeCount[i]=cnt;
                if(cnt>0) valid++;
            }
        }
        if(maxWrong>2){
            cout<<-1<<endl;
            flag=1;
        }
        if(maxWrong<=1 && flag==0){
            cout<<ans<<endl;
            flag=1;
        }
        if(flag==0){
            for(auto x : index){
                if(x.second.size()==valid){
                    char val;
                    int isSecond=0;
                    forn(0,x.second.size()){
                        if(mistakeCount[x.second[i]]==2){
                            val = arr[x.second[i]][x.first];
                            isSecond=1;
                            break;
                        }
                    }
                    if(isSecond!=1){
                        continue;
                    }
                    int allSame=0;
                    forn(0,x.second.size()){
                        if(val!=arr[x.second[i]][x.first] && mistakeCount[x.second[i]]!=1){
                            break;
                        }
                        if(i==(x.second.size()-1)){
                            allSame=1;
                        }
                    }
                    if(allSame){
                        forn(0,m){
                            if(i!=x.first){
                                cout<<ans[i];
                            }
                            else cout<<val;
                        }
                        cout<<endl;
                        flag=1;
                        break;
                    }
                }
                else continue;
            }
        }
        if(flag==0){
            cout<<-1<<endl;
        }
    }
    return 0;
}