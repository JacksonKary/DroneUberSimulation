#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 * @brief helicopter class.
 */
class Helicopter : public IEntity {
 public:
  /**
   * @brief Default constructor for helicopter class.
   * @param[in] obj JsonObject to create helicopter from
   */
  Helicopter(JsonObject& obj);
  /**
   * @brief destructor
   */
  ~Helicopter() override = default;
  /**
   * @brief Returns the Helicopters position
   * @return Vector3 object representing position
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Returns the helicopters direction
   * @return Vector3 object representing direction
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Returns the helicopters destination
   * @return Vector3 object representing destination
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Returns the details of a helicopter
   * @return JsonObject with the helicopter details
   */
  JsonObject GetDetails() const override;
  /**
   * @brief Returns the speed of the helicopter
   * @return speed of the helicopter as a float
   */
  float GetSpeed() const { return speed; }
  /**
   * @brief Sets the helicopters position
   * @param[in] pos_ position vector
   */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Sets the helicopters direction
   * @param[in] dir_ direction vector
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the helicopters destination
   * @param[in] des_ destionation vector
   */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Rotates the helicopter
   * @param[in] angle Angle to rotate
   */
  void Rotate(double angle);
  /**
   * @brief Updates the Helicopter
   * @param[in] dt time elapsed between moving
   * @param[in] scheduler vector of IEntity pointers
   */
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
   * @brief returns a random float value between the defined boundaries
   * @param[in] Min lower bound of range
   * @param[in] Max upper bound of range
   */
  float Random(float Min, float Max);
  /**
   * @brief Sets the Helicopter's destination.
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

#endif  // HELICOPTER_H
