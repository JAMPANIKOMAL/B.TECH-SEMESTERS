class a228
{
    public static void main(String[] args)
    {
        try
        {
            int x = 10 / 0;
        }
        catch (ArithmeticException e)
        {
            System.out.print("Cannot divide by zero");
        }
    }
}