#include <SFML/Graphics.hpp>
#include <string>
class Settings {
public:
    int display_width = 1200;
    int display_heigth = 800;

    std::string name = "platformer";

};

class Player {
public:
    float x = 10.f;
    float y = 50.f;
    
};

int main()
{
    Player player;

    sf::Texture snake_head;
    snake_head.loadFromFile("images/snake_head.png");

    sf::Sprite new_sprite;
    new_sprite.setTexture(snake_head);

    new_sprite.setPosition(sf::Vector2f(player.x, player.y)); // absolute position
    

    Settings settings;
    sf::RenderWindow window(sf::VideoMode(settings.display_width, settings.display_heigth), settings.name);
    sf::RectangleShape rectangle(sf::Vector2f(100, 100));
    rectangle.setFillColor(sf::Color::Green);

    //rectangle.setPosition(player.x_player, player.y_player);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                new_sprite.move(sf::Vector2f(-10, 0)); // offset relative to the current position
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                new_sprite.move(sf::Vector2f(10, 0)); // offset relative to the current position
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                new_sprite.move(sf::Vector2f(0, -10)); // offset relative to the current position
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                new_sprite.move(sf::Vector2f(0, 10)); // offset relative to the current position
            }
        }


        window.clear();
        window.draw(new_sprite);
        window.display();
    }

    return 0;
}
