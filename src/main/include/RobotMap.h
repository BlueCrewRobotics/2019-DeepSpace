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
constexpr int BUTTON_R_BUMP = 6; // Drive gear sifting
constexpr int BUTTON_SELECT = 7;
constexpr int BUTTON_START = 8;
constexpr int BUTTON_L3 = 9;
constexpr int BUTTON_R3 = 10;

constexpr int AXIS_LX = 0; // Steer left/right
constexpr int AXIS_LY = 1;
constexpr int AXIS_L_TRIG = 2; // Forward driving
constexpr int AXIS_R_TRIG = 3; // Reverse driving
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

// Ramp Times for drive starting and stopping
constexpr double DRIVE_RAMP_TIME = 0.2;

// Maximum velocity in units/100ms
constexpr int VELOCITY_MAX = 3000;
constexpr int VELOCITY_SP_MAX_HG = 3000;  // Maximum velocity in actual high gear
constexpr int VELOCITY_SP_MAX_LG = 1400;  // Maximum velocity in actual low gear
constexpr int VELOCITY_SP_MAX_LL = 700;   // Maximum velocity in low low virtual gear


// PID constants PID[0] Used for low speed right side
constexpr double RIGHT_KF_0 = 0.64; // 0.6576
constexpr double RIGHT_KP_0 = 0.4;  // 0.73
constexpr double RIGHT_KI_0 = 0.0;
constexpr double RIGHT_KD_0 = 0.0;

// PID constants PID[1] uesd for high speed left side
constexpr double RIGHT_KF_1 = 0.3; // 0.296
constexpr double RIGHT_KP_1 = 0;
constexpr double RIGHT_KI_1 = 0;
constexpr double RIGHT_KD_1 = 0;

// PID constants PID[0] Used for low speed right side
constexpr double LEFT_KF_0 = 0.6; // 0.6941
constexpr double LEFT_KP_0 = 0.4; // 0.73
constexpr double LEFT_KI_0 = 0.0;
constexpr double LEFT_KD_0 = 0;

// PID constants PID[1] uesd for high speed left side
constexpr double LEFT_KF_1 = 0.3; // 0.32
constexpr double LEFT_KP_1 = 0;
constexpr double LEFT_KI_1 = 0;
constexpr double LEFT_KD_1 = 0;

// Bottom PCM CAN ID
constexpr int PCM_BOTTOM = 9;
constexpr int PCM_TOP = 8;

// Solenoid Mappings for bottom PCM
constexpr int BTM_GEARSHIFT = 0;  // Drive train gear shifter
constexpr int BTM_SOLENOID_1 = 1; // Spare
constexpr int BTM_SOLENOID_2 = 2; // Spare
constexpr int BTM_SOLENOID_3 = 3; // Spare
constexpr int BTM_SOLENOID_4 = 4; // Spare
constexpr int BTM_SOLENOID_5 = 5; // Spare
constexpr int BTM_SOLENOID_6 = 6; // Spare
constexpr int BTM_SOLENOID_7 = 7; // Spare

// Solenoid Mapping for top PCM
constexpr int TOP_HATCH_EXT_4 = 0;    // TOP PCM 0 - Hatch 4" extend forward
constexpr int TOP_HATCH_EXT_7 = 1;    // TOP PCM 1 - Hatch 7" extend forward
constexpr int TOP_CARGO_EXT_5 = 2;    // TOP PCM 2 - Cargo 5" extend forward
constexpr int TOP_CARGO_EXT_7 = 3;    // TOP PCM 3 - Cargo 7" extend forward
constexpr int TOP_CARGO_TILT = 4;     // TOP PCM 4 - Cargo tilt up
constexpr int TOP_CLAMP_SOLENOID = 5; // TOP PCM 5 - Cargo grab open
constexpr int TOP_HATCH_GRABBER = 6;  // TOP PCM 6 - Hatch release
constexpr int TOP_SPARE_7 = 7;        // TOP PCM 7 - Spare

constexpr int HATCH_HALL_EFFECT = 0;

// CAN Address for Aux motors

constexpr int CARGO_LEFT_CAN_ADDR = 11;
constexpr int CARGO_RIGHT_CAN_ADDR = 12;

constexpr double CARGO_INTAKE_LEFT = 0.5;
constexpr double CARGO_INTAKE_RIGHT = -0.5;
constexpr double CARGO_SHOOT_LEFT = -0.5;
constexpr double CARGO_SHOOT_RIGHT = 0.5;

// Elevator configuration
constexpr int ELEVATOR_DRIVE_CAN_ADDR = 5;
// Elevator constants PID[0] used for postioning
constexpr double ELEVATOR_KF_0 = 0;
constexpr double ELEVATOR_KP_0 = 0.485; // (0.50 X 1023) / 1024
constexpr double ELEVATOR_KI_0 = 0;
constexpr double ELEVATOR_KD_0 = 0;

// Elevator closed loop ramp
constexpr double ELEVATOR_RAMP = 0.25;

// Elevator position declaration
constexpr int ELEVATOR_RESET_HOME_POS =
    0; // Used to set the elevator home position
constexpr int ELEVATOR_CRUISE_VELOCITY =
    2000; // Velocity for motion control units / 100ms
constexpr int ELEVATOR_ACCELERATION = 2000; // Acceleration in unit s/ 1 second

constexpr bool ELEVATOR_SOFT_LIMITS_ENABLE =
    true;                                      // Disable/Enable of soft limits
constexpr int ELEVATOR_TOP_SOFT_LIMIT = 26000; // Set the soft top limit
constexpr int ELEVATOR_BOT_SOFT_LIMIT = 200;   // Set the soft bottom limit

constexpr int ELEVATOR_BALL_LEVELS = 5;
constexpr int ELEVATOR_HATCH_LEVELS = 3;

constexpr int ELEV_BALL_GRAB = 0;
constexpr int ELEV_BALL_GRAB_POS = 0;
constexpr int ELEV_BALL_ROCKET_BTM = 1;
constexpr int ELEV_BALL_ROCKET_BTM_POS = 7900;
constexpr int ELEV_BALL_CONTAINER = 2;
constexpr int ELEV_BALL_CONTAINER_POS = 12200;
constexpr int ELEV_BALL_ROCKET_MID = 3;
constexpr int ELEV_BALL_ROCKET_MID_POS = 18500;
constexpr int ELEV_BALL_ROCKET_TOP = 4;
constexpr int ELEV_BALL_ROCKET_TOP_POS = 25500;

constexpr int ELEV_HATCH_ROCKET_BTM = 0;
constexpr int ELEV_HATCH_ROCKET_BTM_POS = 200;
constexpr int ELEV_HATCH_ROCKET_MID = 1;
constexpr int ELEV_HATCH_ROCKET_MID_POS = 10500;
constexpr int ELEV_HATCH_ROCKET_TOP = 2;
constexpr int ELEV_HATCH_ROCKET_TOP_POS = 21500;

constexpr double ELEV_DRIVE_RAMP_BTM = 0.2;
constexpr double ELEV_DRIVE_RAMP_MID = 1.0;
constexpr double ELEV_DRIVE_RAMP_TOP = 1.5;

// Digital input switches
constexpr int DIGITAL_INPUT_0 = 0;