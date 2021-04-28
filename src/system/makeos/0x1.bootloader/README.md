# bootstrap

## 基础概念
+ 硬盘类型: HDD(传统硬盘)、HHD(混合硬盘)、SSD(固态硬盘)
+ 磁碟分割方式：GPT、MBR
+ 文件系统：NTFS(win)、EXT4(linux)、HFS+(macos)、FAT32、、EXFAT、EXT3
+ 固件接口标准: UEFI、BOIS
+ 自启方式: UEFI模式(UEFI + GPT)、Legacy模式(BIOS + MBR)

## 固件接口标准
### BIOS
> Basic Input/Output System，即基本輸入輸出系統。

IBM推出的业界标准的固件接口，存储于主板的 `ROM` / `EEPROM` / `flash` 中。它在开机后会最先启动，然后按照里面写好的步骤把主要硬件挨个检查一遍，然后去硬盘找引导程序，然后把引导权交给它，然后就进系统了。

简单来说 `bios` 启动是直接读取硬盘0扇区数据，所以bios启动需要弄扇区启动代码，因为bios基于扇区启动硬盘系统。

### UEFI
> Unified Extensible Firmware Interface，即统一可扩展固件接口, 用于替代BIOS接口，EFI是UEFI的前称，

UEFI 加了很多特性，比如可以使用鼠标（bios只能用键盘），可以启用蓝牙。efi一个很重要的特性是它可以直接把引导权限交给硬盘上的efi分区（一个特定的系统分区，大小200m），这样会省掉很多启动时间，同时实现更丰富的功能。

简单来说 `uefi` 是基于文件启动硬盘系统， 直接读取硬盘 `esp` 分区内特定文件 `/efi/boot/bootx64.efi`， mbr分区或gpt分区都支持  不用写入主引导 分区引导了 只需要把系统文件拷贝到位就行了。

## 启动方式实现
### BIOS引导启动
> `BIOS` 从引导设备中读取512个字节(硬盘的一个扇区)，如果在这512个字节的末尾检测到两个字节的 "0x55AA"，则将这512个字节中的数据作为代码加载并运行。

汇编实现一个`bootlader`程序(512byte)
```asm
.code16
.global _start
_start:
  mov $0x0e41, %ax
  int $0x10
  hlt
.fill 510-(.-_start), 1, 0
.word 0xaa55
```

linux 平台编译
```bash
# 编译汇编
as -o boot.o boot.s
# 输出为纯二进制文件，指定程序的入口点 -e _start
ld -o boot.bin --oformat binary -e _start boot.o
```

win 平台编译
```powershell
as -o boot.o boot.s
ld -r -Ttext 0x0 -e _start -s -o boot.out boot.o
objcopy -O binary -j .text boot.out boot.bin
```

执行程序
```bash
qemu-system-x86_64 boot.bin
```

### uefi引导启动
>  将efi存放为 `esp` (FAT格式) 分区内的 `/efi/boot/bootx64.efi`

```bash
mkdir -p esp/efi/boot && mv boot.bin esp/efi/boot/bootx64.efi
qemu-system-x86_64 \
  -drive format=raw,file=fat:rw:esp \
  -m 1024 \
  -nographic \
  -no-fd-bootchk \
  -smp 2
```