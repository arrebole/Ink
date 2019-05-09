namespace Car
{
    public interface IWheel
    {
        void scroll();
    }

    public interface IHorn
    {
        void didi();
    }

    public interface ICarFactory
    {
        IWheel createWheel();
        IHorn createHorn();
    }


    public class FerrariWheel : IWheel
    {
        public void scroll()
        {
            System.Console.WriteLine("FerrariWheel");
        }

    }

    internal class FerrariHorn : IHorn
    {
        public void didi()
        {
            System.Console.WriteLine("Ferrari didi");
        }
    }

    internal class BugattiWheel : IWheel
    {
        public void scroll()
        {
            System.Console.WriteLine("BugattiWheel");
        }
    }

    internal class BugattiHorn : IHorn
    {
        public void didi()
        {
            System.Console.WriteLine("Bugatti didi");
        }
    }

    public class FerrariFactory : ICarFactory
    {
        public IWheel createWheel()
        {
            return new FerrariWheel();
        }
        public IHorn createHorn()
        {
            return new FerrariHorn();
        }
    }

    public class BugattiFactory : ICarFactory
    {
        public IWheel createWheel()
        {
            return new BugattiWheel();
        }
        public IHorn createHorn()
        {
            return new BugattiHorn();
        }
    }

}
