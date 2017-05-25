**Objective**

To Design a voltage measurement system using STM8 ADC peripheral. Measure the input DC voltage [0-5V] and display the measured voltage on LED bar graph. Input voltage to the system can be provided using a linear potentiometer.

![image](https://cloud.githubusercontent.com/assets/25156625/26470274/b9544aae-41ba-11e7-8000-1626f6708ff6.png)

**Methodology**

The voltage is varied using a Potentiometer and the variable voltage is provided to AIN 0. 5 Led are connected to pin1-pin5 of port B. The ADC is configured to provide data according to the voltage at AIN 0 of Port B. The result of ADC is stored in DR Registers. We have used Continuous mode of Conversion and Pre-scaled the Master frequency by a factor of 8. The data converted after ADC is Right aligned.

**Schematic**

![image](https://cloud.githubusercontent.com/assets/25156625/26470422/40c631e6-41bb-11e7-97bf-8644683da7aa.png)



