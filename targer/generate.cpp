#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

std::vector<int> generateRandomNumbers(int min, int max, int count) {
    std::vector<int> numbers;
    for (int i = 0; i < count; i++) {
        int num = rand() % (max - min + 1) + min;
        numbers.push_back(num);
    }
    return numbers;
}

void printNumbers(const std::vector<int>& numbers) {
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // 设置随机数种子
    srand(time(0));

    // 生成红色球的6个随机号码（1-33之间）
    std::vector<int> redNumbers = generateRandomNumbers(1, 33, 6);

    // 生成蓝色球的1个随机号码（1-16之间）
    std::vector<int> blueNumbers = generateRandomNumbers(1, 16, 1);

    // 输出生成的双色球号码
    std::cout << "Red numbers: ";
    printNumbers(redNumbers);
    std::cout << "Blue number: ";
    printNumbers(blueNumbers);

    return 0;
}

/*
使用了 `generateRandomNumbers` 函数来生成指定范围内的随机数，并存储在一个向量中。
然后，我们使用 `printNumbers` 函数来打印生成的号码。

程序首先设置随机数种子，然后生成6个红色球的随机号码（范围为1-33），
以及1个蓝色球的随机号码（范围为1-16）。最后，程序输出生成的双色球号码。
*/
