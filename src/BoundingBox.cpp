//
// Created by yairs on 20/04/2020.
//

#include <iostream>

#include "../include/BoundingBox.h"
using namespace std;


BoundingBox::BoundingBox(string name, float x, float y, float width, float height) :name(name), x(x) , y(y), width(width), height(height){}


/**
 * function that calculates the area of a Bounding box.
 * @return the area of the Bounding box.
 */
float BoundingBox::area() {
    return (width * height);
}

/**
 * Function which checks if two Bounding boxes objects are colliding is space,
 * also handles with errors such as if one of them has negative parameters etc.
 *
 * @param other which is another Bounding box which this is compared with.
 * @return True is the two Bounding boxes is Colliding.
 */
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
        cout << "intersect"<< endl;
        return true;
    }
    else {
        cout << "separate"<< endl;
        return false;
    }
}

//
/**
 * Function which checks if a Bounding box doesn't have negative parameters or has no area.
 * @return True is the Bounding box is valid.
 */
bool BoundingBox::isValidBox(){
    if (x < 0 | y < 0 | width < 0 | height < 0){
        return false;
    }
    return !((x == 0 & width == 0) | (y == 0 & height == 0));
}


