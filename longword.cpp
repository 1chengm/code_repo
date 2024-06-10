#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string sentence;
    getline(cin, sentence); // 读取整行输入，包括空格

    // 使用字符串流来分割句子中的单词
    stringstream ss(sentence);
    string word;
    string longestWord = "";
    int maxLength = 0;

    while (ss >> word) {
        // 检查当前单词是否比已知的最长单词更长
        if (word.length() > maxLength) {
            maxLength = word.length();
            longestWord = word;
        }
    }

    // 输出最长单词，并在末尾加上句点
    cout << longestWord  << endl;

    return 0;
}
