using Message;


class Program
{
    static void Main(string[] args)
    {
        MessageFactory.createMessage(MessageTypes.success).call();
        MessageFactory.createMessage(MessageTypes.error).call();
    }
}

