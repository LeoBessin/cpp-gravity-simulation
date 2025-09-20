//
// Created by bessi on 20/09/2025.
//

#ifndef CPP_GRAVITY_SIMULATION_BALL_H
#define CPP_GRAVITY_SIMULATION_BALL_H


class Ball {
public:
    Ball(const float radius, const float mass, const float restitution, const float x, const float y,
         const float vx = 0, const float vy = 0)
        : radius(radius), mass(mass), restitution(restitution), x(x), y(y), vx(vx), vy(vy) {
    }

    void update(float dt);

    void applyForce(float fx, float fy, float dt);

    void render() const;;

    void getPosition(float &outX, float &outY) const {
        outX = x;
        outY = y;
    }

private:
    float radius;
    float mass;
    float restitution;
    float x;
    float y;
    float vx;
    float vy;
};


#endif //CPP_GRAVITY_SIMULATION_BALL_H
