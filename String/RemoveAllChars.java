package String;

/**
 * RemoveAllChars
 * Input: string, array of chars
 * Output: string with all chars removed
 */
public class RemoveAllChars {

    public static void main(String[] args) {
        String str = "Hello, World";
        char remove[] = {'h', 'l'};

        String processedStr = removeAllChars(str, remove);

        System.out.println(processedStr);
    }

    public static String removeAllChars(String str, char chars[]) {
        // string is immutable, so use char array to represent result string
        char[] result = new char[str.length()];
        int curIndex = 0;
        boolean include = true;
        for(int i = 0; i < str.length(); i++) {
            include = true;
            for(char c: chars) {
                if (str.charAt(i) == Character.toUpperCase(c) || str.charAt(i) == Character.toLowerCase(c)) {
                    // if char of string is in char of array, then do not add this to result
                    include = false;
                    break;
                }
            }
            if (include) {
                // include char into result
                result[curIndex] = str.charAt(i);
                curIndex++;
            }
        }

        return new String(result);
    }
    
}