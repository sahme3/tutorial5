#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"
#include <string>


class TAArray {
private:
    TextArea** arr;
    int capacity;
    int size; 

public:
    // Set everything up with a default capacity
    TAArray();

    // Clean up our dynamic array (but we don't delete the TextAreas themselves)
    ~TAArray();

    // Retrieve a TextArea pointer by index, or nullptr if it's out of range
    TextArea* get(int index) const;

    // Retrieve a TextArea pointer by matching its ID, or nullptr if not found
    TextArea* get(const std::string &id) const;

    // Add a pointer at the end (expands array if needed)
    void add(TextArea* ta);

    // Insert a pointer at a specific index, shifting the rest.
    // If the index is invalid, we just append at the end.
    void add(TextArea* ta, int idx);

    // Remove a pointer by index, returning the pointer we took out (or nullptr on failure)
    TextArea* remove(int index);

    // Remove a pointer by ID, returning the pointer we took out (or nullptr if no match)
    TextArea* remove(const std::string &id);

    // Let the caller see how many items are currently stored
    int getSize() const;
};

#endif
