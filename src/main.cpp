#include "graphics/window.h"
#include "core/ball.h"
#include "core/constants.h"
#include <iostream>
#include <chrono>


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

