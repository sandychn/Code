def value(s):
    res = 0
    for i in range(len(s)):
        res = res * 26 + ord(s[i]) - ord('a') + 1
    return res


def main():
    s, t = input(), input()
    a, b = value(s), value(t)
    if a + 1 == b:
        print('No such string')
    else:
        ans = [(ord(ch) - ord('a') + 1) for ch in s]
        ans[-1] += 1
        for i in range(len(ans) - 1, -1, -1):
            # print(i)
            if ans[i] > 26:
                ans[i - 1] += 1
                ans[i] -= 26
        print(''.join([chr(x + ord('a') - 1) for x in ans]))


if __name__ == "__main__":
    main()