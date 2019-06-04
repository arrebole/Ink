$out = Resolve-Path ../../../../../target;
$udpServerFile = $out.path + "/tcpServer-nonblock-oneThread-c.exe"

clang-cl.exe .\tcpServer.cc -o $udpServerFile /link ws2_32.lib