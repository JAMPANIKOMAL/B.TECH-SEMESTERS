class CustomException extends Exception
{
    CustomException(String message)
    {
        super(message);
    }
}

class a260
{
    public static void main(String[] args)
    {
        try
        {
            throw new CustomException("This is a custom exception");
        }
        catch (CustomException e)
        {
            System.out.println(e.getMessage());
        }
    }
}
