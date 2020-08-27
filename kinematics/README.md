# Inverse Kinematics #

**still a lot to do**

## The legs ##

The length-measurements of the legs is performed on the centers of the rotational axis and from the perspective of the foottip touching the ground in its center.

* L1: 10mm
* L2: 60,5mm
* L3: 111,1mm (resp. L3a: 107mm / L3b: 30mm)
* L4: 118,5mm

The foot-tip actually just elevates the body 20mm from the ground on every leg and is because of this disregarded for now.

![L1_L2](https://github.com/michaelkubina/SpotMicroESP32/blob/master/kinematics/L1_L2.png)

![L3](https://github.com/michaelkubina/SpotMicroESP32/blob/master/kinematics/L3.png)

![L4](https://github.com/michaelkubina/SpotMicroESP32/blob/master/kinematics/L4.png)


## The body ##
The body (the plane where the four legs are attached to) is 78mm \* 207,5mm. The axis of the front and rear leg-pairs are 78mm apart, while the center of the first rotational axis of the legs is 207,5mm apart. The 207,5mm are the sum of the chassis side (150mm), both inner shoulders (each 5mm thick) and two times the halfes of the bottom/top shoulder blocks (2 \* 23,75mm = 47,5mm).

![Body](https://github.com/michaelkubina/SpotMicroESP32/blob/master/kinematics/body.png)
