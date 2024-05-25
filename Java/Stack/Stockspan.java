/*
The stock span problem is a financial problem where we have a
series of n daily price quotes for a stock and we need to calculate
the span of stocks price for all n days.
The span Si of the stocks price on a given day i is defined as the
maximum number of consecutive days just before the given day,
for which the price of the stock on the given day is less than or
equal to its price on the current day.
For example, if an array of 7 days prices is given as {100, 80, 60,
70, 60, 75, 85}, then the span values for corresponding 7 days
are {1, 1, 1, 2, 1, 4, 6}.

*/

class Stockspan {
    // Function to calculate the span of stockâ€™s price for all n days.
    public static int[] calculateSpan(int price[], int n) {
        int S[] = new int[n];
        Stack<Integer> st = new Stack<>();
        st.push(0);

        // span value of first day is always 1.
        S[0] = 1;

        for (int i = 1; i < n; i++) {
            // we pop elements from the stack till price at top of stack
            // is less than or equal to current price.
            while (!st.isEmpty() && price[i] >= price[st.peek()]) {
                st.pop();
            }

            // if stack becomes empty, then price[i] is greater than all
            // elements on left of it in list so span is i+1.
            // Else price[i] is greater than elements after value at top of stack.
            S[i] = st.isEmpty() ? i + 1 : i - st.peek();

            // pushing this element to stack.
            st.push(i);
        }
        // returning the list.
        return S;
    }
}
