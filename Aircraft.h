#ifndef AIRCRAFT
#define AIRCRAFT

#include <sfml/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Entity.h"
#include "ResourceIdentifiers.h"

class Aircraft : public Entity {

public:
	enum Type {
		Eagle,
		Raptor,
	};

	Aircraft(Type type, const TextureHolder& textures);
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Type mType;
	sf::Sprite mSprite;
};


#endif // !AIRCRAFT
