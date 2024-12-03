import java.util.*;

public class C_Removing_Smallest_Multiples
{
    public static void main(String[] args) {
        int t=0;
        Scanner sc = new Scanner(System.in);
        Solution s = new Solution();
        t = sc.nextInt();
        sc.nextLine();
        while(t>0)
        {
            t--;
            int n=sc.nextInt();
            String str = sc.next();
            s.helper(str,n);
        }
        sc.close();
    }
}
//3:07

class Solution {
    private void mapInsert(HashMap<Long,Integer> map,long key,int val,int multiple){
        if(!map.containsKey(key))
            map.put(key, val);
        else{
            int value = map.get(key);
            int mini = Math.min(value, val);
            if(mini==value){

            }
            map.put(key, mini);
        }
    }
    public void helper(String s,int n)
    {
        HashMap<Long,Integer> map = new HashMap<>();
        long cost=0;
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='0'){
                if(map.containsKey((long)(i+1))){
                    int temp = map.get((long)(i+1));
                    cost+=temp;
                    int multiple = ((i+1)/temp);
                    this.mapInsert(map, (multiple+1+0L)*temp*1L, temp,(multiple+1));
                    this.mapInsert(map, (i+1)*2*1L, (i+1),2);
                }
                else{
                    cost+=(i+1);
                    this.mapInsert(map, (i+1)*2*1L, (i+1),2);
                }
            }
        }
        System.out.println(cost);
        return;
    }
}
//this is incorrect, since 12 ko generate krne k liye 3 use kiya, aur 4 jo 3 ke pehle map me tha usko nikal
//diya, thus ab 16 generate khudse krna padega, since 4 ka next multiple 16 hi hota aur 4 use krsakte.
//aur isko manage krne k liye, 4 ke next multiple ko rakhte, toh 16 key me 4 insert krne k liye uska empty 
//hona mangta. thus ye ek loop jesa ban jata.
//isko seive se kar

// 1
// 16
// 1100101001101110
//exp = 24 and got=28