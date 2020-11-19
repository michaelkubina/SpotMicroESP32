# Electronics #

**Work-in-Progress : currently working on tidying up the fritzing diagram, writing a kicad-schema and writing an "assembly and wiring instruction"**

![Circuitry Milestone](https://github.com/michaelkubina/SpotMicroESP32/blob/master/electronics/circuitry_working.jpg)

## Resources ##

You can find an excel-sheet in this sections, which describes the basic pin-assignments. I still need to tidy everything up, but the informations on this page are sort-of final. I actually am thinking to remove the TFT and the neopixel underglow completly. I am also thinking about integrating an DFPlayer Module to be able to play MP3 files and to add a current sensor in case we need to cut current draw from the servos when stalling.

## Wiring ##

This fritzing-diagram is not cleaned up, but it is in itself complete for the current state. When wiring your own robot, think of some kind of color coding for your wires, so its easier to distuingish them - for example:
* 5V with an violett wires
* 3.3V with an red wires
* I2C Clock white
* I2C Data grey
* etc...

![Fritzing Diagram](https://github.com/michaelkubina/SpotMicroESP32/blob/master/electronics/fritzing_diagram.png)

## Images ##

![Circuit Overview](https://github.com/michaelkubina/SpotMicroESP32/blob/master/electronics/images/electronics_0001.jpg)
![Circuit Overview](https://github.com/michaelkubina/SpotMicroESP32/blob/master/electronics/images/electronics_0002.jpg)
![Circuit Overview](https://github.com/michaelkubina/SpotMicroESP32/blob/master/electronics/images/electronics_0003.jpg)
![Circuit Overview](https://github.com/michaelkubina/SpotMicroESP32/blob/master/electronics/images/electronics_0004.jpg)
![Circuit Overview](https://github.com/michaelkubina/SpotMicroESP32/blob/master/electronics/images/electronics_0005.jpg)
![Circuit Overview](https://github.com/michaelkubina/SpotMicroESP32/blob/master/electronics/images/electronics_0006.jpg)
![Circuit Overview](https://github.com/michaelkubina/SpotMicroESP32/blob/master/electronics/images/electronics_0007.jpg)
![Circuit Overview](https://github.com/michaelkubina/SpotMicroESP32/blob/master/electronics/images/electronics_0008.jpg)

### PCA9685 ###

The PCA9685 is capable of FastMode+ (I2C clock at 1Mhz) - it should have its own I2C bus - which gives us more update cycles on the servos. The MG996R even though most tutorials and sellers claim their working frequency to be 50Hz, we can actually go to even 333Hz and beyond. The limit is only the 12Bit resolution and the maximum value for your servo for the max-angle. The pulsewidth of about 2ms + about 0.3ms is whats relevant for the IC in these digital servos.

Do not use Standard Mode - 100KHz
Do not use FastMode - 400KHz
Go with FastMode+ - 1MHz

| Channel | Servo | Abbreviation        |
|---------|-------|---------------------|
| CH0     | Front Left Shoulder   | FLS |
| CH1     | Front Left Upper Leg  | FLU |
| CH2     | Front Left Lower Leg  | FLL |
| CH3     | Front Right Shoulder  | FRS |
| CH4     | Front Right Upper Leg | FRU |
| CH5     | Front Right Lower Leg | FRL |
| CH6     | Rear Left Shoulder    | RLS |
| CH7     | Rear Left Upper Leg   | RLU |
| CH8     | Rear Left Lower Leg   | RLL |
| CH9     | Rear Right Shoulder   | RRS |
| CH10    | Rear Right Upper Leg  | RRU |
| CH11    | Rear Right Lower Leg  | RRL |
| CH12    | x | x |
| CH13    | x | x |
| CH14    | x | x |
| CH15    | x | x |