class a121
{
    public static void main (String [] args)
    {
        sum(new int[]{10, 20, 30});
    }
    public static void sum(int[] x) 
    {
        int total = 0;
        for (int x1 : x) 
        {
            total += x1;
        }
        System.out.println("Sum: " + total);
    }
}