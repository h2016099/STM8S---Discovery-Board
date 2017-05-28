**Objective**

To send the serial data to 74HC595 from STM8 SPI master. The data should be sent to 74HC595 over serial SPI bus & should get displayed on the 8 output LEDs.

**Methodology**

Configured spi as Master and no pre scaling of master clock. We have used Hsi as master clock and sent the same to SPI through PCKEN register. Baud rate chosen is master freq/256. Cpol and cpha both configured low. SPI master slave pin (PE.5) connected to VDD. Port b used for SHCP and SCK is connected to STCP of 74HC595. MOSI pin connected to DS.

**Schematic**
![image](https://cloud.githubusercontent.com/assets/25156625/26531516/5c98466c-4408-11e7-87d6-3ea0886d2b7f.png)

**Critical Issues**

1. For every data transmission to 74HC595, SHCP should be triggered from ‘zero’ to ‘one’
2. Monitor TXE bit to ensure the frame of data has been transmitted.

**References**

RM0016 – STM8S105C6 user manual

STM8S Datasheet for connections.

74HC595 Product Data Sheet


