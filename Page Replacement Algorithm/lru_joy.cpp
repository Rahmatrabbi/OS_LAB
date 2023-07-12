#include <bits/stdc++.h>
using namespace std;
bool contains(vector<pair<int, int>> frames_array, int n)
{
    for (auto frame : frames_array)
    {
        if (frame.first == n)
            return true;
    }

    return false;
}

int getIndex(vector<pair<int, int>> &frames_array)
{
    int size = frames_array.size();
    int index = 0;
    int largest = frames_array[0].second;

    for (int i = 1; i < size; i++)
    {
        if (frames_array[i].second > largest)
        {
            index = i;
            largest = frames_array[i].second;
        }
    }

    return index;
}


int main()
{
    pair<int, int> frame;
    vector<int> reference_string = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    vector<pair<int, int>> frames_array;
    int frame_size = 3;
    int page_fault = 0;
    int i = 0;
    int replaced_index;

    for (auto x : reference_string)
    {
        if (!contains(frames_array, x))
        {
            page_fault++;
            cout << "Fault: " << x << " at:" << i << endl;
            if (frames_array.size() < frame_size)
            {
                frame = {x, 0};
                frames_array.push_back(frame);
            }

            else
            {
                replaced_index = getIndex(frames_array);
                frame = {x, 0};
                cout << "Victim: " << frames_array[replaced_index].first <<  endl;
                frames_array[replaced_index] = frame;
            }
        }

        else
        {
            for(auto &p: frames_array)
            {
                if(p.first == x)
                {
                    p.second = 0;
                }
            }
        }

            for (auto &p : frames_array)
            {
                p = make_pair(p.first, p.second + 1);
            }

        ++i;
    }

    cout << "Total Page Faults are: " << page_fault;
    return 0;
}
