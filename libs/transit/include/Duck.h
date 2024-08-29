#ifndef LIBS_TRANSIT_INCLUDE_DUCK_H_
#define LIBS_TRANSIT_INCLUDE_DUCK_H_
#include "math/vector3.h"
#include <vector>
#include "IEntity.h"
#include "AstarStrategy.h"
#include "util/json.h"

class Duck : public IEntity {
 public:
    /**
     * @brief Constructor 
     * @param[in] obj JsonObject that represents info on the entity
     */
    Duck(JsonObject& obj);

    /**
     * @brief Destructor
     */
    ~Duck() override = default;

    /**
     * @brief Gets the position of the entity
     * @return Vector3 that is the position
     */
    Vector3 GetPosition() const { return position; }

    /**
     * @brief Gets the direction of the entity
     * @return Vector3 that is the direction 
     */
    Vector3 GetDirection() const { return direction; }

    /**
     * @brief Gets the destination of the entity
     * @return Vector3 that is the destination
     */
    Vector3 GetDestination() const { return destination; }

    /**
     * @brief Sets the position of the entity
     * @param[in] pos_ Vector3 that is the position to set 
     */
    void SetPosition(Vector3 pos_) { position = pos_; }

    /**
     * @brief Sets the direction of the entity
     * @param[in] dir_ Vector3 that is the direction to set 
     */
    void SetDirection(Vector3 dir_) { direction = dir_; }

    /**
     * @brief Sets the destination of the entity
     * @param[in] des_ Vector3 that is the destination to set
     */
    void SetDestination(Vector3 des_) { destination = des_; }

    /**
     * @brief Updates the entity in the simulation 
     * @param[in] dt The delta time elapsed since the last update
     * @param[in] scheduler The vector of all the entities in the simulation
     */
    void Update(double dt, std::vector<IEntity*> scheduler);

    /**
     * @brief Gets the speed of the entity
     * @return A float that is the speed
     */
    float GetSpeed() const { return speed; }

    /**
     * @brief Gets the json information of the entity
     * @return A JsonObject that contains information on the entity
     */  
    JsonObject GetDetails() const { return details; }

    /**
     * @brief Rotates the entity
     * @param[in] angle The angle to rotate by 
     */     
    void Rotate(double angle);

    /**
     * @brief Stops Duck from trying to update position upon reaching destination
     */     
    void Complete();

 private:
    JsonObject details;
    Vector3 position;
    Vector3 direction;
    Vector3 destination;
    float speed;
    IStrategy* astar = NULL;
    bool completed = false;
};
#endif  // LIBS_TRANSIT_INCLUDE_DUCK_H_
