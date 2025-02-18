#include "TAArray.h"
#include <iostream>

// We're starting with a small default size. We'll grow the array later if needed.
static const int DEFAULT_CAPACITY = 10;

TAArray::TAArray() {
    capacity = DEFAULT_CAPACITY;
    size = 0;
    arr = new TextArea*[capacity];
    // Initialize all the array slots to nullptr so we don't accidentally use garbage pointers.
    for(int i = 0; i < capacity; i++) {
        arr[i] = nullptr;
    }
}

TAArray::~TAArray() {
    // We aren't deleting the actual TextArea objects here. The test code uses them after removing
    // or does its own cleanup. Deleting them here might cause double frees. 
    delete[] arr; 
}

// If the index is valid, just return the pointer at that spot. Otherwise, return nullptr.
TextArea* TAArray::get(int index) const {
    if(index < 0 || index >= size) {
        return nullptr;
    }
    return arr[index];
}

// Look through the array to find a TextArea with this ID. If we find it, return it; if not, return nullptr.
TextArea* TAArray::get(const std::string &id) const {
    for(int i = 0; i < size; i++) {
        if(arr[i] != nullptr && arr[i]->getID() == id) {
            return arr[i];
        }
    }
    return nullptr;
}

// Add a new TextArea pointer at the end of our list. If the array is full, we make a bigger one first.
void TAArray::add(TextArea* ta) {
    // If there's no room left, we double the capacity.
    if(size >= capacity) {
        int newCap = capacity * 2;
        TextArea** temp = new TextArea*[newCap];
        // Initialize all to nullptr in the new array.
        for(int i = 0; i < newCap; i++) {
            temp[i] = nullptr;
        }
        // Copy existing pointers to the bigger array.
        for(int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;  // get rid of the old smaller array
        arr = temp;
        capacity = newCap;
    }
    // Put our new pointer at the end, then bump up the size.
    arr[size] = ta;
    size++;
}

// Insert a new TextArea pointer at a given index, shifting the rest to the right.
// If the index is out of range, we just stick it at the end (append).
void TAArray::add(TextArea* ta, int idx) {
    // If idx is outside 0..size, just call the "regular" add.
    if(idx < 0 || idx > size) {
        add(ta);
        return;
    }
    // If we're at capacity, same approach as the other add()—double up.
    if(size >= capacity) {
        int newCap = capacity * 2;
        TextArea** temp = new TextArea*[newCap];
        for(int i = 0; i < newCap; i++) {
            temp[i] = nullptr;
        }
        for(int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity = newCap;
    }
    // Move all pointers from right to left so there's space at idx.
    for(int i = size; i > idx; i--) {
        arr[i] = arr[i - 1];
    }
    arr[idx] = ta;
    size++;
}

// Remove a pointer at a certain index, and shift everything left to fill the gap.
// Return the pointer we removed (or nullptr if the index is invalid).
TextArea* TAArray::remove(int index) {
    if(index < 0 || index >= size) {
        return nullptr;
    }
    TextArea* removed = arr[index];
    // Shuffle pointers left
    for(int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = nullptr;
    size--;
    return removed;
}

// Remove a pointer by matching its ID. Return the pointer if found, otherwise nullptr.
TextArea* TAArray::remove(const std::string &id) {
    for(int i = 0; i < size; i++) {
        if(arr[i] != nullptr && arr[i]->getID() == id) {
            TextArea* removed = arr[i];
            // Slide everything left to close that gap.
            for(int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arr[size - 1] = nullptr;
            size--;
            return removed;
        }
    }
    return nullptr;
}

// Just return how many TextArea pointers we're storing right now.
int TAArray::getSize() const {
    return size;
}
