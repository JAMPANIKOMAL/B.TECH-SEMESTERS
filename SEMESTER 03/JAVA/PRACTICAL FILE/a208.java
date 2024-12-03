class a208
{
    public static void main(String[] args)
    {
        int x = 5;
        int y = 0;
        try
        {
            int result = x / y;
        }
        catch (ArithmeticException e)
        {
            System.out.println("Cannot divide by zero");
        }
    }
}