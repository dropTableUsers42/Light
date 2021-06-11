/** @file physicsworld.cpp
 *  @brief The Physics World.
 *
 *  The Physics World file class conatins the 
 *  Physics Model for the Physics Engine. This 
 *  includes the Gravity Model, Rigid Body 
 *  objects.
 *
 *  @author Divyansh Tiwari (divyanshtiwari237)
 *  @author Neilabh Banzal (Neilabh21)
 *  @bug No known bugs.
 */

/* -- Includes -- */
/* physicsworld header */

#include "physicsworld.hpp"

/** @brief Physics World initialisation with Gravity.
 *
 *  This intialises the Physics World with Gravity, 
 *  input from the ---?---. 
 *
 */
PhysicsWorld::PhysicsWorld(const glm::vec3& gravity)
    : m_gravity(gravity)    
    {}

/** @fn void PhysicsWorld::addRigidBody(const RigidBody& object)
 *  @brief Add a new Rigid Body to m_objects
 *  @param object: input, const RigidBody& type
 */
void PhysicsWorld::addRigidBody(const RigidBody& object)
{
    m_objects.push_back(object);
}

/** @fn void PhysicsWorld::stepSimulation(float time)
 *  @brief steps the simulation by time timestep 
 *  @param timestep: input, float type,time interval
 */
void PhysicsWorld::stepSimulation(float timestep)
{
    for(int i = 0; i < m_objects.size(); i++)
    {
        m_objects[i].updatePosition(timestep);
    }
}