package String;

/**
 * LongestSubPalindrome
 */
public class LongestSubPalindrome {

    public static void main(String[] args) {
        String str = "abaab";

        String longSubPal = longestSubPalindrome(str);

        System.out.println(longSubPal);
    }

    public static String longestSubPalindrome(String str) {
        // create dynamic programming table
        final int N = str.length();
        boolean dpTable[][] = new boolean[N][N];
        // initial set-up
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    dpTable[i][j] = true;
                } 
            }
        }
        System.out.println("Initial DP Table:");
        print2dArray(dpTable);

        // bottom-up fill in DP table
        for (int i = N-1; i >= 0; i--) {
            for (int j = N-1; j >= 0; j--) {
                // only fill in the cells where i < j
                if (i < j) {
                    if ((i+1 > j-1 || dpTable[i+1][j-1]) && (str.charAt(i) == str.charAt(j))) {
                        dpTable[i][j] = true;
                    }
                }
            }
        }
        System.out.println("After Bottom-up fill-in:");
        print2dArray(dpTable);

        // find the "longest" 'True' cell
        // Search from "right-upper corner" diagonally
        // i = 0 | 0 1 | 0 1 2 | 0 1 2 3 | 0 1 2 3 4
        // j = 4 | 3 4 | 2 3 4 | 1 2 3 4 | 0 1 2 3 4
        int startIndex = 0;
        int endIndex = 0;
        outmostloop:
        for (int k = 0; k < N; k++) {
            for (int i = 0; i <= k; i++) {
                int j = N-1 - k + i;
                if (dpTable[i][j]) {
                    startIndex = i;
                    endIndex = j;
                    break outmostloop;
                }
            }
        }

        return str.substring(startIndex, endIndex+1);
    }


    /*
    * @Helper function to display Dynamic Programming Table
    */
    public static void print2dArray(boolean arr[][]) {
        final String ANSI_RESET = "\u001B[0m";
        final String ANSI_RED = "\u001B[31m";
        final String ANSI_GREEN = "\u001B[32m";

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                System.out.printf("%s ", arr[i][j]? ANSI_GREEN + "T" + ANSI_RESET : ANSI_RED + "F" + ANSI_RESET);
            }
            System.out.println();
        }
    }
    
}