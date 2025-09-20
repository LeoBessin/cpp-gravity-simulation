// Dans src/main.cpp

#include "graphics/window.h"
#include "core/ball.h"
#include "core/constants.h"
#include <iostream>
#include <chrono>
#include <cmath>

// Fonction utilitaire pour appliquer la force de la souris à la balle
void applyMouseForceToBall(Window &window, Ball &ball, float dt) {
    if (window.isMouseButtonPressed(0)) {
        float mouseX;
        float mouseY;
        window.getMouseWorldPosition(mouseX, mouseY);

        float ballX;
        float ballY;
        ball.getPosition(ballX, ballY);

        const float dx = mouseX - ballX;
        const float dy = mouseY - ballY;
        const float length = std::sqrt(dx * dx + dy * dy);
        if (length > 0.0001f) {
            const float fx = CLICK_FORCE * dx / length;
            const float fy = CLICK_FORCE * dy / length;
            ball.applyForce(fx, fy, dt);
        }
    }
}

int main() {
    try {
        const Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "My OpenGL Window");
        Ball ball(0.1f, 1.0f, 0.8f, 0.0f, 0.0f, 5.0f, 0.0f);

        window.setAspectOrtho(-WINDOW_ASPECT, WINDOW_ASPECT, -1.0f, 1.0f, -1.0f, 1.0f);

        auto lastTime = std::chrono::high_resolution_clock::now();

        while (!window.shouldClose()) {
            auto currentTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> elapsed = currentTime - lastTime;
            const float dt = elapsed.count();
            lastTime = currentTime;

            window.clear();
            window.changeTitle("FPS: " + std::to_string(static_cast<int>(1.0f / dt)));

            applyMouseForceToBall(const_cast<Window &>(window), ball, dt);

            ball.update(dt);
            ball.render();

            window.swapBuffers();
            window.pollEvents();
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
