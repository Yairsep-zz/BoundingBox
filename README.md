# BoundingBox
I represented Boundig box by x , y, width and height parameters, as looking in Cartesian coordinate system.
x  represents the x coordinate of the button left of the object, meaning x + width is the coordinate of the right corner of the object.
y  represents the y coordinate of the button left of the object, meaning y + height is the coordinate of the upper side corner of the object.

Instructions:
1. Pull the project from Github using the link to your IDE (I used Clion)
2. Bounding box object is represented in BoundingBox.h and BoundingBox.cpp.
3. Function to determine if two objects intersect / invalid / separate is in BoundingBox.cpp - isColliding.
4. Soring function is in main.cpp - boxVectorSort.
5. Get into main.cpp file, in the main function currently there is a template.
6. Change parameters of the existing Bounding boxes (rec1, rec2 etc) or add more objects as you wish.
7. If you added more objects make sure to add them into input vector ( input.push_back(*someobject) ).
8. Run main function - in the console the list of the sorted Bounding boxes will be printed.
9.Tests are located in tests.cpp file - End cases and tests to make sure the function work properly.
