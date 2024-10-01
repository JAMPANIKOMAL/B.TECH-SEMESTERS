class a141
{
    int x = 10;
    static int y = 20; 
    public static void main(String[] args) 
    {
        a141 a1 = new a141();
        a1.x = 888;
        a1.y = 999;
        a141 a2 = new a141();
        System.out.println(a2.x + "   " + a2.y);
    }
}