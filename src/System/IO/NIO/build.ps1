
$outPath = "../../../../target/System/IO/nonblock/";
mkdir $outPath;
$udpServerFile = (Resolve-Path $outPath).Path + "tcpServer-nonblock-c.exe"

clang-cl.exe ./tcpServ.cc -o $udpServerFile /link ws2_32.lib