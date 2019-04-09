

namespace message
{
    public interface IMessage
    {
        void code();
    }

    public class Error : IMessage
    {
        public void code()
        {
            System.Console.WriteLine("error");
        }
    }

    public class Success : IMessage
    {
        public void code()
        {
            System.Console.WriteLine("success");
        }
    }

    public enum MessageTypes
    {
        success,
        error,
    }

    // 设计模式：简单工厂模式
    // 算法：——
    // 复杂度：——
    public class MessageFactory
    {

        public static IMessage createMessage(MessageTypes arg)
        {
            IMessage message = null;
            switch (arg)
            {
                case MessageTypes.success:
                    message = new Success();
                    break;
                
                case MessageTypes.error:
                    message =  new Error();
                    break;
            }
            return message;
        }
    }


}
