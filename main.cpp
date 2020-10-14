#include "DataSequence.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int split_input(float* arr, int n, char str[]) // split comma separated numbers
{
    int count = 0;
    char * token = strtok(str, ","); // get the first token
    // loop through the string to extract all other tokens
    while( token != nullptr )
    {
        float num = atof(token); // convert string to float
        if (num <= 0)
        {
            return -1; // -1 if number is not valid
        }
        else
        {
            *(arr + count) = num; // store in the array
            count++;
        }
        token = strtok(nullptr, ","); // increment the token
    }
    return 1; // indicates success
}


int main()
{
    float n; // size of the array
    float delimiter; // to store the delimiter "-1" or other invalid delimiters
    int numBins; // store number of bins

    char str1[1000]; string str2; // temporary variables

    cin >> n; // the number of dimensions in the vector

    if (n <= 0)
        cout << "-1\n";
    else
    {
        float nums[(int) n];
        cin >> delimiter;

        if (delimiter != -1)
            cout << "-1\n";
        else
        {
            cin >> str1;

            int f = split_input(nums, (int) n, str1);
            if (f == -1)
                cout << "-1\n";
            else
                {

                getline(cin, str2);

                if (str2.length() == 2)
                    cout << "-1\n";
                else {
                    str2 = str2.substr(1);
                    int length = str2.length();
                    string s1(1, str2[0]);
                    string s2(1, str2[1]);
                    string d1 = s1 + s2;
                    string s3(1, str2[length - 1]);
                    string s4(1, str2[length - 2]);
                    string d2 = s4 + s3;

                    if (d1 == "-1" && d2 == "-1")
                    {
                        int l1 = str2.find_first_of(' ');
                        string nbins = str2.substr(l1 + 1, str2.length() - 6);
                        numBins = stoi(nbins);
                        if (numBins <= 0)
                            cout << "-1\n";
                        else
                            {

                            DataSequence dataSequence ((int) n, numBins); // object of class DataSequence

                            for (float num: nums)
                                dataSequence.setElement(num); // add elements to DataSequence

                            dataSequence.sort(); // sort the DataSequence
                            // fix the precision to four decimal places
                            cout << fixed << setprecision(4) << dataSequence.getMin() << " -1 " << fixed <<
                            setprecision(4) << dataSequence.getMean() << " -1 " << fixed << setprecision(4)
                            << dataSequence.getMedian() << " -1 " << fixed << setprecision(4) << dataSequence.getMax() << " -1 ";
                            dataSequence.makeHistogram(); // make the Histogram from DataSequence
                        }
                    }
                    else
                        {
                        cout << "-1\n";
                    }
                }
            }
        }
    }

  return 0 ; // return success
}
