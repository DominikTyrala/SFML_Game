#ifndef GAME_CLASS
#define GAME_CLASS
#include <SFML/Graphics.hpp>

class Game {
public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time);
	void render();
	void handlePlayerInput(sf::Keyboard::Key, bool);

private:
	sf::RenderWindow mWindow;
	sf::Texture mTexture;
	sf::Sprite mPlayer;
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

	bool mIsMovingUp = false;
	bool mIsMovingDown = false;
	bool mIsMovingLeft = false;
	bool mIsMovingRight = false;
};

#endif // !GAME_CLASS

/*
sf::Texture works on video card
sf::Sprite	works on ram, refers to texture
sf::Image	
sf::Font
sf::SoundBuffer - sound effects short
sf::Sound - plays soundbuffer
sf::Music - plays music in background
*/

