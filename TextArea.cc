#include "TextArea.h"
#include <iostream>

// Default constructor: sets coordinates to (0,0,0,0), empty ID, empty content
TextArea::TextArea() {
    rect = {0, 0, 0, 0};
    id = "";
    content = "";
}

// The tutorial's test code wants a constructor that takes a Rectangle, an ID, and some text.
// We store those in our member variables.
TextArea::TextArea(const Rectangle &r, const std::string &myId, const std::string &myContent) {
    rect = r;
    id = myId;
    content = myContent;
}

// Print a quick summary of our ID, content, and the rectangle's coordinates/dimensions
void TextArea::print() const {
    std::cout << "TextArea [ID=" << id
              << ", content=\"" << content << "\""
              << ", rect=(" << rect.x << "," << rect.y
              << "," << rect.width << "," << rect.height << ")]\n";
}

// Return the ID so we can search for this TextArea by ID in TAArray.
const std::string& TextArea::getID() const {
    return id;
}
