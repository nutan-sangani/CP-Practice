import java.util.*;

public class B_Pleasant_Pairs
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
            int[] nums = new int[n];
            for(int i=0;i<n;i++)
                nums[i]=sc.nextInt();
            s.helper(nums,n);
        }
        sc.close();
    }
}

class Pair{
    int value;
    int index;
    public Pair(int value,int index){
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
    public void helper(int[] nums,int n)
    {
        List<Pair> sorted = new ArrayList<>();
        long count=0;
        for(int i=0;i<n;i++){
            Pair nn = new Pair(nums[i],i+1);
            sorted.add(nn);
        }
        Collections.sort(sorted,new MyComp());
        for(int i=0;i<n;i++){
            int one = nums[i];
            long limit = (2*n*1L)/(one*1L)+1L;
            int j=0;
            while(j<n && sorted.get(j).value<=limit){
                int two = sorted.get(j).value;
                int twoIndex = sorted.get(j).index;
                int oneIndex = (i+1);
                if(one*two==(oneIndex+twoIndex) && one!=two){
                    count++;
                }
                j++;
            }
        }
        System.out.println(count/2);
        return;
    }
}