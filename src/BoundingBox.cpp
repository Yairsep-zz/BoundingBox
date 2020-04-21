//
// Created by yairs on 20/04/2020.
//

#include <iostream>
#include <algorithm>
#include "../include/BoundingBox.h"
using namespace std;

BoundingBox::BoundingBox(string name, float x, float y, float width, float height) :name(name), x(x) , y(y), width(width), height(height){}

float BoundingBox::area() {
    return (width * height);
}

bool BoundingBox::isColliding(BoundingBox &other) {

    if (x < 0 | y < 0 | width < 0 | height < 0){
        cout << "Error: Invalid parameters for this"<< endl;
        return true;
    }
    if (other.x < 0 | other.y < 0 | other.width < 0 | other.height < 0){
        cout << "Error: Invalid parameters for other"<< endl;
        return true;
    }

    if ((x + width >= other.x) && (x <= other.x +other.width) &&
        (y + height >= other.y)& (y <= other.y + other.height)){
        cout << "Intersect"<< endl;
        return true;
    }
    else {
        cout << "separate"<< endl;
        return false;
    }

}

bool BoundingBox::isValidBox(){
    if (x < 0 | y < 0 | width < 0 | height < 0){
        return false;
    }
    if ((x == 0 &  width == 0) | (y == 0 & height == 0)){
        return false;
    }
    else{
        return true;
    }
}

//BoundingBox::BoundingBox() {
//
//}


