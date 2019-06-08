$outPath = "../../../../target/System/IO/block/";

$udpServerFile = $outPath + "udpServer-c.exe";
$tcpServerFile = $outPath + "tcpServer-c.exe";
$tcpServermultiThreadFile = $outPath + "tcpServer-multiThread-c.exe";


mkdir $outPath;


Write-Output "build blockIO udp server...";
clang ./UDPServ_win10-x64.c -Wall -o $udpServerFile -lws2_32;


Write-Output "build blockIO tcp server...";
clang ./UDPServ_win10-x64.c -Wall -o $tcpServerFile -lws2_32;

Write-Output "build blockIO tcp multithreading server ..."
clang ./TCPServ-multiThread_win10-x64.c -Wall -o $tcpServermultiThreadFile -lws2_32;

