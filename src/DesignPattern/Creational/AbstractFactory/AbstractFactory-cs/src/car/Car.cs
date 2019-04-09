namespace Car
{
    interface IWheel
    {
        void scroll();
    }

    interface IHorn
    {
        void didi();
    }

    interface ICarFactory
    {
        IWheel createWheel();
        IHorn createHorn();
    }


    class FerrariWheel : IWheel
    {
        public void scroll()
        {
            System.Console.WriteLine("FerrariWheel");
        }
    }

    class FerrariHorn : IHorn
    {
        public void didi()
        {
            System.Console.WriteLine("Ferrari didi");
        }
    }

    class BugattiWheel : IWheel
    {
        public void scroll()
        {
            System.Console.WriteLine("BugattiWheel");
        }
    }

    class BugattiHorn : IHorn
    {
        public void didi()
        {
            System.Console.WriteLine("Bugatti didi");
        }
    }

    class FerrariFactory : ICarFactory
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

    class BugattiFactory : ICarFactory
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

    public enum CarTypes
    {
        Bugatti,
        Ferrari,
    }
    public class Client
    {
        private IWheel wheel;
        private IHorn horn;
        public Client(CarTypes t)
        {
            ICarFactory factory = null;
            switch (t)
            {
                case CarTypes.Bugatti:
                    factory = new BugattiFactory();
                    break;
                case CarTypes.Ferrari:
                    factory = new FerrariFactory();
                    break;
            }
            this.wheel = factory.createWheel();
            this.horn = factory.createHorn();
        }

        public void run()
        {
            wheel.scroll();
            horn.didi();
        }

    }

}
