import java.util.*;
 
public class B_Equalize_by_Divide
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
            int n = sc.nextInt();
            long[] nums = new long[n];
            for(int i=0;i<n;i++){
                nums[i] = sc.nextLong();
            }
            s.helper(nums,n);
        }
    }
}

class Pair{
    long value;
    int index;
    public Pair(long value,int index){
        this.value=value;
        this.index=index;
    }
}

class MyComp implements Comparator<Pair>{

    @Override
    public int compare(Pair o1, Pair o2) {
        if(o1.value<o2.value) return -1;
        else if(o1.value>o2.value) return 1;
        else return 0;
    }
    
}
 
class Solution {
    public void helper(long[] nums,int n)
    {
        Pair[] pairs = new Pair[n];
        for(int i=0;i<n;i++){
            Pair nn = new Pair((long)nums[i],i);
            pairs[i]=nn;
        }
        List<Pair> ans = new ArrayList<>();
        Arrays.sort(pairs,new MyComp());

        if(pairs[0].value==1 && pairs[n-1].value!=1){
            System.out.println(-1);
            return;
        }

        while(pairs[0].value!=pairs[n-1].value){
            int i=0;
            int j=1;
            while(j<n){
                if(pairs[j].value>pairs[i].value){
                    pairs[j].value = Math.ceilDiv(pairs[j].value, pairs[i].value);
                    Pair nn = new Pair(pairs[j].index,pairs[i].index);
                    ans.add(nn);
                    // System.out.println((pairs[j].index+1)+" "+(pairs[i].index+1));
                }
                j++;
            }
            Arrays.sort(pairs,new MyComp());
        }
        System.out.println(ans.size());
        for(int i=0;i<ans.size();i++){
            System.out.println((ans.get(i).value+1)+" "+(ans.get(i).index+1));
        }
        return;
    }
}
 
 