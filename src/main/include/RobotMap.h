/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;

/*
   Game controller addressing.
   Access in code by including RobotMap.h and using DRIVER_CONTROLLER
   */

constexpr int DRIVER_CONTROLLER = 0;
constexpr int AUX_CONTROLLER = 1;

/* 
   Game controller button and joystick addressing.
   Access in code by including RobotMap.h and using BUTTON_A
   */
constexpr int BUTTON_A = 1;
constexpr int BUTTON_B = 2;
constexpr int BUTTON_X = 3;
constexpr int BUTTON_Y = 4;
constexpr int BUTTON_L_BUMP = 5;
constexpr int BUTTON_R_BUMP = 6;    // Drive gear sifting
constexpr int BUTTON_SELECT = 7;
constexpr int BUTTON_START = 8;
constexpr int BUTTON_L3 = 9;
constexpr int BUTTON_R3 = 10;

constexpr int AXIS_LX = 0;          // Steer left/right
constexpr int AXIS_LY = 1;
constexpr int AXIS_L_TRIG = 2;      // Forward driving
constexpr int AXIS_R_TRIG = 3;      // Reverse driving
constexpr int AXIS_RX = 4;
constexpr int AXIS_RY = 5;


/* 
   Motor Drive Talon and Victor addressing. 
   Access in code by including RobotMap.h and using MOTOR_LEFT_MASTER 
   */

constexpr int MOTOR_LEFT_MASTER = 1;
constexpr int MOTOR_RIGHT_MASTER = 2;
constexpr int MOTOR_LEFT_FOLLOWER = 3;
constexpr int MOTOR_RIGHT_FOLLOWER = 4;

// Continuous current limit for Talons in amps
constexpr int CONTINUOUS_CURRENT_LIMIT = 30;
// Peak current limit for the Talons in amps
constexpr int PEAK_CURRENT_LIMIT = 150;
// Peak current duration for Talons in ms 
constexpr int DURATION_CURRENT_LIMIT = 30;

// Ramp Times for level of elevator heights and high and low gear
constexpr int RAMP_TIME = 0.2;


// Maximum velocity in units/100ms
constexpr int VELOCITY_MAX = 3000;
constexpr int VELOCITY_SP_MAX_HG = 3000;
constexpr int VELOCITY_SP_MAX_LG = 1400;


// PID constants PID[0] Used for low speed right side
constexpr double RIGHT_KF_0 = 0.6576;   // 0.6576
constexpr double RIGHT_KP_0 = 0.73;     // 0.73
constexpr double RIGHT_KI_0 = 0.0;
constexpr double RIGHT_KD_0 = 0.0;

// PID constants PID[1] uesd for high speed left side
constexpr double RIGHT_KF_1 = 0.296;    // 0.296
constexpr double RIGHT_KP_1 = 0;
constexpr double RIGHT_KI_1 = 0;
constexpr double RIGHT_KD_1 = 0;

// PID constants PID[0] Used for low speed right side
constexpr double LEFT_KF_0 = 0.6941;    // 0.6941
constexpr double LEFT_KP_0 = 0.73;      // 0.73
constexpr double LEFT_KI_0 = 0.0;
constexpr double LEFT_KD_0 = 0;

// PID constants PID[1] uesd for high speed left side
constexpr double LEFT_KF_1 = 0.32;      // 0.32
constexpr double LEFT_KP_1 = 0;
constexpr double LEFT_KI_1 = 0;
constexpr double LEFT_KD_1 = 0;



// Bottom PCM CAN ID
constexpr int PCM_BOTTOM = 9;
constexpr int PCM_TOP = 8;

// Solenoids mapping
constexpr int SOLENOID_0 = 0;
constexpr int SOLENOID_1 = 1;
constexpr int ARM_GRABBER_FORWARD = 2;
constexpr int ARM_GRABBER_REVERSE = 3;
constexpr int BALL_INTAKE_SOLENOID = 4;
constexpr int SOLENOID_5 = 5;
constexpr int SOLENOID_6 = 6;
constexpr int SOLENOID_7 = 7;

// Port numbers for each pneumatic relay



// CAN Address for Aux motors

constexpr int BALL_INTAKE_LEFT = 11;
constexpr int BALL_INTAKE_RIGHT = 12;

// Elevator configuration
constexpr int ELEVATOR_DRIVE_CAN_ADDR = 5;




