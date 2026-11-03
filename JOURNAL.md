# 10/27/2026 Started working on project + read docs!! (Arya: 1hr)

Arya: Today, I made a new EasyESA project and found a good ESP32 module and placed it! I decided to use the ESP32-S3 as it supported native USB-OTG and also was very powerful with 16MB of flash and 8MB of PSRAM! I then decided to do some research for the drone so I know what we should put for the schematic. It did take a while, but I figured out which firmware we are going to use, and I also found a good reference schematic to use. We decided to do the ESP-Drone firmware as it was made by Espressif themselves and in the official docs with an official app for controlling the drone. We also planned to use a MPU-6050 module instead of the bare chip since the modules were way cheaper compared to the bare chip. We did not get too much done with the project today, but it should be easier after we finish researching and understanding the parts that the drone will need since this is my (and possibly Funmi's) first time making a drone!

Lapse: https://lapse.hackclub.com/timelapse/IyVeEQJVIN3q

<img width="865" height="778" alt="image" src="https://github.com/user-attachments/assets/bb6d7ad8-0dc5-4b5b-8005-741e20656d90" />

# 10/28/2026 Placed more parts on the schematic + completed motor circutry!! (Arya: 1hr)

Arya: Today, I put some more parts on the schematic! I did do a lot of research for what parts to put, and I did use some other part since I had some trouble with finding the parts from the reference schematic. But the parts have the same function the same way, so I just used the alternatives that I found. This primarily applied to the MOSFETs for the motors. I also did get stuck on how the wiring on the MOSFETs on the reference schematic worked, so I asked a friend in a Slack Huddle and he helped me understand. I used some AI to help me understand deeper and confirm on that since he was not sure of his response. I did have some trouble with finding the 1N4148W diodes for the motor circuitry since there were a LOT of different diodes called the same things with the exact same features on most of them, but some of them had different ratings. I think I am done with the motor circuitry component placement as of now!

Lapse: https://lapse.hackclub.com/timelapse/JW5rUNNi4N1H

<img width="1105" height="646" alt="image" src="https://github.com/user-attachments/assets/8972fc64-26ed-492d-90bc-b4019ac4706d" />

Arya: Today, we completed placing the main components on the schematic and started some wiring as well! I started with finishing up the components by adding a thing for power regulation, and we decided to use a buck-boost converter instead of a LDO like the reference schematic used since we were using a battery and that the 3V3 components should not be under or overvolted as that may damage them. It was a bit tricky finding a good buck- boost module, but I managed to find a decent one from TI that had the proper voltage output and supported enough amps being drawn. I also added some capacitors and header pin footprints to the schematic for the motor wiring/circutry. I then also added a slide switch for the power so that we had a nice way for turning it on and off. I also did the wiring for the power switch as well!

Lapse: https://lapse.hackclub.com/timelapse/hAp201WeoFbX

<img width="2362" height="1672" alt="SCH_Schematic1_1-P1_2026-10-29" src="https://github.com/user-attachments/assets/496dc88f-00ce-4525-9620-c40792675df0" />

# 10/30/2026 Finished the schematic!! (Arya: 1hr 25mins)

Arya: Today, we locked in and finished the schematic for the PCB! I worked on the motors, and I used the reference schematic to help me wire the parts together, and then I made some nets and connected them to each motor setup. I finished all of the wiring for the motor. We then worked on wiring other things, like the TP4056 charging IC for the battery and the MPU-6050 gyro module. I used the pinout of a module that I had with me to help me wire the module! It only needed 4 pins for the main things, the other 4 pins available on the module were left unconnected. We then connected everything else to the ESP32, and we are now done with the schematic for the drone! When we work on this next time, we may start with the PCB for the drone or another schmeatic!

Lapse: https://lapse.hackclub.com/timelapse/q_PGseIQKXhP

<img width="2362" height="1672" alt="SCH_Schematic1_1-P1_2026-10-30" src="https://github.com/user-attachments/assets/1e1035b6-6d31-41bb-9049-b74c87d0a123" />

# 10/31/2026 Started and Finished PCB!! (Arya: 3hrs)

Arya: Today, we started and finished the PCB for the drone! We first started off with making some fixes to the schematic as we missed some things from last time, but we finally then moved on to the PCB. We started off with the layout of the PCB, and then we also decided the shape of the PCB as well, Funmi initially found a DXF and used that for the shape, but the center area turned out to be too small to comfortably fit the components and the thick power wires as they will carry a lot of current for the motors. Funmi then found a better DXF file that had a significantly larger center, so we decided to do that, and the components comfortably fit in to place with plenty of space for comfortable wiring. After we placed the components, we started with the wiring, by using the default trace width. But then, we decided that running 4 motors at once will draw plenty of power, so I converted the thin traces into larger and thicker traces so that they do not burn out. We then ran DRC and finished any wiring that was unconnected before doing the ground fill, which will connect all of the GND pins, and this is the main reason on why we did not wire any of the GND pins. We then connected the areas there the ground fill would not reach and then we changed the outline of the PCB so that the ESP32's antenna does not have any PCB under it as that is very bad for it and can strongly interfere. We are now done with the schematic and PCB for the actual drone, and now we decided to make a optional schematic and PCB for the remote so that there is another way to control it!

Lapse: https://lapse.hackclub.com/timelapse/CQgJdJIBf0Yd

<img width="2160" height="2396" alt="PCB_PCB1_2026-10-31" src="https://github.com/user-attachments/assets/c0dadca5-f7a9-4e8a-acbd-c8d373054403" />
<img width="2160" height="1652" alt="3D_PCB1_2026-10-31" src="https://github.com/user-attachments/assets/0ea488dc-efc7-49b8-a071-0ed8c487772c" />

# 11/1/2026 Started and almost finished remote!! (Arya: 2hrs 40mins)

Arya: Today, we started with the remote that will go along with the drone! We managed to almost finish it! We decided to use ESP-NOW as the wireless communication protocol between the drone and the remote, and we used the same ESP32 chip as the drone for the remote as well! The remote will have two joysticks and will also be powered by a battery! We also imported some ICs like the battery charger and the buck-boost from the schematic of the main drone along with the power switch and the reverse protection diodes, and managed to finish the schematic! We then started with the PCB and used a DXF for the outline that was shaped like a game controller. We then layed out the things and started wiring! We did not finish all of the wiring, but we almost are done with it!

Lapse: https://lapse.hackclub.com/timelapse/f50ZKv_25U5I

<img width="2362" height="1672" alt="SCH_remote_1-P1_2026-11-01" src="https://github.com/user-attachments/assets/8907591b-a499-45c2-97fe-9f6b89378617" />
<img width="2160" height="1277" alt="PCB_PCB2_2026-11-01" src="https://github.com/user-attachments/assets/4253adb9-6abd-4d83-b4ad-fc6808dad766" />

# 11/2/2026 Finished remote PCB + added motor holes to drone PCB and branded both PCBs + started CAD!! (Arya: 4hrs)

Arya: Today, I managed to finish up the PCB for the remote for the drone and also managed to add holes for the motors on the drone! I even branded both of the PCBs! I also managed to start the enclosure for the remote as well and make good progress! Starting off with the PCBs, I did DRC and confirmed all of the wiring except the GND, and then I did a ground fill on the PCB. I then connected the things that did not get connected via the ground fill together and I also added random vias between the two ground fill layers as it is good for the PCB. I then went on AliExpress to look for some motors that will work with our drone, and I found a good set that had 2 CW and 2 CCW motors and that was exactly what I needed! I added holes to the drone PCB for the motors and then moved on to the CAD for the remote! I did have a lot of trouble with getting the DXF of the outline of the remote PCB compatible so that I could use the offset tool in Onshape that makes the outline bigger on all sides evenly. After trying a lot of things, my only solution was to remove the antenna outline as that was the cause of the problem. But after that, the offset tool worked fine! I then manually added an antenna outline back by using the measuring tool in EasyEDA to get the proper dimensions of the antenna. I decided to make it a bit bigger than the dimensions so that the things would fit. I then extruded everything and added a hole for the charging port of the remote. It was a bit trick as Onshape would not let me make a sketch on the side of the case for some reason, so I had to make a hole from the top of the case, extrude it downwards, and then make another sketch that fills the area above the port back up. This was very tricky today. I then started with making the top part of the case by using the same sketch for the sketch on the top so that the dimensions would be perfect. I then added a circular hole to the top part for the joystick and aligned it properly. I still have to do the holes for the other joystick and other buttons! To help me get the proper placement of the holes and parts on the CAD, I made an assembly which I went back and forth with to help me align things properly!

Lapse: https://lapse.hackclub.com/timelapse/nyggARL979qf

<img width="1533" height="822" alt="image" src="https://github.com/user-attachments/assets/74f5bd2a-bc7b-41b1-b99e-6149c677a15a" />
<img width="1455" height="809" alt="image" src="https://github.com/user-attachments/assets/1c57f953-3a43-487d-8704-9e32ee2613c5" />
<img width="1090" height="691" alt="image" src="https://github.com/user-attachments/assets/29c91f56-522c-424c-a8e4-34791571a8ae" />
<img width="1203" height="778" alt="image" src="https://github.com/user-attachments/assets/a51c0eba-a3b1-4549-b76d-0cab3f58fa8a" />
