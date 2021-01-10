#include <SFML/Graphics.hpp>

class GameWindow
{
public:
    GameWindow(const std::string& windowName, float w, float h);
    void Update();
    void BeginDraw();
    void Draw(const sf::Drawable& drawable);
    void EndDraw();
    bool IsOpen() const;
    //sf::RenderWindow WindowGame;
    void SetSpriteBackground(sf::Texture t);
    sf::Sprite sprite;
    sf::Event event;
    sf::RenderWindow WindowGame;   
};