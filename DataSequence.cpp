#include <iostream>
#include "DataSequence.h"
#include "Histogram.h"

// Implementation of DataSequence Class

// Public member functions //
 DataSequence::DataSequence(int n, int bins) // constructor
 {
    this->bins = bins;
    this->size = n;
    numList = new float [size]; // create the array
    count = 0;
}

DataSequence::~DataSequence() // destructor
{
    delete numList; // delete the pointer
}

void DataSequence::setElement(float number)
{
    numList[count] = number;
    count++;
}

void DataSequence:: makeHistogram()
{
    Histogram histogram (numList, bins, size); // object of class Histogram

    histogram.compute_binValue();
    histogram.compute_binFreq();
}



void DataSequence::printArray()
{
    for (int i = 0; i < size; i++)
        std::cout << numList[i] << std::endl;

}

void DataSequence::sort()
{
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < size-1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i+1; j < size; j++)
            if (numList[j] < numList[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        float temp = numList[min_idx];
        numList[min_idx] = numList[i];
        numList[i] = temp;
    }
}

float DataSequence::getMin()
{
    return numList[0];
}

float DataSequence::getMax()
{
    return numList[size - 1];
}

float DataSequence::getMedian()
{
    if (size % 2 != 0)
        return numList[size / 2];
    else
        return (numList[(size - 1) / 2] + numList[size / 2]) / 2;
}

float DataSequence::getMean()
{
    float sum = 0.0;
    for (int i = 0; i < size; i++)
        sum += numList[i];

    return sum/float(size);
}

DataSequence::DataSequence(DataSequence &dataSequence)
{
    bins = dataSequence.bins;
    size = dataSequence.size;
    count = dataSequence.count;
    numList = dataSequence.numList;

    delete numList; // deleting old pointer
}
