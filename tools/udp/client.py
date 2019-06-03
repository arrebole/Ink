# -*- coding: utf-8 -*-
import socket
import time
import sys

# 发送信息
def sendMessage(aSocket, addr: (str, int)):
    data = bytes("test...", 'ascii')
    for _ in range(10):
        aSocket.sendto(data, addr)
        time.sleep(1)
    print("发送完成")


# 用于测试udp 服务器
def testUdp(host: str = "127.0.0.1", port: int = 3000):
    client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sendMessage(client, (host, port))
    client.close()


if __name__ == "__main__":
    testUdp()
