class a232
{
    public static void main(String[] args)
    {
        try
        {
            throw new ArithmeticException("Custom Arithmetic Exception");
        }
        catch (ArithmeticException e)
        {
            System.out.print(e.getMessage());
        }
    }
}