7201M/P-Vex-Team
==============

This is the code repository for the Marist Vex teams 7201M/P

Code By Konrad Kraemer

###Changelog:
-------------

####Current Version: 3.1.1



3.1.1 Fix - the old maintain belt height and arm height code did nothing. small mistake. This is a rewrite of that code, which fixes it. JANUARY 15, 2015

3.1 Feature - music. nuff said. JANUARY 14, 2015

3.0.3.1 Tweak - changed the correction value to .2. this makes it less sensitive, and reduces the chance of overcorrecting JANUARY 14, 2015

3.0.3 Feature - added code to maintain belt height and improved the code which maintains arm height. This is because three cubes are too much for the belt alone to handle JANUARY 14, 2015

3.0.2 Feature - Added the ability for the belt to move both quickly and slowly. JANUARY 14, 2015

3.0.1.1 Fix - Fixed the competition template

3.0.1 Feature - Added a gyroscope override. This is because the drive function previously locked up if the robot was at all moved while the gyroscope was being calibrated, this change allows the user to bypass the gyrosope in the case of an "emergency". JANUARY 13, 2015

3.0 Rewrite - codebase completely rewritten to acommodate the mechanum wheels, control the scissor lift, and redo the autonomous to run from a library, instead of the recording done in previous years. Also, remote control code was modified to allow the controls to always be in-relation to driver, regardless of the rotation of the robot. DECEMBER 23, 2014

3.0-beta.2 - Feature- relative omnidirectional drive code completed and fully functional. SEPTEMBER 18, 2014

3.0-beta.1 - Rewrite. Functioning omnidirectional drive code. SEPTEMBER 17, 2014

2.0.8.1 Tweak - correction value changed to .5 to make the autonomous even less jumpy

2.0.8 Modification - removed the lurching and anti-tippingcode because our drivers thought it limited our mobility

2.0.7 Feature Replacement - we decided that we need full power, so we are dropping the 2.0.5 changes, and instead tweaking the accel

2.0.6	Feature- software speed limiting to prevent the robot from lurching forward if arm is fully up. This previously caused the robot to flip.

2.0.5	Feature- software arm limiting to prevent the arm from exceding a certain height and flipping the robot. Also, this code turns off the automatic arm	power which would keep it level.

2.0.4.1 Tweak - ticks to give up changed to 500	ticks. Now it doesn't take soo long to move on. Also, correction value changed to 1 to make it less jumpy. JANUARY 8, 2014

2.0.4	BugFix - told robot to give up after 1000 ticks. Robot used to try to complete a command indefinitely, if it hit a wall, it would just sit there and do nuthin, so now it gives up. JANUARY 7, 2014

2.0.3.2	Tweak - deadzone changed to 27. Maximum speed	becomes 100 JANUARY 6, 2014

2.0.3.1	Bugfix - correction code wasn't working. motor values went to -3000s. Problem was that I accidentaly read the left encoder instead of the right encoder JANUARY 6, 2014

2.0.3	Bugfix - some motors were having problems catching up with the others, added code to set the max speed for motors during recording to 127 MINUS the value of variable deadzone (max 122). JANUARY 6, 2014

2.0.2	Bugfix - same problem as 2.0.1, I solved it by having the code wait until any encoder reaches its predefined target for that cycle. JANUARY 5, 2014

2.0.1	Bugfix - since the recording code takes more time to execute than the autonomous, the autonomous code ends up running a tad too quickly. I started fixing this by forcing certain parts of the code to execute at a certain time, however I abandoned this approach and went with another (2.0.2) JANUARY 4, 2014

2.0	Complete rewrite - modular code to aid testing in VirtualWorlds and make the code more legible. Autonoumous recording now supports full control with thumbsticks. - December 28, 2013

1.2	Rewrote Autonomous - Codes itself uses D-pad controls - Fall 2013

1.1	Autonomous attempt - unsuccessful - early 2013

1.0	First Official Remote Control Code - Late 2012


###TODO:
Implement Virtual Worlds Testing
