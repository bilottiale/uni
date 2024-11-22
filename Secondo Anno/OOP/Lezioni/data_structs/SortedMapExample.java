// Java code to demonstrate SortedMap Interface 
import java.util.*;

public class SortedMapExample {
	public static void main(String[] args)
	{
		SortedMap<Integer, String> sm = new TreeMap<Integer, String>(); 
		sm.put(2, "practice");
		sm.put(3, "quiz");
		sm.put(1, "code");
		sm.put(4, "geeksforgeeks");
		
		for (Map.Entry<Integer, String> m : sm.entrySet()) {
			System.out.println("Key: " + m.getKey() + " | Value: " + m.getValue());
		}
	}
}
