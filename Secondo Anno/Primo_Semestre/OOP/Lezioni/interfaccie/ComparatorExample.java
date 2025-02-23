import java.util.*;

class Person1 {
    private String name;
    private int age;

    public Person1(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    @Override
    public String toString() {
        return "Person{name='" + name + "', age=" + age + "}";
    }
}

public class ComparatorExample {
    public static void main(String[] args) {
        List<Person> people = new ArrayList<>();
        people.add(new Person("Alice", 30));
        people.add(new Person("Bob", 25));
        people.add(new Person("Charlie", 35));
        people.add(new Person("David", 25));

        // Sort by age using a Comparator
        people.sort(new Comparator<Person>() {
            @Override
            public int compare(Person p1, Person p2) {
                return Integer.compare(p1.getAge(), p2.getAge());
            }
        });

        System.out.println("Sorted by age:");
        for (Person person : people) {
            System.out.println(person);
        }

        // Sort by name using a Comparator (lambda version)
        people.sort((p1, p2) -> p1.getName().compareTo(p2.getName()));

        System.out.println("\nSorted by name:");
        for (Person person : people) {
            System.out.println(person);
        }
    }
}
