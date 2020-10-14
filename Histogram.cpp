#include <iostream>
#include "Histogram.h"

// Implementation of Histogram Class

// Public member functions
Histogram:: Histogram(float* arr, int bins, int size)
{
    this->nums = arr;
    this->bins = bins;
    this->size = size;
    binValue = new float [bins+1];
    binFreq = new int [bins];

    for (int i = 0; i < bins; i++)
        binFreq[i] = 0;

}

Histogram::~Histogram() // destructor
{
    delete Histogram::binValue; // delete pointers
    delete Histogram::binFreq;
}

void Histogram:: compute_binValue()
{
    float min = nums[0];
    float max = nums[size - 1];
    float width = (max - min) / float(bins);

    binValue[0] = min;
    for (int i = 1; i  < bins + 1; i++)
    {
        binValue[i] = binValue[i-1] + width;
    }

    for (int i = 0; i < bins; i++)
        std::cout << binValue[i] << ",";

    std::cout << binValue[bins] << " -1 ";
}

void Histogram:: compute_binFreq()
{
    for (int i = 0; i < bins; i++)
    {
        //std::cout << binValue[i] << " " << binValue[i+1] << std::endl;
        for (int j = 0; j < size; j++)
        {
            //std::cout << "Value = " << nums[j] << std::endl;
            if (nums[j] >= binValue[i] && nums[j] < binValue[i+1])
            {
                //std::cout << "Allowed = " << nums[j] << std::endl;
                binFreq[i] += 1;
            }
        }
    }

    for (int i = 0; i < bins - 1; i++)
        std:: cout << binFreq[i] << ",";

    std::cout << binFreq[bins - 1] << " -1";
}

 Histogram::Histogram(Histogram &oldCopy) // copy constructor
{
    nums = oldCopy.nums;
    bins = oldCopy.bins;
    size = oldCopy.size;
    binValue = oldCopy.binValue;
    binFreq = oldCopy.binFreq;

    // deleting old pointers
    delete binValue;
    delete binFreq;
}

