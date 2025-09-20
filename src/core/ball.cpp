// ball.cpp

#include "ball.h"
#include "constants.h"
#include "../graphics/draw.h"

void Ball::applyForce(float fx, float fy, float dt) {
    const float ax = fx / mass;
    const float ay = fy / mass;
    vx += ax * dt;
    vy += ay * dt;
}

void Ball::render() const {
    drawCircle(x, y, radius);
}

void Ball::update(float dt) {
    // Force de gravité
    const float fy = mass * EARTH_GRAVITY;
    const float ay = fy / mass; // = EARTH_GRAVITY

    vy += ay * dt;
    x += vx * dt;
    y += vy * dt;

    if (x - radius < -WINDOW_ASPECT) {
        x = -WINDOW_ASPECT + radius;
        vx = -vx * restitution;
    } else if (x + radius > WINDOW_ASPECT) {
        x = WINDOW_ASPECT - radius;
        vx = -vx * restitution;
    }

    if (y - radius < -1.0f) {
        y = -1.0f + radius;
        vy = -vy * restitution;
    } else if (y + radius > 1.0f) {
        y = 1.0f - radius;
        vy = -vy * restitution;
    }
}

