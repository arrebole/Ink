
using Car;

class Program
{
    public static void Main(string[] arg)
    {
        Client c = new Client(CarTypes.Bugatti);
        c.run();
    }
}
