//
// Created by yairs on 20/04/2020.
//

#ifndef BOUNDINGBOX_BOUNDINGBOX_H
#define BOUNDINGBOX_BOUNDINGBOX_H

#include <string>
#include <vector>

using namespace std;

class BoundingBox {

public:

//    BoundingBox();
    BoundingBox(string name, float x, float y, float width, float height);

    string name;
    float x;
    float y;
    float width;
    float height;

    float area();
    bool isColliding(BoundingBox& other);
    static vector<BoundingBox> boxVectorSort(vector<BoundingBox> list);

    vector<BoundingBox> boxArraySort(BoundingBox *boxArr);

    bool isValidBox();
};


#endif //BOUNDINGBOX_BOUNDINGBOX_H
