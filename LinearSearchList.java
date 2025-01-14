import java.util.Arrays;
import java.util.ArrayList;
import java.util.Scanner;

public class LinearSearch {
    static int search(ArrayList<Integer> array, int key) {
        int size = array.size();
        for (int i = 0; i < size; i++) {
            if (array.get(i)== key) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int size = scn.nextInt();
        ArrayList<Integer> array = new ArrayList<Integer>();
        for (int i = 0; i < size; i++)
            array.add(scn.nextInt());
        
        System.out.print("Enter the key: ");
        int key = scn.nextInt();
        scn.close();
    
        System.out.println("Array: "+ array);
        System.out.println("Key: "+ key);
        System.out.print(search(array, key));
    }
}