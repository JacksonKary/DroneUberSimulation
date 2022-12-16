#ifndef ROBOT_H
#define ROBOT_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 * @brief Robot class inherits IEntity
 */
class Robot : public IEntity {
 public:
  /**
   * @brief Robot Constructor - Robots are created with a name.
   * @param[in] obj JsonObject with name.
   */
  Robot(JsonObject& obj);
  /**
   * @brief Robot deconstructor.
   */
  ~Robot() override = default;
  /**
   * @brief Gets the Vector3 position of this Robot.
   * @return The Vector3 position of this Robot.
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Gets the Vector3 direction of this Robot.
   * @return The Vector3 direction of this Robot.
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Gets the Vector3 destination of this Robot.
   * @return The Vector3 destination of this Robot.
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Gets the availability of this Robot.
   * @return The bool availability of this Robot.
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Gets the details of this Robot.
   * @return The JsonObject details of this Robot.
   */
  JsonObject GetDetails() const override;
  /**
   * @brief Gets the speed of this Robot.
   * @return The float speed of this Robot.
   */
  float GetSpeed() const { return speed; }
  /**
   * @brief Gets the name of the strategy of this Robot.
   * @return The string strategy name of this Robot.
   */
  std::string GetStrategyName() { return strategyName; }
  /**
   * @brief Sets the availability of this Robot.
   * @param[in] choice New bool availability for this Robot.
   */
  void SetAvailability(bool choice);
  /**
   * @brief Sets the position for this Robot.
   * @param[in] pos_ New Vector3 position for this Robot.
   */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Sets the direction for this Robot.
   * @param[in] dir_ New Vector3 direction for this Robot.
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the destination for this Robot.
   * @param[in] des_ New Vector3 destination for this Robot.
   */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Sets the strategy name for this Robot.
   * @param[in] strategyName_ New string strategy name for this Robot.
   */
  void SetStrategyName(std::string strategyName_) {
    strategyName = strategyName_;
  }
  /**
   * @brief Rotates this Robot.
   * @param[in] angle The double amount of degrees to rotate this Robot by.
   */
  void Rotate(double angle);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
};

#endif  // ROBOT_H
