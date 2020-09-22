# Roku Remote

## Introduction
My roomate keeps loosing the remote to the TV. So I made a spare remote to work with our TV and simulates the same behaviour as the original remote. The remote can also work via micro USB as well as a Lithium polymer battery. This project was my first forray into ARM microcontrollers and ST's Hardware Abstraction Layer (HAL).  

## Recording button codes
The Roku remote work on a IR signal and the data is modulated on the 37 kHz signal. The NEC protocol decription can be found [here](https://techdocs.altium.com/display/FPGA/NEC+Infrared+Transmission+Protocol) . A Analog Discovery along with the TSOP382 (IR receiver) was used to record the signal. The receiver demodulates the signal internally and only ouputs the data bits. Each button was pressed and the corresponding code was recorded. It was noted that each button had 2 codes associated with it. The first one was transmitted when the button was pressed and the second was transmitted when the button was held down. Only the last 4 bytes of the codes are shown here as the first 4 bytes are always the same (0x57E3).

The recorded button codes are as follows:
| Button | Code in HEX |  Last 4 bytes of the held down code|
|--------|-------------| ----------|
| Power  | 0x57E3E817 | 0x57E3E916 | 
| Back   | 0x57E36699 | 0x57E36798 |
| Home   | 0xCO3F | 0xC13E |
| ↑      | 0x9867 | 0x9966 |
| →      | 0xB44B | 0xB54A |
| ↓      | 0xCC33 | 0xCD32 |
| ←      | 0x7887 | 0x7986 |
| OK     | 0x54AB | 0x55AA |
| V+     | 0xF00F | 0xF10E |
| V-     | 0x08F7 | 0x09F6 |
| Mute   | 0x04FB | 0x05FA |


## The code
ST's Nucleo-F401RE(497-14360-ND) was used to build the remote on a breadboard. Although, a STM32L052K8T was actually used in the final prototype due to its lower power consumption as compared to the STM32F401RE.

The HAL does not have a microsecond delay so a timer was used. The following code shows how this works:
```
void delay_us(uint16_t time)
{
	TIM6->ARR = time; 	 	// Load time into Auto Reload Register
	TIM6->CR1 |= (1<<0); 	// start timer

	while(TIM6->CR1 & 1);	// Wait for timer to elapse
}
```
ST's Cube IDE makes it very easy to set up and use timers graphically. To generate the carrier another 16-bit advanced timer was used in PWM mode. The STM32F401RE has 16-bit prescale register which allows just about any frequency. This, combined with the Auto-Prelor Register, one can generate just about any frequency signal with any duty cycle. So a 37kHz carrier with a 30% duty cycle, for efficiency, was generated. This Precale and AR registers are especially more advatageous to an ATMEGA328P which only has a couple of prescalers to choose from and the "auto reload register" is the only way to control frequency. And hence duty cycle cannot be controlled in the same way.

Each button code consists of 3 sections. The start code, specific button code and the end code. This can be seen in Table 1.
## PCB
The PCB was made in Eagle and manufactured by JLCPCB. All components were hand soldered. Including, the STM32L052K8T. The blue silk screen on the PCBs look pretty good. 

## Shortcomings
- The SMD IR transmitter that was spec'd for the project didn't seem to work properly. So a THT transmitter, was was used to test the breadboard prototype, was soldered in its place. Some wire bodging was needed to accomplish this.
- The battery protection circuitry was not correctly wired up (Some kind of issue with Battery GND vs system GND).

## TO DO
- Redo board to eliminate wire bodges.
- Make a case for the board.
