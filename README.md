# SpotMicroESP32

My take on a SpotMicro with an optimized design for supportfree 3D-printing utilizing an ESP32-DevKitC. This is still a Work-in-Progress!

You can find the 3D-printing parts on Thingiverse as well: https://www.thingiverse.com/thing:4559827/files

Join the Slack-Channel for this remix - discuss any topics regarding this design: spotmicroai.slack.com (#spotmicro-esp32)

This Project currently lacks the whole programming/software part. Luckily Maarten Weyn already made the inverse kinematics work and wrote also an Smartphone App for simple Control of this Robot via BLE. Take a look into his Repository as well:
https://github.com/maartenweyn/SpotMicro_ESP32

An walking gait implementation and voice-commanding was achieved by Guna R. from the slacks #spotmicro-esp32 channel, whis is build upon Maartens software (see Repo above). You definitly have to take a look there as well:
https://github.com/cholan2100/ceasar

Look also at the GitLab pages for the general SpomicroAI community, where you can find different models and resources: https://gitlab.com/custom_robots/spotmicroai

![SpotMicroESP32](https://github.com/michaelkubina/SpotMicroESP32/blob/master/spotmicroESP32.jpg)

## Note of thanks
I want to thank Deok-yeon Kim (KDY0523) for his beautyfull and well thought out design of the SpotMicro, without whom my derivate would not have been possible. You can find his original Design here on Thingiverse: https://www.thingiverse.com/thing:3445283

Him sharing the files with an open licence, made it possible to let it grow a community around it. This is why i want to reference to them as well - the SpotMicroAI Community: https://spotmicroai.readthedocs.io/en/latest/

## Preface
This is a work-in-progress, with rather loose milestones. For 2020 there were only two goals
- ~to redesign the original parts, so that they could be printed without any support~
- ~to make a circuitry for all sensors and parts, that possibly would fit and be considere necessary~ (currently sketching it in kicad and fritzing! coming soon!)

This repository is currently just my hobby and as such, it will have its own pace. This being said, i am still happy about any questions, collaborations, suggestions, ideas, forks and what else comes to your mind. I want you to participate, because i think there are a lot of things, that you could dig into.

## Coming soon...
- ~~Mountingplate for the ciruitry - FreeCAD and STL (in progress)~~
- more Template FreeCAD-Files for your own modifications
- KiCAD or Fritzing circuit diagrams

## Sections

* [3D-printed Partlist](https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/)
* [Bill of Materials](https://github.com/michaelkubina/SpotMicroESP32/#bill-of-material)
* [Assembly Guide](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/)
* [Electronics](https://github.com/michaelkubina/SpotMicroESP32/blob/master/electronics/)
* [Programming](https://github.com/michaelkubina/SpotMicroESP32/blob/master/code/)
* [Inverse Kinematics](https://github.com/michaelkubina/SpotMicroESP32/blob/master/kinematics/)

## Bill of Material
The following Section will describe in detail the different parts needed for your own SpotMicroESP32 build, with at least some rough estimate of the price.

### 3D-Printing
To build your own SpotMicroESP32 you will need to print a lot parts. For an overview of the 3D printed parts needed, please visit the [3D-printed Partlist](https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/). It might be necessary to remix some of the templates to suit your needs, when chosing other electronic components than those listet here.

### Electronics
The SpotMicroESP32 ist still a Work-in-Progress and as such the BOM might change as well - check the "deprecated" section for changes. There are still some parts missing and some others are not tested yet - those status will be marked as such. I will give a rough price estimate, which may or may not work for you and might be out of date at some point.

| part or module | number | short description | status | estimated price | 
|----------------|--------|-------------------|--------|:-------------------------|
| ESP32-DevKitC 							|  1x | the core MCU for the build with WIFI + BLE capabilities. 											| tested			| 7€		|
| ESP32-CAM									|  1x | ESP32-Module with OV2640 Camera (version 2). There are also cameras with a version 1 OV2640, where the sensor is in landscape orientation and not in portrait. Also the flexcable seems to be some millimeters shorter than the one from Version 2. You can distinguish them by the imprint on the flexcable, stating TY-OV2640-V2.0. Also dont go with the one with an fisheye-lens - the field of view would be hindered. 																		| tested	| 10€		|
| FT232RL USB-TTL-Adapter					|  1x | USB-to-Serial Adapter for ESP32-CAM flashing														| tested			| 2€		|
| (MG996R Servo)								| 12x | The bare minimum... but with flaws like jittering and much play... 10Kg servos with metal gears and ball bearings. With these the robot is capable to stand up/change his pose but they are most likely too weak for smooth and reliable walking. **(Update 2020-11-19: It can be affirmed, that walking is possible not great, but also not horrible)** Go with these only if you can accept these limitations and if more expensive servos would mean not to try this project in the first place.  										| tested			| 5€ each 	|
| better go with DS3218MG Servo 			| up to 12x | 20Kg servos with metal gears and ball bearings. Much less play and in my tests no jittering, but also very strong. With these your robot should be able to walk **significantly better**. Maybe only 4 of these are enough, when used in the lower legs - the most stressed parts. Maybe you would need also 4 additional ones for the upper legs - but maybe MG996R are enough here. The shoulders should be comfortable with MG996R, as these dont do much heavy work.  														| partially tested	| 15€-20€ each 	|
| FSH6S Servohorn 							| 12x | servohorn used for this build (should be already shipped with your servos) 							| tested 			| n.n. 		|
| Rubber Dampeners for your Servos			| 48x | servo rubber dampeners, so you could use M3 screws (should be already shipped with your servos) 	| tested 			| n.n. 		|
| Servocable Extension						|  4x | extending the servocables of the lower legs about 10cm to 15cm 										| tested			| 10€		|
| 625ZZ Ball Bearing 						|  8x | miniature ball bearing without a flange 															| tested 			| 1€ each 	|
| WS2812b 12 LED Ring (50mm outer diameter) |  1x | Neopixel-Clone-Ring with an outer diameter of 50mm used to signal status/mood						| tested            | 6€        |
| 0.96" OLED I2C Display					|  1x | small OLED screen with SSD1306 IC for status informations											| tested			| 4€		|
| HC-SR04 Ultrasonic Sensor					|  2x | ultrasonic sensor module for distance measuring														| tested			| 3€ each	|
| GY-521 Gyroscope and Accelerometer		|  1x | a module to measure accelaration and spatial orientation, which can be extented with magnetometers  | tested			| 3€		|
| PCA9685 16Channel 12Bit PWM Board			|  1x | PWM driver board used for your servos and LEDs, which can power your parts from an external source	| tested			| 5€		|
| HW-482 / KY-019 5V 10A Relais				|  1x | relais module to cut the power to your servos completely											| tested			| 3€		|
| 19mm Push Button with LED					|  1x | illuminated latching pushbutton 																	| tested			| 10€		|
| Micro-USB to DIP Adapter					|  2x | USB-Ports used for extending the USB-Ports of the ESP32 DevKitC and ESP32-CAM (TTL-Adapter)			| tested			| 2€		|
| XL4016 DC-DC 9A Stepdown Converter  		|  1x | big step-down converter to lower your LiPo 2S voltage to 6,5V **(will be deprecated after parts update)** | tested		    | 8€		|
| or SZBK07 DC-DC 20A Stepdown Converter  	|  1x | even bigger step-down converter to lower your LiPo 2S voltage to 6,5V **(parts updates pending)**	| tested		    | 12€		|
| LM2596 DC-DC or similar Stepdown Module	|  1x | small step-down converter to lower your LiPo 2S voltage 5V for ESP32's VIN and Modules 				| tested			| 2€ each	|
| 5200mAh - 6200mAh LiPo 30C+ 2S Tamiya/XH	|  1x | beefy LiPo as your main power source ***(this is actually your individual choice)***				| tested		 	| 40€		|

#### Depecrated

The Camera-Unit in the head will be replaced by an ESP32-CAM, because its reasonably cheap (~10€) and opens up a lot of new possibilities like object-recognition, because of additional processing-power.

| part or module | number | short description | status | estimated price | 
|----------------|--------|-------------------|--------|:-------------------------|
| OV7670 VGA-Camera Module w/o FIFO			|  1x | VGA-Camera without framebuffer IC, used with lower resolution due to memory restrictions **(replaced by ESP32-CAM)**			| tested			| 3€		|
| 5mm ~3V LEDs (White)						|  6x | LEDs used as your camera-lights	**(replaced by ESP32-CAM internal flashlight)**													| tested			| 1€		|
| 5mm ~3V RGB-LEDs							|  2x | RGB-LEDs used as an underglow, might signal status or mood **(replaced by Neopixel-Generica)**									| tested			| 1€		|
| 1,77" TFT with ST7735 w/o SD				|  1x | small TFT screen with ST7735 IC for status informations **(replaced by 1.8" TFT with SD-Card)**									| tested			| 7€		|
| optional WS2812B Pixelboard				|  4x | Neopixel-Clones (SMD LED's on small round PCB) used as an underglow, might signal status or mood	**(removed, as the result is underwealming** | tested			| 1€		|
| 1,8" TFT with ST7735 with SD				|  1x | small TFT screen with ST7735 IC for status informations	**(replaced by 0.96" OLED I2C Display)**	 |tested			| 7€		|

### Miscellaneous

| part or module | number | short description | status | estimated price | 
|----------------|--------|-------------------|--------|:-------------------------|
| M2x8 cylinderhead screws + M2 nuts		| 84x each | screws + nuts to mount your servohorns ***(you could glue the servohorns in place instead and save yourself 72x M2x8 screws and nuts, but i have not tested it)***, also used to mount the 1,77" TFT and the pins for the ball bearings 	| tested | 8€  |
| M3x8 cylinderhead screws + M3 nuts		| 80x each | screws + nuts for the whole assembly ***(i hope i have not forgotten some, better buy in bulk as these are usefull for other projects as well)***																							| tested | 8€  |
| M3x20 cylinderhead screws + M3 nuts		| 64x each | screws + nuts to mount your servos and assemble the upper legs																																												| tested | 12€ |
| lots of cables and connectors and stuff	|          | it's up to you which cables or wires and connectors you want to use, or if you would like to solder everything into place, and if you use heat shrinks, fabric hoses 																		| up to you | 20€ |
| PLA + TPU (***?***)						|          | you will need about 1Kg of PLA + some grams of TPU (eg. my Black/White design: 500g for the covers + upper legs, 500g for the chassis + lower legs + shoulder joints, some small grams for the grey sensorplate in the head) + some grams of TPU for the foottips | tested | 30€+ |