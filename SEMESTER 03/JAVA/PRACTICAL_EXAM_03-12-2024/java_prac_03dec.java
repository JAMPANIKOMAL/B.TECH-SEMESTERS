// Write a java program that:
// 1. Prompts the user to enter two integers
// 2. Performs divison of the first number by second
// 3. Uses try-catch blocks to handle any ArithmeticException (e.g., division by zero)
// 4. Displays an appropriate error message if an exception occurs; otherwise, displays the result.


import java.util.Scanner;
class java_prac_03dec 
{
	public static void main(String[] args) 
	{
        	Scanner s = new Scanner(System.in);

       		try 
		{
            		System.out.print("\nEnter the first integer: ");
            		int n = s.nextInt();
            		System.out.print("Enter the second integer: ");
            		int d = s.nextInt();
			int result = n / d;
			System.out.println("\nResult: " + result + "\n");
			
			//System.out.print("\n" + n + " / " + d + " = " + result + "\n");
			//System.out.print(result);
        	} 

		catch (ArithmeticException e) 
		{
            		System.out.println("Error: Division by zero.\n");
        	}
    	}
}

