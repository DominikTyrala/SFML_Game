#ifndef SCENENODE
#define SCENENODE

#include <memory>
#include <vector>
#include <algorithm>
#include <cassert>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
public:
	typedef std::unique_ptr<SceneNode> Ptr;

public:
	SceneNode();
	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::vector<Ptr> mChildren;
	SceneNode* mParent;
};

#endif // !SCENENODE
