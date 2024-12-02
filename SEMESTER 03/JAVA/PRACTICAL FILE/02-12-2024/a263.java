class Parent
{
    void show()
    {
        System.out.println("Parent Method");
    }
}

class a263 extends Parent
{
    void show()
    {
        System.out.println("Child Method");
    }

    public static void main(String[] args)
    {
        a263 obj = new a263();
        obj.show();
    }
