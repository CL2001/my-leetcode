#include <string>
#include <algorithm>


class Solution {
public:
    std::string addBinary(std::string a, std::string b)
    {
        int resultSize = std::max(a.length(), b.length()) + 1;
        std::string result(resultSize, '0');

        int indexA = a.length() - 1;
        int indexB = b.length() - 1;

        bool carry = false;
        int current = resultSize - 1;
        while (current >= 0)
        {
            char currentA = (indexA >= 0) ? a[indexA] : '0';
            char currentB = (indexB >= 0) ? b[indexB] : '0';
            indexA--;
            indexB--;

            if (currentA == '1' && currentB == '1' && carry)
            {
                carry = true;
                result[current] = '1';
            }
            else if (currentA == '1' && currentB == '1' && !carry)
            {
                carry = true;
                result[current] = '0';
            }
            else if (((currentB == '1' && currentA == '0') || (currentB == '0' && currentA == '1')) && carry)
            {
                carry = true;
                result[current] = '0';
            }
            else if (((currentB == '1' && currentA == '0') || (currentB == '0' && currentA == '1')) && !carry)
            {
                carry = false;
                result[current] = '1';
            }
            else if (carry) {
                carry = false;
                result[current] = '1';
            }
            else
            {
                carry = false;
                result[current] = '0';
            }
            current--;
        }

        if (result.front() == '0')
            return result.erase(0, 1);

        return result;
    }
};