import java.util.Arrays;
import java.util.Scanner;

public class LinearSearch {
    static int search(int[] array, int key) {
        int size = array.length;
        for (int i = 0; i < size; i++) {
            if (array[i] == key) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int size = scn.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = scn.nextInt();
        
        System.out.print("Enter the key: ");
        int key = scn.nextInt();
        scn.close();
        System.out.println("Array: "+ Arrays.toString(array));
        System.out.println("Key: "+ key);
        System.out.print(search(array, key));
    }
}