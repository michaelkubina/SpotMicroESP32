# SpotMicroESP32
My take on a SpotMicro with an optimized design for supportfree 3D-printing utilizing an ESP32-DevKitC.

## Introduction
This is a work-in-progress, with rather loose milestones. For 2020 there were only two goals
- to redesign the original parts, so that they could be printed without any support
- to make a circuitry for all sensors and parts, that possibly would fit and be considere necessary

Both of these will be coming soon, as both goals have progress farther than 90% each. This repository is a representation of my hobby and as such, it will have its own pace. This being said, i am still happy about any questions, collaborations, suggestions, idead, forks and what else comes to your mind.

## Coming soon...
- STLs and FreeCAD-Files
- more Template FreeCAD-Files for your own modifications
- KiCAD or Fritzing circuit diagrams
- Photos
- other things i forgot

# SpotMicroESP32 - Parts
This section gices an overview of all necessary parts and their compatibility to the original KDY0523-Spotmicro.

## Partlist
The SpotMicroESP32 uses parts, that where redesign from the ground. These are largely incompatible to the original KDY0523-Spotmicro - meaning they are as an assembly not interchangable. This is due to some design decisions, that include the ability to print without support, using less different screw sizes and repositioning screwholes or altering dimensions to achive a more convenient and fluid design. The following list will not only provide informations about the total amount of prints needed (including the amount of mirrored copies), but if its compatible with the original KDY0523-Spotmicro and how many mirrored copies you would need of it.

### Chassis

[Inner Shoulder Thumbnail]:		https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Inner_Shoulder.png
[Outer Shoulder Thumbnail]:		https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Outer_Shoulder.png
[Chassis Side Thumbnail]:		https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Chassis_Side.png
[Top Shoulder Thumbnail]:		https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Top_Shoulder.png
[Bottom Shoulder Thumbnail]:	https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Bottom_Shoulder.png
[Circuitboard Mount Template]:	https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Circuitboard_Mount%20(Template).png

| Thumbnail                                                             | Name                        | KDY0523-Spotmicro Compatibility | normal copies | mirrored copies | total amount |
|-----------------------------------------------------------------------|-----------------------------|---------------------------------|---------------|-----------------|--------------|
| ![Inner Shoulder Thumbnail][Inner Shoulder Thumbnail]                 | Inner Shoulder              |                              no | 2 | - | 2 |
| ![Outer Shoulder Thumbnail][Outer Shoulder Thumbnail]                 | Outer Shoulder              |                              no | 2 | - | 2 |
| ![Chassis Side Thumbnail][Chassis Side Thumbnail]                     | Chassis Side                |                              no | 2 | - | 2 |
| ![Top Shoulder Thumbnail][Top Shoulder Thumbnail]                     | Top Shoulder                |                              no | 2 | - | 2 |
| ![Bottom Shoulder Thumbnail][Bottom Shoulder Thumbnail]               | Top Shoulder                |                              no | 2 | - | 2 |
| ![Circuitboard Mount Template Thumbnail][Circuitboard Mount Template] | Circuitboard Mount Template |                              no | - | - | - |

### Hull

[Front Cover Optimized Thumbnail]:		https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Front_Cover_Optimized.png
[Sensormount Thumbnail]:				https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Sensormount.png
[Cameramount Thumbnail]:				https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Cameramount.png
[Rear Cover Thumbnail]:					https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Rear_Cover.png
[Rear Cover Template Thumbnail]:		https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Rear_Cover%20(Template).png
[Top Cover Split Front Thumbnail]:		https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Top_Cover_Split_Front.png
[Top Cover Split Rear Thumbnail]:		https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Top_Cover_Split_Rear.png
[Top Cover Template Thumbnail]:			https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Top_Cover%20(Template).png
[Bottom Cover Split Front Thumbnail]:	https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Bottom_Cover_Split_Front.png
[Bottom Cover Split Rear Thumbnail]:	https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Bottom_Cover_Split_Rear.png
[Bottom Cover Template Thumbnail]:		https://github.com/michaelkubina/SpotMicroESP32/blob/master/parts/SpotMicroESP32_parts_v1_0_0/thumbs/Bottom_Cover%20(Template).png

| Thumbnail                                                                 | Name                        | KDY0523-Spotmicro Compatibility | normal copies | mirrored copies | total amount |
|---------------------------------------------------------------------------|-----------------------------|---------------------------------|---------------|-----------------|--------------|
| ![Front Cover Optimized Thumbnail][Front Cover Optimized Thumbnail]       | Front Cover Optimized       |                              no | 1 | - | 1 |
| ![Sensormount Thumbnail][Sensormount Thumbnail]                           | Sensormount                 |                              no | 1 | - | 1 |
| ![Cameramount Thumbnail][Cameramount Thumbnail]                           | Cameramount                 |                              no | 1 | - | 1 |
| ![Rear Cover Thumbnail][Rear Cover Thumbnail]                             | Rear Cover                  |                              no | 1 | - | 1 |
| ![Rear Cover Template Thumbnail][Rear Cover Template Thumbnail]           | Rear Cover Template         |                              no | - | - | - |
| ![Top Cover Split Front Thumbnail][Top Cover Split Front Thumbnail]       | Top Cover Split Front       |                              no | 1 | - | 1 |
| ![Top Cover Split Rear Thumbnail][Top Cover Split Rear Thumbnail]         | Top Cover Split Rear        |                              no | 1 | - | 1 |
| ![Top Cover Template Thumbnail][Top Cover Template Thumbnail]             | Top Cover Template          |                              no | - | - | - |
| ![Bottom Cover Split Front Thumbnail][Bottom Cover Split Front Thumbnail] | Bottom Cover Split Front    |                              no | 1 | - | 1 |
| ![Bottom Cover Split Rear Thumbnail][Bottom Cover Split Rear Thumbnail]   | Bottom Cover Split Rear     |                              no | 1 | - | 1 |
| ![Bottom Cover Template Thumbnail][Bottom Cover Template Thumbnail]       | Bottom Cover Template       |                              no | - | - | - |

