# -*- coding: utf-8 -*-
import socket


def handle(aSocket: socket):
    while True:
        # recvfrom系统调用函数,无请求时线程阻塞并挂起
        data, addr = aSocket.recvfrom(1024)
        print('Received from %s:%s.' % addr,data.decode('utf-8'))

# udp 服务器, SOCK_DGRAM 无状态连接
def udpService(port: int = 3000):
    app = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    app.bind(("0.0.0.0", port))
    handle(app)


if __name__ == "__main__":
    udpService()
