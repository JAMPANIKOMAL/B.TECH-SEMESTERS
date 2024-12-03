abstract class Shape
{
    abstract void draw();

    void description()
    {
        System.out.println("This is a shape");
    }
}

class a265 extends Shape
{
    void draw()
    {
        System.out.println("Drawing a Circle");
    }

    public static void main(String[] args)
    {
        a265 circle = new a265();
        circle.description();
        circle.draw();
    }
}
