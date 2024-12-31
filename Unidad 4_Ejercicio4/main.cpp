#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
using namespace sf;

//////Variables//////
Texture texture_c1, texture_c2, texture_c3, texture_c4, cursor;
Sprite sprite_c1, sprite_c2, sprite_c3, sprite_c4, sprite_cursor;

float height_c1, width_c1; float height_c2, width_c2; float height_c3, width_c3; float height_c4, width_c4;
bool isDragging = false; // Indicador de si estamos arrastrando un sprite
Sprite* selectedSprite = nullptr; // Puntero al sprite seleccionado

///Punto de entrada a la aplicación///
int main() {

	//Cargamos la textura del archivo
	texture_c1.loadFromFile("rcircle.png");
	texture_c2.loadFromFile("rcircle.png");
	texture_c3.loadFromFile("rcircle.png");
	texture_c4.loadFromFile("rcircle.png");
	cursor.loadFromFile("cursor.png");


	//Cargamos el material del sprite
	sprite_c1.setTexture(texture_c1);
	sprite_c2.setTexture(texture_c2);
	sprite_c3.setTexture(texture_c3);
	sprite_c4.setTexture(texture_c4);
	sprite_cursor.setTexture(cursor);

	//Movemos el sprite
	sprite_c2.setPosition(0, 0);
	sprite_c2.setPosition(672, 0);
	sprite_c3.setPosition(0, 472);
	sprite_c4.setPosition(672, 472);
	sprite_cursor.setPosition(0, 0);

	height_c1 = static_cast<float>(texture_c1.getSize().y);
	width_c1 = static_cast<float>(texture_c1.getSize().x);

	//sf::Event evt;

	/////Creamos la ventana//////
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Que Ventana horrible");

	/////Loop principal//////
	App.setMouseCursorVisible(false);

	Vector2i pospress;
	Vector2i posrell;
	
	/////Loop principal//////
	while (App.isOpen())
	{
		sf::Event evt;
		App.clear();

		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type) {

				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;

			case sf::Event::MouseMoved:
				sprite_cursor.setPosition(evt.mouseMove.x, evt.mouseMove.y);

				if (isDragging && selectedSprite) {
					selectedSprite->setPosition(static_cast<float>(evt.mouseMove.x-64), static_cast<float>(evt.mouseMove.y-64));
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (evt.mouseButton.button == sf::Mouse::Left) {
					Vector2f mousePos(static_cast<float>(evt.mouseButton.x), static_cast<float>(evt.mouseButton.y));

					// Verificar si se hace clic en algún sprite
					if (sprite_c1.getGlobalBounds().contains(mousePos)) {
						selectedSprite = &sprite_c1;
						isDragging = true;
					}
					else if (sprite_c2.getGlobalBounds().contains(mousePos)) {
						selectedSprite = &sprite_c2;
						isDragging = true;
					}
					else if (sprite_c3.getGlobalBounds().contains(mousePos)) {
						selectedSprite = &sprite_c3;
						isDragging = true;
					}
					else if (sprite_c4.getGlobalBounds().contains(mousePos)) {
						selectedSprite = &sprite_c4;
						isDragging = true;
					}
				}
				break;

			case sf::Event::MouseButtonReleased:
				if (evt.mouseButton.button == sf::Mouse::Left) {
					isDragging = false;
					selectedSprite = nullptr;
				}
				break;
			}


		}

		App.draw(sprite_c1);
		App.draw(sprite_c2);
		App.draw(sprite_c3);
		App.draw(sprite_c4);
		App.draw(sprite_cursor);

		App.display();
	}
	return 0;
}
