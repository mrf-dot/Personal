using System;

namespace Sample
{
    class Example
    {
	static void Main(string[] args) {
		HelloWorld();
		FizzBuzz();
		NameAndAge();
	}
        static void HelloWorld()
        {
            Console.WriteLine("Hello, world!");
        }

        static void FizzBuzz()
        {
            for (int i = 1; i < 101; i++)
            {
                String s = "";
                s += (i % 3 == 0) ? "Fizz" : "";
                s += (i % 5 == 0) ? "Buzz" : "";
                Console.WriteLine((string.IsNullOrWhiteSpace(s)) ? i.ToString() : s);
            }
	    Console.WriteLine();
        }

	static void NameAndAge() {
		Console.Write("What is your name?: ");
		string name = Console.ReadLine();
		Console.Write("How old are you?: ");
		int age = int.Parse(Console.ReadLine());
		Console.WriteLine($"You are {age} years old, {name}.");
	}

    }
}
