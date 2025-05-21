import java.util.*;

public class Solution {
    public String solution(String number, int k) {
        Deque<Character> stack = new ArrayDeque<>();

        for (char digit : number.toCharArray()) {
            while (!stack.isEmpty() && k > 0 && stack.peekLast() < digit) {
                stack.pollLast();
                k--;
            }
            stack.offerLast(digit);
        }

        while (k-- > 0) {
            stack.pollLast();
        }

        StringBuilder sb = new StringBuilder();
        for (char ch : stack) {
            sb.append(ch);
        }

        return sb.toString();
    }
}
