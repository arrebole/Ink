.code16
.global _start # makes our label "_start" available to the outside

_start: # this is the beginning of our binary later.
  mov $0x0e41, %ax # sets AH to 0xe (function teletype) and al to 0x41 (ASCII "A")
  int $0x10 # call the function in ah from interrupt 0x10
  hlt # stops executing

.fill 510-(.-_start), 1, 0 # add zeroes to make it 510 bytes long
.word 0xaa55 # magic bytes that tell BIOS that this is bootable
