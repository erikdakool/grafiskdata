#include <SFML/Graphics.hpp>
#include "Matrix.h"
#include "GameObject.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    enum State{Polygon,Scale,Translate,Rotate};
    State state = Polygon;
    sf::Vector2i mouseLast(-1,-1);
    bool rotateClick = false;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    auto gameObject = new GameObject();
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")){}
    sf::Texture background;
    background.loadFromFile("background.png");
    sf::Sprite menuBack;
    menuBack.setPosition(0,0);
    menuBack.setTexture(background);
    menuBack.setColor(sf::Color(128,128,128));

    sf::Text polygon;
    polygon.setFont( font );
    polygon.setStyle( sf::Text::Bold );
    polygon.setString( "Create new" );
    polygon.setFillColor( sf::Color::White );
    polygon.setCharacterSize( 32 );
    polygon.setPosition( 0.f,75.0f );

    sf::Text scale;
    scale.setFont( font );
    scale.setStyle( sf::Text::Bold );
    scale.setString( "Scale" );
    scale.setFillColor( sf::Color::White );
    scale.setCharacterSize( 32 );
    scale.setPosition( 400.f,75.0f );

    sf::Text translate;
    translate.setFont( font );
    translate.setStyle( sf::Text::Bold );
    translate.setString( "Translate" );
    translate.setFillColor( sf::Color::White );
    translate.setCharacterSize( 32 );
    translate.setPosition( 200.f,75.0f );

    sf::Text rotate;
    rotate.setFont( font );
    rotate.setStyle( sf::Text::Bold );
    rotate.setString( "Rotate" );
    rotate.setFillColor( sf::Color::White );
    rotate.setCharacterSize( 32 );
    rotate.setPosition( 600.f,75.0f );


    sf::Text info;
    info.setFont( font );
    info.setStyle( sf::Text::Bold );
    info.setString( "::Polygon" );
    info.setFillColor( sf::Color::White );
    info.setCharacterSize( 32 );
    info.setPosition( 800.f,75.0f );

    gameObject->addPoint(300,300);
    gameObject->addPoint(600,300);
    gameObject->addPoint(800,900);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            auto pos = sf::Mouse::getPosition(window);

            //paintable click
            if(pos.y > 200){
                if(state == Polygon){
                    gameObject->addPoint((float)pos.x,(float)pos.y);
                }else if(mouseLast.x !=-1 && mouseLast.y != -1){
                    float dx;
                    float dy;
                    if(state == Rotate) {
                        float a = sqrtf((mouseLast.x-600)^2 + (mouseLast.y-500)^2);
                        float b = sqrt((pos.x-600)^2 + (pos.y-500)^2);

                        float dr = acos(b/a);
                        std::cout << dr << " " << a << " " << b<< endl;
                        gameObject->Rotate(dr);
			if(rotateClick == false){
				gameObject->Rotate(5*180/3.14);
				rotateClick = true;
			}
                    }else if (state == Translate){
                        dx = (float)pos.x-mouseLast.x ;
                        dy = (float)pos.y- mouseLast.y;
                        gameObject->Translate(dx,dy);
                    }else if(state == Scale){
                        dx = (float)pos.x/mouseLast.x;
                        dy = (float)pos.y/mouseLast.y;
                        cout << dx << " " << pos.x <<  " " <<mouseLast.x << endl;
                        gameObject->Scale(dx,dy);
                    }
                }
                //menu click
            }else if(pos.y < 200 && pos.x < 800){
                if(pos.x > 600){
                    state = Rotate;
                    gameObject->Rotate(5*180/3.14);
                    info.setString( "::Rotate" );
                }else if(pos.x > 400){
                    state = Scale;
                    info.setString( "::Scale" );
                }else if(pos.x > 200){
                    state = Translate;
                    info.setString( "::Translate" );
                }else{
                    gameObject = new GameObject();
                    info.setString( "::Polygon" );
                    state = Polygon;
                }
            }
            mouseLast.x = pos.x;
            mouseLast.y = pos.y;
        } else{
            mouseLast.x = -1;
            mouseLast.y = -1;
	    rotateClick = false;
        }
	

        window.clear();
        gameObject->Draw(window);
        window.draw(menuBack);
        window.draw(polygon);
        window.draw(scale);
        window.draw(translate);
        window.draw(rotate);
        window.draw(info);
        window.display();
    };
    return 0;
}
