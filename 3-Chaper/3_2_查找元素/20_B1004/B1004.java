import java.util.Scanner;

class Student {
    public String name;
    public String id;
    public int score;
}

public class B1004 {
    public static void main(String[] args) {
        // Input the student number
        Scanner input = new Scanner(System.in);
        int number = input.nextInt();
        
        // Input the student info
        Student[] student = new Student[number];
        for(int i = 0; i < number; i++) {
            student[i] = new Student();
        }
        
        for(int i = 0; i < number; i++) {
            student[i].name = input.next();
            student[i].id = input.next();
            student[i].score = input.nextInt();
        }
        
        // Traversal the student obj and find the MAX, MIN
        Student MAX = new Student();
        MAX = student[0];
        Student MIN = new Student();
        MIN = student[0];
        
        for(int i = 1; i < number; i++) {
            if(student[i].score > MAX.score) {
                MAX = student[i];
            }
            if(student[i].score < MIN.score) {
                MIN = student[i];
            }
        }
        
        // Display the result
        System.out.println(MAX.name + " " + MAX.id);
        System.out.println(MIN.name + " " + MIN.id);
        
    }
}
