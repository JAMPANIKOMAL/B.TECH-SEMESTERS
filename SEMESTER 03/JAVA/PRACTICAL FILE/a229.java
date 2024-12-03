class a229
{
    public static void main(String[] args)
    {
        try
        {
            int[] arr = {1, 2};
            System.out.print(arr[5]);
        }
        catch (ArrayIndexOutOfBoundsException e)
        {
            System.out.print("Array index out of bounds");
        }
    }
}
