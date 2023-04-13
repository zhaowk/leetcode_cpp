//示例 1：
//
//输入：text = "ghiabcdefhelloadamhelloabcdefghi"
//输出：7
//解释：我们可以把字符串拆分成 "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)"。

//示例 2：
//
//输入：text = "merchant"
//输出：1
//解释：我们可以把字符串拆分成 "(merchant)"。

//示例 3：
//
//输入：text = "antaprezatepzapreanta"
//输出：11
//解释：我们可以把字符串拆分成 "(a)(nt)(a)(pre)(za)(tpe)(za)(pre)(a)(nt)(a)"。
#include "1147.h"
#include <vector>
#include <string>
#include <iostream>

int main() {
    std::vector<std::tuple<std::string_view, std::string_view, int>> cases{
            {"case 1", "ghiabcdefhelloadamhelloabcdefghi", 7},
            {"case 2", "merchant", 1},
            {"case 3", "antaprezatepzapreanta", 11},
            {"case 4", "antaprezatatzapreanta", 13},
            {"case 5", "elvtoelvto", 2}
    };

    for (auto [name, arg, want] : cases) {
        if (auto got = Solution::longestDecomposition(arg); got != want) {
            std::cerr << name << " test failed! want: " << want << ", got: " << got << std::endl;
            return 1;
        }
    }

    return 0;
}
