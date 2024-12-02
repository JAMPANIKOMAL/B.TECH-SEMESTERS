class a267
{
    public static void main(String[] args)
    {
        try
        {
            int[] arr = new int[3];
            arr[4] = 5;
        }
        catch (ArrayIndexOutOfBoundsException e)
        {
            System.out.println("Array Index Out of Bounds Exception");
        }
    }
}
