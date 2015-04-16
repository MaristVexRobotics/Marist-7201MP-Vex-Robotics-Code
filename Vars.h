#define SONGNAME "katyperryOG.wav"

//drivetrain vars
int leftBackDrivePower;
int rightBackDrivePower;
int leftFrontDrivePower;
int rightFrontDrivePower;

//actuator vars
int armPower;
int beltPower;
int beltSensorVal;

//pneumatics vars
/*bool pneumaticsActivated;
bool pneumaticsWereActivated;*/

//Remote Vars
int rcDriveForward;
int rcDriveStrafe;
int rcDriveTurn;

bool dualThumbstick = false;

int pos;

//Encoder Vars
int leftFrontEncoder;
int rightFrontEncoder;
int leftBackEncoder;
int rightBackEncoder;
int leftArmDegrees;
int rightArmDegrees;
int armError;
long armDiffOld;

int result;
int leftArmPower;
int rightArmPower;

int integral;
int diffIntegral;


//Other Sensor Vars
float gyroValue;
int lineReadMid;


bool gyroOverride;//3.0.1
bool correctionOverride;

int beltMaintainValue;
int armMaintainHeight;


//==================
//constants
//==================
float EFL = 1;
float EFR = 1;
float EBL = 1;
float EBR = 1;
float EAL = 1;
float EAR = 1;
const int POTENTIOMETER_DIFF = -110;
const float CORRECTION = 0.2;
const int AUTO_TIME_INTERVAL = 5; // time between execution of autonomous reads (in 10 millisecond increments (3 = 30ms))
const int MAINTAIN_HEIGHT_ARM_POWER = 10;
const int MAINTAIN_HEIGHT_BELT_POWER = 10;

const int DEADZONE = 10; // give auto code room to make corrections by limiting the max movement speed.
const int STRAFE_DEADZONE = 30;

const int MAX_WAIT_TIME = 500;
//*
float Kp = 0.0;
float Ki = 0.0;
float Kd = 0.0;
// */
//1, .005, .05
/*
float Kp = 0.5;
float Ki = 0.005;
float Kd = 0.05;
// */

//*
const float KpA = 0.2;
const float KiA = 0.0;
const float KdA = 0.0;
// */

/*
const float KpA = 0.5;
const float KiA = 0.005;
const float KdA = 0.05;
// */

const int LINE_SENSOR_THRESHOLD = 505;


const int BELT_SPEED_FAST = 127;
const int BELT_SPEED_SLOW = 60;

const int SKYRISE_MAINTAIN_HEIGHT = 0;
const int CUBE_MAINTAIN_HEIGHT = 853;


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
  armError = 0;
  armDiffOld = 0;
  integral = 0;
  diffIntegral = 0;
  gyroValue = 0;
  lineReadMid = 0;
  beltMaintainValue = 0;
}
