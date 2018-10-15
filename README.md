# Application to demonstrate Mbed-OS error handling and error coding APIs

This example demonstrates how to use the Mbed OS error handling API.

**Table of contents:**

1. [Requirements](#requirements)
1. [Setup](#setup)
   - [Clone the example](#import-the-example)
   - [Compile the example](#compile-the-example)
   - [Run the example](#run-the-example)

## Requirements

This example program can be run on any Mbed-Enabled device. For demostration purposes, the below documentation uses K64F as the test device. 

## Setup

#### Clone the example

Setup your Mbed development environment as described in - [Get started with Mbed OS](https://os.mbed.com/docs/latest/tutorials/your-first-program.html).

From the command-line, clone the example:

```
git clone https://github.com/ARMmbed/mbed-os-example-kernel-attach-hooks
cd mbed-os-example-error-handling
mbed deploy
```

#### Compile the example

Compile the application as below using ARM compiler. If you want to use GCC or IAR toolchains, use GCC_ARM or IAR for -t option.

```
mbed compile -m K64F -t ARM
```
This may take few minutes and once its successfully completed it would generate the output as below.

```
Link: mbed-os-example-kernel-attach-hooks
Elf2Bin: mbed-os-example-kernel-attach-hooks
| Module             |         .text |       .data |        .bss |
|--------------------|---------------|-------------|-------------|
| [lib]\c_w.l        | 11449(+11449) |     16(+16) |   348(+348) |
| [lib]\cpprt_w.l    |       36(+36) |       0(+0) |       0(+0) |
| [lib]\fz_wm.l      |       18(+18) |       0(+0) |       0(+0) |
| [lib]\m_wm.l       |       48(+48) |       0(+0) |       0(+0) |
| anon$$obj.o        |       32(+32) |       0(+0) | 1024(+1024) |
| main.o             |     308(+308) |       0(+0) |       0(+0) |
| mbed-os\components |       54(+54) |       0(+0) |       0(+0) |
| mbed-os\drivers    |     119(+119) |       0(+0) |       0(+0) |
| mbed-os\features   |       30(+30) |       0(+0) |   184(+184) |
| mbed-os\hal        |   1896(+1896) |     30(+30) |     64(+64) |
| mbed-os\platform   |   3548(+3548) |   104(+104) |   516(+516) |
| mbed-os\rtos       | 13155(+13155) | 2294(+2294) | 4588(+4588) |
| mbed-os\targets    |   9345(+9345) |   101(+101) |   324(+324) |
| Subtotals          | 40038(+40038) | 2545(+2545) | 7048(+7048) |
Total Static RAM memory (data + bss): 9593(+9593) bytes
Total Flash memory (text + data): 42583(+42583) bytes

Image: .\BUILD\k64f\arm\mbed-os-example-kernel-attach-hooks.bin
```

#### Run the example

1. Connect a K64F device to your pc
1. Open a serial terminal connected to the device
1. Copy the binary file to the device.
1. Reset the device by pressing the reset button to start the program.

The output should look similar to below:

```
attach_thread_terminate_hook demo:

test thread started

test thread exiting

test thread terminated

```

