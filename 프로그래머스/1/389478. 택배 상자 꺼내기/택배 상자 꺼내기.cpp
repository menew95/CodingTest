#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int target_row = (num - 1) / w;
    int target_col;

    if (target_row % 2 == 0) {
        target_col = (num - 1) % w;
    } else {
        target_col = w - 1 - ((num - 1) % w);
    }
    int total_boxes_to_remove = 1;
    int highest_row = (n - 1) / w;

    for (int r = target_row + 1; r <= highest_row; ++r) {
        int box_num_on_top;
        
        if (r % 2 == 0) {
            box_num_on_top = r * w + target_col + 1;
        } else {
            box_num_on_top = r * w + (w - 1 - target_col) + 1;
        }

        if (box_num_on_top <= n) {
            total_boxes_to_remove++;
        }
    }

    return total_boxes_to_remove;
}