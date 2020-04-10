import java.util.*;

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        HashMap<String, Integer> m = new HashMap<>();
        for (String word: words) {
          m.put(word, m.getOrDefault(word, 0) + 1);
        }
        PriorityQueue<String> pq = new PriorityQueue<String>(
            (n1, n2) -> 
            m.get(n1).equals(m.get(n2))?n2.compareTo(n1):m.get(n1)-m.get(n2)
        );
        for (String n: m.keySet()) {
          pq.add(n);
          if (pq.size() > k) pq.poll();
        }
        List<String> top_k = new ArrayList<>();
        while (!pq.isEmpty()) top_k.add(pq.poll());
        Collections.reverse(top_k);
        return top_k;
        
    }
}

public class _692_Top_K_Frequent_Words {
    public static void main(String[] args) {
        Solution s = new Solution();
        String[] words = {"i", "love", "leetcode", "i", "love", "coding"};
        System.out.println(s.topKFrequent(words, 2));
    }
}
