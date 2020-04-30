# Validate IP Address

![Medium](../../materials/-Medium-f0ad4e.svg) ![String](../../materials/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode468-cpp-f34b7d.svg)   | 0 ms    | 6.4 Mb       |
| ![python](https://img.shields.io/badge/leetcode468-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode468-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

**IPv4** addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots (`"."`), e.g.,`172.16.254.1`;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

**IPv6** addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (`":"`). For example, the address `2001:0db8:85a3:0000:0000:8a2e:0370:7334` is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so `2001:db8:85a3:0:0:8A2E:0370:7334` is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, `2001:0db8:85a3::8A2E:0370:7334` is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address `02001:0db8:85a3:0000:0000:8a2e:0370:7334` is invalid.

## NOTE

You may assume there is no extra space or special characters in the input string.

## EXAMPLE 1

```plain
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
```

## EXAMPLE 2

```plain
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
```

## EXAMPLE 3

```plain
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.
```

## SOLUTION

* 标准字符串处理

## CODE

### C++

```cpp
class Solution
{
    const string IPV4 = "IPv4";
    const string IPV6 = "IPv6";
    const string NAY = "Neither";
    const string HEX = "0123456789ABCDEFabcdef";

    inline bool isHexDigit(char ch)
    {
        return binary_search(HEX.begin(), HEX.end(), ch);
    }

    bool isIPv4Block(const string &block)
    {
        int hoge = 0, sz = block.size();
        if (sz <= 0 || sz > 3) return false;
        for (int i = 0; i < sz; i++)
        {
            char ch = block[i];
            if (!isdigit(ch)) return false;
            if (i == 0 && ch == '0' && sz > 1) return false;
            hoge = 10 * hoge + ch - '0';
        }
        return hoge <= 255;
    }

    bool isIPv6Block(const string &block)
    {
        int sz = block.size();
        if (sz <= 0 || sz > 4) return false;
        for (int i = 0; i < sz; i++)
        {
            if (!isHexDigit(block[i])) return false;
        }
        return true;
    }

    vector<string> split(const string &str, char sep)
    {
        vector<string> ret;
        if (str.empty()) return ret;
        stringstream iss(str);
        for (string _; getline(iss, _, sep); ret.push_back(_));
        return ret;
    }

public:
    string validIPAddress(string IP)
    {
        if (IP.substr(0, 4).find('.') != string::npos)
        {
            vector<string> blocks = split(IP, '.');
            if (blocks.size() != 4) return NAY;
            int piyo = accumulate(blocks.begin(), blocks.end(), 0, 
                [](int a, string _) -> int { return a + _.size(); });
            if (piyo + 3 != IP.size()) return NAY;
            for (auto item : blocks)
            {
                if (!isIPv4Block(item)) return NAY;
            }

            return IPV4;
        }
        else if (IP.substr(0, 5).find(':') != string::npos)
        {
            vector<string> blocks = split(IP, ':');
            if (blocks.size() != 8) return NAY;
            int piyo = accumulate(blocks.begin(), blocks.end(), 0, 
                [](int a, string _) -> int { return a + _.size(); });
            if (piyo + 7 != IP.size()) return NAY;
            for (auto item : blocks)
            {
                if (!isIPv6Block(item)) return NAY;
            }
            return IPV6;
        }
        else return NAY;
    }
};
```

### Python3

### Ruby

### Java
