import random
from scapy.all import *


def randomSrcIP() -> str:
    rand = random.randint
    return f'78.141.{rand(60,62)}.{rand(1,255)}'


def randomSrcPort() -> int:
    return random.randint(10000, 65535)


def sendSYN(ip: str, port: int):
    # pack = Ether() / IP(dst=ip, src=randomSrcIP()) / TCP(dport=port, sport=randomSrcPort(), flags="S")
    pack = Ether() / IP(dst=ip) / TCP(dport=port, sport=randomSrcPort(), flags="S")
    sendp(pack, verbose=False)
