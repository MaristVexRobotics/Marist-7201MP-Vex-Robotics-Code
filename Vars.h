//drivetrain vars
int leftBackDrivePower;
int rightBackDrivePower;
int leftFrontDrivePower;
int rightFrontDrivePower;

//actuator vars
int scissorPower;
int frontClawPower;
int backClawPower;

//Remote Vars
int rcDriveForward;
int rcDriveStrafe;
int rcDriveTurn;

//Encoder Vars
int leftFrontEncoder;
int rightFrontEncoder;
int leftBackEncoder;
int rightBackEncoder;
int leftScissorEncoder;
int rightScissorEncoder;

//Other Sensor Vars
int gyroValue;
int lineReadMid;
int lineReadSide;

//==================
//constants
//==================
const float EFL = 1;
const float EFR = 1;
const float EBL = 1;
const float EBR = 1;
const int CORRECTION = 2;
const int AUTOTIMEINTERVAL = 5; // time between execution of autonomous reads (in 10 millisecond increments (3 = 30ms))
const int MAX_SCISSOR_HEIGHT = 700;
const int MIN_SCISSOR_HEIGHT = 20;
const int MAINTAIN_HEIGHT_SCISSOR_POWER = 10;

const int DEADZONE = 5; // give auto code room to make corrections by limiting the max movement speed.

const int MAX_WAIT_TIME = 500;

const int LINE_SENSOR_THRESHOLD = 505;




void resetVars() {
	leftBackDrivePower = 0;
	rightBackDrivePower = 0;
	leftFrontDrivePower = 0;
	rightFrontDrivePower = 0;
	scissorPower = 0;
	frontClawPower = 0;
	backClawPower = 0;
	rcDriveForward = 0;
	rcDriveStrafe = 0;
	rcDriveTurn = 0;
	leftFrontEncoder = 0;
	rightFrontEncoder = 0;
	leftBackEncoder = 0;
	rightBackEncoder = 0;
	leftScissorEncoder = 0;
	rightScissorEncoder = 0;
}
