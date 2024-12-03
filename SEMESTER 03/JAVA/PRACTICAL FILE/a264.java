class ParentClass
{
    void greet()
    {
        System.out.println("Hello from ParentClass");
    }
}

class a264 extends ParentClass
{
    void greet()
    {
        System.out.println("Hello from ChildClass");
    }

    public static void main(String[] args)
    {
        ParentClass obj = new a264();
        obj.greet();
    }
}
