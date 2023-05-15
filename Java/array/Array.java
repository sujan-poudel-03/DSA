package Java.array;

public class Array {
    public static void main(String[] args) {
        int[] arr = new int[10];

        // initialize
        arr[0] = 1;
        arr[1] = 3;
        arr[2] = 5;
        arr[3] = 7;
        arr[4] = 9;

        System.out.printf("Size of array is : %d \n", arr.length);

        traversal(arr);

        insert(arr, 2, 10);
        delete(arr, 2);
        search(arr, 7);
        update(arr, 2, 10);
    }

    public static void traversal(int[] arr) {
        System.out.println("-------------------Traversal Operation------------------- \n");

        System.out.print("[");
        int size = arr.length;
        for (int i = 0; i < size; i++) {
            System.out.printf("%d", arr[i]);
            if (i < size - 1) System.out.print(", ");
        }
        System.out.println("]");
    }

    public static void insert(int[] arr, int index, int element) {
        System.out.println("-------------------Insert Operation-------------------");
        int size = arr.length - 1;
        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }

        arr[index] = element;
        size++;

        System.out.println("Element inserted successfully.");
        System.out.println("Now the new array is:");
        traversal(arr);
    }

    public static void delete(int[] arr, int index) {
        System.out.println("-------------------Delete Operation-------------------");
        
        int size = arr.length;

        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;

        System.out.println("Element deleted successfully.");
        System.out.println("Now the new array is:");
        traversal(arr);
    }

    public static void search(int[] arr, int element) {
        System.out.println("-------------------Search Operation-------------------");

        int size = arr.length;
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                System.out.printf("Element found at index %d\n", i);
                return;
            }
        }

        System.out.println("Element not found.");
    }

    public static void update(int[] arr, int index, int element) {
        System.out.println("-------------------Update Operation-------------------");

        arr[index] = element;

        System.out.println("Element updated successfully.");
        System.out.println("Now the new array is:");
        traversal(arr);
    }
}