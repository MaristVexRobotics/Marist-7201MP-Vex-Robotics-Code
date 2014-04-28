int leftDrive;
int rightDrive;
int leftDriveOld; //2.0.7
int rightDriveOld; //2.0.7
int armVar;
int beltVar;
int leftEncoderVar;
int rightEncoderVar;
int leftArmEncoderVar;
int rightArmEncoderVar;
int mL = 0;
int mR = 0;

//==================
//constants
//==================
float EL = 1; // not used currently
float ER = .7; // these two values were used to correct the difference between the two motors,
int CORRECTION = 2;
int AUTOTIMEINTERVAL = 5; // time between execution of autonomous reads (in 10 millisecond increments (3 = 30ms))
int MAX_ARM_HEIGHT = 700; //2.0.5
int MIN_ARM_HEIGHT = 20; //2.0.5
int ACCEL_LIMIT = 10; //2.0.7
int ARM_UP_HEIGHT = 500; //2.0.7

//addition of 2.0.3
//-------------------------
int DEADZONE = 5; // give auto code room to make corrections by limiting the max movement speed.
//-------------------------

int MAX_WAIT_TIME = 500;
