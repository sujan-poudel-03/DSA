public class Repeated {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 4, 5, 5, 1, 5, 5 };
        int[] counted = new int[arr.length];
        int count = 0;

        for (int i = 0; i < arr.length; i++) {
            int occurances = countOccurance(arr, arr[i]);
            if (occurances > 1 && !includes(counted, arr[i])) {
                counted[i] = arr[i];
                count++;
            }
        }
        System.out.println("the number of repeated number are " + count);
        System.out.println("The duplicated elements are:");

        for (int i : counted) {
            System.out.println(i);
        }

    }

    public static boolean includes(int[] arr, int elm) {
        for (int i : arr) {
            if (i == elm)
                return true;
        }

        return false;
    }

    public static int countOccurance(int[] arr, int elm) {
        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            if (elm == arr[i])
                count++;
        }

        return count;
    }
}
