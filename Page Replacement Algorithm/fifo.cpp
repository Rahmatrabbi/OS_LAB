#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int fifo(vector<int> pages, int frames) {
    int page_faults = 0;
    queue<int> frame_queue;
    vector<bool> is_present(frames, false);

    for (int i = 0; i < pages.size(); i++) {
        int current_page = pages[i];

        if (!is_present[current_page]) {
            page_faults++;

            if (frame_queue.size() == frames) {
                int page_to_remove = frame_queue.front();
                frame_queue.pop();
                is_present[page_to_remove] = false;
            }

            frame_queue.push(current_page);
            is_present[current_page] = true;
        }
    }

    return page_faults;
}

int main() {
    int frames, pages;
    cout << "Enter the number of frames: ";
    cin >> frames;
    cout << "Enter the number of pages: ";
    cin >> pages;

    vector<int> page_sequence(pages);
    cout << "Enter the page sequence: ";
    for (int i = 0; i < pages; i++) {
        cin >> page_sequence[i];
    }

    int page_faults = fifo(page_sequence, frames);

    cout << "Number of page faults: " << page_faults << endl;

    return 0;
}
