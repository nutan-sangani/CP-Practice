import java.util.*;

public class B_Forming_Triangles
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

class Solution {

    class Pair{
        public int value;
        public int index;

        public Pair(int value,int index){
            this.value=value;
            this.index=index;
        }

    }

    private long countCombination3(int start,int end)
    {
        long prod = 1L;
        for(int i=start;i>end;i--)
        {
            prod = prod*(i+0L);
        }
        prod = prod/6L;
        return prod;
    }

    private long countCombination(int start,int end)
    {
        long prod = 1L;
        for(int i=start;i>end;i--)
        {
            prod = prod*(i+0L);
        }
        prod = prod/2L;
        return prod;
    }

    public void helper(int[] nums,int n)
    {
        Arrays.sort(nums);
        Map<Integer,Integer> count = new HashMap<>();
        List<Pair> unique = new ArrayList<>(); //pair of value and its first index.
        long ans=0;
        for(int i=0;i<n;i++)
        {
            if(count.containsKey(nums[i]))
            {
                int value = count.get(nums[i]);
                value++;
                count.put(nums[i], value);
            }
            else{
                count.put(nums[i], 1);
                unique.add(new Pair(nums[i],i));
            }
        }
        if(unique.size()==1)
        {
            long combinations = countCombination3(n, n-3);
            System.out.println(combinations);
            return;
        }
        for(int i=0;i<unique.size();i++)
        {
            Pair pair = unique.get(i);
            int value = pair.value;
            int index = pair.index;
            int countOfValue = count.get(value);
            if(countOfValue>1){
                long combinations = countCombination(countOfValue, countOfValue-2);
                int indexCount = index-0;
                ans += ((combinations*indexCount*1L)+0L);
            }
            if(countOfValue>=3)
            {
                long combinations = countCombination3(countOfValue, countOfValue-3);
                ans+=combinations;
            }
        }
        System.out.println(ans);
        return;
    }
}
//0 0 1 1 2 3 6
//1 1 2 2 4 8 64
