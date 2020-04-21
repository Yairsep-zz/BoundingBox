//
// Created by yairs on 20/04/2020.
//

#include <iostream>
#include "../include/BoundingBox.h"

void test_Area(BoundingBox a){
    cout << to_string(a.area()) <<endl;
}

void test_validBox(BoundingBox a){
    if (a.isValidBox()){
        cout << "Bounding box under test is valid" <<endl;
    }
    else{
        cout << "Bounding box under test is invalid" <<endl;
    }
}

void test_sorting1(){

    //Testing Sorting algorithm - no intersects
    BoundingBox *rec1 = new BoundingBox("rec1", 100 , 100 , 100 , 100);
    BoundingBox *rec2 = new BoundingBox("rec2", 20 , 20 , 20 , 20);
    BoundingBox *rec3 = new BoundingBox( "rec3", 9 , 9 , 5 , 5);
    BoundingBox *rec4 = new BoundingBox( "rec4" , 5 , 5 , 3 , 3);
    BoundingBox *rec5 = new BoundingBox( "rec5" , 2 , 2 , 2 , 2);
    BoundingBox *rec6 = new BoundingBox( "rec6" , 0 , 0 , 1 , 1);

    vector<BoundingBox> test1;
    test1.push_back(*rec1);
    test1.push_back(*rec2);
    test1.push_back(*rec3);
    test1.push_back(*rec4);
    test1.push_back(*rec5);
    test1.push_back(*rec6);

    vector<BoundingBox> output = BoundingBox::boxVectorSort(test1);
    for (int i = 0 ; i < output.size() ; i++){
        if (i != output.size()-1){
            cout << output[i].name + " < ";
        }
        else{
            cout << output[i].name << endl;
        }
    }
}

void test_sorting2(){

    //Testing Sorting algorithm - 1 intersect
    BoundingBox *rec1 = new BoundingBox("rec1", 0 , 0 , 2 , 2);
    BoundingBox *rec2 = new BoundingBox("rec2", 2 , 2 , 2 , 2);
    BoundingBox *rec3 = new BoundingBox( "rec3", 5 , 5 , 10 , 10);

    vector<BoundingBox> test2;
    test2.push_back(*rec1);
    test2.push_back(*rec2);
    test2.push_back(*rec3);

    vector<BoundingBox> output2 = BoundingBox::boxVectorSort(test2);
    for (int i = 0 ; i < output2.size() ; i++){
        if (i != output2.size()-1){
            cout << output2[i].name + " < ";
        }
        else{
            cout << output2[i].name << endl;
        }
    }
}

//int main(int argc, char** argv) {
//
//    BoundingBox *rec1 = new BoundingBox("rec1", 0 , 0 , 0 , 0);
//    BoundingBox *rec2 = new BoundingBox("rec2", 0 , 0 , 2 , 2);
//    BoundingBox *rec3 = new BoundingBox( "rec3", -1 , 2 , 2 , 2);
//    BoundingBox *rec4 = new BoundingBox( "rec4" , 5 , 5 , 3 , 3);
//    BoundingBox *rec5 = new BoundingBox( "rec5" , 1 , 1 , 1 , 1);
//    BoundingBox *rec6 = new BoundingBox( "rec6" , 1 , 1 , 2 , 2);
//
//    test_Area(*rec1); // 0
//    test_Area(*rec2); // 4
//    test_validBox(*rec3); // invalid
//    test_validBox(*rec2); // valid
//    rec4->isColliding(*rec3); //Invalid parameters for other
//    rec3->isColliding(*rec4); //Invalid parameters for this
//    rec5->isColliding(*rec6); //intersect
//    rec4->isColliding(*rec6); //separate
//
//    //Testing unsorted list
//    test_sorting1(); // rec6 < rec5 < rec4 < rec3 < rec2 < rec1
//    //Testing Sorting algorithm - 3 objects, 1 intersect
//    test_sorting2(); // rec3
//
//}
