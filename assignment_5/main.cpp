#include <SFML/Graphics.hpp>
#include "Matrix.h"
#include "GameObject.h"
#include <iostream>

using namespace std;
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    auto gameObject = new GameObject();
    gameObject->addPoint(1,1);
    gameObject->addPoint(1,10);
    gameObject->addPoint(10,1);

    gameObject->Scale(10,10);
    gameObject->Translate(400,300);

    auto gameObject2 = new GameObject();
    gameObject2->addPoint(1,1);
    gameObject2->addPoint(1,10);
    gameObject2->addPoint(10,1);

    gameObject2->Roatate((90*3.14)/180);
    gameObject2->Scale(10,10);
    gameObject2->Translate(300,300);

    auto gameObject3 = new GameObject();
    gameObject3->addPoint(1,1);
    gameObject3->addPoint(1,10);
    gameObject3->addPoint(10,1);

    gameObject3->Roatate((270*3.14)/180);
    gameObject3->Scale(10,10);
    gameObject3->Translate(400,200);

    auto gameObject4 = new GameObject();
    gameObject4->addPoint(1,1);
    gameObject4->addPoint(1,10);
    gameObject4->addPoint(10,1);

    gameObject4->Roatate((180*3.14)/180);
    gameObject4->Scale(10,10);
    gameObject4->Translate(300,200);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        gameObject->Draw(window);
        gameObject2->Draw(window);
        gameObject3->Draw(window);
        gameObject4->Draw(window);
        window.display();
    };
    return 0;
}