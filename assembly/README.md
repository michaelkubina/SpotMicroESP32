# Assembly #
This document describes the assembly process for the SpotMicroESP32. There are some prerequisites to make, before you can begin with the assembly of your printed parts and before you can mount your parts into place. Make sure you have the necessary parts from the [3D-printed Partlist](https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/). You will need at least the screws and nuts from the [Bill of Materials](https://github.com/michaelkubina/SpotMicroESP32#bill-of-material).

**Important! Read the assembly guide at least once, so you are familiar with when to use mirrored parts or which servo should be mounted with which actual gear-position.**

## Prerequisites ##
The single most important thing is to test and to calibrate your servos. By calibration i mean to determin the minimum and maximum positions, and what dutycicle results in what actual angle. Don't use any servos, that behave weird in any way, such as: stuttering, grinding noises, clicking noises or which wont turn at least full 180° - you would regret it afterwards and will have to do a lot of disassembling stuff to get it straight. At last it is important, that you position each servo into a specific position, which will be named in the parts-list in each major step. Depending on where it should be mountet, it results in 2x 0° 2x 60°, 2x 120°, 2x 180° and 4x 90°. Make sure you add all the rubber dampeners to your servos, so you could fit the M3 through the mounting holes.
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
|  4x | MG996R at 2x 60° and 2x 120° |
| 16x | Servo rubber dampeners (should be shipped with your servo) |
|  4x | FSH6S Servohorn |
|  4x | 625zz ball bearings without flange |
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

You need to screw the M2 nuts on the M2x8 first, otherwise it would hinder the mounting of the servohorn. You can't use the bare M2x8 screws without the nuts in this step, because they would stick out from the other side and touch the servo unavoidably, which would result in blocking the servo movement or other damage. **You might consider using M2x6 instead and ditch the need for M2 nuts here completly.** Screw the servohorn into place, using the middle hole on each little arm. Make sure that the two arms of the servohorn are perfectly perpendicular to the lower leg, when mounted to the servogear at 0° resp 180° (depending which leg) and which arm was on top then. This is because the teeth are not an even number and by this not symmetrical which would either result in a gap between the lower and upper leg when resting or in the worst case, the servo could not rest in 0° or 180° position and always stutter thus pulling more current. 

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

![009 - Top Shell & Bottom Shell](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/009_topshell_mid_frontview.png)

![009 - Top Shell & Bottom Shell](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/009_topshell_mid_backview.png)

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

## Shoulder Joint ##

You need to make two identical Shoulder Joints for both sides - this means, that you need two mirrored pieces for the Shoulder Joint Servomount. This time instead of mounting both on the right or left, each the left and right side will have one of the mirrored pieces.

### Parts ###

**you might use only two M2x8 on each servohorn cap to screw the servohorn into place and thus reducing the amount of M2x8 screws and M2 nuts by 2/3**

**if you have M2x6 then use these instead of the M2x8 which are only in use, because it was easier to buy the screws and nuts in bulk**

| Total Amount | Part |
|--------------|------|
|  4x | MG996R at 90° |
| 16x | Servo rubber dampeners (should be shipped with your servo) |
|  4x | FSH6S Servohorn |
|  |  |
|  |  |
|  4x | Shoulderjoint Servomount (2x right-handed, 2x left-handed) |
|  4x | Shoulderjoint Servohorn Cap |
|  4x | ball bearing Pin |
|  |  |
|  |  |
| 36x | M3 nuts |
| 16x | M3x20 |
| 20x | M3x8 |
| 24x | M2 nuts |
| 24x | M2x8 |

### Servohorn Cap Preparation ###

You need to screw the M2 nuts on the M2x8 first, otherwise it would hinder the mounting of the servohorn. You can't use the bare M2x8 screws without the nuts in this step, because they would stick out from the other side and touch the servo unavoidably, which would result in blocking the servo movement or other damage. **You might consider using M2x6 instead and ditch the need for M2 nuts here completly.** Screw the servohorn into place, using the middle hole on each little arm.

![013 - Servohorn Cap Preparation](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/013_servohorncap_pre.png)

![013 - Servohorn Cap Preparation](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/013_servohorncap_post.png)

### Attach Ballbearing Pin to Servomount ###

Insert 1x M2 nut into the small space in the Shoulderjoint Servomount. Screw 1x M2x8 through the ball bearing pin and attach it to the Shoulderjoint Servomount.

![014 - Attach Ballbearing Pin to Servomount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/014_shoulderpin_pre.png)

![014 - Attach Ballbearing Pin to Servomount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/014_shoulderpin_post.png)

### Attach Servohorn Cap to Servomount ###

Now insert 4x M3 nuts into to pockets in the base of the Servomount and screw the Servohorn Cap with 4x M3x8 into place.

![015 - Attach Servohorn Cap to Servomount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/015_servocap_servomount_pre.png)

![015 - Attach Servohorn Cap to Servomount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/015_servocap_servomount_post.png)

![015 - Attach Servohorn Cap to Servomount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/015_servocap_servomount_post_solid_front.png)

![015 - Attach Servohorn Cap to Servomount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/015_servocap_servomount_post_solid_back.png)

### Attach Shoulder Joint to upper Leg ###

For the robots normal standing position the lower legs servo is at 90° while the upper legs servo is at 120° (left legs) or 60° (right legs), depending which leg. Make sure you have actually positioned your servos correctly before, **otherwise you should do the movement befor assembling further**. When mounting the Shoulder Joint you wont align it to the upper leg along the upper star, but along the first to the right (left legs) resp. first to the left (right legs). Since the servohorn has six arms, each arm means an increase of 60°. For the left legs use this picture as an orientation.

![016 - Attach Shoulder Joint to upper Leg](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/016_shoulder_joint_leg_angles.png)

The assembly is straight forward. Take an M3x8 screw and screw the assembled shoulder joint into place, as mentioned above. It is intentional, that the upper leg wont move between both horizontal endpoints, but instead could retract the leg further to the back than to the front.

![016 - Attach Shoulder Joint to upper Leg](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/016_shoulder_joint_leg_pre.png)

![016 - Attach Shoulder Joint to upper Leg](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/016_shoulder_joint_leg_post.png)

![016 - Attach Shoulder Joint to upper Leg](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/016_shoulder_joint_leg_post_sideview.png)

### Attach Servo to Shoulder Joint ###

Make sure the servos you want to place are at 90°. Place 4x M3 nuts into the pockets for mounting the servo. Place the servo now into its pocket and screw it into place with 4x M3x20.

![017 - Attach Servo to Shoulder Joint](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/017_shoulder_joint_servomount_servo_pre.png)

![017 - Attach Servo to Shoulder Joint](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/017_shoulder_joint_servomount_servo_mid.png)

![017 - Attach Servo to Shoulder Joint](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/017_shoulder_joint_servomount_servo_post.png)

### Shoulder Joint Completed ###

You have now succesfully attached the Shoulder Joint to the upper leg. With this you have now completed the front left leg. Repeat the steps for the other 3 legs and make sure you use the mirrored parts when building the right legs and the left legs. **And keep in mind, that the shoulder joint uses the mirrored parts for the front or rear leg on both sides!**

![018 - Shoulder Joint Completed](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/018_shoulder_joint_complete.png)

![018 - Shoulder Joint Completed](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/018_shoulder_joint_complete_sideview.png)

### Overview of all of the four legs ###

With the front left (FL) leg finished, rebuild the rear left (RL) leg with the same steps. But this time use the mirrored shoulder joint piece instead. The picture below shows both legs, where the only difference is the direction the servo in the shoulder joint is facing. Both gears should face outwards towards the nose or back of the robot.

![019 - Overview of all of the four legs](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/019_left_legs.png)

The same applies to the front right (FR) and rear right (RR) leg, with both servo gears facing outwards. Use for the right sided legs also the mirrored copies of the lower and upper leg parts. Keep in mind, that you have set the right angles for your servos prior to assembly, with the servos in the shoulder joint being at 90°, the servos in the upper legs at 60° and the servos in the lower legs at 0°.

![019 - Overview of all of the four legs](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/019_right_legs.png)

When all of your legs are assembled the should look like this, with the front legs shoulder servos gears facing to the front of the robot and the rear shoulder servos facing backwards.

![019 - Overview of all of the four legs](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/019_all_legs.png)

## Connecting to the Shoulders ##

**you might use only two M2x8 on each servohorn cap to screw the servohorn into place and thus reducing the amount of M2x8 screws and M2 nuts by 2/3**

**if you have M2x6 then use these instead of the M2x8 which are only in use, because it was easier to buy the screws and nuts in bulk**

| Total Amount | Part |
|--------------|------|
|  4x | FSH6S Servohorn |
|  |  |
|  |  |
|  2x | Outer Shoulder |
|  |  |
|  |  |
|  4x | M3x8 |
| 24x | M2 nuts |
| 24x | M2x8 |

Screw the servohorns to the outer shoulder piece with twelve M2x8 screws and nuts.

![020 - Connecting to the Shoulders](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/020_Front_Outer_Shoulder_pre.png)

![020 - Connecting to the Shoulders](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/020_Front_Outer_Shoulder_post.png)

### Front & Rear Legs ###

Screw the front legs to the outer shoulder using two M3x8 screws. Make sure the servos in the shoulder joints are at 90° and that the arms of the servohorn are perfectly perpendicular.

![020 - Front & Rear Legs](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/020_front_outer_shoulder_front_legs_pre.png)

![020 - Front & Rear Legs](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/020_front_outer_shoulder_front_legs_mid.png)

Repeat this for the rear legs as well, so that both outer shoulder pieces face outwards.

![020 - Front & Rear Legs](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/020_front_outer_shoulder_front_legs_post.png)

![020 - Front & Rear Legs](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/020_rear_outer_shoulder_rear_legs_post.png)

The front and rear legs with the shoulder should look like this.

![020 - Front & Rear Legs](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/020_Outer_Shoulders_complete.png)

## Body ##

| Total Amount | Part |
|--------------|------|
|  4x | 625zz ball bearings without flange |
|  |  |
|  |  |
|  2x | Inner Shoulder |
|  2x | Top Shoulder |
|  2x | Bottom Shoulder |
|  2x | Chassis Side |
|  1x | Circuitry Mountingplate **(still in development)** |
|  |  |
|  |  |
| 24x | M3 nuts |
| 24x | M3x8 |

### Inner Shoulders ###

Add into each the top and bottom shoulder block two M3 nuts. Make sure you have oriented the blocks the right way, so that the pockets for the nuts that will be used to hold the covers are facing into the body.

![021 - Inner Shoulders](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/021_inner_shoulders_pre.png)

Screw the inner shoulder with four M3x8 screws into place, so that the screwsheads will sink into their pockets.

![021 - Inner Shoulders](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/021_inner_shoulders_mid.png)

![021 - Inner Shoulders](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/021_inner_shoulders_post.png)

### Chassis ###

Take the chassis side piece and place four M3 nuts into their pockets - the flat side should face outwards and the long cutout for the circuitry mountingplate should be at the bottom. **Currently the circuitry mountingplate is in development - the orange piece is just a placeholder and actually the template piece, if someone wants to design their own**

![021 - Chassis](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/021_chassis_sides.png)

Put your ***(pre-populated ???)*** circuitry mountingplate between both sides.

![021 - Chassis](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/021_chassis_sides_circuitboardmount_pre.png)

![021 - Chassis](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/021_chassis_sides_circuitboardmount_post.png)

Now attach both inner shoulders to it with each four M3x8 screws and the bigger blocks being at the top.

![021 - Chassis](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/021_chassis_all_pre.png)

The assembled chassis should look like this.

![021 - Chassis](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/021_chassis_all_post.png)

### Mount legs to chassis ###

Attach now the ball bearings to your shoulder joints. Put into the front of the top and bottom shoulder block M3 nuts. Screw the front legs assembly to the shoulder block with four M3x8 screws.

![022 - Mount legs to chassis](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/022_chassis_front_legs_and_shoulder_pre.png)

![022 - Mount legs to chassis](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/022_chassis_front_legs_and_shoulder_post.png)

Repeat the steps for the rear legs as well.

![022 - Mount legs to chassis](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/022_chassis_rear_legs_and_shoulder_pre.png)

![022 - Mount legs to chassis](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/022_chassis_rear_legs_and_shoulder_post.png)

When finished, your SpotMicroESP32 should look like this.

![022 - Mount legs to chassis](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/022_all_chassis_and_legs.png)

## Head with ESP32-CAM ##

| Total Amount | Part |
|--------------|------|
|  1x | ESP32-CAM with OV2640 (Version 2! with slightly longer cable) |
|  2x | HC-SR04 Ultrasonic Sensor |
|  |  |
|  |  |
|  1x | Front Cover |
|  1x | Sensormount ESP32-CAM|
|  1x | Cameramount ESP32-CAM|
|  1x | Cameramount Counterpiece ESP32-CAM|
|  |  |
|  |  |
|  4x | M3 nuts |
|  6x | M3x8 |

Place the ESP32-CAM into the designated place of the Cameramount. Screw the counterpiece with two M3x8 screws into place, with the small pads facing towards the ESP32-CAM thus preventing the PCB from lifting. Place now the two HC-SR04 into their spaces in the sensormount-piece, but dont push them all way down yet. Instead leave some half centimeter space.. Push now the Cameramount-piece on top of if, so that the wedges slide on top of the HC-SR04 PCBs, thus preventing them from slipping back out again. It might be necessare to hone down a small portion of the lower ends of the wedges.

Place now four M3 nuts into the spaces in the front cover, push the sensor- & cameramount into place and screw all of it with four M3x8 screws into place. The head is now assembled.

## Head with OV7670 (DEPRECATED) ##

| Total Amount | Part |
|--------------|------|
|  1x | OV7670 VGA Camera w/o FIFO |
|  2x | HC-SR04 Ultrasonic Sensor |
|  6x | 5mm LED (White) |
|  |  |
|  |  |
|  1x | Front Cover |
|  1x | Sensormount |
|  1x | Cameramount |
|  |  |
|  |  |
|  8x | M3 nuts |
|  8x | M3x8 |

### Cameramount ###

Place four M3 nuts into the pockets below the tilted camera-base.

![023 - Cameramount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/023_cameramount_nuts_pre.png)

![023 - Cameramount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/023_cameramount_nuts_post.png)

Screw your OV7670 VGA Camera into place with four M3x8 screws.

![023 - Cameramount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/023_camera_mate_pre.png)

![023 - Cameramount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/023_camera_mate_post.png)

### Sensormount ###

**You will need to bend (or solder) the pins of the HC-SR04 in a fashian that they are parallell to the PCB and facing inwards. If the pins are perpendicular to the PCB you would not have enough space, to attach the head to the body. If being parallel and facing outwards, you would not be able to do the assembly at all. If you feel more comfortable with soldering the cables directly to the PCB, do this instead.**

Place your six 5mm LED (white) into the six small holes of the sensormount with their pins in the orientation as seen in the image. The two white LEDs in the middle row (highlighted in pink or green) need to be rotated by 90°, otherwise you would not be able to assemble proberly.

![023 - Sensormount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/023_leds_pre.png)

![023 - Sensormount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/023_leds_post.png)

Place now both HC-SR04 Ultrasonic Sensors into the sensormount, but dont push them into their pockets completly yet - leave them about half a centimeter of space for now. Make sure you have oriented them the right way, so that the internal oscillator fits into the small pocket at the sides of the sensormount. Place the assembled cameramount on top of it and push both pieces together. Make sure you route the pins of the LEDs through their holes at the top and bottom row, and the pins in the middle row along the camera-base near the HC-SR04's.

![023 - Sensormount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/023_sensormount_camermount_mate_pre.png)

When your Cameramount slides over the HC-SR04 Ultrasonic Sensors (still sticking out ca. half a centimeter), push the cameramount and the sensors gently down. 

![023 - Sensormount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/023_sensormount_camermount_mate_mid.png)

The Cameramount has two small wegdes (highlighted green) on the sides of the camera-base, which prevent the HC-SR04 from sliding out of their pockets. When pushing both the sensormount and the cameramount together, those wedges should push both HC-SR04 down. 

![023 - Sensormount](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/023_sensormount_camermount_mate_post.png)

### Build Assembly into front Cover ###

Place four M3 nuts into the spaces in the front cover.

![023 - Build Assembly into front Cover](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/023_front_cover_nuts.png)

Place the whole assembly into the front cover and screw it with four M3x8 into place.

![023 - Build Assembly into front Cover](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/023_mate_all_pre.png)

Your finished head-unit should look like this.

![023 - Build Assembly into front Cover](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/023_mate_all_mid.png)

![023 - Build Assembly into front Cover](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/023_mate_all_post.png)

## Tail ##

| Total Amount | Part |
|--------------|------|
|  1x | 1,8" TFT with ST7735 with SD-Card  |
|  1x | Push Button (latching, **not momentary**) |
|  |  |
|  |  |
|  1x | Rear Cover Long for the 1.8" TFT with SD-Card|
|  |  |
|  |  |
|  4x | M3 Nuts |
|  4x | M3x8 |

### Mount TFT Screen and Pushbutton ###

Place the 1,8" TFT with SD-Card into its designated pocket and screw it with four M3x8 screws into place - counter it with four M3 nuts from behind.

![024 - Mount TFT Screen and Pushbutton](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/024_tft_pre.png)

Remove the nut from your pushbutton and slide it through the hole - counter it with the nut again from behind.

![024 - Mount TFT Screen and Pushbutton](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/024_pushbutton_pre.png)

![024 - Mount TFT Screen and Pushbutton](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/024_tft_and_pushbutton_post_interior.png)

Your rear cover is complete.

![024 - Mount TFT Screen and Pushbutton](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/024_tft_and_pushbutton_post_exterior.png)

## Top and bottom Cover ##

**ATTENTION! The bottom cover needs to be overhauled, so we could easily access the balance-charger-cable of the LiPo. In the current configuration we are not even able to mount 2S LiPo's into place!**

| Total Amount | Part |
|--------------|------|
|  1x | Bottom Cover Front **do not use yet! See note above!** |
|  1x | Bottom Cover Rear **do not use yet! See note above!** |
|  1x | Top Cover Front  |
|  1x | Top Cover Rear  |
|  |  |
|  |  |
|  8x | M3 Nuts |
|  8x | M3x8 |

## Connect both cover halves ##

Take the front and rear half of the top cover. Use four M3x8 screws to screw both pieces together - counter them with four M3 nuts.

![025 - Connect both cover halves](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/025_top_cover_pre.png)

![025 - Connect both cover halves](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/025_top_cover_post.png)

Repeat this for the bottom cover halves as well.

![025 - Connect both cover halves](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/025_bottom_cover.png)

## Mount covers ##

| Total Amount | Part |
|--------------|------|
| 16x | M3 nuts |
| 16x | M3x8 |

In order to mount the head-unit, the tail and the top and bottom cover to the body, you need to add the M3 nuts into the top and bottom blocks in the front and rear shoulders (highlighed green).

![026 - Mount Head](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/026_shoulder_bottom_block_nuts.png)

![026 - Mount Head](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/026_shoulder_top_block_nuts.png)

### Mount Head ###

Slide the assembled head-unit onto the front shoulder-plate.

![026 - Mount Head](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/026_head_pre.png)

Screw it from the top and from the bottom with four M3x8 screws into place.

![026 - Mount Head](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/026_head_mid.png)

![026 - Mount Head](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/026_head_post.png)

### Mount Tail ###

Slide the tail onto the body as well and screw it with four M3x8 nuts into place.

![026 - Mount Tail](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/026_tail.png)

### Mount top and bottom covers ###

Place the bottom cover beneath the body and screw it with four M3x8 into place.

![026 - Mount top and bottom covers](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/026_bottom_cover.png)

Place the top cover over the body and screw it with four M3x8 screws into place.

![026 - Mount top and bottom covers](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/026_top_cover.png)

## Assembly Finished! ##

Congratulations, you have now succesfully assembled your SpotMicroESP32.

![027 - Assembly Finished!](https://github.com/michaelkubina/SpotMicroESP32/blob/master/assembly/images/027_spotmicroesp32_complete.png)

# what's left? #

**The mountingplate for the circuitry is still missing and is currently being designed!**
Once it's ready i will add the steps necessary as a separate sections in the chassis part.
The mountingplate suits specifically this build. You might use different hardware as i did, and as of this need modifications. Please use the updated Template, once its all finished.

Furthermore i want to adress some shortcomings in this guide. I want to replace all images, where the rubber dampeners are missing (mea culpa) and i want to make it more clear, which servo has to be at which angle for assembly. I realize, that the description are sometimes not very clear...i will need to think of a way to clarify this.