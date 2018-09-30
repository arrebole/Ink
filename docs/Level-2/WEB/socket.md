# socket编程

---



### go简单的tcp模型

>go 默认极为并发模型，利用goroutine实现并发处理。

```go
func main() {
	// 1、监听端口
	listen, err := net.Listen("tcp", "localhost:8080")
	if err != nil {
		return
	}

	for {
		// 2、接受请求
		conn, err := listen.Accept()
		if err != nil {
			return
		}
		go process(conn)
	}

}

// 3 处理请求
func process(conn net.Conn) {
	defer conn.Close()
	for {
		buf := make([]byte, 512)
		_, err := conn.Read(buf)
		if err != nil {
			return
		}
		fmt.Println(string(buf))
	}
}
```



### java简单的tcp模型

>基础socket实现，单线程同步模型，监听阻塞一次只能处理一个连接。

```java
public class TcpServer {
    public static void main(String[] args) throws Exception {
        ServerSocket serverSocket = null;
        try {
            serverSocket = new ServerSocket(8080);
            System.out.println("那就start...");
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }

        while (true) {
            try {

                Socket socket = serverSocket.accept();

                InputStream in = socket.getInputStream();
                OutputStream out = socket.getOutputStream();
                
                byte[] inBuff = new byte[1024];
                int len = in.read(inBuff);
                String str = new String(inBuff, 0, len);
                System.out.print(str);

                byte[] outBuff = new byte[1024];
                outBuff = inBuff;
                out.write(outBuff);
                out.flush();

                
                socket.close();

            } catch (SocketTimeoutException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
                break;
            }

        }

        try {
            serverSocket.close();
        } catch (SocketException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
```

