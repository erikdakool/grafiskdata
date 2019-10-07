//
// Created by erik on 27.09.2019.
//

#include "GameObject.h"
#include <cmath>
#include <iostream>
using namespace std;

GameObject::GameObject() {

}

void GameObject::addPoint(float x, float y) {
    Matrix<float> tMatrix = {
            {x},
            {y},
            {1}
    };
    this->points.push_back(tMatrix);
}

void GameObject::Rotate(float r) {
    Translate(-500,-600);
    Matrix<float> tMatrix ={
            {cos(r), -sin(r), 0},
            {sin(r), cos(r), 0},
            {0,0,1}
    };
    for (int i = 0; i < points.size(); ++i) {
        points[i] = tMatrix*points[i];
    }
    Translate(500,600);
}

void GameObject::Translate(float x, float y) {
    Matrix<float> tMatrix ={
            {1, 0, x},
            {0, 1, y},
            {0, 0, 1}
    };
    for (int i = 0; i < points.size(); ++i) {
        points[i] = tMatrix*points[i];
    }
}

void GameObject::Scale(float x, float y) {
    Translate(-500,-600);
    Matrix<float> tMatrix ={
            {x, 0, 0},
            {0, y, 0},
            {0, 0, 1}
    };
    for (int i = 0; i < points.size(); ++i) {
        points[i] = tMatrix*points[i];
    }
    Translate(500,600);
}

void GameObject::Draw(sf::RenderWindow& window) {
    sf::Vertex line[points.size()*2];
    for (int i = 0; i < points.size(); ++i) {
        if(i==points.size()-1){
            line[i*2] = sf::Vertex(sf::Vector2f(points[i][0][0],points[i][1][0]));
            line[i*2+1] = sf::Vertex(sf::Vector2f(points[0][0][0],points[0][1][0]));
        } else{
            line[i*2] = sf::Vertex(sf::Vector2f(points[i][0][0],points[i][1][0]));
            line[i*2+1] = sf::Vertex(sf::Vector2f(points[i+1][0][0],points[i+1][1][0]));
        }
    }
    int i = 1;
    window.draw(line,points.size()*2,sf::Lines);
}