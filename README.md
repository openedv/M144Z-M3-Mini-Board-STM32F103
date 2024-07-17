## 1 Repository overview

This repository is structured as follows:

+ A [1_docs](./1_docs) folder, containing related documentation, includes schematic diagrams, data sheets, pictures of each example configuration, pin elicitation diagrams, and pin assignment tables.
+ A [2_tools](./2_tools) folder, containing Development tools. Such as Flash download software, USB virtual serial port driver, and serial port terminal, etc
+ An [example](./examples) folder, containing examples of different peripherals.
+ A [libraries](./libraries) folder, containing HAL library for STM32F1.


## 2 Board Resources

Here aims to introduce the **hardware and software resources** of the M144Z-M3 Mini Board, including the introduction of chip resources, the introduction of experimental platform hardware resources, and the supporting resource use guide. By studying this manual, the reader will have a comprehensive understanding of the resources of the Mini Board, which will be very helpful for subsequent program design.

It is intended to provide readers with a comprehensive introduction to the M144Z-M3 Mini Board resources. It is highly recommended that you read this manual before learning the examples!

### 2.1 Hardware Description

M144Z-M3 Mini Board selects **STM32F103ZET6** as MCU.

<img src="./1_docs/3_figures/image/p1.png">


| Resource          | Quantity   | Description                                                         |
| ----------------- | ---------- | ------------------------------------------------------------------- |
| CPU               | 1          | STM32F103ZET6; FLASH:512KB; SRAM:64KB                               |
| SRAM              | 1          | 1MB, 16-bit parallel port access                                    |
| SPI FLASH         | 1          | 16MB                                                                |
| EEPROM            | 1          | 256B                                                                |
| Power Light       | 1          | BLUE                                                                |
| LED               | 2          | RED(LED0), GREEN(LED1)                                              |
| RESET BUTTON      | 1          | Used for MCU/LCD reset.                                             |
| KEY               | 3          | KEY0 (sets the boot mode function), WKUP (has the wake-up function) |
| SWD Interface     | 1          | Used for simulation debugging, downloading code, etc.               |
| 5V power input/output outlet     | 1 | For 5V power supply access/external supply of 5V voltage.     |
| 3.3V power input/output outlet   | 1 | For 3.3V power supply access/external supply of 5V voltage.   |
| Select the serial port interface | 1 | Used to select serial connection.                             |
| One click download circuit       | 1 | Easy to download code with serial port.                       |

 
<img src="./1_docs/3_figures/image/main.png">

+ **EEPROM**:The EEPROM chip, with a capacity of 2Kb, which is equivalent to 256 bytes. It is used to store important data that cannot be lost during power loss, such as system settings parameters/touch screen calibration data, etc. With this, it is convenient to achieve non-volatile data storage.
+ **NOR FLASH**:The SPI FLASH chip expanded externally on the mini board, with a capacity of 128Mbit, which is equivalent to 16M bytes. It can be used to store user data, meeting the demand for large-capacity data storage. Of course, if you find that 16M bytes are not sufficient, you can store the data on an external TF card.
+ **USB slave**: this interface can not only be used as a USB slave communication interface, but also has a power supply function, which can supply power for the Mini Board. USB_Slave can be used to connect the computer to realize the USB virtual serial port experiment.
+ **TF card interface**:The TF card interface driven via SDIO. The TF card capacity selection range is very wide (up to TB level). With this interface, it can meet the demand for massive data storage.
+ **TFTLCD interface**:This is the onboard LCD module interface on the mini board, which is connected to the TFTLCD module via FPC ribbon cable and an adapter board. This interface is compatible with the entire series of TFTLCD modules from Elecrow, including 2.4-inch, 3.5-inch, 4.3-inch, and 7-inch TFTLCD modules, and supports both resistive and capacitive touch functionalities.

### 2.2 Software Resources

There are up to **47** examples provided. Before learning each example, carefully read the **README.md**, which includes a brief introduction to the example function, hardware hookup, STM32CubeIDE configuration instructions, and running phenomena. Here are all the examples.

| Example Name                      | Example Name                      | Example Name                      |  
| --------------------------------- |  ----------------------           |  ----------------------           |
| 00_f103_test                      | 10_tftlcd_mcu                     | 19_spi                            |
| 01_led                            | 11_usmart                         | 20_touch                          | 
| 02_key                            | 12_rtc                            | 21_flash_eeprom                   |
| 03_exti                           | 13_1_lowpower_pvd                 | 22_sram                           |  
| 04_uart                           | 13_2_lowpower_sleep               | 23_malloc                         |
| 05_iwdg                           | 13_3_lowpower_stop                | 24_sd                             |
| 06_wwdg                           | 13_4_lowpower_standby             | 25_fatfs                          | 
| 07_btim                           | 14_dma                            | 26_picture                        | 
| 08_1_gtim_interrupt               | 15_1_adc_single_channel           | 27_1_dsp_basicmath                |
| 08_2_gtim_pwm                     | 15_2_adc_dma_single_channel       | 27_2_dsp_fft                      |
| 08_3_gtim_capture                 | 15_3_adc_dma_multi_channel        | 28_atkncr                         |
| 08_4_gtim_count                   | 16_adc_temperature                | 29_1_iap_bootloader               |
| 09_1_atim_npwm                    | 17_1_dac_output                   | 29_2_led_flash_app                |
| 09_2_atim_compare                 | 17_2_dac_triangular_wave          | 30_usb_card_reader                |
| 09_3_atim_cplm_pwm                | 17_3_dac_sine_wave                | 31_usb_vsp                        | 
| 09_4_atim_pwm_in                  | 18_iic                            | 32_freertos_demo                  |


## 3 How to use STM32CubeIDE
If you have not set up **STM32CubeIDE** or can't use it, you will need to do so following the [steps outlined in this tutorial](./1_docs/STM32CubeIDE_Usage_Guide.md).

## 4 Accessories
When using the MIni Board, you can use the following accessories.
 
| LCD module         | Dap Debugger   | USB to Serial Port module  | Digital Oscilloscope
| ------------------ | ----------------|---------------------------------------|------------------------------------------------ |
| <a href="https://github.com/openedv/LCD-module_2.8-inch_ATK-MD0280"><img src="./1_docs/3_figures/image/01_MD0280.png" width="250" height="200" /></a>     |    <a href="https://github.com/openedv/alientek-tools_DAP_Debugger"><img src="./1_docs/3_figures/image/Mini_HSDAP.png" width="200" height="100" /></a>     |    <a href="https://github.com/openedv/USB-to-Serial-Port-module-ATK-MO340P"><img src="./1_docs/3_figures/image/USB.png" width="280" /></a>  |  <a href="https://github.com/openedv/Digital-Oscilloscope_DS100"><img src="./1_docs/3_figures/image/digital.png" width="300" /></a>











