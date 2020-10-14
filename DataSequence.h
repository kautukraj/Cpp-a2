#ifndef DataSequence_H
#define DataSequence_H

class DataSequence
        {
 public:
  explicit DataSequence(int n, int bins) ; // constructor
  ~DataSequence() ; // destructor
  DataSequence(DataSequence&) ; // copy constructor

  // get functions //
  float getMin();
  float getMax();
  float getMedian();
  float getMean();

  void setElement(float n);
  void sort();
  void makeHistogram();
  void printArray();
  
 protected: // no protected members
  
 private:
  // Data members //
  float* numList;
  int size;
  int count;
  int bins;
} ;
#endif
