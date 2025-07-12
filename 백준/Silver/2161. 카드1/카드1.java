import java.util.ArrayDeque;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        ArrayDeque<Integer> deque = new ArrayDeque<>();
        for (int i = 1; i <= N; i++) {
            deque.add(i);
        }

        while (deque.size() > 1) {
            System.out.print(deque.poll() + " ");
            Integer polled = deque.poll();
            deque.addLast(polled);
        }
        System.out.println(deque.peek());
    }
}
