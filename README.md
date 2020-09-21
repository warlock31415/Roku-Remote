# Roku Remote

## Introduction
My roomate keeps loosing the remote to the TV. So I made a spare remote to work with our TV and simulates the same behaviour as the original remote. The remote can also work via micro USB as well as a Lithium polymer battery. This project was my first forray into ARM microcontrollers and ST's Hardware Abstraction Layer (HAL).  

## Recording button codes
The Roku remote work on a IR signal and the data is modulated on the 37 kHz signal. The NEC protocol decription can be found [here] (https://techdocs.altium.com/display/FPGA/NEC+Infrared+Transmission+Protocol) . A Analog Discovery along with the TSOP382 (IR receiver) was used to record the signal. The receiver demodulates the signal internally and only ouputs the data bits. Each button was pressed and the corresponding code was recorded. It was noted that each button had 2 codes associated with it. The first one was transmitted when the button was pressed and the second was transmitted when the button was held down. 

## The code
ST's Nucleo-F401RE(497-14360-ND) was used to build the remote on a breadboard. Although, a STM32L052K8T was actually used in the final prototype due to its lower power consumption as compared to the STM32F401RE.

The HAL does not have a microsecond delay so a timer was used. ST's Cube IDE makes it very easy to set up and use timers graphically. To generate the carrier another 16-bit advanced timer was used in PWM mode. The STM32F401RE has 16-bit prescale register which allows just about any frequency. This, combined with the Auto-Prelor Register, one can generate just about any frequency signal with any duty cycle. So a 37kHz carrier with a 30% duty cycle, for efficiency, was generated. This Precale and AR registers are especially more advatageous to an ATMEGA328P which only has a couple of prescalers to choose from and the "auto reload register" is the only way to control frequency. And hence duty cycle cannot be controlled in the same way.

## PCB
The PCB was made in Eagle and manufactured by JLCPCB. All components were hand soldered. Including, the STM32L052K8T. The blue silk screen on the PCBs look pretty good. 
