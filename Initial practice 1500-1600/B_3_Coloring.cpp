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

int getInput(){
    int color;
    cin>>color;
    return color;
}

void printOutPut(int color,int i,int j){
    cout<<color<<" "<<i<<" "<<j<<endl;
    cout.flush();
}

int main()
{
    FASTIO
    
    {
        queue<pll> qBlack; //black = 1
        queue<pll> qWhite; //white = 2
        int n;
        cin>>n;
        ll blackCount,whiteCount;
        blackCount = whiteCount = (pow(n,2)/2);
        ll nSquared = pow(n,2);
        if((nSquared%2)) blackCount++;
        forn(1,n+1){
            if(i%2==0){
                for(int j=1;j<=n;j++){
                    if(j%2!=0) qWhite.push(mp(i,j));
                    else qBlack.push(mp(i,j));
                }
            }
            else{
                for(int j=1;j<=n;j++){
                    if(j%2!=0) qBlack.push(mp(i,j));
                    else qWhite.push(mp(i,j));
                }
            }
        }
        forn(0,nSquared){
            int aliceColor = getInput();
            // cout<<aliceColor<<endl;
            if(aliceColor!=1 && blackCount>0){
                pll p = qBlack.front();
                qBlack.pop();
                printOutPut(1,p.first,p.second);
                --blackCount;
                continue;
            }
            else if(aliceColor!=2 && whiteCount>0){
                pll p = qWhite.front();
                qWhite.pop();
                printOutPut(2,p.first,p.second);
                --whiteCount;
                continue;
            }
            else{
                if(whiteCount>0){
                    pll p = qWhite.front();
                    qWhite.pop();
                    printOutPut(3,p.first,p.second);
                    --whiteCount;
                    continue;
                }
                else{
                    pll p = qBlack.front();
                    qBlack.pop();
                    printOutPut(3,p.first,p.second);
                    --blackCount;
                    continue;
                }
            }
        }
    }
    return 0;
}