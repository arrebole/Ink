
import socket
import time

# 创建链接的套接字
def tcpConnect(ip:str,port:int)->socket.socket:
    result = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    result.connect((ip,port))
    return result

def ping(aSocket:socket.socket):
    message = bytes("ping ...", 'ascii')
    for _ in range(300):
        # 阻塞式发送
        aSocket.send(message,0)
        time.sleep(1)
        


if __name__ == "__main__":
    tcpClient = tcpConnect("127.0.0.1",3000)
    ping(tcpClient)
    tcpClient.close()