Function BuildUDP()
{
    echo "build udp server...";
    clang ./UDPServer.c -Wall -o udpServer.exe -lws2_32;
}

Function BuildUDP()
{
    echo "build tcp server...";
    clang ./TCPServer.c -Wall -o tcpServer.exe -lws2_32;
}

BuildUDP;