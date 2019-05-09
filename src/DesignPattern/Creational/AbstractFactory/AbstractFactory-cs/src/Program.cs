using Car;

// 抽象工厂客户端
// 仅使用由 AbstractFactory 和 AbstractProduct类声明的接口
class Client
{
    private IWheel wheel;
    private IHorn horn;
    public Client(ICarFactory f)
    {
        this.wheel = f.createWheel();
        this.horn = f.createHorn();
    }

    public void run()
    {
        wheel.scroll();
        horn.didi();
    }

}

public class Program
{
    public static void Main(string[] arg)
    {
        Client c = new Client(new FerrariFactory());
        c.run();
    }
}
