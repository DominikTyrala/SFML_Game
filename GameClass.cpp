#include "GameClass.h"

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application"), mTexture(), lTexture(), mPlayer(), mLandscape(){

	if (!mTexture.loadFromFile("C:/Users/jz1clv/Documents/visual studio 2015/Projects/SFML_GAME_V2/SFML_GAME_V2/Images/Eagle.png")) {
		//TO DO if file has not been loaded properly
	}
	mPlayer.setTexture(mTexture);

	if (!lTexture.loadFromFile("C:/Users/jz1clv/Documents/visual studio 2015/Projects/SFML_GAME_V2/SFML_GAME_V2/Images/Desert.png")) {
		//TO DO if file has not been loaded properly
	}
	mLandscape.setTexture(lTexture);

	mPlayer.setPosition(100.f, 100.f);
}

void Game::run() {

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen()) {
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::processEvents() {
	sf::Event event;

	while (mWindow.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				mWindow.close();
				break;
		}
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}


void Game::update(sf::Time deltaTime) {
	sf::Vector2f movement(0.f, 0.f);

	if (mIsMovingUp)
		movement.y -= 1.f;
	if (mIsMovingDown)
		movement.y += 1.f;
	if (mIsMovingLeft)
		movement.x -= 1.f;
	if (mIsMovingRight)
		movement.x += 1.f;

	mPlayer.move(movement); //* deltaTime.asSeconds()
}

void Game::render() {
	mWindow.clear();
	mWindow.draw(mLandscape);
	mWindow.draw(mPlayer);
	mWindow.display();
}

