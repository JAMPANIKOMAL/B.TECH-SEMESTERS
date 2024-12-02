class a258
{
    int a, b;

    a258(int x, int y)
    {
        a = x;
        b = y;
    }

    void display()
    {
        System.out.println("Sum: " + (a + b));
    }

    public static void main(String[] args)
    {
        a258 obj = new a258(5, 10);
        obj.display();
    }
}
