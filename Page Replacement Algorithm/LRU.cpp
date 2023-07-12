#include <bits/stdc++.h>
using namespace std;
int pageFaults(int pages[], int n, int frames)
{
    unordered_set<int> s;
    unordered_map<int, int> indexes;
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < frames)
        {
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
        }

        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int lru = INT_MAX, val;
                for (auto it = s.begin(); it != s.end(); it++)
                {
                    if (indexes[*it] < lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }
                // Remove the indexes page
                s.erase(val);
                // insert the current page
                s.insert(pages[i]);
                // Increment page faults
                page_faults++;
            }
            // Update the current page index
            indexes[pages[i]] = i;
        }
    }

    return page_faults;
}

int main()
{

    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames = 3;
    cout << "Number of page faults: " << pageFaults(pages, n, frames);
    return 0;
}
