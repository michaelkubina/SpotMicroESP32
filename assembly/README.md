# Assembly #
This document describes the assembly process for the SpotMicroESP32. There are some prerequisites to make, before you can begin with the assembly of your printed parts and before you can mount your parts into place. Make sure you have the necessary parts from the [3D-printed Partlist](https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/). You will need at least the screws and nuts from the [Bill of Materials](https://github.com/michaelkubina/SpotMicroESP32/blob/master/).

## Prerequisites ##
The single most important thing is to test and to calibrate your servos. By calibration i mean to determin the minimum and maximum positions, and what dutycicle results in what actual angle. Don't use any servos, that behave weird in any way, such as: stuttering, grinding noises, clicking noises or which wont turn at least full 180° - you would regret it afterwards and will have to do a lot of disassembling stuff to get it straight. At last it is important, that you position each servo in it's 90° position.
If you wish to use fabric hoses, make sure you use the smallest and thinest possible. There is just not enough space in these parts to use thick ones. Or simply go with the standard servocable, which could look pretty nice, depending on your color theme.

## Lower Leg ##
You need to make two identical lower legs each for both sides - this means, that you need two mirrored pieces for the lower leg and lower leg counterpiece. Its important that you extend the servo cable and if you use fabric hoses, to guide it through.

### Parts ###

| Total Amount | Part |
|--------------|------|
|  4x | MG996R (2x at 0° and 2x at 180°) |
| 16x | Servo rubber dampeners (should be shipped with your servo) |
|  |  |
|  |  |
|  4x | lower leg (2x right-handed, 2x left-handed) |
|  4x | lower leg counterpiece (2x right-handed, 2x left-handed) |
|  4x | ball bearing pin |
|  4x | foot tips |
|  |  |
|  |  |
| 24x | M3 nuts |
| 16x | M3x20 |
|  8x | M3x8 |
|  4x | M2 nuts |
|  4x | M2x8 |

### Lower leg and foot tip ###

Insert 2x M3 nuts into their spaces in the lower leg. Hold the foot tip at position and screw with 2x M3x8 the foot tip into place.

![001 - Lower Leg & Foot Tip](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/001_lower_leg_foot.png)

### Lower leg counterpiece and ball bearing pin ###

Insert 1x M2 nut into the small space in the lower leg counterpiece. Screw 1x M2x8 through the ball bearing pin and attach it to the lower leg counterpiece.

![002 - Lower Leg Counterpiece & Ball Bearing Pin](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/002_lower_leg_counterpiece_pin.png)

### Lower leg counterpiece and ball bearing pin ###

Insert 4x M3 nuts into the small spaces in the lower leg counterpiece. Insert now from above the servo into its pocket in the lower leg counterpiece. Now push both the lower leg counterpiece with the servo and the lower leg with the foot tip together, closing all gaps. Be careful not to loose any M3 nuts and screw both parts together with 4x M3x20 screws.

![003 - Lower Leg Sandwich](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/003_lower_leg_sandwich.png)

### Lower leg completed ###

Your assembled lower leg should look like this one. Repeat it once again for the second left lower leg and assemble the two mirrored (right-handed) right lower legs.

![004 - Lower Leg Complete](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/004_lower_leg_complete.png)

## Upper Leg ##
You need to make two identical upper legs each for both sides - this means, that you need two mirrored pieces for the upper leg bottom shell, upper leg top shell, servohorn mount and ball bearing mount.

### Parts ###

**you might use only two M2x8 on each leg to screw the servohorn into place and thus reducing the amount of M2x8 screws and M2 nuts by 2/3**
**if you have M2x6 then use these instead of the M2x8 which are only in use, because it was easier to buy the screws and nuts in bulk**
**use the long version of the servohorn & ballbearing mount for improved resting position of the legs or stick to the normal version true to KDY-0523's design for the legs being at an angle when resting**

| Total Amount | Part |
|--------------|------|
|  4x | MG996R at 90° |
| 16x | Servo rubber dampeners (should be shipped with your servo) |
|  4x | 625zz ball bearings without flange|
|  |  |
|  |  |
|  4x | upper leg top shell (2x right-handed, 2x left-handed) |
|  4x | upper leg bottom shell (2x right-handed, 2x left-handed) |
|  4x | servohorn mount **long version!** (2x right-handed, 2x left-handed) |
|  4x | ball bearing mount **long version!** (2x right-handed, 2x left-handed) |
|  |  |
|  |  |
| 32x | M3 nuts |
| 32x | M3x20 |
|  4x | M3x8 |
| 24x | M2 nuts |
| 24x | M2x8 |

### Servohorn mount ###

You need to screw the M2 nuts on the M2x8 first, otherwise it would hinder the mounting of the servohorn. You can't use the bare M2x8 screws without the nuts in this step, because they would stick out from the other side and touch the servo unavoidably, which would result in blocking the servo movement or other damage. Screw the servohorn into place, using the middle hole on each little arm. Make sure that the two arms of the servohorn are perfectly perpendicular and which arm was on top. This is because the teeth are not an even number and by this not symmetrical. 

![005 - Servohorn & Servohornmount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/005_servohornmount_pre.png)

![005 - Servohorn & Servohornmount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/005_servohornmount_post.png)

### Attach Servohorn mount ###

Position the assembled servohorn mount to the lower leg and make sure that the right arm ist on top. Otherwise remove the servohorn and turn it around as long as it sits perfectly perpendicular and attach it again. Screw the whole servohornmount with a M3x8 to the servo gear.

![006 - Servohornmount & Servo Gear](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/006_servohornmount_pre.png)

![006 - Servohornmount & Servo Gear](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/006_servohornmount_post.png)

![006 - Servohornmount & Servo Gear](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/006_servohornmount_post_sideview.png)

### Attach Ballbearing mount ###

Push your 625ZZ Ball Bearing into the Ballbearing Mount (it should be are really tight fit). Afterwards push the ballbearing mount on the ballbearing pin of the lower leg.

![007 - Ballbearing mount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/007_ballbearingmount_pre.png)

![007 - Ballbearing mount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/007_ballbearingmount_post.png)

![007 - Ballbearing mount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/007_ballbearingmount_post_sideview.png)

### Upper Leg Bottom Shell preparation ###

Put four M3 nuts in the holes by the servo-pocket and push the servo into place. The two inner nuts are secured by the servo, the two out nuts might fall out so be careful not to lose them.

![008 - Bottom Shell & Servo](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/008_bottomshell_pre.png)

![008 - Bottom Shell & Servo](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/008_bottomshell_post.png)

### Route Cables through Upper Leg Top Shell ###

This part is a bit tricky, especialy when using fabric hoses for the servocables, since the space between the shells is very limited. Route your extended servocable from the lower leg through the front hole of the top shell. Pull after that the servocable of the bottom shell servo through the hole as well. 

![009 - Top Shell & Bottom Shell](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/009_topshell_pre.png)

Then push both shells toghether and at the same time pull the cables carfully further through the hole. Make sure the servocable from the lower leg goes into both shells through the gap between both shells and is further guided underneath the top shell in the groove specially made for it (marked green). You have also to watch out not to lose the two M3 nuts next to the servo.

![009 - Top Shell & Bottom Shell](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/009_bottomshell_mid_frontview.png)

![009 - Top Shell & Bottom Shell](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/009_bottomshell_mid_backview.png)

### Screw both shells together ###

When both shells are closed you might either move your cables freely back and forth through the hole, in the case you do not use fabric hoses. When using fabric hoses it might be to tight, so you must open the shells slightly, when you want to pull the cables further through.

![010 - Both Shells](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/010_bothshells_pre.png)

Use now four M3x20 to screw the servo into place and with it both the top and bottom shell, so they cant come apart without unscrewing them.

![010 - Both Shells](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/010_bothshells_mid.png)

![010 - Both Shells](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/010_bothshells_post.png)

### Complete Upper Leg ###

Now with both shell attached to each other and the servocables of the lower and upper leg routet through, place four M3 nuts in the four rear-facing pockets.

![011 - Preparations before completion](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/011_prepare_completion_pre.png)

![011 - Preparations before completion](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/011_prepare_completion_post.png)

Place then both shells on the lower leg so that the screwholes in the servohorn and ballbearing mounts align with those in the shells. Use four M3x20 screws, to screw everything together to complete the upper leg.

![012 - Completion of the Upper Leg](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/012_completion_pre.png)

![012 - Completion of the Upper Leg](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/012_completion_post_transparent.png)

This is also the robots legs resting position, which results in the legs laying flat.

![012 - Completion of the Upper Leg](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/012_completion_post_solid.png)

![012 - Completion of the Upper Leg](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/012_completion_post_frontview.png)

![012 - Completion of the Upper Leg](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/012_completion_post_sideview.png)

For the robots normal standing position the lower legs servo is at 90° while the upper legs servo is at 120° or 60°, depending which leg.

![012 - Completion of the Upper Leg](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/012_completion_post_standing_frontview.png)

![012 - Completion of the Upper Leg](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/012_completion_post_standing_sideview.png)

## to be continued... ##