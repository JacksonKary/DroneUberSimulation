#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "IEntity.h"
#include "util/json.h"

//--------------------  Controller Interface ----------------------------

/**
 * @brief Abstract controller class used in the Transit Service.
 * Uses the Model View Controller Pattern.
 */
class IController {
 public:
  /**
   * @brief IController Deconstructor.
   */
  virtual ~IController() {}
  /**
   * @brief Adds and entity to the program.
   * @param[in] entity The IEntity entity to add.
   */
  virtual void AddEntity(const IEntity& entity) = 0;
  /**
   * @brief Updates an entity in the program.
   * @param[in] entity The IEntity entity to update.
   */
  virtual void UpdateEntity(const IEntity& entity) = 0;
  /**
   * @brief Removes an entity from the program.
   * @param[in] id The int id of the entity to be removed.
   */
  virtual void RemoveEntity(int id) = 0;
  /**
   * @brief Adds a path to the program.
   * @param[in] id The int id of the path to be added.
   * @param[in] path The vector<vector<float> > path to be added
   */
  virtual void AddPath(int id,
                       const std::vector<std::vector<float> >& path) = 0;
  /**
   * @brief Removes a path from the program.
   * @param[in] id The int id of the path to be removed.
   */
  virtual void RemovePath(int id) = 0;
  /**
   * @brief Allows messages to be passed back to the view.
   * @param[in] event The message to view as a string.
   * @param[in] details The JsonObject details of the event.
   */
  virtual void SendEventToView(const std::string& event,
                               const JsonObject& details) = 0;
};

#endif  // CONTROLLER_H_
