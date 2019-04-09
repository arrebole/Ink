using message;

class Program
{
    static void Main(string[] args)
    {
        MessageFactory.createMessage(MessageTypes.success).code();
        MessageFactory.createMessage(MessageTypes.error).code();
    }
}
