<Query Kind="Program" />

// Using https://learn.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/linq/sorting-data
// https://learn.microsoft.com/en-us/dotnet/api/system.array.sort?view=net-7.0

class Program {
	
	// Person class that has name and age 
	class Person{
		public string name;
		public int age;

		public Person(String n, int a){
		  this.name = n;
		  this.age = a; 
		}	
    } 
	
	public static void Main (string[] args) {
		// Variables 
		double[] numbers = {645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25};

		Person[] people = {new Person("Hal", 20), new Person("Susann", 31), new Person("Dwight", 19), new Person("Kassandra", 21), new Person("Lawrence", 25), new Person("Cindy", 22), new Person("Cory", 27), new Person("Mac", 19), new Person("Romana", 27), new Person("Doretha", 32), new Person("Danna", 20), new Person("Zara", 23), new Person("Rosalyn", 26), new Person("Risa", 24), new Person("Benny", 28), new Person("Juan", 33), new Person("Natalie", 25)};

		// Sort numbers ascending by numerical value
		Console.WriteLine("==== Sort numbers ascending by numerical value ====");
		Console.WriteLine("BEFORE:");
		Console.Write(numbers);
		Array.Sort(numbers);
		
		Console.WriteLine("\nAFTER:");
		Console.Write(numbers);
		
		// Sort people alphabetically (lexicograhically) by name 
		Console.WriteLine("\n==== Sort people alphabetically (lexicographically) by name ====");
		Console.WriteLine("BEFORE:");
		Console.WriteLine(people);
		 
		Console.WriteLine("\nAFTER:");
		IEnumerable<Person> query = from person in people orderby person.name select person;
		Console.WriteLine(query);
		
		// Sort people descending by age, where people of the same age should be sorted alphabetically 
		Console.WriteLine("\n==== Sort people descending by age, where people of the same age should be sorted alphabetically ====");
		Console.WriteLine("BEFORE:");
		Console.WriteLine(people);
		
		Console.WriteLine("\nAFTER:");
		// Primarily sort by age, and secondary sort by name - Descending 
		IEnumerable<Person> query2 = from person in people orderby person.age descending select person;
		Console.WriteLine(query2);
		
	}
}