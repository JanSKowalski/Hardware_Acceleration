# Hardware_Acceleration

A living portfolio of projects related to the design and optimization of computer hardware. 
For more details about specifc accelerators, access the readme available in that directory.

| In Progress | 5, 6 |
|------|------|
| Completed   | 1-4  |



<!--Projects with VLSI components are available in the vlsi directory.-->



Xilinx Vitis-HLS allows for quick implementation of Verilog for FPGAs. There are two parts to the code: a "host" file that manages data on the computer and a "kernel" that is implemented on an FPGA.

Xilinx has its own V++ compiler that I use, targeting the u200 platform  
  https://www.xilinx.com/products/boards-and-kits/alveo/u200.html#gettingStarted

The accelerators are tested with software and hardware emulation, as I do not own a u200  
 <code> make run TARGET=\<sw_emu/hw_emu> DEVICE=xilinx_u200_xdma_201830_2 </code>

Thank you to my mentors for supporting my education
