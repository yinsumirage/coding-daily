#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n; // 读取人数

    string votes;
    cin >> votes; // 读取投票信息

    int count_d = 0; // 计数冬马族的投票数
    int count_x = 0; // 计数雪菜族的投票数

    for (char vote : votes) {
        if (vote == 'D') {
            count_d++;
        } else {
            count_x++;
        }

        // 根据当前的投票情况判断是否需要进行一票否决
        if (count_d > 0 && count_x > 0) {
            count_d--;
            count_x--;
        }
    }

    // 判断最终剩下的种族，如果剩下的人数大于1，继续投票直到只剩下一个人
    while (count_d > 1 || count_x > 1) {
        if (count_d > count_x) {
            count_x = 0;
        } else {
            count_d = 0;
        }
    }

    // 根据最终的计数结果确定当选种族
    if (count_d > count_x) {
        cout << "D" << endl;
    } else {
        cout << "X" << endl;
    }

    system("pause");

    return 0;

}
