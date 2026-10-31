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
