#ifndef ENTITY
#define ENTITY

#include <SFML/System/Vector2.hpp>
#include "SceneNode.h"

class Entity : public SceneNode{
	private:
		sf::Vector2f mVelocity;
	public:
		//set and get its speed which is in the two dimensional vector
		void setVelocity(sf::Vector2f velocity);
		void setVelocity(float vx, float vy);
		sf::Vector2f getVelocity() const;
};

#endif // !ENTITY

