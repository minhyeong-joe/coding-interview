package String;

import java.util.ArrayList;
import java.util.Map;
import java.util.LinkedHashMap;

/**
 * RemoveDupChar
 */

public class RemoveDupChar {

    public static void main(String[] args) {
        String str = "Hello World";
        System.out.println("Original String: " + str);

        String dupRemovedStr = removeDupChar(str);

        System.out.println("Result String: " + dupRemovedStr);
    }

    public static String removeDupChar(String str) {
        ArrayList<Character> resultArr = new ArrayList<>();
        // HashMap: random order, LinkedHashMap keeps the insertion order
        Map<Character, Integer> freqDict = new LinkedHashMap<Character, Integer>();
        
        // iterate over input string, count chars
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            int freq = freqDict.getOrDefault(ch, 0);
            freqDict.put(ch, freq+1);
        }

        // iterate over frequecny dict and append the non-duplicates
        freqDict.forEach((ch, freq)->{
            if (freq == 1) {
                resultArr.add(ch);
            }
        });

        // build string from char array
        StringBuilder sb = new StringBuilder();
        for (Character ch: resultArr) {
            sb.append(ch);
        }
        
        return new String(sb);
    }
    
}