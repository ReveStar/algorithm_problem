import java.util.HashMap;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        char[] inputs = new Scanner(System.in).nextLine().toLowerCase().toCharArray();
        int min_index = 0;
        int len = inputs.length;

        for (int i = 1; i < len; i++) {
            char last = inputs[i];
            if (last == inputs[min_index] && (min_index + 1) < i && (inputs[min_index + 1]) < inputs[min_index]) {
                min_index += 1;
            }
        }
        System.out.println(inputs[min_index]);
    }
}
