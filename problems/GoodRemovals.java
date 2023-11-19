import java.util.Scanner;

public class GoodRemovals {
    private static final int MOD = (int) (1e9) + 7;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numTestCases = scanner.nextInt();

        for (int testCase = 0; testCase < numTestCases; testCase++) {
            int length = scanner.nextInt();
            int[] array = new int[length];

            for (int i = 0; i < length; i++) {
                array[i] = scanner.nextInt();
            }

            int evenCount = 0;
            for (int num : array) {
                if (num % 2 == 0) {
                    evenCount += 1;
                }
            }

            int result;
            if (evenCount == length) {
                result = (int) (Math.pow(2, evenCount) - 1) % MOD;
            } else {
                result = (int) Math.pow(2, evenCount) % MOD;
            }

            System.out.println(result);
        }
    }
}
