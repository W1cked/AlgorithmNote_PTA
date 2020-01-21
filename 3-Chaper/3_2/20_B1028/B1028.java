import java.util.Scanner;

class Person {
    public String name;
    public int year;
    public int month;
    public int day;
    
    public Person() {
        
    }
    
    public Person(String name, int year, int month, int day) {
        this.name = name;
        this.year = year;
        this.month = month;
        this.day = day;
    }
    
    public boolean Bigger(Person left) {
        if(this.year != left.year)
            return this.year >= left.year;
        else if(this.month != left.month) 
            return this.month >= left.month;
        else 
            return this.day >= left.day;
    }
    
    public boolean Smaller(Person right) {
        if(this.year != right.year)
            return this.year <= right.year;
        else if(this.month != right.month) 
            return this.month <= right.month;
        else 
            return this.day <= right.day;
    }
}   

public class B1028 {
    public static void main(String[] args) {
        /** Iinitialize the data */
        Person OLD = new Person("OLD", 2014, 9, 6);
        Person YOUNG = new Person("YOUNG", 1814, 9, 6);
        Person left = new Person("Left", 1814, 9, 6);
        Person right = new Person("Right", 2014, 9, 6);
        
        /** Input the number */
        int number, counter = -1;
        Scanner input = new Scanner(System.in);
        number = input.nextInt();
        
        /** Input the person information */
        Person[] person = new Person[10];
        for(int i = 0; i < number; i++) {
            person[i] = new Person();
        }
        String tempDate = new String();
        for(int i = 0; i < number; i++) {
            person[i].name = input.next();
            tempDate = input.next();
            formatInput(person[i], tempDate);
            
            // Fliter the invalid data
            if(person[i].Bigger(left) && person[i].Smaller(right)) {
                counter++;
                // Update OLD and YOUNG
                if(person[i].Smaller(OLD)) {
                    OLD = person[i];
                }
                if(person[i].Bigger(YOUNG)) {
                    YOUNG = person[i];
                }
            }
        }
        
        /** Display the result */
        if(counter == -1) {
            System.out.println("0");
        }
        else
            System.out.printf("%d %s %s", counter + 1, OLD.name, YOUNG.name);
        
    }
    
    public static void formatInput(Person temp, String tempDate) {
        // Cut the bits
        String date[] = tempDate.split("/");
        String year = date[0];
        String month = date[1];
        String day = date[2];
        
        // Convert String into integer
        int iYear = Integer.parseInt(year);
        int iMonth = Integer.parseInt(month);
        int iDay = Integer.parseInt(day);
        
        // Assign the integers into object
        temp.year = iYear;
        temp.month = iMonth;
        temp.day = iDay;
    }
}
