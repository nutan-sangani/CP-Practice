import java.util.*;

public class C_Dora_and_Search
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
    public void helper(int[] nums,int n)
    {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(Comparator.naturalOrder());
        for(int i=0;i<n;i++){
            maxHeap.add(nums[i]);
            minHeap.add(nums[i]);
        }
        int i=0;
        int j=n-1;
        while(i<j){
            int smallest = minHeap.peek();
            int largest = maxHeap.peek();
            if((nums[i]!=smallest && nums[i]!=largest) && (nums[j]!=smallest && nums[j]!=largest)){
                    System.out.println((i+1)+" "+(j+1));
                    return;
            }
            else{
                if(nums[i]==largest || nums[i]==smallest){
                    if(nums[i]==largest){
                        maxHeap.poll();
                    }
                    else minHeap.poll();
                    i++;
                }
                if(nums[j]==smallest || nums[j]==largest){
                    if(nums[j]==largest){
                        maxHeap.poll();
                    }
                    else minHeap.poll();
                    j--;
                }
            }
        }
        if(i>=j){
            System.out.println(-1);
            return;
        }
        System.out.println(-1000);
        return;
    }
}