#ifndef Histogram_H
#define Histogram_H

class Histogram
{
public:
    explicit Histogram(float*, int, int) ; // constructor
    ~Histogram() ; // destructor
    Histogram(Histogram &histogram); // write a copy constructor

    void compute_binValue();
    void compute_binFreq();

protected: // no protected members

private:
    // Data members //
    float* nums;
    float* binValue;
    int* binFreq;
    int bins;
    int size;
} ;
#endif
