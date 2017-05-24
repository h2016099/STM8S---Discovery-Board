**Objective**

In this experiment, the objective is to design a LED pattern repeating infinitely using STM8S105C6 microcontroller, 4 LEDs and a tactile switch such that the first LED glows when the tactile switch is pressed for the first time, the second glows on the second press of the switch and so on till all the led glows. The pattern must repeat itself infinitely upon pressing the switch after 5 times.

**Schematic**

Used 4 LED’s and connected them to port B. Output resistors of value 1k are also used to limit the current. The LED’s are driven by the STM8S105C6 microcontroller and the input is received by tactile switch as shown in figure below.

![image](https://cloud.githubusercontent.com/assets/25156625/26421475/d7c7e072-40e3-11e7-8df4-049a44fd63bd.png)

**Critical Issues**

At the press of the switch, it was taking the input as several times, so we have to create a loop such that it stays in the loop till the tactile switch has pressed down and comes out of the loop as soon as it is released.

** Software Design**

Used General Purpose Input Output (GPIO) function to control the input (tactile switch) and output i.e. LED’s by making use of Data Direction Register (DDR), Input Data Register (IDR), Output Data Register (ODR), and Control Register 1 (CR1).

