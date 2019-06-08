$outPath = "../../../../../target/System/IO/multiplexing/";
if (-not(Test-Path $outPath)) {
    mkdir $outPath;
}

$Respath = Resolve-Path $outPath;
clang-cl.exe ./TCPServ-select_win10-x64.c  -o ($Respath.Path + "tcpServ-multiplexing-select-c.exe") /link ws2_32.lib;