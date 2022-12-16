#ifndef DRONE_H_
#define DRONE_H_

#include <vector>

#include "BatteryDecorator.h"
#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/** @brief Represents a drone in a physical system.
 * Drones move using euler integration based on a specified
 * velocity and direction.
 **/
class Drone : public IEntity {
 public:
  /**
   * @brief Constructor - Drones are created with a name.
   * @param[in] obj JsonObject with name.
   */
  Drone(JsonObject& obj);
  /**
   * @brief Drone deconstructor.
   */
  ~Drone();
  /**
   * @brief Gets speed of drone.
   * @return Speed of drone as float.
   */
  float GetSpeed() const { return speed; }
  /**
   * @brief Gets the drone position.
   * @return The Vector3 positon of this drone.
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Gets the drone direction.
   * @return The Vector3 direction of this drone.
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Gets the drone destination.
   * @return The Vector3 destination of this drone.
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Gets the drone details.
   * @return The JsonObject details of this drone.
   */
  JsonObject GetDetails() const { return details; }
  /**
   * @brief Gets the drone availability.
   * @return The Bool availability of this drone.
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Gets the nearest entity to this drone.
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler);
  /**
   * @brief Updates the drone's position.
   *
   * @param[in] dt delta time that has passed.
   * @param[in] scheduler IEntity* Vector of nearest entities.
   */
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
   * @brief Sets the drone's position.
   *
   * @param[in] pos_ New Vector3 position of drone.
   */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Sets the drone's direction.
   *
   * @param[in] dir_ New Vector3 direction of drone.
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the drone's destination
   * @param[in] des_ destination vector
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Sets the drone's availability
   * @param[in] avail boolean representing its availibity
   */
  void SetAvailability(bool avail) { available = avail; }

  /**
   * @brief Rotates the drone
   * @param[in] angle Angle to rotate
   */
  void Rotate(double angle);

  /**
   * @brief Makes the drone jump
   * @param[in] height height to jump
   */
  void Jump(double height);

  /**
   * @brief Sets the color of the drone.
   * @param[in] color_ color of the drone.
   */
  void SetColor(std::string color_) { color = color_; }

  /**
   * @brief Gets the color of the drone.
   * @return Color of the drone.
   */
  std::string GetColor() const { return color; }

  /**
   * @brief Returns the nearestEntity member variable of drone.
   * @return The nearest entity to the drone.
   */
  IEntity* ReturnNearestEntity() { return nearestEntity; }

  // Removing the copy constructor and assignment operator
  // so that drones cannot be copied.
  /**
   * @brief Removing the copy constructor
   * so that drones cannot be copied.
   */
  Drone(const Drone& drone) = delete;

  /**
   * @brief Removing the assignment operator
   * so that drones cannot be copied.
   */
  Drone& operator=(const Drone& drone) = delete;

  /**
   * @brief Returns the drone's graph
   * @return the drone's graph
   */
  const IGraph* GetGraph() { return graph; }

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  float jumpHeight = 0;
  bool goUp = true;  // jump helper
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  std::string strategyName;
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
  std::string color = "#00ff00";  // default green
};

#endif  // DRONE_H_
