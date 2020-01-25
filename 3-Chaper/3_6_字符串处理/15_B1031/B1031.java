import java.util.Scanner;

class Person{
    String ID;
    int sumWeight = 0;
    char check;
    boolean vaild = true;
}

public class B1031 {
    
    static int[] weight = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    static char[] check = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    
    public static void main(String[] args) {
        int number;
        Scanner input = new Scanner(System.in);
        number = input.nextInt();
        
        // Create some objects
        Person[] person = new Person[number];
        for(int i = 0; i < number; i++) {
            person[i] = new Person();
        }
        
        // Input the data
        for(int i = 0; i < number; i++) {
            person[i].ID = input.next();
        }
        
        // Is someone invaild before 18 bits?
        for(int i = 0; i < number; i++) {
            for(int j = 0; j < 17; j++) {
                if(person[i].ID.charAt(j) >= '0' && person[i].ID.charAt(j) <= '9') {
                    continue;
                }
                else {
                    person[i].vaild = false;
                }
            }
        }
        
        // Compte the weightID of vaild person
        for(int i = 0; i < number; i++) {
            if(!person[i].vaild) {
               continue; 
            }
            else {
                for(int j = 0; j < 17; j++) {
                    person[i].sumWeight += (person[i].ID.charAt(j) - '0') * weight[j];
                }
                // Find the check
                person[i].check = check[person[i].sumWeight % 11];
                if(person[i].check == person[i].ID.charAt(17)) {
                    person[i].vaild = true;
                }
                else {
                    person[i].vaild = false;
                }
            }
        }
        
        // Display the result
        int counter = 0;
        for(int i = 0; i < number; i++) {
            if(person[i].vaild) {
                counter++;
            }
        }
        if(counter == number) {
            System.out.println("All passed");
        }
        
        for(int i = 0; i < number; i++) {
            if(!person[i].vaild) {
                System.out.println(person[i].ID);
            }
        }
        
    }
}
