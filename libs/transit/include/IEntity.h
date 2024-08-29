#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>
#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

using namespace routing;

//--------------------  Controller Interface ----------------------------

/**
 * @brief Abstract controller class used in the Transit Service.
 * Uses the Model View Controller Pattern
 */
class IEntity {
 public:
  /**
   * @brief Default constructor.
   */
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }
  /**
   * @brief IEntity Deconstructor.
   */
  virtual ~IEntity() {}
  /**
   * @brief Gets id of this entity.
   * @return The int id of this entity.
   */
  virtual int GetId() const { return id; }
  /**
   * @brief Gets the Vector3 position of this entity.
   * @return The Vector3 position of this entity.
   */
  virtual Vector3 GetPosition() const = 0;
  /**
   * @brief Gets the Vector3 direction of this entity.
   * @return The Vector3 direction of this entity.
   */
  virtual Vector3 GetDirection() const = 0;
  /**
   * @brief Gets the Vector3 destination of this entity.
   * @return The Vector3 destination of this entity.
   */
  virtual Vector3 GetDestination() const = 0;
  /**
   * @brief Gets the details of this entity.
   * @return The JsonObject details of this entity.
   */
  virtual JsonObject GetDetails() const = 0;
  /**
   * @brief Gets the speed of this entity.
   * @return The float speed of this entity.
   */
  virtual float GetSpeed() const = 0;
  /**
   * @brief Gets the availability of this entity.
   * @return The bool availability of this entity.
   */
  virtual bool GetAvailability() const {}
  /**
   * @brief Gets the strategy name of this entity.
   * @return The string strategy name of this entity.
   */
  virtual std::string GetStrategyName() {}
  /**
   * @brief Sets the availability of this entity.
   * @param[in] choice New bool availability for this entity.
   */
  virtual void SetAvailability(bool choice) {}
  /**
   * @brief Updates the scheduler.
   * @param[in] dt New distance of this entity (?).
   * @param[in] scheduler The scheduler vector of IEntity pointers.
   */
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}
  /**
   * @brief Sets the graph for this entity.
   * @param[in] graph New IGraph* for this entity.
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }
  /**
   * @brief Sets the position for this entity.
   * @param[in] pos_ New Vector3 position for this entity.
   */
  virtual void SetPosition(Vector3 pos_) {}
  /**
   * @brief Sets the direction for this entity.
   * @param[in] dir_ New Vector3 direction for this entity.
   */
  virtual void SetDirection(Vector3 dir_) {}
  /**
   * @brief Sets the destination for this entity.
   * @param[in] des_ New Vector3 destination for this entity.
   */
  virtual void SetDestination(Vector3 des_) {}
  /**
   * @brief Sets the strategy name for this entity.
   * @param[in] strategyName_ New string strategy name for this entity.
   */
  virtual void SetStrategyName(std::string strategyName_) {}
  /**
   * @brief Rotates this entity.
   * @param[in] dt The double amount of degrees to rotate this entity by.
   */
  virtual void Rotate(double angle) {}
  /**
   * @brief Lets entity jump in place.
   * @param[in] height The height jumped by entity as a double.
   */
  virtual void Jump(double height) {}
  /**
   * @brief Gets the nearest entity from the scheduler list of entitites.
   * @param[in] scheduler The scheduler vector of IEntity pointers.
   */
  virtual void GetNearestEntity(std::vector<IEntity*> scheduler) {}
  /**
   * @brief Returns the nearest entity of this IEntity.
   * @return The nearest entity to this IEntity.
   */
  virtual IEntity* ReturnNearestEntity() { return NULL; }
  /**
   * @brief Sets the color of this IEntity.
   * @param[in] color_ New color for this IEntity.
   */
  virtual void SetColor(std::string color_) {}
  /**
   * @brief Gets the color of this IEntity.
   * @return Color of this IEntity.
   */
  virtual std::string GetColor() const { return "None"; }

 protected:
  int id;
  const IGraph* graph;
};

#endif  // ENTITY_H_
