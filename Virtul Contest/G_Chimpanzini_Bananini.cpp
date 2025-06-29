#include <iostream>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll,custom_hash>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;
using namespace __gnu_pbds;

void debug(){
    cout<<endl;
}

template<typename T,typename... Args>
void debug(T firstArg,Args... args){
    cout<<firstArg<<" ";
    debug(args...);
}

template<typename T>
void printArray(vector<T>& a){
    int n = a.size();
    forn(0,n) cout<<a[i]<<" ";
    cout<<endl;
}

template<typename T>
void printMatrix(vector<vector<T>>& a){
    int rows = a.size();
    forn(0,rows){
        printArray(a[i]);
    }
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll cyclicShiftRightForNums(deque<ll>& nums,ll sum,ll score){
    ll last = nums.back();
    ll size = nums.size();
    nums.pop_back();
    nums.push_front(last);
    score += (sum - last);
    score -= (size*last);
    score += last;
    return score;
}

ll cyclicShiftLeftForReverse(deque<ll>& nums,ll sum,ll score){
    ll first = nums.front();
    ll size = nums.size();
    nums.pop_front();
    nums.push_back(first);
    score -= first;
    score -= (sum - first);
    score += (first*size);
    return score;
}

void solve(){
    ll q;
    cin>>q;
    deque<ll>* nums = new deque<ll>;
    deque<ll>* reverse = new deque<ll>;
    ll sum = 0;
    ll reverseScore = 0;
    ll directScore = 0;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            directScore = cyclicShiftRightForNums(*nums,sum,directScore);
            reverseScore = cyclicShiftLeftForReverse(*reverse,sum,reverseScore);
            cout<<directScore<<endl;
        }
        else if(type==2){
            deque<ll>* temp = nums;
            nums = reverse;
            reverse = temp;
            ll tempScore = reverseScore;
            reverseScore = directScore;
            directScore = tempScore;
            cout<<directScore<<endl;
        }
        else{
            ll elem;
            cin>>elem;
            (*nums).push_back(elem);
            (*reverse).push_front(elem);
            directScore += (elem)*((*nums).size());
            reverseScore += sum;
            reverseScore += elem;
            sum+=elem;
            cout<<directScore<<endl;
        }
    }
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