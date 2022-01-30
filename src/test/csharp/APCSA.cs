using System;
using APCSA;

FeigenbaumU3 u3 = new FeigenbaumU3();
u3.main();
namespace APCSA
{
    class FeigenbaumU3
    {
        private const string alphabetLower = "abcdefghijklmnopqrstuvwxyz";
        private const string alphabetUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        public void main()
        {
            Console.WriteLine("Program input: A string, a shift, encrypt/decrypt option");
            Console.WriteLine("Program output: Either a decrypted or encrypted string based on user input");
            Console.Write("Enter a string: ");
            string message = Console.ReadLine();
            Console.Write("Enter a shift: ");
            int key = 0;
            while (!int.TryParse(Console.ReadLine(), out key) || key % 26 == 0)
                Console.Write("Please enter a number which is not a multiple of 26: ");
            string mode = "";
            do
            {
                Console.Write("Type 'e' to encrypt the string or 'd' to decrypt the string: ");
                mode = Console.ReadLine().ToLower();
                if (mode == "e")
                    Console.WriteLine($"Your encrypted string is: {encrypt(message, key)}");
                else if (mode == "d")
                    Console.WriteLine($"Your decrypted string is: {decrypt(message, key)}");
                else
                    Console.Write("Please enter your choice again: ");
            } while (mode != "e" && mode != "d");
        }

        public string encrypt(string message, int key)
        {
            string encryptedstring = "";
            char currentChar;
            for (int i = 0; i < message.Length; i++)
            {
                currentChar = message[i];
                if (alphabetLower.IndexOf(currentChar) != -1)
                    encryptedstring += alphabetLower[(alphabetLower.IndexOf(currentChar) + key) % 26];
                else if (alphabetUpper.IndexOf(currentChar) != -1)
                    encryptedstring += alphabetUpper[(alphabetUpper.IndexOf(currentChar) + key) % 26];
                else
                    encryptedstring += currentChar;
            }
            return encryptedstring;
        }

        public string decrypt(string message, int key)
        {
            return encrypt(message, 26 - key);
        }
    }
}
