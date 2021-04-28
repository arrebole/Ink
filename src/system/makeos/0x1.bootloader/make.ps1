#! pwsh

function buildBoot {
    param (
        [string]$file,
        [string]$out
    )
    as -o temp.o $file
    ld -r -Ttext 0x0 -e _start -s -o temp.out temp.o
    objcopy -O binary -j .text temp.out $out

    Remove-Item temp*
}

buildBoot -file boot.s -out boot.bin
