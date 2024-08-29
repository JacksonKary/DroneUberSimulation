#ifndef RECHARGE_STATION_H_
#define RECHARGE_STATION_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 * @brief A class representing a recharge station
 */
class RechargeStation : public IEntity {
 public:
  /**
   * @brief default constructor
   */
  RechargeStation(JsonObject& obj);
  /**
   * @brief default deconstructor
   */
  ~RechargeStation();
  /**
   * @brief Returns the speed of the RechargeStation
   * @return speed of the RechargeStation as a float
   */
  float GetSpeed() const { return speed; }
  /**
   * @brief Returns the RechargeStations position
   * @return Vector3 object representing position
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Returns the RechargeStations direction
   * @return Vector3 object representing direction
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Returns the RechargeStations destination
   * @return Vector3 object representing destination
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Returns the details of a RechargeStation
   * @return JsonObject with the RechargeStation details
   */
  JsonObject GetDetails() const { return details; }
  /**
   * @brief Returns a boolean for RechargeStation avaliability
   * @return Boolean for avaliability
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Adds the nearest avaliable Entities to the vector
   * @param[in] scheduler vector of IEntity pointers
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler) {}
  /**
   * @brief Updates the RechargeStation
   * @param[in] dt time elapsed between moving
   * @param[in] scheduler vector of IEntity pointers
   */
  void Update(double dt, std::vector<IEntity*> scheduler) {}
  /**
   * @brief Sets the RechargeStations position
   * @param[in] pos_ position vector
   */
  void SetPosition(Vector3 pos_) {}
  /**
   * @brief Sets the RechargeStations direction
   * @param[in] dir_ direction vector
   */
  void SetDirection(Vector3 dir_) {}
  /**
   * @brief Sets the RechargeStations destination
   * @param[in] des_ destionation vector
   */
  void SetDestination(Vector3 des_) {}
  /**
   * @brief Rotates the RechargeStation
   * @param[in] angle Angle to rotate
   */
  void Rotate(double angle) {}
  /**
   * @brief Makes the RechargeStation jump
   * @param[in] height height to jump
   */
  void Jump(double height) {}
  /**
   * @brief Recharges battery level
   * @param[in] color_ string that represents the color, in hex
   */
  void SetColor(std::string color_) { color = color_; }
  /**
   * @brief Removing the copy constructor
   * so that RechargeStations cannot be copied.
   */
  RechargeStation(const RechargeStation& station) = delete;
  /**
   * @brief Removing the assignment operator
   */
  RechargeStation& operator=(const RechargeStation& station) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  float jumpHeight = 0;
  bool goUp = true;
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  std::string strategyName;
  IEntity* nearestEntity = NULL;
  std::string color;
};

#endif  // RECHARGE_STATION_H_
