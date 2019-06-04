$out = Resolve-Path ../../../../../target;
$udpServerFile = $out.path + "/udpServer-blocking-oneThread-c.exe";
$tcpServerFile = $out.path + "/tcpServer-blocking-oneThread-c.exe";
$tcpServerMultithreadingFile = $out.path + "/tcpServer-blocking-MultiThread-c.exe";

Function BuildUDP()
{
    echo "build udp server...";
    clang ./UDPServerOneThread.c -Wall -o $udpServerFile -lws2_32;
}

Function BuildTCP()
{
    echo "build tcp server...";
    clang ./TCPServerOneThread.c -Wall -o $tcpServerFile -lws2_32;
}

Function BuildTCPmultithreading()
{
    echo "build tcp multithreading server ..."
    clang ./TCPServerMultithreading.c -Wall -o $tcpServerMultithreadingFile -lws2_32;
}

BuildUDP;
BuildTCP;
BuildTCPmultithreading;