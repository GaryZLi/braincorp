#include <iostream>
#include <vector>

float min, max;

class rangeFilter {
public:
    rangeFilter(float scan): scan(scan) {}

    float update() {
        if (scan < min) {
            scan = min;
        }

        if (scan > max) {
            scan = max;
        }

        return scan;
    }

private:
    float scan;
};

class medianFilter {
public:
    medianFilter(std::vector<float> arr, int len): arr(arr), len(len) {}

    int partition(std::vector<float>& tmpArr, int start, int end) {
        float pivot = tmpArr[end];
        int index = start - 1;

        for (int i = start; i < end; i++) {
            if (tmpArr[i] < pivot) {
                index++;

                temp = tmpArr[i];
                tmpArr[i] = tmpArr[index];
                tmpArr[index] = temp;
            }
        }

        index++;

        temp = tmpArr[end];
        tmpArr[end] = tmpArr[index];
        tmpArr[index] = temp;

        return index;
    }

    void qs(std::vector<float>&tmpArr, int start, int end) {

        if (start < end) {
            int index = partition(tmpArr, start, end);

            qs(tmpArr, 0, index-1);
            qs(tmpArr, index+1, end);
        }
    }

    float update() {
        qs(arr, 0, len-1);         

        int mid;

        if (len % 2 == 0) {
            mid = len/2;

            std::cout << mid << " " << arr[mid] << " " << arr[mid-1] << std::endl;
            return (arr[mid] + arr[mid-1]) / 2;
        }
        else {
            mid = len/2;
            return arr[mid];
        }
    }


private:
    std::vector<float> arr;
    int len;
    float temp;
};

int main() {
    int len, D;

    // std::cout << "Enter the length of the array: ";
    // std::cin >> len;

    // std::cout << "Enter D scans: ";
    // std::cin >> D;

    // std::cout << "Enter the min range: ";
    // std::cin >> min;

    // std::cout << "Enter the max range: ";
    // std::cin >> max;


    len = 5;
    D = 3;
    min = 0;
    max = 20;

    std::vector<std::vector<float>> arr;

    for (int i = 0; i < len; i++) {
        arr.push_back(std::vector<float>());
    }

    std::cout << "Enter scans" << std::endl;

    float scan;
    int num = 0;
    for (int N = 0; N < len*len; N++) { //loop until for the first len-updates
        std::cin >> scan;

        std::cout << std::endl;

        if (scan == 12345)
            break;

        num %= len;

        arr.at(num).push_back(rangeFilter(scan).update());

        std::cout << medianFilter(arr.at(num), arr.at(num).size()).update() << "-----" << std::endl;


        // medianFilter(arr.at(num), arr.at(num).size()).update();

        if (arr.at(num).size() > D + 1) {
            arr.at(num).erase(arr.at(num).begin());
        }

        num++;
    }

    return 0;
}






// 0 [ 0, 1, 2, 1, 3]
// 1 [ 1, 5, 7, 1, 3]
// 2 [ 2, 3, 4, 1, 0]
// 3 [ 3, 3, 3, 1, 3]
// 4 [10, 2, 4, 0, 0]



// 0 [  0,  1,   2, 1,   3]
// 1 [0.5,  3, 4.5, 1,   3]
// 2 [  1,  3,   4, 1,   3]
// 3 [1.5,  3, 3.5, 1,   3]
// 4 [2.5,  3,   4, 1, 1.5]