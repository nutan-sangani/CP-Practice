import java.util.*;

public class C_Heavy_Intervals
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
            long[] l=new long[n];
            long[] r=new long[n];
            Long[] c=new Long[n];
            for(int i=0;i<n;i++){
                l[i]=sc.nextLong();
            }
            for(int i=0;i<n;i++){
                r[i]=sc.nextLong();
            }
            for(int i=0;i<n;i++){
                c[i]=sc.nextLong();
            }
            s.helper(l,r,c,n);
        }
    }
}

class Solution {
    public void helper(long[] l,long[] r,Long[] c,int n)
    {
        Arrays.sort(r);
        // Long[] cBoxed = Arrays.stream(c).boxed().toArray(size -> new Long[size]);
        Arrays.sort(c,Comparator.reverseOrder());
        TreeSet<Long> lowerLimit = new TreeSet<>();
        for(int i=0;i<n;i++){
            lowerLimit.add(l[i]);
        }
        long sum=0;
        ArrayList<Long> diff = new ArrayList<>();
        for(int i=0;i<n;i++){
            long lower = lowerLimit.floor(r[i]);
            lowerLimit.remove(lower);
            diff.add(r[i]-lower);
        }
        Collections.sort(diff);
        for(int i=0;i<n;i++){
            sum+=(diff.get(i)*1L*c[i]);
        }
        System.out.println(sum);
    }
}
//l = 1 2 5 20
//r = 3 4 10 30
//c = 3 3 2 2
//3*1 + 3*3 + 10 + 20 = 42