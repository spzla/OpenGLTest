#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum CameraMovement {
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT,
  UP,
  DOWN
};

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float FOV = 45.0f;

class Camera
{
public:
  glm::vec3 position;
  glm::vec3 front;
  glm::vec3 up;
  glm::vec3 right;
  glm::vec3 worldUp;

  float yaw;
  float pitch;
  
  float movementSpeed;
  float movementSpeedMultiplier;
  float mouseSensitivity;
  float fov;

  Camera(glm::vec3 pPosition = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 pUp = glm::vec3(0.0f, 1.0f, 0.0f), float pYaw = YAW, float pPitch = PITCH);
  Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float pYaw, float pPitch);

  glm::mat4 getViewMatrix();

  void processKeyboard(CameraMovement direction, float deltaTime);
  void processMouseMovement(float xoffset, float yoffset, bool constraintPitch = true);
  void processMouseScroll(float xoffset, float yoffset);

  void setMovementSpeedMultiplier(float multiplier);

private:
  void updateCameraVectors();
};