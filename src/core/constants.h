//
// Created by bessi on 20/09/2025.
//

#ifndef CPP_GRAVITY_SIMULATION_CONSTANTS_H
#define CPP_GRAVITY_SIMULATION_CONSTANTS_H

#pragma once

// Window dimensions
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr float WINDOW_ASPECT = static_cast<float>(WINDOW_WIDTH) / WINDOW_HEIGHT;

// Mathematics & Physics constants
constexpr float EARTH_GRAVITY = -9.81f;
constexpr float PI = 3.14159265358979323846f;

// Project settings
constexpr float CLICK_FORCE = 50.0f;
constexpr float BALL_RADIUS = 0.05f;
constexpr float BALL_MASS = 1.0f;
constexpr float BALL_RESTITUTION = 0.8f;


#endif //CPP_GRAVITY_SIMULATION_CONSTANTS_H
