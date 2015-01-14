//drivetrain vars
int leftBackDrivePower;
int rightBackDrivePower;
int leftFrontDrivePower;
int rightFrontDrivePower;

//actuator vars
int armPower;
int beltPower;
int beltSensorVal;


//Remote Vars
int rcDriveForward;
int rcDriveStrafe;
int rcDriveTurn;

//Encoder Vars
int leftFrontEncoder;
int rightFrontEncoder;
int leftBackEncoder;
int rightBackEncoder;
int leftArmDegrees;
int rightArmDegrees;

//Other Sensor Vars
float gyroValue;
int lineReadMid;
int lineReadSide;


bool gyroOverride = false;//3.0.1

//==================
//constants
//==================
const float EFL = 1;
const float EFR = 1;
const float EBL = 1;
const float EBR = 1;
const int POTENTIOMETER_DIFF = 284;
const float CORRECTION = .5;
const int AUTO_TIME_INTERVAL = 5; // time between execution of autonomous reads (in 10 millisecond increments (3 = 30ms))
const int MAINTAIN_HEIGHT_ARM_POWER = 10;

const int DEADZONE = 10; // give auto code room to make corrections by limiting the max movement speed.

const int MAX_WAIT_TIME = 500;

const int LINE_SENSOR_THRESHOLD = 505;

const int BELT_POS1 = 100;
const int BELT_POS2 = 200;
const int BELT_POS3 = 300;
const int BELT_POS4 = 400;
const int BELT_POS5 = 500;

const int BELT_SPEED_FAST = 127;
const int BELT_SPEED_SLOW = 50;


void resetVars() {
  leftBackDrivePower = 0;
  rightBackDrivePower = 0;
  leftFrontDrivePower = 0;
  rightFrontDrivePower = 0;
  armPower = 0;
  beltPower = 0;
  rcDriveForward = 0;
  rcDriveStrafe = 0;
  rcDriveTurn = 0;
  leftFrontEncoder = 0;
  rightFrontEncoder = 0;
  leftBackEncoder = 0;
  rightBackEncoder = 0;
  leftArmDegrees = 0;
  rightArmDegrees = 0;
  beltSensorVal = 0;
}
