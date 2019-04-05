
namespace Message
{
    public interface IMessage
    {
        void call();
    }

    public class Error : IMessage
    {
        void IMessage.call()
        {
            System.Console.WriteLine("error");
        }
    }

    public class Success : IMessage
    {
        void IMessage.call()
        {
            System.Console.WriteLine("success");
        }
    }

    public enum MessageTypes
    {
        success,
        error,
    }

    // 简单工厂模式
    public class MessageFactory
    {

        public static IMessage createMessage(MessageTypes arg)
        {

            switch (arg)
            {
                case MessageTypes.success:
                    return new Success();
                case MessageTypes.error:
                    return new Error();
            }
            return null;
        }
    }


}
