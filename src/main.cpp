//
// Created by yairs on 20/04/2020.
//

#include <iostream>
#include <algorithm>
#include "../include/BoundingBox.h"


using namespace std;

/**
    Returns the volume of a sphere with the specified radius.

    @param radius The radius of the circle.
    @return The volume of the sphere.
*/
bool compareByArea(BoundingBox a, BoundingBox b)
{
    return (a.area() < b.area());
}

/**
    Returns the volume of a sphere with the specified radius.

    @param radius The radius of the circle.
    @return The volume of the sphere.
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

//vector<BoundingBox> BoundingBox::boxArraySort(BoundingBox boxArr[]) {
//
//    int size = sizeof(*boxArr);
//    vector<BoundingBox> output;
//    //First remove intersected objects
//    for (int i = 0 ; i < size ; i++) {
//        if (!isValidBox()){
//            cout << "Invalid box at index " + to_string(i);
//        }
//        bool valid = true;
//        for (int j = 0; j < size; j++) {
//            if (i != j && boxArr[i].isColliding(boxArr[j])) {
//                valid = false;
//            }
//        }
//        if (valid){
//            output.push_back(boxArr[i]);
//        }
//    }
//    //Sorting output by area;
//    sort(output.begin() , output.end(), compareByArea);
//    return output;
//}

int main(int argc, char** argv) {

    BoundingBox *rec1 = new BoundingBox("rec1", 0 , 0 , 2 , 2);
    BoundingBox *rec2= new BoundingBox("rec2", 80 , 80 , 80 , 80);
    BoundingBox *rec3 = new BoundingBox( "rec3", 2 , 2 , 2 , 2);
    BoundingBox *rec4 = new BoundingBox( "rec4" , 30 , 30 , 3 , 3);


//    BoundingBox boxArr[4] = {*a,*b,*c,*d};
//    vector<BoundingBox> temp = BoundingBox::boxArraySort(boxArr);

    vector<BoundingBox> test;
    test.push_back(*rec1);
    test.push_back(*rec2);
    test.push_back(*rec3);
    test.push_back(*rec4);

    vector<BoundingBox> temp = BoundingBox::boxVectorSort(test);

    for (int i = 0 ; i < temp.size() ; i++){
        if (i != temp.size()-1){
            cout << temp[i].name + " < ";
        }
        else{
            cout << temp[i].name;
        }
    }
}



