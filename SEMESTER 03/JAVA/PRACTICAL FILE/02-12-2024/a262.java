class a261
{
    void display()
    {
        System.out.println("Base Class Display");
    }
}

class a262 extends a261
{
    void display()
    {
        System.out.println("Derived Class Display");
    }

    public static void main(String[] args)
    {
        a261 obj = new a262();
        obj.display();
    }
}
