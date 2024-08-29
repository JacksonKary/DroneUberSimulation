#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include <vector>

#include "Drone.h"
#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief A class to decorate a drone with a battery
 */
class BatteryDecorator : public IEntity {
 public:
  /**
   * @brief default constructor
   */
  BatteryDecorator(IEntity* drone_);
  // droney = drone_;
  // time = 0;
  // batteryLevel = 100;

  /**
   * @brief default deconstructor
   */
  ~BatteryDecorator() {}
  /**
   * @brief Returns the speed of the BatteryDecorator
   * @return speed of the BatteryDecorator as a float
   */
  float GetSpeed() const { return droney->GetSpeed(); }
  /**
   * @brief Returns the BatteryDecorators position
   * @return Vector3 object representing position
   */
  Vector3 GetPosition() const { return droney->GetPosition(); }
  /**
   * @brief Returns the BatteryDecorators direction
   * @return Vector3 object representing direction
   */
  Vector3 GetDirection() const { return droney->GetDirection(); }
  /**
   * @brief Returns the BatteryDecorators destination
   * @return Vector3 object representing destination
   */
  Vector3 GetDestination() const { return droney->GetDestination(); }
  /**
   * @brief Returns the details of a BatteryDecorator
   * @return JsonObject with the BatteryDecorator details
   */
  JsonObject GetDetails() const { return droney->GetDetails(); }
  /**
   * @brief Returns a boolean for BatteryDecorator avaliability
   * @return Boolean for avaliability
   */
  bool GetAvailability() const { return droney->GetAvailability(); }
  /**
   * @brief Adds the nearest avaliable Entities to the vector
   * @param[in] scheduler vector of IEntity pointers
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler) {
    droney->GetNearestEntity(scheduler);
  }
  /**
   * @brief Updates the BatteryDecorator, which wraps around the drone's update
   * @param[in] dt time elapsed between moving
   * @param[in] scheduler vector of IEntity pointers
   */
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
   * @brief Recharges battery level
   * @param[in] stationPosition position of station recharge at
   * @return returns distance to the given position as a float
   */
  float nearestStation(Vector3 point);
  /**
   * @brief Sets the BatteryDecorator's position
   * @param[in] pos_ position vector
   */
  void SetPosition(Vector3 pos_) { droney->SetPosition(pos_); }
  /**
   * @brief Sets the BatteryDecorator's direction
   * @param[in] dir_ direction vector
   */
  void SetDirection(Vector3 dir_) { droney->SetDirection(dir_); }
  /**
   * @brief Sets the BatteryDecorator's destination
   * @param[in] des_ destination vector
   */
  void SetDestination(Vector3 des_) { droney->SetDestination(des_); }
  /**
   * @brief Rotates the BatteryDecorator
   * @param[in] angle Angle to rotate
   */
  void Rotate(double angle) { droney->Rotate(angle); }
  /**
   * @brief Makes the BatteryDecorator jump
   * @param[in] height height to jump
   */
  void Jump(double height) { droney->Jump(height); }
  /**
   * @brief Recharges battery level
   */
  void Recharge();

  /**
   * @brief Gets the color of the BatteryDecorator
   * @return Color of the BatteryDecorator
   */
  std::string GetColor() const {
    if (droney) {
      return droney->GetColor();
    }
  }

  /**
   * @brief Sets the bee member variable to a new BeelineStrategy
   */
  void SetBeeline();

  /**
   * @brief Calculates the total length of the drone and robot's path
   * @return Total length of the path
   */
  float CalculatePathLength();

 protected:
  bool isPathCalculated = false;
  IEntity* droney;
  bool dontDec = true;
  int time = 0;
  int batteryLevel;  // As a int percentage
  float distToDest = 0;
  float distToStationFromDest;
  float distToStation;

  const int timeToDecr = 400;  // Amount of time to decrement batteryLevel by 1
  float distCanTravel = timeToDecr * 30;

  Vector3 closestStation;  // Closest station to a point

  std::vector<Vector3> stations{
      Vector3(0, 260, -100),   Vector3(1035, 252, 387),
      Vector3(627, 250, -249), Vector3(1002, 250, -320),
      Vector3(-180, 221, 269), Vector3(460, 248, 345),
      Vector3(-790, 250, 280), Vector3(-816, 242, -300),
      Vector3(-100, 257, -510)};

  IStrategy* bee = NULL;
};  // close class

#endif  // BATTERY_DECORATOR_H_
