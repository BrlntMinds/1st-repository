# 1st-repository

 

Overall description of our robotic solution

 

First things first. The main component we need is the brain, which is fed with all the code we built. We utilized the programming language C++. The brain, a mcore main control board, is the one that sends, receives and analyzes information. With the help of the code, it will compare and analyze the data provided and obtained from the track.

Our robot does 3 important steps: collects information, processes it, and acts upon it.

First, Information gathering: Through the sensors we use, the Ultrasonic sensor and the Camera, we collect information about the robot´s surrounding at any given time. If the robot is close or far from an object or the barriers, it will make use of its sensors to determine its position and act accordingly. While the ultrasonic sensors confirm where more space is and where to turn, the camera easily detects the distance and color to identify and dodge obstacles.

After many tryouts we discovered that, in some cases, the ultrasonic sensors are not able to detect the distance correctly, whereas the camera, apart from detecting the distance, can also detect the colors of obstacles present in the second challenge of the race, but it is a bit problematic when it comes to coding since it is not compatible with the first language of coding that we were using at the beginning, so we had to make an extra effort and combine C++ along with Makeblock´s blocks-base coding language.

Second, Information processing: The element of hardware which processes the information in our robot is the brain. In the code, we inserted multiple instructions which adapt to both challenges of the race. The brain receives the first part of the information, then it goes through the procedure written in the code and finally sends the information into the energy system, thus sending energy to the servo which then turns in the direction that the brain instructs it to turn.

Lastly, Acting by the code autonomously: After sending the information through the energy system to turn on the propulsion motors and the servo motor, also known as the direction motor, the robot starts to run and avoid obstacles.

The propulsion motor is the one that makes it possible for our robot to move forward and backward while the servo, or direction motor, is the one that makes it possible for our robot to turn left and right with the desired angle stated in the coding based on the scenario interpreted by the information previously gathered.

 

Now, it is the time to narrate the most difficult part of this process, coding.

Code: The hardest part of our robot is the coding, the first challenge, the easiest one, is that the robot needs to turn and follow the course without crashing against either the internal or external walls. To complete this challenge we needed to use 2 ultrasonic sensors on the sides of the robot to detect if there is or not an obstacle on its sides. If there was an obstacle, then it would try to dodge it; on the other hand, when it doesn’t detect an obstacle,  it will steer into the area where there aren’t any obstacles.

In addition to this difficulty, keeping the bot in the same lane where it was initially placed just added an extra spice to the contest. In order to be up to the challenge, we created the variable “Lane”. This variable maintains the robot in the same lane where it was originally placed when starting the track. This variable works by, at the beginning of the track, measuring the distance between the internal and external wall, then that distance is stored into the variable "Lane", and the robot stays in that range, getting this value: if it’s in the internal lane, the variable is 1; in the middle, it’s 2, and in the external lane, it’s 3. Once either of these 3 functions are chosen for each lane, the robot chooses one of the 3 variables and follows the path that the coding dictates, for example, in the first case, if the robot detects that the range is 5 centimeters on one sensor and 27 centimeters in the other sensor, it will try to stay on that distance, but if suddenly the 5 centimeters sensor detects that the robot is less than 5 centimeters away from one of the walls, it will turn the robot to the right or left depending on the initial direction, and if it detects less than 27 centimeters from the walls, it will also turn the robot right or left depending on the initial direction as well. The very same happens with the other 2 variables, each one having a different set distance.
	6.	For the second challenge, which has a greater difficulty, the robot has not only to evade the walls like in the first challenge, but also it has to turn in a direction indicated in the code depending on the color of the obstacle, which in this case will be either red or green. For this task, it will not use the ultrasonic sensors, as they can’t detect color, so the robot will use the camera which is able to detect the color of the obstacle and steer in the desired path according to the coding. The camera has a special function to let us visualize what the camera is watching live. This function lets us choose what objects to identify. Once picked out, these are saved into the camera’s memory including their size and color, which we can select and code for further instructions. When the camera detects an obstacle, a white-translucent square appears over the object to show that it is detecting something, this appears in the live feed during testing. With all this information, it is just a matter of analyzing the situation and creating a program that can act upon the task to be completed, although its clearly easier said than done. We decided to save the colors red and green since they are the ones needed in the second challenge.

We only use the variable "Lane" in the first challenge, while in the second challenge we set as default the second lane. 

Once started, the robot doesn’t stop, in fact it will keep going at all times until a certain time is reached, this time was carefully taken through testing, to make sure that the robot stays as close, if not in the same area where it originally started, while there could have been more methods to return the robot to its original starting place, due to limited materials, we did the best without code, software and hardware.
It was noted that the robot would consume a full pack of 4 AA Batteries quickly, which are connected in series to the brain which distributes the energy into the camera, ultra sonic sensors and servo and propulsion motor.

 

With these, the robot successfully stays in the desired path and successfully completes the course with maximum efficiency, easily avoiding all the obstacles and walls, and finally keeping itself in the best time and path cited for each challenge’s course, even if one of the sensors fails, which may happen, won’t affect the robot’s final performance in the end of it all.
