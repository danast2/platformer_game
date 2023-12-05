#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
    window.setFramerateLimit(120);

    float dt;
    sf::Clock dt_clock;

    const float grid_size = 100.f;

    //Player
    const float movement_speed = 100.f;
    sf::Vector2f velocity;
    window.setFramerateLimit(120);

    sf::Texture new_player_texture;
    new_player_texture.loadFromFile("images/snake_head.png");
    

    sf::Sprite new_player_sprite;
    new_player_sprite.setTexture(new_player_texture);
    

    while (window.isOpen())
    {
        dt = dt_clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            velocity.x = 0.f;
            velocity.y = 0.f;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                velocity.y += -movement_speed * dt;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                velocity.y += movement_speed * dt;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                velocity.x += -movement_speed * dt;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                velocity.x += movement_speed * dt;
            }
        }



        new_player_sprite.move(velocity);

        window.clear();

        window.draw(new_player_sprite);

        window.display();
    }

    return 0;
}