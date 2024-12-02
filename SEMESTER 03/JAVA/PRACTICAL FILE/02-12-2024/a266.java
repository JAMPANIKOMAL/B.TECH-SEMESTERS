interface Drawable
{
    void draw();
}

class a266 implements Drawable
{
    public void draw()
    {
        System.out.println("Drawing a rectangle");
    }

    public static void main(String[] args)
    {
        Drawable obj = new a266();
        obj.draw();
    }
}
