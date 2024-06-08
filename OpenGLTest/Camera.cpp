#include "Camera.h"

Camera::Camera(glm::vec3 pPosition, glm::vec3 pUp, float pYaw, float pPitch)
  : front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY), fov(FOV)
{
  position = pPosition;
  worldUp = pUp;
  yaw = pYaw;
  pitch = pPitch;
  updateCameraVectors();
}

Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float pYaw, float pPitch)
  : front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY), fov(FOV)
{
  position = glm::vec3(posX, posY, posZ);
  worldUp = glm::vec3(upX, upY, upZ);
  yaw = yaw;
  pitch = pitch;
  updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix()
{
  return glm::lookAt(position, position + front, up);
}

void Camera::processKeyboard(CameraMovement direction, float deltaTime)
{
  float velocity = movementSpeed * movementSpeedMultiplier * deltaTime;
  if (direction == FORWARD)
    position += front * velocity;
  if (direction == BACKWARD)
    position -= front * velocity;
  if (direction == LEFT)
    position -= right * velocity;
  if (direction == RIGHT)
    position += right * velocity;
  if (direction == UP)
    position += up * velocity;
  if (direction == DOWN)
    position -= up * velocity;
}

void Camera::processMouseMovement(float xoffset, float yoffset, bool constraintPitch)
{
  xoffset *= mouseSensitivity;
  yoffset *= mouseSensitivity;

  yaw += xoffset;
  pitch += yoffset;

  if (constraintPitch)
  {
    if (pitch > 89.0f)
      pitch = 89.0f;
    if (pitch < -89.0f)
      pitch = -89.0f;
  }
  
  updateCameraVectors();
}

void Camera::processMouseScroll(float xoffset, float yoffset)
{
  fov -= yoffset;
  if (fov < 1.0f)
    fov = 1.0f;
  if (fov > 45.0f)
    fov = 45.0f;
}

void Camera::setMovementSpeedMultiplier(float multiplier)
{
  movementSpeedMultiplier = multiplier;
}

void Camera::updateCameraVectors()
{
  glm::vec3 front{};
  front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
  front.y = sin(glm::radians(pitch));
  front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
  this->front = glm::normalize(front);

  right = glm::normalize(glm::cross(this->front, worldUp));
  up = glm::normalize(glm::cross(right, this->front));
}
