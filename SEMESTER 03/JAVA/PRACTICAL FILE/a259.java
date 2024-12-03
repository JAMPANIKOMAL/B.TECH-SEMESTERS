class a259 extends Thread
{
    public void run()
    {
        System.out.println("Thread is running");
    }

    public static void main(String[] args)
    {
        a259 thread = new a259();
        thread.start();
    }
}
