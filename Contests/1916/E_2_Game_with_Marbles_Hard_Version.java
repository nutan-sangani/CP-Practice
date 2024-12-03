import java.util.*;

public class E_2_Game_with_Marbles_Hard_Version
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
            int[] a=new int[n];
            for(int i=0;i<n;i++)
            {
                a[i]=sc.nextInt();
            }
            int[] b=new int[n];
            for(int i=0;i<n;i++)
            {
                b[i]=sc.nextInt();
            }
            s.helper(a,b);
		}
	}
}

class Mycomp implements Comparator<AbstractMap.SimpleEntry<Integer,Integer>>
{
    @Override
    public int compare(AbstractMap.SimpleEntry<Integer,Integer>a,AbstractMap.SimpleEntry<Integer,Integer>b)
    {
        int k = a.getKey().compareTo(b.getKey());
        if(k==-1) return 1;
        else if(k==1) return -1;
        return 0;
    }
}

class Solution {
    public void helper(int[]a,int[]b)
    {
        long aTotal=0;
        long bTotal=0;
        PriorityQueue<AbstractMap.SimpleEntry<Integer,Integer>> pq = new PriorityQueue<>(new Mycomp());
        int n=a.length;
        for(int i=0;i<n;i++)
        {
            int key = a[i]+b[i]-1;
            pq.add(new AbstractMap.SimpleEntry<Integer,Integer>(key,i));
        }
        for(int i=0;i<n;i++)
        {
            Map.Entry<Integer,Integer> temp = pq.peek();
            pq.poll();
            int first=a[temp.getValue()];
            int second=b[temp.getValue()];
            if(i%2==0)
            {
                aTotal+=(first-1);
            }
            else bTotal+=(second-1);
        }
        System.out.println(aTotal-bTotal);
    }
}