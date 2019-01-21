/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

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
constexpr int BUTTON_A = 0;
constexpr int BUTTON_B = 1;
constexpr int BUTTON_X = 2;
constexpr int BUTTON_Y = 3;
constexpr int BUTTON_L_BUMP = 4;
constexpr int BUTTON_R_BUMP = 5;
constexpr int BUTTON_SELECT = 6;
constexpr int BUTTON_START = 7;
constexpr int BUTTON_L3 = 8;
constexpr int BUTTON_R3 = 9;

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

// Maximum velocity in units/100ms
constexpr int VELOCITY_MAX = 3000;

// Bottom PCM CAN ID
constexpr int PCM_BOTTOM = 9;
constexpr int PCM_TOP = 8;

// Solenoids mapping
constexpr int SOLENOID_0 = 0;
constexpr int SOLENOID_1 = 1;
constexpr int SOLENOID_2 = 2;
constexpr int SOLENOID_3 = 3;
constexpr int SOLENOID_4 = 4;
constexpr int SOLENOID_5 = 5;
constexpr int SOLENOID_6 = 6;
constexpr int SOLENOID_7 = 7;