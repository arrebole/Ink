
import socket
import time

# 获取域名的 ip地址
# dns解析域名
def queryIp(hostName: str) -> str:
    result = socket.gethostbyname(hostName)
    return result


if __name__ == "__main__":
    while True:
        print(queryIp("google.com"))
        time.sleep(0.5)
        
