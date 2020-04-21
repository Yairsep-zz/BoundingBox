//
// Created by yairs on 20/04/2020.
//

#ifndef BOUNDINGBOX_BOUNDINGBOX_H
#define BOUNDINGBOX_BOUNDINGBOX_H

#include <string>
#include <vector>
using namespace std;


/**
 *  @brief  Bounding Box object represent a rectangle or a square in a Cartesian coordinate system
 *  @param  name  The name of the object
 *  @param  x  represents the x coordinate of the button left of the object.
 *  @param  y  represents the y coordinate of the button left of the object.
 *  @param  width  represents width of the object. meaning x + width is the coordinate of the right corner of the object.
 *  @param  height  represents height of the object. meaning y + height is the coordinate of the upper side corner of the object.
 */
class BoundingBox {

public:
//
    BoundingBox(string name, float x, float y, float width, float height);
    string name;
    float x;
    float y;
    float width;
    float height;

    float area();
    bool isColliding(BoundingBox& other);
    bool isValidBox();
    static vector<BoundingBox> boxVectorSort(vector<BoundingBox> list);

};


#endif //BOUNDINGBOX_BOUNDINGBOX_H
