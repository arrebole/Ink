#! pwsh

$arch = "x64";
$vsPath = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community";
$vsDevShell = Join-Path $vsPath "Common7\Tools\Microsoft.VisualStudio.DevShell.dll";
$libDir = "D:\Applications\Scoop\apps\vcpkg\current\installed\$arch-windows-static\lib";
$includeDir = "D:\Applications\Scoop\apps\vcpkg\current\installed\$arch-windows-static\include";

# 如果没有 Enter-VsDevShell 命令则加载模块 DevShell
if (-Not $(Get-Command 'Enter-VsDevShell' -errorAction SilentlyContinue)) {
    Import-Module ($vsDevShell)
    Enter-VsDevShell -VsInstallPath $vsPath -DevCmdArguments "-arch=$arch -no_logo"
}

# 增加第三方库头文件路径
if (-Not $env:INCLUDE.contains($includeDir)) {
    $env:INCLUDE = $env:INCLUDE + ";" + $includeDir
}

# 增加第三方lib路径
if (-Not $env:LIB.contains($libDir)) {
    $env:LIB = $env:LIB + ";" + $libDir
}
echo $env:LIB
cl.exe /Fe:app.exe main.c /source-charset:utf-8 /link User32.lib glfw3.lib opengl32.lib gdi32.lib shell32.lib

Remove-Item *.obj