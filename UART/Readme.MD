**objective**

To Send I/O Pin Status over Asynchronous serial(UART) link. Enable serial
communication between PC and microcontroller
using UART link, For example declare any
two GPIO pins as input and logical state (high / low) of those pins will be reported over UART
to the external serial device.

**Frame Configuration**

Frame Size - 8N1 (8-Data Bits, 1-Start, 1- Stop)

Baudrate - 9600 bps

**Setting the Baudrate**

Communication baud rate is derived from the system’s master clock f master . This f master can come
from various sources. STM8S has total 3 sources of clock. Figure below shows the clock tree of
STM8 devices. Master clock can be derived from external crystal oscillator (HSE) or Internal
clock sources (HSI, LSI). STM8 has 1 MHz internal clock source which can be further prescaled.
Similarly we can connect an external clock source of up to 24 MHz. The actual source of master
clock can be selected using CLK SWR register.

![image](https://cloud.githubusercontent.com/assets/25156625/26523889/2562e076-4340-11e7-9e08-ff30f6d0e0b9.png)

Now, in order to ensure proper baud rate of 9600 in our experiment, we must set the master clock
desired value, because baud rate will be decided using value of Master clock. Set the proper
values in BRR1 and BRR2 registers according to your master clock value.

**Procedure**
1. Make sure master clock is at 16 MHz.
2. Configure the frame for 8 data bits and 1 stop bit.
3. Set the baud rate registers.
4. Enable the UART module.
