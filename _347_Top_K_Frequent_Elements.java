import java.util.*;

class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> m = new HashMap<>();
        for (int n: nums) {
          m.put(n, m.getOrDefault(n, 0) + 1);
        }
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(
            (n1, n2) -> m.get(n1) - m.get(n2));
        for (int n: m.keySet()) {
          pq.add(n);
          if (pq.size() > k) pq.poll();
        }
        List<Integer> top_k = new ArrayList<>();
        while (!pq.isEmpty()) top_k.add(pq.poll());
        Collections.reverse(top_k);
        return top_k;
    }
}

public class _347_Top_K_Frequent_Elements {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {1,2,1,2,1,3};
        System.out.println(s.topKFrequent(nums, 2));
    }
}
