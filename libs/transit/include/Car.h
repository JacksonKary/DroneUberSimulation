#ifndef CAR_H
#define CAR_H

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 * @brief Represents a car in a physical system.
 * Cars move using euler integration based on a specified
 * velocity and direction.
 */
class Car : public IEntity {
 public:
  /**
   * @brief Car Constructor - A single car is created with a speed, position,
   * and destination.
   * @param[in] obj JsonObject with speed, position, and destination.
   */
  Car(JsonObject& obj);
  /**
   * @brief Car deconstructor.
   */
  ~Car() override = default;
  /**
   * @brief Gets the Vector3 position of this Car.
   * @return The Vector3 position of this Car.
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Gets the Vector3 direction of this Car.
   * @return The Vector3 direction of this Car.
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Gets the Vector3 destination of this Car.
   * @return The Vector3 destination of this Car.
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Gets the details of this Car.
   * @return The JsonObject details of this Car.
   */
  JsonObject GetDetails() const override;
  /**
   * @brief Gets the speed of this Car.
   * @return The float speed of this Car.
   */
  float GetSpeed() const { return speed; }
  /**
   * @brief Sets the position for this Car.
   * @param[in] pos_ New Vector3 position for this Car.
   */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Sets the direction for this Car.
   * @param[in] dir_ New Vector3 direction for this Car.
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the destination for this Car.
   * @param[in] des_ New Vector3 destination for this Car.
   */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Rotates this Car.
   * @param[in] angle The double amount of degrees to rotate this Car by.
   */
  void Rotate(double angle);
  /**
   * @brief Updates the Car's position.
   * @param[in] dt Change in time (delta time).
   * @param[in] scheduler IEntity* Vector of nearest entities.
   */
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
   * @brief Helper function that helps choose a new destination once the Car
   * reaches its previous destination
   * @param[in] Min Lower bound of range
   * @param[in] Max Upper bound of range
   * @return Random value of type float within the input bounds
   */
  float Random(float Min, float Max);
  /**
   * @brief Helper function that helps choose and set a new destination once the
   * Car reaches its previous destination
   */
  void SetNewDestination();

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  IStrategy* strategy = NULL;
  float speed;
};

#endif  // CAR_H
