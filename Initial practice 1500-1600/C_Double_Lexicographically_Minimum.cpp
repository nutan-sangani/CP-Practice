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
        string s;
        cin>>s;
        int i,j;
        int n = s.size();
        map<int,int> count;
        int uniqueCount = 0;
        forn(0,n){
            if(count[s[i]]==0){
                ++uniqueCount;
            }
            count[s[i]]++;
        }
        deque<int> q;
        vector<char> ans(n,'.');
        i=0;
        j=n-1;
        int flag=0;
        for(pll x : count){
            int cnt = x.second;
            uniqueCount--;
            if(flag==1){
                while(cnt){
                    ans[i++]=x.first;
                    cnt--;
                }
            }
            if(flag==2){
                if(cnt%2!=0){
                    cnt--;
                    q.push_back(x.first);
                }
                while(cnt){
                    cnt-=2;
                    ans[i++]=x.first;
                    ans[j--]=x.first;
                }
                while(!q.empty()){
                    ans[i++]=q.back();
                    q.pop_back();
                }
            }
            else if(cnt%2!=0){
                if(uniqueCount>1){
                    while(cnt>1){
                        cnt-=2;
                        ans[i++]=x.first;
                        ans[j--]=x.first;
                    }
                    ans[j]=x.first;
                    cnt--;
                    flag=1;
                }
                else{
                    flag=2;
                    q.push_back(x.first);
                    cnt--;
                    while(cnt){
                        cnt-=2;
                        ans[i++]=x.first;
                        ans[j--]=x.first;
                    }
                }
            }
            else{
                while(cnt){
                    cnt-=2;
                    ans[i++]=x.first;
                    ans[j--]=x.first;
                }
            }
        }
        while(!q.empty()){
            ans[i++]=q.back();
            q.pop_back();
        }
        forn(0,n){
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
//1 2 3 4 5
//1 2 3 4 5 6