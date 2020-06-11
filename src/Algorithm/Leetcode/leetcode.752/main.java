import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import java.io.Console;
import java.util.HashSet;

class Solution {
    private Set<String> seen;
    private Queue<String> queue;
    private int count;

    public Solution() {
        queue = new LinkedList<>();
        seen = new HashSet<String>();
        count = 0;
    }

    public boolean isUnableStart(String[] deadends, String target) {

        for (String i : deadends) {
            seen.add(i);
        }

        if (seen.contains(target) || seen.contains("0000")) {
            return false;
        }
        return true;
    }

    public int openLock(String[] deadends, String target) {

        if (!isUnableStart(deadends, target)) {
            return -1;
        }

        queue.offer("0000");
        seen.add("0000");

        while (!queue.isEmpty()) {
            int sizeQueue = queue.size();

            for (int i = 0; i < sizeQueue; i++) {
                String roulette = queue.poll();

                if (target.equals(roulette)) {
                    return count;
                }
                for (int j = 0; j < 4; j++) {

                    String up = neighbor(roulette, j, 1);
                    String down = neighbor(roulette, j, -1);
                    if (seen.add(up)) {
                        queue.offer(up);
                    }
                    if (seen.add(down)) {
                        queue.offer(down);
                    }
                }
            }
            count++;
        }

        return -1;
    }

    private String neighbor(String roulette, int i, int flage) {
        final int UP = 1;
        char[] cs = roulette.toCharArray();
        // 向大搜索
        if (flage == UP) {
            if (cs[i] == '9') {
                cs[i] = '0';
            } else {
                cs[i]++;
            }
        } else {
            // 向小搜索
            if (cs[i] == '0') {
                cs[i] = '9';
            } else {
                cs[i]--;
            }
        }

        return new String(cs);
    }

    public static void main(String[] args) {
        String[] deadends = { "0201", "0101", "0102", "1212", "2002" };
        String target = "0202";
        int ret = new Solution().openLock(deadends, target);
        System.out.print(ret);
    }
}