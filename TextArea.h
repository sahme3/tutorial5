#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "defs.h"
#include <string>

class TextArea {
private:
    Rectangle rect;
    std::string id;
    std::string content;

public:
    // Start with everything set to zero or empty
    TextArea();

    // This constructor is how test.cc typically creates a new TextArea
    TextArea(const Rectangle &r, const std::string &myId, const std::string &myContent);

    // The test code calls ->print() to display ID, content, and rectangle info
    void print() const;

    // We need to look up areas by ID in TAArray, so here's a quick getter
    const std::string& getID() const;
};

#endif
