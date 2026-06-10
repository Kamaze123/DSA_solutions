class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t num = 0;
        for(int i = 0; i < 32; i++){
            int res = (n >> i) & 1;
            num += (res << (31- i));
        }

        return num;
    }
};
