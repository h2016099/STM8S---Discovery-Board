**objective**

To Send I/O Pin Status over Asynchronous serial(UART) link. Enable serial
communication between PC and microcontroller
using UART link, For example declare any
two GPIO pins as input and logical state (high / low) of those pins will be reported over UART
to the external serial device.

Frame Size - 8N1 (8-Data Bits, 1-Start, 1- Stop)

Baudrate - 9600 bps

**Setting the Baudrate**

Communication baud rate is derived from the system’s master clock f master . This f master can come
from various sources. STM8S has total 3 sources of clock. Figure below shows the clock tree of
STM8 devices. Master clock can be derived from external crystal oscillator (HSE) or Internal
clock sources (HSI, LSI). STM8 has 1 MHz internal clock source which can be further prescaled.
Similarly we can connect an external clock source of up to 24 MHz. The actual source of master
clock can be selected using CLK SWR register.


