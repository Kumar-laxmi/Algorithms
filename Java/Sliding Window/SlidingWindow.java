public class SlidingWindow {
    public static void main(String[] args) {
        int[] array = {1, 3, -1, -3, 5, 3, 6, 7};
        int k = 3;
        int[] maxValues = getMaxValues(array, k);
        System.out.println(Arrays.toString(maxValues));  // [3, 3, 5, 5, 6, 7]
    }

    public static int[] getMaxValues(int[] array, int k) {
        if (array == null || k <= 0) {
            return new int[0];
        }
        int n = array.length;
        int[] maxValues = new int[n - k + 1];
        Deque<Integer> deque = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            while (!deque.isEmpty() && deque.peek() < i - k + 1) {
                deque.poll();
            }
            while (!deque.isEmpty() && array[deque.peekLast()] < array[i]) {
                deque.pollLast();
            }
            deque.offer(i);
            if (i >= k - 1) {
                maxValues[i - k + 1] = array[deque.peek()];
            }
        }
        return maxValues;
    }
}

