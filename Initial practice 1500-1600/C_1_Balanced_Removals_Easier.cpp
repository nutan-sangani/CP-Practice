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

int first;

struct Axes{
    public:
        int x;
        int y;
        int z;
        int index;
    Axes(int x,int y,int z,int index){
        this->x=x;
        this->y=y;
        this->z=z;
        this->index=index;
    }

    void display(){
        cout<<this->x<<" "<<this->y<<" "<<this->z<<" "<<this->index<<endl;
    }
};

class MyComp{
    public:
    bool operator()(const Axes& a,const Axes& b){
        if(a.x!=b.x) return a.x<b.x;
        else if(a.y!=b.y) return a.y<b.y;
        else return a.z<=b.z;
    }
};

void helper(vector<Axes>& nums,int n)
{
    vector<pll> ans;
    vector<Axes> tp(nums);
    vecll rem2;
    int flag=0;
    int count=0;
    while(nums.size()>0){
        vecll rem;
        sort(itr(nums),MyComp());
        int i = 0;
        int n = nums.size();
        if(flag>=2){
            int z=0;
            while(z+1<nums.size()){
                ans.pb(mp(nums[z].index,nums[z+1].index));
                z+=2;
            }
            break;
        }
        while(i<n){
            int start=i;
            while(i+1<n && nums[i].x==nums[i+1].x) i++;
            int end=i;
            i++;
            if(start==end && flag<2){
                rem.pb(nums[start].index);
                continue;
            }
            if(flag>=1){
                flag++;
                int k=start;
                while(k<end){
                    ans.pb(mp(nums[k].index,nums[k+1].index));
                    k+=2;
                }
                int size = end - start + 1;
                if(size%2!=0)
                    rem.pb(nums[end].index);
                continue;
            }
            int j = start;
            vecll temp;
            while(j<=end){
                int sy,ey;
                sy=j;
                while(j<end && nums[j].y==nums[j+1].y){
                    j++;
                }
                ey=j;
                j++;
                int k = sy;
                if(sy==ey){
                    rem.pb(nums[sy].index);
                    continue;
                }
                while(k<ey){
                    ans.pb(mp(nums[k].index,nums[k+1].index));
                    k+=2;
                }
                int size = ey-sy+1;
                if(size%2!=0){
                    rem.pb(nums[ey].index);
                }
            }
        }
        nums.clear();
        forn(0,rem.size()){
            nums.pb(tp[rem[i]-1]);
        }
        rem.clear();
        flag++;
    }
    int i=0;
    while(i<rem2.size()){
        ans.pb(mp(rem2[i],rem2[i+1]));
        i+=2;
    }
    if(ans.size()!=n/2) cout<<"OOOHHH NOO"<<endl;
    i=0;
    for(int j=0;j<ans.size();j++){
        cout<<ans[j].first<<" "<<ans[j].second<<endl;
    }
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    vector<Axes> nums;
    forn(0,t){
        ll a,b,c;
        cin>>a>>b>>c;
        if(i==0){
            first=a;
        }
        Axes nn(a,b,c,i+1);
        nums.pb(nn);
    }
    helper(nums,t);
    return 0;
}
//bahot simple tha, plain tarike se krta toh pta chalta ki 3 pass me hojayega.