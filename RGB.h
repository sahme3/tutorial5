#ifndef RGB_H
#define RGB_H

class RGB {
private:
    int r;
    int g;
    int b;

public:
    // Default Constructor
    RGB();
    
    // Param Constructor
    RGB(int red, int green, int blue);

    // Getters 
    int getR() const;
    int getG() const;
    int getB() const;

    // Setters
    void setR(int red);
    void setG(int green);
    void setB(int blue);

    // Static function to compare two RGB colors
    static bool isEqual(const RGB &c1, const RGB &c2);
};

#endif
