mod = 1e9+7
def fast_power(base, power):
    res = 1
    while power > 0:
        if power % 2 == 1:
            res *=base %mod
            res%=mod
        power = power // 2
        base = base * base%mod 
    return res %mod;
if __name__ == '__main__':
    x = int(input())
    k = (fast_power(2,x) - 2) %mod
    ans  =  fast_power(4,k)
    print(ans)

    ###ans = ans*6 %mod
