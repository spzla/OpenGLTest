#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "stb_image.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);