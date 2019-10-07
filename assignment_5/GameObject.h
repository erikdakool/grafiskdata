//
// Created by erik on 27.09.2019.
//

#ifndef ASSIGNMENT_5_GAMEOBJECT_H
#define ASSIGNMENT_5_GAMEOBJECT_H

#include <memory>
#include <vector>

#include "Matrix.h"
#include "SFML/Graphics.hpp"

using namespace std;
class GameObject {
public:
    GameObject();
    ~GameObject();

    void Rotate(float r);
    void Translate(float x, float y);
    void Scale(float x, float y);

    void addPoint(float x, float y);
    void Draw(sf::RenderWindow& window);
private:
    vector<Matrix<float>> points;
};


#endif //ASSIGNMENT_5_GAMEOBJECT_H
