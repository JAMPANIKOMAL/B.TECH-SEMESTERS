class a230
{
    public static void main(String[] args)
    {
        try
        {
            int x = 10 / 0;
        }
        catch (ArithmeticException e)
        {
            System.out.print("Error");
        }
        finally
        {
            System.out.print("This will always execute");
        }
    }
}