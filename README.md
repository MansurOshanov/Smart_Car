 
1. Introduction
Current project is aimed at the creation of a smart motorhome, which is a subtype of recreational vehicles. Recreational vehicles (RVs) are popular in North America for camping purposes, because these afford a convenient living space (Brooker & Joppe 2013, 1-2). However, there might be a potential for the popularization of RVs in Kazakhstan with the development of cross-country tourism. 
Motorhomes usually have two main compartments, living space and driver’s cabin, illustrated in Figure 1. Assembly of a smart motorhome requires two implementations: moving car functionality and a set of sensors for a living space. This project is aimed at the improvement of living conditions for campers in motorhomes. In the perspective, the development of smart motorhomes will contribute to the development of the RV industry. 
 
 
Figure 1 Recreational Van
2. Materials and Methods 
Exterior design was inspired by the Scooby-Doo Mystery Machine demonstrated in Figure 2.
  
A.	Materials used for the exterior design:
•	Cardboards
•	Tape
•	Water paint
•	Metal plates for the floor
•	Screws for the metal plates
B.	Materials used for the car component functionality:
•	2 x Arduino Uno
•	Wi-Fi Receiver
•	3 wheels
•	3 VEX motor engines
2 regimes: manual mode and autopilot
•	Gas and brakes made with force sensing resistors
•	VEX Ultrasonic range finder for autopilot
C.	Additional functionality:
•	Headlights made with LEDs
•	Horn made with speaker
D.	Housing functionality components
•	Passive infrared sensor for motion detection
•	Photoresistor for detection of outside light
•	LED for light bulbs
•	9V Battery power supply
•	Arduino Uno
E.	Extra materials:
•	Wires
•	Jumper wires
•	Resistors
•	Screws
Since our project did not involve usage of any logic gates, flip-flops and multiplexers, the architecture of the motorhome was straightforward and required input and output pins, VCC and ground connections, as well as resistors for the LEDs. We used only three wheels because one of the front wheel had many tine wheels which enabled it to move forward, pushed by the back wheels, and to the sides, activated by engines.
We use pressure sensors connected to the Arduino at the local machine to control the forward and backward movement of the car. The strength of the pressure is translated into speed; therefore, the car can move slower or faster. There is also a function for autopilot, which allows the car to avoid obstacles with the VEX Ultrasonic range finder, which forces the car to turn when an obstacle is less than 7 cm away. The local machine communicates with the car with the receiver and there are several remotely controlled car functions:
•	Turning headlights on and off
•	Turning on the speaker (horn)
•	Switching between the manual mode and autopilot
Inside the living compartment with infrared sensor, the lights turn on if a person comes in and it is dark outside. In the daylight, the light will not turn on.

3. Results
The code developed for the aligned functioning of all the car functions were added to the archive of the final report with the following names: projectRobotics.ino, sender.ino and Automatic_lightning_system.ino . Due to their lengthiness, they are not included in the document. But as as far as the testing has demonstrated, all the functions work properly. 
The assembly of the components was also successful. One Arduino in the car was powered by powerBank and another with 9V battery. Illustration of the assembled control panel, connected to the computer are illustrated in the Figure 3. You can observer several buttons for the headlight, speaker and mode control. Receiver is also visible.

The Figures 4 and 5 illustrate front and top view of the car. The front view in Figure 4 demonstrates the location of the proximity sensor, which controls the autopilot mode. While the back view in Figure 5 demonstrates the components for the driver’s panel and the living compartment. 
     
             Figure 4 Front view                                      Figure 5 Top view
 An exterior design is demonstrated in the Figure 6. It is a replica of the car pictured in famour Scooby-Doo cartoon. There is also a Youtube video available in the link: https://www.youtube.com/watch?v=DQlRiYU7Rlo&feature=youtu.be 
 
Figure 6 Exterior design
4. Discussion and Conclusions 
The drawback of the inner view of an assembled car is that there was not sufficient time to work on the inner design aesthetics; therefore, it appears to be tangled. It also caused several issues with wires probably short-circuiting as sometimes during the testing not all the functionality was working properly. However, after fixing the wires, problems would solve. We also initially had issues with Arduinos working on the metallic sheets, because they were not padded with additional layer of cardboard to prevent short circuiting. Otherwise, the planned functionality was implemented as required.
Mansur Oshanov made a significant contribution to the assembly of the car and he also helped assembling the remote control. Temirlan Turysbek was responsible for the well functioning code in the files: projectRobotics.ino and sender.ino . Alpamys Duimagambetov assembled the control system for the living compartment and wrote the code Automatic_lightning_system.ino . Akhan Janabekov was fully responsible for the exterior design. Yevgeniya Migranova has written the proposal, report and made the final presentation. Furthermore, all the members were assisting to some extent with the assembly of all the pieces including metal carcass.
References
1.	Brooker E, Joppe M. Trends in camping and outdoor hospitality—An international review. Journal of Outdoor Recreation and Tourism. 2013 Dec 1;3:1-6. https://doi.org/10.1016/j.jort.2013.04.005 

