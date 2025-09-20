//
// Created by bessi on 20/09/2025.
//

#include "draw.h"
#include "../core/constants.h"
#include <GL/gl.h>
#include <cmath>

void drawCircle(const float cx, const float cy, const float r, const int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // centre du cercle
    for (int i = 0; i <= num_segments; i++) {
        const float theta = 2.0f * PI * static_cast<float>(i) / static_cast<float>(num_segments);
        const float x = r * cosf(theta);
        const float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}
