public class ArrayDemo {
   public static void main(String []args) {
      int LA[] = new int[3];
      System.out.println("Array Before Insertion:");
      for(int i = 0; i < 3; i++)
         System.out.println("LA[" + i + "] = " + LA[i]); //prints empty array
      System.out.println("Inserting Elements..");
      
      // Printing Array after Insertion
      
System.out.println("Array After Insertion:");
      for(int i = 0; i < 3; i++) {
         LA[i] = i+3;
         System.out.println("LA[" + i + "] = " + LA[i]);
      }
   }
}