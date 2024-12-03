import java.util.*;

public class B_Vika_and_the_Bridge
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
            int k=sc.nextInt();
            int[] nums = new int[n];
            for(int i=0;i<n;i++)
                nums[i]=sc.nextInt();
            s.helper(nums,n,k);
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

    public String toString(){
        return this.value+" "+this.index;
    }
}

class MyComp implements Comparator<Pair>{

    @Override
    public int compare(Pair o1, Pair o2) {
        if(o1.value < o2.value) {
            return -1;
        }
        else if(o1.value > o2.value) return 1;
        else{
            if(o1.index < o2.index) return -1;
            else return 1;
        }
    }
    
}

class Solution {

    public void helper(int[] nums,int n,int k)
    {
        List<Pair> arr = new ArrayList<>();
        for(int i=0;i<n;i++)
        {
            Pair nn = new Pair(nums[i], i);
            arr.add(nn);
        }
        Collections.sort(arr, new MyComp());
        int i=0;
        int mini=Integer.MAX_VALUE;
        while(i<n)
        {
            PriorityQueue<Integer> sortedSet = new PriorityQueue<>(Comparator.reverseOrder());
            //galti se set le liya tha, phir 1 hr baith k debug kiya, fhir click hua ki set me duplicates allowed nhi h
            int prev=-1;
            while (i<n && (prev==-1 || arr.get(i).value==prev)) {
                if(prev!=-1){
                    int diff = arr.get(i).index - arr.get(i-1).index-1;
                    sortedSet.add(diff);
                }
                else{
                    int diff = arr.get(i).index;
                    sortedSet.add(diff);
                }
                prev=arr.get(i).value;
                i++;
            }
            int diff = (n) - arr.get(i-1).index - 1;
            sortedSet.add(diff);
            int max1 = sortedSet.peek();
            sortedSet.poll();
            int t1,t2;
            if(max1%2==0){
                t1=max1/2;
                t2=t1-1;
            }
            else{
                t1=t2=max1/2;
            }
            sortedSet.add(t1);
            sortedSet.add(t2);
            max1 = sortedSet.peek();
            mini = Math.min(max1,mini);
        }
        System.out.println(mini);
    }
}
//1 1 2 2 3 3 4 4
//0 6 1 4 2 5 3 7
//for 1 : 0,5,1
//for 2 : 1,2,3
//for 3 : 2,2,2
//for 4 : 3,3,0

//but first se waha aana padega and last se n k bahar jana padega