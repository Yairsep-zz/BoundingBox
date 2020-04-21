//
// Created by yairs on 20/04/2020.
//

#include <iostream>
#include <algorithm>
#include "../include/BoundingBox.h"
using namespace std;


/**
 *Comparing areas sizes between two Bounding boxes.
 *@param two Bounding boxes
 *@return True if b's area is larger than a's area.
*/
bool compareByArea(BoundingBox a, BoundingBox b)
{
    return (a.area() < b.area());
}

/**
 *Returns a vector of Bounding boxes sorted by their area from the smallest to the largest.
 *@param vector input of unsorted bounding boxes
 *@return sorted vector of Bounding boxes without intersecting objects.
*/
vector<BoundingBox> BoundingBox::boxVectorSort(vector<BoundingBox> list) {

    vector<BoundingBox> output;
    //First remove intersected objects
    for (int i = 0 ; i < list.size() ; i++) {
        bool valid = true;
        if (!list[i].isValidBox()){
            cout << "Error: Invalid box at index " + to_string(i) <<endl;
            valid =false;
        }
        for (int j = 0; j < list.size(); j++) {
            if (i != j && list[j].isValidBox() && list[i].isColliding(list[j])) {
                valid = false;
            }
        }
        if (valid){
            output.push_back(list[i]);
        }
    }
    //Sorting output by area;
    sort(output.begin() , output.end(), compareByArea);
    return output;
}


int main(int argc, char** argv) {

    BoundingBox *rec1 = new BoundingBox("rec1", 20 , 20 , 20 , 20);
    BoundingBox *rec2= new BoundingBox("rec2", 5 , 5 , 5 , 5);
    BoundingBox *rec3 = new BoundingBox( "rec3", 2 , 2 , 2 , 2);
    BoundingBox *rec4 = new BoundingBox( "rec4" , 0 , 0 , 1 , 1);

    vector<BoundingBox> input;
    input.push_back(*rec1);
    input.push_back(*rec2);
    input.push_back(*rec3);
    input.push_back(*rec4);

    vector<BoundingBox> output = BoundingBox::boxVectorSort(input);
    cout << "Bounding boxes sorted by area which are separated:" << endl;
    for (int i = 0 ; i < output.size() ; i++){
        if (i != output.size()-1){
            cout << output[i].name + " < ";
        }
        else{
            cout << output[i].name << endl;
        }
    }
}



